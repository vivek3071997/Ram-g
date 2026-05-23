# Mission 0: Hanuman's Solar Leap - Technical Storyboard (v1)

*   **Document Reference:** `Modern_sketch/Missions/Mission0_Hanuman_Leap/v1_Mission0_Hanuman_Leap.md`
*   **Version:** v1 (Prologue Design - Kid Hanuman's Solar Leap Storyboard)
*   **Aesthetic Style:** Monochromatic line-art blueprint showing multi-frame progression.
*   **Embedded Storyboard:**
    ![Hanuman Solar Leap Storyboard](v1_mission0_hanuman_leap.png)

---

## 1. Storyboard Frame-by-Frame Breakdown

This storyboard details the physical flow, visual setups, active player mechanics, and biomechanical parameters of **Mission 0: Hanuman's Solar Leap (Prologue)**, completely aligned with the C++ level sequence and the procedural character mechanics.

### Frame 1: Orchard Sprint & Imp Tickling (High-Agility Athletics)
*   **Visual Scene Description:** A dense forest floor in the Western Ghats (Brahmagiri Valley). In the background stand the symmetrical sandstone walls and tall marble pillars of the Anjani Palace compound. Golden sunbeams filter through gnarled nyagrodha banyan branches. Fleeing Tyaksha imps leap over sandstone benches.
*   **Character Action & Clothing:** Kid Hanuman is depicted as a powerful athletic youth (2.10m tall at baseline, bare powerhouse shoulders). He is wearing a dark charcoal crew-neck t-shirt and loose olive/khaki tactical cargo shorts ([v1_Hanuman.md](../../Characters/Hanuman/v1_Hanuman.md)). He is sprinting at a rapid `700 units/sec` pace, launching a high-speed fists attack that playfully tickles and knocks back a fleeing Tyaksha imp.
*   **Active Game Mechanic:** The player navigates the orchards using keyboard/mouse or left thumbstick. Pressing the attack button executes **PerformKidFistsAttack** (rapid, non-lethal strikes), dealing `15.f` damage and `45.f` posture stagger to clear woodland imps.
*   **Code Connection:** Maps to `EMission0State::OrchardChase` state and `AHanumanCharacter::PerformKidFistsAttack()` in `HanumanCharacter.cpp`.

### Frame 2: Wind-Column Launch (Vayu's Updraft Ascent)
*   **Visual Scene Description:** High-altitude sandstone cliffs of Mount Sumeru rising vertically. Streamlines of soft white air (Vayu's updrafts) rise up from the valley floor.
*   **Character Action:** Hanuman launches from a high ridge, entering vertical ascent at high speed (`Z velocity 650.0f` + launch boost). His body posture is aerodynamic, streamlined to slice through high-velocity air drafts. Concentric wind ripples warp the air around his feet.
*   **Active Game Mechanic:** Moving into `AVayuWindUpdraft` physics-force fields launches Hanuman upwards. The player holds down the spacebar to trigger **StartAerodynamicGlide** (Laghima levitation, 90% weight reduction, gravity scale lowered to `0.12f`), catching thermal columns to navigate high-altitude gaps.
*   **Code Connection:** Maps to `EMission0State::ThermalAscent` state and `AVayuWindUpdraft` force fields.

### Frame 3: Stratospheric Cloud Run (Solar Pursuit Platforming)
*   **Visual Scene Description:** Deep upper stratosphere, curved dark horizon, storm clouds floating below. Blinding glowing rays from the Solar Fusion Reactor (the Sun) illuminate the sky. Stepped vapor cloud platforms stretch towards the solar reactor.
*   **Character Action:** Hanuman is shown sprinting across stepped vapor cloud platforms, shielding his eyes from the solar core. Vignette vector lines squeeze around the borders of the frame, and red-shifted visual contrast highlights his heavy breathing (hypoxic strain).
*   **Active Game Mechanic:** High-speed platforming runner. Exceeding the `3,000 units` altitude threshold triggers hypoxic Vision Degradation. Visual contrast spikes to `1.85` and vignette squeezes to `0.85` representing blackout risk while stamina is siphoned at `15 J/s`.
*   **Code Connection:** Maps to `EMission0State::SunPursuit` state and the `APostProcessVolume` overrides.

### Frame 4: Celestial Encounter & Vajra Crash (The Power-Seal)
*   **Visual Scene Description:** High stratospheric gates locked in a crackling yellow-blue electrostatic grid. The colossal, four-tusked white elephant Airavat blocking the path, and Lord Indra commanding lightning spears from a hover platform.
*   **Character Action:** Hanuman is shown swinging from Airavat's massive ivory tusks via a glowing neon-blue grapple thread originating from his tail component (`TailMesh`). An inset shows a blinding lightning strike (the Vajra) hitting Hanuman's jaw, fracturing his cheek line. He is depicted falling vertically back toward the distant valley, with a expanding circular lock overlaying his body.
*   **Active Game Mechanic:** The player triggers `StartGrapple()` (`1,500 units` range) onto Airavat's tusk sockets (`OBJ_AIRAVAT_TUSKS`) to swing and recover the **Golden Mango Key**. Snatching it triggers the scripted Vajra Thunderbolt: Hanuman's stamina/focus are depleted to `0.f`, lactic acid spikes to `100.f`, double-jump and grapple are locked, and walk speed is throttled to `250.f`.
*   **Code Connection:** Maps to `EMission0State::AiravatBattle`, `EMission0State::IndraBattle`, and the scripted `TriggerVajraNerfSequence()` siphoning locks.
