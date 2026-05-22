#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "TyakshaEnemy.generated.h"

UCLASS()
class RAMG_API ATyakshaEnemy : public ACharacter
{
	GENERATED_BODY()

public:
	ATyakshaEnemy();

protected:
	virtual void BeginPlay() override;

public:	
	virtual void Tick(float DeltaTime) override;

	/** Navigation locations representing orchard tree/rock branches */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Tyaksha | AI")
	TArray<FVector> EscapeBranches;

	/** Current branch target index */
	int32 CurrentTargetBranchIndex = -1;

	/** Move velocity scale during leaps */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Tyaksha | AI")
	float MoveLeapForce = 900.f;

	/** Time remaining before leaping to another branch */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Tyaksha | AI")
	float LeapInterval = 4.f;

	float LeapTimer = 0.f;

	/** Projectile class to throw */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Tyaksha | Combat")
	TSubclassOf<AActor> ProjectileClass;

	/** Frequency of seed throwing */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Tyaksha | Combat")
	float ShootInterval = 2.5f;

	float ShootTimer = 0.f;

	/** Posture value (tickle threshold) */
	UPROPERTY(BlueprintReadOnly, Category = "Tyaksha | Combat")
	float Posture = 100.f;

	UPROPERTY(BlueprintReadOnly, Category = "Tyaksha | Combat")
	bool bIsTickled = false;

	/** Class of Sacred Fruit to drop */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Tyaksha | Combat")
	TSubclassOf<AActor> SacredFruitClass;

	/** Called by Hanuman Character when hit by Kid Fists */
	UFUNCTION(BlueprintCallable, Category = "Tyaksha | Actions")
	void TakeNonLethalStrike(float Damage, float PostureDmg, AActor* Attacker);

	/** Move to a random branch */
	UFUNCTION(BlueprintCallable, Category = "Tyaksha | AI")
	void LeapToRandomBranch();

	/** Target and throw a seed projectile */
	UFUNCTION(BlueprintCallable, Category = "Tyaksha | Combat")
	void AttackPlayer();

private:
	FVector CurrentLeapTarget;
	bool bIsLeaping = false;
};
