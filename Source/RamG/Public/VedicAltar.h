#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "VedicAltar.generated.h"

UCLASS()
class RAMG_API AVedicAltar : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AVedicAltar();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	/** Purity/Integrity level of the sacred altar fire. If defiled to 0, yajna barriers collapse. */
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "RamG | Altar Stats")
	float AltarIntegrity = 100.0f;

	/** Angles of the three Vedic Brass Sun-Mirrors in degrees */
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "RamG | Mirror Puzzle")
	TArray<float> MirrorRotations;

	/** Target angle in degrees for focusing the concentrated solar ray onto the altar */
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "RamG | Mirror Puzzle")
	float RequiredAlignmentAngle = 90.0f;

	/** Tolerance margin for alignment in degrees */
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "RamG | Mirror Puzzle")
	float AlignmentTolerance = 5.0f;

	/** Purity barrier state */
	UPROPERTY(BlueprintReadOnly, Category = "RamG | Altar Stats")
	bool bIsZonePurified = false;

	/** Rotates a specific mirror by an angle offset */
	UFUNCTION(BlueprintCallable, Category = "RamG | Mirror Puzzle")
	void RotateMirror(int32 MirrorIndex, float AngleDelta);

	/** Damages the altar integrity (e.g. Asuric defilers drop toxic waste) */
	UFUNCTION(BlueprintCallable, Category = "RamG | Altar Stats")
	void DefileAltar(float Amount);

	/** Restores integrity using fire-infused purifying spells */
	UFUNCTION(BlueprintCallable, Category = "RamG | Altar Stats")
	void CleanseAltar(float Amount);

	/** Computes if all three sun-mirrors are correctly aligned to focus sunlight */
	UFUNCTION(BlueprintPure, Category = "RamG | Mirror Puzzle")
	bool CheckAlignment() const;
};
