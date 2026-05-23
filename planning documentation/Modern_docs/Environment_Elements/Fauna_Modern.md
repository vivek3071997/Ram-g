# Grounded Fauna: Wildlife, Avians, & Insects

*   **Asset Category:** Interactive Biological World Entities
*   **GDD Integration:** Guides AI behavioral models, sound triggers, and visual shaders for all animals in-game.

---

## 1. Terrestrial Wildlife (Fauna)

All animals are purely biological, conforming to realistic skeletal mass, muscles, and real-world behavior, styled with premium visual contrast.

### A. Primeval Forest Elephants (Grounded Giants)
*   **Biomechanical Specs:** Mass: `6,500 kg` | Bounding Box: `FVector(5.2, 2.5, 3.4)`.
*   **PBR Shader Settings:** High-roughness wrinkled hide normal maps, holding mud/dirt layers.
*   **Interactive Systems:** Radial foot-stomp shockwave (`3m` radius). Stomping on soil causes screen shake and knocks down minor units through physical impact vectors.
*   **AI State Machine:** Peaceful/Patrol $\rightarrow$ Threat Detected $\rightarrow$ Heavy Charge (Straight vectors at `20 km/h`).

### B. Sita's Golden Fawn (Bioluminescent Decoy)
*   **Biomechanical Specs:** Mass: `45 kg` | Rare biological deer with localized genetic bioluminescence.
*   **PBR Shader Settings:**
    *   *Fur Shader:* Soft, golden-yellow PBR fur with sub-dermal glowing capillary veins.
    *   *Emissive Glow:* `15.0 cd/m²` (Warm yellow point-light source illuminating nearby leaves).
*   **Gameplay Utility:** Active decoy. Its bioluminescence acts as a physical beacon, drawing Sita away from the cottage and into Maricha's optical trap zone.

---

## 2. High-Velocity Avians (Birds)

### A. Jatayu's Vulture Flock
*   **Biomechanical Specs:** Mass: `12 kg` (Rest state) | Wingspan: `3.0m` (Standard flock units).
*   **Flight Physics:** Complies with aerodynamic lift equations: $L = \frac{1}{2} \rho v^2 C_L A$.
*   **AI System:** Circles thermal updraft columns to track long-range coordinates. Alerts ground players of approaching Asuric scouting vehicles.

### B. Garuda's Poison-Purging Eagles
*   **Biomechanical Specs:** Peak biological eagles with highly acidic saliva chemistry.
*   **Gameplay Utility:** Summons that swoop down to inject neutralizing enzymes into players infected by Indrajit's poison arrow traps, instantly curing the bleed/poison status.

---

## 3. Micro-Swarm Grids (Insects)

### A. Bioluminescent Fireflies (Navigation Guides)
*   **Visual System:** Small, glowing GPU particle emitters.
*   **Gameplay Utility:** Naturally gather around safe forest paths at night. Following the fireflies keeps the player on secure pathways, avoiding dark swamp traps.

### B. Asuric Locust Swarms (Target Occlusion)
*   **Physics System:** Fluid-dynamic vector grids. Locust swarms move as a cohesive, target-occluding volume.
*   **Gameplay Utility:** Swarms block the player's targeting HUD, preventing lock-ons. Players must fire a pneumatic wind-shear arrow (*Vayavyastra*) to disperse the swarm instantly.
