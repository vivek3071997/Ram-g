# Ram-G — Mission 0: Hanuman's Solar Leap
# Complete Development Task List

> **Mission 0 Summary:** Kid Hanuman starts in Sumeru's orchards, learns movement mechanics, chases forest imps, ascends through thermal updrafts, reaches the stratosphere, battles Airavat and Indra, receives the Curse of Forgetfulness, and the camera transitions to Ayodhya where Prince Rama is revealed.

---

## STATUS KEY
- `[ ]` — Not Started
- `[/]` — In Progress
- `[x]` — Completed
- `[!]` — Blocked / Needs Decision

---

## 📁 SECTION 1 — CHARACTERS

### 1.1 Kid Hanuman (Primary Playable)

#### 1.1.1 Character Design & Concept Art
- [ ] Concept art — Kid Hanuman full-body reference sheet (front, side, back)
- [ ] Concept art — Kid Hanuman facial expressions sheet (joy, mischief, surprise, determination, pain/fall)
- [ ] Concept art — Kid Hanuman "Normal Monkey" post-nerf appearance (aura off, shrunken stats)
- [ ] Design — Fur color, pattern, and length variation (golden-orange highlights, lighter chest)
- [ ] Design — Clothing/loincloth style, sacred thread (Yajnopavita), simple jewelry appropriate for a young Vanara child
- [ ] Design — Tail design (length proportional to child form, used as grapple hook)
- [ ] Design — Scaling reference chart: Kid Hanuman vs. Adult Hanuman vs. Anjana

#### 1.1.2 3D Modeling
- [ ] Model — Kid Hanuman base mesh (child-scaled Vanara body, ~1.0m height)
- [ ] Model — Kid Hanuman high-poly sculpt (facial features, fur texture bake surface)
- [ ] Model — Kid Hanuman low-poly game mesh (optimized, LOD-ready)
- [ ] Model — Kid Hanuman Tail (separate bone-driven mesh, physics simulation)
- [ ] Model — Mango Basket prop (held quest object with progress fill visual)
- [ ] Model — LOD1, LOD2, LOD3 generation for all Kid Hanuman meshes

#### 1.1.3 Rigging & Skinning
- [ ] Rig — Full body skeleton rig (biped + tail bone chain, minimum 6 tail bones)
- [ ] Rig — Facial rig (jaw, brow, cheek, eye orbit — blend-shape driven)
- [ ] Rig — IK/FK system for arms (bow-draw ready, grapple hook reach)
- [ ] Rig — Tail physics simulation rig (secondary motion for tail swing, grapple)
- [ ] Skinning — Weight paint full body, ensure clean deformation at joints
- [ ] Skinning — Blend-shape targets for all expression sheet states

#### 1.1.4 Texturing & Materials
- [ ] Texture — Albedo (Base Color) map — fur, skin, cloth (4K resolution)
- [ ] Texture — Roughness/Metallic map — fur shimmer, sacred thread metallic beads
- [ ] Texture — Normal map — fur strands, facial micro-detail, muscle definition
- [ ] Texture — Subsurface Scattering map — ear rims, finger pads, nose
- [ ] Texture — Ambient Occlusion map
- [ ] Texture — Emissive map — Golden aura glow state (pre-nerf) vs. OFF state (post-nerf)
- [ ] Shader — Fur strand shader (anisotropic highlights, wind-reactive shell layering)
- [ ] Shader — Subsurface skin shader for face (child-like warmth tone)
- [ ] Shader — Golden aura overlay material (particle-driven, fades on nerf)

#### 1.1.5 Character Animations
- [ ] **Locomotion (Base Set)**
  - [ ] Idle — Playful rock-shift, tail swish (8-second loop)
  - [ ] Idle Variation 1 — Sniff the air, scratch ear
  - [ ] Idle Variation 2 — Balance on one foot, grin
  - [ ] Walk — Bouncy, child-like amble
  - [ ] Run — Fast barefoot sprint with tail trailing
  - [ ] Sprint (Full Speed) — Leaning forward, wind effect, tail arrow-straight
  - [ ] Jump — Single jump, big knee-launch
  - [ ] Double Jump — Mid-air spin kick before second launch
  - [ ] Glide — Arms and legs spread, tail acting as rudder
  - [ ] Land (Soft) — Crouch-absorb with grin
  - [ ] Land (Hard) — Shockwave crouch, dust burst
  - [ ] Fall — Tumble, arms flailing
  - [ ] Crouch — Low crouch sneak
  - [ ] Crouch Walk — Sneaking toe-walk

- [ ] **Climbing & Traversal**
  - [ ] Vine Grab (Reach & Lock)
  - [ ] Vine Swing (L-R pendulum motion, building momentum)
  - [ ] Vine Drop (Release and fall)
  - [ ] Wall Run (Vertical & Horizontal)
  - [ ] Wall Jump (Push-off and rotate)
  - [ ] Ledge Grab (Catch ledge, hang)
  - [ ] Ledge Pull-Up (Slow & Fast variants)
  - [ ] Tail Grapple Launch (Tail shoots out to anchor, body swing)
  - [ ] Tail Grapple Swing Arc
  - [ ] Tail Grapple Release
  - [ ] Cloud Pad Land (Bounce springy)
  - [ ] Thermal Updraft Enter (Feet leave ground, hover spin)
  - [ ] Thermal Updraft Float (Rotating hover loop)
  - [ ] Thermal Updraft Exit (Blast upward launch)

- [ ] **Combat**
  - [ ] Light Punch — Fast 1-2-3 combo sequence
  - [ ] Heavy Punch — Wind-up overhead slam
  - [ ] Tail Swipe (Low) — 180° arc knockback
  - [ ] Tail Uppercut (Upward flick)
  - [ ] Dodge Roll — Forward somersault
  - [ ] Dodge Roll — Side cartwheel
  - [ ] Tickle Tackle (Non-lethal Tyaksha subdual) — Jump-pounce tackle
  - [ ] Fruit Basket Catch (Return fruit to basket animation)
  - [ ] Hit Reaction — Stagger (Light)
  - [ ] Hit Reaction — Knockback (Heavy)
  - [ ] Defeated / KO — Dizzy spiral fall

- [ ] **Boss-Specific Animations**
  - [ ] Airavat Tusk Grab — Hands latch onto tusk, feet scramble up
  - [ ] Airavat Neck Scale — Pulling up fur-over-fur climbing motion
  - [ ] Airavat Ear Tickle — Reach and tickle action with belly laugh
  - [ ] Indra Chariot Grab — Both hands clench golden chariot rim
  - [ ] Indra Crown Grab — One arm reach-and-snatch
  - [ ] Dodge Lightning Ring — Dive-roll with timing window cue

- [ ] **Narrative & Cutscene**
  - [ ] Pointing at the Sun (mistaking it for a mango)
  - [ ] Laughing — Big open-mouth child laugh
  - [ ] Fear Reaction — Eyes wide, tail between legs
  - [ ] Receiving Vajra Strike — Full body hit, spin, fall
  - [ ] Unconscious Fall to Earth (long-form cinematic fall)
  - [ ] Receiving Divine Boons — Glowing aura rises, body floats
  - [ ] Post-Nerf Sit (Peaceful normal monkey on Rishyamukha Hill)
  - [ ] Camera Pan Exit (Kid Hanuman sitting idle, camera pulls away)

#### 1.1.6 Character VFX
- [ ] VFX — Golden-orange aura particles (normal state, pre-nerf)
- [ ] VFX — Aura fade-out on nerf (dissolve + particle drain)
- [ ] VFX — Sprint trail (golden wind streaks)
- [ ] VFX — Double jump shockwave ring (compressed air burst)
- [ ] VFX — Tail whip swipe trail (golden arc)
- [ ] VFX — Thermal updraft enter (body glow pulse + spiraling air)
- [ ] VFX — Vajra strike impact (blue-white electric discharge, screen flash)
- [ ] VFX — Boon receive (multi-colored divine light showers)

---

### 1.2 Anjana (Mother — NPC)

- [ ] Concept art — Anjana full-body (gentle Vanara woman, maternal appearance)
- [ ] Model — Anjana 3D base mesh
- [ ] Rig & Skin — Full body rig (no combat, only expressive upper body)
- [ ] Texture — Albedo, Roughness, Normal maps
- [ ] Animations:
  - [ ] Idle — Arms crossed, watchful
  - [ ] Call Out — Hand to mouth, calling pose
  - [ ] Reach Out — Arms extended in worry
  - [ ] Wave (Farewell) — Soft hand wave
  - [ ] Dialogue Mouth Sync — Phoneme blend-shapes for dialogue

---

### 1.3 Lord Indra (Boss — Sky Arena)

#### 1.3.1 Character Design & Concept Art
- [ ] Concept art — Indra full-body in battle regalia (thunderous, regal)
- [ ] Concept art — Indra's Golden Chariot (Vimana design)
- [ ] Concept art — Indra expressions (arrogance, fury, warning, awe)
- [ ] Design — Indra golden crown, armor, Vajra weapon in hand
- [ ] Design — Thundercloud cloak / storm-lightning aura outline

#### 1.3.2 3D Modeling
- [ ] Model — Indra character base mesh
- [ ] Model — Indra's full regalia armor set
- [ ] Model — Indra's Vajra (Thunderbolt weapon) — multi-pronged, crackling
- [ ] Model — Indra's Golden Chariot (Airborne vimana platform)
- [ ] LOD variants for Indra and chariot

#### 1.3.3 Rigging & Animation
- [ ] Rig — Full body + armor physics rig
- [ ] Rig — Cape/cloak secondary physics simulation
- [ ] Animations:
  - [ ] Idle on Chariot (commanding stance)
  - [ ] Chariot Drive (standing, arms controlling reins)
  - [ ] Vajra Throw (Wind-up, launch, recall)
  - [ ] Lightning Spear Cast (Charge pose, discharge throw)
  - [ ] Lightning Ring Stomp (Slam chariot floor, rings radiate outward)
  - [ ] Warning Point (Point at Hanuman before attack)
  - [ ] Rage Escalation (Arms spread, storm intensifies around him)
  - [ ] Stagger (When Hanuman grabs crown)
  - [ ] Post-Battle Regret (Arms lower, expression shifts)

#### 1.3.4 Texturing & Materials
- [ ] Texture — Indra albedo (gold armor, blue skin, white beard)
- [ ] Texture — Normal, Roughness, Emissive (lightning veins on armor)
- [ ] Shader — Lightning arc material (scrolling UV electric shader on Vajra)
- [ ] Shader — Storm-cloud cloak volumetric material

#### 1.3.5 VFX
- [ ] VFX — Vajra arc lightning trails
- [ ] VFX — Lightning ring ground wave (radial shockwave with z-crackling)
- [ ] VFX — Storm field (background thunder + dark cloud volume)
- [ ] VFX — Chariot propulsion jets (gold flame exhaust)

---

### 1.4 Airavat (Boss — Cloud Bridge)

#### 1.4.1 Character Design & Concept Art
- [ ] Concept art — Airavat full body (Celestial White Elephant, 3x normal elephant scale)
- [ ] Concept art — Airavat decorative regalia (Deva gold trappings, anklets, crown jewel)
- [ ] Concept art — Boss Phase breakdown sketches (tusk climb, trunk lash)

#### 1.4.2 3D Modeling
- [ ] Model — Airavat base mesh (colossal elephant, white/pearl skin)
- [ ] Model — Gold regalia armor/jewelry for Airavat
- [ ] Model — Airavat tusks (separate dynamic objects for grapple interaction)
- [ ] Model — LOD variants

#### 1.4.3 Rigging & Animation
- [ ] Rig — Full elephant skeleton (trunk IK chain, ear physics, tail)
- [ ] Rig — Tusk separate bone chain (player can grab and climb)
- [ ] Animations:
  - [ ] Walk/Charge across cloud bridge
  - [ ] Stomp (L/R foot) — Ground crack shockwave
  - [ ] Trunk Sweep (low ground sweep)
  - [ ] Trunk Lash (overhead whip slam)
  - [ ] Water Blast (trunk curl, spray forward)
  - [ ] Tusk Shake (shake player off tusk)
  - [ ] Ear Flap (defensive flap)
  - [ ] Sleep Fall (knees buckle, side collapse — tickle defeat)
  - [ ] Roar (mouth open, eyes glow)

#### 1.4.4 Texturing & Materials
- [ ] Texture — Albedo (pearl white, gold jewelry, bioluminescent vein accents)
- [ ] Texture — Normal, Roughness, Emissive maps
- [ ] Shader — Pearl/iridescent skin shader
- [ ] Shader — Gold regalia PBR metallic shader

#### 1.4.5 VFX
- [ ] VFX — Stomp cloud crack (cloud splits, electric dust)
- [ ] VFX — Trunk water blast (high-pressure water cone)
- [ ] VFX — Sleep particles (ZZZ bubbles — playful, child-friendly)
- [ ] VFX — Bioluminescent vein pulse (escalates as anger rises)

---

### 1.5 Vayu (Voice/Wind Spirit — Unseen NPC)
- [ ] Concept art — Wind spirit visualization (swirling air silhouette, no solid form)
- [ ] Dialogue script finalization (3 voiced lines in Mission 0)
- [ ] VFX — Vayu's presence (localized wind spiral, leaves and petals swirling)
- [ ] Audio — Deep resonant voice acting direction brief

---

### 1.6 Tyakshas (Enemy Mobs — Orchard Chase)
- [ ] Concept art — Tyaksha (small forest imp, green, leaf-camouflage, mischievous grin)
- [ ] Model — Tyaksha base mesh (small, agile, with fruit bag)
- [ ] Rig & Skin — Biped rig (fast, spring-loaded joints)
- [ ] Texture — Albedo, Normal, Roughness maps
- [ ] Animations:
  - [ ] Idle (shifty look around)
  - [ ] Run (lopsided fast scurry)
  - [ ] Double Jump (spring legs)
  - [ ] Camouflage Blend (color shift to match leaf background)
  - [ ] Seed Throw (rearing back, pitch-and-throw arm)
  - [ ] Hit/Tackled (stumble, drop fruit, laugh)
  - [ ] Caught (held upside down by tail, wriggling)
- [ ] VFX — Seed throw projectile + thorn prickle impact
- [ ] VFX — Camouflage shimmer (chromatic aberration effect)

---

## 📁 SECTION 2 — WORLD & ENVIRONMENT

### 2.1 Mount Sumeru — Orchards (Zone 1 — Ground Level)

#### 2.1.1 Layout & Level Design
- [ ] Blockout — Orchard zone footprint (play area ≈ 300m × 300m)
- [ ] Layout — Fruit tree arrangement, climbing vines, stone arches
- [ ] Layout — Anjana's Grove focal point (sacred fruits, glowing amber light)
- [ ] Design — Natural obstacles: mossy boulders, root-tangles, creek beds

#### 2.1.2 3D Environment Assets
- [ ] Model — Tropical fruit trees (mango, banana, sacred amla)
- [ ] Model — Mossy stone arches (multiple scale variants: small, medium, large)
- [ ] Model — Hanging vines (grapple-interactable, physics-simulated)
- [ ] Model — Sacred Fruit Basket (quest object, placed at grove center)
- [ ] Model — Anjana's Hut (background prop, warm golden interior glow)
- [ ] Model — Wildflowers and ground fern clusters (background dressing)
- [ ] Model — Ancient stone idol (small Shiva/Vayu shrine in corner of grove)
- [ ] Model — Creek bed with flowing water (animated water shader)
- [ ] Model — Fireflies (particle-system driven ambient life)

#### 2.1.3 Textures & Materials
- [ ] Texture — Tree bark (mossy, tropical, PBR roughness)
- [ ] Texture — Leaf canopy (translucent SSS leaves, multiple color variants)
- [ ] Texture — Mossy stone (wet moss layer on top, dry stone base)
- [ ] Texture — Red-brown earth ground (with embedded root detail)
- [ ] Texture — Sacred Fruit (Emissive glow, amber-gold hue, normal bump)
- [ ] Shader — Wind-reactive leaf shader (vertex displacement by wind vector)
- [ ] Shader — Flowing creek water shader (normal-scroll, foam edge)

#### 2.1.4 Atmospheric & Lighting
- [ ] Lighting — Pre-dawn ambient (deep blue-purple sky dome at scene start)
- [ ] Lighting — Anjana's Grove warm torch light (orange-amber point lights)
- [ ] Lighting — Early sunrise rays penetrating tree canopy (volumetric shafts)
- [ ] Atmospheric — Morning mist ground layer (particle-driven, low-lying)
- [ ] Audio Ambience — Crickets, early bird calls, creek babble, wind in leaves

---

### 2.2 Mount Sumeru — Peak Ascent (Zone 2 — Cliff Traversal)

#### 2.2.1 Layout & Level Design
- [ ] Blockout — Vertical cliff face layout (height range: 0m to 4000m play equivalent)
- [ ] Design — Thermal updraft column placement (3 mandatory updraft puzzles)
- [ ] Design — Windwheel stone puzzles (3 wheel-redirect puzzles to unlock updraft paths)
- [ ] Design — Moving cloud platform placement (timing-based, evaporate at 3 seconds)

#### 2.2.2 3D Environment Assets
- [ ] Model — Sumeru cliff face (massive, layered geological strata with visual altitude layers)
- [ ] Model — Stone windwheel (mechanical rotating stone disk with directional vane arrows)
- [ ] Model — Cloud Platform (solid condensation disk, visually semi-transparent white puff)
- [ ] Model — Thermal Updraft Column (visible rotating air column, heat haze shimmer)
- [ ] Model — Mountain Shrine (hidden Vayu shrine halfway up — lore collectible)
- [ ] Model — Eagle nest ledge (environmental storytelling prop)
- [ ] Model — Frozen waterfall (visual landmark at mid-altitude layer)

#### 2.2.3 Textures & Materials
- [ ] Texture — Rock strata (layered — red sediment at base, grey granite at apex)
- [ ] Texture — Ice crystal patches (upper cliff faces)
- [ ] Shader — Cloud Platform dissolve shader (opacity fades on 3-second timer)
- [ ] Shader — Thermal updraft heat-haze (refraction shader, scrolling UV)
- [ ] Shader — Stone windwheel (painted direction arrows, clean carved stone)

#### 2.2.4 Atmospheric & Lighting
- [ ] Lighting — Sunrise gradient (warm orange at cliff base, cooler blue at apex)
- [ ] Lighting — God-ray shafts from above (dramatic topdown light columns)
- [ ] Atmospheric — Thin cloud wisps at mid-altitude (opacity particle wisps)
- [ ] Audio Ambience — Rising wind howl as altitude increases, thinning bird calls

---

### 2.3 Troposphere Cloud Deck (Zone 3 — Cloud Platforming)

#### 2.3.1 Layout & Level Design
- [ ] Blockout — Horizontal cloud platform field (open sky, wide arena)
- [ ] Design — Platform arrangement (series of timed cloud pads in a route)
- [ ] Design — Rising Sun path (visual target in the far sky, slightly animated orbit)
- [ ] Design — Danger zones (gaps between pads, fall = Vayu rescue trigger)

#### 2.3.2 3D Environment Assets
- [ ] Model — Cloud Platform variants (small, medium, large condensation pads)
- [ ] Model — Rising Sun asset (distant hero, glowing golden sphere with lens flare)
- [ ] Model — Ice crystal cluster decorations (floating in cloud layer)
- [ ] Model — Wind shear ribbon effects (visual directional wind guides)
- [ ] Model — Airavat pre-battle cloud bridge (solid massive cloud runway)

#### 2.3.3 Textures & Materials
- [ ] Texture — Cloud volumetric material (subsurface scatter, soft edge glow)
- [ ] Shader — Cloud pad evaporate shader (particle puff + dissolve)
- [ ] Shader — Atmospheric depth haze (distance-based opacity)
- [ ] Shader — Sun corona glow (emissive + post-process bloom)

#### 2.3.4 Atmospheric & Lighting
- [ ] Lighting — Full golden sunrise sky dome (horizon band: orange → yellow → white)
- [ ] Lighting — Underside cloud shadow play (soft blue undershadow on pads)
- [ ] Atmospheric — High altitude hum (reduced ambient sound, muffled bass)
- [ ] Audio Ambience — Roaring wind, distant celestial trumpet echoes (Airavat approach)

---

### 2.4 Upper Stratosphere & Storm Arena (Zone 4 — Boss Arena)

#### 2.4.1 Layout & Level Design
- [ ] Blockout — Circular storm arena (radius ≈ 500m, open sky dome)
- [ ] Design — Indra's chariot rail path (circular ellipse orbit route)
- [ ] Design — Lightning ring spawn zones (tiled floor of cloud — radial markers)
- [ ] Design — Arena boundary (wind-wall perimeter that bounces player back)

#### 2.4.2 3D Environment Assets
- [ ] Model — Storm cloud ceiling (dark, roiling cumulonimbus layer above)
- [ ] Model — Solar Gate (distant architecture — golden arch in the sky, non-reachable)
- [ ] Model — Lightning spire towers (background props — natural static discharge rods)
- [ ] Model — Chariot rail (invisible physics rail, visible energy trail)

#### 2.4.3 Textures & Materials
- [ ] Texture — Dark cumulonimbus cloud (heavy, blue-black, volumetric)
- [ ] Shader — Electric arc material (UV-scrolled, emissive blue-white crackling)
- [ ] Shader — Arena floor cloud (solid but visually vaporous)

#### 2.4.4 Atmospheric & Lighting
- [ ] Lighting — Strobing lightning ambience (dynamic directional light, rapid flash)
- [ ] Lighting — Indra golden chariot bloom glow (warm point light source orbiting)
- [ ] Atmospheric — Ozone scent VFX (blue-green tint post-process on lightning flashes)
- [ ] Audio Ambience — Rolling thunder, celestial war conch, chariot wheel roar

---

## 📁 SECTION 3 — OBJECTS & INTERACTIVE ELEMENTS

### 3.1 Interactive Gameplay Objects

- [ ] **Sacred Fruit** — Collectible glowing fruit (amber emissive, collected on overlap)
  - [ ] Model — Multiple fruit types (mango, amla, divine berry)
  - [ ] Interaction — Pickup animation + basket fill progress
  - [ ] VFX — Glow + collect sparkle burst

- [ ] **Mango Basket** — Quest progress tracker (Hanuman holds it)
  - [ ] Model — Woven basket with fruit visible inside
  - [ ] UI link — Basket fill = HUD mission progress indicator

- [ ] **Hanging Vine** — Grapple point
  - [ ] Model — Thick jungle vine with leaf clusters
  - [ ] Physics — Swing simulation (pendulum mass-spring)
  - [ ] Interaction — Latch animation + swing arc + release

- [ ] **Stone Windwheel** — Puzzle element
  - [ ] Model — Large rotating stone disk with vane blades
  - [ ] Interaction — Push/rotate mechanic (holding input spins it)
  - [ ] Logic — Correct angle unlocks thermal updraft below
  - [ ] VFX — Wind redirect visual (ribbon particles from vane tips)

- [ ] **Cloud Platform Pad** — Timed traversal platform
  - [ ] Model — Solid round condensation disk
  - [ ] Logic — 3-second timer starts on player land → dissolve
  - [ ] VFX — Warning color shift (white → yellow → red before dissolve)
  - [ ] VFX — Dissolve puff burst

- [ ] **Thermal Updraft Column** — Vertical lift mechanic
  - [ ] VFX — Rising heat shimmer column with rotating air particles
  - [ ] Logic — Enter column → apply upward velocity, player holds position
  - [ ] Audio — Whooshing wind roar when inside column

- [ ] **Airavat's Tusks (OBJ_AIRAVAT_TUSKS)** — Boss Phase 1 climbing surface
  - [ ] Model — Colossal ivory tusk (surface must support wall-run and grapple)
  - [ ] Interaction — Grab surface + climb animation
  - [ ] VFX — Impact sparks when Hanuman kicks off tusk surface

- [ ] **Vajra Core (OBJ_VAJRA_CORE)** — Boss Phase 2 hazard field generator
  - [ ] Model — Floating multi-pronged crystal core with crackling lightning
  - [ ] Logic — Generates radial lightning ring waves at timed intervals
  - [ ] VFX — Ring wave emission, core charge-up pulse

- [ ] **Indra's Golden Crown** — Narrative goal object (grab = boss trigger cinematic)
  - [ ] Model — Ornate golden crown with ruby/sapphire inlays
  - [ ] Interaction — One-handed grab animation
  - [ ] VFX — Grab sparkle + crown aura flare

---

### 3.2 Environmental Prop Objects (Non-Interactive Dressing)

- [ ] Ancient stone idol / Vayu shrine (grove area)
- [ ] Fallen mossy columns (orchard ruins)
- [ ] Bird nests on cliff ledges
- [ ] Frozen waterfall ice formation (mid-cliff)
- [ ] Celestial cloud formation sculptures (stratosphere dressing)
- [ ] Background mountain ranges (distant, non-traversable)

---

## 📁 SECTION 4 — NATURE ELEMENTS & COMPONENTS

### 4.1 Wind System

- [ ] Design — Wind vector field system for the full scene (ground → stratosphere)
  - [ ] Ground (Zone 1): 15 km/h gentle valley breeze (affects foliage)
  - [ ] Cliff face (Zone 2): 40 km/h variable gusts (pushes player sideways)
  - [ ] Cloud deck (Zone 3): 80 km/h stratospheric drift (requires player to angle jumps)
  - [ ] Storm arena (Zone 4): 120 km/h jet-stream + localized Indra storm bursts
- [ ] Implement — Wind vertex shader (leaf/grass vertex displacement by wind vector)
- [ ] Implement — Character cape/cloth physics driven by wind vector field
- [ ] Implement — Wind audio layer (volume + pitch scales with altitude/intensity)
- [ ] Implement — Wind visual particles (leaf spirals, dust, ice crystals at altitude)
- [ ] Vayu's Wind (Special) — Directed personal updraft (saves player on failed fall)
  - [ ] VFX — Localized upward spiral wind with fatherly silhouette shimmer

---

### 4.2 Light System

- [ ] Implement — Dynamic sky dome (time-of-day progression: 5:15 AM → 6:30 AM)
- [ ] Lighting — Pre-dawn blue-purple ambient → sunrise orange transition
- [ ] Lighting — Volumetric god-ray shafts (sky light piercing cloud gaps)
- [ ] Lighting — Anjana's grove warm torch point lights (amber, 3m radius, flicker)
- [ ] Lighting — Sun disc glow emissive (increasing intensity as player ascends)
- [ ] Lighting — Indra's lightning strobe (dynamic directional flicker during boss fight)
- [ ] Lighting — Airavat bioluminescent vein glow (point lights embedded in model)
- [ ] Post-Process — Bloom intensity increases at higher altitude layers
- [ ] Post-Process — Chromatic aberration on Vajra strike screen impact
- [ ] Post-Process — Color grading LUT — warm golden for orchard, cold blue for stratosphere

---

### 4.3 Water System

- [ ] Implement — Orchard creek (Zone 1) — flowing shallow stream
  - [ ] Shader — Normal-map scroll water surface
  - [ ] Shader — Subsurface scatter (visible pebbles below)
  - [ ] Audio — Gentle creek babble
  - [ ] Physics — Splash particle on player contact
- [ ] Implement — Airavat Trunk Water Blast (Boss attack water projectile)
  - [ ] VFX — High-pressure water cone blast (Niagara particle simulation)
  - [ ] Physics — Player knockback on hit
  - [ ] Audio — High-pressure hose-blast sound + splash impact

---

### 4.4 Earth / Ground System

- [ ] Implement — Ground deformation on heavy landing (temporary dent decal)
- [ ] Particle — Landing dust burst (foot-strike → loose soil particles)
- [ ] Particle — Running footstep dust (light puff trail at sprint speed)
- [ ] Material — Ground texture blending (earth → moss → stone → ice by altitude)
- [ ] Implement — Airavat stomp cloud crack (cloud floor splits on stomp impact)
  - [ ] VFX — Cloud floor crack decal + radial split shockwave

---

### 4.5 Fire & Electricity System (Boss Arena)

- [ ] Implement — Vajra lightning arc material (electric, UV-scroll emissive shader)
- [ ] VFX — Lightning strike impact (point flash + ground char decal)
- [ ] VFX — Lightning ring wave (radial ring expansion from Vajra Core)
- [ ] VFX — Electric crackle on Indra's armor (ambient looping arc particles)
- [ ] Audio — Thunder crack (directional, distance-attenuated)
- [ ] Audio — Vajra hum (constant low-frequency hum while boss charges)
- [ ] Audio — Hit-by-lightning (full screen white flash + muffled ear ring for 2s)

---

### 4.6 Atmosphere & Sky System

- [ ] Implement — Volumetric cloud layer (Troposphere cloud deck — dense, traversable-looking)
- [ ] Implement — Upper atmosphere haze (depth fog, blue-white scatter)
- [ ] Implement — God-rays / light shafts (volumetric directional lights piercing clouds)
- [ ] Implement — Star fade-out (pre-dawn stars visible at Zone 1, gone by Zone 3)
- [ ] Implement — Rising Sun animation (slow arc movement from east horizon)
- [ ] Particle — Ice crystals at high altitude (sparse drifting ice shard particles)
- [ ] Audio — Altitude-based sound filter (low-pass filter increases with altitude — thin air)

---

## 📁 SECTION 5 — STORY FLOW & NARRATIVE

### 5.1 Narrative Script & Dialogue

- [ ] **Opening Cinematic (Pre-gameplay):**
  - [ ] Script — Anjana calling out to young Hanuman in the grove
  - [ ] Script — Hanuman's playful response, pointing at the sun
  - [ ] Script — Vayu's wind-whisper encouragement
  - [ ] Voice Actor (VA) direction brief — Anjana (warm, worried mother)
  - [ ] Voice Actor (VA) direction brief — Kid Hanuman (high-energy, gleeful child)
  - [ ] Voice Actor (VA) direction brief — Vayu (deep, echoing, warm)
  - [ ] Lip-sync animation pass for all 3 characters in opening cinematic

- [ ] **Mid-Mission Dialogue (Atmospheric — no player pause):**
  - [ ] Script — Hanuman taunting the clouds ("Move, clouds! I must have that mango!")
  - [ ] Script — Airavat's deep warning bellow (subtitled translated roar)
  - [ ] Script — Indra's warning speech before fight ("Who dares enter the solar path?")
  - [ ] Script — Hanuman's cheeky reply to Indra
  - [ ] VA brief + recording session specs for all mid-mission lines

- [ ] **The Vajra Strike & Boon Sequence (Cinematic):**
  - [ ] Script — Brahma's divine proclamation of boons (voice-over narration)
  - [ ] Script — Sage council's curse narration (somber tone, overlapping voices)
  - [ ] Script — Hanuman's dazed whisper as powers fade ("What... was I... doing?")
  - [ ] Full cinematic storyboard (frame-by-frame visual reference)
  - [ ] Lip-sync pass for all cinematic characters

- [ ] **Mission End Transition (Reveal Cinematic):**
  - [ ] Script — Narrator (Valmiki voice) — spoken stanza from Ramayana
  - [ ] Storyboard — Camera pan from Rishyamukha Hill → across mountains → Sarayu river → Ayodhya palace → Rama's cradle
  - [ ] Music — Score transition from Hanuman's Raga Shankara theme → Rama's Raga Bhairav theme

---

### 5.2 Mission Flow & Checkpoint Structure

- [ ] Define — Checkpoint 1 placement: After collecting all 7 sacred fruits (grove cleared)
- [ ] Define — Checkpoint 2 placement: After completing all 3 windwheel puzzles (cliff top)
- [ ] Define — Checkpoint 3 placement: After clearing cloud platform field (entering storm arena)
- [ ] Define — Auto-save trigger: After Airavat boss defeated
- [ ] Define — Mission complete trigger: After Indra's crown is grabbed (cinematic starts)
- [ ] Implement — Vayu rescue cinematic trigger (fall below z < 4000m during ascent)
- [ ] Implement — Mission fail conditions (if player runs out of Vayu rescues — 3 rescues max)
- [ ] HUD — Mission objective tracker UI (shows current step: Collect Fruits → Climb → Reach Sun)

---

### 5.3 Collectibles & Lore Items

- [ ] Design — Lore Scroll 1: Vayu Shrine (mid-cliff) — "The Boons of Vayu" written scroll
- [ ] Design — Lore Scroll 2: Cloud Platform field — "The Celestial Highways of Devas"
- [ ] Design — Hidden Challenge: Find 3 secret star formations in the sky (constellation collectible)
- [ ] Design — Achievement: "First Leap" — Complete Mission 0 without using a Vayu rescue
- [ ] Design — Achievement: "Golden Stomach" — Collect all 7 fruits without dropping one

---

## 📁 SECTION 6 — UI & HUD ELEMENTS

- [ ] HUD — Health bar (playful, Vanara-themed design — fruit icons instead of HP bars)
- [ ] HUD — Stamina/Energy ring (tail glowing orange, drains on sprint and abilities)
- [ ] HUD — Mission Objective text (top-center, minimal)
- [ ] HUD — Altitude indicator (Mission 0 specific — shows current altitude in styled Sanskrit numerals)
- [ ] HUD — Vayu Rescue counter (3 icons of Vayu wind-leaf — loses 1 on each rescue)
- [ ] HUD — Sacred Fruit basket progress (fills as fruits are collected — 7/7)
- [ ] UI — Dialogue subtitles (Sanskrit text + English translation option)
- [ ] UI — Tutorial prompt cards (controller/keyboard glyph prompts for each new mechanic introduced)

---

## 📁 SECTION 7 — AUDIO DESIGN

### 7.1 Music / Score
- [ ] Compose — Mission 0 main exploration theme (Raga Shankara base — playful, wonder-filled)
- [ ] Compose — Airavat Boss Theme (thunderous percussion + elephant horn instruments)
- [ ] Compose — Indra Boss Theme (electrical storm orchestral — war drums + synth crackle)
- [ ] Compose — Vajra Strike cinematic score (sudden silence → single low drone → divine swell)
- [ ] Compose — Boon Sequence theme (multi-layered divine choir + veena + flute)
- [ ] Compose — Transition to Rama reveal (slow Raga Bhairav drone — peaceful, sacred)
- [ ] Record — All musical themes with live instruments where possible
- [ ] Mix & Master — All music stems (adaptive layering system for intensity changes)

### 7.2 Voice Acting
- [ ] Cast — Voice Actor for Kid Hanuman
- [ ] Cast — Voice Actor for Anjana (Mother)
- [ ] Cast — Voice Actor for Vayu (Wind Spirit — deep, booming)
- [ ] Cast — Voice Actor for Lord Indra
- [ ] Cast — Voice Actor for Brahma (Narration voice for boons)
- [ ] Cast — Voice Actor for Sage Council (multi-voice curse delivery)
- [ ] Record — All voice lines (studio session scheduled)
- [ ] Process — Audio cleaning, noise removal, mastering of all VO
- [ ] Implement — Dialogue trigger system in engine (proximity + cutscene triggers)

### 7.3 Sound Effects (SFX)
- [ ] SFX — Footstep variants (dirt, moss, rock, cloud)
- [ ] SFX — Jump whoosh (light child jump vs. powered super jump)
- [ ] SFX — Vine grab thwack + swing creak
- [ ] SFX — Thermal updraft column enter roar
- [ ] SFX — Cloud pad dissolve puff
- [ ] SFX — Fruit pick-up chime (gentle, satisfying)
- [ ] SFX — Basket fill progress sound (filling up with each fruit)
- [ ] SFX — Tyaksha chatter + seed throw + caught squeal
- [ ] SFX — Airavat roar (deep, layered elephant + brass horn)
- [ ] SFX — Airavat stomp (ground-shaking low frequency impact)
- [ ] SFX — Airavat trunk water blast
- [ ] SFX — Airavat sleep ZZZ (gentle, comedic)
- [ ] SFX — Indra chariot wheel rumble
- [ ] SFX — Indra Vajra charge-up (rising electrical buzz)
- [ ] SFX — Indra Vajra throw (crack + whistle + impact)
- [ ] SFX — Lightning ring ground wave (crackle sweep)
- [ ] SFX — Vajra body-strike (massive impact + screen ring)
- [ ] SFX — Boon descending (celestial shimmer + reverb swell)
- [ ] SFX — Aura fade-off (power drain hum descending)

---

## 📁 SECTION 8 — GAMEPLAY SYSTEMS & MECHANICS

### 8.1 Movement & Physics
- [ ] Implement — Kid Hanuman base locomotion state machine (idle, walk, run, sprint)
- [ ] Implement — Jump (single and double) with air time and gravity curve
- [ ] Implement — Glide state (spread arms, reduced gravity, lateral control)
- [ ] Implement — Tail Grapple system (aim, launch, latch, swing, release)
- [ ] Implement — Wall run system (horizontal and vertical surface run)
- [ ] Implement — Ledge grab + pull-up system
- [ ] Implement — Vine swing physics (pendulum simulation, momentum build)
- [ ] Implement — Thermal updraft column interaction (enter → vertical velocity applied)
- [ ] Implement — Cloud platform timer system (3-second stand → dissolve trigger)
- [ ] Implement — Wind vector field interaction (lateral push on character at altitude)
- [ ] Implement — Vayu Rescue system (fall detection → cinematic rescue → respawn)
- [ ] Implement — Altitude tracking variable (used for HUD, audio filter, and lighting triggers)

### 8.2 Combat
- [ ] Implement — Light punch combo (3-hit combo, timing windows)
- [ ] Implement — Heavy punch (charged input, wind-up delay, large knockback)
- [ ] Implement — Tail swipe (directional input, AOE sweep)
- [ ] Implement — Dodge roll system (i-frames duration, stamina cost)
- [ ] Implement — Tickle tackle (context-sensitive — only on Tyakshas, non-lethal)
- [ ] Implement — Enemy hit-react system (stagger, knockback, defeat states)

### 8.3 Boss Systems
- [ ] Implement — Airavat Boss Phase 1 (tusk grapple climbing mechanic + stomp dodge)
- [ ] Implement — Airavat Boss Phase 2 (trunk lash dodge + ear tickle context action)
- [ ] Implement — Airavat Boss health bar and phase threshold trigger (Phase 1 → Phase 2 at 50% HP)
- [ ] Implement — Indra Boss bullet-hell pattern (lightning spear + ring wave timing)
- [ ] Implement — Indra chariot orbit logic (smooth ellipse orbit with speed increase per phase)
- [ ] Implement — Indra crown grab (survival duration check → cinematic trigger)
- [ ] Implement — Boss arena boundary (wind-wall bounce-back system)

### 8.4 Puzzle Systems
- [ ] Implement — Windwheel rotate mechanic (player push input → stone rotation)
- [ ] Implement — Windwheel angle validation (correct angle unlocks updraft)
- [ ] Implement — Tyaksha fruit steal/return loop (imp grabs fruit → player catches → basket deposit)
- [ ] Implement — Tyaksha camouflage system (blend toggle, reveal on proximity)

### 8.5 Progression & Triggers
- [ ] Implement — Mission checkpoint save system (3 checkpoints + auto-save)
- [ ] Implement — Zone transition triggers (Zone 1 → 2 → 3 → 4 → Cinematic)
- [ ] Implement — Collectible lore scroll pickup + journal system
- [ ] Implement — Achievement trigger events
- [ ] Implement — Cinematic lock-in system (locks player input during cutscenes)
- [ ] Implement — Character transition swap (end cinematic → Rama reveal scene handoff)

---

## 📁 SECTION 9 — CINEMATICS & CUTSCENES

- [ ] Cinematic 1 — **Opening** (2–3 min): Anjana's grove, Hanuman sees the sun, Vayu's blessing, leap
- [ ] Cinematic 2 — **Airavat Intro** (30 sec): Airavat appears on cloud bridge, massive reveal shot
- [ ] Cinematic 3 — **Airavat Sleep** (15 sec): Hanuman tickles Airavat, giant sleeps comically
- [ ] Cinematic 4 — **Indra Confrontation** (45 sec): Indra appears on chariot, warning dialogue
- [ ] Cinematic 5 — **Vajra Strike & Fall** (1 min): Vajra hit, Hanuman falls, Vayu's rage, cosmos disturbance
- [ ] Cinematic 6 — **Boon Sequence** (1.5 min): Brahma + deities descend, grant boons, sages curse
- [ ] Cinematic 7 — **Transition Reveal** (45 sec): Aura fades, camera pans across landscape, Ayodhya reveal, baby Rama cries
- [ ] Storyboard — All 7 cinematics (full frame-by-frame director's storyboard)
- [ ] Animatic — All 7 cinematics (rough motion test before full animation)
- [ ] Full Animation Polish — All 7 cinematics (final-quality in-engine or pre-rendered)

---

## 📁 SECTION 10 — TECHNICAL & PIPELINE

### 10.1 Engine Setup (Mission 0 Specific)
- [ ] Scene — Create Mission 0 scene file in engine (SCENE_SUMERU_STRATOSPHERE)
- [ ] Setup — Zone volume system (defines which zone player is in for dynamic changes)
- [ ] Setup — Adaptive music system (Wwise / FMOD integration for layered music)
- [ ] Setup — Post-process volume stacking (per-zone color grading and DOF settings)
- [ ] Setup — Occlusion culling configuration for the vertical scene
- [ ] Setup — LOD system calibration (all assets LOD1/2/3 thresholds set)

### 10.2 Performance & Optimization
- [ ] Profile — Target frame rate: 60fps at 1080p / 30fps at 4K (console targets)
- [ ] Optimize — Vertex count budget: Character budget 120k tris, Boss budget 300k tris
- [ ] Optimize — Texture streaming setup (cloud assets streamed, not always resident)
- [ ] Optimize — Particle budget per zone (cap Niagara emitters by zone volume)
- [ ] Optimize — Physics simulation budget (cloth, tail, vine physics LOD)
- [ ] Test — Memory footprint target for Mission 0 (< 4GB VRAM on target hardware)

### 10.3 QA & Testing
- [ ] Test — Full playthrough of Mission 0 from start to end (dev build)
- [ ] Test — All 5 movement mechanics functioning correctly
- [ ] Test — All 3 windwheel puzzles solvable and validated
- [ ] Test — Cloud platform timer accuracy (exactly 3 seconds before dissolve)
- [ ] Test — Vayu rescue system fires correctly (3 rescues, mission fail after 3rd)
- [ ] Test — Airavat boss both phases complete correctly
- [ ] Test — Indra boss survival timer and crown grab trigger correctly
- [ ] Test — All 7 cinematics play without stuttering
- [ ] Test — Character transition handoff (Hanuman → Rama reveal) plays correctly
- [ ] Test — All collectibles are pickable and logged in journal
- [ ] Test — All achievements trigger correctly
- [ ] Test — No collision clipping bugs on vine swing + wall run
- [ ] Test — Audio zones transition smoothly (no audio pop between zones)
- [ ] Bug fix — Address all P1 and P2 bugs found in test pass

---

## 📁 SECTION 11 — ADDITIONAL ITEMS (BEYOND ORIGINAL SCOPE)

*These items were identified as missing from the original brief and are essential for a complete, professional-quality Mission 0:*

- [ ] **Accessibility Settings** — Colorblind mode (lightning contrast), subtitle font scaling, input remapping
- [ ] **Tutorial Prompt System** — Context-aware prompts for each new mechanic (first vine, first thermal, first grapple)
- [ ] **Photo Mode** — Implement photo mode with pose selector for Kid Hanuman (marketing content)
- [ ] **Language Localization** — English, Hindi, Tamil, Telugu subtitle packs for Mission 0 dialogue
- [ ] **Controller Rumble Design** — Haptic feedback map (Vajra strike = full rumble, footstep = subtle pulse)
- [ ] **Difficulty Settings** — Easy (slower lightning rings, extended cloud platform timers), Normal, Hard
- [ ] **Trailer Assets** — Extract Mission 0 hero moments for reveal/launch trailer (cloud leap, Vajra strike, Rama reveal)
- [ ] **Concept Art Book Page** — One full-page spread of Mission 0 for the game's art book
- [ ] **Speedrun Friendliness** — Identify and design optimal speedrun skip routes through Zone 2 cliff
- [ ] **Player Death Screen** — Themed death screen (Vayu wind visual, "The Sky forgives…" quote)
- [ ] **Loading Screen** — Mission 0 loading screen (Kid Hanuman leaping at the sun, Sanskrit quote overlay)

---

## 🗓️ SUGGESTED MILESTONE SCHEDULE

| Milestone | Key Deliverables | Target |
| :--- | :--- | :--- |
| **M0-Alpha** | Kid Hanuman rig + base animations, Scene blockout all 4 zones, Basic movement mechanics | Week 6 |
| **M0-Beta** | All character models textured, All boss mechanics implemented, All 3 puzzle types working | Week 12 |
| **M0-Gold-1** | All animations polished, All VFX implemented, All audio integrated | Week 18 |
| **M0-Gold-2** | All cinematics animated, QA pass complete, Performance targets met | Week 22 |
| **M0-Release** | Localization complete, Accessibility pass, Final cert submission | Week 24 |

---

*Document created by: Technical Planning Manager*
*Project: Ram-G — Game Based on the Bharat Mythical Story Ramayana*
*Version: 1.0 | Date: 2026-05-23*
