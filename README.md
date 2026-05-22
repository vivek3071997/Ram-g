# Ram-G: Grounded 21st-Century Epic Action-Adventure

[![License: MIT](https://img.shields.io/badge/License-MIT-yellow.svg)](LICENSE)
[![Unreal Engine](https://img.shields.io/badge/Unreal%20Engine-5.4-blue.svg)](https://www.unrealengine.com)

**Ram-G** is a grounded, scientific 21st-century action-adventure retelling of the traditional Sanskrit epic **Ramayana**. 

Unlike conventional high-fantasy representations, this game establishes realistic, physiological boundaries for player capabilities, physical combat, and celestial forces. Divine beings, avatars, and monsters operate under strict thermodynamic, biomechanical, and classical physical rules.

---

## 🚀 Technical Highlights & OOP Architecture

The core gameplay code is written in clean, production-grade **Unreal Engine 5.4 C++** and is structured to enforce strong Object-Oriented Programming (OOP) paradigms:

- **Biomechanical Physiological Pools**: Tracks heart rate, cardiovascular output, lactic acid buildup, reaction delay (neurological latency), and ATP replenishment rates dynamically inside C++.
- **Physical Weapon & Ranged Hierarchy (`ARamGWeapon`, `ARamGBow`, `ARamGMeleeWeapon`)**: Tiers of ranged longbows (Kodanda, Pinaka) with accurate arrow trajectory drops, and heavy melee weapons (Chandrahasa, Kaumodaki mace, Parashu axe) with custom block-bypassing and ground slam sweeping physics.
- **Elemental Astra Component (`URamGAstraComponent`)**: A focus-channeling elemental logic system that processes natural element counters (e.g., Varunastra water purges Agneyastra fire fields, Vayavyastra cyclones disperse toxic vapors).
- **Target Lock & Marma Precision System (`URamGCombatComponent`)**: Timed parry window parameters, physical posture breaks, and custom hit calculation multipliers on vital *Marma* targets (head, neck, heart nodes).

---

## 🎮 Mission 0: Hanuman's Solar Leap (Prologue)

The Prologue mission, **Hanuman's Solar Leap**, serves as a playable tutorial in C++ introducing the core physics, movement, and combat systems of the game.

### Playable Stages:
1. **Tutorial**: Learn basic orchards movement, Vayu's double jump vertical launches, and tail grappling swings.
2. **Orchard Chase**: Search for high-speed, ticklish forest sprites (**Tyakshas**), stagger them using non-lethal strikes to drop 5 sacred fruits into your Mango Basket.
3. **Thermal Ascent**: Redirect Vayu’s wind updrafts to glide upwards, jumping across solid cloud platforms that vaporize and dissolve after 3 seconds.
4. **Sun Pursuit**: An agile high-speed cloud platform runner chasing the rising sun.
5. **Airavat Battle**: Grapple onto the ivory tusks of the colossal elephant Airavat, climbing behind his ears to tickle him to sleep, releasing the Golden Mango Key.
6. **Indra Sky Battle**: Survive Lord Indra's chariot lightning rings and spear barrages in the sky storm fields.
7. **The Vajra Nerf**: endure the Vajra strike. Hanuman’s health and focus drain, and the Sages apply the spiritual seal of forgetfulness, locking double-jump, grapple, and reducing movement speeds.
8. **Rama Reveal**: The camera transitions over the Sarayu river and Ayodhya palace, entering the chambers of the newborn Prince Rama.

---

## 🛠️ Project Setup & Compilation

### Requirements:
- **Unreal Engine 5.4**
- **Visual Studio 2022** (with Game Development C++ workloads)
- **Git**

### Installation:
1. Clone the repository to your local computer:
   ```bash
   git clone https://github.com/vivek3071997/RAM-g.git
   ```
2. Right-click **`RamG.uproject`** and select **Generate Visual Studio Project Files**.
3. Open **`RamG.sln`** in Visual Studio.
4. Set your build configuration to **Development Editor** (Win64) and compile.
5. Launch the editor to start designing your custom Blueprints and HUD.

---

## 🧪 Testing and Diagnostics

The codebase features a built-in automated gameplay test suite to ensure stability across the state machine. To execute the tests:

1. Open your test arena map in the editor.
2. Ensure the **`AMission0GameMode`** is assigned in your World Settings.
3. In the console or via Blueprints, call:
   ```cpp
   AMission0GameMode::RunMissionDiagnostic();
   ```
4. Verify the output logs in your Output Log window to confirm that double-jump boosts, grapple spring constants, fruit pickup indices, and the Vajra nerf speed-lock system pass all baseline diagnostic criteria.

---

## 📜 Contributing & License
- See [CONTRIBUTING.md](CONTRIBUTING.md) for style conventions and Git contribution guidelines.
- Distributed under the [MIT License](LICENSE).
