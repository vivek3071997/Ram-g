# Grounded Relics: Jewelry, Regalia, & Crystalline Artifacts

*   **Asset Category:** Interactive Items & Optical Puzzle Objects
*   **GDD Integration:** Links artifact physical stats (mass, light transmission, chemical concentration) directly to player inventory, shields, and puzzle systems.

---

## 1. Royal Regalia & Jewelry (Relics)

All regalia are biological and mineral items designed to scale player stats or protect the physical frame, strictly avoiding bionic augmentations.

### A. Sita's Chudamani Gem (Light-Refracting Beacon)
*   **Physical Specs:** Mass: `0.08 kg` | Natural polished light-refracting crystal.
*   **PBR Shader Settings:** High light transmission (`0.95`), high refractive index ($n = 2.417$, identical to diamond), producing brilliant silver sparkles in moonlight.
*   **Gameplay Utility:** Active beacon. When held or dropped by Sita, it acts as a passive point-light source that is highly visible to Rama's long-range targeting visor.

### B. Royal Solar Chest Plates (Arrow Deflection)
*   **Physical Specs:** Mass: `4.5 kg` | High-purity polished brass alloy.
*   **PBR Shader Settings:** Metallic: `1.0` | Roughness: `0.08` | Reflects bright yellow solar glare.
*   **Gameplay Utility:** Direct-impact protection. Deflects incoming minor Asuric arrows by `100%` if they hit the front chest hitbox, distributing the kinetic impact across the player's core.

---

## 2. Interactive Systems & Crystalline Artifacts

### A. Ganga-Jal Purification Flask (Chemical Purge)
*   **Physical Specs:** Mass: `0.75 kg` (Filled) | Sealed copper flask containing active chemical compounds.
*   **Gameplay Utility:** Splash-impact utility. Throwing the flask at toxic swamp vents releases a chemical neutralizer, purifying the air within a `3m` radius and converting the toxic gas into harmless water vapor.

### B. Sphatika Alignment Prisms (Optical Puzzles)
*   **Physical Specs:** Mass: `120 kg` (Static) | Giant, natural-cut quartz crystal prisms mounted on stone turntable gears in Mithila.
*   **PBR Shader Settings:** Subsurface scattering, high anisotropic light transmission, and clear internal fracture maps.
*   **Gameplay Utility:** Light-refraction keys. Players must align these large static prisms to capture and direct directional solar beams into subterranean photo-sensitive receivers to open sealed vault doors.
