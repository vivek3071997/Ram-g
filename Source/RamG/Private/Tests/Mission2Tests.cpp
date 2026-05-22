#include "Misc/AutomationTest.h"
#include "CoreMinimal.h"
#include "Engine/World.h"
#include "Mission2GameMode.h"
#include "SitaCharacter.h"
#include "BhumisuraEnemy.h"
#include "PinakaVault.h"
#include "Kismet/GameplayStatics.h"
#include "GameFramework/CharacterMovementComponent.h"

#if WITH_DEV_AUTOMATION_TESTS

/**
 * Unreal Engine C++ Automation Test verifying Mission 2 Gameplay Logic,
 * Princess Sita's Earth Aura Spandan, Ganga-Jal flask gopher purification,
 * Pinaka chest Ley-Line gravity puzzles, and the Valkala Swap exile nerfs.
 */
IMPLEMENT_SIMPLE_AUTOMATION_TEST(FMission2DiagnosticsTest, "RamG.Missions.Mission2.Diagnostics", EAutomationTestFlags::ApplicationContextMask | EAutomationTestFlags::ProductFilter)

bool FMission2DiagnosticsTest::RunTest(const FString& Parameters)
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

	FActorSpawnParameters SpawnParams;
	SpawnParams.SpawnCollisionHandlingOverride = ESpawnActorCollisionHandlingMethod::AlwaysSpawn;

	// 2. Spawn and test Bhumisura Burrow/Emerge states
	ABhumisuraEnemy* Gopher = World->SpawnActor<ABhumisuraEnemy>(ABhumisuraEnemy::StaticClass(), FVector::ZeroVector, FRotator::ZeroRotator, SpawnParams);
	if (TestNotNull(TEXT("ABhumisuraEnemy should be spawnable in current world context"), Gopher))
	{
		// Gopher should start burrowed and unpurified
		TestTrue(TEXT("Bhumisura starts in burrowed state"), Gopher->bIsBurrowed);
		TestFalse(TEXT("Bhumisura starts unpurified"), Gopher->bIsPurified);
		TestFalse(TEXT("Bhumisura starts unstaggered"), Gopher->bIsStaggered);

		// Trigger emerge
		Gopher->RevealAndEmerge();
		TestFalse(TEXT("Emerge should clear burrowed status"), Gopher->bIsBurrowed);
		TestTrue(TEXT("Emerge should set staggered status"), Gopher->bIsStaggered);
		TestTrue(TEXT("Emerge should decrease movement to emerge speed"), Gopher->GetCharacterMovement()->MaxWalkSpeed == Gopher->EmergeSpeed);

		// Trigger purification
		Gopher->Purify(nullptr);
		TestTrue(TEXT("Purification should set purified status"), Gopher->bIsPurified);
		TestFalse(TEXT("Purification should clear staggered status"), Gopher->bIsStaggered);
		TestTrue(TEXT("Purified status increases speed to flee"), Gopher->GetCharacterMovement()->MaxWalkSpeed == 600.f);

		Gopher->Destroy();
	}

	// 3. Spawn and test Sita character attributes and abilities
	ASitaCharacter* Sita = World->SpawnActor<ASitaCharacter>(ASitaCharacter::StaticClass(), FVector::ZeroVector, FRotator::ZeroRotator, SpawnParams);
	if (TestNotNull(TEXT("ASitaCharacter should be spawnable in current world context"), Sita))
	{
		// Verify default physiological configurations
		TestTrue(TEXT("Sita defaults to childhood state"), Sita->bIsChildhoodState);
		TestFalse(TEXT("Sita starts without forest garments"), Sita->bIsValkalaEquipped);
		TestEqual(TEXT("Sita starts with 100 Stamina units"), Sita->CurrentStamina, 100.f);
		TestEqual(TEXT("Sita starts with 10 Ganga-Jal flask charges"), Sita->GangaJalFlaskCount, 10);

		// Trigger Spandan pulse
		Sita->TriggerBhumiSpandan();
		TestTrue(TEXT("Spandan pulse must decrease operational Stamina"), Sita->CurrentStamina < 100.f);
		TestTrue(TEXT("Spandan pulse sets active cooldown indicator"), Sita->bBhumiSpandanActive);

		// Test childhood lockdowns on combat earth spells
		Sita->SpawnEarthShield();
		TestEqual(TEXT("Childhood state must prevent Earth Shield casting"), Sita->EarthShieldTimer, 0.f);

		// Upgrade to adult state
		Sita->bIsChildhoodState = false;
		Sita->SpawnEarthShield();
		TestTrue(TEXT("Adult state must allow Earth Shield casting"), Sita->EarthShieldTimer > 0.f);

		// Test Valkala Swap exile nerf
		Sita->ExecuteValkalaSwap();
		TestTrue(TEXT("Valkala swap must record garment state"), Sita->bIsValkalaEquipped);
		TestEqual(TEXT("Valkala swap must cap Stamina pool by 50%"), Sita->CurrentStamina, 50.f);
		TestEqual(TEXT("Valkala swap must fully strip gold Ganga-Jal flask inventory"), Sita->GangaJalFlaskCount, 0);

		Sita->Destroy();
	}

	// 4. Spawn and test Pinaka Vault puzzle alignments
	APinakaVault* Vault = World->SpawnActor<APinakaVault>(APinakaVault::StaticClass(), FVector::ZeroVector, FRotator::ZeroRotator, SpawnParams);
	if (TestNotNull(TEXT("APinakaVault should be spawnable in current world context"), Vault))
	{
		// Default angles start mismatched
		TestTrue(TEXT("Default alignment ratio should be despondently low"), Vault->GetAlignmentRatio() < 0.6f);
		TestTrue(TEXT("Default gravity force is colossal (in kN)"), Vault->GetCurrentEffectiveGravityForce() > 100000.f);

		// Pushing mismatched chest fails
		bool bFailedPush = Vault->TryLiftAndPushChest(nullptr);
		TestFalse(TEXT("Mismatched chest displacement must fail"), bFailedPush);
		TestFalse(TEXT("Mismatched chest displaced status remains false"), Vault->bChestDisplaced);

		// Align Ley-Lines to exact target angle (90 degrees)
		Vault->AxisRotationAngle = 90.f;
		Vault->AxisStabilityAngle = 90.f;
		Vault->AxisWeightAngle = 90.f;

		// Verifies gravity neutralization
		TestEqual(TEXT("Ley-Line alignment achieves 100% ratio"), Vault->GetAlignmentRatio(), 1.0f);
		TestEqual(TEXT("Aligned gravity force drops to zero"), Vault->GetCurrentEffectiveGravityForce(), 0.f);

		// Pushing zero-gravity chest succeeds
		bool bSucceededPush = Vault->TryLiftAndPushChest(nullptr);
		TestTrue(TEXT("Zero-gravity chest displacement must succeed"), bSucceededPush);
		TestTrue(TEXT("Chest displaced status is recorded as true"), Vault->bChestDisplaced);

		Vault->Destroy();
	}

	return true;
}

#endif // WITH_DEV_AUTOMATION_TESTS
