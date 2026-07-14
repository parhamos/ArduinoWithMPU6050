# Robonix AccelMeter Firmware

# Coding Standard

---

Document Number : RAD-COD-001

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
|1.0.0|2026-07-14|Initial Coding Standard|Robonix Development Team|

---

# Table of Contents

1. Purpose

2. Scope

3. Coding Philosophy

4. General Rules

5. Naming Convention

6. File Naming

7. Folder Naming

8. Namespace Policy

9. Language Rules

---

# 1. Purpose

This document defines the coding rules used throughout the Robonix
AccelMeter firmware.

Every source file shall comply with this document.

The purpose of this standard is to ensure

• Readability

• Maintainability

• Predictability

• Consistency

• Long-term scalability

Implementation shall never violate this document.

---

# 2. Scope

This standard applies to

• Header files

• Source files

• Classes

• Structures

• Enumerations

• Functions

• Variables

• Constants

• Documentation

• Comments

• APIs

• Module implementation

---

# 3. Coding Philosophy

The firmware follows the following principles.

Simple

Readable

Deterministic

Modular

Maintainable

Explicit

Predictable

Industrial

The simplest correct solution shall always be preferred.

Code shall be written for humans first and computers second.

Optimization shall never reduce readability without measurable benefit.

---

# 4. General Rules

---

## COD-001

One class per module.

---

## COD-002

One responsibility per class.

---

## COD-003

Every source file shall compile independently.

---

## COD-004

Every header shall be self-contained.

---

## COD-005

Public interfaces shall remain minimal.

---

## COD-006

Implementation details belong in .cpp files.

---

## COD-007

Header files shall expose only what is necessary.

---

## COD-008

Every function shall perform one logical task.

---

## COD-009

Functions shall remain short whenever practical.

---

## COD-010

Readable code is preferred over clever code.

---

## COD-011

Avoid duplicated code.

Shared functionality shall be extracted into Common.

---

## COD-012

Global mutable data is prohibited.

Approved singleton module instances are the only exception.

---

## COD-013

Every module shall compile independently.

---

## COD-014

Modules shall never bypass the Software Architecture Document.

---

## COD-015

If a coding decision conflicts with Architecture,
Architecture shall prevail.

---

# 5. Naming Convention

Consistency is mandatory.

The same object type shall always follow the same naming rule.

---

## Classes

PascalCase

Examples

Model

Sensor

Display

Calibration

Statistics

Scheduler

Application

---

## Structures

PascalCase

Examples

MeasurementFrame

StatisticsData

CalibrationData

DeviceStatus

---

## Enumerations

PascalCase

Examples

SensorState

FirmwareState

AccelerationUnit

---

## Enumeration Values

PascalCase

Examples

Connected

Disconnected

Running

Stopped

Error

Metric

Imperial

---

## Functions

camelCase

Examples

begin()

update()

reset()

calculate()

readSensor()

showPage()

sendFrame()

---

## Variables

camelCase

Examples

sampleRate

frameCounter

measurement

temperature

---

## Member Variables

Prefix

m_

Examples

m_temperature

m_frameCounter

m_sensorState

m_sampleRate

---

## Static Member Variables

Prefix

s_

Example

s_instanceCounter

---

## Global Objects

Lower camelCase

Examples

model

sensor

display

statistics

scheduler

---

## Constants

Prefix

k

PascalCase

Examples

kDefaultSampleRate

kStandardGravity

kMaxSamples

kSerialBaudRate

---

## Compile-time Constants

Use

constexpr

whenever possible.

---

## Macros

Macros are prohibited except

Header Guards

Conditional Compilation

Compiler-specific directives

---

# 6. File Naming

One module shall use one file pair.

Examples

Model.h

Model.cpp

Sensor.h

Sensor.cpp

Display.h

Display.cpp

File names shall use PascalCase.

Abbreviations shall be avoided unless widely accepted.

---

# 7. Folder Naming

Folders shall use PascalCase.

Examples

Application

Scheduler

Sensor

Display

Protocol

Calibration

Statistics

Model

Common

---

# 8. Namespace Policy

Version 1.0 does not use C++ namespaces.

Future versions may introduce namespaces if required.

---

# 9. Language Rules

Programming language

C++17

Framework

Arduino

Compiler

PlatformIO Toolchain

Compiler warnings shall be treated seriously.

Code shall compile warning-free whenever practical.
# 10. File Organization

Every module shall follow the same internal file organization.

A module normally consists of:

Module.h

Module.cpp

ModuleConfig.h

Optional

ModuleTypes.h

README.md

Additional files may be added only when they improve readability and
maintainability.

---

# 11. Header File Rules

## HDR-001

Every header file shall use include guards.

Example

#ifndef SENSOR_H

#define SENSOR_H

...

#endif

---

## HDR-002

Include Guards are mandatory.

#pragma once may be used only if explicitly approved for the project.

Version 1.0 adopts Include Guards as the official style.
---

## HDR-003

Header files shall be self-contained.

A header shall compile when included by itself.

---

## HDR-004

A header shall include only the headers it directly depends on.

Do not rely on indirect includes.

---

## HDR-005

Unused include files are prohibited.

---

## HDR-006

Implementation code is prohibited inside header files.

Exceptions

constexpr

inline functions when justified

template definitions

---

## HDR-007

Public interface shall appear before private implementation.

Recommended class order

public

protected

private

---

## HDR-008

One public class per header.

---

## HDR-009

Avoid circular dependencies.

Use forward declarations whenever possible.

---

# 12. Source File Rules

## SRC-001

Every source file shall include its own header first.

Example

#include "Sensor.h"

---

## SRC-002

Remaining includes shall follow this order.

Project headers

Third-party libraries

Framework headers

Standard library headers

---

## SRC-003

Source files shall contain implementation only.

---

## SRC-004

Anonymous namespaces may be used for internal helper functions.

Global helper functions are prohibited.

---

## SRC-005

Implementation shall match the declaration order in the header.

---

## SRC-006

Do not implement undocumented public functions.

---

# 13. Include Rules

The number of include files shall remain minimal.

Only direct dependencies shall be included.

---

Preferred

Sensor.h

↓

Model.h

Incorrect

Sensor.h

↓

Display.h

↓

Protocol.h

↓

Statistics.h

if they are unused.

---

Avoid transitive dependencies.

Every file shall explicitly include what it requires.

---

# 14. File Layout

The following order shall be used for source files.

File Header Comment

↓

Includes

↓

Internal Constants

↓

Anonymous Namespace

↓

Static Variables

↓

Constructors

↓

Public Functions

↓

Protected Functions

↓

Private Functions

↓

End of File

---

The following order shall be used for header files.

File Header Comment

↓

Include Guard

↓

Includes

↓

Forward Declarations

↓

Class Declaration

↓

Public Section

↓

Protected Section

↓

Private Section

↓

Global Object Declaration (if applicable)

↓

End Guard

---

# 15. Formatting Rules

Indentation

4 spaces

Tabs

Prohibited

Maximum line length

120 characters

One statement per line

Required

One declaration per line

Required

Opening braces

Same line

Example

if (...)

{

}

Function definitions

Opening brace on next line is prohibited.

Example

bool Sensor::begin() {

}

---

# 16. Whitespace Rules

One blank line between functions.

One blank line between logical sections.

No trailing whitespace.

One space after

if

for

while

switch

Example

if (condition)

Correct

if(condition)

Incorrect

---

# 17. Preprocessor Rules

Only the following directives are normally permitted.

#include

#ifndef

#define

#endif

#ifdef

#ifndef

#if

#elif

#else

#undef

Compiler-specific directives require documented justification.

---

# 18. Forward Declaration Policy

Forward declarations shall be preferred when they reduce compile-time
dependencies.

Do not use forward declarations when the complete type definition is
required.

Correct usage shall improve modularity without reducing readability.
# 19. Class Design Rules

## CLS-001

Each class shall have exactly one responsibility.

---

## CLS-002

Classes shall expose the smallest possible public interface.

---

## CLS-003

Data members shall remain private unless explicit justification exists.

---

## CLS-004

Public member variables are prohibited.

Exceptions

Plain Data Structures (POD)

Configuration structures

Message structures

---

## CLS-005

Class declarations shall follow this order.

Public

Protected

Private

---

## CLS-006

Member function declarations shall appear in the following order.

Constructor

Destructor

Initialization

Public API

Utility Functions

Private Functions

---

## CLS-007

Virtual functions are prohibited unless explicitly required.

Version 1.0 does not require polymorphism.

---

## CLS-008

Inheritance is prohibited unless approved by the Software Architecture Document.

Composition shall be preferred over inheritance.

---

# 20. Constructor Rules

## CON-001

Constructors shall initialize all member variables.

---

## CON-002

Member initialization lists shall be preferred.

Correct

Sensor() :
    m_connected(false)
{
}

Incorrect

Sensor()
{
    m_connected = false;
}

---

## CON-003

Constructors shall not perform lengthy operations.

---

## CON-004

Hardware initialization shall be performed by

begin()

not by constructors.

---

# 21. Structure Rules

Structures shall represent data only.

---

## STR-001

Structures shall not contain business logic.

---

## STR-002

Structures shall remain lightweight.

---

## STR-003

Structures may contain only

Data

Default values

Simple helper methods when justified

---

## STR-004

Runtime firmware data shall remain inside Model structures.

---

## STR-005

Structure names shall use nouns.

Examples

MeasurementFrame

DeviceStatus

StatisticsData

CalibrationData

---

# 22. Enumeration Rules

Enumerations shall use

enum class

---

## ENUM-001

Traditional enums are prohibited.

---

## ENUM-002

Underlying type shall be specified whenever practical.

Example

enum class SensorState : uint8_t

---

## ENUM-003

Enumeration values shall use PascalCase.

Correct

Connected

Disconnected

Running

Stopped

Incorrect

CONNECTED

running

STATE_RUNNING

---

## ENUM-004

Enumeration values shall not contain prefixes.

Correct

Connected

Incorrect

SensorConnected

---

# 23. Data Type Rules

## DAT-001

Fixed-width integer types shall be preferred.

Examples

uint8_t

uint16_t

uint32_t

int16_t

---

## DAT-002

Arduino aliases

byte

word

are prohibited.

---

## DAT-003

Use

bool

for logical values.

Do not use integers as Boolean flags.

---

## DAT-004

Floating-point calculations shall use

float

Version 1.0 does not require

double.

---

## DAT-005

Character arrays shall be preferred over dynamic strings for fixed-size buffers.

Arduino String shall not be used in firmware modules.

---

# 24. Const Correctness

## CONST-001

Read-only parameters shall be declared const whenever applicable.

---

## CONST-002

Read-only member functions shall be marked const.

Example

const DeviceStatus& status() const;

---

## CONST-003

Compile-time constants shall use constexpr.

---

## CONST-004

Literal numeric values shall be replaced with named constants.

---

## CONST-005

Functions shall return const references when ownership is not transferred.

Example

const MeasurementFrame& measurement() const;

---

# 25. Type Alias Policy

Type aliases shall be introduced only when they improve readability.

Avoid unnecessary typedef declarations.

Prefer

using

over

typedef

when aliases are required.

Example

using Timestamp = uint32_t;
# 26. Function Rules

## FUNC-001

Each function shall perform one logical task.

---

## FUNC-002

Functions shall remain as short as practical.

Target length

Less than 40 lines

Long functions shall be divided into smaller private functions.

---

## FUNC-003

Function names shall describe actions.

Correct

readSensor()

calculateRms()

updateDisplay()

Incorrect

process()

run()

doWork()

---

## FUNC-004

Input parameters shall be validated whenever required.

---

## FUNC-005

Avoid side effects.

Functions shall modify only the data they own.

---

## FUNC-006

Hidden dependencies are prohibited.

Every dependency shall be explicit.

---

## FUNC-007

Return values shall indicate meaningful results.

Avoid unused return values.

---

# 27. Getter and Setter Rules

The firmware follows a controlled accessor policy.

---

## GET-001

Getter functions shall be preferred over public data members.

---

## GET-002

Getter names shall not use prefixes.

Correct

measurement()

status()

statistics()

Incorrect

getMeasurement()

getStatus()

---

## GET-003

Read-only getters shall return const references whenever appropriate.

Example

const MeasurementFrame& measurement() const;

---

## GET-004

Writable access shall be granted only when ownership permits.

Example

MeasurementFrame& measurement();

---

## SET-001

Setter functions shall be used only when required.

Unnecessary setters are prohibited.

---

## SET-002

Validation shall occur inside setters whenever applicable.

---

## SET-003

Setters shall not contain unrelated processing.

---

# 28. Parameter Rules

## PAR-001

Pass small fundamental types by value.

Examples

bool

uint8_t

uint16_t

float

---

## PAR-002

Pass large objects by const reference.

---

## PAR-003

Output parameters shall be avoided.

Prefer return values.

---

## PAR-004

Functions should have a limited number of parameters.

Recommended maximum

Four

---

# 29. Error Handling Rules

## ERR-001

Recoverable errors shall be reported.

---

## ERR-002

Modules shall never terminate firmware execution.

---

## ERR-003

Error information shall be stored in the Model.

---

## ERR-004

Functions shall return bool when only success or failure is required.

Example

bool begin();

bool update();

---

## ERR-005

Error messages shall not be hardcoded inside business logic.

---

## ERR-006

Hardware failures shall not corrupt Model data.

---

# 30. Comment Rules

Comments shall explain

Why

not

What.

---

## COM-001

Every source file shall begin with the project header.

---

## COM-002

Every public function shall have a brief description.

---

## COM-003

Complex algorithms shall be documented.

---

## COM-004

Obvious code shall not be commented.

Incorrect

i++;

 // Increment i

---

## COM-005

Comments shall remain synchronized with the implementation.

Outdated comments are prohibited.

---

# 31. Return Value Rules

## RET-001

Return values shall be meaningful.

---

## RET-002

Return nullptr only for pointer-returning functions.

---

## RET-003

Do not use magic error codes.

Use enumerations or documented constants.

---

## RET-004

Prefer early return to reduce nesting.

Example

if (!m_connected)
{
    return false;
}

---

# 32. Boolean Rules

Boolean variables shall read naturally.

Correct

isConnected

hasError

isRunning

Incorrect

flag

status1

value2

---

Boolean functions shall also read naturally.

Examples

isReady()

isConnected()

hasData()

supportsCalibration()

---

# 33. Defensive Programming

Modules shall verify assumptions whenever practical.

Examples

Check sensor availability.

Validate configuration.

Validate input ranges.

Reject invalid states.

The firmware shall fail safely whenever recovery is possible.
# 34. Memory Management Rules

Version 1.0 follows a fully static memory model.

---

## MEM-001

Dynamic memory allocation is prohibited.

Forbidden

malloc()

calloc()

realloc()

free()

new

delete

---

## MEM-002

Module instances shall be statically allocated.

Example

extern Model model;

extern Sensor sensor;

---

## MEM-003

Buffers shall have fixed compile-time sizes.

---

## MEM-004

Large local arrays are prohibited.

---

## MEM-005

Recursive allocation is prohibited.

---

## MEM-006

Memory ownership shall be explicit.

Each object shall have exactly one owner.

---

# 35. Module Rules

## MOD-001

Every module shall expose only its public interface.

---

## MOD-002

Modules shall never access another module's private data.

---

## MOD-003

Modules shall communicate only through:

Model

or

Documented APIs

---

## MOD-004

Each module shall implement

begin()

when initialization is required.

---

## MOD-005

Each module shall implement

update()

only when periodic execution is required.

---

## MOD-006

Modules shall remain independently testable.

---

## MOD-007

Module configuration shall reside in

ModuleConfig.h

---

## MOD-008

Shared data types shall reside in

Model

or

Common

Never duplicate identical data structures.

---

# 36. API Design Rules

## API-001

Public APIs shall remain minimal.

---

## API-002

Breaking API changes are prohibited after approval.

---

## API-003

Public APIs shall use documented data types.

---

## API-004

Return ownership shall always be clear.

---

## API-005

Avoid overloaded functions unless readability improves.

---

## API-006

Public APIs shall avoid hidden side effects.

---

## API-007

Every public API shall have a documented purpose.

---

# 37. Forbidden Practices

The following practices are prohibited.

---

FP-001

Global mutable variables
(except approved module instances)

---

FP-002

Copy-and-paste programming.

---

FP-003

Duplicate business logic.

---

FP-004

Magic numbers.

---

FP-005

Circular dependencies.

---

FP-006

Direct module-to-module access.

---

FP-007

Using Arduino String.

---

FP-008

Hidden global state.

---

FP-009

Modifying another module's internal data.

---

FP-010

Ignoring compiler warnings.

---

FP-011

Commented-out source code.

Unused code shall be removed using version control.

---

FP-012

Dead code.

---

FP-013

Empty catch blocks.

(Currently not applicable, but reserved for future portability.)

---

FP-014

Multiple return paths caused only by poor design.

Early returns for validation are acceptable.

---

# 38. Build Rules

## BLD-001

Every commit shall build successfully.

---

## BLD-002

Compiler warnings shall be investigated.

---

## BLD-003

A module shall not be merged until it compiles successfully.

---

## BLD-004

The complete firmware shall build after every approved implementation step.

---

# 39. Git Rules for Source Code

## GITC-001

One logical change per commit.

---

## GITC-002

Commit messages shall follow the approved convention.

Examples

feat(sensor): add measurement acquisition

fix(model): correct frame update

docs(api): document Model interface

---

## GITC-003

Documentation updates shall accompany public API changes.

---

## GITC-004

Broken source code shall never be committed.

---

# 40. Version 1.0 Development Policy

Version 1.0 prioritizes

Stability

Predictability

Maintainability

Architecture compliance

Code quality

Feature additions that require architectural changes are prohibited.

Such requests shall be deferred to Version 2.
# 41. Code Review Checklist

Every source file shall be reviewed before approval.

The following checklist shall be completed.

---

Architecture Compliance

□ Layering respected

□ Module responsibility respected

□ No forbidden dependencies

□ Model ownership respected

---

Coding Compliance

□ Naming Convention respected

□ Formatting respected

□ Header Rules respected

□ Source Rules respected

□ Function Rules respected

□ Memory Rules respected

□ API Rules respected

---

Documentation Compliance

□ File header completed

□ Public APIs documented

□ Comments updated

□ No obsolete comments

---

Build Verification

□ Builds successfully

□ No compiler errors

□ No unresolved symbols

□ Warnings reviewed

---

Quality Verification

□ No duplicated code

□ No dead code

□ No commented-out code

□ No magic numbers

□ No hidden dependencies

□ No prohibited language features

---

# 42. Recommended Development Workflow

The recommended workflow for Version 1.0 shall be:

Approve Documentation

↓

Implement One Module

↓

Compile

↓

Review

↓

Commit

↓

Continue

Every module shall successfully compile before implementation proceeds
to the next module.

---

# 43. Example Module Template

Recommended directory structure.

Module/

    Module.h

    Module.cpp

    ModuleConfig.h

    ModuleTypes.h      (Optional)

    README.md          (Optional)

The exact structure may be simplified when additional files are not
required.

---

# 44. Coding Compliance Levels

Every source file shall satisfy one of the following compliance levels.

Level A

Full compliance.

Required for production firmware.

---

Level B

Minor documented deviations.

Acceptable during development.

Must be corrected before release.

---

Level C

Experimental implementation.

Not permitted in the Version 1.0 release branch.

---

# 45. Deviations

Any deviation from this Coding Standard shall:

Be documented.

Be technically justified.

Be approved by the project owner.

Undocumented deviations are prohibited.

---

# 46. Relationship to Other Documents

This document shall be interpreted together with:

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

# 47. Approval

Document Name

Coding Standard

Document Number

RAD-COD-001

Version

1.0.0

Status

APPROVED

State

FROZEN

Approval Authority

Robonix Development Team

After approval, all firmware source files shall comply with this
document.

---

# End of Document

Document Name

Coding Standard

Document Number

RAD-COD-001

Version

1.0.0

Status

APPROVED

State

FROZEN

############################################################

END OF DOCUMENT

############################################################