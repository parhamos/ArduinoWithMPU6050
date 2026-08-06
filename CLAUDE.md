# CLAUDE.md

Guidance for Claude Code (and other AI assistants) working in this repository.

## Project Overview

**AccelMeter** — Arduino firmware that reads acceleration/gyro/temperature data
from an MPU6050 IMU over I2C and displays live readings on a 16x2 character LCD
(also via I2C), while streaming readings over serial.

- Target board: Arduino **Uno** (`atmelavr`, `arduino` framework)
- Build system: **PlatformIO** (not the Arduino IDE)
- Language: C++ (Arduino dialect, no STL/exceptions/RTTI)

## Build, Upload, Monitor

This project uses PlatformIO CLI (`pio`), not `make`/`cmake`.

```bash
pio run                    # build
pio run -t upload          # build + flash to the Uno
pio device monitor         # open serial monitor (115200 baud, matches SERIAL_BAUD)
pio run -t clean           # clean build artifacts
```

There is no separate lint/format/test command configured — `test/` is an
empty PlatformIO Unit Testing placeholder (just the stock README), no tests
exist yet. If you add tests, use PlatformIO's Unity-based test runner
(`pio test`).

## Directory Structure

```
platformio.ini      PlatformIO project/env config, board, framework, lib_deps
include/Config.h     Global project-wide constants (project name/version, timing, feature flags)
src/main.cpp         Arduino entry point: setup() / loop()
lib/<Module>/        One directory per self-contained module/"library"
test/                Empty PlatformIO test placeholder
```

Each PlatformIO `lib/<Module>` directory is auto-discovered and linked by the
Library Dependency Finder based on `#include`s in `src/main.cpp` — no manual
registration in `platformio.ini` is needed for in-repo libs.

## Module Pattern (important convention)

Every module in `lib/` follows the same 4-file convention. When adding a new
module or extending an existing one, follow this pattern exactly:

| File | Purpose |
|---|---|
| `<Module>.h` | Public API: class declaration + `extern <Module> <instance>;` global singleton |
| `<Module>Config.h` | Compile-time tunables for the module as `constexpr` (ranges, pins, rates, addresses) |
| `<Module>Private.h` | `extern` declarations for underlying third-party/hardware objects the module wraps (e.g. `extern Adafruit_MPU6050 mpu;`) — kept out of the public header so callers only see the module's own API |
| `<Module>.cpp` | Implementation; defines the global singleton instance and the underlying private object |

Modules are used as **global singletons**, not instantiated by callers:

```cpp
#include "Sensor.h"
sensor.begin();
sensor.update();
sensor.ax();
```

`main.cpp` stays thin — it only orchestrates `begin()`/`update()` calls on
module singletons plus timing/delay logic. Business logic belongs in the
module `.cpp` files, not in `main.cpp`.

## Current Implementation State

Not all modules under `lib/` are implemented yet — this is a framework/scaffold
in progress. Check before assuming a module works:

**Implemented and used by `main.cpp`:**
- `Sensor` — wraps `Adafruit_MPU6050`, exposes `begin()/update()/ax()/ay()/az()/temperature()/connected()`
- `Display` — wraps `LiquidCrystal_I2C`, exposes `begin()/splash()/update()/showError()`

**Implemented but not yet wired into `main.cpp`:**
- `Scheduler` — simple non-blocking periodic-task helper (`Task` struct + `scheduler.run(task)`, millis()-based, no interrupts)
- `Common` — shared enums/constants (`CommonTypes.h`, `CommonConfig.h`)

**Scaffolded only — headers/config define the intended data model, but `.h`/`.cpp`/`Private.h` are empty stub files with no implementation:**
- `Application` — presumably the intended top-level orchestrator (all files empty)
- `Model` — intended central system state (`ModelTypes.h`/`ModelConfig.h` define a full `SystemData` struct tree — measurement, statistics, communication, settings, status — but `Model.h`/`Model.cpp`/`ModelPrivate.h` are empty)
- `Calibration`, `Buttons`, `Protocol`, `Filter`, `Utility` — all files empty; no API defined yet

When picking up work in these stub modules, `ModelTypes.h` is the best
reference for the intended shape of shared state (`SystemData`, `Vector3f`,
`MeasurementData`, `StatisticsData`, etc.) even though nothing consumes it yet.

**Known duplication to be aware of:** `lib/Common/CommonTypes.h` and
`lib/Model/ModelTypes.h` both independently define near-identical enums
(`Unit`, `SensorState`, `CalibrationState`). `Common` also has its own
`SensorData` struct that overlaps with `Model`'s `MeasurementData`. These were
never reconciled — if you touch either, check whether the change needs to be
mirrored in the other, and consider flagging/resolving the duplication rather
than adding a third copy.

## Conventions

- **Units:** internal acceleration values are stored in SI units, **m/s²**
  (see comment in `ModelConfig.h`). Conversion to `g` happens only at the
  Display/Protocol boundary, never inside sensor/model logic.
- **Config values are `constexpr`**, grouped under `//===` or `/***/` banner
  comments by category (Timing, General Settings, etc.), not `#define`
  (except version/name strings and header guards).
- **Global singletons over dependency injection** — modules declare one
  `extern` global instance (`sensor`, `display`, `scheduler`) and everything
  references that instance directly rather than passing pointers/references
  around.
- **Header guards** use `#ifndef MODULE_NAME_H` style, not `#pragma once`.
- **Formatting:** Allman brace style (opening brace on its own line) and a
  blank line between statements/members throughout the codebase. Match this
  in new code even though it's verbose — it's consistent across every
  existing file.
- `platformio.ini` sets `build_flags = -I include`, so headers in `include/`
  (currently just `Config.h`) can be included by bare name from anywhere.

## Dependencies (`platformio.ini`)

- `marcoschwartz/LiquidCrystal_I2C@^1.1.4` — I2C character LCD driver
- `adafruit/Adafruit MPU6050@^2.2.9` — IMU driver (pulls in Adafruit Unified Sensor / BusIO transitively)

## Hardware Notes

- LCD I2C address defaults to `0x27`, 16x2 (`lib/Display/DisplayConfig.h`) — adjust if your board uses `0x3F` or a different size.
- MPU6050 configured for ±8g accel range, ±500°/s gyro range, 21Hz DLPF (`lib/Sensor/SensorConfig.h`).
- Serial runs at 115200 baud.
