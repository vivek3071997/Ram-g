#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "VayuWindUpdraft.generated.h"

class UBoxComponent;
class UParticleSystemComponent;

UCLASS()
class RAMG_API AVayuWindUpdraft : public AActor
{
	GENERATED_BODY()
	
public:	
	AVayuWindUpdraft();

protected:
	virtual void BeginPlay() override;

public:	
	virtual void Tick(float DeltaTime) override;

	/** Trigger volume representing the column of upward thermal air */
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Vayu | Components")
	UBoxComponent* WindVolume;

	/** Dynamic particle system component to visualize wind flow */
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Vayu | Components")
	UParticleSystemComponent* WindParticles;

	/** Vertical lifting force (acceleration value applied every frame) */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Vayu | Tuning")
	float LiftStrength = 1200.f;

	/** Maximum terminal velocity when gliding up in the wind column */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Vayu | Tuning")
	float TerminalUpwardVelocity = 900.f;

	/** Active toggle for the wind puzzle */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Vayu | State")
	bool bIsWindActive = true;

	/** Hooked to redirect wind direction in puzzles */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Vayu | State")
	FVector WindDirection = FVector(0.f, 0.f, 1.f);

	/** Toggle active state dynamically from code or BP */
	UFUNCTION(BlueprintCallable, Category = "Vayu | Actions")
	void SetWindActive(bool bActive);

	UFUNCTION()
	virtual void OnOverlapBegin(UPrimitiveComponent* OverlappedComp, AActor* OtherActor, 
								UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, 
								bool bFromSweep, const FHitResult& SweepResult);
};
