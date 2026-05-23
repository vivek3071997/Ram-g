# S07 — Audio Design | Mission 0 Development Tasks

> **Mission:** Mission 0 — Hanuman's Solar Leap
> **Section:** Music Score, Voice Acting, Sound Effects, Audio Systems

| Metric | Value |
|--------|-------|
| Total Tasks | 48 |
| Total Subtasks | 99 |
| 🤖 AI-Assisted Tasks | 20 (42%) |
| 🤝 AI+Human Tasks | 18 (37%) |
| 👤 Human-Only Tasks | 10 (21%) |
| Teams Involved | AUDIO, VO, ENG |

---

## Tag Legend
- `🤖 AI` — Fully achievable by AI  `🤝 AI+H` — AI drafts, human refines  `👤 Human` — Human expertise required
- `[AUDIO]` `[VO]` `[ENG]` `[QA]` — Team tags

---

## 7.1 Music / Score (7 Themes + Underscore Variants)

### 7.1.1 Mission 0 Main Exploration Theme — Raga Shankara (Playful, Wonder)

- [ ] Compose reference brief (tempo, instrumentation, emotional arc) `🤖 AI [Claude, ChatGPT]` `[AUDIO]`
  - [ ] Define: moderate tempo, tabla + bansuri flute + light strings `👤 Human` `[AUDIO]`
  - [ ] Reference track mood board (3 existing tracks as tonal anchors) `🤖 AI [Claude research]` `[AUDIO]`
- [ ] AI-generate demo stems for composer review `🤝 AI+H [Suno AI, Udio, AIVA + composer]` `[AUDIO]`
  - [ ] Generate 2–3 variations in Raga Shankara scale `🤖 AI [Suno AI, AIVA]` `[AUDIO]`
  - [ ] Composer reviews AI stems, extracts usable motifs `👤 Human` `[AUDIO]`
- [ ] Human composer: arrange and orchestrate final version `👤 Human` `[AUDIO]`
- [ ] Record live instruments where possible (bansuri flute, tabla) `👤 Human` `[AUDIO]`
- [ ] Mix and master final stems (separate stems: melody, rhythm, atmosphere) `👤 Human` `[AUDIO]`
- [ ] Engine integration — Wwise/FMOD import and adaptive layer setup `🤖 AI [GitHub Copilot for integration code]` `[ENG]`

### 7.1.2 Airavat Boss Theme — Thunderous Percussion + Elephant Horns

- [ ] Compose brief (heavy, majestic, percussive — Dundubhi war drums + brass) `🤖 AI [Claude]` `[AUDIO]`
- [ ] AI demo stems `🤝 AI+H [Suno AI, Udio + composer]` `[AUDIO]`
- [ ] Composer arranges + orchestrates final `👤 Human` `[AUDIO]`
- [ ] Record live war drum section (Dhol, Nagara) if budget allows `👤 Human` `[AUDIO]`
- [ ] Mix, master, engine integration `👤 Human` `[AUDIO]`
- [ ] Phase transition layer — Intensity increases at 50% Airavat HP `🤖 AI [GitHub Copilot]` `[ENG]`

### 7.1.3 Indra Boss Theme — Electrical Storm Orchestral

- [ ] Compose brief (electric, war-like, celestial power — brass + choir + storm) `🤖 AI [Claude]` `[AUDIO]`
- [ ] AI demo stems `🤝 AI+H [Suno AI, AIVA + composer]` `[AUDIO]`
- [ ] Composer arranges + adds electronic crackle layer `👤 Human` `[AUDIO]`
- [ ] Mix, master, engine integration with chariot-orbit intensity layers `👤 Human` `[AUDIO]`

### 7.1.4 Vajra Strike Cinematic Score — Silence → Drone → Divine Swell

- [ ] Compose brief (sudden silence 1s → single low Shruti drone → massive swell) `🤖 AI [Claude]` `[AUDIO]`
- [ ] Composer creates this 45-second micro-score `👤 Human` `[AUDIO]`
- [ ] Mix and sync to cinematic timing exactly `👤 Human` `[AUDIO]`
- [ ] Engine integration — trigger on Vajra strike event `🤖 AI [GitHub Copilot]` `[ENG]`

### 7.1.5 Boon Sequence Theme — Divine Choir + Veena + Flute

- [ ] Compose brief (ascending, sacred, multi-deity choir — Sanskrit devotional) `🤖 AI [Claude]` `[AUDIO]`
- [ ] AI demo stems (choir texture) `🤝 AI+H [Suno AI, AIVA + composer]` `[AUDIO]`
- [ ] Composer layers real veena and flute over AI choir texture `👤 Human` `[AUDIO]`
- [ ] Mix, master, engine integration for 1.5-minute cinematic sync `👤 Human` `[AUDIO]`

### 7.1.6 Transition to Rama Reveal — Raga Bhairav (Peaceful, Sacred)

- [ ] Compose brief (slow, meditative, Raga Bhairav — dawn raga, peaceful transition) `🤖 AI [Claude]` `[AUDIO]`
- [ ] AI demo stems `🤝 AI+H [Suno AI + composer]` `[AUDIO]`
- [ ] Composer creates gentle 45-second resolve piece `👤 Human` `[AUDIO]`
- [ ] Mix, master, engine integration for camera-pan cinematic `👤 Human` `[AUDIO]`
- [ ] Cross-fade from Hanuman Raga Shankara theme → Rama Raga Bhairav `🤖 AI [GitHub Copilot]` `[ENG]`

### 7.1.7 Ambient Exploration Underscore Variants (4 zones)

- [ ] Zone 1 Orchard underscore (light, birdsong-infused, gentle tabla) `🤝 AI+H [Suno AI + composer]` `[AUDIO]`
- [ ] Zone 2 Cliff underscore (building tension, rising strings) `🤝 AI+H [Suno AI + composer]` `[AUDIO]`
- [ ] Zone 3 Cloud Deck underscore (airy, ethereal, high flute) `🤝 AI+H [Suno AI + composer]` `[AUDIO]`
- [ ] Zone 4 Storm Arena underscore (pre-boss tension, low drone + thunder) `🤝 AI+H [Suno AI + composer]` `[AUDIO]`

---

## 7.2 Voice Acting — 6 Characters

### 7.2.1 Kid Hanuman

- [ ] Casting brief — high-energy child voice, playful, fearless `🤖 AI [Claude]` `[VO]`
- [ ] Audition script package (10 lines covering full emotional range) `🤖 AI [Claude]` `[VO]`
- [ ] Studio recording session (all Mission 0 Hanuman lines) `👤 Human` `[VO]`
- [ ] Audio cleaning and noise removal `🤝 AI+H [Adobe Podcast AI + engineer]` `[AUDIO]`
- [ ] Mastering and normalization `👤 Human` `[AUDIO]`
- [ ] Engine import + dialogue trigger system hookup `🤖 AI [GitHub Copilot]` `[ENG]`

### 7.2.2 Anjana (Mother)

- [ ] Casting brief — warm, worried maternal, Vanara dignified `🤖 AI [Claude]` `[VO]`
- [ ] Recording session (4 lines) + audio process + engine import `👤 Human` `[VO]`

### 7.2.3 Vayu (Wind Spirit)

- [ ] Casting brief — deep, booming, warm paternal (processed with reverb + wind FX) `🤖 AI [Claude]` `[VO]`
- [ ] Recording session (3 lines) + audio process (add wind reverb) + engine import `👤 Human` `[VO]`
- [ ] AI voice generation as backup / prototype `🤝 AI+H [ElevenLabs + voice director]` `[VO]`

### 7.2.4 Lord Indra

- [ ] Casting brief — regal, arrogant, thunderous deep voice `🤖 AI [Claude]` `[VO]`
- [ ] Recording session (6 lines) + audio process (add hall reverb) + engine import `👤 Human` `[VO]`

### 7.2.5 Brahma (Narration — Boon Sequence)

- [ ] Casting brief — ancient, omniscient, measured cosmic calm `🤖 AI [Claude]` `[VO]`
- [ ] Recording session (narration VO) + audio process + engine import `👤 Human` `[VO]`
- [ ] AI voice generation as prototype for timing reference `🤝 AI+H [ElevenLabs + voice director]` `[VO]`

### 7.2.6 Sage Council (Multi-Voice Curse)

- [ ] Casting brief — 3 distinct sage voices, solemn, staggered delivery `🤖 AI [Claude]` `[VO]`
- [ ] Recording session (3 VAs × 3 lines each) + mix overlapping delivery `👤 Human` `[VO]`
- [ ] Audio design — stagger and blend the 3 voices in mix `👤 Human` `[AUDIO]`

---

## 7.3 Sound Effects — Environment (by Zone)

### Zone 1 — Orchard

- [ ] Morning birdsong ambience loop (layered — 5 species) `🤝 AI+H [ElevenLabs Sound FX + sound designer]` `[AUDIO]`
- [ ] Cricket chirp layer (pre-dawn, fading as sunrise begins) `🤖 AI [ElevenLabs Sound FX]` `[AUDIO]`
- [ ] Creek water babble loop (gentle, positional) `🤝 AI+H [ElevenLabs Sound FX + sound designer]` `[AUDIO]`
- [ ] Wind-in-leaves rustle loop (breeze, gentle 15 km/h) `🤖 AI [ElevenLabs Sound FX]` `[AUDIO]`

### Zone 2 — Cliff Ascent

- [ ] Wind howl escalation (volume + pitch increases with altitude) `🤝 AI+H [ElevenLabs Sound FX + sound designer]` `[AUDIO]`
- [ ] Rock crumble / pebble scatter SFX (on ledge land) `🤖 AI [ElevenLabs Sound FX]` `[AUDIO]`
- [ ] Thermal updraft column enter (rushing whoosh, sustained roar inside) `🤖 AI [ElevenLabs Sound FX]` `[AUDIO]`
- [ ] Stone windwheel rotation grind `🤝 AI+H [ElevenLabs Sound FX + sound designer]` `[AUDIO]`

### Zone 3 — Cloud Deck

- [ ] Celestial hum ambience (high-altitude open-sky resonance) `🤝 AI+H [ElevenLabs Sound FX + sound designer]` `[AUDIO]`
- [ ] Distant Airavat conch trumpet echo (pre-boss approach cue) `🤖 AI [ElevenLabs Sound FX]` `[AUDIO]`
- [ ] Cloud platform dissolve puff SFX `🤖 AI [ElevenLabs Sound FX]` `[AUDIO]`

### Zone 4 — Storm Arena

- [ ] Rolling thunder (randomized, directional, distance-attenuated) `🤝 AI+H [ElevenLabs Sound FX + sound designer]` `[AUDIO]`
- [ ] Indra chariot wheel roar (approach + orbit loop) `🤝 AI+H [ElevenLabs Sound FX + sound designer]` `[AUDIO]`
- [ ] Vajra charge-up hum (rising electrical buzz, 3-second build) `🤖 AI [ElevenLabs Sound FX]` `[AUDIO]`

---

## 7.4 Sound Effects — Character (Kid Hanuman)

- [ ] Footstep set — Dirt / Moss / Rock / Cloud (4 surface variants × 3 steps each) `🤝 AI+H [ElevenLabs Sound FX + sound designer]` `[AUDIO]`
- [ ] Jump whoosh — light child jump (soft air) `🤖 AI [ElevenLabs Sound FX]` `[AUDIO]`
- [ ] Double jump — powered super-launch (tail crack + air burst) `🤝 AI+H [ElevenLabs Sound FX + sound designer]` `[AUDIO]`
- [ ] Tail grapple launch + latch thwack `🤝 AI+H [ElevenLabs Sound FX + sound designer]` `[AUDIO]`
- [ ] Land soft (gentle pad) + Land hard (ground thud + dust) `🤖 AI [ElevenLabs Sound FX]` `[AUDIO]`
- [ ] Punch combo (3 hits: fist whoosh × 3, each slightly heavier) `🤖 AI [ElevenLabs Sound FX]` `[AUDIO]`
- [ ] Tail swipe (wide arc swoosh) `🤖 AI [ElevenLabs Sound FX]` `[AUDIO]`
- [ ] Hurt sound (child pain grunt — brief, not severe) `👤 Human` `[VO]`
- [ ] Laugh (big, open child laugh — used in Airavat tickle scene) `👤 Human` `[VO]`
- [ ] Scared gasp (seeing Indra's Vajra) `👤 Human` `[VO]`
- [ ] Exertion breath loop (stamina drain state) `🤝 AI+H [ElevenLabs + VO]` `[VO]`

### Tyaksha SFX

- [ ] Tyaksha chatter (mischievous chittering loop) `🤖 AI [ElevenLabs Sound FX]` `[AUDIO]`
- [ ] Tyaksha run (light scurrying pitter-patter) `🤖 AI [ElevenLabs Sound FX]` `[AUDIO]`
- [ ] Seed throw (wind-up + projectile whistle) `🤖 AI [ElevenLabs Sound FX]` `[AUDIO]`
- [ ] Tyaksha caught squeal (comic, not distressing) `👤 Human` `[VO]`

---

## 7.5 Sound Effects — Bosses

### Airavat SFX

- [ ] Airavat roar (deep, layered elephant + brass horn, 3 variants) `🤝 AI+H [ElevenLabs Sound FX + sound designer]` `[AUDIO]`
- [ ] Airavat stomp (ground-shaking low-frequency impact, 2 variants L/R) `🤝 AI+H [ElevenLabs Sound FX + sound designer]` `[AUDIO]`
- [ ] Airavat trunk sweep (air displacement whoosh) `🤖 AI [ElevenLabs Sound FX]` `[AUDIO]`
- [ ] Airavat trunk lash (overhead whip crack) `🤖 AI [ElevenLabs Sound FX]` `[AUDIO]`
- [ ] Airavat water blast (high-pressure hose burst + splash) `🤝 AI+H [ElevenLabs Sound FX + sound designer]` `[AUDIO]`
- [ ] Airavat tusk vibrate (deep bone resonance when player climbs) `🤖 AI [ElevenLabs Sound FX]` `[AUDIO]`
- [ ] Airavat sleep ZZZ (gentle comedic breath loop) `🤝 AI+H [ElevenLabs + sound designer]` `[AUDIO]`

### Indra SFX

- [ ] Indra chariot approach (rumble crescendo from distance) `🤝 AI+H [ElevenLabs Sound FX + sound designer]` `[AUDIO]`
- [ ] Vajra charge-up (sustained rising electrical buzz) `🤖 AI [ElevenLabs Sound FX]` `[AUDIO]`
- [ ] Vajra throw (crack + high-speed whistle + impact explosion) `🤝 AI+H [ElevenLabs Sound FX + sound designer]` `[AUDIO]`
- [ ] Lightning ring ground wave (sweeping crackle radial) `🤖 AI [ElevenLabs Sound FX]` `[AUDIO]`
- [ ] Crown grab sting (sharp musical hit stinger on grab) `👤 Human` `[AUDIO]`

---

## 7.6 Sound Effects — UI

- [ ] Fruit pickup chime (gentle, satisfying — 7 tone melody) `🤝 AI+H [Suno AI + sound designer]` `[AUDIO]`
- [ ] Basket fill progress sound (filling up — subtle whoosh per fruit) `🤖 AI [ElevenLabs Sound FX]` `[AUDIO]`
- [ ] Checkpoint save jingle (short 3-note soft sting) `🤝 AI+H [Suno AI + sound designer]` `[AUDIO]`
- [ ] Achievement unlock sting (triumphant mini-fanfare, 2 seconds) `🤝 AI+H [Suno AI + sound designer]` `[AUDIO]`
- [ ] Tutorial prompt appear (soft paper-scroll unfurl) `🤖 AI [ElevenLabs Sound FX]` `[AUDIO]`
- [ ] Menu navigate / select (wooden plaque tap sounds) `🤖 AI [ElevenLabs Sound FX]` `[AUDIO]`

---

## 7.7 Audio System Implementation

- [ ] Wwise / FMOD project setup for Mission 0 `👤 Human` `[AUDIO]`
  - [ ] Create bus structure (Music, VO, SFX-World, SFX-UI) `👤 Human` `[AUDIO]`
  - [ ] Import all audio assets into project `🤝 AI+H [GitHub Copilot for import scripting + engineer]` `[ENG]`
- [ ] Adaptive music system (intensity-based layer blending) `👤 Human` `[AUDIO]`
  - [ ] Define intensity states (Explore, Combat-Low, Combat-High, Cinematic) `👤 Human` `[AUDIO]`
  - [ ] Build RTPC (Real-Time Parameter Control) blend curves `👤 Human` `[AUDIO]`
  - [ ] Code game-side intensity variable to drive RTPC `🤖 AI [GitHub Copilot]` `[ENG]`
- [ ] Altitude-based low-pass filter system `👤 Human` `[AUDIO]`
  - [ ] Map altitude Z-variable → Wwise LPF bus cutoff `🤖 AI [GitHub Copilot]` `[ENG]`
  - [ ] Test filter progression across Zones 1–4 `👤 Human` `[QA]`
- [ ] Zone-based audio transition system (crossfade on zone boundary) `🤖 AI [GitHub Copilot]` `[ENG]`
  - [ ] Define 4 zone audio volumes in engine `👤 Human` `[AUDIO]`
  - [ ] Trigger crossfade (2-second blend) on volume enter/exit `🤖 AI [GitHub Copilot]` `[ENG]`
- [ ] Occlusion and reverb zones (cave/cliff acoustic model) `👤 Human` `[AUDIO]`
- [ ] Audio performance profiling (CPU % budget per zone) `👤 Human` `[AUDIO]`
  - [ ] Profile audio CPU cost in M0-Beta build `👤 Human` `[QA]`
  - [ ] Reduce voice count limits if above 5% CPU budget `👤 Human` `[AUDIO]`
