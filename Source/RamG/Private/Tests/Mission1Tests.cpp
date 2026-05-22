#include "Misc/AutomationTest.h"
#include "CoreMinimal.h"
#include "Engine/World.h"
#include "GameFramework/PlayerController.h"
#include "Mission1GameMode.h"
#include "RamaCharacter.h"
#include "VedicAltar.h"
#include "Kismet/GameplayStatics.h"
#include "GameFramework/CharacterMovementComponent.h"

#if WITH_DEV_AUTOMATION_TESTS

/**
 * Unreal Engine C++ Automation Test verifying Mission 1 Gameplay Logic,
 * Prince Rama's Valkala Bow stamina draw, Shabda-Bhedi focus, Vedic Altar
 * sun-mirror puzzles, and Mithila disarmament locks.
 */
IMPLEMENT_SIMPLE_AUTOMATION_TEST(FMission1DiagnosticsTest, "RamG.Missions.Mission1.Diagnostics", EAutomationTestFlags::EditorContext | EAutomationTestFlags::ProductFilter)

bool FMission1DiagnosticsTest::RunTest(const FString& Parameters)
{
	// 1. Fetch active simulation World
	UWorld* World = nullptr;
	const TIndirectArray<FWorldContext>& WorldContexts = GEngine->GetWorldContexts();
	for (const FWorldContext& Context : WorldContexts)
	{
		if (Context.World() && Context.World()->IsGameWorld())
		{
			World = Context.World();
			break;
		}
	}

	if (!World)
	{
		// Fallback to editor world if running in Editor context
		for (const FWorldContext& Context : WorldContexts)
		{
			if (Context.World())
			{
				World = Context.World();
				break;
			}
		}
	}

	if (!TestNotNull(TEXT("Unreal Simulation World must be active and loaded"), World))
	{
		return false;
	}

	// 2. Spawn and test Vedic Altar and mirror rotation alignment puzzle
	FActorSpawnParameters SpawnParams;
	SpawnParams.SpawnCollisionHandlingOverride = ESpawnActorCollisionHandlingMethod::AlwaysSpawn;
	AVedicAltar* Altar = World->SpawnActor<AVedicAltar>(AVedicAltar::StaticClass(), FVector::ZeroVector, FRotator::ZeroRotator, SpawnParams);
	
	if (TestNotNull(TEXT("AVedicAltar should be spawnable in current world context"), Altar))
	{
		// Check that the three mirrors start mismatched
		TestTrue(TEXT("Sun-Mirror 0 should not be aligned initially"), FMath::Abs(Altar->MirrorRotations[0] - Altar->RequiredAlignmentAngle) > Altar->AlignmentTolerance);
		TestFalse(TEXT("Altar should not be purified initially"), Altar->CheckAlignment());

		// Manually rotate the mirrors to focus angle (90 degrees)
		Altar->RotateMirror(0, Altar->RequiredAlignmentAngle - Altar->MirrorRotations[0]);
		Altar->RotateMirror(1, Altar->RequiredAlignmentAngle - Altar->MirrorRotations[1]);
		Altar->RotateMirror(2, Altar->RequiredAlignmentAngle - Altar->MirrorRotations[2]);

		// Verify purification barrier triggers
		TestTrue(TEXT("Altar should check out as perfectly aligned"), Altar->CheckAlignment());
		TestTrue(TEXT("Sunray purification state must be active"), Altar->bIsZonePurified);

		// Clean up the altar
		Altar->Destroy();
	}

	// 3. Spawns Prince Rama Character to verify active physiological attributes and limits
	ARamaCharacter* Rama = World->SpawnActor<ARamaCharacter>(ARamaCharacter::StaticClass(), FVector::ZeroVector, FRotator::ZeroRotator, SpawnParams);
	
	if (TestNotNull(TEXT("ARamaCharacter should be spawnable in current world context"), Rama))
	{
		// 3a. Verify initial physical pools
		TestEqual(TEXT("Rama starts with 100 Stamina units"), Rama->CurrentStamina, 100.f);
		TestEqual(TEXT("Rama starts with 100 Focus Joules"), Rama->CurrentFocus, 100.f);
		TestEqual(TEXT("Rama starts with 30 Iron-Point arrows"), Rama->IronPointArrows, 30);
		TestEqual(TEXT("Rama starts with 3 Agneyastra explosive charges"), Rama->AgneyastraCharges, 3);

		// 3b. Verify Bow Drawing physics consumes stamina
		Rama->StartDrawBow();
		Rama->Tick(0.5f); // Holds draw for 0.5s

		TestTrue(TEXT("Holding draw string must decrease active Stamina"), Rama->CurrentStamina < 100.f);
		TestTrue(TEXT("Holding draw string must generate pull force"), Rama->CurrentDrawForce > 0.f);

		// Release standard arrow
		Rama->ReleaseBow();
		TestEqual(TEXT("Releasing bow must decrement arrow quiver"), Rama->IronPointArrows, 29);
		TestEqual(TEXT("Releasing bow must reset current draw force"), Rama->CurrentDrawForce, 0.f);

		// 3c. Verify Shabda-Bhedi Vidya focus highlights invisible enemies
		Rama->ToggleShabdaBhediVidya();
		TestTrue(TEXT("Shabda-Bhedi Vidya focus state must be active"), Rama->bIsShabdaBhediActive);

		FVector MockSource = Rama->GetActorLocation() + FVector(200.f, -100.f, 50.f);
		FVector Direction = Rama->GetShabdaBhediDirectionToSoundSource(MockSource);
		TestTrue(TEXT("Audio directional vector must be calculated"), Direction.IsNormalized());

		// Toggle back off
		Rama->ToggleShabdaBhediVidya();
		TestFalse(TEXT("Shabda-Bhedi Vidya focus state disabled"), Rama->bIsShabdaBhediActive);

		// 3d. Verify Courtly Disarmament gatehouse locks
		Rama->SurrenderAllWeapons();
		TestTrue(TEXT("Disarmament must lock weapons HUD"), Rama->bWeaponsLocked);
		TestEqual(TEXT("Disarmament must fully strip arrows"), Rama->IronPointArrows, 0);
		TestEqual(TEXT("Disarmament must fully strip Agneyastra fire charges"), Rama->AgneyastraCharges, 0);
		TestEqual(TEXT("Disarmament must restrict movement to scholar walk"), Rama->GetCharacterMovement()->MaxWalkSpeed, 300.f);

		// Try drawing bow under locks - should fail
		Rama->StartDrawBow();
		TestFalse(TEXT("Rama should not be drawing bow under disarmament lock"), Rama->CurrentDrawForce > 0.f);

		// Clean up Prince Rama
		Rama->Destroy();
	}

	return true;
}

#endif // WITH_DEV_AUTOMATION_TESTS
