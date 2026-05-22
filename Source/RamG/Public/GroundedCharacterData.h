#pragma once

#include "CoreMinimal.h"
#include "Engine/DataAsset.h"
#include "GroundedCharacterData.generated.h"

UENUM(BlueprintType)
enum class EGddCharacterTier : uint8
{
	Divine              UMETA(DisplayName = "Divine"),
	DivineHumanAvatar   UMETA(DisplayName = "Divine Human (Avatar)"),
	StrongMortal        UMETA(DisplayName = "Strong Mortal"),
	WeakMortal          UMETA(DisplayName = "Weak Mortal")
};

UCLASS(BlueprintType)
class RAMG_API UGroundedCharacterData : public UDataAsset
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Identification")
	FString CharacterName;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Identification")
	FString SanskritName;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Identification")
	EGddCharacterTier CharacterTier = EGddCharacterTier::WeakMortal;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Physiology")
	float HeightInMeters = 1.8f;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Physiology")
	float WeightInKg = 80.0f;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Physiology", meta = (ToolTip = "Signal transmission delay in ms"))
	float NeurologicalLatencyMs = 200.f;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Physiology", meta = (ToolTip = "Cardiovascular efficiency in L/min"))
	float MaxCardiacOutputLMin = 25.f;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Physiology", meta = (ToolTip = "Anaerobic threshold in mmol/L"))
	float LacticAcidThresholdMmol = 4.f;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Physiology", meta = (ToolTip = "ATP energy replenishment rate in J/s"))
	float AtpRecoveryRateJs = 10.f;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Combat", meta = (ToolTip = "Focus/Willpower capacity in Joules"))
	float MaxFocusCapacityJoules = 100.f;
};
