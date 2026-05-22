# Ram-G: Grounded Base Character System

This document outlines the standard schema, technical parameters, and conceptual guidelines for defining all characters in the **Modern GDD representation** of **Ram-G**. 

To maintain realistic gameplay immersion, this template standardizes a **grounded, scientific approach** to human and divine capabilities. By anchoring all parameters in real-world human physiology, neuroscience, and classical physics, we establish clear, logical boundaries for player movements, actions, and combat systems.

---

## 1. Character Attribute Schema

Every character in the modern database is defined using these structured parameters:

| Parameter | Type | Description | Scientific / Biomechanical Rationale |
| :--- | :--- | :--- | :--- |
| **Name** | String | Standard English transliteration and Sanskrit name. | Standard database identifier. |
| **GDD Tier** | Enum | **Divine**, **Divine Human (Avatar)**, **Strong Mortal**, **Weak Mortal**. | Determines physiological and neurological limits. |
| **Role** | String | Playable protagonist, combat companion, support, or Boss. | Narrative and combat designation. |
| **Age** | Integer / Range | Biological age during active gameplay phases. | Determines metabolic peaks and physical maturity. |
| **Height** | Float | Physical height in meters. | Impacts center of mass, reach, and hitbox scale. |
| **Weight** | Float | Total biological mass in kilograms. | Dictates inertia, friction coefficients, and kinetic impact. |
| **Neurological Latency** | Float (ms) | Action-potential transmission speed (brain-to-muscle). | Real human range: `150ms - 250ms`. Avatar/Divine range: `80ms - 110ms`. |
| **Max Cardiac Output** | Float (L/min)| Maximum blood volume pumped by heart per minute. | Dictates aerobic stamina recovery and prolonged exertion limits. |
| **Lactic Acid Threshold**| Float (mmol/L)| Blood lactate level before muscle fatigue drops agility. | High levels cause muscle stiffness, slower draws, and higher swing lag. |
| **ATP Recovery Rate** | Float (J/s) | Adenosine Triphosphate regeneration rate. | Dictates quick-dash recovery and heavy-attack reload intervals. |
| **Spiritual Focus / Willpower** | Float (Joules) | Cognitive capacity to suppress stress and activate focus. | High focus enables bullet-time precision (*Shabda-Bhedi*). |
| **A/V Profile** | Struct | Physical voice acoustics (Hz) and acoustic Raga theme. | Rooted in classical acoustic resonance and frequency bands. |

---

## 2. Programmatic Integration Models

To translate this grounded template directly into game engine code, the following standard representations are recommended:

### A. Unity Game Engine (C# ScriptableObject)
```csharp
using UnityEngine;
using System.Collections.Generic;

public enum GddCharacterTier
{
    Divine,             // Celestial entity complying with thermodynamic laws but utilizing high energy fields
    DivineHumanAvatar,  // Flawless neurological speed and optimal ATP output within human physical limits
    StrongMortal,       // Peak athletic human bound strictly by realistic stamina and injury thresholds
    WeakMortal          // Standard biological human bounds
}

[CreateAssetMenu(fileName = "NewCharacterGrounded", menuName = "Ram-G/GroundedCharacterData")]
public class GroundedCharacterData : ScriptableObject
{
    [Header("Basic Identification")]
    public string characterName;
    public string sanskritName;
    public GddCharacterTier characterTier;
    public string gameplayArchetype;
    
    [Header("Physiological Specifications")]
    public float heightInMeters;
    public float weightInKg;
    [Tooltip("Neurological latency in milliseconds. Lower value = faster reaction times.")]
    public float neurologicalLatencyMs = 200.0f;
    [Tooltip("Max cardiac output in Liters per minute. Impacts long-term stamina regeneration.")]
    public float maxCardiacOutputLMin = 25.0f;
    [Tooltip("Lactic acid threshold in mmol/L. Lower value = tires faster under rapid physical exertion.")]
    public float lacticAcidThresholdMmol = 4.0f;
    [Tooltip("ATP recovery rate in Joules/second. Dictates rapid dash/dodge replenishment.")]
    public float atpRecoveryRateJs = 10.0f;

    [Header("Narrative & Focus")]
    public string coreObjective;
    public string ethicalNature;
    [Tooltip("Focus capacity in Joules. Controls sensory visual/auditory tracking duration.")]
    public float maxFocusCapacityJoules = 100.0f;

    [Header("Weapon & Gear Mapping")]
    public string primaryWeaponFileLink;
    public string secondaryWeaponFileLink;
    public string activeClothingFileLink;

    [Header("Acoustic Profile")]
    public float primaryVocalFrequencyHz = 110.0f; // Bass/baritone ranges
    public float secondaryVocalFrequencyHz = 220.0f;
    public string acousticRagaScale; // Sanskrit classical raga mapped scale
    public AudioClip exploratoryTheme;
    public AudioClip combatTheme;
}
```

### B. Unreal Engine 5 (C++ DataAsset)
```cpp
#pragma once

#include "CoreMinimal.h"
#include "Engine/DataAsset.h"
#include "GroundedCharacterData.generated.h"

UENUM(BlueprintType)
enum class EGddCharacterTier : uint8
{
    Divine              UMETA(DisplayName = "Divine"),
    DivineHumanAvatar   UMETA(DisplayName = "Divine Human (Avatar)"),
    StrongMortal        UMETA(DisplayName = "Strong Mortal"),
    WeakMortal          UMETA(DisplayName = "Weak Mortal")
};

UCLASS(BlueprintType)
class RAMG_API UGroundedCharacterData : public UDataAsset
{
    GENERATED_BODY()

public:
    UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Identification")
    FString CharacterName;

    UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Identification")
    FString SanskritName;

    UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Identification")
    EGddCharacterTier CharacterTier;

    UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Physiology")
    float HeightInMeters = 1.8f;

    UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Physiology")
    float WeightInKg = 80.0f;

    UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Physiology", meta = (ToolTip = "Signal transmission delay in ms"))
    float NeurologicalLatencyMs = 200.f;

    UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Physiology", meta = (ToolTip = "Cardiovascular efficiency in L/min"))
    float MaxCardiacOutputLMin = 25.f;

    UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Physiology", meta = (ToolTip = "Anaerobic threshold in mmol/L"))
    float LacticAcidThresholdMmol = 4.f;

    UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Physiology", meta = (ToolTip = "ATP energy replenishment rate in J/s"))
    float AtpRecoveryRateJs = 10.f;

    UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Combat", meta = (ToolTip = "Focus/Willpower capacity in Joules"))
    float MaxFocusCapacityJoules = 100.f;
};
```

---

## 3. Grounded Character GDD Markdown Template

Every modern GDD character file created in the `Modern_docs/Characters/` folder follows this standardized structure:

```markdown
# [Character Name] ([Sanskrit Name])

*   **Role:** [Role - Protagonist, Companion, Boss]
*   **GDD Character Tier:** [Divine / Divine Human (Avatar) / Strong Mortal / Weak Mortal]
*   **Gameplay Archetype:** [Balanced Archer / Agile Hunter / Massive Warlord / Illusory Skirmisher]

---

## 1. Physiological & Biomechanical Specifications

| Parameter | Metric Value | Grounded / Scientific Rationale |
| :--- | :--- | :--- |
| **Age** | [Age] | Determines metabolic peaks and physical maturity. |
| **Height** | [Height in meters] m | Center of gravity and stride mechanics. |
| **Weight** | [Weight in kg] kg | Kinetic momentum and footstep ground-impact force vectors. |
| **Neurological Latency**| [Latency] ms | Flawless cognitive transduction speed. |
| **Max Cardiac Output** | [Cardiac Output] L/min | Aerobic threshold and quick oxygen distribution capacity. |
| **Lactic Acid Threshold**| [Lactate] mmol/L | Anaerobic limit before performance drop. |
| **ATP Recovery Rate** | [ATP Rate] J/s | Quick-dash stamina replenishment time. |
| **Spiritual Focus / Willpower** | [Focus] Joules | Maximum threshold for mental flow state. |
| **Ethical Nature** | [Dharmic / Chaotic / Ragasic] | Personality drive and narrative moral standing. |

---

## 2. Grounded Skills & Physics-Based Powers

### Peak Human Capabilities & Biological Overclocks
*   **Skill 1:** Description of skill (e.g. hyper-oxygenation, focus tracking) with a biological or cognitive explanation.
*   **Skill 2:** Trait (e.g. low-frequency sound localization, kinetic redirection).

### Composite Archery & Kinetic Gear
*   **Weapon System:** Reference to composite weapon (e.g. `../Weapons/Kodanda.md`) and how the character biomechanically wields it.
*   **Equipped Costume:** Reference to composite clothing (e.g. `../Clothing/Materials_Textures.md`) and PBR parameters.

---

## 3. Narrative, Objectives & Logical Drive

### Lore Biography
A realistic and grounded retelling of the character's narrative journey, highlighting human grit, deep relationships, and moral choices.

### Strategic Core Objectives
*   **Initial Acts (1-3):** [Core goal and motivation]
*   **Exile & Search Acts (4-7):** [Core goal and motivation]
*   **Siege & War Acts (8-10):** [Core goal and motivation]

---

## 4. Acoustic Profile & Classical Raga Score

### Auditory Specifications
*   **Vocal Range Frequency:** [Frequency e.g., 85Hz - 150Hz] | Dictates physical depth of spoken words and vocal effort.
*   **Acoustic Theme:** [Sanskrit classical raga scale, e.g. Raga Bhairav] | Melodic profile.
*   **Musical Integration:** Explains how the solo acoustic flute or resonant drums blend based on state changes.

### Action SFX (Acoustic Mechanics)
*   **Footstep Impacts:** Grounded sounds based on mass (heavy boots on dust, light sandaled soft friction).
*   **Vocalizations & Breathing:** Breath sound loops during high exertion (lactic threshold limits).
*   **Combat Action Sounds:** Cable snap of carbon bows, whistle of aerodynamic kinetic shafts.

---

## 5. Visual Render & Particle Systems (VFX)

### Material & Shader Settings
*   **Anisotropic Hair:** PBR highlights for realistic biological hair.
*   **Subsurface Skin Scattering:** Dynamic skin shader coordinates showing physical fatigue.

### Dynamic Spiritual Aura (Flow State Particles)
*   **Focus State Particles:** Fine, localized heat-haze distortion of the air surrounding the body during hyper-focus, avoiding artificial neon glows.
*   **Kinetic Dirt/Debris Particles:** Small rocks and sand reacting to high-velocity leaps and foot strikes (conservation of momentum).
