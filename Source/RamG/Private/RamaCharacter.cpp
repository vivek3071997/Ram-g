#include "RamaCharacter.h"
#include "GameFramework/CharacterMovementComponent.h"

ARamaCharacter::ARamaCharacter()
{
	PrimaryActorTick.bCanEverTick = true;

	// Establish Prince Rama physiological stats inside the C++ constructor
	CurrentStamina = 100.f;
	CurrentFocus = 100.f;
	CurrentLacticAcid = 0.f;

	BowStaminaCostRate = 20.f;
	ShabdaBhediFocusCostRate = 12.f;
	AgneyastraCharges = 3;
	IronPointArrows = 30;

	bWeaponsLocked = false;
	bIsDrawingBow = false;
	bIsShabdaBhediActive = false;
}

void ARamaCharacter::BeginPlay()
{
	Super::BeginPlay();
	
	UE_LOG(LogTemp, Warning, TEXT("[RAMA YOUTH] Prince Rama initiates forest guard under Guru Vishwamitra."));
}

void ARamaCharacter::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	// 1. Process Physical Bow Drawing Cost & Draw Calibration
	if (bIsDrawingBow)
	{
		if (CurrentStamina > 0.f)
		{
			// Stamina decays dynamically as the bowstring is drawn back
			CurrentStamina -= BowStaminaCostRate * DeltaTime;
			if (CurrentStamina < 0.f) CurrentStamina = 0.f;

			// Draw force builds up to maximum over 1.5 seconds
			CurrentDrawForce += (MaxDrawForce / 1.5f) * DeltaTime;
			if (CurrentDrawForce > MaxDrawForce)
			{
				CurrentDrawForce = MaxDrawForce;
			}
		}
		else
		{
			// Forced release due to muscle exhaustion
			UE_LOG(LogTemp, Warning, TEXT("[EXHAUSTION] Bow string slipped! Stamina depleted."));
			ReleaseBow();
		}
	}

	// 2. Process Shabda-Bhedi Vidya Focus Decay
	if (bIsShabdaBhediActive)
	{
		if (CurrentFocus > 0.f)
		{
			CurrentFocus -= ShabdaBhediFocusCostRate * DeltaTime;
			if (CurrentFocus < 0.f) CurrentFocus = 0.f;
		}
		else
		{
			UE_LOG(LogTemp, Log, TEXT("[FOCUS DEPLETED] Shabda-Bhedi Vidya focus ended. Visual range restored."));
			ToggleShabdaBhediVidya();
		}
	}
}

void ARamaCharacter::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

	// Custom input bindings would map to StartDrawBow/ReleaseBow and ToggleShabdaBhediVidya
}

void ARamaCharacter::StartDrawBow()
{
	if (bWeaponsLocked)
	{
		UE_LOG(LogTemp, Warning, TEXT("[LOCK] Cannot draw bow! Prince Rama is completely unarmed in Mithila's court."));
		return;
	}

	if (CurrentStamina < 15.f)
	{
		UE_LOG(LogTemp, Warning, TEXT("[FATIGUE] Too tired to draw bow. Rest or practice Pranayama."));
		return;
	}

	if (IronPointArrows <= 0)
	{
		UE_LOG(LogTemp, Warning, TEXT("[OUT OF AMMO] No iron-point arrows remaining in your quiver!"));
		return;
	}

	bIsDrawingBow = true;
	CurrentDrawForce = 0.f;
	UE_LOG(LogTemp, Log, TEXT("[ARCHERY] Drawing Valkala Forest Bow..."));
}

void ARamaCharacter::ReleaseBow()
{
	if (!bIsDrawingBow) return;

	bIsDrawingBow = false;
	
	if (IronPointArrows > 0)
	{
		IronPointArrows--;
		UE_LOG(LogTemp, Warning, TEXT("[ARCHERY] Released Valkala Forest Bow! Arrow fired with force %f. Remaining quiver: %d"), CurrentDrawForce, IronPointArrows);
	}

	CurrentDrawForce = 0.f;
}

void ARamaCharacter::FireAgneyastra()
{
	if (bWeaponsLocked)
	{
		UE_LOG(LogTemp, Warning, TEXT("[LOCK] Cannot invoke Agneyastra! Weapons are locked."));
		return;
	}

	if (AgneyastraCharges <= 0)
	{
		UE_LOG(LogTemp, Warning, TEXT("[OUT OF MANA] Agneyastra fire charges depleted."));
		return;
	}

	AgneyastraCharges--;
	UE_LOG(LogTemp, Warning, TEXT("[AGNEYASTRA ACTIVATE] Prince Rama launches a blazing fire arrow! Explodes on contact, burning Asuric platforms."));
}

void ARamaCharacter::ToggleShabdaBhediVidya()
{
	if (bWeaponsLocked)
	{
		UE_LOG(LogTemp, Warning, TEXT("[LOCK] Spiritual concentration focus is locked."));
		return;
	}

	if (!bIsShabdaBhediActive)
	{
		if (CurrentFocus < 15.f)
		{
			UE_LOG(LogTemp, Warning, TEXT("[CONCENTRATION FAILS] Focus too low to enter Shabda-Bhedi Vidya state."));
			return;
		}

		bIsShabdaBhediActive = true;
		UE_LOG(LogTemp, Warning, TEXT("[SHABDA-BHEDI ACTIVE] Prince Rama closes his eyes, focusing on sound vectors. Dark/foggy visuals, sound sources highlighted."));
	}
	else
	{
		bIsShabdaBhediActive = false;
		UE_LOG(LogTemp, Log, TEXT("[SHABDA-BHEDI INACTIVE] Visual cues normalized."));
	}
}

void ARamaCharacter::SurrenderAllWeapons()
{
	bWeaponsLocked = true;
	bIsDrawingBow = false;
	bIsShabdaBhediActive = false;
	CurrentDrawForce = 0.f;
	AgneyastraCharges = 0;
	IronPointArrows = 0;

	// Royal courtly scholar walk speed restriction
	GetCharacterMovement()->MaxWalkSpeed = 300.f;

	UE_LOG(LogTemp, Error, TEXT("[COURT DISARMAMENT] Weapons surrendered at Mithila's gate house. Prince Rama is unarmed."));
}

FVector ARamaCharacter::GetShabdaBhediDirectionToSoundSource(const FVector& SoundSourceLocation) const
{
	// Calculate and return normalized relative sound vector for UI directional pings
	FVector Dir = (SoundSourceLocation - GetActorLocation()).GetSafeNormal();
	return Dir;
}
