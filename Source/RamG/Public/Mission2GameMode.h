#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameModeBase.h"
#include "Mission2GameMode.generated.h"

class ASitaCharacter;

UENUM(BlueprintType)
enum class EMission2State : uint8
{
	ChildhoodPrologue    UMETA(DisplayName = "Palace Childhood Gardens"),
	SacredGardenDefense  UMETA(DisplayName = "Sacred Garden Orchard Defense"),
	PinakaSanctuary      UMETA(DisplayName = "Pinaka Chest Sanctuary Puzzle"),
	SwayamvaraCeremony   UMETA(DisplayName = "Adult Swayamvara Ceremony"),
	ParashuramaBoss      UMETA(DisplayName = "Sage Parashurama Courtly Duel"),
	ValkalaSwap          UMETA(DisplayName = "Kaikeyi Valkala Banishment Nerf"),
	DasharathaReveal     UMETA(DisplayName = "King Dasharatha Ayodhya Chambers")
};

UCLASS()
class RAMG_API AMission2GameMode : public AGameModeBase
{
	GENERATED_BODY()

public:
	AMission2GameMode();

protected:
	virtual void BeginPlay() override;

public:
	/** Current active gameplay progression step */
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "RamG | State Engine")
	EMission2State CurrentMissionState;

	/** Transitions the mission to a new state and prints contextual logs */
	UFUNCTION(BlueprintCallable, Category = "RamG | State Engine")
	void SetMissionState(EMission2State NewState);

	/** Executes the Valkala Swap exile nerf on Princess Sita */
	UFUNCTION(BlueprintCallable, Category = "RamG | State Engine")
	void ExecuteValkalaSwap(ASitaCharacter* Sita);

	/** Runs the automated test diagnostic suite for Princess Sita's C++ components */
	UFUNCTION(BlueprintCallable, Category = "RamG | Diagnostics")
	void RunMission2Diagnostic();
};
