# Environment Elements: Birds & Avian Database

*   **Database Directory:** `Docs/Environment_Elements/Fauna/`
*   **Engine Blueprint Class:** `A_AvianBase` / `Pawn` (Flight Movement Component)

---

## 1. Modular Entity Specifications

### A. Vulture Kings (Jatayu's Flock)
*   **Mythological Role:** Colossal guardian birds of the high skies, descendants of Aruna (charioteer of the sun god). Wielders of absolute loyalty.
*   **Physical & Aerodynamic Specifications:**
    *   *Mass:* `300 kg` (High structural weight).
    *   *Wingspan:* `15 meters` (Bounding Box: `[2.5m, 15.0m, 1.8m]`).
    *   *PBR Materials:* Coarse obsidian-black feathers with volcanic gold tips. Specular anisotropy: `0.7` (feathers reflect light along structural barbs). Roughness: `0.3` (high oil protection sheen).
*   **Flight & Traversal Mechanics:**
    *   *Supersonic Gliding:* Feeds on high stratospheric jet streams. Enters a high-speed glide mode when entering wind channels.
    *   *Wing-Lash Attack:* During combat (as playable Jatayu in Act 5), sweeping wings generate a `50m/s` wind blast that pushes back Asuric gliders and deflects projectiles.

### B. Divine Eagles (Garudaputra)
*   **Mythological Role:** Celestial eagles summoned by Garuda to dissolve dark binding sorcery and rescue the player.
*   **Physical & PBR Specifications:**
    *   *Mass:* `45 kg`.
    *   *Wingspan:* `3.2 meters`.
    *   *PBR Materials:* Pure white and golden plumage. Golden crown feathers glow with celestial *Prana* energy (`Emissive Tint: #F1C40F`, intensity: `2.0`).
*   **Behavioral & Interactive Mechanics:**
    *   *Poison-Purging AoE:* Upon summoning, the eagle sweeps down in a circular dive. Any active poison puddles or *Nagapasha* serpent traps within a `12.0m` radius are vaporized.
    *   *Divine Call Checkpoint:* Landing on ancient obelisks, they act as quest updates and fast-travel anchors.

### C. Forest Songbirds (Kokila & Shuka)
*   **Mythological Role:** Indian Cuckoos (*Kokila*) and green parrots (*Shuka*), providing lush ambient beauty.
*   **Physical & PBR Specifications:**
    *   *Mass:* `0.2 kg`.
    *   *PBR Materials:* Vibrant emerald-green and deep ruby-red satin feathers. High diffuse sheen.
*   **Behavioral & Interactive Mechanics:**
    *   *Ambient Spawners:* Spawn procedurally on leafy canopy nodes in groups of 10 to 15.
    *   *Flee Trigger:* If combat actions occur within `15.0m`, they burst into flight, generating dynamic leafy particle trails and rustling sound effects.

---

## 2. GDD Integration & Relative Mapping

The avian elements are mapped directly to corresponding campaign chapters and characters:

| Entity Name | Primary Location Link | Scene Placement | Connected Characters |
| :--- | :--- | :--- | :--- |
| **Vulture King** | [Lanka (LOC_LANKA)](../../Locations/Lanka.md) | [Stormy Stratosphere (SCENE_STORMY_STRATOSPHERE)](../../Scenes/Scene_6_Stormy_Stratosphere.md) | [Jatayu](../../Characters/Jatayu.md) / [Sampati](../../Characters/Sampati.md) |
| **Divine Eagle** | [Dandakaranya (LOC_DANDAKARANYA_PANCHAVATI)](../../Locations/Dandakaranya_Panchavati.md) | [Siddhashrama Altar (SCENE_SIDDHASHRAMA_ALTAR)](../../Scenes/Scene_1_Siddhashrama_Altar.md) | [Garuda](../../Characters/Garuda.md) / [Lord Rama](../../Characters/Lord_Rama.md) |
| **Forest Songbird** | [Ayodhya (LOC_AYODHYA)](../../Locations/Ayodhya.md) | [Enchanted Canopy (SCENE_ENCHANTED_CANOPY)](../../Scenes/Scene_5_Enchanted_Canopy.md) | [Sita](../../Characters/Sita.md) |

---

## 3. Acoustic & Audio Profile

*   **Vulture King SFX:**
    *   *Sonic Screech:* High-intensity shriek (`1.2kHz - 3.4kHz`), echoing over long distances.
    *   *Wind Shear:* Low-frequency whoosh of massive wings (`Flap SFX: Wing_Whoosh_Heavy.wav`).
*   **Divine Eagle SFX:**
    *   *Celestial Chime:* Chanted mantra chords overlaying its cry on summon.
*   **Forest Songbird SFX:**
    *   *Dynamic Whistling:* Whistling notes procedurally mapped to **Raga Lalit** scales, sounding like traditional woodland birds.
