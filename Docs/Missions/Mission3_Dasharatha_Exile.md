# Mission 3: The King's Echo Chamber

*   **Playable Protagonist:** King Dasharatha (Playable Palace State)
*   **Reveals & Transitions to:** Lakshmana (Playable Sworn Guard State)
*   **Theme & Focus:** Political intrigue, the heavy toll of old sins, parental grief, and a tragic narrative transition through death.

---

## 1. Scene & Environment

*   **Primary Active Scene:** [Scene: Palace Anger (Kopabhawan)](../Scenes/Scene_3_Palace_Anger.md) (`SCENE_PALACE_ANGER`)
*   **Key Environment Elements:** The dark, claustrophobic vaults and corridors of the Ayodhya palace, leading to the disarrayed chambers of Kaikeyi (*Kopabhawan*).
*   **Key Interactive Objects:** [Object: Royal Solar Torch](../Objects/Object_Royal_Solar_Torch.md) (`OBJ_ROYAL_SOLAR_TORCH`), acoustic floor-grates, and the Shabda-Vedhi sound-hunting bow.

---

## 2. Basic Flow of Steps

1.  **Treasury Intrigue (Monster Hunt):** Dasharatha inspects the subterranean royal vault. He must clear *Chhaya-Shatrus* (guilt phantoms that steal gold and block paths) using royal solar torches.
2.  **Tracking the Whispers (Puzzle):** Navigate the palace corridors to track the shadow of Manthara, aligning wall-tapestry listening scopes to intercept her dark whispers to Kaikeyi.
3.  **The Chamber of Anger (Dialogue Boss 1 - Queen Kaikeyi):** Enter the Kopabhawan. The player must engage in a high-stakes verbal duel with Kaikeyi, maintaining his composure as his heart meter (stamina) takes severe hits from her stubborn demands.
4.  **Flashback: The Blind Hunt (Boss 2 - The Shadow of the Elephant):** Relive the fateful night Dasharatha shot Shravana Kumar. The player must navigate a pitch-black forest, relying purely on audio cues (3D sound) to shoot an invisible target near the riverbank.
5.  **The Transition Nerf (Shravana Kumar Curse):** Return to the present. As Rama departs, the curse of Shravana's blind parents takes full effect: Dasharatha's heart meter drains to zero, triggering a fatal cardiac collapse.
6.  **Lakshmana's Swearing-In:** The camera pulls away from Dasharatha's lifeless body, gliding through the palace gardens to Lakshmana's training courtyard. Enraged and grieving, Lakshmana swears the **Vow of No-Sleep (Nidra-Khanda)** to protect Rama, imposing a unique stamina-lock mechanic on himself.

---

## 3. Fun Monster Hunting

### Clearing the Chhaya-Shatrus (Guilt Phantoms)
*   **Mechanic:** Dark, smoky phantoms shaped like historical adversaries haunt the royal vault. They cannot be harmed by conventional swords; they feed on the King's royal authority and authority-bar.
*   **Combat Flow:** Dasharatha must use the **Royal Solar Torch** (Surya-Mishal) to cast bright light cones. Directing the light at the phantoms burns them, while using the **Royal Scepter** creates a shockwave of authority that vaporizes them when staggered.
*   **Enemy Type:** *Chhaya-Shatrus* — Wraith-like shadows that absorb physical steel, fleeing only when confronted by raw light and solar authority.

---

## 4. Fun Puzzle Solving

### Intercepting Palace Whispers (Manthara's Shadow)
*   **Context:** Manthara is poisoning Kaikeyi's mind in the palace towers. Dasharatha must uncover their plot before Kaikeyi summons him.
*   **Puzzle Mechanics:**
    *   The player must tail Manthara's shadow through the palace corridors without triggering the guard alerts.
    *   *Listening Columns:* Align rotating bronze drainage tubes and stone wall-frescoes that serve as natural acoustic amplifiers.
    *   When the tubes are aligned properly, the player hears fragments of dialogue. The player must rearrange the words in a puzzle interface to decode Kaikeyi's plan (the two boons: Rama's exile and Bharata's coronation).

---

## 5. Boss Encounters

### Boss 1: Queen Kaikeyi (The Dialogue Boss)
*   **Combat Arena:** The dark, broken Kopabhawan chamber.
*   **Boss Mechanics:**
    *   Kaikeyi attacks using **Vows of the Deva-Asura War** (sacred, unbreakable promises).
    *   Instead of a health bar, Dasharatha has a **Heart Integrity Meter**.
    *   Kaikeyi throws verbal accusations and demands. The player must choose diplomatic, emotionally grounded, or authoritative responses. Choosing poorly drains the Heart Meter.
    *   *The Ultimate Attack:* Kaikeyi invokes the two ancient boons. This attack cannot be dodged or countered; it instantly drains the Heart Meter to 10%, locking the King in a defeated, paralyzed state.

### Boss 2: The Sound of the Forest (Shravana Kumar Flashback)
*   **Combat Arena:** The dark, stormy banks of the Sarayu River.
*   **Boss Mechanics:**
    *   The screen is completely black, except for occasional lightning flashes that briefly reveal the environment.
    *   The player must rely on a **Shabda-Vedhi (Sound-Piercing)** targeting reticle that turns green when aiming towards sound frequencies.
    *   *The Hunt:* The player hears water bubbling, leaves rustling, and a sound resembling a wild elephant drinking.
    *   *The Shot:* The player fires. A cinematic triggers showing that instead of an elephant, Dasharatha's arrow has pierced the chest of young Shravana Kumar, who was filling his pitcher for his blind parents.

---

## 6. The Character Nerf & Transition

### The Shravana Kumar Curse (Death Lock)
*   **The Curse:** As Shravana Kumar dies, his blind parents curse Dasharatha: *“You shall perish in the exact same manner as us—separated from your beloved eldest son, dying of a broken heart in absolute darkness.”*
*   **The Nerf (Fatal Cardiac Collapse):**
    *   As the chariot carrying Rama, Sita, and Lakshmana crosses the horizon, Dasharatha's Heart Integrity Meter drops to zero.
    *   All screen colors fade to grayscale. The player experiences heavy heartbeat audio throbbing, and Dasharatha collapses to the floor, whispering *"Haa Rama! Haa Rama!"*
*   **The Swapped Character (Lakshmana):**
    *   Control immediately shifts to Lakshmana in his training arena.
    *   Grieving his father's death and furious at the injustice, Lakshmana takes the **Vow of No-Sleep (Nidra-Khanda)**:
        > *For 14 years, Lakshmana will bypass all sleep and rest to guard his brother Rama and sister Sita. Sleep itself is personified as Goddess Nidra, who transfers Lakshmana's fatigue to his sleeping wife Urmila in Ayodhya.*
    *   *Mechanical Vow Impact (The Stamina Nerf):* Lakshmana **cannot recover stamina or health by resting or using camps**. He must actively defeat Asuric foes or perform perfect parries (Guard Resonance) to restore his stamina and health in the field.

---

## 7. Dialogue & Narrative Scripts

### Dialogue Segment: The Broken Vow
*   **Location:** The Palace of Ayodhya.
*   **Characters:** King Dasharatha, Queen Kaikeyi, Sumantra (Charioteer).

```markdown
King Dasharatha: (Clutching his chest, voice trembling) "Kaikeyi... ask for my eyes, ask for my crown, ask for my life! But do not tear my Rama away from me. The kingdom will burn in the fire of this sin!"

Queen Kaikeyi: (Cold, unyielding) "You are the descendant of Raghu, O King! A lineage that has never broken a promise. Will you be the first to taint your ancestors' names to satisfy a father's weakness?"

Sumantra: (Entering, bowing) "Your Majesty, the chariot is ready at the palace gates. Prince Rama awaits your final blessing before they cross into the dark forests."

King Dasharatha: (Screaming, reaching out to the sky) "I am blind! The darkness of the Sarayu has caught up with me! Shravana... forgive me... Rama! Rama!" (He collapses, his hand falling limp).
```

---

## 8. Weapons & Equipment Used

*   **Royal Solar Torch (Surya-Mishal):** Weapon/utility used to dispel shadow phantoms and illuminate secret passages ([Object: Royal Solar Torch](../Objects/Object_Royal_Solar_Torch.md) / `OBJ_ROYAL_SOLAR_TORCH`).
*   **Shabda-Vedhi Bow (Blind Bow):** A unique longbow used in the flashback sequence that requires audio alignment rather than visual targeting.
*   **Royal Scepter (Danda):** Used to emit waves of royal authority to push back major shadow threats.
