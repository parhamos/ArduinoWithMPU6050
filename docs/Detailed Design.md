# Robonix AccelMeter Firmware

# Detailed Design

---

Document

Detailed Design

Document Number

RAD-DDD-001

Version

1.0.0

Status

APPROVED

State

FROZEN

---

# 1. Purpose

This document defines the implementation-level design decisions that
are not covered by the Software Architecture Document or Module
Specifications.

It serves as the bridge between the approved design documents and the
firmware implementation.

---

# 2. Firmware Structure

Application

↓

Scheduler

↓

Sensor

↓

Calibration

↓

Filter

↓

Statistics

↓

Display

Protocol

Display and Protocol execute independently using the same runtime data.

---

# 3. Object Lifetime

Exactly one instance shall exist for each module.

Application

Scheduler

Model

Sensor

Calibration

Filter

Statistics

Display

Protocol

No dynamic creation of module objects is permitted.

---

# 4. Initialization Order

The firmware shall initialize modules in the following order.

Model

↓

Sensor

↓

Calibration

↓

Filter

↓

Statistics

↓

Display

↓

Protocol

↓

Scheduler

↓

Application enters RUN state.

---

# 5. Scheduler Execution Order

Each scheduler cycle shall execute:

Sensor.update()

↓

Calibration.update()

↓

Filter.update()

↓

Statistics.update()

↓

Display.update()

↓

Protocol.update()

The execution order shall never change without updating the approved
architecture.

---

# 6. Data Flow

Sensor writes MeasurementFrame.

Calibration updates calibrated values.

Filter updates filtered values.

Statistics updates StatisticsData.

Display reads Model only.

Protocol reads Model only.

Only producer modules may modify their assigned runtime objects.

---

# 7. Model Ownership

Model is the only shared runtime storage.

Modules shall exchange information exclusively through the Model.

No module shall directly access another module's internal data.

---

# 8. Memory Policy

Static allocation only.

Dynamic allocation is prohibited.

No malloc()

No free()

No new

No delete

Module buffers shall have fixed sizes defined in ModelConfig.

---

# 9. Error Handling

Each module returns execution status.

A module shall never terminate firmware execution.

Errors shall be propagated to the Application through approved runtime
status fields.

---

# 10. Timing Policy

Every update() function shall execute once per Scheduler cycle.

Execution shall be deterministic.

Busy waiting shall be avoided.

Long blocking delays are prohibited.

---

# 11. Public Interface Rules

Every module shall expose only:

Constructor

begin()

update(Model&)

No additional public methods are permitted unless approved by the
architecture documentation.

---

# 12. Internal State Policy

Internal implementation state is permitted only when required.

Examples:

Filter algorithm state

Statistics window buffer

Display page state

Protocol communication state

Internal state shall remain private.

---

# 13. Coding Rules

Implementation shall comply with:

Project Rules

Coding Standard

Architecture

Data Dictionary

Module Specifications

No implementation may contradict approved documentation.

---

# 14. Version Control Policy

Documentation shall be updated before implementation changes.

Source code shall always conform to the latest approved documents.

---

# 15. Completion Criteria

Firmware implementation is considered complete only when:

All approved modules are implemented.

Compilation succeeds without warnings.

Module interfaces match the specifications.

Unit tests pass.

Documentation and implementation remain synchronized.

---

END OF DOCUMENT