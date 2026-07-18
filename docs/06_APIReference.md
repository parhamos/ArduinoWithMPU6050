# Robonix AccelMeter Firmware

# API Reference

---

Document Number : RAD-API-001

Version : 1.0.0

Status : Approved

---

# Purpose

This document defines the public APIs of all firmware modules.

Only public interfaces are documented.

---

# Application

| Function | Description |
|----------|-------------|
| bool begin() | Initialize application |
| void run() | Execute main application loop |

---

# Scheduler

| Function | Description |
|----------|-------------|
| bool begin() | Initialize scheduler |
| void update() | Execute one scheduler cycle |

---

# Model

| Function | Description |
|----------|-------------|
| bool begin() | Initialize runtime data |

---

# Sensor

| Function | Description |
|----------|-------------|
| bool begin() | Initialize MPU6050 |
| bool update(Model&) | Read sensor data |

---

# Calibration

| Function | Description |
|----------|-------------|
| bool begin() | Initialize calibration |
| bool update(Model&) | Apply calibration |

---

# Filter

| Function | Description |
|----------|-------------|
| bool begin() | Initialize filter |
| bool update(Model&) | Filter measurements |

---

# Statistics

| Function | Description |
|----------|-------------|
| bool begin() | Initialize statistics |
| bool update(Model&) | Calculate statistics |

---

# Display

| Function | Description |
|----------|-------------|
| bool begin() | Initialize LCD |
| bool update(Model&) | Refresh display |

---

# Protocol

| Function | Description |
|----------|-------------|
| bool begin() | Initialize communication |
| bool update(Model&) | Transmit runtime data |

---

All modules shall expose only the APIs listed above.

END OF DOCUMENT