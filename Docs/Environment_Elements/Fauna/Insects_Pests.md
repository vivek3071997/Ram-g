# Environment Elements: Insects & Pests Database

*   **Database Directory:** `Docs/Environment_Elements/Fauna/`
*   **Engine Blueprint Class:** `A_InsectSwarm` / `NiagaraSystem` (GPU Particle Swarm)

---

## 1. Modular Entity Specifications

### A. Asuric Locust Swarms (Maya Patanga)
*   **Mythological Role:** Demonic locust swarms summoned by the demon Tataka to block out the sun, blind archers, and defile holy altars.
*   **Physical & Particle Specifications:**
    *   *Swarm System:* GPU Niagara particle system spawning `2,500` active locust sprites per swarm volume.
    *   *Volume Size:* Spherical bounds, radius `8.0 meters`.
    *   *Material Shader:* Black oil-satin, high absorption. High pixel-depth offset to simulate fuzzy swarm boundaries.
*   **Gameplay & Occlusion Mechanics:**
    *   *Targeting Occlusion:* Bypasses standard locking/archery sights. The player's targeting reticle is disabled while inside the swarm volume.
    *   *Health Drain:* Deals `5.0` damage per second and applies the "Dread" status, reducing Stamina regeneration rates by `30%`.
    *   *Dispersal Method:* High vulnerability to heat. Firing a fire arrow (`Agneyastra`) into the swarm ignites the gas trails, causing a chain explosion that clears the swarm.

### B. Divine Glowing Fireflies (Jyotirlinga Patanga)
*   **Mythological Role:** Sacred bioluminescent fireflies that nest near hermitage groves, showing paths to lost travellers.
*   **Physical & Particle Specifications:**
    *   *Particle System:* Dynamic vector field movement. `150` floating particles per cluster.
    *   *Bioluminescent Lighting:* Emits dynamic soft gold-green point light (`Hex #2ECC71`, `Intensity: 0.8 Lux`, radius: `3.0m`).
*   **Behavioral & Interactive Mechanics:**
    *   *Navigation Aid:* Glow and cluster near hidden platforming ledges and grapple rings at night.
    *   *Stealth Integration:* Crouching inside a firefly swarm reduces player visibility to enemies by `40%`, absorbing the player's heat signature.

### C. Toxic Swamp Flies (Krimi Swarm)
*   **Mythological Role:** Swarm pests of the deep Dandaka swamp valleys, feeding on decaying Asuric matter.
*   **Physical & Particle Specifications:**
    *   *Swarm System:* CPU particle system with physics collision loops. `500` particles.
    *   *Visuals:* Heavy green vapor smoke plumes trace the swarm path.
*   **Behavioral & Interactive Mechanics:**
    *   *AoE Hazard:* Spawns statically over toxic green swamp waters.
    *   *Mechanical Debuff:* Stepping into the swarm slows physical movement speed by `20%` and deals poison status damage.

---

## 2. GDD Integration & Relative Mapping

The insect elements are connected directly to corresponding combat arenas and characters:

| Entity Name | Primary Location Link | Scene Placement | Connected Characters |
| :--- | :--- | :--- | :--- |
| **Asuric Locust Swarm** | [Mithila (LOC_MITHILA)](../../Locations/Mithila.md) | [Siddhashrama Altar (SCENE_SIDDHASHRAMA_ALTAR)](../../Scenes/Scene_1_Siddhashrama_Altar.md) | [Tataka](../../Characters/Tataka.md) / [General Indrajit](../../Characters/General_Indrajit.md) |
| **Glowing Firefly** | [Dandakaranya (LOC_DANDAKARANYA_PANCHAVATI)](../../Locations/Dandakaranya_Panchavati.md) | [Enchanted Canopy (SCENE_ENCHANTED_CANOPY)](../../Scenes/Scene_5_Enchanted_Canopy.md) | [Sita](../../Characters/Sita.md) / [Lakshmana](../../Characters/Lakshmana.md) |
| **Toxic Swamp Fly** | [Kishkindha (LOC_KISHKINDHA)](../../Locations/Kishkindha.md) | [Dandaka Wilds (SCENE_DANDAKA_WILDS)](../../Scenes/Scene_4_Dandaka_Wilds.md) | [Maricha](../../Characters/Maricha.md) |

---

## 3. Acoustic & Audio Profile

*   **Asuric Locust Swarm SFX:**
    *   *Swarm Buzz:* High-pitch, chaotic buzz sound loop (`600Hz - 1.8kHz`), shifting in frequency based on swarm speed.
*   **Glowing Firefly SFX:**
    *   *Magic Chime:* Ultra-low volume, delicate wind-chime chimes that trigger when the player walks through.
*   **Toxic Swamp Fly SFX:**
    *   *Heavy Buzz:* Heavy, low rasping hum loop, alerting players to swamp hazards ahead.
