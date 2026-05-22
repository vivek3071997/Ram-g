#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "IndraBoss.generated.h"

UCLASS()
class RAMG_API AIndraBoss : public ACharacter
{
	GENERATED_BODY()

public:
	AIndraBoss();

protected:
	virtual void BeginPlay() override;

public:	
	virtual void Tick(float DeltaTime) override;

	/** Arena center coordinate for chariot flight path */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Indra | Movement")
	FVector ArenaCenter = FVector(0.f, 0.f, 2000.f);

	/** Chariot orbital flight radius */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Indra | Movement")
	float FlightRadius = 800.f;

	/** Chariot flight rotation speed (degrees per second) */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Indra | Movement")
	float FlightSpeed = 45.f;

	/** Expandable lightning ring class */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Indra | Combat")
	TSubclassOf<AActor> LightningRingClass;

	/** Interval for spawning shockwave lightning rings on floor */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Indra | Combat")
	float RingSpawnInterval = 4.0f;

	float RingTimer = 0.f;

	/** Lightning bolt projectile class */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Indra | Combat")
	TSubclassOf<AActor> LightningSpearClass;

	/** Interval for spear attacks */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Indra | Combat")
	float SpearInterval = 2.0f;

	float SpearTimer = 0.f;

	/** Proximity at which player can grab crown and end battle */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Indra | Transition")
	float CrownGrabRange = 220.f;

	UPROPERTY(BlueprintReadOnly, Category = "Indra | State")
	bool bIsDefeated = false;

	/** Grab crown to trigger Vajra strike event */
	UFUNCTION(BlueprintCallable, Category = "Indra | Transition")
	void GrabCrown(AActor* Attacker);

	/** Fire dynamic lightning ring */
	UFUNCTION(BlueprintCallable, Category = "Indra | Combat")
	void SpawnLightningRing();

	/** Fire high-speed tracking lightning spear */
	UFUNCTION(BlueprintCallable, Category = "Indra | Combat")
	void FireLightningSpear();

private:
	float CurrentAngle = 0.f;
};
