#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "BhumisuraEnemy.generated.h"

UCLASS()
class RAMG_API ABhumisuraEnemy : public ACharacter
{
	GENERATED_BODY()

public:
	ABhumisuraEnemy();

protected:
	virtual void BeginPlay() override;

public:
	virtual void Tick(float DeltaTime) override;

	/** Burrowing states */
	UPROPERTY(BlueprintReadOnly, Category = "Bhumisura | State")
	bool bIsBurrowed = true;

	UPROPERTY(BlueprintReadOnly, Category = "Bhumisura | State")
	bool bIsPurified = false;

	UPROPERTY(BlueprintReadOnly, Category = "Bhumisura | State")
	bool bIsStaggered = false;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Bhumisura | Tuning")
	float StaggerDuration = 3.f;

	float StaggerTimer = 0.f;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Bhumisura | Tuning")
	float BurrowSpeed = 350.f;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Bhumisura | Tuning")
	float EmergeSpeed = 150.f;

	/** Combat properties */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Bhumisura | Combat")
	float MudSpitDamage = 10.f;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Bhumisura | Combat")
	float MudSpitInterval = 4.f;

	float MudSpitTimer = 0.f;

	/** Actions */
	UFUNCTION(BlueprintCallable, Category = "Bhumisura | Actions")
	void RevealAndEmerge();

	UFUNCTION(BlueprintCallable, Category = "Bhumisura | Actions")
	void Purify(AActor* Purifier);

	UFUNCTION(BlueprintCallable, Category = "Bhumisura | Actions")
	void SpitPoisonMud(AActor* TargetPlayer);

	/** Movement & AI Simulation */
	void UpdateBurrowBehavior(float DeltaTime);
};
