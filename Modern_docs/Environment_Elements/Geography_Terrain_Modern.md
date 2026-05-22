# Grounded Geography: Dynamic Rivers, Waterbodies, & Mountain Terrains

*   **Asset Category:** World Hydrodynamics & Static Collision Meshes
*   **GDD Integration:** Sets fluid density profiles, wave buoyancy formulas, and physical surface friction coefficients for all terrain assets.

---

## 1. River Hydrodynamics & Liquid Physics

All waterbodies in **Ram-G** use realistic fluid dynamic equations, influencing vehicle drift, player swim stamina, and platform balancing.

### A. Sarayu River (Silent Currents)
*   **Physical Specs:** Flow Velocity: `1.5 m/s` | Density: `1,000 kg/m³` (Freshwater).
*   **Gameplay Utility:** Mild flow drag that slowly drifts the [Ganga Skiff](file:///../Vehicles/Ganga_Stealth_Hydrofoil.md). Easy to swim across, with low stamina consumption.

### B. Ganges River Crossing (Turbulent Rapids)
*   **Physical Specs:** Flow Velocity: `3.5 m/s - 6.0 m/s` | High turbulence.
*   **Physics Formula:** Frictional flow drag acting on boats is calculated using:
    $$F_D = \frac{1}{2} \rho v^2 C_D A$$
*   **Gameplay Utility:** High drag forces require active torque steering. Stepping into the rapids sweeps players downstream, causing rapid stamina depletion unless they use safety ropes.

### C. The Southern Ocean (Deep Salt Water)
*   **Physical Specs:** Flow Velocity: variable wave amplitudes up to `4.5m` height | Density: `1,025 kg/m³` (Saline).
*   **Gameplay Utility:** Violent waves that damage standard light watercraft. Crossing requires the tactical engineering of the stone bridge.

---

## 2. Mountain & Cavern Terrains

Mountain terrains feature highly detailed static collision meshes with realistic friction parameters, dictating parkour mechanics and climbing stamina costs.

### A. Sumeru Granite Cliffs (Vertical Climbing)
*   **Physical Specs:** Vertical white granite | Friction Coefficient ($\mu$): `0.7` (High grip).
*   **Gameplay Utility:** High grip allows quick parkour ascends using standard leather flats, consuming minimal climbing stamina.

### B. Rishyamukha Sandstone Crags (Loose Shale)
*   **Physical Specs:** Layered red sandstone | Friction Coefficient ($\mu$): `0.4` (Low grip).
*   **Gameplay Utility:** Loose sandstone shale slips under foot pressure. Landing hard on shale slopes triggers slide mechanics, requiring player coordination to prevent fall damage.

### C. Trikuta Volcanic Caves (Glassy Obsidian)
*   **Physical Specs:** Mirror-polished black obsidian | Friction Coefficient ($\mu$): `0.2` (Slippery).
*   **Gameplay Utility:** Slippery obsidian stone makes running difficult. Fast sprints result in sliding slips. Firing an *Agneyastra* arrow at basalt nodes temporarily heats the stone, increasing grip for `10 seconds`.
