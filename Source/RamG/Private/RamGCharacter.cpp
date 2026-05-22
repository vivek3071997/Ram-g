#include "RamGCharacter.h"
#include "GroundedCharacterData.h"
#include "GameFramework/CharacterMovementComponent.h"
#include "Kismet/GameplayStatics.h"
#include "EnhancedInputComponent.h"
#include "EnhancedInputSubsystems.h"

// Sets default values
ARamGCharacter::ARamGCharacter()
{
	// Set this character to call Tick() every frame.
	PrimaryActorTick.bCanEverTick = true;

	// Grounded movement parameters - no cartoonish speeds or infinite floating jumps
	GetCharacterMovement()->GravityScale = 1.6f; // More weight/gravitational presence
	GetCharacterMovement()->MaxWalkSpeed = 600.f; // Human limits
	GetCharacterMovement()->JumpZVelocity = 550.f;
	GetCharacterMovement()->AirControl = 0.15f; // Harder to change trajectory mid-air

	// Pool initializations
	CurrentStamina = 100.f;
	CurrentFocus = 100.f;
	CurrentLacticAcid = 0.f;
	bIsPranayamaActive = false;
	bIsExhausted = false;
}

// Called when the game starts or when spawned
void ARamGCharacter::BeginPlay()
{
	Super::BeginPlay();

	// Initialize pools dynamically from the Grounded Character Data Asset if available
	if (CharacterData)
	{
		// Cardiovascular output dictates maximum stamina reservoir scale
		CurrentStamina = CharacterData->MaxCardiacOutputLMin * 4.f;
		CurrentFocus = CharacterData->MaxFocusCapacityJoules;
		CurrentLacticAcid = 0.f;

		// Modify default walk speed relative to physical weight and neurological latency
		float SpeedModifier = (200.f / CharacterData->NeurologicalLatencyMs);
		GetCharacterMovement()->MaxWalkSpeed = 600.f * SpeedModifier;
	}

	// Add input mapping context
	if (APlayerController* PlayerController = Cast<APlayerController>(Controller))
	{
		if (UEnhancedInputLocalPlayerSubsystem* Subsystem = ULocalPlayer::GetSubsystem<UEnhancedInputLocalPlayerSubsystem>(PlayerController->GetLocalPlayer()))
		{
			if (DefaultMappingContext)
			{
				Subsystem->AddMappingContext(DefaultMappingContext, 0);
			}
		}
	}
}

// Called every frame
void ARamGCharacter::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	UpdatePhysiologicalMetabolism(DeltaTime);
}

// Called to bind functionality to input
void ARamGCharacter::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

	if (UEnhancedInputComponent* EnhancedInputComponent = Cast<UEnhancedInputComponent>(PlayerInputComponent))
	{
		// Bind Movement & Camera controls
		if (MoveAction)
		{
			EnhancedInputComponent->BindAction(MoveAction, ETriggerEvent::Triggered, this, &ARamGCharacter::Move);
		}
		if (LookAction)
		{
			EnhancedInputComponent->BindAction(LookAction, ETriggerEvent::Triggered, this, &ARamGCharacter::Look);
		}

		// Bind Grounded Mechanics
		if (DashAction)
		{
			EnhancedInputComponent->BindAction(DashAction, ETriggerEvent::Started, this, &ARamGCharacter::PerformDash);
		}
		if (FocusAction)
		{
			EnhancedInputComponent->BindAction(FocusAction, ETriggerEvent::Started, this, &ARamGCharacter::StartPranayamaFocus);
			EnhancedInputComponent->BindAction(FocusAction, ETriggerEvent::Completed, this, &ARamGCharacter::StopPranayamaFocus);
		}
	}
}

void ARamGCharacter::Move(const FInputActionValue& Value)
{
	FVector2D MovementVector = Value.Get<FVector2D>();

	if (Controller != nullptr && !bIsExhausted)
	{
		// Find out which way is forward
		const FRotator Rotation = Controller->GetControlRotation();
		const FRotator YawRotation(0, Rotation.Yaw, 0);

		// Get forward vector
		const FVector ForwardDirection = FRotationMatrix(YawRotation).GetUnitAxis(EAxis::X);
	
		// Get right vector 
		const FVector RightDirection = FRotationMatrix(YawRotation).GetUnitAxis(EAxis::Y);

		// Apply movement, scaling with biological latency in neural paths
		float FatigueDampening = 1.f - (CurrentLacticAcid * 0.05f);
		if (FatigueDampening < 0.4f) FatigueDampening = 0.4f;

		AddMovementInput(ForwardDirection, MovementVector.Y * FatigueDampening);
		AddMovementInput(RightDirection, MovementVector.X * FatigueDampening);
	}
}

void ARamGCharacter::Look(const FInputActionValue& Value)
{
	FVector2D LookAxisVector = Value.Get<FVector2D>();

	if (Controller != nullptr)
	{
		// Add yaw and pitch input
		AddControllerYawInput(LookAxisVector.X);
		AddControllerPitchInput(LookAxisVector.Y);
	}
}

void ARamGCharacter::PerformDash()
{
	if (bIsExhausted || CurrentStamina < DashStaminaCost)
	{
		return;
	}

	// Consume stamina
	CurrentStamina -= DashStaminaCost;

	// Grounded fast dash utilizing biomechanical force direction
	FVector DashDirection = GetActorForwardVector();
	if (GetCharacterMovement()->Velocity.Size2D() > 10.f)
	{
		DashDirection = GetCharacterMovement()->Velocity.GetSafeNormal2D();
	}

	// Dynamic accumulation of lactic acid depending on the metabolic efficiency
	float LacticIncrease = 2.0f;
	if (CharacterData)
	{
		// Efficient players clear lactate faster, weak players accumulate rapidly
		LacticIncrease = (5.f / CharacterData->LacticAcidThresholdMmol);
	}
	CurrentLacticAcid += LacticIncrease;

	// Launch character
	float DashForce = 1500.f;
	LaunchCharacter(DashDirection * DashForce, true, false);
}

void ARamGCharacter::StartPranayamaFocus()
{
	if (bIsPranayamaActive || bIsExhausted || CurrentFocus <= 10.f)
	{
		return;
	}

	bIsPranayamaActive = true;

	// Slow down game time purely through global dilation adjustment and custom offset
	UGameplayStatics::SetGlobalTimeDilation(GetWorld(), PranayamaTimeDilationFactor);

	// Make the player run at full speed relative to slow motion: 
	// Global Dilation * CustomTimeDilation = Effective Dilation
	CustomTimeDilation = 1.f / PranayamaTimeDilationFactor;
}

void ARamGCharacter::StopPranayamaFocus()
{
	if (!bIsPranayamaActive)
	{
		return;
	}

	bIsPranayamaActive = false;

	// Restore normal flow
	UGameplayStatics::SetGlobalTimeDilation(GetWorld(), 1.0f);
	CustomTimeDilation = 1.0f;
}

void ARamGCharacter::UpdatePhysiologicalMetabolism(float DeltaTime)
{
	float MaxStamina = CharacterData ? CharacterData->MaxCardiacOutputLMin * 4.f : 100.f;
	float MaxFocus = CharacterData ? CharacterData->MaxFocusCapacityJoules : 100.f;

	// 1. Pranayama Active State
	if (bIsPranayamaActive)
	{
		CurrentFocus -= PranayamaFocusCostPerSecond * DeltaTime;
		if (CurrentFocus <= 0.f)
		{
			CurrentFocus = 0.f;
			StopPranayamaFocus();
		}
	}
	else
	{
		// Passive focus regeneration
		float FocusRegenRate = CharacterData ? (CharacterData->AtpRecoveryRateJs * 0.1f) : 2.f;
		CurrentFocus = FMath::Min(MaxFocus, CurrentFocus + FocusRegenRate * DeltaTime);
	}

	// 2. Lactic Acid Clearance
	if (CurrentLacticAcid > 0.f)
	{
		float ClearanceMultiplier = CharacterData ? (CharacterData->MaxCardiacOutputLMin / 25.f) : 1.f;
		CurrentLacticAcid = FMath::Max(0.f, CurrentLacticAcid - (0.5f * ClearanceMultiplier * DeltaTime));
	}

	// 3. Stamina Recovery (Cardiovascular dependency)
	if (bIsExhausted)
	{
		// Recover slower during heavy fatigue (high lactic acid)
		float ExhaustionRecoveryFactor = 0.5f / (1.f + CurrentLacticAcid * 0.2f);
		float BaseRegen = CharacterData ? CharacterData->AtpRecoveryRateJs : 10.f;
		CurrentStamina += BaseRegen * ExhaustionRecoveryFactor * DeltaTime;

		if (CurrentStamina >= MaxStamina * 0.3f) // Recover out of exhaustion threshold
		{
			bIsExhausted = false;
		}
	}
	else
	{
		// Normal passive regeneration, throttled by lactic build up
		float LacticThrottling = 1.f / (1.f + CurrentLacticAcid * 0.1f);
		float RegenRate = CharacterData ? (CharacterData->AtpRecoveryRateJs * LacticThrottling) : (10.f * LacticThrottling);
		
		// If walking/standing still, regenerate. If sprinting (if implemented), drain.
		if (GetCharacterMovement()->Velocity.Size2D() < 50.f)
		{
			RegenRate *= 1.5f; // Enhanced recovery when completely still
		}

		CurrentStamina = FMath::Min(MaxStamina, CurrentStamina + RegenRate * DeltaTime);

		if (CurrentStamina <= 0.f)
		{
			CurrentStamina = 0.f;
			bIsExhausted = true;
			StopPranayamaFocus();
		}
	}
}
