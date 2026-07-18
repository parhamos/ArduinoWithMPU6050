# Robonix AccelMeter Firmware

# Data Dictionary

---

Document Number : RAD-DAT-001

Version : 1.0.0

Status : Draft

Classification : Internal

Project : Robonix AccelMeter

Language : English

Author : Robonix Development Team

---

# Revision History

| Version | Date | Description | Author |
|----------|------|-------------|--------|
|1.0.0|2026-07-14|Initial Data Dictionary|Robonix Development Team|

---

# Table of Contents

1. Purpose

2. Scope

3. Data Philosophy

4. Data Categories

5. Ownership Rules

6. General Naming Rules

7. General Lifetime Rules

---

# 1. Purpose

This document defines every runtime data object used by the firmware.

Its purpose is to establish a single and authoritative definition for all
firmware data before implementation.

All runtime objects, configuration objects and status objects shall be
defined here before appearing in the source code.

This document is the authoritative reference for the firmware data model.

---

# 2. Scope

This document defines:

• Runtime data

• Configuration data

• Status data

• Measurement data

• Calibration data

• Statistical data

• Shared data structures

• Data ownership

• Access permissions

• Data lifetime

Implementation details are intentionally excluded.

---

# 3. Data Philosophy

The firmware follows a centralized data model.

Every runtime data object shall have:

• One definition

• One owner

• One lifetime

• One documented purpose

Duplicate runtime data is prohibited.

Data duplication increases memory usage and introduces synchronization
errors.

The firmware therefore adopts a Single Source of Truth policy.

---

# 4. Data Categories

Firmware data is divided into the following categories.

---

Runtime Data

Values produced during firmware execution.

Examples

MeasurementFrame

StatisticsData

---

Configuration Data

Values defining firmware behavior.

Examples

DeviceConfiguration

---

Status Data

Current operational state of firmware.

Examples

DeviceStatus

---

Calibration Data

Sensor calibration parameters.

Examples

CalibrationData

---

Temporary Data

Local variables used only inside functions.

Temporary data shall never become part of the firmware model.

---

Constant Data

Compile-time constants.

Examples

kDefaultSampleRate

kStandardGravity

---

# 5. Ownership Rules

Every runtime object shall have exactly one owner.

The owner is responsible for:

Creation

Initialization

Modification

Consistency

Lifetime

Other modules may read shared data only through documented interfaces.

No runtime object shall have multiple owners.

---

# 6. General Naming Rules

Runtime data objects shall use nouns.

Examples

MeasurementFrame

CalibrationData

StatisticsData

DeviceStatus

Configuration objects shall end with

Configuration

Status objects shall end with

Status

Measurement objects shall end with

Frame

Collections shall use plural nouns.

Examples

samples

pages

measurements

---

# 7. General Lifetime Rules

Firmware data shall belong to one of the following lifetime categories.

---

Permanent

Exists during the entire firmware execution.

Example

Model

---

Module Lifetime

Exists as long as the owning module exists.

Example

Internal module state.

---

Function Lifetime

Exists only during function execution.

Example

Temporary variables.

---

Compile-time Lifetime

Exists only during compilation.

Examples

constexpr

enum class

Configuration constants

---

No runtime object shall change its lifetime category without documented
approval.

# 8. Fundamental Data Types

The firmware shall use a limited and standardized set of primitive data
types.

Using consistent data types improves portability, readability and memory
predictability.

---

## Integer Types

The following fixed-width integer types shall be used.

| Type | Size | Usage |
|------|------|------|
| uint8_t | 8 bit | Small counters, states |
| int8_t | 8 bit | Signed small values |
| uint16_t | 16 bit | Sample rate, counters |
| int16_t | 16 bit | Signed measurements |
| uint32_t | 32 bit | Time, frame counters |
| int32_t | 32 bit | Large signed values |

---

## Floating Point Types

| Type | Usage |
|------|------|
| float | Physical values |
| double | Not used in Version 1.0 |

---

## Boolean Type

Logical values shall use

bool

Allowed values

true

false

Integer flags shall not replace Boolean values.

---

## Character Types

| Type | Usage |
|------|------|
| char | Character data |
| char[] | Fixed-size text buffers |

Arduino String is prohibited.

---

# 9. Common Type Definitions

The firmware defines several common aliases to improve readability.

---

Timestamp

Represents elapsed firmware time.

Type

using Timestamp = uint32_t;

Unit

milliseconds (ms)

Owner

Common

---

SampleCounter

Counts acquired samples.

Type

using SampleCounter = uint32_t;

Unit

count

Owner

Model

---

FrameCounter

Counts generated measurement frames.

Type

using FrameCounter = uint32_t;

Unit

count

Owner

Model

---

# 10. Measurement Units

Every physical quantity shall have one documented engineering unit.

No object may represent multiple units simultaneously.

---

## Acceleration

Unit

m/s²

Storage

float

Internal Unit

SI

Conversion to "g"

Performed only by presentation modules.

---

## Temperature

Unit

°C

Storage

float

---

## Time

Unit

milliseconds

Type

Timestamp

---

## Frequency

Unit

Hz

Storage

float

---

## Sample Rate

Unit

Hz

Storage

uint16_t

---

# 11. Coordinate System

The firmware uses a three-axis Cartesian coordinate system.

Axes

X

Y

Z

The axis orientation follows the MPU6050 sensor reference.

Axis mapping shall remain consistent throughout the firmware.

---

# 12. Common Data Objects

## Vector3f

Purpose

Represents a three-dimensional physical vector.

Owner

Common

Fields

x

float

SI Unit

Depends on context

---

y

float

SI Unit

Depends on context

---

z

float

SI Unit

Depends on context

---

Usage

Acceleration

Offset

Filtered values

Calibration

---

## Version

Purpose

Represents firmware version information.

Owner

Common

Fields

major

uint8_t

minor

uint8_t

patch

uint8_t

---

# 13. Unit Consistency Rules

A runtime object shall always use one engineering unit.

Unit conversion shall never occur inside the Model.

Conversions are permitted only inside:

Display

Protocol

or other presentation modules.

The Model shall always store values using SI units.

---

# 14. Type Ownership Rules

Common types

↓

Common

Runtime data

↓

Model

Configuration

↓

Model

Status

↓

Model

Temporary variables

↓

Function scope

Compile-time constants

↓

ModuleConfig

This ownership shall not change without architectural approval.
# 15. Measurement Data Objects

Measurement objects represent the physical values acquired and processed
during firmware execution.

These objects form the core runtime data of the firmware.

---

# MeasurementFrame

Purpose

Stores one complete measurement frame.

Owner

Model

Lifetime

Permanent

Access

Read/Write by owning modules

Read-only by other modules

Related Modules

Sensor

Calibration

Filter

Statistics

Display

Protocol

---

Fields

## raw

Type

Vector3f

Description

Raw acceleration directly acquired from the sensor.

Unit

m/s²

Default

0

---

## calibrated

Type

Vector3f

Description

Acceleration after zero-offset calibration.

Unit

m/s²

Default

0

---

## filtered

Type

Vector3f

Description

Acceleration after digital filtering.

Unit

m/s²

Default

0

---

## magnitude

Type

float

Description

Acceleration vector magnitude.

Unit

m/s²

Default

0

Valid Range

0 ...

---

## timestamp

Type

Timestamp

Description

Time when the measurement frame was generated.

Unit

ms

Default

0

---

## frameNumber

Type

FrameCounter

Description

Sequential measurement frame number.

Unit

count

Default

0

---

Rules

Only one MeasurementFrame exists during firmware execution.

The object shall always contain the latest processed measurement.

Historical measurements are outside the scope of Version 1.0.

---

# AccelerationSample

Purpose

Represents one raw acceleration sample.

Owner

Sensor

Lifetime

Temporary

Access

Private to Sensor module

Related Modules

Sensor

---

Fields

## value

Type

Vector3f

Description

Raw acceleration sample.

Unit

m/s²

---

## timestamp

Type

Timestamp

Description

Acquisition time.

Unit

ms

---

Rules

AccelerationSample is a temporary acquisition object.

It shall never become part of the permanent firmware model.

---

# Measurement Data Flow

Sensor

↓

AccelerationSample

↓

MeasurementFrame.raw

↓

MeasurementFrame.calibrated

↓

MeasurementFrame.filtered

↓

MeasurementFrame.magnitude

↓

Statistics

↓

Display / Protocol

This processing sequence shall remain unchanged throughout Version 1.0.

---

# Measurement Integrity Rules

Every measurement frame shall represent one acquisition cycle.

Fields belonging to the same frame shall originate from the same sensor
update.

Partially updated measurement frames are prohibited.

The timestamp shall correspond to the acquisition cycle represented by
the frame.

The frameNumber shall increase monotonically during normal firmware
operation.
# 16. Configuration Data Objects

Configuration objects define the operational behavior of the firmware.

Unlike measurement data, configuration values change infrequently and
remain valid until explicitly modified.

Configuration data shall be stored in the Model.

---

# DeviceConfiguration

Purpose

Stores all configurable runtime parameters.

Owner

Model

Lifetime

Permanent

Access

Read/Write by Application

Read/Write by Configuration Module (future)

Read-only by all other modules

Related Modules

Application

Sensor

Calibration

Filter

Display

Protocol

---

Fields

## sampleRate

Type

uint16_t

Description

Measurement sampling frequency.

Unit

Hz

Default

100

Valid Range

1 ... 1000

---

## unit

Type

AccelerationUnit

Description

Display unit for acceleration.

Stored Unit

Enumeration

Default

Metric

Remarks

Internal calculations always use SI units.

Only presentation modules shall use this field.

---

Rules

Configuration values shall remain valid until explicitly modified.

Configuration changes shall not invalidate measurement data.

Configuration shall not contain temporary runtime values.

---

# Future Configuration Objects

The following configuration objects are reserved for future firmware
versions.

DisplayConfiguration

ProtocolConfiguration

FilterConfiguration

CalibrationConfiguration

These objects are outside the scope of Version 1.0.

---

# Configuration Integrity Rules

Configuration objects shall contain only user-configurable parameters.

Calculated values shall never be stored inside configuration objects.

Configuration values shall survive module updates during firmware
execution.

Each configuration parameter shall have:

• Defined purpose

• Defined type

• Defined default value

• Defined valid range

Configuration objects shall never store measurement data.

---

# Configuration Update Rules

Configuration shall be modified only through documented APIs.

Modules shall never modify configuration directly unless they are the
approved owner.

Configuration changes shall become effective only after successful
validation.

Invalid configuration values shall be rejected.

Previous valid configuration shall remain unchanged after a failed
configuration update.

---

# Configuration Data Flow

Application

↓

Validation

↓

DeviceConfiguration

↓

Functional Modules

↓

Firmware Execution

The data flow shall remain unidirectional.

Modules may read configuration data but shall not bypass the documented
configuration interface.
# 17. Status Data Objects

Status objects represent the current operational state of the firmware.

Status data describes the condition of the system at runtime.

Status objects shall not contain measurement values or configuration
parameters.

All status data shall be stored in the Model.

---

# DeviceStatus

Purpose

Represents the current operating state of the firmware.

Owner

Model

Lifetime

Permanent

Access

Read/Write by owning modules

Read-only by all other modules

Related Modules

Application

Scheduler

Sensor

Calibration

Statistics

Display

Protocol

---

Fields

## firmware

Type

FirmwareState

Description

Current firmware execution state.

Default

Stopped

---

## sensor

Type

SensorState

Description

Current sensor status.

Default

Disconnected

---

## serial

Type

CommunicationState

Description

Current serial communication status.

Default

Disconnected

---

## calibration

Type

CalibrationState

Description

Current calibration status.

Default

NotCalibrated

---

Rules

Status fields shall represent only the current firmware condition.

Status values shall not contain historical information.

Status values shall be updated immediately after a state transition.

---

# Status Integrity Rules

Every status field shall represent exactly one subsystem.

A status field shall never represent multiple independent conditions.

Status values shall always correspond to a valid enumeration value.

Invalid or undefined status values are prohibited.

---

# State Transition Rules

Status transitions shall occur only after successful completion of the
associated operation.

Examples

Disconnected

↓

Connected

↓

Running

↓

Error

Transitions shall be deterministic and documented by the owning module.

Unexpected transitions are prohibited.

---

# Status Update Policy

Each functional module is responsible for updating the status fields
related to its own operation.

Examples

Sensor Module

↓

DeviceStatus.sensor

---

Calibration Module

↓

DeviceStatus.calibration

---

Communication Module

↓

DeviceStatus.serial

---

Application

↓

DeviceStatus.firmware

No module shall modify status fields belonging to another module.

---

# Status Data Flow

Functional Module

↓

Status Update

↓

DeviceStatus

↓

Display

↓

Protocol

↓

Diagnostic Information

Status data shall always reflect the latest confirmed system state.

---

# Diagnostic Usage

Status data is intended for:

System monitoring

LCD indication

Serial diagnostics

Debug messages

Future protocol interfaces

Status objects shall not be used to control firmware execution directly.

They describe the current state but do not implement system behavior.

# 18. Data Ownership Rules

Every runtime data object shall have exactly one owner.

The owner is responsible for:

• Creation

• Initialization

• Modification

• Validation

• Lifetime management

Ownership shall never be shared.

Only the designated owner may modify a data object.

Other modules may access the data only through documented interfaces.

---

# 19. Data Access Rules

The firmware defines three levels of data access.

---

Owner Access

Read

Write

Modify

Validate

---

Consumer Access

Read only

Consumers shall never modify shared runtime data directly.

---

Temporary Access

Function-local variables

Temporary buffers

Intermediate calculations

Temporary data shall never become a permanent firmware object unless
explicitly defined in the Model.

---

# 20. Data Lifetime Rules

Every data object belongs to one lifetime category.

---

Permanent

Exists during the complete firmware execution.

Examples

MeasurementFrame

StatisticsData

CalibrationData

DeviceConfiguration

DeviceStatus

---

Module Lifetime

Internal state owned by a module.

Exists while the module instance exists.

This data shall not be exposed through the firmware Model.

---

Function Lifetime

Temporary local variables.

Destroyed when the function returns.

---

Compile-time Lifetime

constexpr

Configuration constants

Enumerations

Type aliases

---

A data object shall never change its lifetime category during execution.

---

# 21. Data Ownership Matrix

| Data Object | Owner | Primary Producer | Primary Consumers |
|-------------|-------|------------------|-------------------|
| MeasurementFrame | Model | Sensor / Calibration / Filter | Statistics, Display, Protocol |
| StatisticsData | Model | Statistics | Display, Protocol |
| CalibrationData | Model | Calibration | Sensor, Filter |
| DeviceConfiguration | Model | Application | Sensor, Display, Protocol |
| DeviceStatus | Model | Functional Modules | Display, Protocol |

---

# 22. Data Modification Rules

Runtime data shall be modified only by the module responsible for that
processing stage.

Examples

Sensor Module

↓

MeasurementFrame.raw

---

Calibration Module

↓

MeasurementFrame.calibrated

---

Filter Module

↓

MeasurementFrame.filtered

---

Statistics Module

↓

StatisticsData

No module shall overwrite data owned by another processing stage.

Previously generated values shall remain valid until replaced by the
responsible module.

---

# 23. Data Consistency Rules

A runtime object shall always remain internally consistent.

Partial updates are prohibited.

Related fields shall represent the same processing cycle.

Example

MeasurementFrame.raw

MeasurementFrame.calibrated

MeasurementFrame.filtered

MeasurementFrame.timestamp

MeasurementFrame.frameNumber

shall correspond to the same acquisition cycle.

---

# 24. Data Validation Rules

Every module shall validate the data before writing it to the Model.

Examples

Sensor availability

Valid configuration

Physical limits

Enumeration validity

Invalid data shall not overwrite valid runtime data.

---

# 25. Data Flow Summary

The firmware data flow is defined as follows.

Hardware

↓

Sensor

↓

MeasurementFrame.raw

↓

Calibration

↓

MeasurementFrame.calibrated

↓

Filter

↓

MeasurementFrame.filtered

↓

Statistics

↓

StatisticsData

↓

Display

↓

Protocol

↓

External User

This processing sequence shall remain unchanged throughout Version 1.0.

# 26. Data Dictionary Review Checklist

Every runtime data object shall be reviewed before implementation.

The following checklist shall be completed.

---

Data Definition

□ Object name is unique.

□ Purpose is documented.

□ Owner is defined.

□ Lifetime is defined.

□ Access policy is defined.

□ Related modules are identified.

---

Type Verification

□ Data type is appropriate.

□ Engineering unit is specified.

□ Default value is defined.

□ Valid range is documented.

□ Enumeration values are documented where applicable.

---

Architecture Compliance

□ Object belongs to the correct architectural layer.

□ Ownership complies with the Software Architecture Document.

□ Object does not duplicate existing runtime data.

□ Data flow is documented.

---

Implementation Readiness

□ Object can be implemented without interpretation.

□ Object does not require undocumented assumptions.

□ Object is ready for inclusion in ModelObjects.h.

---

# 27. Relationship to Other Documents

The Data Dictionary shall be interpreted together with the following
documents.

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

RAD-MOD-001

Module Specification

↓

RAD-API-001

API Reference

↓

Firmware Source Code

If a conflict exists, the higher-level document shall take precedence.

---

# 28. Change Management

Any modification to a runtime data object shall be performed through the
following sequence.

Update Data Dictionary

↓

Review

↓

Approval

↓

Update ModelObjects.h

↓

Update Module Specifications

↓

Update API Reference

↓

Update Source Code

Direct modification of firmware data structures without updating this
document is prohibited.

---

# 29. Approval

Document Name

Data Dictionary

Document Number

RAD-DAT-001

Version

1.0.0

Status

APPROVED

State

FROZEN

Approval Authority

Robonix Development Team

After approval, every runtime data object implemented in the firmware
shall conform to this document.

---

# End of Document

Document Name

Data Dictionary

Document Number

RAD-DAT-001

Version

1.0.0

Status

APPROVED

State

FROZEN

############################################################

END OF DOCUMENT

############################################################