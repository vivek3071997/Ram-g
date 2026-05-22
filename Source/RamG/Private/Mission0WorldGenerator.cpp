#include "Mission0WorldGenerator.h"
#include "SacredFruit.h"
#include "VayuWindUpdraft.h"
#include "CloudPlatform.h"
#include "TyakshaEnemy.h"
#include "AiravatBoss.h"
#include "IndraBoss.h"
#include "Engine/World.h"
#include "Kismet/GameplayStatics.h"
#include "Engine/OverlapResult.h"

// Sets default values
AMission0WorldGenerator::AMission0WorldGenerator()
{
	PrimaryActorTick.bCanEverTick = false;

	// 1. Sumeru Orchard Fruit coordinates (Tutorial & Mango Chase)
	FruitPositions.Add(FVector(-500.f, -300.f, 150.f));
	FruitPositions.Add(FVector(-200.f, 400.f, 200.f));
	FruitPositions.Add(FVector(300.f, -100.f, 180.f));
	FruitPositions.Add(FVector(600.f, 500.f, 250.f));
	FruitPositions.Add(FVector(900.f, -400.f, 220.f));
	FruitPositions.Add(FVector(-800.f, 200.f, 190.f));

	// 2. Tyaksha Forest Imps starting positions (Orchard Chase)
	TyakshaPositions.Add(FVector(-300.f, -200.f, 400.f));
	TyakshaPositions.Add(FVector(400.f, 300.f, 450.f));
	TyakshaPositions.Add(FVector(800.f, -100.f, 420.f));

	// 3. Thermal Ascent (Wind Updrafts supporting vertical launching)
	UpdraftPositions.Add(FVector(2000.f, 0.f, 50.f));
	UpdraftPositions.Add(FVector(3200.f, -300.f, 50.f));
	UpdraftPositions.Add(FVector(4400.f, 400.f, 50.f));

	// 4. Solid Cloud Platforms forming stairs to stratosphere
	CloudPlatformPositions.Add(FVector(2000.f, 0.f, 600.f));
	CloudPlatformPositions.Add(FVector(2400.f, 200.f, 1000.f));
	CloudPlatformPositions.Add(FVector(2800.f, -200.f, 1400.f));
	CloudPlatformPositions.Add(FVector(3200.f, -300.f, 1800.f));
	CloudPlatformPositions.Add(FVector(3600.f, 100.f, 2200.f));
	CloudPlatformPositions.Add(FVector(4000.f, -100.f, 2600.f));
	CloudPlatformPositions.Add(FVector(4400.f, 400.f, 3000.f));
	CloudPlatformPositions.Add(FVector(4800.f, 0.f, 3400.f));

	// 5. Boss Arenas (Airavat grounds clearing & Indra's cosmic storm heights)
	AiravatSpawnLocation = FVector(7000.f, 0.f, 100.f);
	IndraSpawnLocation = FVector(11000.f, 0.f, 4000.f);
}

// Called when the game starts or when spawned
void AMission0WorldGenerator::BeginPlay()
{
	Super::BeginPlay();

	// If spawned at runtime and no elements are present, build them automatically
	if (SpawnedActors.Num() == 0)
	{
		UE_LOG(LogTemp, Log, TEXT("[WORLD GENERATOR] Building Mission 0 level elements dynamically at BeginPlay."));
		GenerateWorld();
	}
}

void AMission0WorldGenerator::GenerateWorld()
{
	// Avoid duplicates - wipe any previously generated items first
	ClearGeneratedWorld();

	UWorld* World = GetWorld();
	if (!World) return;

	UE_LOG(LogTemp, Warning, TEXT("====================================="));
	UE_LOG(LogTemp, Warning, TEXT("[WORLD GENERATOR] Assembling Mission 0 Environment Layout..."));
	UE_LOG(LogTemp, Warning, TEXT("====================================="));

	FActorSpawnParameters SpawnParams;
	SpawnParams.Owner = this;
	SpawnParams.SpawnCollisionHandlingOverride = ESpawnActorCollisionHandlingMethod::AlwaysSpawn;

	// 1. Spawn Sacred Fruits in the orchard
	if (FruitClass)
	{
		for (const FVector& Pos : FruitPositions)
		{
			if (RunCollisionSafetyCheck(Pos, 50.f))
			{
				ASacredFruit* Fruit = World->SpawnActor<ASacredFruit>(FruitClass, Pos, FRotator::ZeroRotator, SpawnParams);
				if (Fruit)
				{
					SpawnedActors.Add(Fruit);
					UE_LOG(LogTemp, Log, TEXT("[SPAWN] Sacred Fruit placed at: %s"), *Pos.ToString());
				}
			}
		}
	}
	else
	{
		UE_LOG(LogTemp, Error, TEXT("[WORLD GENERATOR ERROR] FruitClass reference is missing!"));
	}

	// 2. Spawn Tyaksha Forest Imps in the trees
	if (TyakshaClass)
	{
		for (const FVector& Pos : TyakshaPositions)
		{
			if (RunCollisionSafetyCheck(Pos, 100.f))
			{
				ATyakshaEnemy* Imp = World->SpawnActor<ATyakshaEnemy>(TyakshaClass, Pos, FRotator::ZeroRotator, SpawnParams);
				if (Imp)
				{
					SpawnedActors.Add(Imp);
					UE_LOG(LogTemp, Log, TEXT("[SPAWN] Tyaksha Forest Imp placed at: %s"), *Pos.ToString());
				}
			}
		}
	}
	else
	{
		UE_LOG(LogTemp, Error, TEXT("[WORLD GENERATOR ERROR] TyakshaClass reference is missing!"));
	}

	// 3. Spawn Vayu Wind Updrafts in Sumeru's valleys
	if (UpdraftClass)
	{
		for (const FVector& Pos : UpdraftPositions)
		{
			AVayuWindUpdraft* Updraft = World->SpawnActor<AVayuWindUpdraft>(UpdraftClass, Pos, FRotator::ZeroRotator, SpawnParams);
			if (Updraft)
			{
				SpawnedActors.Add(Updraft);
				UE_LOG(LogTemp, Log, TEXT("[SPAWN] Vayu Wind Updraft placed at: %s"), *Pos.ToString());
			}
		}
	}
	else
	{
		UE_LOG(LogTemp, Error, TEXT("[WORLD GENERATOR ERROR] UpdraftClass reference is missing!"));
	}

	// 4. Spawn Solid Cloud Platforms (Ascending Staircase)
	if (CloudPlatformClass)
	{
		for (const FVector& Pos : CloudPlatformPositions)
		{
			if (RunCollisionSafetyCheck(Pos, 150.f))
			{
				ACloudPlatform* Cloud = World->SpawnActor<ACloudPlatform>(CloudPlatformClass, Pos, FRotator::ZeroRotator, SpawnParams);
				if (Cloud)
				{
					SpawnedActors.Add(Cloud);
					UE_LOG(LogTemp, Log, TEXT("[SPAWN] Dissolving Cloud Platform placed at: %s"), *Pos.ToString());
				}
			}
		}
	}
	else
	{
		UE_LOG(LogTemp, Error, TEXT("[WORLD GENERATOR ERROR] CloudPlatformClass reference is missing!"));
	}

	// 5. Spawn Boss 1: Colossal Ivory Elephant Airavat
	if (AiravatClass)
	{
		AAiravatBoss* Airavat = World->SpawnActor<AAiravatBoss>(AiravatClass, AiravatSpawnLocation, FRotator::ZeroRotator, SpawnParams);
		if (Airavat)
		{
			// Scale elephant to massive dimensions (4x) as designated by GDD specs
			Airavat->SetActorScale3D(FVector(4.f, 4.f, 4.f));
			SpawnedActors.Add(Airavat);
			UE_LOG(LogTemp, Log, TEXT("[SPAWN] Colossal Boss Airavat placed at: %s (Scaled 4x)"), *AiravatSpawnLocation.ToString());
		}
	}
	else
	{
		UE_LOG(LogTemp, Error, TEXT("[WORLD GENERATOR ERROR] AiravatClass reference is missing!"));
	}

	// 6. Spawn Boss 2: Lord Indra on Sky Chariot
	if (IndraClass)
	{
		AIndraBoss* Indra = World->SpawnActor<AIndraBoss>(IndraClass, IndraSpawnLocation, FRotator::ZeroRotator, SpawnParams);
		if (Indra)
		{
			SpawnedActors.Add(Indra);
			UE_LOG(LogTemp, Log, TEXT("[SPAWN] Sky Chariot Lord Indra placed at: %s"), *IndraSpawnLocation.ToString());
		}
	}
	else
	{
		UE_LOG(LogTemp, Error, TEXT("[WORLD GENERATOR ERROR] IndraClass reference is missing!"));
	}

	UE_LOG(LogTemp, Warning, TEXT("====================================="));
	UE_LOG(LogTemp, Warning, TEXT("[WORLD GENERATOR] Level assembly complete. Created %d actors."), SpawnedActors.Num());
	UE_LOG(LogTemp, Warning, TEXT("====================================="));
}

void AMission0WorldGenerator::ClearGeneratedWorld()
{
	int32 DestroyedCount = 0;

	// Destroy tracked instances
	for (AActor* Actor : SpawnedActors)
	{
		if (Actor && Actor->IsValidLowLevel())
		{
			Actor->Destroy();
			DestroyedCount++;
		}
	}

	SpawnedActors.Empty();

	// Robust fallback: Sweep editor world for floating items of our types to avoid orphans
	UWorld* World = GetWorld();
	if (World)
	{
		TArray<AActor*> OrphanFruits;
		UGameplayStatics::GetAllActorsOfClass(World, ASacredFruit::StaticClass(), OrphanFruits);
		for (AActor* O : OrphanFruits) { if (O && O->GetOwner() == this) { O->Destroy(); DestroyedCount++; } }

		TArray<AActor*> OrphanImps;
		UGameplayStatics::GetAllActorsOfClass(World, ATyakshaEnemy::StaticClass(), OrphanImps);
		for (AActor* O : OrphanImps) { if (O && O->GetOwner() == this) { O->Destroy(); DestroyedCount++; } }

		TArray<AActor*> OrphanUpdrafts;
		UGameplayStatics::GetAllActorsOfClass(World, AVayuWindUpdraft::StaticClass(), OrphanUpdrafts);
		for (AActor* O : OrphanUpdrafts) { if (O && O->GetOwner() == this) { O->Destroy(); DestroyedCount++; } }

		TArray<AActor*> OrphanClouds;
		UGameplayStatics::GetAllActorsOfClass(World, ACloudPlatform::StaticClass(), OrphanClouds);
		for (AActor* O : OrphanClouds) { if (O && O->GetOwner() == this) { O->Destroy(); DestroyedCount++; } }

		TArray<AActor*> OrphanAiravats;
		UGameplayStatics::GetAllActorsOfClass(World, AAiravatBoss::StaticClass(), OrphanAiravats);
		for (AActor* O : OrphanAiravats) { if (O && O->GetOwner() == this) { O->Destroy(); DestroyedCount++; } }

		TArray<AActor*> OrphanIndras;
		UGameplayStatics::GetAllActorsOfClass(World, AIndraBoss::StaticClass(), OrphanIndras);
		for (AActor* O : OrphanIndras) { if (O && O->GetOwner() == this) { O->Destroy(); DestroyedCount++; } }
	}

	if (DestroyedCount > 0)
	{
		UE_LOG(LogTemp, Warning, TEXT("[WORLD GENERATOR] Cleaned up %d level elements successfully."), DestroyedCount);
	}
}

bool AMission0WorldGenerator::RunCollisionSafetyCheck(const FVector& Location, float SafeRadius) const
{
	// Safety logic: ensures that spawning points do not overlap directly with pre-existing elements
	UWorld* World = GetWorld();
	if (!World) return false;

	FCollisionShape SphereCollision = FCollisionShape::MakeSphere(SafeRadius);
	FCollisionQueryParams Params;
	Params.AddIgnoredActor(this);

	// Perform a simple sweep checking if structural ground or barriers already occupy the space
	TArray<FOverlapResult> Overlaps;
	bool bHasOverlap = World->OverlapMultiByObjectType(
		Overlaps,
		Location,
		FQuat::Identity,
		FCollisionObjectQueryParams(FCollisionObjectQueryParams::AllStaticObjects),
		SphereCollision,
		Params
	);

	if (bHasOverlap)
	{
		UE_LOG(LogTemp, Warning, TEXT("[SAFETY CHECK] Location %s blocked by structural obstacles. Skipping spawn."), *Location.ToString());
		return false;
	}

	return true;
}
