# Robonix AccelMeter Firmware

# Project Rules Document (PRD)

---

Document Number : RAD-PRD-001

Version : 1.0.0

Status : APPROVED

Classification : Internal

Project : Robonix AccelMeter

Language : English

Author : Robonix Development Team

---

# Revision History

| Version | Date | Description | Author |
|----------|------|-------------|--------|
| 1.0.0 | 2026-07-14 | Initial Project Rules | Robonix Development Team |

---

# 1. Purpose

This document defines the mandatory rules governing the development of the Robonix AccelMeter firmware.

All project documentation, software architecture, source code, testing activities and future maintenance shall comply with this document.

This document has the highest priority within the project.

---

# 2. Scope

These rules apply to:

- Documentation
- Software Architecture
- Source Code
- Module Design
- APIs
- Git Workflow
- Testing
- Maintenance
- Future Development

---

# 3. Document Hierarchy

The following document precedence shall apply.

Project Rules

↓

Project Vision

↓

Software Architecture

↓

Coding Standard

↓

Data Dictionary

↓

Module Specification

↓

API Reference

↓

Source Code

If conflicts occur, the higher-level document shall prevail.

---

# 4. General Development Rules

## RULE-001

Documentation shall be completed before implementation.

---

## RULE-002

Approved documents shall become frozen.

They shall not be modified during Version 1.0 except to correct documented errors.

---

## RULE-003

Software architecture shall not change during Version 1.0.

Future architectural improvements shall be recorded for Version 2.

---

## RULE-004

Only one module shall be developed at a time.

Parallel implementation of multiple modules is prohibited.

---

## RULE-005

Each completed module shall successfully compile before development continues.

---

## RULE-006

Every completed module shall be committed to Git.

One commit shall represent one logical change.

---

## RULE-007

Refactoring is prohibited during Version 1.0 unless required to correct defects.

---

## RULE-008

Public APIs shall remain stable after approval.

---

## RULE-009

All runtime data shall be stored in the Model.

The Model is the Single Source of Truth.

---

## RULE-010

Modules shall never communicate directly.

Communication shall occur only through documented interfaces and the Model.

---

# 5. Documentation Rules

## DOC-001

Every document shall contain:

- Document Number
- Version
- Status
- Revision History

---

## DOC-002

Every engineering decision shall be documented.

---

## DOC-003

Implementation shall follow approved documentation.

Documentation shall not be retroactively modified to match implementation.

---

## DOC-004

If implementation conflicts with documentation, the documentation shall take precedence until formally revised.

---

# 6. Source Code Rules

## CODE-001

Source code shall comply with the approved Coding Standard.

---

## CODE-002

Source code shall compile without errors before commit.

---

## CODE-003

Every module shall have a single responsibility.

---

## CODE-004

Dynamic memory allocation is prohibited.

---

## CODE-005

Blocking delays during normal execution are prohibited.

---

## CODE-006

Magic numbers are prohibited.

Named constants shall be used.

---

## CODE-007

Global mutable variables are prohibited except approved singleton module instances.

---

# 7. Git Rules

## GIT-001

Each commit shall represent a single logical change.

---

## GIT-002

Commit messages shall follow a consistent format.

Examples

feat(sensor): add MPU6050 initialization

fix(display): correct LCD page switching

docs(sad): complete runtime architecture

---

## GIT-003

Broken builds shall never be committed.

---

# 8. Testing Rules

## TEST-001

Every implemented module shall build successfully.

---

## TEST-002

Module testing shall precede system integration.

---

## TEST-003

Regression testing shall be performed after significant changes.

---

# 9. Change Management

Any proposal affecting:

- Architecture
- Public APIs
- Data Model
- Coding Standard

shall be deferred to the project roadmap unless required to correct a defect in Version 1.0.

---

# 10. Project Philosophy

The project follows these principles:

- Documentation First
- Stable Architecture
- Modular Design
- Deterministic Execution
- Static Memory
- Maintainability
- Testability
- Industrial Software Quality

---

# 11. Approval

Document Name

Project Rules Document

Document Number

RAD-PRD-001

Version

1.0.0

Status

APPROVED

State

FROZEN

---

# End of Document

############################################################

END OF DOCUMENT

############################################################