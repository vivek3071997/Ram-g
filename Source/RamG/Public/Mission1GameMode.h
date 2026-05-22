#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameModeBase.h"
#include "Mission1GameMode.generated.h"

class ARamaCharacter;

UENUM(BlueprintType)
enum class EMission1State : uint8
{
	AshramGuard          UMETA(DisplayName = "Ashram Guard & Defense"),
	MirrorAlignment      UMETA(DisplayName = "Vedic Sun-Mirror Alignment"),
	SubahuDuel           UMETA(DisplayName = "Subahu Sniping Duel"),
	TatakaClearing       UMETA(DisplayName = "Tataka Forest Battle"),
	MithilaTransition    UMETA(DisplayName = "Mithila Courtly Disarmament"),
	SitaReveal           UMETA(DisplayName = "Sita Royal Garden Reveal")
};

UCLASS()
class RAMG_API AMission1GameMode : public AGameModeBase
{
	GENERATED_BODY()

public:
	AMission1GameMode();

protected:
	virtual void BeginPlay() override;

public:
	/** Current active gameplay progression step */
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "RamG | State Engine")
	EMission1State CurrentMissionState;

	/** Transitions the mission to a new state and prints contextual logs */
	UFUNCTION(BlueprintCallable, Category = "RamG | State Engine")
	void SetMissionState(EMission1State NewState);

	/** Executes the court disarmament nerf on Prince Rama and prepares the Sita character swap */
	UFUNCTION(BlueprintCallable, Category = "RamG | State Engine")
	void ExecuteCourtlyDisarmament(ARamaCharacter* Rama);

	/** Runs the automated test diagnostic suite for Prince Rama's C++ components */
	UFUNCTION(BlueprintCallable, Category = "RamG | Diagnostics")
	void RunMission1Diagnostic();
};
