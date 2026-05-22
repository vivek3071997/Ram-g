# Smart Clothing: High-Performance Materials & Textures

*   **Asset Category:** Procedural PBR Materials & Custom Shader Profiles
*   **GDD Integration:** Dictates fabric physics, wind drag coefficients, and light-reflection PBR shaders for all characters.

---

## 1. Technical Material Profiles

Traditional GDD garments are redesigned into high-performance, aerodynamically sound, and protective 21st-century modern textiles, strictly avoiding cybernetic robotic shells.

### A. Kauseya Silk-Polymer (Sita & Royal Rama)
*   **Structure:** Ultra-lightweight raw silk woven with fine light-refracting polymer micro-fibers, creating a natural light guide.
*   **PBR Shader Settings:**
    *   *Base Color:* High-contrast white and gold pigment maps.
    *   *Roughness:* `0.15` (high anisotropic highlight).
    *   *Metallic:* `0.0` (dielectric profile).
    *   *Sheen:* `0.8` (soft, light-transmitting velvet-like rim glow).
*   **Physics Drag Coefficient ($C_d$):** `0.45` | Fluid, graceful drapes that billow in wind sweeps.
*   **Gameplay Utility:** Active optical refraction reduces visual signature in shadows by `85%`.

### B. Valkala Hemp-Mesh (Rama & Lakshmana Exile Wear)
*   **Structure:** High-strength, breathable organic hemp fibers blended with synthetic micro-polymers, optimized for wilderness survival.
*   **PBR Shader Settings:**
    *   *Base Color:* Saffron-ochre and matte black color palettes.
    *   *Roughness:* `0.85` (highly matte, zero sun reflections).
    *   *Metallic:* `0.0`.
    *   *Normal Maps:* Deep, coarse fabric weave capturing realistic micro-threads.
*   **Physics Drag Coefficient ($C_d$):** `1.15` | Form-fitting compression cuts designed to minimize branches grabbing.
*   **Gameplay Utility:** Absorbs sweat, speeds up ATP stamina recovery by `+10%` through optimal thermal insulation.

### C. Ajina Ballistic Hide (Hanuman & Wilderness Hunters)
*   **Structure:** Kevlar-infused biological hide, cured using high-density organic compounds to create a flexible, impact-absorbing plate.
*   **PBR Shader Settings:**
    *   *Base Color:* Earthy dark-brown and charcoal.
    *   *Roughness:* `0.6` (soft natural leather shine).
    *   *Metallic:* `0.05` (organic lipid coating).
*   **Gameplay Utility:** Dampens low-velocity kinetic projectile hits, reducing pierce damage by `35%`.

### D. Kavacha Electromagnetic Mail (Ravana & Guard Captains)
*   **Structure:** Flexible, interlocking micro-rings made of titanium-carbon alloy, pre-charged to generate a localized micro-electromagnetic field.
*   **PBR Shader Settings:**
    *   *Base Color:* Obsidian black with dark gold accents.
    *   *Roughness:* `0.1` (extremely sharp specular peaks).
    *   *Metallic:* `0.95` (fully metallic conductor).
    *   *Anisotropy:* High circular mapping to simulate metal ring facets.
*   **Gameplay Utility:** Completely disperses physical kinetic slashes, converting the energy into minor thermal emissions.
