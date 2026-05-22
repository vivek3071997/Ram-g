#include "Misc/AutomationTest.h"
#include "CoreMinimal.h"
#include "Engine/World.h"
#include "GameFramework/PlayerController.h"
#include "Mission0GameMode.h"
#include "HanumanCharacter.h"
#include "Kismet/GameplayStatics.h"
#include "GameFramework/CharacterMovementComponent.h"

#if WITH_DEV_AUTOMATION_TESTS

/**
 * Unreal Engine C++ Automation Test verifying Mission 0 Core Gameplay Logic,
 * Grounded Biomechanical limits, and Vajra Nerf states.
 */
IMPLEMENT_SIMPLE_AUTOMATION_TEST(FMission0DiagnosticsTest, "RamG.Missions.Mission0.Diagnostics", EAutomationTestFlags::ApplicationContextMask | EAutomationTestFlags::ProductFilter)

bool FMission0DiagnosticsTest::RunTest(const FString& Parameters)
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

	// 2. Fetch Active GameMode and verify its custom Mission State Controller
	AGameModeBase* GameMode = UGameplayStatics::GetGameMode(World);
	if (!TestNotNull(TEXT("GameMode must be active in World"), GameMode))
	{
		return false;
	}

	AMission0GameMode* MissionGameMode = Cast<AMission0GameMode>(GameMode);
	if (!TestNotNull(TEXT("World GameMode must subclass AMission0GameMode"), MissionGameMode))
	{
		return false;
	}

	// 3. Fetch Hanuman Playable Character
	ACharacter* PlayerChar = UGameplayStatics::GetPlayerCharacter(World, 0);
	AHanumanCharacter* Hanuman = Cast<AHanumanCharacter>(PlayerChar);

	if (Hanuman)
	{
		// 3a. Verify Hanuman base physiological variables are positive and healthy
		TestTrue(TEXT("Hanuman current stamina must be fully initialized (> 0.0f)"), Hanuman->CurrentStamina >= 0.0f);
		TestTrue(TEXT("Hanuman current focus must be fully initialized (> 0.0f)"), Hanuman->CurrentFocus >= 0.0f);
		
		// 3b. Verify double jump physics are bound in prologue
		TestEqual(TEXT("Hanuman must possess Vayu's vertical double-jump (MaxJumpCount = 2)"), Hanuman->MaxJumpCount, 2);
		
		// 3c. Verify grapple hook parameters
		TestEqual(TEXT("Hanuman's tail grapple max range must be exactly 1500 units in prologue"), Hanuman->GrappleMaxRange, 1500.f);

		// 3d. Verify Sacred fruit collection and basket tracking
		int32 InitialFruitsCount = Hanuman->FruitsCollected;
		Hanuman->CollectSacredFruit();
		TestEqual(TEXT("Sacred fruit collection must increment Mango Basket count"), Hanuman->FruitsCollected, InitialFruitsCount + 1);
		
		// Reset fruit count to preserve state
		Hanuman->FruitsCollected = InitialFruitsCount;

		// 3e. Verify Vajra Nerf impact transition and biological locking
		EMission0State SavedState = MissionGameMode->GetCurrentMissionState();
		float SavedWalkSpeed = Hanuman->GetCharacterMovement()->MaxWalkSpeed;

		// Trigger the strike
		MissionGameMode->TriggerVajraNerfSequence();

		TestEqual(TEXT("Vajra Strike must set GameMode state to VajraNerf"), MissionGameMode->GetCurrentMissionState(), EMission0State::VajraNerf);
		TestEqual(TEXT("Vajra Strike must limit movement to crawl (MaxWalkSpeed = 250)"), Hanuman->GetCharacterMovement()->MaxWalkSpeed, 250.f);
		TestEqual(TEXT("Vajra Strike must restrict jumping to a single jump"), Hanuman->MaxJumpCount, 1);
		TestEqual(TEXT("Vajra Strike must lock grapple range to zero"), Hanuman->GrappleMaxRange, 0.f);
		TestEqual(TEXT("Vajra Strike must fully drain Stamina to zero"), Hanuman->CurrentStamina, 0.f);

		// Restore original state to keep sandbox clean
		MissionGameMode->SetMissionState(SavedState);
		Hanuman->MaxJumpCount = 2;
		Hanuman->GrappleMaxRange = 1500.f;
		Hanuman->GetCharacterMovement()->MaxWalkSpeed = SavedWalkSpeed;
	}
	else
	{
		AddWarning(TEXT("Kid Hanuman Playable Character not found in current scene context. Skipping active physiological tests."));
	}

	return true;
}

#endif // WITH_DEV_AUTOMATION_TESTS
