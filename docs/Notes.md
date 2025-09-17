Unit Source of Truth

Unit in readings must be copied from the config (don’t invent different units).

If unit changes, bump config version and let Flutter re-sync.

JSON-LD Mapping (Flutter side)

Use JSON-LD in Flutter to map to SOSA/SSN + SAREF:

sosa:Observation → a reading

sosa:observedProperty → e.g. saref:Moisture

sosa:hasFeatureOfInterest → the plant/plot

sosa:phenomenonTime → ts

saref:hasUnitOfMeasure → %

(Keep the ESP side plain JSON; map to JSON-LD only in Flutter.)

Notes on Ontologies

SOSA/SSN → observation mechanics (who/what/when).

SAREF → domain terms (e.g., moisture, temperature) and units.

Calibrations/valid ranges → store in ESP config; expose as metadata to Flutter.

Naming Convention

<sensor_type>_<sensor_id> → file stems, BLE names, and keys.
Examples: soil_moisture_sensor_01, air_temp_sensor_01.

----------------------------------------------------------------

Flutter (reactive_ble)
Permissions (Android 12+)

Manifest: BLUETOOTH_SCAN, BLUETOOTH_CONNECT, ACCESS_FINE_LOCATION

App: request via permission_handler.

Scanning with Timeout (dart)

_scanSubscription = _ble.scanForDevices(withServices: []).listen((d) { ... });
Future.delayed(Duration(seconds: 10), () {
  _
