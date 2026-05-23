# S04 — Nature Elements & Systems | Mission 0 Development Tasks

> **Mission:** Mission 0 — Hanuman's Solar Leap
> **Section:** Environmental Physics Systems — Wind, Light, Water, Earth, Fire/Electricity, Atmosphere

| Metric | Value |
|--------|-------|
| Total Tasks | 44 |
| Total Subtasks | 91 |
| 🤖 AI-Assisted Tasks | 14 (32%) |
| 🤝 AI+Human Tasks | 20 (45%) |
| 👤 Human-Only Tasks | 10 (23%) |
| Teams Involved | ENG, VFX, TECH-ART, AUDIO |

---

## 4.1 Wind System

- [ ] Design doc — Wind vector field spec for all 4 zones `🤖 AI [Claude]` `[DESIGN]`
  - [ ] Zone 1 (Orchard): 15 km/h gentle valley breeze direction vector `👤 Human` `[DESIGN]`
  - [ ] Zone 2 (Cliff): 40 km/h variable gusts with lateral push on character `👤 Human` `[DESIGN]`
  - [ ] Zone 3 (Cloud Deck): 80 km/h stratospheric drift — player must angle jumps `👤 Human` `[DESIGN]`
  - [ ] Zone 4 (Storm Arena): 120 km/h jet-stream + localized Indra storm bursts `👤 Human` `[DESIGN]`
- [ ] Implement — Global wind vector field system (zone-specific volumes) `🤖 AI [GitHub Copilot, Claude]` `[ENG]`
  - [ ] Wind volume actor with directional vector and intensity fields `🤖 AI [GitHub Copilot]` `[ENG]`
  - [ ] Character controller integration (lateral force applied per zone) `👤 Human` `[ENG]`
  - [ ] Wind intensity ramps smoothly at zone transitions `🤖 AI [GitHub Copilot]` `[ENG]`
- [ ] Implement — Foliage vertex shader wind response `👤 Human` `[TECH-ART]`
  - [ ] Build vertex displacement node graph driven by global wind vector `👤 Human` `[TECH-ART]`
  - [ ] Apply to all leaf, grass, and vine materials `👤 Human` `[TECH-ART]`
  - [ ] Tune displacement amplitude and frequency per plant type `👤 Human` `[TECH-ART]`
- [ ] Implement — Character cloth/cape physics driven by wind vector `👤 Human` `[TECH-ART]`
  - [ ] Attach cloth sim to Indra's cape and Hanuman's loincloth `👤 Human` `[TECH-ART]`
  - [ ] Tune spring and collision parameters `👤 Human` `[TECH-ART]`
- [ ] Implement — Wind audio layer (volume + pitch scales with zone/intensity) `🤝 AI+H [ElevenLabs SFX + audio engineer]` `[AUDIO]`
  - [ ] Design 4 wind loops (gentle → howl) `🤝 AI+H [ElevenLabs Sound FX + sound designer]` `[AUDIO]`
  - [ ] Set up Wwise/FMOD blend between states `👤 Human` `[AUDIO]`
- [ ] Implement — Wind visual particles (leaf spirals, dust, ice crystals by zone) `🤝 AI+H [Niagara + VFX artist]` `[VFX]`
  - [ ] Zone 1: leaf spiral emitter (slow, organic) `🤝 AI+H [Niagara template + VFX artist]` `[VFX]`
  - [ ] Zone 2: dust and cliff-grit particles (horizontal gust bursts) `👤 Human` `[VFX]`
  - [ ] Zone 3+4: ice crystal drift particles (sparse, fast) `👤 Human` `[VFX]`
- [ ] Implement — Vayu's Wind special system (directed personal updraft safety net) `👤 Human` `[ENG]`
  - [ ] Detect player fall below Z-threshold `🤖 AI [GitHub Copilot]` `[ENG]`
  - [ ] Trigger cinematic rescue sequence `👤 Human` `[ENG]`
  - [ ] Respawn player at last cloud platform with minor stamina penalty `🤖 AI [GitHub Copilot]` `[ENG]`
  - [ ] VFX — Upward spiral wind with fatherly silhouette shimmer `👤 Human` `[VFX]`
  - [ ] Rescue counter (max 3, mission fail at 4th) `🤖 AI [GitHub Copilot]` `[ENG]`

---

## 4.2 Light System

- [ ] Implement — Dynamic sky dome (time-of-day progression 5:15 AM → 6:30 AM) `🤝 AI+H [Skybox AI + tech artist]` `[TECH-ART]`
  - [ ] Set up time-of-day controller driving sky color + sun elevation `👤 Human` `[TECH-ART]`
  - [ ] Tie sky progression to mission zone transitions `🤖 AI [GitHub Copilot]` `[ENG]`
- [ ] Lighting — Pre-dawn blue-purple ambient → sunrise orange transition `👤 Human` `[TECH-ART]`
  - [ ] Animate ambient light color from 6500K → 2500K warm over mission runtime `👤 Human` `[TECH-ART]`
  - [ ] Ensure transition is imperceptible frame-to-frame `👤 Human` `[TECH-ART]`
- [ ] Lighting — Volumetric god-ray light shafts (through clouds + trees) `👤 Human` `[TECH-ART]`
  - [ ] Configure volumetric directional light with scattering intensity `👤 Human` `[TECH-ART]`
  - [ ] Test performance cost and optimize ray march steps `👤 Human` `[TECH-ART]`
- [ ] Lighting — Anjana's grove torch lights (amber point lights, 3m radius, flicker) `🤝 AI+H [Claude for flicker logic + tech artist]` `[TECH-ART]`
  - [ ] Place 6 point lights at torch positions `👤 Human` `[TECH-ART]`
  - [ ] Implement flicker animation (perlin noise on intensity) `🤖 AI [Claude, GitHub Copilot]` `[ENG]`
- [ ] Lighting — Sun disc glow emissive (intensity increases as player ascends) `👤 Human` `[TECH-ART]`
  - [ ] Link sun emissive intensity to player altitude variable `🤖 AI [GitHub Copilot]` `[ENG]`
- [ ] Lighting — Indra's lightning strobe (dynamic directional flicker during boss) `👤 Human` `[TECH-ART]`
  - [ ] Random interval flash system (0.2s – 0.8s between flashes) `🤖 AI [Claude, GitHub Copilot]` `[ENG]`
  - [ ] Blue-white color temperature on flash frames `👤 Human` `[TECH-ART]`
- [ ] Lighting — Airavat bioluminescent vein glow (phase-linked point lights in model) `👤 Human` `[TECH-ART]`
  - [ ] Embed point lights at vein junctions `👤 Human` `[TECH-ART]`
  - [ ] Link glow intensity to Airavat HP/phase variable `🤖 AI [GitHub Copilot]` `[ENG]`
- [ ] Post-Process — Bloom intensity increase with altitude `🤝 AI+H [Claude for curve math + tech artist]` `[TECH-ART]`
  - [ ] Create post-process volume stack per zone `👤 Human` `[TECH-ART]`
  - [ ] Tune bloom threshold and intensity per zone `👤 Human` `[TECH-ART]`
- [ ] Post-Process — Chromatic aberration on Vajra strike (screen impact frame) `👤 Human` `[TECH-ART]`
  - [ ] Trigger aberration for 0.5s on Vajra hit event `🤖 AI [GitHub Copilot]` `[ENG]`
- [ ] Post-Process — Color grading LUT per zone (warm golden / cold blue) `🤝 AI+H [Adobe Lightroom AI + tech artist]` `[TECH-ART]`
  - [ ] Create LUT for Zone 1 (warm, soft) `👤 Human` `[TECH-ART]`
  - [ ] Create LUT for Zone 4 (cold, high-contrast, electric) `👤 Human` `[TECH-ART]`
  - [ ] Blend LUTs at zone boundaries `🤖 AI [GitHub Copilot]` `[ENG]`

---

## 4.3 Water System

- [ ] Implement — Orchard creek (Zone 1) flowing shallow stream `👤 Human` `[TECH-ART]`
  - [ ] Model creek terrain channel with embedded rocks (see S02) `👤 Human` `[3D]`
  - [ ] Water surface normal-map scroll shader (dual UV layer) `👤 Human` `[TECH-ART]`
  - [ ] Subsurface pebble visibility (refraction depth fade) `👤 Human` `[TECH-ART]`
  - [ ] Foam edge shader at shoreline `🤝 AI+H [Substance AI + tech artist]` `[TECH-ART]`
- [ ] Audio — Creek babble SFX (3D positional, gentle) `🤝 AI+H [ElevenLabs Sound FX + sound designer]` `[AUDIO]`
  - [ ] Record/generate creek audio `🤝 AI+H [ElevenLabs Sound FX]` `[AUDIO]`
  - [ ] Place 3D audio source along creek path `👤 Human` `[AUDIO]`
- [ ] Physics — Splash particle on player creek contact `🤝 AI+H [Niagara + VFX artist]` `[VFX]`
  - [ ] Design splash emitter (radial water droplets + surface ripple) `👤 Human` `[VFX]`
  - [ ] Trigger on player foot overlap with water trigger volume `🤖 AI [GitHub Copilot]` `[ENG]`
- [ ] Implement — Airavat Trunk Water Blast (boss attack projectile system) `👤 Human` `[ENG]`
  - [ ] High-pressure cone water VFX (Niagara particle simulation) `🤝 AI+H [Houdini AI + VFX artist]` `[VFX]`
  - [ ] Collision detection — player knockback on water blast hit `👤 Human` `[ENG]`
  - [ ] Water blast audio (high-pressure hose blast + splash impact) `🤝 AI+H [ElevenLabs Sound FX + sound designer]` `[AUDIO]`

---

## 4.4 Earth / Ground System

- [ ] Implement — Ground deformation on heavy landing (temporary dent decal) `🤝 AI+H [Claude for decal logic + tech artist]` `[TECH-ART]`
  - [ ] Spawn temporary decal mesh on hard-land event `🤖 AI [GitHub Copilot]` `[ENG]`
  - [ ] Decal fades out over 3 seconds `🤖 AI [GitHub Copilot]` `[ENG]`
- [ ] Particle — Landing dust burst (foot-strike → loose soil particles) `🤝 AI+H [Niagara template + VFX artist]` `[VFX]`
  - [ ] Radial dust emitter at foot contact points `👤 Human` `[VFX]`
  - [ ] Tune particle count, spread angle, lifespan `👤 Human` `[VFX]`
- [ ] Particle — Running footstep dust trail (light puff at sprint speed) `🤝 AI+H [Niagara template + VFX artist]` `[VFX]`
  - [ ] Attach small dust emitter to foot bones, enable at sprint threshold `🤖 AI [GitHub Copilot]` `[ENG]`
- [ ] Material — Ground texture altitude blending (earth → moss → stone → ice) `👤 Human` `[TECH-ART]`
  - [ ] Build multi-layer material blend with altitude-driven weight `👤 Human` `[TECH-ART]`
  - [ ] Test smooth transition zones between altitude layers `👤 Human` `[TECH-ART]`
- [ ] VFX — Airavat stomp cloud crack (cloud floor splits on stomp impact) `👤 Human` `[VFX]`
  - [ ] Spawn crack decal radially from stomp impact point `👤 Human` `[VFX]`
  - [ ] Add radial shockwave ring emission `👤 Human` `[VFX]`
  - [ ] Electric dust burst at crack edges `👤 Human` `[VFX]`

---

## 4.5 Fire & Electricity System (Boss Arena)

- [ ] Implement — Vajra lightning arc material (UV-scroll emissive shader) `👤 Human` `[TECH-ART]`
  - [ ] Build animated emissive material — UV scroll at 2m/s on arc channels `👤 Human` `[TECH-ART]`
  - [ ] Apply to Vajra weapon mesh and OBJ_VAJRA_CORE `👤 Human` `[TECH-ART]`
- [ ] VFX — Lightning strike impact (point flash + ground char decal) `👤 Human` `[VFX]`
  - [ ] Niagara burst emitter: bright white flash + outward spark ring `👤 Human` `[VFX]`
  - [ ] Spawn char/scorch decal at impact point `🤖 AI [Niagara template]` `[VFX]`
- [ ] VFX — Lightning ring wave (radial ring expansion from Vajra Core) `👤 Human` `[VFX]`
  - [ ] Animated ring mesh with electric emissive material `👤 Human` `[VFX]`
  - [ ] Scale ring from 0 to arena radius over 2.5 seconds `🤖 AI [GitHub Copilot]` `[ENG]`
- [ ] VFX — Electric crackle on Indra's armor (ambient looping arc particles) `🤝 AI+H [Niagara + VFX artist]` `[VFX]`
  - [ ] Attach random arc emitters to armor surface bones `👤 Human` `[VFX]`
- [ ] Audio — Thunder crack (directional, distance-attenuated) `🤝 AI+H [ElevenLabs Sound FX + sound designer]` `[AUDIO]`
- [ ] Audio — Vajra hum (constant low-frequency hum while boss charges) `🤝 AI+H [ElevenLabs Sound FX + sound designer]` `[AUDIO]`
- [ ] Audio — Lightning body-strike full effect (screen ring + muffled ear for 2s) `👤 Human` `[AUDIO]`
  - [ ] Design muffled audio low-pass filter event `👤 Human` `[AUDIO]`
  - [ ] Trigger for 2s on Vajra hit event `🤖 AI [GitHub Copilot]` `[ENG]`

---

## 4.6 Atmosphere & Sky System

- [ ] Implement — Volumetric cloud layer (Troposphere, Zone 3 — dense, traversable-looking) `👤 Human` `[TECH-ART]`
  - [ ] Configure volumetric cloud component (density, scattering, shadow) `👤 Human` `[TECH-ART]`
  - [ ] Ensure performance target met at 60fps `👤 Human` `[TECH-ART]`
- [ ] Implement — Upper atmosphere haze (depth fog, blue-white scatter) `🤝 AI+H [Claude for math + tech artist]` `[TECH-ART]`
  - [ ] Exponential height fog with altitude control curve `👤 Human` `[TECH-ART]`
- [ ] Implement — God-rays / volumetric light shafts (Zone 2 → Zone 3) `👤 Human` `[TECH-ART]`
- [ ] Implement — Star fade-out system (visible in Zone 1 pre-dawn, gone by Zone 3) `🤝 AI+H [Claude + tech artist]` `[TECH-ART]`
  - [ ] Sky material: star opacity driven by time-of-day progress `🤖 AI [GitHub Copilot]` `[ENG]`
- [ ] Implement — Rising Sun animation (slow arc movement from east horizon) `🤝 AI+H [Claude for arc math + tech artist]` `[TECH-ART]`
  - [ ] Animate sun actor on ellipse arc over mission duration `🤖 AI [GitHub Copilot]` `[ENG]`
- [ ] Particle — Ice crystals at high altitude (sparse drifting, Zone 3+4) `🤝 AI+H [Niagara + VFX artist]` `[VFX]`
  - [ ] Thin hexagonal crystal mesh (4-poly LOD) with emissive edge `👤 Human` `[VFX]`
  - [ ] Drift emitter with slow upward velocity and random rotation `👤 Human` `[VFX]`
- [ ] Audio — Altitude-based low-pass filter (thin air effect on ambient sound) `👤 Human` `[AUDIO]`
  - [ ] Map altitude variable → Wwise/FMOD LPF cutoff frequency `👤 Human` `[AUDIO]`
  - [ ] Test progressive muffling as player ascends Zone 1 → Zone 4 `👤 Human` `[AUDIO]`
