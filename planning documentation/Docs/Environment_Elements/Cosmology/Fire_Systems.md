# Cosmology: Fire & Thermal Systems

*   **Database Directory:** `Docs/Environment_Elements/Cosmology/`
*   **Engine Blueprint Class:** `A_FireVolume` / `NiagaraSystem` (Thermal Fluid Solver)

---

## 1. Thermal Light Specifications & Combustion States

The combustion and thermal systems in **Ram-G** regulate environmental hazards, defensive barriers, and Asuric fear triggers:

| Fire Type | Fuel Material | Light Color (Hex / HSL) | Temperature | Primary Gameplay Role |
| :--- | :--- | :--- | :--- | :--- |
| **Yajna Sacred Fire** | Sandalwood & Clarified Butter | `Hex #FF5722` / `HSL(14°, 100%, 57%)` | `800°C` | Sacred shielding area, purges Asuric spawn, recharges Prana. |
| **Lanka Firestorm** | Golden Palace Roofs & Oil | `Hex #E67E22` / `HSL(28°, 80%, 52%)` | `1,200°C` | City destruction act, collapsing debris, smoke suffocation. |
| **Volcanic Lava** | Molten Obsidian Basalt | `Hex #C0392B` / `HSL(6°, 63%, 46%)` | `1,500°C` | High-damage liquid volume, blocks paths, creates obsidian bridges when cooled. |

---

## 2. Gameplay Mechanics: Altar Protection & Volcanic Magma

### A. Sacred Yajna Protection Field (Agni-Vedi)
*   **Mechanic:** The sacrificial altar fire at Siddhashrama acts as a permanent **spiritual barrier**.
*   **Active Boundary:** A spherical volume, radius `6.0 meters`. Any minor Asuric shadow entity stepping inside this volume is instantly vaporized. The player (Rama) gets `+25%` bow draw speed and active health regen while inside the Vedi circle.

### B. Lanka Palace Burning (Lanka-Dahan Loop)
*   **Mechanic:** Playing as Hanuman with his tail ignited (Act 7), the player sprints across roofs. Touching wooden/gilded structures sets them on fire.
*   **Destructive Chain Reaction:** Ignited structures lose structural HP at `5%` per second. Once at `0%`, the structure collapses, generating falling debris hazards that force the player to leap away.

### C. Volcanic Lava Volumes
*   **Physics Profile:** Thick liquid displacement mesh. Stepping in lava deals massive, lethal damage (`150 HP/s`) and inflicts permanent "Melt" status.
*   **Water Cooling Reaction:** Firing the **Varunastra** water-storm arrow into a lava flow cools the surface, converting the fluid into a solid, black **Obsidian Bridge** that players can walk on safely for 15 seconds.

---

## 3. GDD Integration & Relative Mapping

The thermal systems are connected directly to corresponding combat arenas and characters:

| Entity Name | Primary Location Link | Scene Placement | Connected Characters |
| :--- | :--- | :--- | :--- |
| **Yajna Sacred Fire** | [Mithila (LOC_MITHILA)](../../Locations/Mithila.md) | [Siddhashrama Altar (SCENE_SIDDHASHRAMA_ALTAR)](../../Scenes/Scene_1_Siddhashrama_Altar.md) | [Sage Vishwamitra](../../Characters/Sage_Vishwamitra.md) / [Lord Rama](../../Characters/Lord_Rama.md) |
| **Lanka Firestorm** | [Lanka (LOC_LANKA)](../../Locations/Lanka.md) | [Stormy Stratosphere (SCENE_STORMY_STRATOSPHERE)](../../Scenes/Scene_6_Stormy_Stratosphere.md) | [Hanuman](../../Characters/Hanuman.md) / [Ravana](../../Characters/Ravana.md) |
| **Volcanic Lava** | [Lanka (LOC_LANKA)](../../Locations/Lanka.md) | [Dandaka Wilds (SCENE_DANDAKA_WILDS)](../../Scenes/Scene_4_Dandaka_Wilds.md) | [Maricha](../../Characters/Maricha.md) |

---

## 4. Acoustic & Audio Profile

*   **Sacred Fire Ambient:** Rhythmic, peaceful wood crackling sounds overlaying low, spiritual Sanskrit chant hums (`Fire_Yajna_Loop.wav`).
*   **City Firestorm Roar:** Chaotic, roaring combustion sweeps, collapsing timber structures, and screaming winds.
*   **Lava Hissing:** Deep, slow, bubble-popping boiling liquid rumbles combined with sharp steam hisses when cooling arrows strike the molten surface.
