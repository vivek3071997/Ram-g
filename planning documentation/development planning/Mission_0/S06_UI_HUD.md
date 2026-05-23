# S06 — UI & HUD Elements | Mission 0 Development Tasks

> **Mission:** Mission 0 — Hanuman's Solar Leap
> **Section:** User Interface, Heads-Up Display, Tutorial Prompts, Menus & Accessibility

| Metric | Value |
|--------|-------|
| Total Tasks | 22 |
| Total Subtasks | 46 |
| 🤖 AI-Assisted Tasks | 10 (45%) |
| 🤝 AI+Human Tasks | 8 (36%) |
| 👤 Human-Only Tasks | 4 (19%) |
| Teams Involved | UI, ENG, ART, WRITE |

---

## Tag Legend
- `🤖 AI` — Fully or mostly achievable by AI
- `🤝 AI+H` — AI drafts/assists, human directs/refines
- `👤 Human` — Requires human expertise
- `[UI]` `[ENG]` `[ART]` `[WRITE]` `[QA]` — Team responsible

---

## 6.1 In-Game HUD Elements

### 6.1.1 Health Bar — Playful Vanara Fruit-Icon Theme

- [ ] Design — Health bar concept (fruit icons replace HP bar; each fruit = 1 HP unit) `🤝 AI+H [Figma AI, DALL-E 3 + UI designer]` `[UI]`
  - [ ] Sketch 3 layout concepts for fruit-based health display `👤 Human` `[UI]`
  - [ ] AI-generate fruit icon variants (glowing, bitten, dark states) `🤖 AI [DALL-E 3, Adobe Firefly]` `[ART]`
  - [ ] Select best concept and finalize layout `👤 Human` `[UI]`
- [ ] Asset creation — Fruit icon states (full, half, empty / 7 icons) `🤝 AI+H [Adobe Firefly + artist]` `[ART]`
  - [ ] Generate 3 icon states per fruit type `🤖 AI [Adobe Firefly]` `[ART]`
  - [ ] Export as sprite atlas (PNG, power-of-2 dimensions) `👤 Human` `[ART]`
- [ ] Animation — Fruit icon pulse on damage, shake on near-death `🤝 AI+H [Claude for tween logic + UI dev]` `[ENG]`
- [ ] Engine implementation — Bind fruit icons to player health component `🤖 AI [GitHub Copilot, Claude]` `[ENG]`
  - [ ] HUD widget updates fruit state on health change event `🤖 AI [GitHub Copilot]` `[ENG]`
- [ ] QA — Test all 7 damage states, death trigger, and health restore `👤 Human` `[QA]`

### 6.1.2 Stamina / Energy Ring — Tail Glow Drain

- [ ] Design — Circular energy ring around tail icon; orange glow drains clockwise `🤝 AI+H [Figma AI + UI designer]` `[UI]`
  - [ ] Sketch ring design with tail motif in center `👤 Human` `[UI]`
  - [ ] Finalize color scheme (full = bright orange, empty = grey) `👤 Human` `[UI]`
- [ ] Asset — Ring fill material (radial progress shader) `🤖 AI [GitHub Copilot for shader logic]` `[ENG]`
- [ ] Engine implementation — Bind ring fill to stamina component `🤖 AI [GitHub Copilot]` `[ENG]`
  - [ ] Auto-refill animation when stamina regenerates `🤖 AI [GitHub Copilot]` `[ENG]`
- [ ] QA — Test drain on sprint, grapple, ability use; regen timing `👤 Human` `[QA]`

### 6.1.3 Mission Objective Text Display

- [ ] Design — Minimal top-center objective text (fade in/out on step change) `🤝 AI+H [Figma AI + UI designer]` `[UI]`
- [ ] Engine implementation — Objective text widget driven by mission flow events `🤖 AI [GitHub Copilot, Claude]` `[ENG]`
  - [ ] Text animates in (slide + fade) on new step, fades out after 4 seconds `🤖 AI [GitHub Copilot]` `[ENG]`

### 6.1.4 Altitude Indicator — Sanskrit Numeral Styled

- [ ] Design — Vertical altitude meter on screen edge; Sanskrit numeral font `🤝 AI+H [Figma AI + UI designer]` `[UI]`
  - [ ] Research and confirm Sanskrit/Devanagari numeral glyphs `🤖 AI [Claude]` `[WRITE]`
  - [ ] Design vertical bar with numeral readout `👤 Human` `[UI]`
- [ ] Font — Devanagari numeral font license or custom glyph set `🤝 AI+H [Google Fonts + UI designer]` `[UI]`
- [ ] Engine implementation — Altitude indicator bound to player Z position `🤖 AI [GitHub Copilot]` `[ENG]`
  - [ ] Scale player Z to in-world altitude units for readout `🤖 AI [GitHub Copilot]` `[ENG]`

### 6.1.5 Vayu Rescue Counter — 3 Wind-Leaf Icons

- [ ] Design — 3 wind-leaf icons in top corner; leaf greys out on rescue use `🤝 AI+H [DALL-E 3 + UI designer]` `[UI]`
  - [ ] AI-generate wind-leaf icon (active and greyed states) `🤖 AI [Adobe Firefly, DALL-E 3]` `[ART]`
  - [ ] Layout 3 icons horizontally `👤 Human` `[UI]`
- [ ] Engine implementation — Counter bound to VayuRescueSystem (see S08) `🤖 AI [GitHub Copilot]` `[ENG]`
  - [ ] On rescue use: animate leaf grey-out + gentle puff VFX `🤝 AI+H [Niagara + VFX artist]` `[VFX]`

### 6.1.6 Sacred Fruit Basket Progress Indicator

- [ ] Design — Basket icon fills with mini-fruits as player collects (0/7 → 7/7) `🤝 AI+H [DALL-E 3 + UI designer]` `[UI]`
  - [ ] Design basket icon with fill overlay system `👤 Human` `[UI]`
  - [ ] AI-generate fruit fill stages (1 through 7 fruits inside) `🤖 AI [Adobe Firefly]` `[ART]`
- [ ] Engine implementation — Bound to fruit collect counter (see S03) `🤖 AI [GitHub Copilot]` `[ENG]`
  - [ ] Basket bounce animation on each fruit collect `🤖 AI [GitHub Copilot for tween]` `[ENG]`

---

## 6.2 Dialogue & Subtitle System

- [ ] Subtitle display system design (position, max characters per line, fade timing) `🤝 AI+H [Claude + UI designer]` `[UI]`
  - [ ] Define subtitle box position (lower-center), opacity, background blur `👤 Human` `[UI]`
  - [ ] Set max 2 lines × 42 characters before wrap `👤 Human` `[UI]`
- [ ] Devanagari font rendering (Sanskrit text display) `🤝 AI+H [Google Fonts Noto + UI dev]` `[ENG]`
  - [ ] Integrate Noto Sans Devanagari font into engine `🤖 AI [GitHub Copilot]` `[ENG]`
  - [ ] Test full Sanskrit phoneme coverage `👤 Human` `[QA]`
- [ ] English subtitle track — import and time-sync to all VO clips `🤝 AI+H [Claude for text + audio engineer]` `[AUDIO]`
- [ ] Hindi subtitle track — translate all lines, time-sync `🤝 AI+H [DeepL + localizer review]` `[WRITE]`
- [ ] Subtitle timing pipeline — export from VO session → engine import `👤 Human` `[AUDIO]`
- [ ] Subtitle style guide (font size 18pt min, stroke, shadow, background panel) `🤖 AI [Claude]` `[UI]`

---

## 6.3 Tutorial Prompt System

- [ ] Tutorial card design template (controller glyph + action word + icon) `🤝 AI+H [Figma AI + UI designer]` `[UI]`
  - [ ] Design card frame in Vanara wooden-plaque style `👤 Human` `[UI]`
  - [ ] Define 3 card states: appear, active, dismiss `👤 Human` `[UI]`
- [ ] Tutorial prompt — Jump mechanic (triggered at first orchard jump surface) `🤖 AI [GitHub Copilot, Claude]` `[ENG]`
  - [ ] Write prompt text: "Press [X] to Jump — hold for extra height!" `🤖 AI [Claude]` `[WRITE]`
  - [ ] Implement proximity trigger near first jump pad `🤖 AI [GitHub Copilot]` `[ENG]`
- [ ] Tutorial prompt — Vine grapple (triggered near first vine) `🤖 AI [GitHub Copilot]` `[ENG]`
  - [ ] Write prompt text: "Aim tail at the vine — Press [R2] to Grapple!" `🤖 AI [Claude]` `[WRITE]`
- [ ] Tutorial prompt — Thermal updraft (triggered at Zone 1→2 boundary) `🤖 AI [GitHub Copilot]` `[ENG]`
  - [ ] Write prompt text: "Step into the warm air column — Vayu lifts you!" `🤖 AI [Claude]` `[WRITE]`
- [ ] Tutorial prompt — Windwheel puzzle (triggered near first windwheel) `🤖 AI [GitHub Copilot]` `[ENG]`
  - [ ] Write prompt text: "Push the stone wheel to redirect the wind currents" `🤖 AI [Claude]` `[WRITE]`
- [ ] Tutorial prompt — Cloud platform timing (triggered at first cloud pad) `🤖 AI [GitHub Copilot]` `[ENG]`
  - [ ] Write prompt text: "Cloud pads dissolve in 3 seconds — move fast!" `🤖 AI [Claude]` `[WRITE]`
- [ ] Context-trigger logic — Show prompt once only; never repeat if player succeeds `🤖 AI [GitHub Copilot]` `[ENG]`

---

## 6.4 Menus & Screens (Mission 0 Specific)

- [ ] Mission 0 loading screen — Hanuman leaping at the sun, Sanskrit quote overlay `🤝 AI+H [Midjourney + art director + UI designer]` `[ART]`
  - [ ] AI generate hero image (Hanuman mid-leap, golden sunrise) `🤖 AI [Midjourney, DALL-E 3]` `[ART]`
  - [ ] Art director review and select best image `👤 Human` `[ART]`
  - [ ] Add Sanskrit quote text overlay with Devanagari font `👤 Human` `[UI]`
- [ ] Player death screen — "The Sky forgives… but the Sun waits" theme `🤝 AI+H [Midjourney + UI designer]` `[ART]`
  - [ ] AI-generate atmospheric dark-sky background `🤖 AI [Midjourney]` `[ART]`
  - [ ] Add quote text + "Try Again / Checkpoint / Main Menu" buttons `👤 Human` `[UI]`
- [ ] Mission complete screen — Golden sky reveal with victory stinger `🤝 AI+H [Midjourney + UI designer]` `[ART]`
- [ ] Pause menu — Mission 0 skinned (Sumeru mountain motif) `🤝 AI+H [Figma AI + UI designer]` `[UI]`

---

## 6.5 Accessibility UI

- [ ] Colorblind mode toggle — Remap lightning ring colors (yellow/blue instead of white/red) `🤖 AI [GitHub Copilot, Claude]` `[ENG]`
  - [ ] Implement global colorblind post-process shader swap `🤖 AI [GitHub Copilot]` `[ENG]`
  - [ ] Test 3 colorblind presets (Deuteranopia, Protanopia, Tritanopia) `👤 Human` `[QA]`
- [ ] Subtitle font size scaling — Slider from 80% → 150% base size `🤖 AI [GitHub Copilot]` `[ENG]`
- [ ] Input remapping screen — Fully rebindable controller + keyboard `🤝 AI+H [GitHub Copilot + UI designer]` `[ENG]`
  - [ ] Build remapping UI widget `🤖 AI [GitHub Copilot]` `[ENG]`
  - [ ] Persist bindings to save file `🤖 AI [GitHub Copilot]` `[ENG]`
- [ ] High-contrast HUD mode — All HUD elements outlined in solid white `🤖 AI [GitHub Copilot]` `[ENG]`
