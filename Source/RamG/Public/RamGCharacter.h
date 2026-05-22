#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "RamGCharacter.generated.h"

class UGroundedCharacterData;
class UInputMappingContext;
class UInputAction;
struct FInputActionValue;

UCLASS()
class RAMG_API ARamGCharacter : public ACharacter
{
	GENERATED_BODY()

public:
	// Sets default values for this character's properties
	ARamGCharacter();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

	/** Character Attributes Configuration */
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "RamG | Character Data", meta = (AllowPrivateAccess = "true"))
	UGroundedCharacterData* CharacterData;

	/** Current Physiological Pools */
	UPROPERTY(BlueprintReadOnly, Category = "RamG | Attributes")
	float CurrentStamina;

	UPROPERTY(BlueprintReadOnly, Category = "RamG | Attributes")
	float CurrentFocus;

	UPROPERTY(BlueprintReadOnly, Category = "RamG | Attributes")
	float CurrentLacticAcid;

	/** State flags */
	UPROPERTY(BlueprintReadOnly, Category = "RamG | Attributes")
	bool bIsPranayamaActive;

	UPROPERTY(BlueprintReadOnly, Category = "RamG | Attributes")
	bool bIsExhausted;

	/** Configuration Settings */
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "RamG | Tuning")
	float DashStaminaCost = 25.f;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "RamG | Tuning")
	float PranayamaFocusCostPerSecond = 15.f;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "RamG | Tuning")
	float PranayamaTimeDilationFactor = 0.5f;

	/** Character Combat & Ability Hooks */
	UFUNCTION(BlueprintCallable, Category = "RamG | Combat")
	void StartPranayamaFocus();

	UFUNCTION(BlueprintCallable, Category = "RamG | Combat")
	void StopPranayamaFocus();

	UFUNCTION(BlueprintCallable, Category = "RamG | Combat")
	void PerformDash();

protected:
	/** Enhanced Input Action Handlers */
	void Move(const FInputActionValue& Value);
	void Look(const FInputActionValue& Value);

	/** Recovery updates */
	void UpdatePhysiologicalMetabolism(float DeltaTime);

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "RamG | Input")
	UInputMappingContext* DefaultMappingContext;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "RamG | Input")
	UInputAction* MoveAction;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "RamG | Input")
	UInputAction* LookAction;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "RamG | Input")
	UInputAction* DashAction;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "RamG | Input")
	UInputAction* FocusAction;
};
