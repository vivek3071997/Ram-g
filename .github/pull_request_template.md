## Description
Provide a clear description of the changes introduced by this PR. Include design rationale, how it integrates with current OOP paradigms (e.g., custom components, overrides), and what files were added or modified.

## Related Issues
Closes # (issue number)

## Type of Change
- [ ] Bug fix (non-breaking change which fixes an issue)
- [ ] New feature (non-breaking change which adds functionality)
- [ ] Breaking change (fix or feature that would cause existing functionality to not work as expected)
- [ ] GDD Documentation Update

## Biomechanical & Gameplay Alignment
- How does this change comply with the **grounded, realistic parameters** established in the GDD?
- Are physiological metrics (stamina, lactic acid, cardiac output, focus) appropriately scaled?

## Verification & Playtest Logs
- [ ] Compiled successfully in Unreal Engine 5.7.4 / VS2022.
- [ ] Executed `AMission0GameMode::RunMissionDiagnostic()` and all tests returned `[PASS]`.
- Please paste your diagnostic logs below:
```text
(Paste logs here)
```

## Checklist
- [ ] My code adheres to the style guidelines outlined in [CONTRIBUTING.md](../CONTRIBUTING.md).
- [ ] I have commented my code, particularly in hard-to-understand physics/tension calculation loops.
- [ ] I have added appropriate tooltips/categories to any new `UPROPERTY` or `UFUNCTION` macros.
