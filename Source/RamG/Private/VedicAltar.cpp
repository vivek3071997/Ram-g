#include "VedicAltar.h"

// Sets default values
AVedicAltar::AVedicAltar()
{
	PrimaryActorTick.bCanEverTick = false;

	AltarIntegrity = 100.f;
	RequiredAlignmentAngle = 90.f;
	AlignmentTolerance = 5.f;
	bIsZonePurified = false;

	// Populate three mirrors with mismatched starting angles to create the puzzle setup
	MirrorRotations.Add(15.f);
	MirrorRotations.Add(45.f);
	MirrorRotations.Add(130.f);
}

// Called when the game starts or when spawned
void AVedicAltar::BeginPlay()
{
	Super::BeginPlay();
	
	UE_LOG(LogTemp, Warning, TEXT("[VEDIC ALTAR] Altar initialized with Fire Integrity 100%. Three mirrors misaligned."));
}

void AVedicAltar::RotateMirror(int32 MirrorIndex, float AngleDelta)
{
	if (!MirrorRotations.IsValidIndex(MirrorIndex))
	{
		UE_LOG(LogTemp, Error, TEXT("[MIRROR PUZZLE] Invalid Mirror index: %d"), MirrorIndex);
		return;
	}

	// Adjust rotation, clamping and wrapping in [0.0 - 360.0] space
	float NewAngle = MirrorRotations[MirrorIndex] + AngleDelta;
	NewAngle = FMath::Fmod(NewAngle, 360.f);
	if (NewAngle < 0.f) NewAngle += 360.f;

	MirrorRotations[MirrorIndex] = NewAngle;
	UE_LOG(LogTemp, Log, TEXT("[MIRROR ROTATION] Mirror %d rotated to %f degrees."), MirrorIndex, NewAngle);

	// Check if all mirrors focused
	if (CheckAlignment())
	{
		bIsZonePurified = true;
		AltarIntegrity = 100.f; // Fully cleanses altar fire
		UE_LOG(LogTemp, Warning, TEXT("[YAGNA PURIFIED] Excellent! All three Sun-Mirrors aligned at %f degrees! concentrated light focused. Altar purified."));
	}
	else
	{
		bIsZonePurified = false;
	}
}

void AVedicAltar::DefileAltar(float Amount)
{
	if (bIsZonePurified)
	{
		// Purified state halves defilement rates due to active sun shield protection
		Amount *= 0.5f;
	}

	AltarIntegrity -= Amount;
	if (AltarIntegrity < 0.f) AltarIntegrity = 0.f;

	UE_LOG(LogTemp, Warning, TEXT("[ALTAR ATTACKED] Altar Integrity damaged by %f. Current Fire Level: %f%%"), Amount, AltarIntegrity);

	if (AltarIntegrity <= 0.f)
	{
		UE_LOG(LogTemp, Error, TEXT("[YAGNA FAILED] Altar fire extinguished! Demon hordes overrun Siddhashrama ashram."));
	}
}

void AVedicAltar::CleanseAltar(float Amount)
{
	AltarIntegrity += Amount;
	if (AltarIntegrity > 100.f) AltarIntegrity = 100.f;

	UE_LOG(LogTemp, Log, TEXT("[ALTAR CLEANSED] Altar fire replenished. Current Purity: %f%%"), AltarIntegrity);
}

bool AVedicAltar::CheckAlignment() const
{
	// Sunrays are focused only when all 3 mirrors are properly rotated to the alignment target
	for (float Rot : MirrorRotations)
	{
		float Diff = FMath::Abs(Rot - RequiredAlignmentAngle);
		
		// Take circular wrapping into account
		if (Diff > 180.f)
		{
			Diff = 360.f - Diff;
		}

		if (Diff > AlignmentTolerance)
		{
			return false;
		}
	}
	return true;
}
