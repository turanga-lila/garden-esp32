# 🌿 Garden Monitor

Soil and environmental sensor monitoring with ESP32-S3 and Flutter integration.

## ✅ Step 1: Soil Moisture Sensor

### Hardware
- ESP32-S3-DevKitC-1-N16R8V
- Capacitive soil moisture sensor v1.2

### Wiring
- Sensor AOUT → GPIO4
- Sensor VCC  → 3.3V
- Sensor GND  → GND

### Output
Serial monitor displays:
- Raw ADC value
- Soil moisture percentage (0–100%)

## 🛠 PlatformIO Setup

# 🌱 Garden Monitor

[![Flutter](https://img.shields.io/badge/Flutter-3.32-blue?logo=flutter)](https://flutter.dev)
[![PlatformIO](https://img.shields.io/badge/PlatformIO-ESP32-orange?logo=espressif)](https://platformio.org)
[![License](https://img.shields.io/badge/license-TBD-lightgrey)](./LICENSE)
[![GitHub issues](https://img.shields.io/github/issues/turanga-lila/garden-esp32)](https://github.com/turanga-lila/garden-esp32/issues)
[![GitHub pull requests](https://img.shields.io/github/issues-pr/turanga-lila/garden-esp32)](https://github.com/turanga-lila/garden-esp32/pulls)


An **ESP32 + Flutter** project for monitoring and managing garden and greenhouse conditions.  
The system integrates sensors (soil moisture, temperature, etc.), BLE communication, NFC tags, and mobile app features.

---

## 📂 Repository Layout
- `garden-esp32/` → ESP32 firmware (Arduino/PlatformIO, NimBLE BLE stack).
- `garden-flutter/` → Flutter mobile app (BLE scanner, config sync, NFC support).
- `docs/` → Documentation (best practices, BLE/NFC integration, troubleshooting).

---

## 📖 Documentation
The full set of docs is in [docs/](docs/). Key files:

- [BestPractices.md](docs/BestPractices.md) – Sensor config/readings, JSON ↔ JSON-LD mapping, calibration.
- [BLE.md](docs/BLE.md) – ESP32 BLE setup and Flutter reactive_ble integration.
- [NFC.md](docs/NFC.md) – NTAG215, NDEF format, Flutter NFC code snippets.
- [RepoStructure.md](docs/RepoStructure.md) – Recommended repo layout, .gitignore, Git practices.
- [Troubleshooting.md](docs/Troubleshooting.md) – Common build/runtime issues and fixes.
- [SUMMARY.md](docs/SUMMARY.md) – Index of all documentation.

---

## 🚀 Roadmap
1. ESP32 firmware reads soil moisture sensor, advertises over BLE.
2. Flutter app discovers ESP32 via BLE and reads sensor data.
3. Persistent sensor configs on ESP32 (JSON).
4. Config synchronization between ESP32 and Flutter.
5. NFC tags for plant/tree identification and geo-binding.
6. Backend integration (prototype: Node-RED or Home Assistant; long term: MQTT/Kafka pipeline).

---

## 🔒 License
TBD (likely GPLv3 or Apache 2.0).  
For now, source is public but **license is not finalized**.

---

## 👩‍💻 Contributing
- Use feature branches (`feature/nfc`, `fix/ble-scan`) and open PRs.
- Track roadmap in GitHub Projects.
- Bugs/issues are documented in the **Bug Tracking Project**.

---

## 🌐 Status
This is an **early-stage prototype**.  
Expect breaking changes while ESP32 + Flutter integration stabilizes.
