# S08 — Gameplay Systems & Mechanics | Mission 0 Development Tasks

> **Mission:** Mission 0 — Hanuman's Solar Leap
> **Section:** Movement, Combat, Boss Systems, Puzzles, Progression & Save

| Metric | Value |
|--------|-------|
| Total Tasks | 42 |
| Total Subtasks | 87 |
| 🤖 AI-Assisted Tasks | 20 (48%) |
| 🤝 AI+Human Tasks | 14 (33%) |
| 👤 Human-Only Tasks | 8 (19%) |
| Teams Involved | ENG, DESIGN, QA |

---

## Tag Legend
- `🤖 AI` — Fully achievable by AI  `🤝 AI+H` — AI assists, human refines  `👤 Human` — Human required
- `[ENG]` `[DESIGN]` `[QA]` — Team tags

---

## 8.1 Movement & Physics (12 Mechanics)

### 8.1.1 Base Locomotion State Machine

- [ ] Design spec — Locomotion state diagram (idle → walk → run → sprint transitions) `🤖 AI [Claude, ChatGPT]` `[DESIGN]`
  - [ ] Define transition conditions (speed thresholds, input states) `👤 Human` `[DESIGN]`
  - [ ] Define blend times between states `👤 Human` `[DESIGN]`
- [ ] Implement — Character movement component with locomotion states `🤖 AI [GitHub Copilot, Claude]` `[ENG]`
  - [ ] State machine in engine (Blueprint/C++) `🤖 AI [GitHub Copilot]` `[ENG]`
  - [ ] Animation blend tree connected to speed parameter `🤖 AI [GitHub Copilot]` `[ENG]`
- [ ] QA — Test all state transitions at each frame rate target `👤 Human` `[QA]`

### 8.1.2 Jump System (Single + Double, Gravity Curve)

- [ ] Design spec — Jump height, time-to-apex, gravity scale values `🤝 AI+H [Claude + game designer]` `[DESIGN]`
  - [ ] Define single jump: apex height 2.5m, time-to-apex 0.4s `👤 Human` `[DESIGN]`
  - [ ] Define double jump: additional 2m lift, must be airborne `👤 Human` `[DESIGN]`
  - [ ] Define custom gravity curve (slower up, faster down = game-feel) `👤 Human` `[DESIGN]`
- [ ] Implement — Jump with custom gravity curve `🤖 AI [GitHub Copilot, Claude]` `[ENG]`
  - [ ] Separate gravity multipliers for ascent vs. descent phase `🤖 AI [GitHub Copilot]` `[ENG]`
  - [ ] Double-jump unlock gate (must be airborne, cooldown after use) `🤖 AI [GitHub Copilot]` `[ENG]`
- [ ] Tune — Iterative feel testing with level designer `👤 Human` `[DESIGN]`

### 8.1.3 Glide State

- [ ] Design spec — Glide: reduced gravity (0.3×), lateral drift control `🤖 AI [Claude]` `[DESIGN]`
- [ ] Implement — Glide mode entered from jump apex (hold jump input) `🤖 AI [GitHub Copilot]` `[ENG]`
  - [ ] Apply reduced gravity on glide state enter `🤖 AI [GitHub Copilot]` `[ENG]`
  - [ ] Allow lateral input (A/D or LS X-axis) during glide `🤖 AI [GitHub Copilot]` `[ENG]`
  - [ ] Glide exit: release input or land on surface `🤖 AI [GitHub Copilot]` `[ENG]`

### 8.1.4 Tail Grapple System

- [ ] Design spec — Grapple range, attach points, swing arc, release rules `🤝 AI+H [Claude + designer]` `[DESIGN]`
  - [ ] Range: 8m. Valid anchor types: vines, ledge rings, Airavat tusks `👤 Human` `[DESIGN]`
  - [ ] Swing arc: pendulum physics (momentum builds with input) `👤 Human` `[DESIGN]`
- [ ] Implement — Aim phase (aim reticle appears on R-trigger hold) `🤖 AI [GitHub Copilot]` `[ENG]`
  - [ ] Spherecast from Hanuman forward → detect grapple anchor tags `🤖 AI [GitHub Copilot]` `[ENG]`
  - [ ] Reticle snaps to nearest valid anchor `🤖 AI [GitHub Copilot]` `[ENG]`
- [ ] Implement — Launch phase (tail extends as projectile to anchor) `🤖 AI [GitHub Copilot]` `[ENG]`
- [ ] Implement — Swing phase (pendulum physics, momentum accumulation) `👤 Human` `[ENG]`
  - [ ] Spring joint or cable constraint between player and anchor `👤 Human` `[ENG]`
  - [ ] Lateral input adds swing momentum `👤 Human` `[ENG]`
- [ ] Implement — Release (let-go triggers projectile arc) `🤖 AI [GitHub Copilot]` `[ENG]`
- [ ] QA — Test grapple on all anchor types, edge cases (wall grapple, grapple while falling) `👤 Human` `[QA]`

### 8.1.5 Wall Run (Horizontal + Vertical)

- [ ] Design spec — Wall-run angle tolerance, speed, time limit `🤖 AI [Claude]` `[DESIGN]`
- [ ] Implement — Vertical wall run (sprint toward wall → auto-attach → run up) `🤖 AI [GitHub Copilot]` `[ENG]`
- [ ] Implement — Horizontal wall run (jump onto wall side → hold direction → run along) `🤖 AI [GitHub Copilot]` `[ENG]`
- [ ] Implement — Wall jump (during wall run: jump input → kick off wall, change direction) `🤖 AI [GitHub Copilot]` `[ENG]`

### 8.1.6 Ledge Grab + Pull-Up

- [ ] Implement — Ledge detection (top edge of platforms and cliffs) `🤖 AI [GitHub Copilot]` `[ENG]`
  - [ ] Overlap check at chest height + line trace to surface top `🤖 AI [GitHub Copilot]` `[ENG]`
- [ ] Implement — Ledge hang state (hold ledge, strafe L/R, or drop) `🤖 AI [GitHub Copilot]` `[ENG]`
- [ ] Implement — Pull-up slow + fast variant (driven by hold vs tap) `🤖 AI [GitHub Copilot]` `[ENG]`

### 8.1.7 Vine Swing Physics

- [ ] Implement — Vine spline physics chain (pendulum mass-spring) `👤 Human` `[ENG]`
  - [ ] Spline-based vine deformation driven by character mass `👤 Human` `[ENG]`
  - [ ] Momentum accumulation on lateral input during swing `👤 Human` `[ENG]`
  - [ ] Release trajectory calculated from swing velocity at release `👤 Human` `[ENG]`

### 8.1.8 Thermal Updraft Column Interaction

- [ ] Implement — Zone trigger volume for each updraft column `🤖 AI [GitHub Copilot]` `[ENG]`
- [ ] Implement — On enter: override character Z velocity with upward force `🤖 AI [GitHub Copilot]` `[ENG]`
- [ ] Implement — On exit: velocity handed back to character controller normally `🤖 AI [GitHub Copilot]` `[ENG]`
- [ ] Implement — Updraft only active after corresponding windwheel is aligned `🤖 AI [GitHub Copilot]` `[ENG]`

### 8.1.9 Cloud Platform Timer System

- [ ] Implement — Per-platform timer (DeltaTime-based, 3.0 seconds) `🤖 AI [GitHub Copilot]` `[ENG]`
- [ ] Implement — Color warning progression (white → yellow → red, driven by timer %) `🤖 AI [GitHub Copilot]` `[ENG]`
- [ ] Implement — Dissolve trigger at 0 seconds (platform disabled + VFX) `🤖 AI [GitHub Copilot]` `[ENG]`
- [ ] Implement — Platform reset after 10 seconds if player not nearby `🤖 AI [GitHub Copilot]` `[ENG]`

### 8.1.10 Wind Vector Field Character Interaction

- [ ] Implement — Character receives lateral force from active zone wind volume `🤖 AI [GitHub Copilot, Claude]` `[ENG]`
- [ ] Implement — Wind force scales with zone (15 → 40 → 80 → 120 km/h) `🤖 AI [GitHub Copilot]` `[ENG]`
- [ ] Tune — Ensure Zone 4 storm gusts feel powerful but survivable `👤 Human` `[DESIGN]`

### 8.1.11 Vayu Rescue Safety Net System

- [ ] Implement — Fall detection (player Z < zone fall threshold) `🤖 AI [GitHub Copilot]` `[ENG]`
- [ ] Implement — Rescue cinematic trigger (pause player, play Vayu wind VFX, float back) `🤖 AI [GitHub Copilot]` `[ENG]`
- [ ] Implement — Rescue counter decrement (max 3, check on each rescue) `🤖 AI [GitHub Copilot]` `[ENG]`
- [ ] Implement — Mission fail trigger on 4th fall (rescue counter = 0) `🤖 AI [GitHub Copilot]` `[ENG]`

### 8.1.12 Altitude Tracking Variable

- [ ] Implement — Global altitude variable (player Z position mapped to display units) `🤖 AI [GitHub Copilot]` `[ENG]`
- [ ] Implement — Altitude drives: HUD indicator, audio LPF, lighting blend, zone detection `🤖 AI [GitHub Copilot]` `[ENG]`

---

## 8.2 Combat (6 Mechanics)

### 8.2.1 Light Punch Combo (3-Hit, Timing Windows)

- [ ] Design spec — Combo timing: 0.4s window between hits, 3-hit chain max `🤝 AI+H [Claude + designer]` `[DESIGN]`
- [ ] Implement — 3-hit combo state machine with timing window `🤖 AI [GitHub Copilot]` `[ENG]`
  - [ ] Hit 1: fast jab (0.2s), Hit 2: cross (0.25s), Hit 3: spinning tail-end (0.35s) `👤 Human` `[DESIGN]`
  - [ ] Each hit checks for hit-react trigger on valid targets `🤖 AI [GitHub Copilot]` `[ENG]`

### 8.2.2 Heavy Punch (Charged Input)

- [ ] Design spec — Hold input 0.8s → charge → release = heavy slam `🤖 AI [Claude]` `[DESIGN]`
- [ ] Implement — Charge state with visual indicator (aura pulse) `🤖 AI [GitHub Copilot]` `[ENG]`
- [ ] Implement — Heavy hit: larger hitbox, greater knockback force `🤖 AI [GitHub Copilot]` `[ENG]`

### 8.2.3 Tail Swipe (Directional AOE Sweep)

- [ ] Implement — Directional input + tail swipe button → 180° arc hitbox `🤖 AI [GitHub Copilot]` `[ENG]`
- [ ] Implement — Arc sweep triggers knockback on all enemies in range `🤖 AI [GitHub Copilot]` `[ENG]`

### 8.2.4 Dodge Roll (I-Frames, Stamina Cost)

- [ ] Design spec — Roll distance 2m, i-frame duration 0.3s, stamina cost 15% `🤝 AI+H [Claude + designer]` `[DESIGN]`
- [ ] Implement — Roll: directional input + dodge → play animation + apply invincibility frames `🤖 AI [GitHub Copilot]` `[ENG]`

### 8.2.5 Tickle Tackle (Context-Sensitive, Non-Lethal on Tyakshas)

- [ ] Design spec — Tackle only appears as option when near a Tyaksha (context prompt) `🤝 AI+H [Claude + designer]` `[DESIGN]`
- [ ] Implement — Context action button appears above Tyaksha at close range `🤖 AI [GitHub Copilot]` `[ENG]`
- [ ] Implement — On press: play tackle animation, Tyaksha drops fruit, enters caught state `🤖 AI [GitHub Copilot]` `[ENG]`

### 8.2.6 Enemy Hit-React System

- [ ] Implement — Hit react state machine for enemies (idle → stagger → recover → resume AI) `🤝 AI+H [Claude + programmer]` `[ENG]`
- [ ] Implement — Knockback physics (impulse applied to enemy root on heavy hit) `🤖 AI [GitHub Copilot]` `[ENG]`
- [ ] Implement — Defeat state (health = 0 → defeat animation → disable collider → dissolve) `🤖 AI [GitHub Copilot]` `[ENG]`

---

## 8.3 Boss Systems — Airavat

- [ ] Airavat AI Behavior Tree (charge patterns, attack sequences) `🤝 AI+H [Claude for logic + programmer]` `[ENG]`
  - [ ] State: Patrol → Aggro → Phase 1 Attack Pattern → Phase 2 Attack Pattern `👤 Human` `[DESIGN]`
  - [ ] Phase 1 attacks: Stomp, Charge, Tusk Shake `👤 Human` `[DESIGN]`
  - [ ] Phase 2 attacks: Trunk Sweep, Trunk Lash, Water Blast `👤 Human` `[DESIGN]`
- [ ] Phase 1 — Tusk Climb Mechanic + Stomp Dodge `👤 Human` `[ENG]`
  - [ ] Grapple-on-tusk interaction: player attaches to tusk surface `👤 Human` `[ENG]`
  - [ ] Stomp dodge: radial shockwave zone spawns on stomp, player must dodge `🤖 AI [GitHub Copilot]` `[ENG]`
- [ ] Phase 2 — Trunk Lash Dodge + Ear Tickle Context Action `👤 Human` `[ENG]`
  - [ ] Trunk lash: sweeping hitbox, high speed — requires dodge timing `👤 Human` `[ENG]`
  - [ ] Ear tickle: context action appears near ear after trunk dodged → triggers sleep `🤖 AI [GitHub Copilot]` `[ENG]`
- [ ] Boss Health Bar + Phase Threshold Trigger (50% HP → Phase 2) `🤖 AI [GitHub Copilot]` `[ENG]`
  - [ ] HP threshold check triggers phase transition cinematic `🤖 AI [GitHub Copilot]` `[ENG]`

---

## 8.4 Boss Systems — Indra

- [ ] Indra AI Bullet-Hell Pattern System (lightning spear + ring wave) `🤝 AI+H [Claude for pattern design + programmer]` `[ENG]`
  - [ ] Define 3 escalating attack patterns (Easy → Medium → Hard ring speed) `👤 Human` `[DESIGN]`
  - [ ] Lightning spear: projectile fired from chariot, player dodges `🤖 AI [GitHub Copilot]` `[ENG]`
  - [ ] Ring wave: expanding floor rings from Vajra Core, player jumps/dodges `🤖 AI [GitHub Copilot]` `[ENG]`
- [ ] Chariot Orbit Logic (smooth ellipse orbit, escalating speed) `🤝 AI+H [Claude for math + programmer]` `[ENG]`
  - [ ] Parametric ellipse path for chariot movement actor `🤖 AI [GitHub Copilot, Claude]` `[ENG]`
  - [ ] Speed increases each time player avoids 5 attacks `👤 Human` `[DESIGN]`
- [ ] Crown Grab Survival Check + Cinematic Trigger `👤 Human` `[ENG]`
  - [ ] Survival timer: player must endure 2 full chariot orbits before crown grab prompt appears `👤 Human` `[DESIGN]`
  - [ ] Crown grab input → play grab animation → lock player → fire cinematic `🤖 AI [GitHub Copilot]` `[ENG]`
- [ ] Boss Arena Boundary — Wind-Wall Bounce-Back System `🤖 AI [GitHub Copilot]` `[ENG]`
  - [ ] Invisible collider ring at arena perimeter `🤖 AI [GitHub Copilot]` `[ENG]`
  - [ ] On collision: apply inward impulse force + brief wind VFX `🤖 AI [GitHub Copilot]` `[ENG]`

---

## 8.5 Puzzle Systems (4 Mechanics)

- [ ] Windwheel Rotate Mechanic (push input → stone rotation) `🤖 AI [GitHub Copilot, Claude]` `[ENG]`
  - [ ] Input: hold action button + directional input → wheel rotates at fixed RPM `🤖 AI [GitHub Copilot]` `[ENG]`
  - [ ] Rotation angle tracked continuously (0°–360°) `🤖 AI [GitHub Copilot]` `[ENG]`
- [ ] Windwheel Angle Validation + Unlock Logic `🤖 AI [GitHub Copilot]` `[ENG]`
  - [ ] At correct angle (±5° tolerance): unlock signal → enable updraft below `🤖 AI [GitHub Copilot]` `[ENG]`
  - [ ] Visual + audio feedback on correct alignment (VFX ribbon + lock-click SFX) `🤖 AI [GitHub Copilot]` `[ENG]`
- [ ] Tyaksha Fruit Steal / Return Gameplay Loop `🤝 AI+H [Claude for AI behavior + programmer]` `[ENG]`
  - [ ] Tyaksha AI: steal fruit from basket → flee to vine/tree `👤 Human` `[ENG]`
  - [ ] Player catches Tyaksha → fruit auto-returns to basket `🤖 AI [GitHub Copilot]` `[ENG]`
  - [ ] If player takes too long, Tyaksha escapes off-map (fruit lost) `👤 Human` `[DESIGN]`
- [ ] Tyaksha Camouflage Toggle System `🤖 AI [GitHub Copilot]` `[ENG]`
  - [ ] Tyaksha blends to leaf color on non-pursuit state `🤖 AI [GitHub Copilot]` `[ENG]`
  - [ ] Proximity (< 3m) or noise (player sprint) reveals camouflage `🤖 AI [GitHub Copilot]` `[ENG]`

---

## 8.6 Progression & Save Systems

- [ ] Checkpoint Save System (3 manual + 1 auto-save) `🤖 AI [GitHub Copilot]` `[ENG]`
  - [ ] Serialize player state (position, health, stamina, fruits collected) `🤖 AI [GitHub Copilot]` `[ENG]`
  - [ ] Save to local slot + cloud backup `🤖 AI [GitHub Copilot]` `[ENG]`
  - [ ] Restore on load (position, HUD state, quest flags) `🤖 AI [GitHub Copilot]` `[ENG]`
- [ ] Zone Transition Trigger System `🤖 AI [GitHub Copilot]` `[ENG]`
  - [ ] Volume overlap → trigger zone switch → update music, lighting, wind `🤖 AI [GitHub Copilot]` `[ENG]`
- [ ] Collectible Lore Scroll System `🤖 AI [GitHub Copilot]` `[ENG]`
  - [ ] Pickup → add to player journal → journal UI entry populated `🤖 AI [GitHub Copilot]` `[ENG]`
  - [ ] Journal accessible from pause menu `🤖 AI [GitHub Copilot]` `[ENG]`
- [ ] Achievement Trigger Events `🤖 AI [GitHub Copilot]` `[ENG]`
  - [ ] "First Leap": flag check on mission complete (0 Vayu rescues used) `🤖 AI [GitHub Copilot]` `[ENG]`
  - [ ] "Golden Stomach": flag check on basket full (all 7 fruits, none dropped) `🤖 AI [GitHub Copilot]` `[ENG]`
- [ ] Cinematic Lock-In System (disables player input during cutscenes) `🤖 AI [GitHub Copilot]` `[ENG]`
  - [ ] Broadcast "CinematicStart" event → all player controllers disable input `🤖 AI [GitHub Copilot]` `[ENG]`
  - [ ] Broadcast "CinematicEnd" → restore input `🤖 AI [GitHub Copilot]` `[ENG]`
- [ ] Character Transition Swap — Hanuman → Rama reveal handoff `👤 Human` `[ENG]`
  - [ ] After final cinematic: unload Mission 0 scene, stream in Ayodhya scene `👤 Human` `[ENG]`
  - [ ] Spawn Prince Rama controller, begin Mission 1 introduction state `👤 Human` `[ENG]`
- [ ] Mission Complete Evaluation (score / grade system) `🤝 AI+H [Claude for scoring formula + programmer]` `[ENG]`
  - [ ] Grade based on: time, fruits collected, rescues used, secrets found `👤 Human` `[DESIGN]`
  - [ ] Display grade on mission complete screen `🤖 AI [GitHub Copilot]` `[ENG]`
