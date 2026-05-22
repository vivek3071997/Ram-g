#include "HanumanCharacter.h"
#include "GameFramework/CharacterMovementComponent.h"
#include "EnhancedInputComponent.h"
#include "Kismet/KismetSystemLibrary.h"
#include "Kismet/GameplayStatics.h"

AHanumanCharacter::AHanumanCharacter()
{
	// Divine child movement bounds - high agility
	GetCharacterMovement()->GravityScale = 1.2f; // Lighter than Rama
	GetCharacterMovement()->MaxWalkSpeed = 700.f; // Energetic child sprint
	GetCharacterMovement()->JumpZVelocity = 650.f;
	GetCharacterMovement()->AirControl = 0.4f; // Extreme control mid-air

	CurrentJumpCount = 0;
	bIsGrappling = false;
	FruitsCollected = 0;
}

void AHanumanCharacter::BeginPlay()
{
	Super::BeginPlay();
}

void AHanumanCharacter::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	if (bIsGrappling)
	{
		UpdateGrapplePhysics(DeltaTime);
	}
}

void AHanumanCharacter::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

	if (UEnhancedInputComponent* EnhancedInputComponent = Cast<UEnhancedInputComponent>(PlayerInputComponent))
	{
		if (GrappleAction)
		{
			EnhancedInputComponent->BindAction(GrappleAction, ETriggerEvent::Started, this, &AHanumanCharacter::StartGrapple);
			EnhancedInputComponent->BindAction(GrappleAction, ETriggerEvent::Completed, this, &AHanumanCharacter::StopGrapple);
		}

		if (AttackAction)
		{
			EnhancedInputComponent->BindAction(AttackAction, ETriggerEvent::Started, this, &AHanumanCharacter::PerformKidFistsAttack);
		}
	}
}

void AHanumanCharacter::Jump()
{
	if (GetCharacterMovement()->IsFalling())
	{
		if (CurrentJumpCount < MaxJumpCount)
		{
			CurrentJumpCount++;
			
			// High velocity double jump: launch upwards and in control direction
			FVector JumpDirection = GetLastMovementInputVector();
			if (JumpDirection.IsNearlyZero())
			{
				JumpDirection = GetActorForwardVector();
			}
			
			// Apply vertical and forward wind boost
			FVector LaunchVelocity = JumpDirection * DoubleJumpLaunchForce * 0.5f;
			LaunchVelocity.Z = DoubleJumpLaunchForce;
			
			LaunchCharacter(LaunchVelocity, false, true);

			// Spawn light wind gust particles (Vayu's blessing)
			// UGameplayStatics::SpawnEmitterAtLocation(GetWorld(), ...);
		}
	}
	else
	{
		CurrentJumpCount = 1;
		Super::Jump();
	}
}

void AHanumanCharacter::Landed(const FHitResult& Hit)
{
	Super::Landed(Hit);
	CurrentJumpCount = 0; // Reset double-jump on landing
}

void AHanumanCharacter::StartGrapple()
{
	if (bIsGrappling) return;

	FVector TraceStart = GetActorLocation();
	FVector ViewDir = GetActorForwardVector();
	
	// If looking using camera, get camera viewpoint forward direction
	if (APlayerController* PC = Cast<APlayerController>(GetController()))
	{
		FVector CamLoc;
		FRotator CamRot;
		PC->GetPlayerViewPoint(CamLoc, CamRot);
		TraceStart = CamLoc;
		ViewDir = CamRot.Vector();
	}

	FVector TraceEnd = TraceStart + (ViewDir * GrappleMaxRange);
	
	TArray<TEnumAsByte<EObjectTypeQuery>> ObjectTypes;
	ObjectTypes.Add(UEngineTypes::ConvertToObjectType(ECollisionChannel::ECC_WorldStatic));
	ObjectTypes.Add(UEngineTypes::ConvertToObjectType(ECollisionChannel::ECC_WorldDynamic));

	FHitResult HitResult;
	TArray<AActor*> ActorsToIgnore;
	ActorsToIgnore.Add(this);

	// Sphere trace to find grapple anchor
	bool bHit = UKismetSystemLibrary::SphereTraceSingleForObjects(
		GetWorld(),
		TraceStart,
		TraceEnd,
		80.f, // Grapple detection radius
		ObjectTypes,
		false,
		ActorsToIgnore,
		EDrawDebugTrace::None,
		HitResult,
		true
	);

	if (bHit)
	{
		AActor* HitActor = HitResult.GetActor();
		// Anchor should have tag "GrappleAnchor" or we can attach to solid static geography
		if (HitActor && (HitActor->ActorHasTag(TEXT("GrappleAnchor")) || HitActor->ActorHasTag(TEXT("OBJ_AIRAVAT_TUSKS")) || HitResult.GetComponent()->ComponentHasTag(TEXT("GrappleSocket"))))
		{
			bIsGrappling = true;
			GrappleAnchorPoint = HitResult.ImpactPoint;

			// Switch character movement to flying/swinging style temporarily
			GetCharacterMovement()->SetMovementMode(EMovementMode::MOVE_Falling);
			
			// Sound Snap twang!
			// UGameplayStatics::PlaySoundAtLocation(GetWorld(), ...);
		}
	}
}

void AHanumanCharacter::StopGrapple()
{
	if (!bIsGrappling) return;

	bIsGrappling = false;
	
	// Retain momentum: launch slightly forward to complete the swing smoothly
	FVector ForwardSwingBoost = GetCharacterMovement()->Velocity.GetSafeNormal() * 300.f;
	ForwardSwingBoost.Z = FMath::Max(150.f, ForwardSwingBoost.Z);
	LaunchCharacter(ForwardSwingBoost, false, false);
}

void AHanumanCharacter::UpdateGrapplePhysics(float DeltaTime)
{
	FVector CharLoc = GetActorLocation();
	FVector VectorToAnchor = GrappleAnchorPoint - CharLoc;
	float CurrentDistance = VectorToAnchor.Size();

	// Apply spring swing forces if string is taut
	FVector Velocity = GetCharacterMovement()->Velocity;
	FVector PullDirection = VectorToAnchor.GetSafeNormal();

	// Dot product to check if moving away from anchor
	float SpeedAway = FVector::DotProduct(Velocity, -PullDirection);

	// Swing tension force
	FVector TensionForce = PullDirection * (CurrentDistance * GrappleSwingStiffness) - (Velocity * GrappleSwingDampening);
	
	// Add gravity compensation to give feeling of swing float (frame-rate independent acceleration)
	TensionForce.Z += 980.f * GetCharacterMovement()->GravityScale;

	GetCharacterMovement()->Velocity += TensionForce * DeltaTime;

	// Keep constraints: if exceeded max stretch, snap length
	if (CurrentDistance > GrappleMaxRange)
	{
		FVector ConstrainedLoc = GrappleAnchorPoint - (PullDirection * GrappleMaxRange);
		SetActorLocation(ConstrainedLoc, true);
	}
}

void AHanumanCharacter::PerformKidFistsAttack()
{
	// Rapid playful non-lethal strikes
	FVector TraceStart = GetActorLocation() + GetActorForwardVector() * 50.f;
	FVector TraceEnd = TraceStart + (GetActorForwardVector() * KidFistsReach);

	TArray<TEnumAsByte<EObjectTypeQuery>> ObjectTypes;
	ObjectTypes.Add(UEngineTypes::ConvertToObjectType(ECollisionChannel::ECC_Pawn));

	TArray<AActor*> ActorsToIgnore;
	ActorsToIgnore.Add(this);

	TArray<FHitResult> HitResults;

	bool bHit = UKismetSystemLibrary::SphereTraceMultiForObjects(
		GetWorld(),
		TraceStart,
		TraceEnd,
		60.f, // Fist trace thickness
		ObjectTypes,
		false,
		ActorsToIgnore,
		EDrawDebugTrace::None,
		HitResults,
		true
	);

	if (bHit)
	{
		for (const FHitResult& Hit : HitResults)
		{
			AActor* HitActor = Hit.GetActor();
			if (HitActor)
			{
				// Kid Fists are non-lethal staggers:
				// Call custom event on target to handle non-lethal staggers and posture damage
				UFunction* StaggerFunc = HitActor->FindFunction(FName("TakeNonLethalStrike"));
				if (StaggerFunc)
				{
					struct FNonLethalParams
					{
						float Damage;
						float PostureDmg;
						AActor* Attacker;
					};
					FNonLethalParams Params{ KidFistsDamage, KidFistsPostureDamage, this };
					HitActor->ProcessEvent(StaggerFunc, &Params);
				}

				// Launch enemy backwards playfully (conservation of momentum)
				if (ACharacter* EnemyChar = Cast<ACharacter>(HitActor))
				{
					FVector KnockbackDir = GetActorForwardVector();
					KnockbackDir.Z = 0.2f;
					EnemyChar->LaunchCharacter(KnockbackDir.GetSafeNormal() * 400.f, true, false);
				}

				// Spawn impact dust/sparkles
				// UGameplayStatics::SpawnEmitterAtLocation(GetWorld(), ...);
			}
		}
	}
}

void AHanumanCharacter::CollectSacredFruit()
{
	FruitsCollected++;
	UE_LOG(LogTemp, Log, TEXT("Hanuman collected sacred fruit. Basket progress: %d/%d"), FruitsCollected, TotalRequiredFruits);
}
