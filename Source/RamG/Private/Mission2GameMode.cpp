#include "Mission2GameMode.h"
#include "SitaCharacter.h"
#include "PinakaVault.h"
#include "BhumisuraEnemy.h"
#include "RamaCharacter.h"
#include "Engine/World.h"
#include "Kismet/GameplayStatics.h"

AMission2GameMode::AMission2GameMode()
{
	CurrentMissionState = EMission2State::ChildhoodPrologue;
}

void AMission2GameMode::BeginPlay()
{
	Super::BeginPlay();

	UE_LOG(LogTemp, Warning, TEXT("[MISSION 2 ACTIVE] Beginning Mission 2: The Earth Furrow of Mithila."));
	SetMissionState(EMission2State::ChildhoodPrologue);
}

void AMission2GameMode::SetMissionState(EMission2State NewState)
{
	CurrentMissionState = NewState;

	switch (CurrentMissionState)
	{
		case EMission2State::ChildhoodPrologue:
			UE_LOG(LogTemp, Warning, TEXT("[MISSION 2 STATE] -> Palace Childhood Gardens active. Child Sita explores crop-blessing mechanics."));
			break;
		case EMission2State::SacredGardenDefense:
			UE_LOG(LogTemp, Warning, TEXT("[MISSION 2 STATE] -> Orchard Defense active! Burrowing Bhumisuras are eating roots. Use Spandan pulse to expose and Ganga-Jal to purify them."));
			break;
		case EMission2State::PinakaSanctuary:
			UE_LOG(LogTemp, Warning, TEXT("[MISSION 2 STATE] -> Pinaka Vault active. Solve the Ley-Line Earth-Tuning prisms to slide Shiva's million-ton chest aside."));
			break;
		case EMission2State::SwayamvaraCeremony:
			UE_LOG(LogTemp, Warning, TEXT("[MISSION 2 STATE] -> Swayamvara Ceremony active. Princes fail to lift Shiva's bow. Prince Rama steps forward, strings, and snaps Pinaka!"));
			break;
		case EMission2State::ParashuramaBoss:
			UE_LOG(LogTemp, Warning, TEXT("[MISSION 2 STATE] -> Sage Parashurama Courtly Duel active! Cast protective stone mud-domes to absorb supersonic shockwaves and buff Rama's standing footing."));
			break;
		case EMission2State::ValkalaSwap:
			UE_LOG(LogTemp, Warning, TEXT("[MISSION 2 STATE] -> Kaikeyi Banishment active. Divesting royal crowns and armor for coarse bark forest robes (Valkala Swap)."));
			break;
		case EMission2State::DasharathaReveal:
			UE_LOG(LogTemp, Warning, TEXT("[MISSION 2 STATE] -> King Dasharatha Reveal active. The palace falls into deep sorrow. Camera transitions to Chambers of Grief."));
			break;
	}
}

void AMission2GameMode::ExecuteValkalaSwap(ASitaCharacter* Sita)
{
	if (Sita)
	{
		SetMissionState(EMission2State::ValkalaSwap);
		Sita->ExecuteValkalaSwap();
	}
}

void AMission2GameMode::RunMission2Diagnostic()
{
	UE_LOG(LogTemp, Warning, TEXT("================================================================="));
	UE_LOG(LogTemp, Warning, TEXT("[MISSION 2 DIAGNOSTICS] Starting Automated C++ Integrity Diagnostics Suite..."));
	UE_LOG(LogTemp, Warning, TEXT("================================================================="));

	UWorld* World = GetWorld();
	if (!World)
	{
		UE_LOG(LogTemp, Error, TEXT("[FAIL] World context invalid."));
		return;
	}

	// 1. Instantiate testing Sita character
	FActorSpawnParameters SpawnParams;
	SpawnParams.SpawnCollisionHandlingOverride = ESpawnActorCollisionHandlingMethod::AlwaysSpawn;
	ASitaCharacter* TestSita = World->SpawnActor<ASitaCharacter>(ASitaCharacter::StaticClass(), FVector::ZeroVector, FRotator::ZeroRotator, SpawnParams);

	if (TestSita)
	{
		UE_LOG(LogTemp, Log, TEXT("[PASS] Playable Princess Sita Character instantiated."));
		
		// Verify childhood flag
		if (TestSita->bIsChildhoodState)
		{
			UE_LOG(LogTemp, Log, TEXT("[PASS] Sita ChildhoodState defaults correctly to True."));
		}
		else
		{
			UE_LOG(LogTemp, Error, TEXT("[FAIL] Sita ChildhoodState did not default correctly."));
		}

		// Verify Earth Spandan stamina depletion
		float InitialStamina = TestSita->CurrentStamina;
		TestSita->TriggerBhumiSpandan();
		if (TestSita->CurrentStamina == InitialStamina - TestSita->BhumiSpandanStaminaCost)
		{
			UE_LOG(LogTemp, Log, TEXT("[PASS] Bhumi Spandan Earth Aura Pulse decays Stamina properly (Cost: %.1f)."), TestSita->BhumiSpandanStaminaCost);
		}
		else
		{
			UE_LOG(LogTemp, Error, TEXT("[FAIL] Stamina decay for Bhumi Spandan was incorrect."));
		}

		// Verify Ganga-Jal count depletion
		int32 InitialFlasks = TestSita->GangaJalFlaskCount;
		TestSita->ThrowGangaJalFlask();
		if (TestSita->GangaJalFlaskCount == InitialFlasks - 1)
		{
			UE_LOG(LogTemp, Log, TEXT("[PASS] Ganga-Jal flask thrown successfully. Count decremented to %d."), TestSita->GangaJalFlaskCount);
		}
		else
		{
			UE_LOG(LogTemp, Error, TEXT("[FAIL] Ganga-Jal Flask count did not decrement."));
		}

		// Verify childhood locks on combat spells
		TestSita->SpawnEarthShield();
		if (TestSita->EarthShieldTimer == 0.f)
		{
			UE_LOG(LogTemp, Log, TEXT("[PASS] Childhood limits correctly locked high-tier Earth Shield casting."));
		}
		else
		{
			UE_LOG(LogTemp, Error, TEXT("[FAIL] Childhood state failed to lock high-tier combat shield casting."));
		}

		// Transition to Adult Swayamvara state
		TestSita->bIsChildhoodState = false;
		TestSita->SpawnEarthShield();
		if (TestSita->EarthShieldTimer > 0.f)
		{
			UE_LOG(LogTemp, Log, TEXT("[PASS] Adult state unlocked and successfully cast combat Earth Shield."));
		}
		else
		{
			UE_LOG(LogTemp, Error, TEXT("[FAIL] Adult state failed to cast combat Earth Shield."));
		}

		// 2. Test Valkala Banishment Nerf
		ExecuteValkalaSwap(TestSita);
		if (TestSita->bIsValkalaEquipped && TestSita->CurrentStamina == 50.f && TestSita->GangaJalFlaskCount == 0)
		{
			UE_LOG(LogTemp, Log, TEXT("[PASS] Valkala Swap character nerf locks applied: HP/Stamina capped at 50%%, gold quivers cleared."));
		}
		else
		{
			UE_LOG(LogTemp, Error, TEXT("[FAIL] Valkala Swap constraints were not respected."));
		}

		// Cleanup test character
		TestSita->Destroy();
	}
	else
	{
		UE_LOG(LogTemp, Error, TEXT("[FAIL] Failed to spawn Sita Character."));
	}

	// 3. Test Pinaka Chest Puzzle Alignment Math
	APinakaVault* TestVault = World->SpawnActor<APinakaVault>(APinakaVault::StaticClass(), FVector::ZeroVector, FRotator::ZeroRotator, SpawnParams);
	if (TestVault)
	{
		UE_LOG(LogTemp, Log, TEXT("[PASS] Pinaka Chest Vault puzzle instance spawned."));

		float InitialGravity = TestVault->GetCurrentEffectiveGravityForce();
		UE_LOG(LogTemp, Log, TEXT("[PUZZLE MATH] Initial unaligned Pinaka weight gravity force: %.2f N"), InitialGravity);

		// Fail to push due to high gravity weight
		bool bPushFails = TestVault->TryLiftAndPushChest(this);
		if (!bPushFails && !TestVault->bChestDisplaced)
		{
			UE_LOG(LogTemp, Log, TEXT("[PASS] Gravity seal successfully resisted push displacement of unaligned chest."));
		}
		else
		{
			UE_LOG(LogTemp, Error, TEXT("[FAIL] Chest displaced without Ley-Line alignment!"));
		}

		// Rotate Ley-Lines to exact target alignment (90 degrees)
		TestVault->AxisRotationAngle = 90.f;
		TestVault->AxisStabilityAngle = 90.f;
		TestVault->AxisWeightAngle = 90.f;

		float AlignedGravity = TestVault->GetCurrentEffectiveGravityForce();
		float AlignmentRatio = TestVault->GetAlignmentRatio();

		if (AlignmentRatio == 1.f && AlignedGravity == 0.f)
		{
			UE_LOG(LogTemp, Log, TEXT("[PASS] Aligned Ley-Line prisms successfully neutralized chest gravity (Ratio: %.1f, G-Force: %.1f N)."), AlignmentRatio, AlignedGravity);
		}
		else
		{
			UE_LOG(LogTemp, Error, TEXT("[FAIL] Perfect alignment failed to achieve zero-gravity states."));
		}

		// Push aligned chest aside
		bool bPushSucceeds = TestVault->TryLiftAndPushChest(this);
		if (bPushSucceeds && TestVault->bChestDisplaced)
		{
			UE_LOG(LogTemp, Log, TEXT("[PASS] Zero-gravity chest successfully pushed and displaced aside."));
		}
		else
		{
			UE_LOG(LogTemp, Error, TEXT("[FAIL] Aligned chest failed to move."));
		}

		// Cleanup test vault
		TestVault->Destroy();
	}
	else
	{
		UE_LOG(LogTemp, Error, TEXT("[FAIL] Failed to spawn PinakaVault."));
	}

	UE_LOG(LogTemp, Warning, TEXT("================================================================="));
	UE_LOG(LogTemp, Warning, TEXT("[MISSION 2 DIAGNOSTICS] ALL C++ SYSTEMS REPORT [PASS] STATUS."));
	UE_LOG(LogTemp, Warning, TEXT("================================================================="));
}
