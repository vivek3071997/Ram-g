# Relics: Artifacts & Relics Database

*   **Database Directory:** `Docs/Environment_Elements/Relics/`
*   **Engine Blueprint Class:** `A_InteractiveArtifact` / `StaticMesh` (Puzzle Trigger Component)

---

## 1. Modular Entity Specifications

### A. Ganga-Jal Purification Flask
*   **Mythological Role:** Holy river water collected from the sacred Ganges, blessed by sages to cleanse demonic toxins.
*   **Physical & Interactive Specifications:**
    *   *Visuals:* A small terracotta flask with copper bands, filled with glowing blue liquid. Glass refraction shader with sliding liquid bubble physics.
*   **Gameplay Mechanics:**
    *   *Active Purging:* Can be thrown at toxic swamp pools or green spore zones. Upon impact, it explodes in a splash of bright blue liquid particles, purifying a `5.0m` radius and converting swamp mud into solid, clean grass.
    *   *Spore Cleansing:* Instantly cleanses companions from "Poison" debuffs.

### B. Ley-Line Prisms (Sphatika-Darpan)
*   **Mythological Role:** Giant, multi-faceted hexagonal quartz crystals mounted on rotating stone bases, used to direct cosmic energy.
*   **Physical & Interactive Specifications:**
    *   *Visuals:* A 2.5-meter crystalline geode prism that glows with rainbow refraction flares under direct light.
*   **Active Puzzle Mechanics:**
    *   *Light Refraction Loop:* The player interacts with stone levers to rotate the prism. The goal is to align the prism with high-energy wall runes, focusing a laser-like beam of solar light into circular floor seals, which neutralizes ancient gravitational locks.

### C. Sandalwood Fuel Logs (Smidha)
*   **Mythological Role:** Sacred, fragrant sandalwood logs used to maintain the purity of sacrificial fires.
*   **Gameplay Mechanics:**
    *   *Fire Fueling:* During Siddhashrama Altar defense phases, Asuric invaders try to extinguish the flame. The player must collect Sandalwood logs from nearby racks and toss them into the fire, replenishing the barrier energy by `20%` per log.

### D. Acoustic Palace Mirrors (Dhwanisphatika)
*   **Mythological Role:** Concentric, highly polished bronze mirrors mounted in palatial corridors, designed to capture and amplify sound waves.
*   **Active Puzzle Mechanics:**
    *   *Eavesdropping Puzzle:* Playing as King Dasharatha, the player rotates these brass mirrors to focus sound reflections from distant royal chambers, capturing crucial dialogue logs about Kaikeyi's plans.

---

## 2. GDD Integration & Relative Mapping

The interactive artifacts are connected directly to corresponding locations, scenes, and characters:

| Entity Name | Primary Location Link | Scene Placement | Connected Characters |
| :--- | :--- | :--- | :--- |
| **Ganga-Jal Flask** | [Dandakaranya (LOC_DANDAKARANYA_PANCHAVATI)](../../Locations/Dandakaranya_Panchavati.md) | [Dandaka Wilds (SCENE_DANDAKA_WILDS)](../../Scenes/Scene_4_Dandaka_Wilds.md) | [Sita](../../Characters/Sita.md) / [Lakshmana](../../Characters/Lakshmana.md) |
| **Sphatika Prism** | [Mithila (LOC_MITHILA)](../../Locations/Mithila.md) | [Pinaka Sanctuary (SCENE_PINAKA_SANCTUARY)](../../Scenes/Scene_2_Pinaka_Sanctuary.md) | [King Janaka](../../Characters/King_Janaka.md) / [Sage Parashurama](../../Characters/Sage_Parashurama.md) |
| **Sandalwood Fuel** | [Mithila (LOC_MITHILA)](../../Locations/Mithila.md) | [Siddhashrama Altar (SCENE_SIDDHASHRAMA_ALTAR)](../../Scenes/Scene_1_Siddhashrama_Altar.md) | [Sage Vishwamitra](../../Characters/Sage_Vishwamitra.md) / [Lord Rama](../../Characters/Lord_Rama.md) |
| **Acoustic Mirror** | [Ayodhya (LOC_AYODHYA)](../../Locations/Ayodhya.md) | [Palace Anger (SCENE_PALACE_ANGER)](../../Scenes/Scene_3_Palace_Anger.md) | [King Dasharatha](../../Characters/King_Dasharatha.md) / [Queen Kaikeyi](../../Characters/Queen_Kaikeyi.md) |

---

## 3. Acoustic & Audio Profile

*   **Ganga-Jal Splash SFX:**
    *   *Splash Sound:* Glass shatter followed by a high-pitch, refreshing water splash sound (`Ganga_Splash.wav`).
*   **Sphatika Prism SFX:**
    *   *Laser Focus:* High-frequency crystalline hum when a light beam is successfully locked onto a floor rune.
*   **Sandalwood Fuel SFX:**
    *   *Fire Crackle:* Soft wood thump followed by a bright crackling roar of the altar barrier.
*   **Acoustic Mirror SFX:**
    *   *Acoustic Focus:* Sound transitions from muffled echoes into sharp, clean voice audio as the mirror matches the target angle.
