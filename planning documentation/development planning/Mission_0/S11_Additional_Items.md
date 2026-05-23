# S11 — Additional Items & Polish | Mission 0 Development Tasks

> **Mission:** Mission 0 — Hanuman's Solar Leap
> **Section:** Accessibility, Localization, Haptics, Difficulty, Photo Mode, Marketing, Player Experience

| Metric | Value |
|--------|-------|
| Total Tasks | 18 |
| Total Subtasks | 38 |
| 🤖 AI-Assisted Tasks | 8 (44%) |
| 🤝 AI+Human Tasks | 6 (33%) |
| 👤 Human-Only Tasks | 4 (22%) |
| Teams Involved | ENG, UI, DESIGN, PROD, ART, QA |

---

## Tag Legend
- `🤖 AI` — Fully achievable by AI  `🤝 AI+H` — AI assists, human refines  `👤 Human` — Human expertise required
- `[ENG]` `[UI]` `[DESIGN]` `[PROD]` `[ART]` `[QA]` — Team tags

---

## 11.1 Accessibility

- [ ] Colorblind Mode — Remap lightning ring colors (yellow/blue instead of white/red) `🤖 AI [GitHub Copilot, Claude]` `[ENG]`
  - [ ] Research standard colorblind palettes (Deuteranopia, Protanopia, Tritanopia) `🤖 AI [Claude]` `[DESIGN]`
  - [ ] Implement global post-process material swap on colorblind mode toggle `🤖 AI [GitHub Copilot]` `[ENG]`
  - [ ] Apply recoloring to: lightning rings, health bar fruit states, stamina ring `🤖 AI [GitHub Copilot]` `[ENG]`
  - [ ] QA — Validate with colorblind simulation tools (Coblis, Sim Daltonism) `👤 Human` `[QA]`
- [ ] Subtitle Font Size Scaling — Slider 80% → 150% of base `🤖 AI [GitHub Copilot]` `[ENG]`
  - [ ] Add "Subtitle Size" slider to Accessibility settings menu `🤖 AI [GitHub Copilot]` `[ENG]`
  - [ ] Bind slider to subtitle widget font size property `🤖 AI [GitHub Copilot]` `[ENG]`
  - [ ] Test at min and max size — verify no text clipping or overflow `👤 Human` `[QA]`
- [ ] Input Remapping — Fully rebindable controller + keyboard `🤝 AI+H [GitHub Copilot + UI designer]` `[ENG]`
  - [ ] Build input remapping UI widget (action list + current binding display) `🤖 AI [GitHub Copilot]` `[ENG]`
  - [ ] Persist custom bindings to local save file `🤖 AI [GitHub Copilot]` `[ENG]`
  - [ ] Reset to defaults button `🤖 AI [GitHub Copilot]` `[ENG]`
  - [ ] Conflict detection (warn if two actions bound to same key) `🤝 AI+H [Claude for logic + programmer]` `[ENG]`
- [ ] High-Contrast HUD Mode — All HUD elements outlined in solid white `🤖 AI [GitHub Copilot]` `[ENG]`
  - [ ] Add white stroke + increased opacity to all HUD widget elements `🤖 AI [GitHub Copilot]` `[ENG]`
  - [ ] Toggle on/off from Accessibility settings `🤖 AI [GitHub Copilot]` `[ENG]`

---

## 11.2 Localization

- [ ] English Text Pack — Finalize all in-game strings (UI labels, objectives, tooltips) `🤝 AI+H [Claude + writer review]` `[WRITE]`
  - [ ] Export all string IDs to localization table `🤖 AI [GitHub Copilot]` `[ENG]`
  - [ ] Native English speaker QA review `👤 Human` `[QA]`
- [ ] Hindi Text Pack — Translate all strings to Hindi (Devanagari script) `🤝 AI+H [DeepL, Google Translate + Hindi localizer review]` `[WRITE]`
  - [ ] AI-generate first-pass translation `🤖 AI [DeepL, Google Translate]` `[WRITE]`
  - [ ] Native Hindi speaker review and correct `👤 Human` `[WRITE]`
  - [ ] Devanagari font rendering test in engine (Noto Sans Devanagari) `👤 Human` `[QA]`
  - [ ] Test all UI elements for text overflow at Hindi string lengths (typically 20–30% longer) `👤 Human` `[QA]`
- [ ] Tamil + Telugu Text Packs `🤝 AI+H [DeepL + Tamil/Telugu localizer]` `[WRITE]`
  - [ ] AI-generate first-pass Tamil translation `🤖 AI [DeepL, Google Translate]` `[WRITE]`
  - [ ] AI-generate first-pass Telugu translation `🤖 AI [DeepL, Google Translate]` `[WRITE]`
  - [ ] Native speaker review for both languages `👤 Human` `[WRITE]`
  - [ ] Font rendering test for Tamil (Noto Sans Tamil) `👤 Human` `[QA]`
  - [ ] Font rendering test for Telugu (Noto Sans Telugu) `👤 Human` `[QA]`
  - [ ] UI overflow test for both languages `👤 Human` `[QA]`

---

## 11.3 Controller Haptics

- [ ] Haptic Feedback Map Design Doc `🤝 AI+H [Claude + game designer]` `[DESIGN]`
  - [ ] Map key game events to haptic patterns and intensities: `🤖 AI [Claude]` `[DESIGN]`
    - Vajra body strike → Full rumble (100%), 0.8s
    - Airavat stomp → Strong low-frequency rumble (80%), 0.5s
    - Fruit pickup → Light double-pulse (20%), 0.1s × 2
    - Vine grapple latch → Medium click (50%), 0.15s
    - Cloud platform warning (red) → Rapid light pulse (30%), repeat
    - Cloud platform dissolve → Medium fade-out (60%), 0.4s
    - Walking → Subtle footstep pulse (10%), per step
    - Sprint → Constant light vibration (15%)
  - [ ] Review haptic map with accessibility team (not all haptic patterns accessible) `👤 Human` `[DESIGN]`
- [ ] Engine implementation of haptic patterns (DualSense / Xbox Haptics API) `🤝 AI+H [GitHub Copilot + platform engineer]` `[ENG]`
  - [ ] Implement PS5 DualSense adaptive trigger resistance on grapple `🤝 AI+H [GitHub Copilot + Sony SDK docs]` `[ENG]`
  - [ ] Implement Xbox haptic events for all mapped game events `🤖 AI [GitHub Copilot]` `[ENG]`
  - [ ] Add "Haptic Intensity" slider (0–100%) in Accessibility settings `🤖 AI [GitHub Copilot]` `[ENG]`
  - [ ] QA — Test all haptic events on both DualSense and Xbox controller `👤 Human` `[QA]`

---

## 11.4 Difficulty Settings

- [ ] Difficulty Parameter Design Doc `🤝 AI+H [Claude + game designer]` `[DESIGN]`
  - [ ] Define Easy mode adjustments: `🤖 AI [Claude]` `[DESIGN]`
    - Lightning ring speed: 50% of Normal
    - Cloud platform timer: 5 seconds (vs 3 on Normal)
    - Vayu rescues: 5 (vs 3 on Normal)
    - Airavat attack frequency: 70% of Normal
    - Fruit collection: Tyakshas move 60% speed
  - [ ] Define Normal mode: all base values as designed `👤 Human` `[DESIGN]`
  - [ ] Define Hard mode adjustments: `🤖 AI [Claude]` `[DESIGN]`
    - Lightning ring speed: 140% of Normal
    - Cloud platform timer: 2 seconds
    - Vayu rescues: 1 only
    - Airavat attacks: 130% frequency, no telegraphing warnings
  - [ ] Sign off on difficulty balance with lead game designer `👤 Human` `[DESIGN]`
- [ ] Engine implementation — Difficulty modifier system `🤝 AI+H [GitHub Copilot + programmer]` `[ENG]`
  - [ ] Create DifficultySettings data asset (Easy / Normal / Hard parameter sets) `🤖 AI [GitHub Copilot]` `[ENG]`
  - [ ] All difficulty-dependent variables read from active DifficultySettings asset `🤖 AI [GitHub Copilot]` `[ENG]`
  - [ ] Difficulty selectable from main menu and pause menu `🤖 AI [GitHub Copilot]` `[ENG]`
  - [ ] QA — Test all 3 difficulty levels full playthrough `👤 Human` `[QA]`

---

## 11.5 Photo Mode

- [ ] Photo mode camera system implementation `🤝 AI+H [GitHub Copilot + programmer]` `[ENG]`
  - [ ] Free-roam camera (detaches from player, full 3D movement, FOV control) `🤖 AI [GitHub Copilot]` `[ENG]`
  - [ ] Time freeze on photo mode enter `🤖 AI [GitHub Copilot]` `[ENG]`
  - [ ] Depth of field control slider `🤖 AI [GitHub Copilot]` `[ENG]`
  - [ ] Filters: Normal, Golden Hour, Black & White, Divine Glow (emissive boost) `🤝 AI+H [Claude for filter logic + tech artist]` `[TECH-ART]`
  - [ ] Screenshot capture and save to system gallery `🤖 AI [GitHub Copilot]` `[ENG]`
- [ ] Kid Hanuman pose selector (8 poses for photo mode) `🤝 AI+H [Claude for pose list + animator]` `[ANIM]`
  - [ ] Define 8 poses: Hero Leap, Tail Point, Victory Flex, Sit Meditate, Mango Reach, Laugh, Warrior Stance, Tickle `🤖 AI [Claude]` `[DESIGN]`
  - [ ] Animate each pose as a held static animation clip `👤 Human` `[ANIM]`
  - [ ] Hook poses to pose selector UI wheel in photo mode `🤖 AI [GitHub Copilot]` `[ENG]`
  - [ ] Expression selector (joy, mischief, determination) for each pose `👤 Human` `[ANIM]`

---

## 11.6 Marketing & Trailer Assets

- [ ] Identify Mission 0 hero moments for reveal / launch trailer `👤 Human` `[PROD]`
  - [ ] Curate top 5 gameplay moments (cloud leap, Airavat tickle, Vajra strike, Boon sequence, Rama reveal) `🤝 AI+H [Claude for suggestions + director]` `[PROD]`
  - [ ] Write trailer brief and shot list `🤖 AI [Claude]` `[PROD]`
- [ ] Capture and assemble trailer footage in engine `👤 Human` `[PROD]`
  - [ ] Record 4K gameplay captures of all hero moments `👤 Human` `[PROD]`
  - [ ] Edit rough cut with temp score `👤 Human` `[PROD]`
  - [ ] Final trailer edit with music and VO `👤 Human` `[PROD]`
- [ ] Concept Art Book spread — Mission 0 (1 full-page spread) `🤝 AI+H [Midjourney + senior concept artist]` `[ART]`
  - [ ] AI-generate 6 candidate compositions `🤖 AI [Midjourney]` `[ART]`
  - [ ] Senior artist selects and paints final full-page spread `👤 Human` `[ART]`
  - [ ] Add caption text and layout in InDesign `👤 Human` `[ART]`

---

## 11.7 Player Experience Polish

- [ ] Death Screen — Design + Implement `🤝 AI+H [Midjourney + UI designer + programmer]` `[ART]`
  - [ ] AI-generate dark sky atmospheric background (Hanuman falling silhouette) `🤖 AI [Midjourney]` `[ART]`
  - [ ] Write 5 rotating quote variants (Valmiki-style) `🤖 AI [Claude]` `[WRITE]`
  - [ ] UI: display random quote + Try Again / Last Checkpoint / Main Menu `🤖 AI [GitHub Copilot]` `[ENG]`
  - [ ] Fade-in animation (0.8s black → image reveal) `🤖 AI [GitHub Copilot]` `[ENG]`
- [ ] Loading Screen — Design + Implement `🤝 AI+H [Midjourney + UI designer + programmer]` `[ART]`
  - [ ] AI-generate hero loading screen image (Hanuman leaping at golden sun) `🤖 AI [Midjourney]` `[ART]`
  - [ ] Art director selection and final image polish `👤 Human` `[ART]`
  - [ ] Add Sanskrit shloka overlay text (Devanagari + English) `👤 Human` `[UI]`
  - [ ] Animated loading spinner (golden tail curl motif) `🤝 AI+H [Adobe Firefly + UI designer]` `[UI]`
  - [ ] Tips/hints carousel on loading screen (3 rotating gameplay tips) `🤖 AI [Claude for tip text + programmer]` `[ENG]`
