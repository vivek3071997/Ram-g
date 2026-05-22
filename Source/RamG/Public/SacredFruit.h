#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "SacredFruit.generated.h"

class USphereComponent;
class UStaticMeshComponent;

UCLASS()
class RAMG_API ASacredFruit : public AActor
{
	GENERATED_BODY()
	
public:	
	ASacredFruit();

protected:
	virtual void BeginPlay() override;

public:	
	virtual void Tick(float DeltaTime) override;

	/** Sphere collision for picking up the fruit */
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Fruit | Components")
	USphereComponent* CollisionComponent;

	/** Static mesh representation of the sacred fruit */
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Fruit | Components")
	UStaticMeshComponent* MeshComponent;

	/** Gold-orange aura shine scale */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Fruit | FX")
	float AuraIntensity = 100.f;

	/** Yaw rotation speed for floating effect */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Fruit | Floating")
	float RotationSpeed = 90.f;

	/** Bobbing amplitude */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Fruit | Floating")
	float BobbingAmplitude = 15.f;

	/** Bobbing frequency */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Fruit | Floating")
	float BobbingFrequency = 2.f;

	/** Called when a player character overlaps with this fruit */
	UFUNCTION()
	virtual void OnOverlapBegin(UPrimitiveComponent* OverlappedComp, AActor* OtherActor, 
								UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, 
								bool bFromSweep, const FHitResult& SweepResult);

private:
	FVector InitialLocation;
	float RunningTime = 0.f;
};
