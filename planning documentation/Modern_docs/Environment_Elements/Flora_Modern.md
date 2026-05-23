# Grounded Flora: Vegetation, Ancient Trees, & Edibles

*   **Asset Category:** Interactive Plant Life & Collectible Pickups
*   **GDD Integration:** Establishes PBR vegetation shaders, climbing meshes, and botanical health/stamina restoration values.

---

## 1. Ancient Forest Vegetation (Flora)

Trees and plants are designed with highly realistic physical properties, serving as active traversal platforms and cover systems in wilderness zones.

### A. Golden Ashoka Tree (Refractive Canopy)
*   **Biomechanical Structure:** High-strength, flexible branches with elastic yield limits up to `4,500 N`, serving as dynamic grapple swing nodes.
*   **PBR Leaf Shader:** Anisotropic reflection normal maps that shift between deep emerald-green and bright golden-yellow depending on sun angle, aiding active camouflage.
*   **Traversal Hook:** Players can use [Lakshmana's parkour climbing mechanics](file:///../Characters/Lakshmana.md) to swing along Ashoka canopies.

### B. Sal Hardwood Tree (Destructible Pillars)
*   **Biomechanical Structure:** Towering, straight, dense trunks with deep-grooved, climbable bark normal maps.
*   **Physical Properties:** Mass: `1,200 kg` | Destructible mesh asset. Heavy blows (such as [Hanuman's mace sweeps](file:///../Characters/Hanuman.md) or Tataka's charges) break the trunk, creating a falling physics hazard that clears minor units.

### C. Nyagrodha Banyan (Sprawling Cover)
*   **Biomechanical Structure:** Massive central trunk with sprawling aerial root networks that anchor into the soil, creating natural, low-profile defensive trenches and stealth cover blocks.

---

## 2. Collectible Edibles & Organic Stimulants

All pickups are grounded in natural organic chemistry and human metabolic recovery, strictly avoiding magical potions.

### A. Anjana's Mangoes (ATP Pickups)
*   **Nutrient Profile:** High-fructose, carbohydrate-rich organic fruit.
*   **Gameplay Utility:** Consuming one mango restores `40 Joules` of ATP energy reserves, quickly cooling down dash moves.

### B. Sabari's Tested Berries (Health Purge)
*   **Nutrient Profile:** Bioflavocitrin-rich forest berries.
*   **Gameplay Utility:** Purges blood toxins and inflicts `+25 HP` immediate cellular healing, removing poison status effects.

### C. Soma-Rasa (Yogic Metabolic Stimulant)
*   **Nutrient Profile:** Concentrated liquid extract of high-altitude Himalayan mountain herbs (*Soma plant*).
*   **Gameplay Utility:** Hyper-oxygenates the cardiovascular system. Consuming one flask increases ATP recovery speed by `+50%` and expands the Focus pool by `+100 Joules` for `20 seconds`, followed by a mild `3-second` cardiac cool-down phase.
