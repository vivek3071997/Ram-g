#include "IndraBoss.h"
#include "Components/CapsuleComponent.h"
#include "GameFramework/CharacterMovementComponent.h"
#include "Kismet/GameplayStatics.h"

AIndraBoss::AIndraBoss()
{
	PrimaryActorTick.bCanEverTick = true;

	// Fly setting
	GetCharacterMovement()->SetMovementMode(EMovementMode::MOVE_Flying);
	GetCharacterMovement()->GravityScale = 0.f;
	GetCharacterMovement()->MaxFlySpeed = 600.f;

	// Scale crown/chariot visual representation
	SetActorScale3D(FVector(1.5f, 1.5f, 1.5f));

	CurrentAngle = 0.f;
	bIsDefeated = false;
	RingTimer = 0.f;
	SpearTimer = 0.f;
}

void AIndraBoss::BeginPlay()
{
	Super::BeginPlay();
	
	ArenaCenter = GetActorLocation();
}

void AIndraBoss::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	if (bIsDefeated)
	{
		return;
	}

	// 1. Orbital Chariot Flight
	CurrentAngle += FlightSpeed * DeltaTime;
	if (CurrentAngle >= 360.f)
	{
		CurrentAngle -= 360.f;
	}

	float Rad = FMath::DegreesToRadians(CurrentAngle);
	FVector NewLocation = ArenaCenter;
	NewLocation.X += FMath::Cos(Rad) * FlightRadius;
	NewLocation.Y += FMath::Sin(Rad) * FlightRadius;
	
	// Float slightly up and down in a slow sine wave
	NewLocation.Z += FMath::Sin(CurrentAngle * 0.1f) * 80.f;
	SetActorLocation(NewLocation, true);

	// Rotate towards player character
	ACharacter* PlayerChar = UGameplayStatics::GetPlayerCharacter(GetWorld(), 0);
	if (PlayerChar)
	{
		FVector DirToPlayer = PlayerChar->GetActorLocation() - GetActorLocation();
		FRotator LookRot = DirToPlayer.Rotation();
		SetActorRotation(LookRot);

		// 2. Proximity Check for Crown Grab
		float DistanceToPlayer = FVector::Dist(GetActorLocation(), PlayerChar->GetActorLocation());
		if (DistanceToPlayer <= CrownGrabRange)
		{
			// Player reached Indra! Grab crown
			GrabCrown(PlayerChar);
		}
	}

	// 3. Combat Loops
	RingTimer += DeltaTime;
	if (RingTimer >= RingSpawnInterval)
	{
		RingTimer = 0.f;
		SpawnLightningRing();
	}

	SpearTimer += DeltaTime;
	if (SpearTimer >= SpearInterval)
	{
		SpearTimer = 0.f;
		FireLightningSpear();
	}
}

void AIndraBoss::GrabCrown(AActor* Attacker)
{
	if (bIsDefeated) return;

	bIsDefeated = true;
	
	UE_LOG(LogTemp, Warning, TEXT("Hanuman leaps onto Indra's chariot and grabs his golden crown!"));
	
	// Notify the custom Mission 0 Game Mode to trigger the Vajra strike callback
	AGameModeBase* GM = UGameplayStatics::GetGameMode(GetWorld());
	if (GM)
	{
		UFunction* TriggerVajraFunc = GM->FindFunction(FName("TriggerVajraNerfSequence"));
		if (TriggerVajraFunc)
		{
			GM->ProcessEvent(TriggerVajraFunc, nullptr);
		}
		else
		{
			UE_LOG(LogTemp, Warning, TEXT("TriggerVajraNerfSequence function not found in GameMode."));
		}
	}

	// Play crash boom audio and chariot impact
	// UGameplayStatics::PlaySoundAtLocation(GetWorld(), ...);
}

void AIndraBoss::SpawnLightningRing()
{
	ACharacter* PlayerChar = UGameplayStatics::GetPlayerCharacter(GetWorld(), 0);
	if (!PlayerChar) return;

	// Spawn expanding electric damage ring on the cloud floor
	FVector SpawnLoc = PlayerChar->GetActorLocation();
	SpawnLoc.Z -= 80.f; // floor level

	if (LightningRingClass)
	{
		FActorSpawnParameters SpawnParams;
		SpawnParams.SpawnCollisionHandlingOverride = ESpawnActorCollisionHandlingMethod::AlwaysSpawn;
		GetWorld()->SpawnActor<AActor>(LightningRingClass, SpawnLoc, FRotator::ZeroRotator, SpawnParams);
	}
	
	UE_LOG(LogTemp, Log, TEXT("Indra spawns a blue expanding lightning ring at player floor!"));
}

void AIndraBoss::FireLightningSpear()
{
	ACharacter* PlayerChar = UGameplayStatics::GetPlayerCharacter(GetWorld(), 0);
	if (!PlayerChar) return;

	FVector SpawnLoc = GetActorLocation() + GetActorForwardVector() * 80.f;
	FRotator SpawnRot = (PlayerChar->GetActorLocation() - SpawnLoc).Rotation();

	if (LightningSpearClass)
	{
		FActorSpawnParameters SpawnParams;
		SpawnParams.Owner = this;
		GetWorld()->SpawnActor<AActor>(LightningSpearClass, SpawnLoc, SpawnRot, SpawnParams);
	}
	
	UE_LOG(LogTemp, Log, TEXT("Indra hurls a crackling blue lightning spear!"));
}
