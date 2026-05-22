#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "PinakaVault.generated.h"

UCLASS()
class RAMG_API APinakaVault : public AActor
{
	GENERATED_BODY()
	
public:	
	APinakaVault();

protected:
	virtual void BeginPlay() override;

public:	
	virtual void Tick(float DeltaTime) override;

	/** Ley-Line Marble Prism current angles (0 to 180 degrees) */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Pinaka | Puzzle")
	float AxisRotationAngle = 0.f;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Pinaka | Puzzle")
	float AxisStabilityAngle = 45.f;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Pinaka | Puzzle")
	float AxisWeightAngle = 120.f;

	/** Puzzle Target Bounds */
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Pinaka | Puzzle")
	float TargetAngle = 90.f;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Pinaka | Puzzle")
	float AngleTolerance = 5.f;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Pinaka | Puzzle")
	float MassPinaka = 1000000.f; // 1 million kg

	UPROPERTY(BlueprintReadOnly, Category = "Pinaka | Puzzle")
	bool bChestDisplaced = false;

	/** Adjust Prism Angles */
	UFUNCTION(BlueprintCallable, Category = "Pinaka | Puzzle Actions")
	void RotateRotationPrism(float DeltaAngle);

	UFUNCTION(BlueprintCallable, Category = "Pinaka | Puzzle Actions")
	void RotateStabilityPrism(float DeltaAngle);

	UFUNCTION(BlueprintCallable, Category = "Pinaka | Puzzle Actions")
	void RotateWeightPrism(float DeltaAngle);

	/** Calculate alignment ratio (0.0 to 1.0) */
	UFUNCTION(BlueprintPure, Category = "Pinaka | Puzzle Calculations")
	float GetAlignmentRatio() const;

	/** Calculate effective gravity force based on Ley-Line alignment ratio */
	UFUNCTION(BlueprintPure, Category = "Pinaka | Puzzle Calculations")
	float GetCurrentEffectiveGravityForce() const;

	/** Checks gravity force and lifts/pushes chest aside */
	UFUNCTION(BlueprintCallable, Category = "Pinaka | Puzzle Actions")
	bool TryLiftAndPushChest(AActor* Instigator);
};
