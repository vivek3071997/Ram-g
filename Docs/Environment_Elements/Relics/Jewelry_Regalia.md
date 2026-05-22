# Relics: Jewelry & Regalia Database

*   **Database Directory:** `Docs/Environment_Elements/Relics/`
*   **Engine Blueprint Class:** `A_EquippableRelic` / `StaticMesh` (Socket Attachment Component)

---

## 1. Modular Entity Specifications

### A. Sita's Chudamani Hair Gem
*   **Mythological Role:** The sacred crest jewel of Princess Sita, gifted by her father Janaka. It serves as the ultimate token of trust and emotional anchor delivered by Hanuman to Rama.
*   **Physical & Rendering Specifications:**
    *   *Visuals:* A high-purity teardrop diamond surrounded by red rubies, mounted on a delicate gold hairpin.
    *   *Refraction Shader:* Ultra-high refraction index (`1.85`). Projects a shimmering, star-like golden beam when hit by direct moonlight.
    *   *Emissive Indicator:* Glows softly inside the dark Ashoka Vatika, serving as a beacon that guides Hanuman towards Sita's hidden courtyard.
*   **Active Gameplay Mechanics:**
    *   *Sita's Hope Aura:* Carrying the Chudamani in Hanuman's inventory grants a permanent `+20%` speed boost and complete immunity to Lanka's fear status effects during the escape acts.

### B. Solar Royal Chest Plates (Uraschhada)
*   **Mythological Role:** Golden plate armor worn by the kings and princes of the Solar Dynasty, engraved with solar chariot wheels.
*   **Physical & Rendering Specifications:**
    *   *Visuals:* Highly polished gold chest plate draped with silk banners.
    *   *Materials:* High metallic PBR (`1.0`), near-zero roughness (`0.05`).
*   **Active Gameplay Mechanics:**
    *   *Arrow Deflection:* Grants a passive `15%` chance to automatically deflect minor enemy arrows, causing them to bounce off the chest plate in a shower of golden sparks.
    *   *Stamina Regeneration:* Boosts physical stamina recovery rates by `15%`.

### C. Imperial Saffron Crowns (Kirita)
*   **Mythological Role:** Majestic, high-tiered gold crowns worn during coronation acts, representing absolute cosmic order.
*   **Active Gameplay Mechanics:**
    *   *Cosmic Cap Boost:* Wearing the Kirita (only during palatial acts) multiplies maximum health by `2.0` and spiritual Prana reserves by `1.5`.

### D. Royal Pearl Necklaces (Mukta-Hara)
*   **Mythological Role:** Pure sea pearl chains gifted by the ocean deity Samudra Deva.
*   **Active Gameplay Mechanics:**
    *   *Poison Cleansing:* Reduces the ticking duration of Asuric poison damage over time by `50%`.

---

## 2. GDD Integration & Relative Mapping

The regalia items are mapped directly to their locations, scenes, and characters:

| Entity Name | Primary Location Link | Scene Placement | Connected Characters |
| :--- | :--- | :--- | :--- |
| **Chudamani Gem** | [Lanka (LOC_LANKA)](../../Locations/Lanka.md) | [Stormy Stratosphere (SCENE_STORMY_STRATOSPHERE)](../../Scenes/Scene_6_Stormy_Stratosphere.md) | [Sita](../../Characters/Sita.md) / [Hanuman](../../Characters/Hanuman.md) / [Lord Rama](../../Characters/Lord_Rama.md) |
| **Solar Chest Plate** | [Ayodhya (LOC_AYODHYA)](../../Locations/Ayodhya.md) | [Siddhashrama Altar (SCENE_SIDDHASHRAMA_ALTAR)](../../Scenes/Scene_1_Siddhashrama_Altar.md) | [Lord Rama](../../Characters/Lord_Rama.md) / [King Dasharatha](../../Characters/King_Dasharatha.md) |
| **Saffron Crown** | [Ayodhya (LOC_AYODHYA)](../../Locations/Ayodhya.md) | [Pinaka Sanctuary (SCENE_PINAKA_SANCTUARY)](../../Scenes/Scene_2_Pinaka_Sanctuary.md) | [King Janaka](../../Characters/King_Janaka.md) / [Prince Bharata](../../Characters/Prince_Bharata.md) |
| **Pearl Necklace** | [Lanka (LOC_LANKA)](../../Locations/Lanka.md) | [Dandaka Wilds (SCENE_DANDAKA_WILDS)](../../Scenes/Scene_4_Dandaka_Wilds.md) | [Samudra Deva](../../Characters/Samudra_Deva.md) / [Lakshmana](../../Characters/Lakshmana.md) |

---

## 3. Acoustic & Audio Profile

*   **Chudamani Gem SFX:**
    *   *Magic Resonance:* A high-frequency, delicate chime loop (`Chudamani_Ring.wav`) that grows louder as the player approaches Sita's location.
*   **Solar Chest Plate SFX:**
    *   *Deflect Ring:* A loud, metallic bronze clink combined with an electric hiss when deflecting arrows in battle.
*   **Saffron Crown & Pearl SFX:**
    *   *Foley Shimmer:* Soft rustling cloth and gentle bead rattling sounds during movement.
