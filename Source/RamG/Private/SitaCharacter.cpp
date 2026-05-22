#include "SitaCharacter.h"
#include "RamaCharacter.h"
#include "BhumisuraEnemy.h"
#include "GameFramework/CharacterMovementComponent.h"
#include "Kismet/GameplayStatics.h"
#include "Engine/World.h"
#include "DrawDebugHelpers.h"
#include "Engine/OverlapResult.h"

ASitaCharacter::ASitaCharacter()
{
	PrimaryActorTick.bCanEverTick = true;

	// Initialize childhood state by default
	bIsChildhoodState = true;
	bIsValkalaEquipped = false;

	// Initial physiological pools
	CurrentStamina = 100.f;
	CurrentFocus = 100.f;
	CurrentLacticAcid = 0.f;

	EarthAuraRadius = 800.f;
	BhumiSpandanCooldown = 3.f;
	BhumiSpandanStaminaCost = 20.f;
	bBhumiSpandanActive = false;
	BhumiSpandanTimer = 0.f;

	GangaJalFlaskCount = 10;
	PurifyingFlaskRange = 1200.f;

	EarthShieldCooldown = 5.f;
	EarthShieldTimer = 0.f;
	EarthResonanceStaminaCost = 15.f;
}

void ASitaCharacter::BeginPlay()
{
	Super::BeginPlay();

	UE_LOG(LogTemp, Warning, TEXT("[SITA MITHILA] Princess Sita steps into Janaka's palace garden. Earth aura tuned."));
}

void ASitaCharacter::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	// Update ability cooldown timers
	if (BhumiSpandanTimer > 0.f)
	{
		BhumiSpandanTimer -= DeltaTime;
		if (BhumiSpandanTimer <= 0.f)
		{
			BhumiSpandanTimer = 0.f;
			bBhumiSpandanActive = false;
		}
	}

	if (EarthShieldTimer > 0.f)
	{
		EarthShieldTimer -= DeltaTime;
		if (EarthShieldTimer < 0.f) EarthShieldTimer = 0.f;
	}
}

void ASitaCharacter::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);
}

void ASitaCharacter::TriggerBhumiSpandan()
{
	if (BhumiSpandanTimer > 0.f)
	{
		UE_LOG(LogTemp, Warning, TEXT("[SITA ABILITY] Bhumi Spandan pulse is on cooldown. Wait %f seconds."), BhumiSpandanTimer);
		return;
	}

	if (CurrentStamina < BhumiSpandanStaminaCost)
	{
		UE_LOG(LogTemp, Warning, TEXT("[SITA ABILITY] Too fatigued to perform Earth Aura Pulse (Bhumi Spandan). Stamina low."));
		return;
	}

	// Consume Stamina
	CurrentStamina -= BhumiSpandanStaminaCost;
	BhumiSpandanTimer = BhumiSpandanCooldown;
	bBhumiSpandanActive = true;

	UE_LOG(LogTemp, Warning, TEXT("[SITA ABILITY] Princess Sita triggers Earth Aura Pulse (Bhumi Spandan)! Ground ripples in radius %f."), EarthAuraRadius);

	// Sphere trace to overlap subterranean Bhumisuras
	FVector StartLoc = GetActorLocation();
	TArray<FOverlapResult> OverlapResults;
	FCollisionQueryParams QueryParams;
	QueryParams.AddIgnoredActor(this);

	FCollisionShape SphereShape = FCollisionShape::MakeSphere(EarthAuraRadius);
	bool bSweepHit = GetWorld()->OverlapMultiByObjectType(
		OverlapResults,
		StartLoc,
		FQuat::Identity,
		FCollisionObjectQueryParams(FCollisionObjectQueryParams::AllDynamicObjects),
		SphereShape,
		QueryParams
	);

#if WITH_EDITOR
	// Draw a debug ring indicating Earth Aura Pulse bounds
	DrawDebugSphere(GetWorld(), StartLoc, EarthAuraRadius, 32, FColor::Green, false, 1.5f, 0, 2.f);
#endif

	if (bSweepHit)
	{
		for (const FOverlapResult& Overlap : OverlapResults)
		{
			ABhumisuraEnemy* Gopher = Cast<ABhumisuraEnemy>(Overlap.GetActor());
			if (Gopher)
			{
				UE_LOG(LogTemp, Log, TEXT("[SITA ABILITY] Overlapped subterranean Bhumisura: %s"), *Gopher->GetName());
				Gopher->RevealAndEmerge();
			}
		}
	}
}

void ASitaCharacter::ThrowGangaJalFlask()
{
	if (GangaJalFlaskCount <= 0)
	{
		UE_LOG(LogTemp, Warning, TEXT("[PURIFICATION] Out of Ganga-Jal flask charges!"));
		return;
	}

	GangaJalFlaskCount--;
	UE_LOG(LogTemp, Log, TEXT("[PURIFICATION] Princess Sita throws a Purifying Ganga-Jal Flask. Remaining: %d"), GangaJalFlaskCount);

	// Raycast/Sphere Trace forward to see if we hit an emerged Bhumisura
	FVector StartLoc = GetActorLocation();
	FVector ForwardVec = GetActorForwardVector();
	FVector EndLoc = StartLoc + (ForwardVec * PurifyingFlaskRange);

	FHitResult HitResult;
	FCollisionQueryParams QueryParams;
	QueryParams.AddIgnoredActor(this);

	bool bHit = GetWorld()->SweepSingleByObjectType(
		HitResult,
		StartLoc,
		EndLoc,
		FQuat::Identity,
		FCollisionObjectQueryParams(FCollisionObjectQueryParams::AllDynamicObjects),
		FCollisionShape::MakeSphere(100.f), // Flask splash radius
		QueryParams
	);

#if WITH_EDITOR
	DrawDebugLine(GetWorld(), StartLoc, EndLoc, FColor::Blue, false, 1.0f, 0, 2.f);
#endif

	if (bHit)
	{
		ABhumisuraEnemy* Gopher = Cast<ABhumisuraEnemy>(HitResult.GetActor());
		if (Gopher)
		{
			UE_LOG(LogTemp, Warning, TEXT("[PURIFICATION] Ganga-Jal Flask splashed directly onto gopher: %s"), *Gopher->GetName());
			Gopher->Purify(this);
		}
	}
}

void ASitaCharacter::SpawnEarthShield()
{
	if (bIsChildhoodState)
	{
		UE_LOG(LogTemp, Warning, TEXT("[LOCK] Childhood Sita cannot cast high-tier combat earth shields!"));
		return;
	}

	if (EarthShieldTimer > 0.f)
	{
		UE_LOG(LogTemp, Warning, TEXT("[SITA COMBAT] Earth Shield is on cooldown. Wait %f seconds."), EarthShieldTimer);
		return;
	}

	EarthShieldTimer = EarthShieldCooldown;
	UE_LOG(LogTemp, Warning, TEXT("[SITA COMBAT] Sita raises a protective Mud-Dome! Blocks Sage Parashurama's supersonic shockwaves."));

#if WITH_EDITOR
	DrawDebugCone(GetWorld(), GetActorLocation() + GetActorForwardVector() * 200.f, GetActorForwardVector(), 300.f, 45.f, 45.f, 16, FColor::Yellow, false, 3.f, 0, 3.f);
#endif
}

void ASitaCharacter::ApplyEarthResonanceBuff(ARamaCharacter* TargetRama)
{
	if (bIsChildhoodState)
	{
		UE_LOG(LogTemp, Warning, TEXT("[LOCK] Childhood Sita cannot channel stability buffs!"));
		return;
	}

	if (CurrentStamina < EarthResonanceStaminaCost)
	{
		UE_LOG(LogTemp, Warning, TEXT("[SITA COMBAT] Stamina too low to channel stability resonance."));
		return;
	}

	CurrentStamina -= EarthResonanceStaminaCost;

	if (TargetRama)
	{
		UE_LOG(LogTemp, Warning, TEXT("[SITA COMBAT] Sita channels Earth Resonance onto Prince Rama (%s)! Leg muscles locked against Sage Parashurama's crushing gravitational pull."), *TargetRama->GetName());
	}
}

void ASitaCharacter::ExecuteValkalaSwap()
{
	bIsValkalaEquipped = true;

	// Banishment limits: Max HP reduced by 50%
	CurrentStamina = 50.f; // Reduced operational stamina pool
	GangaJalFlaskCount = 0; // Strip gold flasks and holy water charms

	// Cap walk speed to regular forest pace
	GetCharacterMovement()->MaxWalkSpeed = 350.f;

	UE_LOG(LogTemp, Error, TEXT("[VALKALA SWAP] exile decree strikes! Sita divests royal jewels and silk robes. Wearing Coarse Bark (Valkala) robes. Health/Stamina capped at 50%%. Defense set to 0."));
}
