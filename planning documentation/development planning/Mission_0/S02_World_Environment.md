# S02 — World & Environment | Mission 0 Development Tasks

> **Mission:** Mission 0 — Hanuman's Solar Leap
> **Section:** Level Design, Environment Art, Lighting & Atmosphere

| Metric | Value |
|--------|-------|
| Total Tasks | 62 |
| Total Subtasks | 127 |
| 🤖 AI-Assisted Tasks | 22 (35%) |
| 🤝 AI+Human Tasks | 24 (39%) |
| 👤 Human-Only Tasks | 16 (26%) |
| Teams Involved | ART, 3D, TECH-ART, DESIGN, VFX |

---

## 2.1 Mount Sumeru — Orchards (Zone 1 — Ground Level)

### 2.1.1 Layout & Level Design

- [ ] Paper design — Orchard zone footprint and flow map (300m × 300m) `🤝 AI+H [Claude for flow logic + level designer]` `[DESIGN]`
  - [ ] Sketch top-down layout with fruit tree placement, vine routes, stone arches `👤 Human` `[DESIGN]`
  - [ ] Define player path from Anjana's hut to Sumeru cliff base `👤 Human` `[DESIGN]`
  - [ ] Review pacing — ensure imp chase fits within 5-minute window `👤 Human` `[DESIGN]`
- [ ] Engine blockout — Grey-box Zone 1 in engine `👤 Human` `[DESIGN]`
  - [ ] Place primitive collision volumes for all traversal surfaces `👤 Human` `[DESIGN]`
  - [ ] Test vine swing paths and grapple arcs `👤 Human` `[DESIGN]`
- [ ] Prop placement pass — Distribute trees, arches, shrines `🤝 AI+H [Claude for density rules + designer]` `[DESIGN]`
- [ ] Playtest and iterate — Adjust layout based on playtest feedback `👤 Human` `[DESIGN]`

### 2.1.2 3D Environment Assets

- [ ] Tropical fruit trees — mango, banana, sacred amla (3 variants each) `🤝 AI+H [Meshy AI + modeler]` `[3D]`
  - [ ] AI-generate base tree form `🤖 AI [Meshy AI]` `[3D]`
  - [ ] Hand-sculpt trunk bark detail and root flare `👤 Human` `[3D]`
  - [ ] Retopo, UV unwrap, bake `👤 Human` `[3D]`
  - [ ] LOD1 and LOD2 `🤖 AI [InstaLOD]` `[3D]`
- [ ] Mossy stone arches (small, medium, large variants) `🤝 AI+H [Meshy AI + modeler]` `[3D]`
  - [ ] Block arch forms in engine, sculpt mossy surface `👤 Human` `[3D]`
  - [ ] Retopo and UV `👤 Human` `[3D]`
- [ ] Hanging vines (grapple-interactable, physics-simulated) `👤 Human` `[3D]`
  - [ ] Model vine segment with leaf clusters `👤 Human` `[3D]`
  - [ ] Set up physics chain/spline for swing `👤 Human` `[3D]`
- [ ] Sacred Fruit Basket (quest object at grove center) `🤖 AI [Meshy AI]` `[3D]`
  - [ ] AI-generate woven basket, refine weave detail `👤 Human` `[3D]`
- [ ] Anjana's Hut (background prop, warm golden interior glow) `🤝 AI+H [Meshy AI + modeler]` `[3D]`
  - [ ] Block, model thatched roof, wall panels `👤 Human` `[3D]`
  - [ ] Add interior glow light setup `👤 Human` `[3D]`
- [ ] Wildflowers and ground fern clusters (background dressing, hero + scatter variants) `🤖 AI [Meshy AI, SpeedTree]` `[3D]`
- [ ] Ancient stone Vayu shrine (small, sacred corner prop) `🤝 AI+H [Midjourney ref + modeler]` `[3D]`
  - [ ] Generate concept reference `🤖 AI [Midjourney]` `[ART]`
  - [ ] Model shrine base, deity relief, offering bowl `👤 Human` `[3D]`
- [ ] Creek bed with animated water flow `👤 Human` `[3D]`
  - [ ] Model creek terrain channel with embedded rocks `👤 Human` `[3D]`
  - [ ] Set up water shader (see S04 Water System) `👤 Human` `[TECH-ART]`
- [ ] Firefly particle system (ambient life — dusk-appropriate) `🤝 AI+H [Niagara + VFX artist]` `[VFX]`

### 2.1.3 Textures & Materials

- [ ] Tree bark texture set — mossy, tropical, PBR roughness (4K) `🤝 AI+H [Adobe Firefly + texture artist]` `[ART]`
  - [ ] AI-generate bark base albedo `🤖 AI [Adobe Firefly]` `[ART]`
  - [ ] Paint moss overlay, roots variation `👤 Human` `[ART]`
  - [ ] Normal, Roughness, AO maps `🤝 AI+H [Substance AI]` `[ART]`
- [ ] Leaf canopy texture (translucent SSS leaves, 4 color variants) `🤝 AI+H [Adobe Firefly + artist]` `[ART]`
  - [ ] Generate leaf atlas with alpha masks `🤖 AI [Adobe Firefly]` `[ART]`
  - [ ] Set up translucency / SSS shader in engine `👤 Human` `[TECH-ART]`
- [ ] Mossy stone texture (wet moss top layer, dry stone base) `🤝 AI+H [Stable Diffusion + artist]` `[ART]`
- [ ] Red-brown earth ground (with embedded root detail) `🤝 AI+H [Stable Diffusion + artist]` `[ART]`
- [ ] Sacred Fruit texture (emissive glow, amber-gold, normal bump) `🤝 AI+H [Adobe Firefly + artist]` `[ART]`
- [ ] Wind-reactive leaf shader (vertex displacement by wind vector) `👤 Human` `[TECH-ART]`
  - [ ] Build vertex shader wind node graph `👤 Human` `[TECH-ART]`
  - [ ] Hook to global wind vector field (see S04 Wind) `👤 Human` `[TECH-ART]`
- [ ] Flowing creek water shader (normal-scroll, foam edge) `👤 Human` `[TECH-ART]`

### 2.1.4 Atmospheric & Lighting

- [ ] Pre-dawn ambient sky dome (deep blue-purple, 5:15 AM) `🤝 AI+H [Skybox AI + tech artist]` `[TECH-ART]`
  - [ ] Configure HDRI sky with matching color temperature `👤 Human` `[TECH-ART]`
- [ ] Anjana's grove warm torch point lights (amber, 3m radius, flicker) `👤 Human` `[TECH-ART]`
  - [ ] Place 6 torch point lights at grove entry and hut `👤 Human` `[TECH-ART]`
  - [ ] Add subtle flicker animation curve `👤 Human` `[TECH-ART]`
- [ ] Sunrise god-ray shafts through tree canopy (volumetric) `👤 Human` `[TECH-ART]`
  - [ ] Configure volumetric directional light shaft intensity `👤 Human` `[TECH-ART]`
- [ ] Morning mist ground layer (particle-driven, low-lying) `🤝 AI+H [Niagara + VFX artist]` `[VFX]`
- [ ] Audio ambience Zone 1 — bird calls, crickets, creek babble, wind in leaves (see S07) `[AUDIO]`

---

## 2.2 Mount Sumeru — Peak Ascent (Zone 2 — Cliff Traversal)

### 2.2.1 Layout & Level Design

- [ ] Paper design — Vertical cliff face layout (0m to 4000m play-equivalent height) `🤝 AI+H [Claude for puzzle spacing + designer]` `[DESIGN]`
  - [ ] Map 3 mandatory windwheel puzzle positions on cliff `👤 Human` `[DESIGN]`
  - [ ] Map moving cloud platform route (timing sequence) `👤 Human` `[DESIGN]`
  - [ ] Define visual altitude milestones (color, temperature changes) `👤 Human` `[DESIGN]`
- [ ] Engine blockout — Grey-box Zone 2 vertical layout `👤 Human` `[DESIGN]`
  - [ ] Collision volumes for cliff faces, ledges, windwheels `👤 Human` `[DESIGN]`
  - [ ] Test updraft columns and cloud platform timing `👤 Human` `[DESIGN]`
- [ ] Windwheel puzzle design doc (3 puzzles, escalating complexity) `🤖 AI [Claude]` `[DESIGN]`
- [ ] Zone 2 playtest and iterate `👤 Human` `[DESIGN]`

### 2.2.2 3D Environment Assets

- [ ] Sumeru cliff face (massive layered geological strata, 4 altitude visual zones) `👤 Human` `[3D]`
  - [ ] Block macro cliff terrain shape `👤 Human` `[3D]`
  - [ ] Sculpt strata layering detail `👤 Human` `[3D]`
  - [ ] Retopo terrain mesh sections `👤 Human` `[3D]`
- [ ] Stone Windwheel (mechanical rotating stone disk with directional vanes) `🤝 AI+H [Meshy AI + modeler]` `[3D]`
  - [ ] Block base disk and vane arms `👤 Human` `[3D]`
  - [ ] Add engraved direction arrows and worn stone details `👤 Human` `[3D]`
  - [ ] Set up rotation pivot for gameplay `👤 Human` `[3D]`
- [ ] Cloud Platform (solid condensation disk, semi-transparent white puff) `🤝 AI+H [Meshy AI + modeler]` `[3D]`
  - [ ] Model puffy disk shape with rough cloud volume silhouette `👤 Human` `[3D]`
  - [ ] Apply dissolve shader (see Textures) `👤 Human` `[TECH-ART]`
- [ ] Thermal Updraft Column visual — rotating air column, heat haze `👤 Human` `[VFX]`
  - [ ] Design Niagara emitter for rotating heat haze particles `👤 Human` `[VFX]`
- [ ] Mountain Shrine (hidden lore collectible prop, Vayu shrine) `🤝 AI+H [Midjourney ref + modeler]` `[3D]`
- [ ] Eagle nest ledge (environmental storytelling prop) `🤖 AI [Meshy AI]` `[3D]`
- [ ] Frozen waterfall ice formation (landmark at mid-altitude) `🤝 AI+H [Meshy AI + modeler]` `[3D]`
  - [ ] Model ice column sheets with translucent shader setup `👤 Human` `[3D]`

### 2.2.3 Textures & Materials

- [ ] Rock strata texture — layered (red sediment base → grey granite apex) `🤝 AI+H [Stable Diffusion + artist]` `[ART]`
  - [ ] Generate 3 altitude-variant rock texture sets `🤖 AI [Stable Diffusion]` `[ART]`
  - [ ] Blend layers using height-based material `👤 Human` `[TECH-ART]`
- [ ] Ice crystal patches (upper cliff faces, cold tint) `🤝 AI+H [Adobe Firefly + artist]` `[ART]`
- [ ] Cloud Platform dissolve shader (opacity fades on 3-sec timer) `👤 Human` `[TECH-ART]`
  - [ ] Build dissolve material with timer input `👤 Human` `[TECH-ART]`
  - [ ] White → yellow → red warning color shift `👤 Human` `[TECH-ART]`
- [ ] Thermal updraft heat-haze shader (refraction, scrolling UV) `👤 Human` `[TECH-ART]`
- [ ] Stone windwheel painted stone shader (engraved arrows, clean carved surface) `🤝 AI+H [Substance AI + artist]` `[ART]`

### 2.2.4 Atmospheric & Lighting

- [ ] Sunrise gradient lighting (warm orange at cliff base → cooler blue at apex) `👤 Human` `[TECH-ART]`
  - [ ] Configure sky light gradient with altitude-based exposure blend `👤 Human` `[TECH-ART]`
- [ ] God-ray shafts from above (topdown dramatic light columns) `👤 Human` `[TECH-ART]`
- [ ] Thin cloud wisps at mid-altitude (opacity particle wisps) `🤝 AI+H [Niagara + VFX artist]` `[VFX]`
- [ ] Audio ambience Zone 2 — rising wind howl, thinning bird calls (see S07) `[AUDIO]`

---

## 2.3 Troposphere Cloud Deck (Zone 3 — Cloud Platforming)

### 2.3.1 Layout & Level Design

- [ ] Paper design — Horizontal cloud platform field (open sky arena) `🤝 AI+H [Claude + designer]` `[DESIGN]`
  - [ ] Map platform route with timing patterns (easy → medium → hard) `👤 Human` `[DESIGN]`
  - [ ] Define Rising Sun target position in far sky `👤 Human` `[DESIGN]`
  - [ ] Mark fall zones and Vayu rescue trigger planes `👤 Human` `[DESIGN]`
- [ ] Engine blockout — Grey-box Zone 3 `👤 Human` `[DESIGN]`
- [ ] Platform timing tuning playtest `👤 Human` `[DESIGN]`
- [ ] Zone 3 visual pacing review (ensure sense of altitude and scale) `👤 Human` `[DESIGN]`

### 2.3.2 3D Environment Assets

- [ ] Cloud Platform variants (small, medium, large condensation pads) `🤝 AI+H [Meshy AI + modeler]` `[3D]`
  - [ ] Model 3 size variants of puffy condensation disk `👤 Human` `[3D]`
  - [ ] Apply dissolve shader `👤 Human` `[TECH-ART]`
- [ ] Rising Sun asset (distant glowing golden sphere with lens flare) `🤝 AI+H [Niagara emitter + VFX artist]` `[VFX]`
  - [ ] Create large emissive sphere mesh `👤 Human` `[3D]`
  - [ ] Add lens flare and corona VFX `👤 Human` `[VFX]`
- [ ] Ice crystal cluster decorations (floating in cloud layer) `🤖 AI [Meshy AI]` `[3D]`
- [ ] Wind shear ribbon effects (visual directional wind guides for player) `🤝 AI+H [Niagara + VFX artist]` `[VFX]`
- [ ] Airavat pre-battle cloud bridge (solid massive cloud runway leading to boss arena) `👤 Human` `[3D]`
  - [ ] Model wide solid cloud surface, fluffy edge details `👤 Human` `[3D]`

### 2.3.3 Textures & Materials

- [ ] Cloud volumetric material (subsurface scatter, soft edge glow) `👤 Human` `[TECH-ART]`
  - [ ] Build cloud material shader with SSS `👤 Human` `[TECH-ART]`
  - [ ] Add animated wind-driven UV scroll `👤 Human` `[TECH-ART]`
- [ ] Cloud pad evaporate shader (puff + dissolve, timer-driven) `👤 Human` `[TECH-ART]`
- [ ] Atmospheric depth haze (distance-based opacity blue shift) `🤝 AI+H [Claude for math + tech artist]` `[TECH-ART]`
- [ ] Sun corona glow (emissive + post-process bloom, intense) `👤 Human` `[TECH-ART]`

### 2.3.4 Atmospheric & Lighting

- [ ] Full golden sunrise sky dome (horizon: orange → yellow → white) `🤝 AI+H [Skybox AI + tech artist]` `[TECH-ART]`
- [ ] Cloud undershadow (soft blue shadow on underside of pads) `👤 Human` `[TECH-ART]`
- [ ] High altitude atmospheric hum — reduced sound, muffled bass (see S07) `[AUDIO]`
- [ ] Audio — Roaring wind, distant celestial trumpet echoes (see S07) `[AUDIO]`

---

## 2.4 Upper Stratosphere & Storm Arena (Zone 4 — Boss Arena)

### 2.4.1 Layout & Level Design

- [ ] Paper design — Circular storm arena (radius 500m, open sky dome) `🤝 AI+H [Claude + designer]` `[DESIGN]`
  - [ ] Define Indra chariot ellipse orbit route `👤 Human` `[DESIGN]`
  - [ ] Map lightning ring spawn zones (radial floor markers) `👤 Human` `[DESIGN]`
  - [ ] Define arena wind-wall perimeter boundary `👤 Human` `[DESIGN]`
- [ ] Engine blockout — Circular arena with chariot rail path `👤 Human` `[DESIGN]`
- [ ] Boss pattern validation playtest (ring timing, chariot speed) `👤 Human` `[DESIGN]`
- [ ] Zone 4 difficulty review and sign-off `👤 Human` `[DESIGN]`

### 2.4.2 3D Environment Assets

- [ ] Storm cloud ceiling (dark roiling cumulonimbus volume above arena) `👤 Human` `[VFX]`
  - [ ] Configure volumetric cloud layer (dark, dense, turbulent) `👤 Human` `[VFX]`
  - [ ] Add animated lightning flash inside cloud volume `👤 Human` `[VFX]`
- [ ] Solar Gate (distant non-reachable golden arch in sky — narrative target) `🤝 AI+H [Midjourney ref + modeler]` `[3D]`
  - [ ] AI concept reference `🤖 AI [Midjourney]` `[ART]`
  - [ ] Model golden arch with divine engravings `👤 Human` `[3D]`
- [ ] Lightning spire towers (background props — natural discharge rods) `🤝 AI+H [Meshy AI + modeler]` `[3D]`
- [ ] Chariot energy trail (visible path of Indra's orbit) `🤝 AI+H [Niagara + VFX artist]` `[VFX]`

### 2.4.3 Textures & Materials

- [ ] Dark cumulonimbus cloud (heavy, blue-black, volumetric) `👤 Human` `[TECH-ART]`
- [ ] Electric arc material (UV-scrolled emissive blue-white crackling) `👤 Human` `[TECH-ART]`
  - [ ] Build scrolling emission shader for Vajra and arena floor `👤 Human` `[TECH-ART]`
- [ ] Arena floor cloud (solid but visually vaporous, storm-grey tint) `🤝 AI+H [Substance AI + tech artist]` `[TECH-ART]`

### 2.4.4 Atmospheric & Lighting

- [ ] Strobing lightning ambience (dynamic directional light, rapid random flash) `👤 Human` `[TECH-ART]`
  - [ ] Set up flash blueprint/script with randomized intervals `🤖 AI [GitHub Copilot, Claude]` `[ENG]`
- [ ] Indra chariot bloom glow (warm point light orbiting with chariot) `👤 Human` `[TECH-ART]`
- [ ] Ozone tint post-process (blue-green tint on lightning flash frames) `👤 Human` `[TECH-ART]`
- [ ] Audio — Rolling thunder, celestial war conch, chariot wheel roar (see S07) `[AUDIO]`
