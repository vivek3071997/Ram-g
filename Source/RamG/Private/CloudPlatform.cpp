#include "CloudPlatform.h"
#include "Components/BoxComponent.h"
#include "Components/StaticMeshComponent.h"
#include "GameFramework/Character.h"
#include "Kismet/GameplayStatics.h"

ACloudPlatform::ACloudPlatform()
{
	PrimaryActorTick.bCanEverTick = true;

	// Visual cloud mesh with collision
	MeshComponent = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("CloudMesh"));
	MeshComponent->SetCollisionProfileName(TEXT("BlockAll"));
	RootComponent = MeshComponent;

	// Overlap sensor on top
	StepTrigger = CreateDefaultSubobject<UBoxComponent>(TEXT("StepTrigger"));
	StepTrigger->SetupAttachment(RootComponent);
	StepTrigger->InitBoxExtent(FVector(90.f, 90.f, 15.f));
	StepTrigger->SetRelativeLocation(FVector(0.f, 0.f, 35.f)); // Align slightly above mesh
	StepTrigger->SetCollisionProfileName(TEXT("OverlapAllDynamic"));
}

void ACloudPlatform::BeginPlay()
{
	Super::BeginPlay();
	
	StepTrigger->OnComponentBeginOverlap.AddDynamic(this, &ACloudPlatform::OnOverlapBegin);
}

void ACloudPlatform::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

void ACloudPlatform::OnOverlapBegin(UPrimitiveComponent* OverlappedComp, AActor* OtherActor, 
									  UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, 
									  bool bFromSweep, const FHitResult& SweepResult)
{
	if (!bIsDissipated && OtherActor && OtherActor != this && OtherActor->IsA(ACharacter::StaticClass()))
	{
		// Start dissipation timer if it isn't already running
		if (!GetWorldTimerManager().IsTimerActive(DissolveTimerHandle))
		{
			GetWorldTimerManager().SetTimer(DissolveTimerHandle, this, &ACloudPlatform::Dissipate, DissipationDelay, false);
			
			// Play initial creaking/cloud cracking vapor audio indicator if defined
			// UGameplayStatics::PlaySoundAtLocation(GetWorld(), ...);
		}
	}
}

void ACloudPlatform::Dissipate()
{
	bIsDissipated = true;

	// Turn off collision
	MeshComponent->SetCollisionEnabled(ECollisionEnabled::NoCollision);
	StepTrigger->SetCollisionEnabled(ECollisionEnabled::NoCollision);

	// Hide visual mesh
	MeshComponent->SetVisibility(false);

	// Spawn cloud puff vapor VFX
	// UGameplayStatics::SpawnEmitterAtLocation(GetWorld(), ...);

	// Clear dissolve timer
	GetWorldTimerManager().ClearTimer(DissolveTimerHandle);

	// Set respawn timer
	GetWorldTimerManager().SetTimer(RespawnTimerHandle, this, &ACloudPlatform::Restore, RespawnDelay, false);
}

void ACloudPlatform::Restore()
{
	bIsDissipated = false;

	// Restore solid physics
	MeshComponent->SetCollisionEnabled(ECollisionEnabled::QueryAndPhysics);
	StepTrigger->SetCollisionEnabled(ECollisionEnabled::QueryOnly);

	// Make visible
	MeshComponent->SetVisibility(true);

	// Spawn smooth condensate condensation PBR particles
	// UGameplayStatics::SpawnEmitterAtLocation(GetWorld(), ...);

	// Clear respawn timer
	GetWorldTimerManager().ClearTimer(RespawnTimerHandle);
}
