# Clothing: Materials & Textures Bible

*   **Asset Category:** Character Clothing Materials / Material Instances
*   **GDD Integration:** Underpins character visual states and mechanical stat adjustments.

---

## 1. PBR Material Specifications

To achieve supreme visual excellence and harmonize textures in modern game engines, the clothing materials in **Ram-G** are defined by the following physically based rendering (PBR) parameters:

| Material Type | Mythological Context | Base Roughness | Metallic | Opacity / Sheen | Specular Reflectance |
| :--- | :--- | :--- | :--- | :--- | :--- |
| **Kauseya (Royal Silk)** | Royal luxury, palatial states. | `0.15` | `0.0` | `0.90` (High Anisotropic Sheen) | `0.65` |
| **Valkala (Bark-Cloth)** | Ascetic exile, forest states. | `0.85` | `0.0` | `1.00` (Dry / High Diffuse) | `0.10` |
| **Ajina (Deerskin)** | Sage meditation, spiritual focus. | `0.70` (Fur) | `0.0` | `1.00` (Short Velvet Fur) | `0.20` |
| **Kavacha (Golden Mail)** | Divine warrior protection. | `0.05` | `1.0` | `1.00` (Metallic Specular Gleam)| `0.95` |

---

## 2. Rendering Shader Blueprints

### A. Kauseya (Royal Silk) Shader Profile
*   **Shader Target:** Custom Anisotropic Fabric Shader (Satin-Sheen profile).
*   **Shader Variables:**
    *   *Anisotropic Angle:* `0.75` (creates elongated, shimmering highlight bands reflecting palace torchlight).
    *   *Micro-Fuzz Density:* `0.12` (adds a soft purple/orange edge highlight representing golden embroidery threads).
    *   *Vertex Wind Physics:* Low amplitude (`0.05m`), low frequency (`0.5Hz`) to simulate rich, heavy weight.
*   **Gameplay Role:** Worn in palaces. Visually wows the player in Act 1, 2, and 10 with warm, shining golden reflections.

### B. Valkala (Bark-Cloth) Shader Profile
*   **Shader Target:** Rough Micro-Bump Surface Shader (Substance-Designer procedural wood fiber).
*   **Shader Variables:**
    *   *Micro-Bump Depth:* High (`0.6`), giving the coarse, hand-woven tree bark a highly detailed 3D structure.
    *   *Subsurface Scattering (SSS):* Low (`0.05`), ensuring the fabric absorbs light deeply, emphasizing natural earth tones.
    *   *Vertex Wind Physics:* High stiffness, low bend. Fabric folds cleanly rather than flowing.
*   **Mechanical Utility:** Worn during the exile. Provides a passive `+25%` stealth bonus when Crouched inside forest fern foliage (`OBJ_FERN_FOLIAGE`).

### C. Ajina (Deerskin Cape) Shader Profile
*   **Shader Target:** Short-Pile Velvet Fur Shader (Shell-and-Fin rendering).
*   **Shader Variables:**
    *   *Fur Length:* `0.02m`.
    *   *Fuzz Scale:* `0.4` (soft, light-absorbing surface).
    *   *Specular Tint:* Warm brown (`Hex #8C5A3C`).
*   **Gameplay Role:** Used as shoulder capes or sit-pads by sages (e.g., Vishwamitra, Sabari). Sitting on an Ajina mat acts as a safe checkpoint, saving player status and clearing negative poison marks.

### D. Kavacha (Golden Mail) Shader Profile
*   **Shader Target:** Metallic Scale/Chainmail PBR Shader.
*   **Shader Variables:**
    *   *Metallic Scale Map:* Hexagonal scale tiling.
    *   *Roughness Map:* High contrast, creating dynamic sparkling highlights when the player performs combat dashes.
    *   *Anisotropic Sparkle:* Glowing solar rays projecting from Rama's armor when *Prana* is at 100%.
*   **Mechanical Utility:** Worn in battles. Grants `80%` physical defense and `50%` Asuric poison resistance. Reduces combat stamina recovery time by `15%`.
