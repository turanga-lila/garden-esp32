# Garden Monitor – Documentation Summary

This file lists all project documentation files and their purpose.

---

## ✅ Core Docs
- [README.md](README.md)  
  Overview of the `docs/` folder.

- [BestPractices.md](BestPractices.md)  
  Sensor configuration and readings format (JSON on ESP32, JSON-LD mapping in Flutter).  
  Includes naming scheme, calibration ranges, and ontology mapping (SOSA + SAREF).

- [RepoStructure.md](RepoStructure.md)  
  Repository layout, `.gitignore` patterns, Git practices, credentials management.  
  Recommends split repos (`garden-esp32`, `garden-flutter`).

---

## 📡 BLE
- [BLE.md](BLE.md)  
  ESP32 NimBLE setup and Flutter reactive_ble integration.  
  Covers UUIDs, read/notify vs. write, scanning with timeout, permissions.

---

## 📲 NFC
- [NFC.md](NFC.md)  
  NTAG215 basics and NDEF format.  
  Best practices for content (URLs, text), Flutter code snippets, geo-tagging integration.

---

## 🛠 Troubleshooting
- [Troubleshooting.md](Troubleshooting.md)  
  Common issues:
  - ESP32 BLE advertising not visible.
  - Flutter Android embedding v1/v2 mismatch.
  - Gradle/Kotlin setup.
  - Git mis-merges and recovery.
  - NFC platform differences.

---

## 🗺 Roadmap (planned)
- Periodic BLE reads from ESP32.
- Config write & persistent storage on ESP32.
- NFC tag + geo binding in Flutter.
- Server/backend integration (prototype: Node-RED/Home Assistant; later: MQTT/Kafka).

