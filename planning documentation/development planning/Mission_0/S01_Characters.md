# S01 — Characters | Mission 0 Development Tasks

> **Mission:** Mission 0 — Hanuman's Solar Leap
> **Section:** Character Art, Modeling, Rigging & Animation

| Metric | Value |
|--------|-------|
| Total Tasks | 89 |
| Total Subtasks | 183 |
| 🤖 AI-Assisted Tasks | 38 (43%) |
| 🤝 AI+Human Tasks | 28 (31%) |
| 👤 Human-Only Tasks | 23 (26%) |
| Teams Involved | ART, 3D, RIG, ANIM, VFX |

---

## 1.1 Kid Hanuman (Primary Playable Character)

### 1.1.1 Character Design & Concept Art

- [ ] Full-body reference sheet (front, side, back views) `🤝 AI+H [Midjourney, DALL-E 3 + Art Director]` `[ART]`
  - [ ] Research Vanara anatomy and child proportions `🤖 AI [Claude, Gemini]` `[ART]`
  - [ ] Generate 10+ AI mood board variations `🤖 AI [Midjourney]` `[ART]`
  - [ ] Art director selects and refines best direction `👤 Human` `[ART]`
  - [ ] Final clean reference sheet painted `👤 Human` `[ART]`
- [ ] Facial expressions sheet (joy, mischief, surprise, determination, pain/fall) `🤝 AI+H [Midjourney + artist]` `[ART]`
  - [ ] Sketch 5 core expression poses `👤 Human` `[ART]`
  - [ ] Refine and ink final expressions `👤 Human` `[ART]`
- [ ] Post-nerf "Normal Monkey" appearance design `🤝 AI+H [Midjourney + artist]` `[ART]`
  - [ ] Design aura-off state, shrunken silhouette `👤 Human` `[ART]`
  - [ ] Create side-by-side comparison sheet `🤖 AI [Midjourney]` `[ART]`
- [ ] Fur color, pattern, and length specification doc `🤖 AI [Claude]` `[ART]`
  - [ ] Define golden-orange highlights, lighter chest palette `👤 Human` `[ART]`
  - [ ] Create color swatch reference file `🤝 AI+H [Adobe Firefly]` `[ART]`
- [ ] Scaling reference chart (Kid vs Adult Hanuman vs Anjana) `🤖 AI [Claude, DALL-E 3]` `[ART]`
  - [ ] Sketch proportional scale comparison `👤 Human` `[ART]`

### 1.1.2 3D Modeling

- [ ] Kid Hanuman base mesh (child-scaled Vanara, ~1.0m height) `🤝 AI+H [Meshy AI, CSM.ai + sculptor]` `[3D]`
  - [ ] Block out primary forms in ZBrush/Maya `👤 Human` `[3D]`
  - [ ] High-poly sculpt (fur texture bake surface, facial detail) `👤 Human` `[3D]`
  - [ ] Retopology to game-ready low-poly mesh `👤 Human` `[3D]`
  - [ ] UV unwrap all mesh pieces `👤 Human` `[3D]`
  - [ ] Bake high→low maps (normal, AO, curvature) `🤖 AI [Marmoset Toolbag auto-bake]` `[3D]`
- [ ] Tail mesh (separate bone-driven, physics simulation) `👤 Human` `[3D]`
  - [ ] Model tail with natural taper and fur volume `👤 Human` `[3D]`
  - [ ] UV unwrap tail mesh `👤 Human` `[3D]`
  - [ ] Bake detail maps from high-poly `🤖 AI [Marmoset auto-bake]` `[3D]`
- [ ] Clothing/loincloth + sacred thread (Yajnopavita) + jewelry `🤝 AI+H [CSM.ai + artist]` `[3D]`
  - [ ] Model loincloth with cloth simulation setup points `👤 Human` `[3D]`
  - [ ] Model sacred thread bead details `👤 Human` `[3D]`
- [ ] Mango Basket prop (held quest object) `🤖 AI [Meshy AI]` `[3D]`
  - [ ] Generate base mesh with AI `🤖 AI [Meshy AI]` `[3D]`
  - [ ] Refine weave pattern detail, UV, bake `👤 Human` `[3D]`
- [ ] LOD1 generation (50% poly reduction) `🤖 AI [InstaLOD, AutoLOD tools]` `[3D]`
- [ ] LOD2 generation (25% of original) `🤖 AI [InstaLOD]` `[3D]`

### 1.1.3 Rigging & Skinning

- [ ] Full body skeleton rig (biped + 6-bone tail chain) `👤 Human` `[RIG]`
  - [ ] Build spine hierarchy (pelvis → chest → neck → head) `👤 Human` `[RIG]`
  - [ ] Build limb IK/FK chains (arms, legs) `👤 Human` `[RIG]`
  - [ ] Build 6-segment tail bone chain `👤 Human` `[RIG]`
  - [ ] Set rotation limits and joint orientations `👤 Human` `[RIG]`
- [ ] Facial rig (jaw, brow, cheek, eye orbit — blend-shape driven) `👤 Human` `[RIG]`
  - [ ] Create blend-shape targets for all 5 expressions `👤 Human` `[RIG]`
  - [ ] Add corrective blend-shapes for jaw/cheek intersections `👤 Human` `[RIG]`
- [ ] IK/FK system for arms (grapple hook reach transitions) `👤 Human` `[RIG]`
- [ ] Tail physics simulation rig (secondary motion) `👤 Human` `[RIG]`
  - [ ] Set up dynamic chain with spring/damper values `👤 Human` `[RIG]`
  - [ ] Test physics response in engine, tune parameters `👤 Human` `[RIG]`
- [ ] Skinning — weight paint full body `👤 Human` `[RIG]`
  - [ ] Initial weight paint pass `🤖 AI [Maya auto-weight]` `[RIG]`
  - [ ] Manual correction pass at problem joints (shoulder, knee, wrist) `👤 Human` `[RIG]`
  - [ ] QA deformation test (extreme pose check) `👤 Human` `[RIG]`

### 1.1.4 Texturing & Materials

- [ ] Albedo (Base Color) map — fur, skin, cloth (4K) `🤝 AI+H [Adobe Firefly, Stable Diffusion + texture artist]` `[ART]`
  - [ ] Generate base fur pattern with AI `🤖 AI [Adobe Firefly]` `[ART]`
  - [ ] Paint skin tones, cloth, bead details by hand `👤 Human` `[ART]`
  - [ ] Composite and finalize in Photoshop/Substance `👤 Human` `[ART]`
- [ ] Roughness / Metallic map `🤝 AI+H [Substance AI + artist]` `[ART]`
  - [ ] Generate roughness from albedo with AI `🤖 AI [Substance AI]` `[ART]`
  - [ ] Manually adjust metallic regions (beads, thread) `👤 Human` `[ART]`
- [ ] Normal map — fur strands, facial micro-detail `🤝 AI+H [Stable Diffusion depth + artist]` `[ART]`
  - [ ] Bake normals from high-poly sculpt `🤖 AI [Marmoset auto-bake]` `[ART]`
  - [ ] Add fabric fiber detail via Substance Painter `👤 Human` `[ART]`
- [ ] Subsurface Scattering (SSS) map — ear rims, finger pads, nose `👤 Human` `[ART]`
- [ ] Ambient Occlusion map `🤖 AI [Marmoset auto-bake]` `[ART]`
- [ ] Emissive map — golden aura glow state (pre-nerf) `🤝 AI+H [Adobe Firefly + artist]` `[ART]`
  - [ ] Design aura gradient pattern `👤 Human` `[ART]`
  - [ ] Set emissive intensity values for engine `👤 Human` `[ART]`
- [ ] Fur strand shader (anisotropic, wind-reactive shell layering) `👤 Human` `[TECH-ART]`
  - [ ] Build shader node graph in engine `👤 Human` `[TECH-ART]`
  - [ ] Tune shell count, fur length, wind response `👤 Human` `[TECH-ART]`
- [ ] Subsurface skin shader (child-like warmth tone) `👤 Human` `[TECH-ART]`
- [ ] Golden aura overlay material (particle-driven, fades on nerf) `🤝 AI+H [Claude for shader logic + artist]` `[TECH-ART]`

### 1.1.5 Animations — Locomotion

- [ ] Idle — Playful rock-shift, tail swish (8-sec loop) `👤 Human` `[ANIM]`
  - [ ] Reference footage collection (child movement refs) `🤖 AI [Claude reference search]` `[ANIM]`
  - [ ] Rough block-out keys `👤 Human` `[ANIM]`
  - [ ] Spline and timing polish `👤 Human` `[ANIM]`
  - [ ] Engine import + blend tree integration `👤 Human` `[ANIM]`
- [ ] Idle Variation 1 — Sniff air, scratch ear `👤 Human` `[ANIM]`
  - [ ] Block, polish, import `👤 Human` `[ANIM]`
- [ ] Idle Variation 2 — Balance on one foot, grin `👤 Human` `[ANIM]`
- [ ] Walk — Bouncy child-like amble `👤 Human` `[ANIM]`
  - [ ] Block root motion path `👤 Human` `[ANIM]`
  - [ ] Polish foot contacts and weight shift `👤 Human` `[ANIM]`
  - [ ] Engine import + locomotion blend setup `👤 Human` `[ANIM]`
- [ ] Run — Fast barefoot sprint with tail trailing `👤 Human` `[ANIM]`
  - [ ] Block, polish, import with tail secondary motion `👤 Human` `[ANIM]`
- [ ] Sprint (Full Speed) — Lean forward, wind effect `👤 Human` `[ANIM]`
- [ ] Jump — Single jump, big knee-launch `👤 Human` `[ANIM]`
  - [ ] Anticipation, apex, fall phases `👤 Human` `[ANIM]`
  - [ ] Engine import + state machine connection `👤 Human` `[ANIM]`
- [ ] Double Jump — Mid-air spin kick before second launch `👤 Human` `[ANIM]`
- [ ] Glide — Arms and legs spread, tail as rudder `👤 Human` `[ANIM]`
- [ ] Land (Soft) — Crouch-absorb with grin `👤 Human` `[ANIM]`
- [ ] Land (Hard) — Shockwave crouch, dust burst `👤 Human` `[ANIM]`
- [ ] Fall — Tumble, arms flailing `👤 Human` `[ANIM]`
- [ ] Crouch Idle `👤 Human` `[ANIM]`
- [ ] Crouch Walk — Sneaking toe-walk `👤 Human` `[ANIM]`

### 1.1.5 Animations — Climbing & Traversal

- [ ] Vine Grab — Reach and lock `👤 Human` `[ANIM]`
- [ ] Vine Swing — L-R pendulum, building momentum `👤 Human` `[ANIM]`
- [ ] Vine Drop — Release and fall `👤 Human` `[ANIM]`
- [ ] Wall Run — Vertical `👤 Human` `[ANIM]`
- [ ] Wall Run — Horizontal `👤 Human` `[ANIM]`
- [ ] Wall Jump — Push-off rotate `👤 Human` `[ANIM]`
- [ ] Ledge Grab — Catch and hang `👤 Human` `[ANIM]`
- [ ] Ledge Pull-Up — Slow variant `👤 Human` `[ANIM]`
- [ ] Ledge Pull-Up — Fast variant `👤 Human` `[ANIM]`
- [ ] Tail Grapple Launch — Tail shoots out to anchor `👤 Human` `[ANIM]`
- [ ] Tail Grapple Swing Arc `👤 Human` `[ANIM]`
- [ ] Tail Grapple Release `👤 Human` `[ANIM]`
- [ ] Cloud Pad Land — Bounce springy `👤 Human` `[ANIM]`
- [ ] Thermal Updraft Enter — Feet leave ground, hover spin `👤 Human` `[ANIM]`
- [ ] Thermal Updraft Float — Rotating hover loop `👤 Human` `[ANIM]`
- [ ] Thermal Updraft Exit — Blast upward launch `👤 Human` `[ANIM]`

### 1.1.5 Animations — Combat

- [ ] Light Punch — Fast 1-2-3 combo sequence `👤 Human` `[ANIM]`
  - [ ] Block all 3 hit poses `👤 Human` `[ANIM]`
  - [ ] Polish timing and impact frames `👤 Human` `[ANIM]`
  - [ ] Import into combo state machine `👤 Human` `[ANIM]`
- [ ] Heavy Punch — Wind-up overhead slam `👤 Human` `[ANIM]`
- [ ] Tail Swipe (Low) — 180° arc knockback `👤 Human` `[ANIM]`
- [ ] Tail Uppercut — Upward flick `👤 Human` `[ANIM]`
- [ ] Dodge Roll — Forward somersault `👤 Human` `[ANIM]`
- [ ] Dodge Roll — Side cartwheel `👤 Human` `[ANIM]`
- [ ] Tickle Tackle — Jump-pounce non-lethal subdual `👤 Human` `[ANIM]`
- [ ] Fruit Basket Catch — Return fruit animation `👤 Human` `[ANIM]`
- [ ] Hit Reaction — Stagger Light `👤 Human` `[ANIM]`
- [ ] Hit Reaction — Knockback Heavy `👤 Human` `[ANIM]`

### 1.1.5 Animations — Boss-Specific

- [ ] Airavat Tusk Grab — Hands latch, feet scramble `👤 Human` `[ANIM]`
- [ ] Airavat Neck Scale — Pulling up fur climbing `👤 Human` `[ANIM]`
- [ ] Airavat Ear Tickle — Reach and tickle with belly laugh `👤 Human` `[ANIM]`
- [ ] Indra Chariot Grab — Both hands clench chariot rim `👤 Human` `[ANIM]`
- [ ] Indra Crown Grab — One arm reach-and-snatch `👤 Human` `[ANIM]`
- [ ] Dodge Lightning Ring — Dive-roll with timing cue `👤 Human` `[ANIM]`

### 1.1.5 Animations — Narrative & Cutscene

- [ ] Point at Sun (mistaking it for a mango) `👤 Human` `[ANIM]`
- [ ] Big open-mouth child laugh `👤 Human` `[ANIM]`
- [ ] Fear Reaction — Eyes wide, tail between legs `👤 Human` `[ANIM]`
- [ ] Vajra Strike — Full body hit, spin, fall `👤 Human` `[ANIM]`
- [ ] Unconscious Fall to Earth (long-form cinematic) `👤 Human` `[ANIM]`
- [ ] Receiving Divine Boons — Floating, aura rises `👤 Human` `[ANIM]`
- [ ] Post-Nerf Sit — Peaceful normal monkey idle `👤 Human` `[ANIM]`
- [ ] Camera Pan Exit — Kid Hanuman sitting, camera pulls `👤 Human` `[ANIM]`

### 1.1.6 Character VFX

- [ ] Golden-orange aura particle system (pre-nerf state) `🤝 AI+H [Houdini AI + VFX artist]` `[VFX]`
  - [ ] Design particle emitter shape and density `👤 Human` `[VFX]`
  - [ ] Set emissive glow parameters `👤 Human` `[VFX]`
  - [ ] Engine import and attach to character root `👤 Human` `[VFX]`
- [ ] Aura fade-out on nerf (dissolve + particle drain downward) `👤 Human` `[VFX]`
- [ ] Sprint trail (golden wind streaks, motion blur) `🤝 AI+H [Niagara + VFX artist]` `[VFX]`
- [ ] Double jump shockwave ring (compressed air burst) `🤝 AI+H [Niagara + VFX artist]` `[VFX]`
- [ ] Tail whip swipe trail (golden arc) `🤝 AI+H [Niagara + VFX artist]` `[VFX]`
- [ ] Thermal updraft enter (body glow pulse + spiraling air) `👤 Human` `[VFX]`
- [ ] Vajra strike impact (blue-white electric discharge, screen flash) `👤 Human` `[VFX]`
- [ ] Boon receive (multi-colored divine light showers from above) `🤝 AI+H [Houdini AI + VFX artist]` `[VFX]`

---

## 1.2 Anjana (Mother — NPC)

- [ ] Concept art — Anjana full-body (gentle Vanara woman, maternal) `🤝 AI+H [Midjourney + artist]` `[ART]`
  - [ ] AI mood board (5 variations) `🤖 AI [Midjourney]` `[ART]`
  - [ ] Final painted reference `👤 Human` `[ART]`
- [ ] 3D base mesh (no combat, expressive upper body) `🤝 AI+H [Meshy AI + modeler]` `[3D]`
  - [ ] Block, sculpt, retopo, UV `👤 Human` `[3D]`
- [ ] Rig — Upper body expressive rig + basic full body walk `👤 Human` `[RIG]`
- [ ] Textures — Albedo, Roughness, Normal (2K) `🤝 AI+H [Adobe Firefly + artist]` `[ART]`
- [ ] Animations:
  - [ ] Idle — Arms crossed, watchful `👤 Human` `[ANIM]`
  - [ ] Call Out — Hand to mouth pose `👤 Human` `[ANIM]`
  - [ ] Reach Out — Arms extended in worry `👤 Human` `[ANIM]`
  - [ ] Wave Farewell `👤 Human` `[ANIM]`
  - [ ] Dialogue phoneme blend-shapes `🤝 AI+H [Speech Graphics AI + animator]` `[ANIM]`

---

## 1.3 Lord Indra (Boss — Sky Arena)

### 1.3.1 Design & Concept Art

- [ ] Concept art — Indra full-body battle regalia `🤝 AI+H [Midjourney + artist]` `[ART]`
  - [ ] AI mood board (8 variations, regal + thunderous) `🤖 AI [Midjourney]` `[ART]`
  - [ ] Art director selection and refinement `👤 Human` `[ART]`
  - [ ] Final painted reference sheet `👤 Human` `[ART]`
- [ ] Concept art — Indra's Golden Chariot (airborne Vimana) `🤝 AI+H [Midjourney + artist]` `[ART]`
- [ ] Concept art — Indra expressions sheet (arrogance, fury, warning, awe) `🤝 AI+H [DALL-E 3 + artist]` `[ART]`
- [ ] Vajra weapon design spec (multi-pronged, crackling) `🤝 AI+H [Midjourney + artist]` `[ART]`

### 1.3.2 3D Modeling

- [ ] Indra character base mesh + armor `👤 Human` `[3D]`
  - [ ] Block out, high-poly sculpt, retopo, UV, bake `👤 Human` `[3D]`
- [ ] Vajra weapon model (crackling multi-pronged thunderbolt) `🤝 AI+H [Meshy AI + modeler]` `[3D]`
  - [ ] Generate base form with AI, refine detail by hand `👤 Human` `[3D]`
- [ ] Golden Chariot / Vimana platform model `👤 Human` `[3D]`
  - [ ] Block, model architectural details, UV, bake `👤 Human` `[3D]`
- [ ] LOD variants for Indra + Chariot `🤖 AI [InstaLOD]` `[3D]`

### 1.3.3 Rigging & Animation

- [ ] Full body rig + armor physics simulation `👤 Human` `[RIG]`
- [ ] Cape/cloak secondary physics `👤 Human` `[RIG]`
- [ ] Animations:
  - [ ] Idle on Chariot — commanding stance `👤 Human` `[ANIM]`
  - [ ] Chariot Drive — standing, arms on reins `👤 Human` `[ANIM]`
  - [ ] Vajra Throw — wind-up, launch, recall `👤 Human` `[ANIM]`
  - [ ] Lightning Spear Cast — charge pose, discharge `👤 Human` `[ANIM]`
  - [ ] Lightning Ring Stomp — slam floor, rings radiate `👤 Human` `[ANIM]`
  - [ ] Warning Point — point at Hanuman pre-attack `👤 Human` `[ANIM]`
  - [ ] Rage Escalation — arms spread, storm intensifies `👤 Human` `[ANIM]`
  - [ ] Stagger — crown grabbed by Hanuman `👤 Human` `[ANIM]`
  - [ ] Post-Battle Regret — arms lower, expression shifts `👤 Human` `[ANIM]`

### 1.3.4 Texturing & Materials

- [ ] Albedo — gold armor, blue skin, white beard `🤝 AI+H [Adobe Firefly + artist]` `[ART]`
- [ ] Normal + Roughness + Emissive (lightning veins on armor) `🤝 AI+H [Substance AI + artist]` `[ART]`
- [ ] Lightning arc material — scrolling UV electric shader on Vajra `👤 Human` `[TECH-ART]`
- [ ] Storm-cloud cloak volumetric material `👤 Human` `[TECH-ART]`

### 1.3.5 VFX

- [ ] Vajra arc lightning trails `🤝 AI+H [Houdini AI + VFX artist]` `[VFX]`
- [ ] Lightning ring ground wave (radial shockwave, z-crackling) `👤 Human` `[VFX]`
- [ ] Storm field background (thunder + dark cloud volume) `🤝 AI+H [Houdini AI + VFX artist]` `[VFX]`
- [ ] Chariot propulsion jets (gold flame exhaust) `🤝 AI+H [Niagara + VFX artist]` `[VFX]`
- [ ] Vajra charge glow pulse (pre-throw power build) `👤 Human` `[VFX]`

---

## 1.4 Airavat (Boss — Cloud Bridge)

### 1.4.1 Design & Concept Art

- [ ] Concept art — Airavat full body (Celestial White Elephant, 3× scale) `🤝 AI+H [Midjourney + artist]` `[ART]`
  - [ ] Reference real elephant anatomy, scale up 3× `🤖 AI [Claude reference]` `[ART]`
  - [ ] AI mood board (6 variations) `🤖 AI [Midjourney]` `[ART]`
  - [ ] Final painted reference `👤 Human` `[ART]`
- [ ] Concept art — Gold regalia (anklets, crown jewel, trappings) `🤝 AI+H [Midjourney + artist]` `[ART]`
- [ ] Boss phase breakdown sketches (tusk climb, trunk lash phases) `👤 Human` `[ART]`

### 1.4.2 3D Modeling

- [ ] Airavat base mesh (colossal elephant, pearl/white skin) `👤 Human` `[3D]`
  - [ ] Block rough form, sculpt, retopo, UV, bake `👤 Human` `[3D]`
- [ ] Gold regalia armor / jewelry overlay `🤝 AI+H [Meshy AI + modeler]` `[3D]`
- [ ] Airavat tusks — separate dynamic objects for grapple `👤 Human` `[3D]`
  - [ ] Model tusks as separate grapple-surface meshes `👤 Human` `[3D]`
- [ ] LOD variants `🤖 AI [InstaLOD]` `[3D]`

### 1.4.3 Rigging & Animation

- [ ] Full elephant skeleton rig (trunk IK chain, ears, tail) `👤 Human` `[RIG]`
  - [ ] Trunk IK — 12-bone chain with spline IK `👤 Human` `[RIG]`
  - [ ] Ear secondary physics `👤 Human` `[RIG]`
- [ ] Tusk separate bone chain (player can climb surface) `👤 Human` `[RIG]`
- [ ] Animations:
  - [ ] Walk / Charge across cloud bridge `👤 Human` `[ANIM]`
  - [ ] Stomp Left Foot — ground crack shockwave `👤 Human` `[ANIM]`
  - [ ] Stomp Right Foot `👤 Human` `[ANIM]`
  - [ ] Trunk Sweep — low ground sweep `👤 Human` `[ANIM]`
  - [ ] Trunk Lash — overhead whip slam `👤 Human` `[ANIM]`
  - [ ] Water Blast — trunk curl, spray forward `👤 Human` `[ANIM]`
  - [ ] Tusk Shake — shake player off tusk `👤 Human` `[ANIM]`
  - [ ] Ear Flap — defensive flap attack `👤 Human` `[ANIM]`
  - [ ] Sleep Fall — knees buckle, side collapse (tickle defeat) `👤 Human` `[ANIM]`

### 1.4.4 Texturing & Materials

- [ ] Albedo — pearl white, gold jewelry, bioluminescent veins `🤝 AI+H [Adobe Firefly + artist]` `[ART]`
- [ ] Normal, Roughness, Emissive maps `🤝 AI+H [Substance AI + artist]` `[ART]`
- [ ] Pearl/iridescent skin shader `👤 Human` `[TECH-ART]`
- [ ] Gold regalia PBR metallic shader `🤝 AI+H [Substance AI + tech artist]` `[TECH-ART]`

### 1.4.5 VFX

- [ ] Stomp cloud crack (cloud splits, electric dust burst) `👤 Human` `[VFX]`
- [ ] Trunk water blast (high-pressure water cone, Niagara) `🤝 AI+H [Houdini AI + VFX artist]` `[VFX]`
- [ ] Sleep particles (ZZZ bubbles — playful, child-friendly) `🤖 AI [Niagara template + VFX artist tweak]` `[VFX]`
- [ ] Bioluminescent vein pulse (escalates with anger — phase 2) `👤 Human` `[VFX]`
- [ ] Tusk impact sparks (when Hanuman kicks off tusk) `🤖 AI [Niagara template]` `[VFX]`

---

## 1.5 Vayu (Voice/Wind Spirit — Unseen NPC)

- [ ] Wind spirit visualization concept (swirling air silhouette, no solid form) `🤝 AI+H [Midjourney + artist]` `[ART]`
  - [ ] Define visual language (translucent, leaf-and-petal form) `👤 Human` `[ART]`
  - [ ] Create reference mood board `🤖 AI [Midjourney]` `[ART]`
- [ ] Dialogue script finalization (3 voiced lines in Mission 0) `🤖 AI [Claude + writer review]` `[WRITE]`
- [ ] VFX — Vayu's presence (localized wind spiral, leaves/petals) `🤝 AI+H [Niagara + VFX artist]` `[VFX]`
  - [ ] Design leaf/petal emitter shape and orbit `👤 Human` `[VFX]`
  - [ ] Add fatherly silhouette shimmer effect `👤 Human` `[VFX]`
- [ ] Voice acting direction brief (deep, resonant, warm paternal) `🤖 AI [Claude]` `[VO]`

---

## 1.6 Tyakshas (Enemy Mobs — Orchard Chase)

- [ ] Concept art — Tyaksha (small forest imp, green, leaf-camouflage) `🤝 AI+H [Midjourney + artist]` `[ART]`
  - [ ] Generate 6 variation AI concepts `🤖 AI [Midjourney]` `[ART]`
  - [ ] Refine selected design `👤 Human` `[ART]`
- [ ] 3D model — Tyaksha base mesh `🤝 AI+H [Meshy AI + modeler]` `[3D]`
  - [ ] Block, sculpt, retopo, UV, bake `👤 Human` `[3D]`
- [ ] Rig — Biped rig (fast, spring-loaded joints) `👤 Human` `[RIG]`
- [ ] Textures — Albedo, Normal, Roughness + camouflage variant `🤝 AI+H [Adobe Firefly + artist]` `[ART]`
  - [ ] Base texture pass `🤖 AI [Adobe Firefly]` `[ART]`
  - [ ] Camouflage blend color variant `👤 Human` `[ART]`
- [ ] Animations:
  - [ ] Idle — Shifty look around `👤 Human` `[ANIM]`
  - [ ] Run — Lopsided fast scurry `👤 Human` `[ANIM]`
  - [ ] Double Jump — Spring legs `👤 Human` `[ANIM]`
  - [ ] Camouflage Blend — Color shift toggle `🤝 AI+H [shader blend + animator]` `[ANIM]`
  - [ ] Seed Throw — Wind-up pitch-and-throw `👤 Human` `[ANIM]`
  - [ ] Hit/Tackled — Stumble, drop fruit, laugh `👤 Human` `[ANIM]`
  - [ ] Caught — Held upside down by tail, wriggling `👤 Human` `[ANIM]`
- [ ] VFX — Seed throw projectile + thorn prickle impact `🤝 AI+H [Niagara + VFX artist]` `[VFX]`
- [ ] VFX — Camouflage shimmer (chromatic aberration shimmer) `🤝 AI+H [shader + VFX artist]` `[VFX]`
