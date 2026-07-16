# Robonix AccelMeter Firmware

# Git Workflow

---

Document Number : RAD-GIT-001

Version : 1.0.0

Status : Approved

---

# Purpose

Define the Git workflow used during firmware development.

---

# Main Branches

main

Stable and released firmware.

develop

Current development version.

feature/<name>

New feature implementation.

bugfix/<name>

Bug fixes.

hotfix/<name>

Critical fixes for released versions.

---

# Commit Rules

Each commit shall:

- Perform one logical change.
- Compile successfully.
- Use a meaningful commit message.

Examples

feat(sensor): add auto calibration

fix(filter): correct IIR coefficient

docs(api): update Protocol API

refactor(model): simplify data access

---

# Commit Types

feat

fix

docs

refactor

test

style

chore

---

# Merge Rules

Feature branches shall be merged into develop.

Only tested code may be merged into main.

Direct commits to main are prohibited.

---

# Version Tags

Release tags shall follow Semantic Versioning.

Examples

v1.0.0

v1.0.1

v1.1.0

v2.0.0

---

# Repository Rules

No generated files.

No build output.

No temporary files.

No personal configuration files.

.gitignore shall be used.

---

# Release Rule

Every release shall include:

Updated ChangeLog

Passing build

Updated version number

Git tag

---

END OF DOCUMENT