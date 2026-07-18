# Robonix AccelMeter Firmware

# Module Specification

---

Module

Protocol

Document Number

RAD-MOD-009

Version

1.0.0

Status

Draft

Classification

Internal

Language

English

---

# Revision History

| Version | Date | Description | Author |
|----------|------|-------------|--------|
|1.0.0|2026-07-14|Initial Module Specification|Robonix Development Team|

---

# Table of Contents

1. Purpose

2. Responsibilities

3. Architectural Position

4. Dependencies

5. Public Interface

6. Data Ownership

7. Communication Flow

8. Error Handling

9. Timing Requirements

10. Constraints

11. Verification Checklist

12. Future Extensions

13. Relationship to Other Documents

14. Approval

---

# 1. Purpose

The Protocol module transfers firmware information to external systems.

Communication data is obtained exclusively from the Model.

The Protocol module formats runtime information into communication
frames suitable for the selected transport interface.

The Protocol module performs no data acquisition and no data
processing.

---

# 2. Responsibilities

The Protocol module shall:

• Read runtime data from the Model.

• Build communication frames.

• Transmit communication frames.

• Execute deterministically.

The Protocol module shall not:

• Acquire sensor measurements.

• Apply calibration.

• Perform signal filtering.

• Calculate statistical values.

• Modify runtime data.

• Control application logic.

---

# 3. Architectural Position

Layer

Functional Module Layer

Architecture Level

Layer 4

Parent Module

Scheduler

Child Modules

None

The Protocol module performs information transfer after runtime
processing has been completed.

---

# 4. Dependencies

The Protocol module depends on:

Model

ModelObjects

ModelConfig

Communication driver

Arduino basic types

The Protocol module shall not depend on:

Sensor hardware

MPU6050 library

Calibration implementation

Filter implementation

Statistics implementation

Display implementation

Application

Scheduler implementation

Communication with other functional modules shall occur only through
the Model.
# 5. Public Interface

The Protocol module exposes only the interfaces required for
initialization and communication updates.

The public interface shall remain stable throughout Version 1.0.

---

## Constructor

Purpose

Construct the Protocol object.

Responsibilities

Construct internal protocol resources.

Remarks

The constructor shall not initialize the communication interface.

The constructor shall not allocate dynamic memory.

---

## begin()

Purpose

Initialize the communication subsystem.

Responsibilities

Initialize the communication driver.

Prepare the communication interface for runtime operation.

Return

bool

Returns

true

Initialization completed successfully.

false

Initialization failed.

---

## update()

Purpose

Transmit runtime information to the external interface.

Prototype

bool update(Model& model)

Responsibilities

Read runtime data from the Model.

Build communication frames.

Transmit communication frames.

Return

bool

Returns

true

Communication completed successfully.

false

Communication failed.

---

# 6. Data Ownership

The Protocol module owns no runtime process data.

All transmitted runtime information is owned by the Model.

The Protocol module reads runtime data from the Model.

The Protocol module shall not modify:

MeasurementFrame

CalibrationData

StatisticsData

DeviceConfiguration

or any other runtime object.

---

# 7. Internal Objects

The Protocol module may contain private implementation objects required
for communication.

Examples include:

Transmit buffer

Frame builder

Communication state variables

Protocol parser state (if applicable)

Temporary formatting buffers

These objects are private to the Protocol module.

Persistent runtime process data shall remain exclusively inside the
Model.

# 8. Communication Flow

The Protocol module executes once during each Scheduler cycle.

The communication sequence shall be:

Scheduler calls Protocol::update(Model)

↓

Read runtime data from the Model

↓

Build communication frame

↓

Transmit communication frame

↓

Return execution status

The Protocol module performs no additional processing after frame
transmission.

---

# 9. Interaction with the Model

The Protocol module communicates exclusively through the Model.

The interaction sequence is:

Read runtime data

↓

Format communication frame

↓

Transmit frame

↓

Return control to the Scheduler

The Protocol module shall not communicate directly with:

Sensor

Calibration

Filter

Statistics

Display

Application

---

# 10. Timing Requirements

The Protocol module shall execute exactly once during each Scheduler
cycle.

Requirements

Deterministic execution.

One communication cycle per Scheduler cycle.

No blocking delays beyond those required by the communication
interface.

No waiting for external events.

Execution time shall remain bounded.

The Protocol module shall complete execution before returning control
to the Scheduler.

---

# 11. Communication State

The Protocol module may maintain internal state required for
communication management.

Examples include:

Transmit buffer

Frame assembly state

Sequence counter

Communication status

Temporary formatting buffers

Communication state is private to the Protocol module.

Communication state shall not be exposed through the public interface.

Runtime process data shall remain exclusively inside the Model.

# 12. Constraints

The following architectural constraints apply.

The Protocol module shall not:

Read hardware sensors.

Acquire measurements.

Apply calibration.

Perform signal filtering.

Calculate statistical values.

Modify runtime objects stored in the Model.

Allocate dynamic memory.

Control application behavior.

The Protocol module shall remain independent of all processing modules.

The selected communication protocol shall not change the public
interface of the module.

Version 1.0 defines the Protocol module as a transmit-only module.

Receive functionality is reserved for future firmware versions.

---

# 13. Verification Checklist

The Protocol module shall satisfy the following verification items
before approval.

---

Architecture Verification

□ Located in Layer 4.

□ Communicates only through the Model.

□ Owns no runtime process data.

□ Performs communication only.

---

Functional Verification

□ Initializes successfully.

□ Reads runtime data correctly.

□ Builds communication frames correctly.

□ Transmits communication frames successfully.

□ Completes one communication cycle per Scheduler cycle.

---

Interface Verification

□ Public interface matches the approved API.

□ begin() initializes the communication subsystem.

□ update(Model&) performs one communication cycle.

□ No undocumented public functions.

---

Coding Verification

□ Complies with Coding Standard.

□ No dynamic memory allocation.

□ Communication state remains private.

□ No modification of runtime process data.

□ No undocumented behavior.

---

# 14. Future Extensions

The following capabilities are reserved for future firmware versions.

• Receive support.

• Command processing.

• Bidirectional communication.

• Multiple communication protocols.

• Packet acknowledgment.

Future extensions shall preserve:

Deterministic execution.

Stable public interface.

Architectural independence.

The Protocol module shall remain responsible only for communication.

---

# 15. Relationship to Other Documents

This specification shall be interpreted together with:

RAD-PRD-001

Project Rules

↓

RAD-PVD-001

Project Vision

↓

RAD-SAD-001

Software Architecture

↓

RAD-COD-001

Coding Standard

↓

RAD-DAT-001

Data Dictionary

↓

RAD-MOD-009

Protocol Module Specification

↓

Firmware Source Code

If a conflict exists, the higher-level document shall take precedence.

---

# 16. Approval

Document Name

Protocol Module Specification

Document Number

RAD-MOD-009

Module

Protocol

Version

1.0.0

Status

APPROVED

State

FROZEN

Approval Authority

Robonix Development Team

After approval, every implementation of the Protocol module shall conform
to this specification.

Any architectural modification shall first be reflected in:

Project Vision

↓

Software Architecture

↓

Data Dictionary

↓

Protocol Module Specification

↓

Source Code

Direct modification of the implementation without updating the approved
documentation is prohibited.

---

# End of Document

Document Name

Protocol Module Specification

Document Number

RAD-MOD-009

Version

1.0.0

Status

APPROVED

State

FROZEN

############################################################

END OF DOCUMENT

############################################################