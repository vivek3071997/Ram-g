#pragma once

#include "CoreMinimal.h"
#include "RamGCharacter.h"
#include "HanumanCharacter.generated.h"

UCLASS()
class RAMG_API AHanumanCharacter : public ARamGCharacter
{
	GENERATED_BODY()

public:
	AHanumanCharacter();

protected:
	virtual void BeginPlay() override;

public:
	virtual void Tick(float DeltaTime) override;
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

	/** Double Jump Logic */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Hanuman | Movement")
	int32 MaxJumpCount = 2;

	UPROPERTY(BlueprintReadOnly, Category = "Hanuman | Movement")
	int32 CurrentJumpCount = 0;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Hanuman | Movement")
	float DoubleJumpLaunchForce = 650.f;

	virtual void Jump() override;
	virtual void Landed(const FHitResult& Hit) override;

	/** Tail Grapple System */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Hanuman | Grapple")
	float GrappleMaxRange = 1500.f;

	UPROPERTY(BlueprintReadOnly, Category = "Hanuman | Grapple")
	bool bIsGrappling = false;

	UPROPERTY(BlueprintReadOnly, Category = "Hanuman | Grapple")
	FVector GrappleAnchorPoint;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Hanuman | Grapple")
	float GrappleSwingStiffness = 8.0f;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Hanuman | Grapple")
	float GrappleSwingDampening = 2.0f;

	UFUNCTION(BlueprintCallable, Category = "Hanuman | Grapple")
	void StartGrapple();

	UFUNCTION(BlueprintCallable, Category = "Hanuman | Grapple")
	void StopGrapple();

	void UpdateGrapplePhysics(float DeltaTime);

	/** Kid Fists Combat */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Hanuman | Combat")
	float KidFistsDamage = 15.f;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Hanuman | Combat")
	float KidFistsPostureDamage = 45.f;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Hanuman | Combat")
	float KidFistsReach = 150.f;

	UFUNCTION(BlueprintCallable, Category = "Hanuman | Combat")
	void PerformKidFistsAttack();

	/** Mango Basket Inventory */
	UPROPERTY(BlueprintReadOnly, Category = "Hanuman | Inventory")
	int32 FruitsCollected = 0;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Hanuman | Inventory")
	int32 TotalRequiredFruits = 5;

	UFUNCTION(BlueprintCallable, Category = "Hanuman | Inventory")
	void CollectSacredFruit();

	UFUNCTION(BlueprintPure, Category = "Hanuman | Inventory")
	bool IsBasketFull() const { return FruitsCollected >= TotalRequiredFruits; }

protected:
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Hanuman | Input")
	UInputAction* GrappleAction;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Hanuman | Input")
	UInputAction* AttackAction;
};
