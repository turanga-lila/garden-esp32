# Best Practices (Sensors, Config, Readings, Ontology Mapping)

## Goals
- Keep **ESP32** configs small, durable, and readable.
- Keep **readings** append-only and compact.
- Maintain a **stable naming scheme** to align ESP32 JSON and Flutter JSON-LD.

## File Strategy on ESP32
- **One config file per sensor**, e.g. `soil_moisture_sensor_01.json`.
- **One readings file per sensor per day**, e.g. `soil_moisture_sensor_01_2025-09-15.jsonl` (newline-delimited JSON).

## Config (ESP JSON example)
```json
{
  "sensor_type": "soil_moisture",
  "sensor_id": "sensor_01",
  "unit": "%",
  "calibration": {
    "wet_value": 1149,
    "dry_value": 2750,
    "valid_range": {"min": 0, "max": 100}
  },
  "sampling": {"period_sec": 900},
  "ble": {
    "service_uuid": "edb8c71d-e270-48a5-a7d3-0f6cb0ccf2fa",
    "characteristic_uuid": "81bff45c-97ca-442f-b7ed-14d1e68c6062"
  },
  "meta": {
    "label": "Bed A – Probe 1",
    "version": 1
  }
}
