# Environment Elements: Fruits & Food Database

*   **Database Directory:** `Docs/Environment_Elements/Flora/`
*   **Engine Blueprint Class:** `A_ItemPickup` / `StaticMesh` (Interactive Inventory Item)

---

## 1. Modular Entity Specifications

### A. Sumeru Golden Mangoes (Amra)
*   **Mythological Role:** Sun-like golden mangoes from Sumeru's high orchards. Triggers kid Hanuman's solar leap.
*   **Physical & Interactive Specifications:**
    *   *Visuals:* Bright yellow-orange skin with a soft golden outer glow particle (`Emissive intensity: 2.5`).
    *   *Stamina Rejuvenation:* Instantly replenishes `100%` Stamina reserves and boosts sprint speed by `20%` for 10 seconds.
    *   *Inventory Type:* Collectable Quest Item / Quick Slot Consumable.

### B. Holy Wild Berries (Badari-Phala)
*   **Mythological Role:** Wild berries harvested and lovingly tasted by the elder ascetic Sabari, proving their absolute sweetness before feeding them to Lord Rama.
*   **Physical & Interactive Specifications:**
    *   *Visuals:* Round, deep red forest berries found in simple wicker baskets near Pampa Lake.
    *   *Purifying Health Restore:* Cleanses all poison and toxic debuffs. Restores `40%` of missing Health Points.
    *   *Ritual Offering:* Gifting gathered berries at sages' shrines unlocks rare story logs and companion blessings.

### C. Sacred Soma-Rasa Nectar
*   **Mythological Role:** A golden, sparkling herbal elixir crafted in sage hermitages using mountain roots and forest flowers.
*   **Physical & Interactive Specifications:**
    *   *Visuals:* Glowing gold liquid inside a small clay vial (*Kupika*).
    *   *Spiritual Prana Boost:* Multiplies player *Prana* generation rates by `2.0x` and reduces the channel time of celestial *Astras* by `50%` for a duration of 30 seconds.

### D. Palace Royal Feasts (Maha Raj-Bhog)
*   **Mythological Role:** Traditional multi-course palace banquets served in Ayodhya and Mithila, celebrating victories and coronations.
*   **Physical & Interactive Specifications:**
    *   *Visuals:* Heavy gold and silver plates loaded with copper cups of saffron milk, baked flatbreads (*Roti*), and sweet rice puddings (*Payasam*).
    *   *Base Stat Upgrade:* Interacting with feast tables in city hubs grants a permanent `+5%` Health and Stamina cap, limited to one upgrade per story act.

---

## 2. GDD Integration & Relative Mapping

The food and crop items are connected directly to their acts, characters, and environments:

| Entity Name | Primary Location Link | Scene Placement | Connected Characters |
| :--- | :--- | :--- | :--- |
| **Golden Mango** | [Kishkindha (LOC_KISHKINDHA)](../../Locations/Kishkindha.md) | [Sumeru Stratosphere (SCENE_SUMERU_STRATOSPHERE)](../../Scenes/Scene_0_Sumeru_Stratosphere.md) | [Hanuman](../../Characters/Hanuman.md) |
| **Wild Berries** | [Kishkindha (LOC_KISHKINDHA)](../../Locations/Kishkindha.md) | [Dandaka Wilds (SCENE_DANDAKA_WILDS)](../../Scenes/Scene_4_Dandaka_Wilds.md) | [Sabari](../../Characters/Sabari.md) / [Lord Rama](../../Characters/Lord_Rama.md) |
| **Soma-Rasa Nectar** | [Dandakaranya (LOC_DANDAKARANYA_PANCHAVATI)](../../Locations/Dandakaranya_Panchavati.md) | [Siddhashrama Altar (SCENE_SIDDHASHRAMA_ALTAR)](../../Scenes/Scene_1_Siddhashrama_Altar.md) | [Sage Vishwamitra](../../Characters/Sage_Vishwamitra.md) |
| **Palace Feast** | [Ayodhya (LOC_AYODHYA)](../../Locations/Ayodhya.md) | [Pinaka Sanctuary (SCENE_PINAKA_SANCTUARY)](../../Scenes/Scene_2_Pinaka_Sanctuary.md) | [King Janaka](../../Characters/King_Janaka.md) / [King Dasharatha](../../Characters/King_Dasharatha.md) |

---

## 3. Acoustic & Audio Profile

*   **Mango & Berry Harvest SFX:**
    *   *Foley Crunch:* Soft rustling basket noise combined with a light celestial chime (`Pickup_Fruit.wav`).
*   **Soma-Rasa Consume SFX:**
    *   *Liquid Gulp:* Liquid drinking sound loop followed by a deep resonant wind chime, indicating active magic buffs.
*   **Palace Feast SFX:**
    *   *Ambient Feast:* Clinking of metal utensils, laughter hum, and soft royal *Veena* chords playing in the background.
