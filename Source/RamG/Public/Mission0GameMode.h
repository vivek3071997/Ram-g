#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameModeBase.h"
#include "Mission0GameMode.generated.h"

UENUM(BlueprintType)
enum class EMission0State : uint8
{
	Tutorial             UMETA(DisplayName = "Tutorial - Orchard Leaps"),
	OrchardChase         UMETA(DisplayName = "Orchard Chase - Imp Tickling"),
	ThermalAscent        UMETA(DisplayName = "Vertical Puzzle - Thermal Wind Updrafts"),
	SunPursuit           UMETA(DisplayName = "Sun Pursuit - Cloud Platform Runner"),
	AiravatBattle        UMETA(DisplayName = "Boss 1 - Airavat Elephant"),
	IndraBattle          UMETA(DisplayName = "Boss 2 - Lord Indra Sky Battle"),
	VajraNerf            UMETA(DisplayName = "The Nerf - Vajra Strike & Forgetfulness Curse"),
	RamaReveal           UMETA(DisplayName = "Ayodhya Reveal - Prince Rama Born")
};

UCLASS()
class RAMG_API AMission0GameMode : public AGameModeBase
{
	GENERATED_BODY()

public:
	AMission0GameMode();

protected:
	virtual void BeginPlay() override;

public:
	virtual void Tick(float DeltaTime) override;

	/** Active progression state for Mission 0 */
	UPROPERTY(BlueprintReadOnly, Category = "Mission 0 | State")
	EMission0State CurrentMissionState = EMission0State::Tutorial;

	/** Number of sacred fruits needed to complete chase */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Mission 0 | Setup")
	int32 RequiredFruitsForChase = 5;

	/** Trigger transition to a new mission state */
	UFUNCTION(BlueprintCallable, Category = "Mission 0 | Progress")
	void SetMissionState(EMission0State NewState);

	/** Callback when Hanuman picks up key from Airavat */
	UFUNCTION(BlueprintCallable, Category = "Mission 0 | Callbacks")
	void OnGoldenMangoKeyCollected();

	/** Trigger Lord Indra's ultimate strike & transition */
	UFUNCTION(BlueprintCallable, Category = "Mission 0 | Callbacks")
	void TriggerVajraNerfSequence();

	/** Triggers Ayodhya pan reveal */
	UFUNCTION(BlueprintCallable, Category = "Mission 0 | Callbacks")
	void TriggerRamaReveal();

	/** Run a full diagnostic check on all Mission 0 gameplay steps and print outputs to log */
	UFUNCTION(BlueprintCallable, Category = "Mission 0 | Debug")
	void RunMissionDiagnostic();

private:
	float StateTimer = 0.f;
};
