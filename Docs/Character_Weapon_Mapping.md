# GDD Character-Weapon Mapping

This document maps all primary weapons and divine astras to their respective wielders, outlining their GDD mechanics in detail: **Wielding Stances**, **Context of Use**, **Post-Impact Effects**, and **Spiritual/Physical Cost of Wielding**.

---

## Master Weapon-Wielder Mapping Table

| Wielder | Weapon/Astra | Wielding Stance | Context of Use (Intention) | Post-Impact Effects | Cost of Wielding |
| :--- | :--- | :--- | :--- | :--- | :--- |
| **Lord Rama** | **Kodanda Bow** | Symmetrical archery stance, holding with left hand, drawing string with right hand. | Primary weapon. Used for exploratory combat, group sweeps, and boss fights. | Pierces targets, causing glowing golden *Prana* sparks. Solar shots inflict a burning aura. | 0 Stamina / 0 Prana for normal shots. Heavy charge shots drain 20% Stamina. |
| | **Brahmastra** | Kneeling prayer stance, channeling energy with eyes closed, firing a blinding golden projectile. | Act 10 Final finisher to dry Ravana's navel nectar and destroy his core. | White screen flash, giant golden dome shockwave, complete target disintegration. | 100% Prana Gauge. 5.0s vulnerable channeling window. Stamina drained to 0. |
| | **Agneyastra** | Wide combat archery stance, drawing string filled with active fire embers. | Clears large groups of minor Asuras and melts ice armor shields. | Explodes in a 6m circle, setting the terrain on fire and applying "Burn" debuff. | 25% Prana Gauge. 1.0s charge time. |
| | **Varunastra** | Symmetrical stance, drawing liquid-water arrow shaft with glowing blue mist. | Extinguishes fire hazards, breaks fire shields, and slows boss movement. | local rainstorm zone for 5s, healing companions and slowing enemies in area. | 25% Prana Gauge. 1.0s charge time. |
| | **Vayavyastra** | High-draw stance, bow pointed upward, wind swirling around feet. | Disperses heavy smoke screens, toxic gases, and unmasks invisible bosses. | 8m wind column tornado, launching minor enemies and unmasking invisible targets. | 25% Prana Gauge. 1.0s charge time. |
| | **Garudastra** | Dynamic drawing stance, glowing spectral wings extending along the bow. | Purges *Nagapasha* binding snares and cleanses poison fields. | Giant golden eagle sweep, instantly vaporizing snakes and green poison puddles. | 50% Prana Gauge. 1.5s charge time. |
| **Sita** | **Bhumija Shield** (Earth Ward) | Kneeling prayer stance, touching the ground with palms, eyes closed. | Active support ability. Casts defensive barriers when Rama or Lakshmana is low on HP. | Glowing, stone-reinforced tree root walls rise from the earth, blocking projectiles. | 40% Spiritual Meter. 2.0s casting time. Wielder is immobile. |
| **Lakshmana** | **Twin Blades** | Reverse-grip dual-wielding, body hunched low for high-speed forward dashes. | Close-quarters melee. Drawn when enemies breach archery range. | Rapid, slicing trails of green light. Inflicts high stagger on minor enemies. | 15 Stamina per dual-slash combo. |
| | **Saumitra Bow** | Lightweight rapid recurve stance, drawing three arrows simultaneously. | Fast group clears and keeping enemies at bay. | Fires 3 separate arrows in a narrow cone, piercing thin targets. | 10 Stamina per triple shot. |
| **Hanuman** | **Kaumodaki Gada** | Two-handed heavy grip, shoulder-resting stance, swinging in wide, flat sweeps. | Primary melee weapon. Used for high-stagger swings and shield breaking. | Visual earth fractures, screen shake, large radial golden energy shockwaves. | 35 Stamina per normal swing. High recovery delay (0.8s). |
| **Sage Parashurama** | **Parashu Axe** | One-handed loose grip, sweeping in wide vertical chops and circular swings. | High-damage close-quarters testing duel. | Molten orange heat cracks the ground, spawning lines of volcanic ash and fissures. | 50 physical stamina. Heavy sweeps leave a 1.2s opening window. |
| **Emperor Ravana** | **Chandrahasa** | Two-handed heavy grip, reverse-sweep ready stance, blade glowing silver. | Primary melee weapon. Wielded to block-break the player and deal colossal sweeps. | Crescent-shaped energy slashes that bypass physical blocks; obsidian impact shards. | 40 boss stamina. High physical swing delay. |
| | **Trishula** | High overhead javelin grip, red static electricity crackling on the three prongs. | Ranged pressure. Thrown to force the player into rolling/dodging. | Red lightning spear splits into three separate homing bolts in mid-air. | 30 boss stamina. Leaves him open to counter-archery for 1.5s. |
| **General Indrajit** | **Nagapasha** | levitating spellcaster stance, hands forming complex circular mudras. | High-stakes crowd control to trap and slow down the player. | Traps the player model in writhe cobras, dealing poison damage over time. | 100% Sorcery Gauge. 3.0s vulnerable chanting window. |
| | **Shakti Lance** | Two-handed overhead throwing grip, lance glowing with toxic violet light. | Act 9 cinematic phase finisher. Wielded to stun and near-fatally wound Lakshmana. | Sonic boom rings, purple static trails, leaves a glowing violet crater on impact. | 80% Sorcery Gauge. 2.0s charging window. |

---

## Wielding Mechanics Details

### 1. The Bowmanship Loop (Rama & Lakshmana)
*   **The Pull Back:** Pressing the attack button enters the drawing phase. The camera zooms in slightly, and a dynamic tension meter appears.
*   **Aura Channeling:** Holding the button draws *Prana* from the environment. The player can hear the character's breathing slow down.
*   **The Release:** Releasing the button triggers the projectile launch. If timed perfectly at full draw, it deals double critical damage (Perfect Release mechanic).

### 2. Heavy Mace swing Mechanics (Hanuman)
*   **Wind-Up Phase:** Hanuman raises the Gada behind his back. The player is vulnerable to fast counter-attacks but gains "Hyper-Armor" (cannot be staggered).
*   **Ground Impact:** Slamming the mace triggers a localized controller rumble and screen shake. Cracks appear in the floor mesh, which fade after 10 seconds.
*   **Recovery Phase:** Hanuman's heavy weight causes him to slide slightly forward. The player must dodge-cancel to avoid the high recovery recovery frames.

### 3. Dual-Blade fast Combos (Lakshmana)
*   **Ready Stance:** Lakshmana stands on his toes, holding the daggers in reverse-grips.
*   **The Slashing Flurry:** Tapping the attack button triggers a chain of rapid cuts. The trail VFX leaves neon-green ribbons in the air.
*   **The Sheath Transition:** Combat automatically sweeps back to his bow stance once the enemy is pushed away.
