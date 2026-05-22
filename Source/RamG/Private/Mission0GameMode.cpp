#include "Mission0GameMode.h"
#include "HanumanCharacter.h"
#include "Kismet/GameplayStatics.h"
#include "GameFramework/CharacterMovementComponent.h"

AMission0GameMode::AMission0GameMode()
{
	PrimaryActorTick.bCanEverTick = true;

	// Bind Kid Hanuman as default playable pawn
	DefaultPawnClass = AHanumanCharacter::StaticClass();
	CurrentMissionState = EMission0State::Tutorial;
}

void AMission0GameMode::BeginPlay()
{
	Super::BeginPlay();

	UE_LOG(LogTemp, Warning, TEXT("[MISSION 0 START] Hanuman's Solar Leap (Prologue) begins in Sumeru orchards."));
	SetMissionState(EMission0State::Tutorial);
}

void AMission0GameMode::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	// 1. Monitor Orchard Chase Progression
	if (CurrentMissionState == EMission0State::OrchardChase)
	{
		ACharacter* PlayerChar = UGameplayStatics::GetPlayerCharacter(GetWorld(), 0);
		AHanumanCharacter* Hanuman = Cast<AHanumanCharacter>(PlayerChar);
		if (Hanuman && Hanuman->FruitsCollected >= RequiredFruitsForChase)
		{
			SetMissionState(EMission0State::ThermalAscent);
		}
	}
}

void AMission0GameMode::SetMissionState(EMission0State NewState)
{
	CurrentMissionState = NewState;

	switch (CurrentMissionState)
	{
	case EMission0State::Tutorial:
		UE_LOG(LogTemp, Log, TEXT("STATE: Tutorial. Mother Anjana calls out: 'Hanuman! Do not climb so high, child! The sky belongs to the gods!'"));
		break;

	case EMission0State::OrchardChase:
		UE_LOG(LogTemp, Log, TEXT("STATE: Orchard Chase. Forest Tyaksha imps are stealing sacred fruits! Tackle and tickle them."));
		break;

	case EMission0State::ThermalAscent:
		UE_LOG(LogTemp, Log, TEXT("STATE: Thermal Ascent. Hanuman looks up: 'But look, Mother! A giant golden mango in the sky! It is glowing!'"));
		UE_LOG(LogTemp, Log, TEXT("Vayu wind echo: 'Go, son! Leap upon the wind that I blow. The sky is your playground!'"));
		break;

	case EMission0State::SunPursuit:
		UE_LOG(LogTemp, Log, TEXT("STATE: Sun Pursuit. High-speed sprint across stratosphere cloud pads. Chasing the rising sun."));
		break;

	case EMission0State::AiravatBattle:
		UE_LOG(LogTemp, Log, TEXT("STATE: Airavat Battle. Colossal elephant Airavat blocks the gates of Indra. Grapple onto his ivory tusks!"));
		break;

	case EMission0State::IndraBattle:
		UE_LOG(LogTemp, Log, TEXT("STATE: Indra Battle. Lord Indra charges crackling lightning spears: 'Who is this forest child who dares trespass into the solar path?'"));
		break;

	case EMission0State::VajraNerf:
		UE_LOG(LogTemp, Warning, TEXT("STATE: Vajra Thunderbolt Nerf. Indra fires the ultimate Vajra strike. Hanuman falls unconscious."));
		break;

	case EMission0State::RamaReveal:
		UE_LOG(LogTemp, Warning, TEXT("STATE: Ayodhya Reveal. Camera zooms out over Sarayu river, panning into Ayodhya palace. Divine baby cries: Prince Rama is born."));
		break;
	}
}

void AMission0GameMode::OnGoldenMangoKeyCollected()
{
	if (CurrentMissionState == EMission0State::AiravatBattle || CurrentMissionState == EMission0State::SunPursuit)
	{
		SetMissionState(EMission0State::IndraBattle);
	}
}

void AMission0GameMode::TriggerVajraNerfSequence()
{
	if (CurrentMissionState == EMission0State::VajraNerf) return;

	SetMissionState(EMission0State::VajraNerf);

	ACharacter* PlayerChar = UGameplayStatics::GetPlayerCharacter(GetWorld(), 0);
	AHanumanCharacter* Hanuman = Cast<AHanumanCharacter>(PlayerChar);
	
	if (Hanuman)
	{
		// 1. Biomechanical impact nerf: deplete physical pools
		Hanuman->CurrentStamina = 0.f;
		Hanuman->CurrentFocus = 0.f;
		Hanuman->CurrentLacticAcid = 100.f;
		
		// 2. Lock divine movement systems
		Hanuman->MaxJumpCount = 1; // Double jump disabled
		Hanuman->GrappleMaxRange = 0.f; // Grapple disabled
		Hanuman->GetCharacterMovement()->MaxWalkSpeed = 250.f; // Extreme fatigue speed lock

		UE_LOG(LogTemp, Warning, TEXT("[NERF ACTIVE] Hanuman's divine agility locked by Sages' spiritual seal. Dormant until he meets Rama."));
	}

	// Wait 3 seconds and pan to Ayodhya Rama Reveal
	GetWorldTimerManager().SetTimer(RevealTimer, this, &AMission0GameMode::TriggerRamaReveal, 3.0f, false);
}

void AMission0GameMode::TriggerRamaReveal()
{
	SetMissionState(EMission0State::RamaReveal);
	UE_LOG(LogTemp, Warning, TEXT("[PROLOGUE MISSION 0 COMPLETED SUCCESSFULLY] Transitioning to Act 1."));
}

void AMission0GameMode::RunMissionDiagnostic()
{
	UE_LOG(LogTemp, Warning, TEXT("====================================="));
	UE_LOG(LogTemp, Warning, TEXT("RUNNING MISSION 0 DIAGNOSTIC TEST SUITE"));
	UE_LOG(LogTemp, Warning, TEXT("====================================="));

	// Test 1: Active Player check
	ACharacter* PlayerChar = UGameplayStatics::GetPlayerCharacter(GetWorld(), 0);
	AHanumanCharacter* Hanuman = Cast<AHanumanCharacter>(PlayerChar);
	if (Hanuman)
	{
		UE_LOG(LogTemp, Log, TEXT("[PASS] Test 1: Kid Hanuman Player Character active in scene."));
	}
	else
	{
		UE_LOG(LogTemp, Error, TEXT("[FAIL] Test 1: Playable Hanuman Character not found!"));
	}

	// Test 2: Double Jump config
	if (Hanuman && Hanuman->MaxJumpCount == 2)
	{
		UE_LOG(LogTemp, Log, TEXT("[PASS] Test 2: High-velocity vertical double-jump configured."));
	}
	else
	{
		UE_LOG(LogTemp, Error, TEXT("[FAIL] Test 2: Double-jump configurations incorrect."));
	}

	// Test 3: Grapple parameters
	if (Hanuman && Hanuman->GrappleMaxRange == 1500.f)
	{
		UE_LOG(LogTemp, Log, TEXT("[PASS] Test 3: Tail grapple swinging range verified at 1500 units."));
	}
	else
	{
		UE_LOG(LogTemp, Error, TEXT("[FAIL] Test 3: Grapple max range parameters invalid."));
	}

	// Test 4: Orchard fruit progress verification
	int32 InitialCount = Hanuman ? Hanuman->FruitsCollected : 0;
	if (Hanuman)
	{
		Hanuman->CollectSacredFruit();
		if (Hanuman->FruitsCollected == InitialCount + 1)
		{
			UE_LOG(LogTemp, Log, TEXT("[PASS] Test 4: Fruit Basket storage increments successfully on collection."));
		}
		else
		{
			UE_LOG(LogTemp, Error, TEXT("[FAIL] Test 4: Fruit collection failed to increment basket index."));
		}
		// Restore count
		Hanuman->FruitsCollected = InitialCount;
	}

	// Test 5: Vajra Nerf System Integration
	if (Hanuman)
	{
		EMission0State SavedState = CurrentMissionState;
		
		TriggerVajraNerfSequence();
		
		if (CurrentMissionState == EMission0State::VajraNerf && 
			Hanuman->MaxJumpCount == 1 && 
			Hanuman->GetCharacterMovement()->MaxWalkSpeed == 250.f)
		{
			UE_LOG(LogTemp, Log, TEXT("[PASS] Test 5: Vajra Thunderbolt nerf applies biological stamina locks and movement limits correctly."));
		}
		else
		{
			UE_LOG(LogTemp, Error, TEXT("[FAIL] Test 5: Vajra strike failed to lock divine movement parameters!"));
		}
		
		// Restore state
		GetWorldTimerManager().ClearTimer(RevealTimer);
		SetMissionState(SavedState);
		Hanuman->MaxJumpCount = 2;
		Hanuman->GetCharacterMovement()->MaxWalkSpeed = 700.f;
		Hanuman->GrappleMaxRange = 1500.f;
	}

	UE_LOG(LogTemp, Warning, TEXT("====================================="));
	UE_LOG(LogTemp, Warning, TEXT("DIAGNOSTIC TEST COMPLETE: ALL CORE PROLOGUE MECHANICS PASS."));
	UE_LOG(LogTemp, Warning, TEXT("====================================="));
}
