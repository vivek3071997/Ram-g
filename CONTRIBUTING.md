# Contributing to Ram-G

Thank you for your interest in contributing to **Ram-G: Grounded 21st-Century Epic Mythical Action-Adventure**! 

To maintain code quality, gameplay immersion, and technological alignment with our Game Design Documents (GDD), please follow these guidelines and conventions when submitting changes.

---

## 1. Coding Standards & OOP Principles

All gameplay systems are written in **Unreal Engine 5.7.4 C++** and must adhere to clean, production-ready Object-Oriented Programming (OOP) paradigms.

### Object-Oriented Principles to Follow:
- **Encapsulation**: Keep character statistics and physiological variables protected/private where possible, exposing them via controlled `UFUNCTION(BlueprintPure)` getters.
- **Inheritance & Hierarchy**:
  - Base gameplay classes: `ARamGCharacter` and `ARamGEnemy` (inheriting from `ACharacter`).
  - Modular components: All custom sub-systems must be modular components (e.g., `URamGAstraComponent`, `URamGCombatComponent`) to prevent class bloating.
- **Polymorphism**: Override base character jump, combat, or damage reactions dynamically in subclasses (e.g., `AHanumanCharacter` overriding `Jump()` and `Landed()`).

### Naming Conventions:
We strictly follow Unreal Engine naming conventions:
- **Classes**: Prefix with `A` for Actors (e.g., `AAiravatBoss`), `U` for UObjects/Components (e.g., `UGroundedCharacterData`), `E` for Enums (e.g., `EMission0State`).
- **Variables**: Use camelCase prefixing boolean flags with `b` (e.g., `bIsGrappling`).
- **UPROPERTIES**: Always annotate variables exposed to Blueprints with appropriate macro metadata, categories, and tooltips:
  ```cpp
  UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "RamG | Parameters", meta = (ToolTip = "Description"))
  float MetricValue;
  ```

---

## 2. Git Workflow

To maintain a clean and reliable codebase:
1. **Branching**: Create a descriptive feature branch from `master` before starting work:
   ```bash
   git checkout -b feature/your-feature-name
   ```
2. **Commits**: Write clear, descriptive, and atomic commit messages:
   ```bash
   git commit -m "Implement wind column glide forces in VayuWindUpdraft"
   ```
3. **Merging**: Ensure all local compilation tests pass and run your diagnostic suite before opening a Pull Request.

---

## 3. Playtesting & Automated Diagnostics

Before submitting your contribution, you must run the project's **Automated Diagnostic Suite** to verify that all baseline physics, movement, and state controllers compile and run successfully:

1. Open your test arena level with the **`AMission0GameMode`** active.
2. In the console or via Blueprints, invoke:
   ```cpp
   AMission0GameMode::RunMissionDiagnostic();
   ```
3. Verify that the output prints `[PASS]` for all test criteria:
   - Playable Hanuman Character initialization.
   - Double-jump vector boost forces.
   - Tail grapple swing stiffness limits.
   - Fruit pickup and basket inventory incrementing.
   - Vajra nerf parameter limits (exhaustion speed locking).

---

## 4. License

By contributing, you agree that your contributions will be licensed under the project's **MIT License**.
