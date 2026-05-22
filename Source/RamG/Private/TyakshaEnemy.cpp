#include "TyakshaEnemy.h"
#include "Components/CapsuleComponent.h"
#include "GameFramework/CharacterMovementComponent.h"
#include "Kismet/GameplayStatics.h"
#include "SacredFruit.h"

ATyakshaEnemy::ATyakshaEnemy()
{
	PrimaryActorTick.bCanEverTick = true;

	// Tiny imp capsule bounds
	GetCapsuleComponent()->InitCapsuleSize(25.f, 45.f);

	// Light physical movement settings
	GetCharacterMovement()->GravityScale = 1.0f;
	GetCharacterMovement()->MaxWalkSpeed = 450.f;
	GetCharacterMovement()->JumpZVelocity = 500.f;
	GetCharacterMovement()->AirControl = 0.5f;

	// Scale down visual mesh to represent small forest imp
	GetMesh()->SetRelativeScale3D(FVector(0.5f, 0.5f, 0.5f));

	Posture = 100.f;
	bIsTickled = false;
	LeapTimer = 0.f;
	ShootTimer = 0.f;
}

void ATyakshaEnemy::BeginPlay()
{
	Super::BeginPlay();

	// Populate branches around initial spawn if empty
	if (EscapeBranches.Num() == 0)
	{
		FVector BaseLoc = GetActorLocation();
		EscapeBranches.Add(BaseLoc + FVector(400.f, 400.f, 250.f));
		EscapeBranches.Add(BaseLoc + FVector(-400.f, 400.f, 350.f));
		EscapeBranches.Add(BaseLoc + FVector(400.f, -400.f, 150.f));
		EscapeBranches.Add(BaseLoc + FVector(-400.f, -400.f, 300.f));
	}
}

void ATyakshaEnemy::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	if (bIsTickled)
	{
		return; // Staggered by tickling, do nothing
	}

	// 1. Handle Leap Timing
	LeapTimer += DeltaTime;
	if (LeapTimer >= LeapInterval)
	{
		LeapTimer = 0.f;
		LeapToRandomBranch();
	}

	// 2. Handle Shooting
	ShootTimer += DeltaTime;
	if (ShootTimer >= ShootInterval)
	{
		ShootTimer = 0.f;
		AttackPlayer();
	}

	// 3. Smooth Leap tracking
	if (bIsLeaping)
	{
		float DistanceToTarget = FVector::Dist(GetActorLocation(), CurrentLeapTarget);
		if (DistanceToTarget < 100.f)
		{
			bIsLeaping = false;
			GetCharacterMovement()->Velocity = FVector::ZeroVector;
		}
	}
}

void ATyakshaEnemy::LeapToRandomBranch()
{
	if (EscapeBranches.Num() == 0) return;

	int32 RandomIndex = FMath::RandRange(0, EscapeBranches.Num() - 1);
	
	// Prevent picking same branch
	if (RandomIndex == CurrentTargetBranchIndex && EscapeBranches.Num() > 1)
	{
		RandomIndex = (RandomIndex + 1) % EscapeBranches.Num();
	}

	CurrentTargetBranchIndex = RandomIndex;
	CurrentLeapTarget = EscapeBranches[CurrentTargetBranchIndex];
	bIsLeaping = true;

	// Turn towards target branch
	FVector Dir = CurrentLeapTarget - GetActorLocation();
	FRotator LookRot = Dir.Rotation();
	LookRot.Pitch = 0.f;
	LookRot.Roll = 0.f;
	SetActorRotation(LookRot);

	// Launch character towards branch in a parabolic arc
	FVector LeapVelocity = Dir.GetSafeNormal2D() * MoveLeapForce;
	LeapVelocity.Z = 450.f; // Ascend factor
	
	LaunchCharacter(LeapVelocity, true, true);
}

void ATyakshaEnemy::AttackPlayer()
{
	ACharacter* PlayerChar = UGameplayStatics::GetPlayerCharacter(GetWorld(), 0);
	if (!PlayerChar) return;

	// Look towards player
	FVector Dir = PlayerChar->GetActorLocation() - GetActorLocation();
	FRotator LookRot = Dir.Rotation();
	LookRot.Pitch = 0.f;
	SetActorRotation(LookRot);

	// Throw seed projectile (simulated by trace or spawning simple projectile)
	if (ProjectileClass)
	{
		FVector SpawnLocation = GetActorLocation() + GetActorForwardVector() * 50.f;
		FRotator SpawnRotation = (PlayerChar->GetActorLocation() - SpawnLocation).Rotation();
		
		FActorSpawnParameters SpawnParams;
		SpawnParams.Owner = this;
		SpawnParams.Instigator = this;
		
		GetWorld()->SpawnActor<AActor>(ProjectileClass, SpawnLocation, SpawnRotation, SpawnParams);
	}
	else
	{
		// Fallback debug tracer
		UE_LOG(LogTemp, Warning, TEXT("Tyaksha throws prickly seed towards player!"));
	}
}

void ATyakshaEnemy::TakeNonLethalStrike(float Damage, float PostureDmg, AActor* Attacker)
{
	if (bIsTickled) return;

	Posture -= PostureDmg;
	UE_LOG(LogTemp, Log, TEXT("Tyaksha hit by %s! Posture: %f/100"), *Attacker->GetName(), Posture);

	if (Posture <= 0.f)
	{
		bIsTickled = true;
		
		// Drop a sacred fruit
		if (SacredFruitClass)
		{
			FVector DropLoc = GetActorLocation();
			DropLoc.Z -= 20.f; // Align close to floor
			FRotator DropRot = FRotator::ZeroRotator;
			
			FActorSpawnParameters SpawnParams;
			SpawnParams.SpawnCollisionHandlingOverride = ESpawnActorCollisionHandlingMethod::AlwaysSpawn;
			
			GetWorld()->SpawnActor<AActor>(SacredFruitClass, DropLoc, DropRot, SpawnParams);
			UE_LOG(LogTemp, Log, TEXT("Tyaksha dropped a sacred fruit!"));
		}

		// Play high giggling sound loop
		// UGameplayStatics::PlaySoundAtLocation(GetWorld(), ...);
		
		// Flee: Leap high up and disappear after a short delay
		LaunchCharacter(FVector(0.f, 0.f, 1000.f), true, true);
		
		FTimerHandle DestroyTimer;
		GetWorldTimerManager().SetTimer(DestroyTimer, [this]() {
			Destroy();
		}, 1.2s, false);
	}
}
