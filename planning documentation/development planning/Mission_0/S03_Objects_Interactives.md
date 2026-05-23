# S03 — Objects & Interactive Elements | Mission 0 Development Tasks

> **Mission:** Mission 0 — Hanuman's Solar Leap
> **Section:** Gameplay Objects, Props & Interactables

| Metric | Value |
|--------|-------|
| Total Tasks | 38 |
| Total Subtasks | 79 |
| 🤖 AI-Assisted Tasks | 16 (42%) |
| 🤝 AI+Human Tasks | 14 (37%) |
| 👤 Human-Only Tasks | 8 (21%) |
| Teams Involved | ART, 3D, ENG, VFX, QA |

---

## 3.1 Interactive Gameplay Objects

### 3.1.1 Sacred Fruit (Collectible — 7 in Zone 1)

- [ ] Concept art — 3 fruit types (mango, amla, divine berry) with glow `🤖 AI [Midjourney, DALL-E 3]` `[ART]`
- [ ] 3D model — Fruit meshes (3 variants, hero-size collectible scale) `🤖 AI [Meshy AI]` `[3D]`
  - [ ] AI-generate base shape, refine with artist `👤 Human` `[3D]`
  - [ ] UV unwrap and bake `👤 Human` `[3D]`
- [ ] Texture — Albedo + Emissive glow (amber-gold) + Normal map `🤝 AI+H [Adobe Firefly + artist]` `[ART]`
- [ ] Interaction logic — Overlap → pickup → basket fill update `🤖 AI [GitHub Copilot, Claude]` `[ENG]`
  - [ ] Trigger volume on fruit mesh `👤 Human` `[ENG]`
  - [ ] Basket fill counter increment + HUD update event `🤖 AI [GitHub Copilot]` `[ENG]`
- [ ] VFX — Glow pulse (idle state) + collect sparkle burst `🤝 AI+H [Niagara + VFX artist]` `[VFX]`
- [ ] SFX — Gentle chime on pickup (see S07) `[AUDIO]`
- [ ] QA — Test all 7 pickup triggers, basket counter accuracy `👤 Human` `[QA]`

### 3.1.2 Mango Basket (Quest Progress Tracker)

- [ ] 3D model — Woven basket with fruit visible inside (fill states: 0/7, 3/7, 7/7) `🤝 AI+H [Meshy AI + modeler]` `[3D]`
  - [ ] Model base basket (open weave detail) `👤 Human` `[3D]`
  - [ ] Model 3 fruit fill insert meshes (visible through weave) `👤 Human` `[3D]`
- [ ] Texture — Woven fiber albedo, fruit color layers `🤝 AI+H [Adobe Firefly + artist]` `[ART]`
- [ ] Logic — Basket state machine (0–7 fruit count drives visible fill mesh swap) `🤖 AI [GitHub Copilot, Claude]` `[ENG]`
- [ ] HUD link — Basket progress indicator driven by same counter (see S06) `[UI]`
- [ ] QA — Verify basket fill states match pickups correctly `👤 Human` `[QA]`

### 3.1.3 Hanging Vine (Grapple Point)

- [ ] 3D model — Thick jungle vine with leaf clusters (3 length variants) `🤝 AI+H [SpeedTree + modeler]` `[3D]`
  - [ ] Generate base vine form with SpeedTree `🤖 AI [SpeedTree]` `[3D]`
  - [ ] Add manual leaf cluster placements `👤 Human` `[3D]`
- [ ] Texture — Bark albedo, leaf SSS, roughness set `🤝 AI+H [Adobe Firefly + artist]` `[ART]`
- [ ] Physics — Pendulum swing simulation (mass-spring model) `👤 Human` `[ENG]`
  - [ ] Set up spline physics chain `👤 Human` `[ENG]`
  - [ ] Tune spring/damper for natural arc feel `👤 Human` `[ENG]`
- [ ] Interaction — Latch animation trigger + swing arc + release event `🤖 AI [GitHub Copilot]` `[ENG]`
- [ ] VFX — Vine sway on player grab impact `🤝 AI+H [Niagara + VFX artist]` `[VFX]`
- [ ] QA — Test swing arc, release trajectory, and collision exit `👤 Human` `[QA]`

### 3.1.4 Stone Windwheel (Puzzle Element)

- [ ] Concept art — Windwheel with directional vane arrows, weathered stone `🤝 AI+H [Midjourney + artist]` `[ART]`
- [ ] 3D model — Large rotating stone disk with vane blades (3 required) `👤 Human` `[3D]`
  - [ ] Block disk and vane geometry `👤 Human` `[3D]`
  - [ ] Sculpt engraved arrow symbols and weathering `👤 Human` `[3D]`
  - [ ] Pivot point centered for rotation animation `👤 Human` `[3D]`
- [ ] Texture — Carved stone albedo with painted arrow inlay `🤝 AI+H [Substance AI + artist]` `[ART]`
- [ ] Interaction — Push/rotate mechanic (hold input → wheel spins in push direction) `🤖 AI [GitHub Copilot, Claude]` `[ENG]`
  - [ ] Input detection + rotation physics `🤖 AI [GitHub Copilot]` `[ENG]`
  - [ ] Angle validation logic (correct angle → updraft enable signal) `🤖 AI [GitHub Copilot]` `[ENG]`
- [ ] VFX — Wind redirect ribbon particles from vane tips on correct align `🤝 AI+H [Niagara + VFX artist]` `[VFX]`
- [ ] Audio — Stone grind on rotation + wind whoosh on unlock (see S07) `[AUDIO]`
- [ ] QA — All 3 puzzle instances validate correctly and unlock their updraft `👤 Human` `[QA]`

### 3.1.5 Cloud Platform Pad (Timed Traversal Platform)

- [ ] 3D model — Round condensation disk (small, medium, large variants) `🤝 AI+H [Meshy AI + modeler]` `[3D]`
- [ ] Texture — Cloud volumetric material (soft SSS edge) `👤 Human` `[TECH-ART]`
- [ ] Logic — 3-second timer starts on player land → color warning → dissolve `🤖 AI [GitHub Copilot, Claude]` `[ENG]`
  - [ ] Frame-rate independent DeltaTime timer `🤖 AI [GitHub Copilot]` `[ENG]`
  - [ ] Material parameter drive for color shift (white → yellow → red) `🤖 AI [GitHub Copilot]` `[ENG]`
  - [ ] Dissolve trigger at 0 seconds `🤖 AI [GitHub Copilot]` `[ENG]`
- [ ] VFX — Puff burst on dissolve completion `🤝 AI+H [Niagara + VFX artist]` `[VFX]`
- [ ] Audio — Soft puff on dissolve (see S07) `[AUDIO]`
- [ ] QA — Timer accuracy across all frame rates, dissolve consistency `👤 Human` `[QA]`

### 3.1.6 Thermal Updraft Column (Vertical Lift Mechanic)

- [ ] VFX — Rising heat shimmer column with rotating air particles `👤 Human` `[VFX]`
  - [ ] Niagara emitter: upward velocity, spiral orbit, heat distortion `👤 Human` `[VFX]`
  - [ ] Column width matches gameplay reach zone `👤 Human` `[VFX]`
- [ ] Logic — Enter column → apply continuous upward velocity to character `🤖 AI [GitHub Copilot, Claude]` `[ENG]`
  - [ ] Trigger volume detection `🤖 AI [GitHub Copilot]` `[ENG]`
  - [ ] Velocity application override while inside `🤖 AI [GitHub Copilot]` `[ENG]`
  - [ ] Exit detection and velocity hand-back to character controller `👤 Human` `[ENG]`
- [ ] Audio — Whooshing wind roar when inside column `[AUDIO]`
- [ ] QA — Test entry/exit transitions, height limit, wind redirect after windwheel unlock `👤 Human` `[QA]`

### 3.1.7 Airavat's Tusks — OBJ_AIRAVAT_TUSKS (Boss Phase 1 Climb Surface)

- [ ] 3D model — Colossal ivory tusk (supports wall-run + grapple) (see S01 Airavat) `👤 Human` `[3D]`
- [ ] Collision — Custom collision mesh that supports wall-run surface detection `👤 Human` `[ENG]`
  - [ ] Define walk-on angle threshold for tusk curve surface `👤 Human` `[ENG]`
- [ ] Interaction — Grapple attach point nodes on tusk surface `🤖 AI [GitHub Copilot]` `[ENG]`
- [ ] Interaction — Tusk shake event (boss ability) → reduces grip, may eject player `👤 Human` `[ENG]`
- [ ] VFX — Impact sparks when Hanuman kicks off tusk surface `🤖 AI [Niagara template]` `[VFX]`
- [ ] QA — Wall-run path, grapple-on-tusk, and tusk-shake ejection all functional `👤 Human` `[QA]`

### 3.1.8 Vajra Core — OBJ_VAJRA_CORE (Hazard Field Generator)

- [ ] 3D model — Floating multi-pronged crystal with crackling lightning `🤝 AI+H [Meshy AI + modeler]` `[3D]`
  - [ ] Block base crystal polyhedron form `👤 Human` `[3D]`
  - [ ] Add prong arms radiating outward `👤 Human` `[3D]`
- [ ] Texture — Translucent crystal body, electric emissive veins `👤 Human` `[TECH-ART]`
- [ ] Logic — Timed radial ring wave spawner (interval configurable per difficulty) `🤖 AI [GitHub Copilot, Claude]` `[ENG]`
  - [ ] Ring wave prefab/BP (expanding radial plane collider) `🤖 AI [GitHub Copilot]` `[ENG]`
  - [ ] Core charge-up timer before each wave `🤖 AI [GitHub Copilot]` `[ENG]`
- [ ] VFX — Ring wave emission + core charge-up glow pulse `👤 Human` `[VFX]`
- [ ] Audio — Vajra hum + wave crack (see S07) `[AUDIO]`
- [ ] QA — Ring timing consistency, wave hitbox accuracy `👤 Human` `[QA]`

### 3.1.9 Indra's Golden Crown (Narrative Grab Object)

- [ ] Concept art — Ornate golden crown with ruby/sapphire inlays `🤝 AI+H [Midjourney + artist]` `[ART]`
- [ ] 3D model — Crown with gemstone details `🤖 AI [Meshy AI]` `[3D]`
  - [ ] AI-generate form, hand-refine gem facets and band engravings `👤 Human` `[3D]`
- [ ] Texture — PBR gold metallic, gem emissive SSS `🤝 AI+H [Substance AI + artist]` `[ART]`
- [ ] Interaction — One-handed grab trigger → cinematic lock-in fires `👤 Human` `[ENG]`
  - [ ] Input detection on chariot proximity `👤 Human` `[ENG]`
  - [ ] Grab animation trigger + cinematic sequence start `🤖 AI [GitHub Copilot]` `[ENG]`
- [ ] VFX — Grab sparkle + crown aura flare on grab `🤝 AI+H [Niagara + VFX artist]` `[VFX]`
- [ ] QA — Grab trigger fires at correct survival time, cinematic plays `👤 Human` `[QA]`

---

## 3.2 Environmental Prop Objects (Non-Interactive Dressing)

### 3.2.1 Ancient Stone Idol / Vayu Shrine

- [ ] Concept art — Small Vayu shrine with wind motif carvings `🤖 AI [Midjourney]` `[ART]`
- [ ] 3D model — Shrine base, deity relief carving, offering bowl `🤝 AI+H [Meshy AI + modeler]` `[3D]`
  - [ ] Block, sculpt carving detail, UV, bake `👤 Human` `[3D]`
- [ ] Texture + material (weathered stone, slight moss) `🤝 AI+H [Stable Diffusion + artist]` `[ART]`
- [ ] Placement — Grove corner, mountain mid-cliff (lore scroll trigger point) `👤 Human` `[DESIGN]`
- [ ] LOD variants `🤖 AI [InstaLOD]` `[3D]`

### 3.2.2 Fallen Mossy Columns

- [ ] 3D model — 2 size variants (broken column sections lying on ground) `🤖 AI [Meshy AI]` `[3D]`
- [ ] Texture — Stone + moss blend material (reuse from Zone 1 stone set) `🤖 AI [material instance]` `[TECH-ART]`
- [ ] Scatter placement (3–5 columns in orchard ruins area) `👤 Human` `[DESIGN]`

### 3.2.3 Bird Nests on Cliff Ledges

- [ ] 3D model — Simple woven nest with 2–3 eggs (hero and small variants) `🤖 AI [Meshy AI]` `[3D]`
- [ ] Texture — Straw/twig albedo, speckled egg pattern `🤖 AI [Adobe Firefly]` `[ART]`
- [ ] Placement — 3 nest props on cliff ledge outcrop `👤 Human` `[DESIGN]`

### 3.2.4 Frozen Waterfall Ice Formation

- [ ] 3D model — Vertical ice column sheets with icicle stalactites `🤝 AI+H [Meshy AI + modeler]` `[3D]`
  - [ ] Block ice column mass, add icicle detail `👤 Human` `[3D]`
- [ ] Texture — Translucent ice shader, refraction, cold blue tint `👤 Human` `[TECH-ART]`
- [ ] Placement — Mid-cliff landmark, visible from Zone 2 base `👤 Human` `[DESIGN]`

### 3.2.5 Celestial Cloud Formation Sculptures (Zone 3 Dressing)

- [ ] 3D model — 4 unique floating cloud formation shapes (non-traversable, background) `🤝 AI+H [Meshy AI + modeler]` `[3D]`
- [ ] Texture — Shared cloud volumetric material (reuse Zone 3 cloud set) `🤖 AI [material instance]` `[TECH-ART]`
- [ ] Placement — Background depth layers at varying altitudes `👤 Human` `[DESIGN]`

### 3.2.6 Background Mountain Ranges (Non-Traversable)

- [ ] 3D model — Distant mountain silhouette mesh (low-detail, high-altitude visible) `🤖 AI [Meshy AI terrain gen]` `[3D]`
- [ ] Texture — Distance haze material (blueish, low detail, atmospheric) `🤝 AI+H [Stable Diffusion + tech artist]` `[ART]`
- [ ] Placement — Ring the Zone 1 and Zone 2 horizon for sense of scale `👤 Human` `[DESIGN]`
- [ ] LOD — Single LOD (always distant, low poly fine) `👤 Human` `[3D]`
