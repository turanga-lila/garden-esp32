# docs/BLE.md
```markdown
# BLE Integration – ESP32 (NimBLE) + Flutter (reactive_ble)

## ESP32 (NimBLE) Essentials
- Advertise a **service UUID** with a **characteristic** for sensor value.
- Use READ for on-demand, NOTIFY for streaming updates.
- Example properties: `NIMBLE_PROPERTY::READ | NIMBLE_PROPERTY::NOTIFY`
- Set advertised name to help discovery:
  ```cpp
  NimBLEAdvertising* adv = NimBLEDevice::getAdvertising();
  adv->setName("GardenMonitor");
  adv->addServiceUUID(SERVICE_UUID);
  adv->start();
