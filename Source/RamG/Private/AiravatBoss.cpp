#include "AiravatBoss.h"
#include "Components/CapsuleComponent.h"
#include "GameFramework/CharacterMovementComponent.h"
#include "Kismet/GameplayStatics.h"

AAiravatBoss::AAiravatBoss()
{
	PrimaryActorTick.bCanEverTick = true;

	// Colossal elephant capsule scale
	GetCapsuleComponent()->InitCapsuleSize(180.f, 300.f);

	// Setup left/right tusk grapple targets for Hanuman's grapple hook
	LeftTuskGrapplePoint = CreateDefaultSubobject<USceneComponent>(TEXT("LeftTuskGrapplePoint"));
	LeftTuskGrapplePoint->SetupAttachment(RootComponent);
	LeftTuskGrapplePoint->SetRelativeLocation(FVector(200.f, -120.f, 50.f));
	LeftTuskGrapplePoint->ComponentTags.Add(FName("GrappleSocket"));

	RightTuskGrapplePoint = CreateDefaultSubobject<USceneComponent>(TEXT("RightTuskGrapplePoint"));
	RightTuskGrapplePoint->SetupAttachment(RootComponent);
	RightTuskGrapplePoint->SetRelativeLocation(FVector(200.f, 120.f, 50.f));
	RightTuskGrapplePoint->ComponentTags.Add(FName("GrappleSocket"));

	// Colossal weight scaling
	SetActorScale3D(FVector(4.0f, 4.0f, 4.0f));

	CurrentPhase = EAiravatPhase::Phase1_TuskClimb;
	bIsCharging = false;
	ShockwaveTimer = 0.f;
}

void AAiravatBoss::BeginPlay()
{
	Super::BeginPlay();
	
	// Add tag to allow grapple hook traces to recognise the boss tusks
	Tags.Add(TEXT("GrappleAnchor"));
}

void AAiravatBoss::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	if (CurrentPhase == EAiravatPhase::Sleeping)
	{
		return;
	}

	// 1. Process Charging Movement
	if (bIsCharging)
	{
		ChargeLerpTime += DeltaTime;
		float Alpha = FMath::Clamp(ChargeLerpTime * 0.5f, 0.f, 1.f);
		
		FVector NewLoc = FMath::Lerp(ChargeStartLoc, ChargeEndLoc, Alpha);
		SetActorLocation(NewLoc, true);

		// Shockwave generation during stampede
		ShockwaveTimer += DeltaTime;
		if (ShockwaveTimer >= ShockwaveInterval)
		{
			ShockwaveTimer = 0.f;
			
			// Simulate ground shockwaves impacting player
			ACharacter* PlayerChar = UGameplayStatics::GetPlayerCharacter(GetWorld(), 0);
			if (PlayerChar)
			{
				float Dist = FVector::Dist(GetActorLocation(), PlayerChar->GetActorLocation());
				if (Dist < 800.f)
				{
					// Apply posture depletion or quick physical stagger to player
					UFunction* TakeStaggerFunc = PlayerChar->FindFunction(FName("TakeNonLethalStrike"));
					if (TakeStaggerFunc)
					{
						struct FStaggerParams { float Damage; float PostureDmg; AActor* Attacker; };
						FStaggerParams Params{ 5.f, 30.f, this };
						PlayerChar->ProcessEvent(TakeStaggerFunc, &Params);
					}
					
					// Force launch player slightly upwards if standing on ground (require jumping)
					UCharacterMovementComponent* MoveComp = PlayerChar->GetCharacterMovement();
					if (MoveComp && !MoveComp->IsFalling())
					{
						PlayerChar->LaunchCharacter(FVector(0.f, 0.f, 350.f), false, true);
						UE_LOG(LogTemp, Log, TEXT("Airavat stamp shockwave launches player!"));
					}
				}
			}
		}

		if (Alpha >= 1.0f)
		{
			bIsCharging = false;
			// Transition to Phase 2 after a couple charges
			if (CurrentPhase == EAiravatPhase::Phase1_TuskClimb)
			{
				TransitionToPhase2();
			}
		}
	}
	else
	{
		// Stand still or initiate a charge if player is near
		ACharacter* PlayerChar = UGameplayStatics::GetPlayerCharacter(GetWorld(), 0);
		if (PlayerChar && FVector::Dist(GetActorLocation(), PlayerChar->GetActorLocation()) < 2000.f)
		{
			// Randomly charge player every few seconds
			if (FMath::RandRange(0, 150) == 50)
			{
				PerformChargeAttack();
			}
		}
	}
}

void AAiravatBoss::TickleEar(AActor* Attacker)
{
	if (CurrentPhase == EAiravatPhase::Sleeping) return;

	CurrentPhase = EAiravatPhase::Sleeping;
	bIsCharging = false;
	
	UE_LOG(LogTemp, Log, TEXT("Hanuman tickles Airavat's ear! The colossal elephant giggles and falls asleep."));

	// Drop the golden mango key
	if (GoldenMangoKeyClass)
	{
		FVector KeyLoc = GetActorLocation() + GetActorForwardVector() * 300.f;
		KeyLoc.Z -= 200.f; // Place on the floor
		
		FActorSpawnParameters SpawnParams;
		SpawnParams.SpawnCollisionHandlingOverride = ESpawnActorCollisionHandlingMethod::AlwaysSpawn;
		
		GetWorld()->SpawnActor<AActor>(GoldenMangoKeyClass, KeyLoc, FRotator::ZeroRotator, SpawnParams);
		UE_LOG(LogTemp, Log, TEXT("Airavat dropped the Golden Mango Key!"));
	}

	// Play giant elephant yawn/sleep sound effect
	// UGameplayStatics::PlaySoundAtLocation(GetWorld(), ...);
	
	// Animate collapsing to sleep
	SetActorRotation(FRotator(0.f, GetActorRotation().Yaw, -30.f)); // Tilt body sideways
}

void AAiravatBoss::PerformChargeAttack()
{
	if (bIsCharging) return;

	ACharacter* PlayerChar = UGameplayStatics::GetPlayerCharacter(GetWorld(), 0);
	if (!PlayerChar) return;

	ChargeStartLoc = GetActorLocation();
	FVector DirToPlayer = (PlayerChar->GetActorLocation() - ChargeStartLoc).GetSafeNormal2D();
	ChargeEndLoc = ChargeStartLoc + (DirToPlayer * 1600.f);

	// Rotate towards charge path
	SetActorRotation(DirToPlayer.Rotation());

	bIsCharging = true;
	ChargeLerpTime = 0.f;
	ShockwaveTimer = 0.f;

	UE_LOG(LogTemp, Warning, TEXT("Colossal Airavat trumpets and charges forward!"));
}

void AAiravatBoss::TransitionToPhase2()
{
	CurrentPhase = EAiravatPhase::Phase2_TrunkLash;
	ChargeSpeed *= 1.3f;
	UE_LOG(LogTemp, Warning, TEXT("Airavat enters Phase 2! Trunk lashing and high velocity sweeps active."));
}
