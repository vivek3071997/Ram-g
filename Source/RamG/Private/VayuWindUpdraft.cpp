#include "VayuWindUpdraft.h"
#include "Components/BoxComponent.h"
#include "GameFramework/Character.h"
#include "GameFramework/CharacterMovementComponent.h"
#include "Particles/ParticleSystemComponent.h"

AVayuWindUpdraft::AVayuWindUpdraft()
{
	PrimaryActorTick.bCanEverTick = true;

	// Create Box trigger
	WindVolume = CreateDefaultSubobject<UBoxComponent>(TEXT("WindVolume"));
	WindVolume->InitBoxExtent(FVector(100.f, 100.f, 400.f));
	WindVolume->SetCollisionProfileName(TEXT("OverlapAllDynamic"));
	RootComponent = WindVolume;

	// Visual particles
	WindParticles = CreateDefaultSubobject<UParticleSystemComponent>(TEXT("WindParticles"));
	WindParticles->SetupAttachment(RootComponent);
}

void AVayuWindUpdraft::BeginPlay()
{
	Super::BeginPlay();
	
	WindVolume->OnComponentBeginOverlap.AddDynamic(this, &AVayuWindUpdraft::OnOverlapBegin);
}

void AVayuWindUpdraft::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	if (!bIsWindActive)
	{
		return;
	}

	TArray<AActor*> OverlappingActors;
	WindVolume->GetOverlappingActors(OverlappingActors, ACharacter::StaticClass());

	for (AActor* Actor : OverlappingActors)
	{
		ACharacter* OverlappingChar = Cast<ACharacter>(Actor);
		if (OverlappingChar)
		{
			UCharacterMovementComponent* MoveComp = OverlappingChar->GetCharacterMovement();
			if (MoveComp)
			{
				// Smooth upward force: if current Z velocity is less than maximum, apply lift
				float CurrentZVel = MoveComp->Velocity.Z;
				if (CurrentZVel < TerminalUpwardVelocity)
				{
					// Apply velocity launch along WindDirection
					FVector LiftForce = WindDirection * LiftStrength * DeltaTime * 60.f; // Frame-rate independent scaling
					
					// Hanuman glides with low gravity when inside Vayu currents
					OverlappingChar->LaunchCharacter(LiftForce, false, false);
					
					// Maintain slow terminal glide speed
					if (MoveComp->Velocity.Z > TerminalUpwardVelocity)
					{
						MoveComp->Velocity.Z = TerminalUpwardVelocity;
					}
				}
			}
		}
	}
}

void AVayuWindUpdraft::SetWindActive(bool bActive)
{
	bIsWindActive = bActive;
	if (WindParticles)
	{
		WindParticles->SetVisibility(bActive);
	}
}

void AVayuWindUpdraft::OnOverlapBegin(UPrimitiveComponent* OverlappedComp, AActor* OtherActor, 
									  UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, 
									  bool bFromSweep, const FHitResult& SweepResult)
{
	if (bIsWindActive && OtherActor && OtherActor->IsA(ACharacter::StaticClass()))
	{
		ACharacter* PlayerChar = Cast<ACharacter>(OtherActor);
		if (PlayerChar)
		{
			// Give a quick initial boost when entering the wind stream
			PlayerChar->LaunchCharacter(WindDirection * 300.f, false, true);
		}
	}
}
