# S10 — Technical & Pipeline | Mission 0 Development Tasks

> **Mission:** Mission 0 — Hanuman's Solar Leap
> **Section:** Engine Setup, Performance Optimization, QA Testing, Documentation

| Metric | Value |
|--------|-------|
| Total Tasks | 32 |
| Total Subtasks | 66 |
| 🤖 AI-Assisted Tasks | 14 (44%) |
| 🤝 AI+Human Tasks | 10 (31%) |
| 👤 Human-Only Tasks | 8 (25%) |
| Teams Involved | ENG, TECH-ART, QA, PROD |

---

## Tag Legend
- `🤖 AI` — Fully achievable by AI  `🤝 AI+H` — AI assists, human refines  `👤 Human` — Human expertise required
- `[ENG]` `[TECH-ART]` `[QA]` `[PROD]` — Team tags

---

## 10.1 Engine Setup (8 Tasks)

- [ ] Create Mission 0 scene file in engine (`SCENE_SUMERU_STRATOSPHERE`) `🤖 AI [GitHub Copilot]` `[ENG]`
  - [ ] Set up blank scene with correct world settings (scale, gravity, physics material) `👤 Human` `[ENG]`
  - [ ] Configure scene streaming volumes for Zone 1→2→3→4 load boundaries `👤 Human` `[ENG]`
- [ ] Zone volume system setup (defines active zone for dynamic systems) `🤖 AI [GitHub Copilot, Claude]` `[ENG]`
  - [ ] Create 4 zone trigger volumes with unique Zone IDs `🤖 AI [GitHub Copilot]` `[ENG]`
  - [ ] Broadcast ZoneChanged event on overlap (drives music, wind, lighting, audio LPF) `🤖 AI [GitHub Copilot]` `[ENG]`
- [ ] Adaptive music system integration (Wwise / FMOD) `👤 Human` `[AUDIO]`
  - [ ] Connect game-side intensity variable to Wwise RTPC `🤖 AI [GitHub Copilot]` `[ENG]`
  - [ ] Test music layer blends on all intensity state changes `👤 Human` `[QA]`
- [ ] Post-process volume stack per zone `👤 Human` `[TECH-ART]`
  - [ ] Zone 1: warm color grading LUT, low bloom, soft vignette `👤 Human` `[TECH-ART]`
  - [ ] Zone 2: increasing contrast, stronger god-ray bloom `👤 Human` `[TECH-ART]`
  - [ ] Zone 3: high bloom, sky blue tint, lens flare from sun `👤 Human` `[TECH-ART]`
  - [ ] Zone 4: cold high-contrast LUT, heavy bloom from lightning, chromatic aberration ready `👤 Human` `[TECH-ART]`
- [ ] Occlusion culling configuration for vertical scene `🤝 AI+H [Claude for culling rules + tech artist]` `[TECH-ART]`
  - [ ] Configure occlusion bounds so Zone 1 assets cull when player is in Zone 3+ `👤 Human` `[TECH-ART]`
  - [ ] Test no visible pop-in at zone boundaries `👤 Human` `[QA]`
- [ ] LOD system calibration (all assets — characters, props, environment) `🤝 AI+H [InstaLOD + tech artist]` `[TECH-ART]`
  - [ ] Set LOD0 (< 10m), LOD1 (10–30m), LOD2 (30–80m), LOD3 (>80m) thresholds `👤 Human` `[TECH-ART]`
  - [ ] Profile LOD transitions — no visible pop at any threshold `👤 Human` `[QA]`
- [ ] Streaming asset configuration (cloud assets streamed, not resident) `🤖 AI [GitHub Copilot]` `[ENG]`
  - [ ] Tag all Zone 3+4 assets as streaming assets `🤖 AI [GitHub Copilot]` `[ENG]`
  - [ ] Set pre-load trigger 200m before zone boundary `🤖 AI [GitHub Copilot]` `[ENG]`
- [ ] Build pipeline setup (dev, staging, certification target builds) `🤝 AI+H [GitHub Actions CI + engineer]` `[ENG]`
  - [ ] Create build config for dev (debug symbols, verbose logs) `🤖 AI [GitHub Copilot]` `[ENG]`
  - [ ] Create build config for cert (stripped, optimized, console compliance) `👤 Human` `[ENG]`
  - [ ] Automated build notification on build break `🤖 AI [GitHub Actions]` `[ENG]`

---

## 10.2 Performance & Optimization (8 Tasks)

- [ ] Establish target frame rate benchmarks `👤 Human` `[QA]`
  - [ ] Console target: 60fps at 1080p / 30fps at 4K `👤 Human` `[ENG]`
  - [ ] PC target: 60fps at 1440p on mid-range GPU (RTX 3060 tier) `👤 Human` `[ENG]`
  - [ ] Profile baseline FPS in each zone at M0-Alpha build `👤 Human` `[QA]`
- [ ] Character vertex budget validation (120k tris per character) `🤝 AI+H [InstaLOD + tech artist]` `[TECH-ART]`
  - [ ] Audit all character meshes at LOD0 `🤖 AI [InstaLOD analytics]` `[TECH-ART]`
  - [ ] Flag over-budget meshes for re-retopo `👤 Human` `[3D]`
- [ ] Boss vertex budget validation (300k tris — Airavat + Indra chariot) `🤝 AI+H [InstaLOD + tech artist]` `[TECH-ART]`
- [ ] Texture streaming setup and VRAM budget tracking `🤝 AI+H [Claude for memory math + tech artist]` `[TECH-ART]`
  - [ ] Target < 4GB VRAM on console at any point in Mission 0 `👤 Human` `[TECH-ART]`
  - [ ] Audit texture resident sets per zone `👤 Human` `[TECH-ART]`
  - [ ] Enable mip-map streaming for all 4K textures `🤖 AI [GitHub Copilot]` `[ENG]`
- [ ] Niagara particle budget per zone (cap emitters per zone volume) `👤 Human` `[VFX]`
  - [ ] Zone 1: max 20 active emitters `👤 Human` `[VFX]`
  - [ ] Zone 4: max 35 active emitters (boss fight intensity) `👤 Human` `[VFX]`
  - [ ] Profile GPU particle cost and reduce where over-budget `👤 Human` `[QA]`
- [ ] Physics simulation LOD (cloth, tail, vine physics reduce quality at distance) `🤝 AI+H [Claude for LOD logic + tech artist]` `[TECH-ART]`
  - [ ] Cloth sim: full at < 5m, simplified at 5–15m, disabled at > 15m `👤 Human` `[TECH-ART]`
  - [ ] Vine swing physics: full at < 10m, keyframe fallback at > 10m `👤 Human` `[TECH-ART]`
- [ ] GPU / CPU frame time breakdown report (per zone, per feature) `👤 Human` `[QA]`
  - [ ] Capture Unreal/Unity profiler frame capture in each zone `👤 Human` `[QA]`
  - [ ] Identify top-3 CPU and GPU hotspots per zone `🤝 AI+H [Claude for analysis of profiler data]` `[QA]`
  - [ ] Create optimization sprint backlog from findings `👤 Human` `[ENG]`
- [ ] Mobile / low-spec scalability pass (if future mobile port planned) `🤝 AI+H [Claude for scalability plan + engineer]` `[ENG]`
  - [ ] Define low/medium/high/ultra quality presets `🤖 AI [Claude]` `[ENG]`
  - [ ] Implement settings menu scalability options `🤖 AI [GitHub Copilot]` `[ENG]`

---

## 10.3 QA & Testing (12 Tasks)

- [ ] Full end-to-end playthrough test (Mission 0 start → Rama reveal transition) `👤 Human` `[QA]`
  - [ ] Complete 3 full playthroughs in dev build, document all issues `👤 Human` `[QA]`
  - [ ] File all bugs in tracker (Jira/GitHub Issues) `👤 Human` `[QA]`
- [ ] Movement mechanics test matrix (all 12 movement systems in S08) `👤 Human` `[QA]`
  - [ ] Create test cases for each mechanic (expected vs actual) `🤖 AI [Claude]` `[QA]`
  - [ ] Execute test matrix, log results `👤 Human` `[QA]`
- [ ] Puzzle validation test (3 windwheels solvable, updraft unlocks) `👤 Human` `[QA]`
  - [ ] Verify each windwheel can be solved in correct and incorrect positions `👤 Human` `[QA]`
  - [ ] Verify updraft activates only on correct alignment `👤 Human` `[QA]`
- [ ] Cloud platform timer accuracy test `👤 Human` `[QA]`
  - [ ] Measure actual timer across 30fps, 60fps, 120fps builds `👤 Human` `[QA]`
  - [ ] Confirm ±0.05s accuracy at all frame rates `👤 Human` `[QA]`
- [ ] Vayu rescue system test (3 rescues then mission fail) `👤 Human` `[QA]`
  - [ ] Test rescue fires on each fall below threshold `👤 Human` `[QA]`
  - [ ] Test mission fail state fires on 4th fall `👤 Human` `[QA]`
  - [ ] Test save state preserved correctly after rescue `👤 Human` `[QA]`
- [ ] Airavat boss full test (Phase 1 tusk climb, Phase 2 tickle, phase transition) `👤 Human` `[QA]`
  - [ ] Test phase trigger at exactly 50% HP `👤 Human` `[QA]`
  - [ ] Test all Airavat attacks: stomp, charge, trunk sweep, lash, water blast `👤 Human` `[QA]`
- [ ] Indra boss full test (lightning patterns, chariot orbit, crown grab trigger) `👤 Human` `[QA]`
  - [ ] Test all 3 difficulty-scaled ring speed variants `👤 Human` `[QA]`
  - [ ] Test crown grab fires after full survival duration `👤 Human` `[QA]`
  - [ ] Test arena boundary bounce-back on all edges `👤 Human` `[QA]`
- [ ] All 7 cinematics playback test `👤 Human` `[QA]`
  - [ ] Verify each cinematic plays at 30fps minimum `👤 Human` `[QA]`
  - [ ] Verify VO, subtitles, and music are all in sync `👤 Human` `[QA]`
  - [ ] Verify no character clipping or camera issues in any cinematic `👤 Human` `[QA]`
- [ ] Character transition handoff test (Hanuman → Rama reveal) `👤 Human` `[QA]`
  - [ ] Verify scene streams in without hitch during Boon Sequence `👤 Human` `[QA]`
  - [ ] Verify Mission 1 state initializes correctly after handoff `👤 Human` `[QA]`
- [ ] Collectibles pickup test (2 scrolls, 3 constellations) `👤 Human` `[QA]`
  - [ ] Test each pickup registers in player journal `👤 Human` `[QA]`
  - [ ] Test journal entry text displays correctly (EN + HI) `👤 Human` `[QA]`
- [ ] Achievement trigger test `👤 Human` `[QA]`
  - [ ] "First Leap": complete mission with 0 rescues → achievement fires `👤 Human` `[QA]`
  - [ ] "Golden Stomach": collect all 7 fruits → achievement fires `👤 Human` `[QA]`
- [ ] Audio zone transition test `👤 Human` `[QA]`
  - [ ] Verify music crossfades smoothly at each zone boundary (no pop) `👤 Human` `[QA]`
  - [ ] Verify altitude LPF progresses smoothly Zone 1 → Zone 4 `👤 Human` `[QA]`
  - [ ] Verify no audio sources persist incorrectly across zone boundaries `👤 Human` `[QA]`

---

## 10.4 Documentation & Pipeline (4 Tasks)

- [ ] Technical Design Document (TDD) for Mission 0 systems `🤝 AI+H [Claude for structure + lead programmer]` `[ENG]`
  - [ ] Document all custom systems: grapple, updraft, wind field, zone system `🤖 AI [Claude]` `[ENG]`
  - [ ] Document data flow diagram (inputs → systems → outputs) `🤝 AI+H [Claude + Mermaid diagram + engineer]` `[ENG]`
  - [ ] Lead programmer review and sign-off `👤 Human` `[ENG]`
- [ ] Asset naming convention guide `🤖 AI [Claude]` `[PROD]`
  - [ ] Define naming rules: `[GAME]_[ZONE]_[TYPE]_[NAME]_[LOD]` format `🤖 AI [Claude]` `[PROD]`
  - [ ] Distribute to all teams before M0-Alpha `👤 Human` `[PROD]`
- [ ] Pipeline integration guide (DCC to engine workflow) `🤝 AI+H [Claude + tech artist]` `[TECH-ART]`
  - [ ] Document Maya/ZBrush → FBX export settings → engine import pipeline `🤝 AI+H [Claude + tech artist]` `[TECH-ART]`
  - [ ] Document Substance Painter → texture export → engine material setup `🤝 AI+H [Claude + tech artist]` `[TECH-ART]`
  - [ ] Document Wwise → engine audio event binding workflow `👤 Human` `[AUDIO]`
- [ ] Post-mortem template setup (ready for use after M0-Release) `🤖 AI [Claude]` `[PROD]`
  - [ ] Template: What went well / What went wrong / What we'd do differently `🤖 AI [Claude]` `[PROD]`
  - [ ] Schedule post-mortem meeting for Week 25 `👤 Human` `[PROD]`
