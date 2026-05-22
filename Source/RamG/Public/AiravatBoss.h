#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "AiravatBoss.generated.h"

class USceneComponent;

UENUM(BlueprintType)
enum class EAiravatPhase : uint8
{
	Phase1_TuskClimb     UMETA(DisplayName = "Phase 1: Tusk Climb"),
	Phase2_TrunkLash     UMETA(DisplayName = "Phase 2: Trunk Lash"),
	Sleeping             UMETA(DisplayName = "Sleeping")
};

UCLASS()
class RAMG_API AAiravatBoss : public ACharacter
{
	GENERATED_BODY()

public:
	AAiravatBoss();

protected:
	virtual void BeginPlay() override;

public:	
	virtual void Tick(float DeltaTime) override;

	/** Phase tracking for the elephant boss */
	UPROPERTY(BlueprintReadOnly, Category = "Airavat | State")
	EAiravatPhase CurrentPhase = EAiravatPhase::Phase1_TuskClimb;

	/** Grapple point scene component on left tusk */
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Airavat | Grapple")
	USceneComponent* LeftTuskGrapplePoint;

	/** Grapple point scene component on right tusk */
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Airavat | Grapple")
	USceneComponent* RightTuskGrapplePoint;

	/** Charge Speed in Phase 1 */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Airavat | Attack")
	float ChargeSpeed = 1100.f;

	/** Rate at which ground shockwaves are generated when charging */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Airavat | Attack")
	float ShockwaveInterval = 1.8f;

	float ShockwaveTimer = 0.f;

	/** Trigger ear tickling to bypass/defeat */
	UFUNCTION(BlueprintCallable, Category = "Airavat | Combat")
	void TickleEar(AActor* Attacker);

	/** Trigger Airavat charge sequence */
	UFUNCTION(BlueprintCallable, Category = "Airavat | Combat")
	void PerformChargeAttack();

	/** Trigger Phase transition */
	void TransitionToPhase2();

	/** Class of item representing the golden mango key */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Airavat | Loot")
	TSubclassOf<AActor> GoldenMangoKeyClass;

private:
	bool bIsCharging = false;
	FVector ChargeStartLoc;
	FVector ChargeEndLoc;
	float ChargeLerpTime = 0.f;
};
