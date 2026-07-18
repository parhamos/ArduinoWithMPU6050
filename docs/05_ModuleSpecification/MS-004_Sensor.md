# Robonix AccelMeter Firmware

# Module Specification

---

Module

Sensor

Document Number

RAD-MOD-004

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

7. Internal Objects

8. Measurement Flow

9. Error Handling

10. Timing Requirements

11. Constraints

12. Verification Checklist

13. Future Extensions

14. Relationship to Other Documents

15. Approval

---

# 1. Purpose

The Sensor module is responsible for acquiring raw acceleration data
from the MPU6050 sensor.

The module converts the acquired values into engineering units and
updates the MeasurementFrame runtime object.

The Sensor module performs no filtering, calibration or statistical
processing.

Its responsibility is limited to reliable measurement acquisition.

---

# 2. Responsibilities

The Sensor module shall:

• Initialize the MPU6050 device.

• Verify sensor availability.

• Acquire raw acceleration measurements.

• Convert measurements to engineering units.

• Update MeasurementFrame.

• Report sensor operational status.

The Sensor module shall not:

• Filter measurements.

• Perform calibration.

• Calculate statistics.

• Update the display.

• Transmit protocol data.

• Own runtime data.

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

The Sensor module is the firmware interface to the physical
accelerometer.

It produces measurement data for the firmware.

---

# 4. Dependencies

The Sensor module depends on:

Model

ModelObjects

ModelConfig

SensorConfig

Adafruit MPU6050 Library

Wire Library

Arduino basic types

The Sensor module shall not depend on:

Calibration

Filter

Statistics

Display

Protocol

Application

Scheduler implementation

Communication with other functional modules shall occur only through
the Model.

# 5. Public Interface

The Sensor module exposes only the interfaces required for sensor
initialization and measurement acquisition.

The public interface shall remain stable throughout Version 1.0.

---

## Constructor

Purpose

Construct the Sensor object.

Responsibilities

Construct internal sensor resources.

Remarks

The constructor shall not access hardware.

The constructor shall not initialize the MPU6050.

The constructor shall not perform measurement acquisition.

---

## begin()

Purpose

Initialize the MPU6050 sensor.

Responsibilities

Initialize the I²C interface.

Configure the MPU6050.

Verify sensor communication.

Prepare the sensor for measurement acquisition.

Return

bool

Returns

true

Sensor initialized successfully.

false

Sensor initialization failed.

---

## update()

Purpose

Acquire one measurement frame.

Prototype

bool update(Model& model)

Responsibilities

Read acceleration data from the MPU6050.

Convert raw values to engineering units.

Update the MeasurementFrame contained in the Model.

Update sensor status information when required.

Return

bool

Returns

true

Measurement acquired successfully.

false

Measurement acquisition failed.

---

# 6. Data Ownership

The Sensor module owns no runtime data.

Runtime measurement data is owned by the Model.

The Sensor module acts only as a producer of measurement data.

The Sensor module shall update only the fields within
MeasurementFrame that correspond to sensor measurements.

The Sensor module shall not modify:

StatisticsData

CalibrationData

DeviceConfiguration

except where explicitly permitted by the Software Architecture
Document.

---

# 7. Internal Objects

The Sensor module may contain internal implementation objects required
for communication with the MPU6050.

Examples include:

MPU6050 driver instance

Temporary raw measurement variables

Temporary conversion variables

These objects are private to the Sensor module.

No internal object shall expose runtime data outside the module.

# 8. Measurement Flow

The Sensor module acquires one complete measurement frame during each
execution cycle.

The measurement sequence shall be:

Scheduler calls Sensor::update(Model)

↓

Verify sensor communication

↓

Read raw acceleration values

↓

Convert raw values to engineering units

↓

Update MeasurementFrame

↓

Return execution status

The Sensor module shall not perform any additional processing after
updating the MeasurementFrame.

---

# 9. Interaction with the Model

The Sensor module communicates with other firmware modules exclusively
through the Model.

The interaction sequence is:

Obtain MeasurementFrame reference

↓

Update acceleration values

↓

Update measurement timestamp (if enabled)

↓

Update sensor status

↓

Return to Scheduler

The Sensor module shall not communicate directly with:

Filter

Statistics

Display

Protocol

Application

---

# 10. Measurement Update Policy

Each execution cycle produces one logical measurement frame.

The Sensor module shall overwrite the previous measurement values with
the latest acquired data.

Historical measurements are not stored by the Sensor module.

Storage of historical data, averaging, peak detection and other
processing functions belong to dedicated functional modules.

---

# Data Flow

MPU6050

↓

Sensor

↓

MeasurementFrame

↓

Model

↓

Scheduler

↓

Filter

↓

Statistics

↓

Display

↓

Protocol

The Sensor module is the only producer of MeasurementFrame data in
Version 1.0.

# 11. Error Handling

The Sensor module is responsible for detecting sensor-related errors.

Typical error conditions include:

• MPU6050 communication failure.

• I²C initialization failure.

• Invalid sensor response.

• Measurement acquisition failure.

The Sensor module shall:

Return false from update() when measurement acquisition fails.

Return false from begin() when initialization fails.

Update only the sensor-related fields of DeviceStatus when required.

The Sensor module shall not attempt application-level recovery.

System-level recovery is the responsibility of the Application module.

---

# 12. Timing Requirements

The Sensor module shall execute once during each Scheduler cycle.

Requirements

One measurement acquisition per execution cycle.

Deterministic execution.

No blocking delays.

No unnecessary retries inside update().

The Sensor module shall complete execution before returning control to
the Scheduler.

Sampling frequency is determined by the Scheduler execution rate and
system configuration.

---

# 13. Constraints

The following constraints apply.

The Sensor module shall not:

Perform signal filtering.

Perform calibration.

Calculate statistics.

Store historical measurements.

Access display hardware.

Transmit protocol data.

Allocate dynamic memory.

Modify runtime objects outside MeasurementFrame and the sensor-related
fields of DeviceStatus.

The Sensor module shall remain independent of all other functional
modules.

---

# 14. Verification Checklist

The Sensor module shall satisfy the following verification items before
approval.

Architecture Verification

□ Located in Layer 4.

□ Accesses hardware only through approved drivers.

□ Communicates with other modules only through the Model.

□ Owns no runtime data.

Functional Verification

□ Initializes the MPU6050 successfully.

□ Acquires one measurement frame per execution cycle.

□ Converts measurements to engineering units.

□ Updates MeasurementFrame correctly.

Interface Verification

□ Public interface matches the approved API.

□ begin() initializes the sensor.

□ update(Model&) acquires one measurement frame.

Coding Verification

□ Complies with Coding Standard.

□ No dynamic memory allocation.

□ No undocumented public interface.

□ No duplicated measurement logic.

# 15. Measurement Units

The Sensor module shall convert all acquired measurements to the
standard engineering units defined by the firmware.

Version 1.0 adopts SI units as the official internal representation.

Acceleration

Unit

m/s²

Temperature (Reserved)

Unit

°C

Angular Velocity (Reserved)

Unit

rad/s

No runtime object shall store acceleration values in g.

Conversion to user-visible units, if required, shall be performed by
higher-level modules.

---

# 16. Future Extensions

The following capabilities are reserved for future firmware versions.

• Gyroscope acquisition.

• Temperature acquisition.

• Sensor self-test.

• Sensor diagnostics.

• Multi-sensor support.

• Automatic sensor identification.

These features shall not change the architectural role of the Sensor
module.

The Sensor module shall remain responsible only for measurement
acquisition.

---

# 17. Relationship to Other Documents

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

RAD-MOD-004

Sensor Module Specification

↓

Firmware Source Code

If a conflict exists, the higher-level document shall take precedence.

---

# 18. Approval

Document Name

Sensor Module Specification

Document Number

RAD-MOD-004

Module

Sensor

Version

1.0.0

Status

APPROVED

State

FROZEN

Approval Authority

Robonix Development Team

After approval, every implementation of the Sensor module shall conform
to this specification.

Any architectural modification shall first be reflected in:

Project Vision

↓

Software Architecture

↓

Data Dictionary

↓

Sensor Module Specification

↓

Source Code

Direct modification of the implementation without updating the approved
documentation is prohibited.

---

# End of Document

Document Name

Sensor Module Specification

Document Number

RAD-MOD-004

Version

1.0.0

Status

APPROVED

State

FROZEN

############################################################

END OF DOCUMENT

############################################################