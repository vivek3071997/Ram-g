#include "SacredFruit.h"
#include "Components/SphereComponent.h"
#include "Components/StaticMeshComponent.h"
#include "Kismet/GameplayStatics.h"

ASacredFruit::ASacredFruit()
{
	PrimaryActorTick.bCanEverTick = true;

	// Create collision sphere
	CollisionComponent = CreateDefaultSubobject<USphereComponent>(TEXT("SphereCollision"));
	CollisionComponent->InitSphereRadius(45.f);
	CollisionComponent->SetCollisionProfileName(TEXT("OverlapAllDynamic"));
	RootComponent = CollisionComponent;

	// Create visual mesh
	MeshComponent = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("StaticMesh"));
	MeshComponent->SetupAttachment(RootComponent);
	MeshComponent->SetCollisionEnabled(ECollisionEnabled::NoCollision);

	// Physics simulated floating bounds
	InitialLocation = FVector::ZeroVector;
}

void ASacredFruit::BeginPlay()
{
	Super::BeginPlay();
	
	InitialLocation = GetActorLocation();

	// Bind overlap event
	CollisionComponent->OnComponentBeginOverlap.AddDynamic(this, &ASacredFruit::OnOverlapBegin);
}

void ASacredFruit::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	// Bobbing up and down
	RunningTime += DeltaTime;
	FVector NewLocation = InitialLocation;
	NewLocation.Z += FMath::Sin(RunningTime * BobbingFrequency) * BobbingAmplitude;
	SetActorLocation(NewLocation);

	// Floating rotation
	FRotator NewRotation = GetActorRotation();
	NewRotation.Yaw += RotationSpeed * DeltaTime;
	SetActorRotation(NewRotation);
}

void ASacredFruit::OnOverlapBegin(UPrimitiveComponent* OverlappedComp, AActor* OtherActor, 
								  UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, 
								  bool bFromSweep, const FHitResult& SweepResult)
{
	if (OtherActor && OtherActor != this)
	{
		// We'll dynamic cast to Hanuman Character or use a general Interface/Base Character method
		// Let's assume we can try to call a functional method directly
		// E.g., if there's a dynamic function, or check class name
		if (OtherActor->IsA(ACharacter::StaticClass()))
		{
			// Try to find if player possesses a fruit basket function
			// We'll implement a function on AHanumanCharacter or in ARamGCharacter to collect fruit
			UFunction* CollectFruitFunc = OtherActor->FindFunction(FName("CollectSacredFruit"));
			if (CollectFruitFunc)
			{
				OtherActor->ProcessEvent(CollectFruitFunc, nullptr);
			}

			// Spawn a golden flash PBR indicator
			// UGameplayStatics::SpawnEmitterAtLocation(GetWorld(), ...);
			
			// Play picking sound snap
			// UGameplayStatics::PlaySoundAtLocation(GetWorld(), ...);
			
			Destroy();
		}
	}
}
