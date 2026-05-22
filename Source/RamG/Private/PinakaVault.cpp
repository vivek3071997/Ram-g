#include "PinakaVault.h"
#include "Kismet/GameplayStatics.h"
#include "Engine/World.h"
#include "DrawDebugHelpers.h"

APinakaVault::APinakaVault()
{
	PrimaryActorTick.bCanEverTick = true;

	AxisRotationAngle = 0.f;
	AxisStabilityAngle = 45.f;
	AxisWeightAngle = 120.f;
	TargetAngle = 90.f;
	AngleTolerance = 5.f;
	MassPinaka = 1000000.f; // 1 million kg
	bChestDisplaced = false;
}

void APinakaVault::BeginPlay()
{
	Super::BeginPlay();
	
	UE_LOG(LogTemp, Warning, TEXT("[PINAKA VAULT] Sacred Shiva's Bow chest placed in sanctuary under gravity seals."));
}

void APinakaVault::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

#if WITH_EDITOR
	// Draw a visual display representing current chest status
	FVector DrawLoc = GetActorLocation() + FVector(0.f, 0.f, 150.f);
	float GravityForceKN = GetCurrentEffectiveGravityForce() / 1000.f;
	FString DebugText = FString::Printf(TEXT("Pinaka Gravity: %.2f kN (Aligned: %.1f%%)"), GravityForceKN, GetAlignmentRatio() * 100.f);
	DrawDebugString(GetWorld(), DrawLoc, DebugText, nullptr, FColor::Orange, 0.1f, false, 1.2f);
#endif
}

void APinakaVault::RotateRotationPrism(float DeltaAngle)
{
	AxisRotationAngle = FMath::Clamp(AxisRotationAngle + DeltaAngle, 0.f, 180.f);
	UE_LOG(LogTemp, Log, TEXT("[PINAKA PUZZLE] Rotation Prism adjusted to %f degrees. Alignment: %f%%"), AxisRotationAngle, GetAlignmentRatio() * 100.f);
}

void APinakaVault::RotateStabilityPrism(float DeltaAngle)
{
	AxisStabilityAngle = FMath::Clamp(AxisStabilityAngle + DeltaAngle, 0.f, 180.f);
	UE_LOG(LogTemp, Log, TEXT("[PINAKA PUZZLE] Stability Prism adjusted to %f degrees. Alignment: %f%%"), AxisStabilityAngle, GetAlignmentRatio() * 100.f);
}

void APinakaVault::RotateWeightPrism(float DeltaAngle)
{
	AxisWeightAngle = FMath::Clamp(AxisWeightAngle + DeltaAngle, 0.f, 180.f);
	UE_LOG(LogTemp, Log, TEXT("[PINAKA PUZZLE] Weight Prism adjusted to %f degrees. Alignment: %f%%"), AxisWeightAngle, GetAlignmentRatio() * 100.f);
}

float APinakaVault::GetAlignmentRatio() const
{
	// Calculate deviation from TargetAngle (90 degrees) for all 3 element axes
	float DiffRot = FMath::Abs(AxisRotationAngle - TargetAngle);
	float DiffStab = FMath::Abs(AxisStabilityAngle - TargetAngle);
	float DiffWgt = FMath::Abs(AxisWeightAngle - TargetAngle);

	// Tolerances grant absolute 1.0 score if close enough
	float ScoreRot = (DiffRot <= AngleTolerance) ? 1.0f : FMath::Max(0.f, 1.f - (DiffRot / 90.f));
	float ScoreStab = (DiffStab <= AngleTolerance) ? 1.0f : FMath::Max(0.f, 1.f - (DiffStab / 90.f));
	float ScoreWgt = (DiffWgt <= AngleTolerance) ? 1.0f : FMath::Max(0.f, 1.f - (DiffWgt / 90.f));

	return (ScoreRot + ScoreStab + ScoreWgt) / 3.0f;
}

float APinakaVault::GetCurrentEffectiveGravityForce() const
{
	// G = M * g * (1 - ratio)
	float NetGravity = MassPinaka * 9.81f * (1.0f - GetAlignmentRatio());
	if (NetGravity < 0.f) NetGravity = 0.f;
	return NetGravity;
}

bool APinakaVault::TryLiftAndPushChest(AActor* PushingActor)
{
	float Alignment = GetAlignmentRatio();
	
	// Threshold alignment ratio to neutralize gravity weight: 95%
	if (Alignment >= 0.95f)
	{
		bChestDisplaced = true;
		UE_LOG(LogTemp, Error, TEXT("[PINAKA VAULT SUCCESS] Gravity neutralized! %s effortlessly slides the million-ton Pinaka chest aside with one hand! Retrieving lost ball..."), PushingActor ? *PushingActor->GetName() : TEXT("Unknown"));
		return true;
	}
	else
	{
		float GravityForceTons = GetCurrentEffectiveGravityForce() / 9810.f; // Convert force to tons
		UE_LOG(LogTemp, Warning, TEXT("[PINAKA VAULT FAILED] Gravity seals are active! Chest weighs %.2f tons. %s cannot move the chest."), GravityForceTons, PushingActor ? *PushingActor->GetName() : TEXT("Unknown"));
		return false;
	}
}
