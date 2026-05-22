#include "BhumisuraEnemy.h"
#include "GameFramework/CharacterMovementComponent.h"
#include "Kismet/GameplayStatics.h"
#include "Engine/World.h"
#include "DrawDebugHelpers.h"

ABhumisuraEnemy::ABhumisuraEnemy()
{
	PrimaryActorTick.bCanEverTick = true;

	bIsBurrowed = true;
	bIsPurified = false;
	bIsStaggered = false;

	StaggerDuration = 3.f;
	StaggerTimer = 0.f;

	BurrowSpeed = 350.f;
	EmergeSpeed = 150.f;

	MudSpitDamage = 10.f;
	MudSpitInterval = 4.f;
	MudSpitTimer = 0.f;
}

void ABhumisuraEnemy::BeginPlay()
{
	Super::BeginPlay();

	// Set initial gopher speed to burrow movement speed
	GetCharacterMovement()->MaxWalkSpeed = BurrowSpeed;
	UE_LOG(LogTemp, Log, TEXT("[BHUMISURA INITIALIZE] %s spawns, burrowing underground. Dirt mounds active."), *GetName());
}

void ABhumisuraEnemy::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	// 1. Process stagger recovery
	if (bIsStaggered)
	{
		StaggerTimer -= DeltaTime;
		if (StaggerTimer <= 0.f)
		{
			bIsStaggered = false;
			StaggerTimer = 0.f;
			
			// Re-burrow underground if not purified
			if (!bIsPurified)
			{
				bIsBurrowed = true;
				GetCharacterMovement()->MaxWalkSpeed = BurrowSpeed;
				UE_LOG(LogTemp, Warning, TEXT("[BHUMISURA RE-BURROW] %s escapes subterranean aura, slipping back under the soil."), *GetName());
			}
		}
	}

	// 2. Process mud spitting mechanics (only if emerged, not purified, and not staggered)
	if (!bIsBurrowed && !bIsPurified && !bIsStaggered)
	{
		MudSpitTimer += DeltaTime;
		if (MudSpitTimer >= MudSpitInterval)
		{
			MudSpitTimer = 0.f;
			APawn* PlayerPawn = UGameplayStatics::GetPlayerPawn(GetWorld(), 0);
			if (PlayerPawn)
			{
				SpitPoisonMud(PlayerPawn);
			}
		}
	}

	// 3. Update gopher AI navigation paths
	UpdateBurrowBehavior(DeltaTime);
}

void ABhumisuraEnemy::RevealAndEmerge()
{
	if (bIsPurified) return;

	bIsBurrowed = false;
	bIsStaggered = true;
	StaggerTimer = StaggerDuration;

	// Slow down significantly while exposed
	GetCharacterMovement()->MaxWalkSpeed = EmergeSpeed;

	UE_LOG(LogTemp, Warning, TEXT("[BHUMISURA EMERGE] %s was hit by Earth Aura Pulse (Bhumi Spandan)! Surface coordinates exposed, gopher staggered!"), *GetName());

#if WITH_EDITOR
	DrawDebugCapsule(GetWorld(), GetActorLocation(), 90.f, 45.f, FQuat::Identity, FColor::Red, false, 2.f, 0, 2.f);
#endif
}

void ABhumisuraEnemy::Purify(AActor* Purifier)
{
	if (bIsPurified) return;

	bIsPurified = true;
	bIsBurrowed = false;
	bIsStaggered = false;
	StaggerTimer = 0.f;

	// Fleeing speed
	GetCharacterMovement()->MaxWalkSpeed = 600.f;

	UE_LOG(LogTemp, Error, TEXT("[BHUMISURA PURIFIED] Ganga-Jal purification successful! %s converts into a glowing, harmless forest rabbit and leaps away into the wood!"), *GetName());

#if WITH_EDITOR
	DrawDebugString(GetWorld(), GetActorLocation() + FVector(0.f, 0.f, 100.f), TEXT("🐰 Purified!"), nullptr, FColor::Cyan, 2.f, true, 1.5f);
#endif
}

void ABhumisuraEnemy::SpitPoisonMud(AActor* TargetPlayer)
{
	if (!TargetPlayer) return;

	UE_LOG(LogTemp, Warning, TEXT("[BHUMISURA ATTACK] %s spits corrosive mud at player (%s)! Mud inflicts %f damage and covers camera."), *GetName(), *TargetPlayer->GetName(), MudSpitDamage);

#if WITH_EDITOR
	DrawDebugSphere(GetWorld(), GetActorLocation() + FVector(0.f, 0.f, 50.f), 15.f, 8, FColor::Magenta, false, 1.f, 0, 1.5f);
#endif
}

void ABhumisuraEnemy::UpdateBurrowBehavior(float DeltaTime)
{
	// Gophers shift their locations dynamically
	if (bIsBurrowed && !bIsPurified)
	{
		// Soil tunneling simulation: move character capsule
		AddMovementInput(GetActorForwardVector(), 0.5f);
	}
	else if (bIsPurified)
	{
		// Flee away from origin coordinates
		AddMovementInput(-GetActorForwardVector(), 1.0f);
	}
}
