# GDD Scenes: Grounded Modern Overview

*   **Asset Category:** High-Fidelity Environmental Scene Setup & PBR Shading Catalog
*   **GDD Integration:** Sets engine volumetric lighting, camera focal lengths, particle parameters, and acoustic Raga layers for all 7 key scenes.

---

## 1. Grounded Camera & Rendering Setup

To maintain a consistent, premium, and highly realistic visual look, all scenes utilize standardized camera post-processing, volumetric fog, and PBR material values.

| Scene Component | Standard Value | Rationale |
| :--- | :--- | :--- |
| **Camera Sensor** | 35mm Full Frame (Digital) | Natural field of view, preventing wide-angle distortions. |
| **Focal Lengths** | 50mm (Exploration) \| 85mm (Duels) | Recreates high-end cinematic shallow depth of field. |
| **Volumetric Fog** | Single Scattering Albedo: `0.9` | Realistic light-ray scattering through morning forest mists. |
| **Color Temperature** | Warm: `5,500 K` \| Cold: `6,500 K` | Matches natural sunlight and high-contrast obsidian shadows. |
| **Audio RT60** | Caverns: `3.2s` \| Forests: `0.8s` | Realistic sound wave decay and spatial acoustic depth. |

---

## 2. Integrated GDD Scene Catalog

### ☁️ Scene 0: Sumeru Stratosphere
*   **Visual Setting:** High-altitude lower stratosphere, white-granite peak launch points.
*   **Volumetric & Lighting:** Directional Sun: `120,000 lux` | Color Temp: `6,500 K`. Thin, high-altitude white cirrus clouds utilizing subsurface light transmission shaders.
*   **Post-Processing:** Contrast: `1.05` | Bloom Threshold: `0.9` | Vignette: `0.15` (simulates slight high-G oxygen strain).
*   **PBR Materials:** Dry white granite normal maps, highly reflective snow ice.
*   **Acoustic & Music:** **Raga Hamsadhwani** (Key: E major, heroic, fast-paced solo bansuri flute). Action SFX: roaring high-altitude wind currents, silent glides.

### 🏛️ Scene 1: Siddhashrama Altar
*   **Visual Setting:** Symmetrical stone altar courtyard at the border trade zone.
*   **Volumetric & Lighting:** Directional Sun: `80,000 lux` | Color Temp: `5,500 K` (Warm afternoon). Fine, floating gold dust motes.
*   **Post-Processing:** Pitambara Gold LUT active | Saturation: `1.05`.
*   **PBR Materials:** Polished sandstone flags, coarse terracotta brick walls, raw timber logs.
*   **Acoustic & Music:** **Raga Yaman** (Key: D major, serene temple flutes, steady temple Mridangam hand drums). Action SFX: cracking firewood flames, gentle wind rustles.

### 💎 Scene 2: Pinaka Sanctuary
*   **Visual Setting:** Deep, underground basalt cavern housing the heavy magnetic Compound Bow *Pinaka*.
*   **Volumetric & Lighting:** Deep shadow zones | Heliostat solar beams: `100,000 lux` cutting through dark, damp mist (Volumetric Fog Density: `0.45`).
*   **Post-Processing:** High contrast (`1.15`) | Highlight bloom: `0.8` (blinding light beam reflection).
*   **PBR Materials:** Wet basalt rock normal maps (Roughness: `0.2`), polished bronze winch gears, high-tensile carbon-steel cables.
*   **Acoustic & Music:** **Raga Yaman Kalyan** (Key: D minor, deep Sanskrit temple chants, resonant low-frequency double-bass drones). Action SFX: grinding winches, water drips.

### 🏡 Scene 3: Palace of Exile
*   **Visual Setting:** Symmetrical Ayodhya council hall where the exile decree is processed.
*   **Volumetric & Lighting:** Deep shadows cast by massive granite columns; high-level gold-anodized ceiling grids.
*   **Post-Processing:** Desaturated colors | Saturation: `0.8` | Saffron Channel Gain: `+10%`.
*   **PBR Materials:** Polished white marble floors (Roughness: `0.1`), soft raw silk drapes (Sheen: `0.7`).
*   **Acoustic & Music:** **Raga Darbari** (Key: C minor, solemn, slow-tempo classical violin, heavy Mridangam beats). Action SFX: echoing footsteps on marble, deep sighs.

### 🛶 Scene 4: Godavari Wilds
*   **Visual Setting:** Primeval jungle clearing along the Godavari river bank, housing the simple timber cottage.
*   **Volumetric & Lighting:** Dense forest canopy shadows | Directional Sun: `40,000 lux` filtering through Sal leaves (Light Shafts enabled).
*   **Post-Processing:** Gerua Wilderness LUT active | Saturation: `0.9` | Green Channel Saturation: `1.15`.
*   **PBR Materials:** Damp forest moss normal maps, dry leaves, interlocking timber bark logs.
*   **Acoustic & Music:** **Raga Lalit** (Key: A minor, solitary, quiet morning flutes, distant bird screeches). Action SFX: roaring river rapids, low electrical hum of the boundary line.

### 🦌 Scene 5: Enchanted Canopy
*   **Visual Setting:** Deep forest clearing where Maricha deploys the golden fawn holographic decoy.
*   **Volumetric & Lighting:** Warm twilight lighting | Emissive gold light particles from the fawn decoy (`15.0 cd/m²`).
*   **Post-Processing:** Bloom Threshold: `0.7` | Soft, warm orange highlights.
*   **PBR Materials:** Volumetric gold light fawn hologram shader, matte-black active camouflage carbon fabrics.
*   **Acoustic & Music:** **Raga Yaman Kalyan** (Key: E major, beautiful solo Sitar runs). Action SFX: high-frequency crystal chimes, mechanical throat collars.

### 🌋 Scene 6: Stormy Stratosphere
*   **Visual Setting:** Volcanic ash stratosphere over the Southern Ocean, where Jatayu intercepts Ravana's solar jet.
*   **Volumetric & Lighting:** Dark volcanic ash clouds (Density: `0.65`) | Color Temp: `3,200 K` (Molten red).
*   **Post-Processing:** Obsidian Crimson LUT active | Contrast: `1.3` | Saturation: `0.95`.
*   **PBR Materials:** Dark carbon-fiber active camo jet skins, realistic bird feathers.
*   **Acoustic & Music:** **Raga Bhairav** (Key: G minor, aggressive, heavy war horns, sweeping orchestral strings, tragic female choir). Action SFX: roaring scramjet exhaust, wing-lash wind shears.
