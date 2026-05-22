#pragma once

#include "CoreMinimal.h"
#include "RamGCharacter.h"
#include "SitaCharacter.generated.h"

UCLASS()
class RAMG_API ASitaCharacter : public ARamGCharacter
{
	GENERATED_BODY()

public:
	ASitaCharacter();

protected:
	virtual void BeginPlay() override;

public:
	virtual void Tick(float DeltaTime) override;
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

	/** Playable States */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Sita | State")
	bool bIsChildhoodState = true;

	UPROPERTY(BlueprintReadOnly, Category = "Sita | State")
	bool bIsValkalaEquipped = false;

	/** Earth Aura Pulse (Bhumi Spandan) configuration */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Sita | Earth Ability")
	float EarthAuraRadius = 800.f;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Sita | Earth Ability")
	float BhumiSpandanCooldown = 3.f;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Sita | Earth Ability")
	float BhumiSpandanStaminaCost = 20.f;

	UPROPERTY(BlueprintReadOnly, Category = "Sita | Earth Ability")
	bool bBhumiSpandanActive = false;

	float BhumiSpandanTimer = 0.f;

	/** Ganga-Jal (Holy Water) purification configuration */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Sita | Purification")
	int32 GangaJalFlaskCount = 10;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Sita | Purification")
	float PurifyingFlaskRange = 1200.f;

	/** Earth Spells (Adult State) */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Sita | Earth Ability")
	float EarthShieldCooldown = 5.f;

	float EarthShieldTimer = 0.f;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Sita | Earth Ability")
	float EarthResonanceStaminaCost = 15.f;

	/** Earth Aura Pulse (Bhumi Spandan) */
	UFUNCTION(BlueprintCallable, Category = "Sita | Earth Ability")
	void TriggerBhumiSpandan();

	/** Ganga-Jal (Holy Water) Purifying Flask throwing */
	UFUNCTION(BlueprintCallable, Category = "Sita | Purification")
	void ThrowGangaJalFlask();

	/** Spawns stone mud-domes to absorb Sage Parashurama's supersonic shockwaves */
	UFUNCTION(BlueprintCallable, Category = "Sita | Earth Ability")
	void SpawnEarthShield();

	/** Channels earth resonance to boost Rama's footing, counteracting pressure fields */
	UFUNCTION(BlueprintCallable, Category = "Sita | Earth Ability")
	void ApplyEarthResonanceBuff(class ARamaCharacter* TargetRama);

	/** Exiles Princess Sita to forest, stripping armor/charms, reducing Max HP by 50% */
	UFUNCTION(BlueprintCallable, Category = "Sita | Banishment")
	void ExecuteValkalaSwap();

protected:
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Sita | Input")
	UInputAction* SpandanAction;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Sita | Input")
	UInputAction* GangaJalAction;
};
