# Environment Elements: Wild Animals Database

*   **Database Directory:** `Docs/Environment_Elements/Fauna/`
*   **Engine Blueprint Class:** `A_FaunaBase` / `Character`

---

## 1. Modular Entity Specifications

### A. Wild Forest Elephants (Vana-Gaja)
*   **Mythological Role:** Standard wildlife of Kosala and Dandaka. Symbolize raw physical power and forest majesty.
*   **Physical & PBR Specifications:**
    *   *Mass:* `5,500 kg` (High kinetic force on collision).
    *   *Bounding Box:* `[3.0m, 5.5m, 3.5m]`.
    *   *PBR Materials:* Coarse grey hide. Diffuse roughness: `0.95`. Normal-map height: `0.75` (high wrinkle depth). Subsurface scattering: `0.0` (opaque).
*   **Behavioral & Interactive Mechanics:**
    *   *AI Navigation:* Herd behavior. Patrols in groups of 3 to 5 along riverbanks. Neutral-docile; turns hostile only if attacked.
    *   *Destructible Interaction:* Charging elephants can break wooden Asuric barricades (`OBJ_BONE_BARRICADE`) and smash minor rock obstacles.
    *   *Combat Hazard:* Foot stomps trigger a screen shake and a radial knockback force within a `4.0m` radius.

### B. Vanara Leopards (Chitraka)
*   **Mythological Role:** Apex predators of the Kishkindha peaks and Dandakaranya undergrowth.
*   **Physical & PBR Specifications:**
    *   *Mass:* `90 kg`.
    *   *Bounding Box:* `[0.6m, 1.8m, 0.8m]`.
    *   *PBR Materials:* Short gold-and-black spotted fur. Specular sheen: `0.4`. Fur-shading anisotropic highlight: `0.5`.
*   **Behavioral & Interactive Mechanics:**
    *   *AI Navigation:* Solitary stealth patroller. Clings to high tree branches and rock shelves.
    *   *Stealth Pounce:* If the player triggers high threat, the leopard lunges from branches, dealing high stagger damage and applying a "Bleed" debuff.
    *   *Environmental Integration:* Avoids camp fires and bright light cones cast by solar torches.

### C. Divine Golden Fawn (Bhumija Mriga)
*   **Mythological Role:** Sita's beloved garden companion, reflecting pure nature and gentle grace.
*   **Physical & PBR Specifications:**
    *   *Mass:* `25 kg`.
    *   *Bounding Box:* `[0.4m, 1.1m, 0.9m]`.
    *   *PBR Materials:* Gold-flecked orange coat with glowing white spots. Emissive texture intensity: `1.5` (glows softly at dusk).
*   **Behavioral & Interactive Mechanics:**
    *   *AI Navigation:* Playful, follows behind Sita within a `3.0m` radius. Flees from combat noises.
    *   *Active Buff Trigger:* Petting the fawn triggers a temporary spiritual aura boost, reducing the casting cost of Sita's earth barriers by `15%` for 60 seconds.

---

## 2. GDD Integration & Relative Mapping

The wild animals are deeply connected to the game's locations, scenes, and characters:

| Entity Name | Primary Location Link | Scene Placement | Connected Characters |
| :--- | :--- | :--- | :--- |
| **Forest Elephant** | [Ayodhya (LOC_AYODHYA)](../../Locations/Ayodhya.md) | [Siddhashrama Altar (SCENE_SIDDHASHRAMA_ALTAR)](../../Scenes/Scene_1_Siddhashrama_Altar.md) | [Sage Vishwamitra](../../Characters/Sage_Vishwamitra.md) |
| **Vanara Leopard** | [Kishkindha (LOC_KISHKINDHA)](../../Locations/Kishkindha.md) | [Dandaka Wilds (SCENE_DANDAKA_WILDS)](../../Scenes/Scene_4_Dandaka_Wilds.md) | [King Sugriva](../../Characters/King_Sugriva.md) |
| **Divine Fawn** | [Mithila (LOC_MITHILA)](../../Locations/Mithila.md) | [Pinaka Sanctuary (SCENE_PINAKA_SANCTUARY)](../../Scenes/Scene_2_Pinaka_Sanctuary.md) | [Sita](../../Characters/Sita.md) |

---

## 3. Acoustic & Audio Profile

*   **Forest Elephant SFX:**
    *   *Vocal Grunt:* Deep, low-frequency trumpeting (`45Hz - 120Hz`). Resonance: highly wet in deep canyons.
    *   *Footsteps:* Massive low-end thuds (`Impact SFX: Heavy_Thud_Dirt_04.wav`), triggering controller haptics.
*   **Vanara Leopard SFX:**
    *   *Stealth Growl:* Low rasping purrs and sharp, brief snarls on pounce activation.
*   **Divine Fawn SFX:**
    *   *Chirp Vocalization:* Gentle, high-pitch soft whistling sounds.
