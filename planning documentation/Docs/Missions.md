# Ram-G: Master Mission Index & Chain Revelation System

This document serves as the master directory and engine integration guide for the **Mission Chain Revelation System** in **Ram-G**. It maps the first half of the game's campaign (Prologue to Act 6), outlining how each mission dynamically transitions player control between characters through mechanical and narrative **"Character Nerfs."**

---

## The Chronological Mission Chain

Below is the structured division of missions, aligning the playable segments with the character transitions:

| Mission | Playable Protagonist | Objectives Achieved | Relationship Shown | Next Playable Revealed | Nerf / Transition Mechanism |
| :--- | :--- | :--- | :--- | :--- | :--- |
| **[Mission 0](Missions/Mission0_Hanuman_Prologue.md)** | **Kid Hanuman** | Reach the Sun, endure Indra's Vajra strike, gather divine boons. | Eternal Devotion | **Lord Rama** | **Curse of Forgetfulness:** Hanuman's active powers are locked until he meets Rama. |
| **[Mission 1](Missions/Mission1_Rama_Youth.md)** | **Prince Rama** | Defend Vishwamitra's sacrifices, defeat Tataka/Subahu. | Divine Marriage Alliance | **Sita** | **Courtly Disarmament:** All physical and celestial weapons are locked in Mithila's court. |
| **[Mission 2](Missions/Mission2_Sita_Mithila.md)** | **Sita** | Lift the Pinaka bow, align earth currents, marry Rama. | Unyielding Devotion | **King Dasharatha** | **Ascetic Strip (Valkala Swap):** Royal clothes and stats are stripped for a 14-year forest exile. |
| **[Mission 3](Missions/Mission3_Dasharatha_Exile.md)** | **King Dasharatha** | Defend the palace vault, negotiate dialogue boss Kaikeyi. | Tragic Father-Son Bond | **Lakshmana** | **Shravana Kumar Curse:** Triggers total health drain and narrative death from grief. |
| **[Mission 4](Missions/Mission4_Lakshmana_Forest.md)** | **Lakshmana** | Guard forest ashrams, clear 14k demon horde, punish Shurpanakha. | Sworn Forest Guard | **Maricha** | **Dark Asuric Mist:** High fog reducing visibility to 20% and inducing movement slow. |
| **[Mission 5](Missions/Mission5_Maricha_Illusion.md)** | **Maricha** | Evade wild beasts, assume Golden Deer form, distract Rama. | Fear-based Servitude | **Jatayu** | **Lethal Sniping Strike:** Rama's arrow slays Maricha, ending his physical form. |
| **[Mission 6](Missions/Mission6_Jatayu_Sky.md)** | **Jatayu** | Intercept Pushpaka Vimana, destroy Ravana's shield. | Sacrificial Promise | **Hanuman** | **Wing Clipping:** Chandrahasa cuts his wings, causing a fatal crash to the earth. |

---

## Technical Integration Models (Engine Transitions)

To implement the chain transitions in the game engine, the following standard representations are recommended:

### A. Unity Character Swap Event (C#)
```csharp
using UnityEngine;
using System;

public class MissionTransitionManager : MonoBehaviour
{
    public static MissionTransitionManager Instance { get; private set; }

    [Header("Transition Settings")]
    public GameObject currentProtagonist;
    public GameObject transitionRevealProtagonist;
    public string transitionCinematicKey;

    public static event Action<string> OnMissionChainTriggered;

    private void Awake()
    {
        if (Instance == null) Instance = this;
        else Destroy(gameObject);
    }

    public void TriggerTransitionNerf(string nerfType)
    {
        Debug.Log($"[Mission Chain] Triggering nerf: {nerfType} on {currentProtagonist.name}");
        
        // 1. Lock current controls and input
        currentProtagonist.GetComponent<PlayerController>().DisableInput();
        
        // 2. Play transition visual effects (e.g. screen fade, lightning, portal)
        VfxManager.Instance.PlayTransitionVfx(nerfType, currentProtagonist.transform.position);
        
        // 3. Play narrative cinematic
        CinematicManager.Instance.PlaySequence(transitionCinematicKey, () => {
            // 4. Disable old character, spawn/enable new character
            currentProtagonist.SetActive(false);
            transitionRevealProtagonist.SetActive(true);
            transitionRevealProtagonist.GetComponent<PlayerController>().EnableInput();
            
            OnMissionChainTriggered?.Invoke(transitionRevealProtagonist.name);
        });
    }
}
```

### B. Unreal Engine 5 Character Control Switch (C++)
```cpp
#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameModeBase.h"
#include "GameFramework/PlayerController.h"
#include "RamGMissionGameMode.generated.h"

UCLASS()
class RAMG_API ARamGMissionGameMode : public AGameModeBase
{
    GENERATED_BODY()

public:
    UFUNCTION(BlueprintCallable, Category = "Mission Swap")
    void ExecuteCharacterTransition(APawn* OldProtagonist, APawn* NewProtagonist, FString NerfEffectTag)
    {
        APlayerController* PC = GetWorld()->GetFirstPlayerController();
        if (PC && OldProtagonist && NewProtagonist)
        {
            // Disable inputs for old pawn
            OldProtagonist->DisableInput(PC);
            
            // Spawn transition particles at Old Protagonist
            TriggerNerfVfx(OldProtagonist->GetActorLocation(), NerfEffectTag);
            
            // Switch controller possession
            PC->UnPossess();
            PC->Possess(NewProtagonist);
            
            // Enable inputs for new pawn
            NewProtagonist->EnableInput(PC);
        }
    }

protected:
    UFUNCTION(BlueprintImplementableEvent, Category = "Mission Swap")
    void TriggerNerfVfx(FVector Location, const FString& EffectTag);
};
```
