---
name: Bug Report 🐞
about: Report gameplay physics, compilation glitches, or biomechanical mismatches.
title: '[BUG]: '
labels: bug
assignees: ''
---

## Description
Provide a clear and concise description of the bug. Explain what happened compared to what was expected according to the GDD (Game Design Document) guidelines.

## Steps to Reproduce
Steps to reproduce the behavior:
1. Load Level/Scene '...'
2. Control Character '...' (e.g. Kid Hanuman)
3. Perform Action '...' (e.g., Double jump into thermal wind updrafts)
4. See error '...'

## Active Gameplay State & Diagnostic Output
Please run the diagnostic suite in-game and paste the log output here if applicable:
1. Open the console or blueprint level script.
2. Execute `AMission0GameMode::RunMissionDiagnostic()`.
3. Paste the relevant console logs:
```text
(Paste logs here)
```

## Grounded Biomechanical & Physics Context
Does this issue impact physiological parameters or physical simulation?
- **Affected Systems**: [ ] Stamina/ATP [ ] Lactic Acid Accumulation [ ] Tail Grapple Hook/Spring Forces [ ] Cloud Dissipation Timer [ ] Boss Behavior States
- **Detailed Mechanics**: (e.g., "Hanuman's lactic acid accumulation reached critical lock state but failed to decelerate walk speed to 250 units.")

## Environment & Build Info
- **Unreal Engine Version**: 5.7.4
- **Operating System**: Windows
- **Build Target**: [ ] Development Editor [ ] Development Client [ ] Shipping
- **IDE**: [ ] Visual Studio 2022 [ ] Rider [ ] Other

## Visual Proof / Code Snips
If applicable, add screenshots, screen recordings, or code blocks to help explain your problem.
