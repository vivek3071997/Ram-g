#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "CloudPlatform.generated.h"

class UBoxComponent;
class UStaticMeshComponent;

UCLASS()
class RAMG_API ACloudPlatform : public AActor
{
	GENERATED_BODY()
	
public:	
	ACloudPlatform();

protected:
	virtual void BeginPlay() override;

public:	
	virtual void Tick(float DeltaTime) override;

	/** Visual cloud mesh */
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Cloud | Components")
	UStaticMeshComponent* MeshComponent;

	/** Overlap trigger bounding top of cloud to detect stepping player */
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Cloud | Components")
	UBoxComponent* StepTrigger;

	/** Seconds character can stand on cloud before dissipation */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Cloud | Tuning")
	float DissipationDelay = 3.0f;

	/** Seconds before cloud respawns and becomes solid again */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Cloud | Tuning")
	float RespawnDelay = 5.0f;

	UPROPERTY(BlueprintReadOnly, Category = "Cloud | State")
	bool bIsDissipated = false;

	UFUNCTION()
	virtual void OnOverlapBegin(UPrimitiveComponent* OverlappedComp, AActor* OtherActor, 
								UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, 
								bool bFromSweep, const FHitResult& SweepResult);

	/** Trigger cloud dissipation */
	UFUNCTION(BlueprintCallable, Category = "Cloud | Actions")
	void Dissipate();

	/** Rebuild solid state */
	UFUNCTION(BlueprintCallable, Category = "Cloud | Actions")
	void Restore();

private:
	FTimerHandle DissolveTimerHandle;
	FTimerHandle RespawnTimerHandle;
};
