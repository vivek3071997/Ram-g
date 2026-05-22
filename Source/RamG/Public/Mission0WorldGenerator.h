#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Mission0WorldGenerator.generated.h"

class ASacredFruit;
class AVayuWindUpdraft;
class ACloudPlatform;
class ATyakshaEnemy;
class AAiravatBoss;
class AIndraBoss;

UCLASS()
class RAMG_API AMission0WorldGenerator : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AMission0WorldGenerator();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	/** Spawning Blueprints classes for each prologue object */
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "RamG | Spawning Classes")
	TSubclassOf<ASacredFruit> FruitClass;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "RamG | Spawning Classes")
	TSubclassOf<AVayuWindUpdraft> UpdraftClass;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "RamG | Spawning Classes")
	TSubclassOf<ACloudPlatform> CloudPlatformClass;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "RamG | Spawning Classes")
	TSubclassOf<ATyakshaEnemy> TyakshaClass;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "RamG | Spawning Classes")
	TSubclassOf<AAiravatBoss> AiravatClass;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "RamG | Spawning Classes")
	TSubclassOf<AIndraBoss> IndraClass;

	/** Pre-calibrated coordinates for the Sumeru orchard tutorial stage */
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "RamG | Layout - Orchard")
	TArray<FVector> FruitPositions;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "RamG | Layout - Orchard")
	TArray<FVector> TyakshaPositions;

	/** Pre-calibrated coordinates for Sumeru climbing stage (updrafts + cloud pads) */
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "RamG | Layout - Summit Ascent")
	TArray<FVector> UpdraftPositions;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "RamG | Layout - Summit Ascent")
	TArray<FVector> CloudPlatformPositions;

	/** Pre-calibrated boss arena positions */
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "RamG | Layout - Boss Arenas")
	FVector AiravatSpawnLocation;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "RamG | Layout - Boss Arenas")
	FVector IndraSpawnLocation;

	/** Spawned actor tracker to allow clean in-editor wipes */
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "RamG | Generated Instances")
	TArray<AActor*> SpawnedActors;

	/** Spawns and configures all Mission 0 world elements in the level */
	UFUNCTION(CallInEditor, Category = "RamG | Generation")
	void GenerateWorld();

	/** Clears and deletes all programmatically spawned elements to reset the level */
	UFUNCTION(CallInEditor, Category = "RamG | Generation")
	void ClearGeneratedWorld();

private:
	/** Validates that none of the coordinates overlap dangerously */
	bool RunCollisionSafetyCheck(const FVector& Location, float SafeRadius) const;
};
