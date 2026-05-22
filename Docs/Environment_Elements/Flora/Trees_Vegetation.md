# Environment Elements: Trees & Vegetation Database

*   **Database Directory:** `Docs/Environment_Elements/Flora/`
*   **Engine Blueprint Class:** `A_FloraTree` / `StaticMesh` (Wind Simulation Component)

---

## 1. Modular Entity Specifications

### A. Golden Ashoka Trees (Swarna-Ashoka)
*   **Mythological Role:** Legendary trees of Ravana's pleasure garden (*Ashoka Vatika*). They bloom in rich gold-amber colors, contrasting the dark sorrow of Sita's imprisonment.
*   **Physical & Rendering Specifications:**
    *   *Mass:* `3,000 kg`.
    *   *Bounding Box:* `[5.0m, 5.0m, 9.0m]`.
    *   *PBR Materials:* Glowing golden-amber leaves with copper-red bark. Metallic leaf sheen: `0.7` (creates shifting specular reflections). Leaf subsurface scattering (SSS): `0.35` (warm orange transmission under light).
*   **Gameplay & Physical Mechanics:**
    *   *Wind Simulation Profile:* High flex. Leaves flutter and shimmer procedurally at low wind speeds.
    *   *Grappling Anchors:* Branches support active grappling mechanics using Hanuman's tail, enabling high-ground traversal.
    *   *Stealth Shadow Volumes:* Foliage creates deep shadow zones on the ground mesh, shielding players from sentry sight cones.

### B. Sal Hardwood Columns (Shala)
*   **Mythological Role:** Colossal hardwood trees of Dandakaranya, forming massive natural walls and ancient pillars.
*   **Physical & Rendering Specifications:**
    *   *Mass:* `8,000 kg`.
    *   *Bounding Box:* `[2.2m, 2.2m, 20.0m]`.
    *   *PBR Materials:* Coarse brown furrowed bark, dark green leaves. Normal-map depth: `0.8` (deep wood bark grooves).
*   **Gameplay & Physical Mechanics:**
    *   *Climbable Bark:* Bark surfaces contain high-friction mesh loops, allowing players to climb trunks without using stamina.
    *   *Destructible Obstacles:* Trees can be broken by high-impact attacks (e.g. Hanuman's Gada swings or charging boss elephants), causing them to fall along designated physics vectors and crush any enemies below.

### C. Holy Banyan Trees (Nyagrodha)
*   **Mythological Role:** Sacred, sprawling trees of Panchavati, providing shelter and shade to sages and exiles.
*   **Physical & Rendering Specifications:**
    *   *Mass:* `18,000 kg` (Enormous multi-trunk system).
    *   *Bounding Box:* `[18.0m, 18.0m, 14.0m]`.
    *   *PBR Materials:* Grey-white bark, deep waxy green leaves. High sheen, low metallic values.
*   **Gameplay & Physical Mechanics:**
    *   *Aerial Root Swings:* Sprawling hanging roots act as interactive rope physics objects. The player can grab a root to swing across rock chasms or accelerate jumps.
    *   *Foliage Platforms:* The thick upper branch canopy acts as a solid traversable platform layer above the forest floor.

---

## 2. GDD Integration & Relative Mapping

The vegetative assets are mapped directly to their locations and scene environments:

| Entity Name | Primary Location Link | Scene Placement | Connected Characters |
| :--- | :--- | :--- | :--- |
| **Golden Ashoka Tree** | [Lanka (LOC_LANKA)](../../Locations/Lanka.md) | [Stormy Stratosphere (SCENE_STORMY_STRATOSPHERE)](../../Scenes/Scene_6_Stormy_Stratosphere.md) | [Sita](../../Characters/Sita.md) / [Hanuman](../../Characters/Hanuman.md) |
| **Sal Hardwood Tree** | [Ayodhya (LOC_AYODHYA)](../../Locations/Ayodhya.md) | [Dandaka Wilds (SCENE_DANDAKA_WILDS)](../../Scenes/Scene_4_Dandaka_Wilds.md) | [Sage Vishwamitra](../../Characters/Sage_Vishwamitra.md) / [Lord Rama](../../Characters/Lord_Rama.md) |
| **Nyagrodha Banyan Tree** | [Dandakaranya (LOC_DANDAKARANYA_PANCHAVATI)](../../Locations/Dandakaranya_Panchavati.md) | [Enchanted Canopy (SCENE_ENCHANTED_CANOPY)](../../Scenes/Scene_5_Enchanted_Canopy.md) | [Lakshmana](../../Characters/Lakshmana.md) |

---

## 3. Acoustic & Audio Profile

*   **Golden Ashoka Tree SFX:**
    *   *Leaf Shimmer:* Soft, metallic rustling sounds (`Leaf_Rustle_Metallic.wav`) that trigger during high wind vectors.
*   **Sal Hardwood Tree SFX:**
    *   *Fall Crash:* Booming splintering wood sounds followed by a heavy earth impact rumble (`Impact SFX: Tree_Fall_Crash.wav`).
*   **Nyagrodha Banyan Tree SFX:**
    *   *Root Creak:* Deep, organic groaning of massive branches sway loops under wind strain.
