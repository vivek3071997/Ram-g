#pragma once

#include "CoreMinimal.h"
#include "RamGCharacter.h"
#include "RamaCharacter.generated.h"

UCLASS()
class RAMG_API ARamaCharacter : public ARamGCharacter
{
	GENERATED_BODY()

public:
	// Sets default values for this character's properties
	ARamaCharacter();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

	/** Prince Rama Ability & Stat Configurations */
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "RamG | Archery")
	float MaxDrawForce = 1.0f;

	UPROPERTY(BlueprintReadOnly, Category = "RamG | Archery")
	float CurrentDrawForce = 0.0f;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "RamG | Archery")
	float BowStaminaCostRate = 20.0f;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "RamG | Archery")
	int32 AgneyastraCharges = 3;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "RamG | Archery")
	int32 IronPointArrows = 30;

	/** Shabda-Bhedi Vidya focus parameters */
	UPROPERTY(BlueprintReadOnly, Category = "RamG | Focus Ability")
	bool bIsShabdaBhediActive = false;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "RamG | Focus Ability")
	float ShabdaBhediFocusCostRate = 12.0f;

	/** Courtly Disarmament State Lock */
	UPROPERTY(BlueprintReadOnly, Category = "RamG | Disarmament")
	bool bWeaponsLocked = false;

	/** Archery Mechanics */
	UFUNCTION(BlueprintCallable, Category = "RamG | Archery")
	void StartDrawBow();

	UFUNCTION(BlueprintCallable, Category = "RamG | Archery")
	void ReleaseBow();

	UFUNCTION(BlueprintCallable, Category = "RamG | Archery")
	void FireAgneyastra();

	/** Focus Mechanics */
	UFUNCTION(BlueprintCallable, Category = "RamG | Focus Ability")
	void ToggleShabdaBhediVidya();

	/** Surrenders all physical weapons, locking all bows, blades, and astras */
	UFUNCTION(BlueprintCallable, Category = "RamG | Disarmament")
	void SurrenderAllWeapons();

	/** Sound Tracking: Calculates relative vector towards an invisible sound-source in fog/darkness */
	UFUNCTION(BlueprintPure, Category = "RamG | Focus Ability")
	FVector GetShabdaBhediDirectionToSoundSource(const FVector& SoundSourceLocation) const;

private:
	bool bIsDrawingBow = false;
};
