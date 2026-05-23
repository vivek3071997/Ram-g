# S09 — Cinematics & Cutscenes | Mission 0 Development Tasks

> **Mission:** Mission 0 — Hanuman's Solar Leap
> **Section:** All 7 In-Engine Cutscenes — Storyboard, Animatic, Animation, Integration

| Metric | Value |
|--------|-------|
| Total Tasks | 28 |
| Total Subtasks | 58 |
| 🤖 AI-Assisted Tasks | 8 (29%) |
| 🤝 AI+Human Tasks | 12 (43%) |
| 👤 Human-Only Tasks | 8 (28%) |
| Teams Involved | ANIM, ART, AUDIO, WRITE, ENG |

---

## Tag Legend
- `🤖 AI` — Fully achievable by AI  `🤝 AI+H` — AI drafts/assists, human directs  `👤 Human` — Human expertise required
- `[ANIM]` `[ART]` `[AUDIO]` `[WRITE]` `[ENG]` `[QA]` — Team tags

---

## Cinematic 1 — Opening Sequence (2–3 minutes)
*Anjana's grove at dawn. Hanuman notices the sun. Vayu encourages him. He leaps.*

- [ ] Script finalization (see S05 — all dialogue locked before storyboard begins) `👤 Human` `[WRITE]`
- [ ] Storyboard — Frame-by-frame (approx. 45 panels, director's cut) `🤝 AI+H [Midjourney for rough panels + storyboard artist]` `[ART]`
  - [ ] AI-generate rough panel compositions for each shot `🤖 AI [Midjourney, DALL-E 3]` `[ART]`
  - [ ] Storyboard artist refines shots, adds camera direction notes `👤 Human` `[ART]`
  - [ ] Director review and approval `👤 Human` `[ART]`
- [ ] Animatic — Rough motion test with placeholder audio (timing reference) `🤝 AI+H [Runway ML for motion rough + animator]` `[ANIM]`
  - [ ] Assemble storyboard panels in editing software with temp audio `👤 Human` `[ANIM]`
  - [ ] Time-sync animatic to final script pacing `👤 Human` `[ANIM]`
- [ ] Character animation — Anjana, Kid Hanuman, Vayu VFX performance `👤 Human` `[ANIM]`
  - [ ] Block all character poses per panel `👤 Human` `[ANIM]`
  - [ ] Spline polish — secondary motion, overlapping action `👤 Human` `[ANIM]`
  - [ ] Lip-sync pass (Speech Graphics AI assist + manual correction) `🤝 AI+H [Speech Graphics AI + animator]` `[ANIM]`
- [ ] Camera choreography — Shot sequence with dolly, crane, close-ups `👤 Human` `[ANIM]`
- [ ] Lighting & VFX — Pre-dawn orchard light, Vayu wind particles, sunrise begin `👤 Human` `[VFX]`
- [ ] VO integration — Final Anjana + Hanuman + Vayu audio synced `👤 Human` `[AUDIO]`
- [ ] Music sync — Opening exploration theme enters at correct moment `👤 Human` `[AUDIO]`
- [ ] Final polish + engine implementation in Sequencer/Cinematic tool `👤 Human` `[ENG]`

---

## Cinematic 2 — Airavat Boss Intro (30 seconds)
*Hanuman reaches the cloud bridge. Airavat materialises from clouds — massive reveal shot.*

- [ ] Storyboard — 12 panels (reveal sequence: low angle → high wide → close tusks) `🤝 AI+H [Midjourney + storyboard artist]` `[ART]`
- [ ] Animatic — Rough 30-second motion with placeholder SFX `👤 Human` `[ANIM]`
- [ ] Character animation — Airavat entrance performance (stomp, head turn, roar) `👤 Human` `[ANIM]`
- [ ] Camera — Dramatic low→high reveal crane shot `👤 Human` `[ANIM]`
- [ ] VFX — Cloud part on Airavat approach, bioluminescent vein pulse `👤 Human` `[VFX]`
- [ ] Audio sync — Airavat roar, Dundubhi drums enter `👤 Human` `[AUDIO]`
- [ ] Engine implementation `🤖 AI [GitHub Copilot for sequencer setup]` `[ENG]`

---

## Cinematic 3 — Airavat Sleep (15 seconds)
*Hanuman tickles Airavat's ear. Giant elephant collapses asleep — comic moment.*

- [ ] Storyboard — 8 panels (tickle action → wide-eyed reaction → slow collapse) `🤝 AI+H [DALL-E 3 + storyboard artist]` `[ART]`
- [ ] Character animation — Airavat eye-widen, ear twitch, knees buckle, side-fall sleep `👤 Human` `[ANIM]`
- [ ] Kid Hanuman — Victorious giggle, jump off ear, land on cloud bridge `👤 Human` `[ANIM]`
- [ ] VFX — ZZZ sleep bubbles rising, Hanuman's aura brightens slightly `🤝 AI+H [Niagara + VFX artist]` `[VFX]`
- [ ] Audio — Comic bass thud on collapse, gentle snore loop begins, Hanuman laugh VO `👤 Human` `[AUDIO]`
- [ ] Engine implementation + timing lock `🤖 AI [GitHub Copilot]` `[ENG]`

---

## Cinematic 4 — Indra Confrontation (45 seconds)
*Indra appears on chariot in storm. Warning speech. Hanuman's cheeky reply.*

- [ ] Storyboard — 18 panels (chariot appears in lightning flash → close-up Indra face → Hanuman grin) `🤝 AI+H [Midjourney + storyboard artist]` `[ART]`
- [ ] Animatic — 45-second rough with placeholder VO `👤 Human` `[ANIM]`
- [ ] Character animation — Indra commanding pose on chariot, cape physics, pointing gesture `👤 Human` `[ANIM]`
- [ ] Kid Hanuman — Defiant grin, hand-on-hip cocky stance, pointing back at Indra `👤 Human` `[ANIM]`
- [ ] Camera — Intercutting close-ups, final two-shot showing scale difference `👤 Human` `[ANIM]`
- [ ] VFX — Lightning storm backdrop intensifies, Indra's armor arcs crackle `👤 Human` `[VFX]`
- [ ] VO integration — Indra warning lines + Hanuman reply synced `👤 Human` `[AUDIO]`
- [ ] Engine implementation `🤖 AI [GitHub Copilot]` `[ENG]`

---

## Cinematic 5 — Vajra Strike & Fall (1 minute)
*Indra fires the Vajra. Hanuman hit, falls from the sky. Vayu withdraws air. Devas panic.*

- [ ] Storyboard — 25 panels (Vajra charge → blue flash → Hanuman hit → spinning fall → earth approaching) `🤝 AI+H [Midjourney + storyboard artist]` `[ART]`
- [ ] Animatic — 1-minute rough with score temp `👤 Human` `[ANIM]`
- [ ] Character animation — Hanuman hit full-body reaction, limb fling, unconscious tumble fall `👤 Human` `[ANIM]`
- [ ] Indra — Regret expression emerging after firing `👤 Human` `[ANIM]`
- [ ] Camera — Follows Hanuman in free-fall, world spinning, horizon inverted, earth rushes up `👤 Human` `[ANIM]`
- [ ] VFX — Vajra strike full-body electric discharge, aura shatters, fall trail `👤 Human` `[VFX]`
- [ ] Score sync — Vajra Strike score (silence → drone → swell) locked to edit `👤 Human` `[AUDIO]`
- [ ] Audio — Thunder crack of Vajra hit, wind rushing past in free-fall `👤 Human` `[AUDIO]`
- [ ] Engine implementation `🤖 AI [GitHub Copilot]` `[ENG]`

---

## Cinematic 6 — Boon Sequence (1.5 minutes)
*Brahma and deities descend. Grant divine boons. Sages deliver the Curse of Forgetfulness.*

- [ ] Storyboard — 35 panels (deity descent → each deity grants boon → sages appear → curse delivery → aura fades) `🤝 AI+H [Midjourney + storyboard artist]` `[ART]`
  - [ ] AI-generate deity concept panels `🤖 AI [Midjourney]` `[ART]`
  - [ ] Storyboard artist refines each panel with camera + timing notes `👤 Human` `[ART]`
- [ ] Animatic — 1.5-min rough with Boon Score temp `👤 Human` `[ANIM]`
- [ ] Character animation — Brahma floating, hand blessing Hanuman; Sage council solemn gestures `👤 Human` `[ANIM]`
- [ ] Kid Hanuman — Rising awake, glowing, expression of awe, then confusion as aura fades `👤 Human` `[ANIM]`
- [ ] Camera — Wide divine light tableau → tight on Hanuman face as curse lands `👤 Human` `[ANIM]`
- [ ] VFX — Multi-deity boon light showers (colored per deity), aura fade, power drain particles `👤 Human` `[VFX]`
- [ ] VO integration — Brahma narration + Sage Council overlapping curse lines synced `👤 Human` `[AUDIO]`
- [ ] Boon Score sync (multi-layered choir swells for each boon granted) `👤 Human` `[AUDIO]`
- [ ] Engine implementation `🤖 AI [GitHub Copilot]` `[ENG]`

---

## Cinematic 7 — Transition Reveal to Ayodhya (45 seconds)
*Hanuman sits peacefully on Rishyamukha Hill as normal monkey. Camera pans across mountains, rivers, enters Ayodhya — baby Rama revealed.*

- [ ] Storyboard — 18 panels (Hanuman sitting → aerial pull-back → mountain ranges flyover → Sarayu river → palace exterior → palace window → cradle close-up → Rama's face) `🤝 AI+H [Midjourney + storyboard artist]` `[ART]`
- [ ] Animatic — 45-second rough with Raga Bhairav temp score `👤 Human` `[ANIM]`
- [ ] Camera animation — Long sweeping aerial crane shot across environment, ending on tight close-up `👤 Human` `[ANIM]`
- [ ] Hanuman — Post-nerf normal monkey idle on hill (peaceful, tail curled, unaware) `👤 Human` `[ANIM]`
- [ ] Baby Rama — Crying infant reveal, divine glow on face `👤 Human` `[ANIM]`
- [ ] VFX — Transition: Hanuman aura fully dark → sky opens golden as camera crosses into Ayodhya `🤝 AI+H [Houdini AI + VFX artist]` `[VFX]`
- [ ] Scene streaming — Ayodhya scene assets pre-loaded during Boon Sequence cinematic `👤 Human` `[ENG]`
- [ ] Score sync — Raga Bhairav peaceful resolve plays for full 45 seconds `👤 Human` `[AUDIO]`
- [ ] Valmiki narrator VO plays over final 20 seconds of pan `👤 Human` `[AUDIO]`
- [ ] Engine implementation — Final cinematic triggers Mission 1 start state `🤖 AI [GitHub Copilot]` `[ENG]`

---

## Cross-Cinematic Pipeline Tasks

- [ ] Cinematic camera rig setup in engine (Cine Camera Actor with DOF, FOV presets) `🤝 AI+H [Claude for settings + tech artist]` `[ENG]`
- [ ] Cinematic Sequencer / Timeline tool configuration (tracks: camera, anim, audio, VFX, events) `👤 Human` `[ENG]`
- [ ] Global lighting rig for all cinematics (dedicated cinematic directional light overrides) `👤 Human` `[TECH-ART]`
- [ ] Cinematic subtitle sync pipeline (SRT export from audio session → engine import per cinematic) `🤖 AI [GitHub Copilot for pipeline scripting]` `[ENG]`
- [ ] Pre-render vs in-engine render decision per cinematic `👤 Human` `[PROD]`
  - [ ] Evaluate: in-engine for all 7 (performance target 30fps minimum during cinematics) `👤 Human` `[ENG]`
  - [ ] Define fallback pre-render plan if performance fails on cinematic 6 `👤 Human` `[ENG]`
- [ ] Compression specs for any pre-rendered sequences (codec, bitrate, resolution) `🤖 AI [Claude]` `[ENG]`
- [ ] Performance target for in-engine sequences (30fps min on lowest target hardware) `👤 Human` `[QA]`
  - [ ] Profile each cinematic in M0-Gold-1 build `👤 Human` `[QA]`
