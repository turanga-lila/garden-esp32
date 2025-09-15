#define DEBUG
#define SOIL_SENSOR_PIN 4

#include <Arduino.h>
#include <NimBLEDevice.h>

// ESP32 (Arduino or ESP-IDF)
// https://www.uuidgenerator.net/
#define SERVICE_UUID        "edb8c71d-e270-48a5-a7d3-0f6cb0ccf2fa"
#define CHARACTERISTIC_UUID "81bff45c-97ca-442f-b7ed-14d1e68c6062"

/* Configurable calibration values soil sensor
Measures dielectric permittivity of the surrounding medium (i.e., soil)
Higher water content = higher permittivity → more voltage dropped across the sensor
*/
int DRY_VALUE = 2750;
int WET_VALUE = 1149;

// Configurable read delay (ms)
unsigned long readDelay = 1000;

NimBLECharacteristic *pCharacteristic;

void initBLE() {
  NimBLEDevice::init("GardenSensor");
  delay(100);
#ifdef DEBUG
  Serial.println("🔗 BLE service initialized.");
#endif

  NimBLEDevice::setPower(ESP_PWR_LVL_P9); // Set max power level for BLE 

  NimBLEServer *pServer = NimBLEDevice::createServer();
  NimBLEService *pService = pServer->createService(SERVICE_UUID);
  pCharacteristic = pService->createCharacteristic(
    CHARACTERISTIC_UUID,
    NIMBLE_PROPERTY::READ | NIMBLE_PROPERTY::NOTIFY
  );


  
#ifdef DEBUG
  Serial.println("🔗 BLE service created.");
#endif

 
#ifdef DEBUG
  Serial.println("🔗 BLE service initializing...");
#endif

  // Initialize the BLE service
  pService->start(); // Start the service

 NimBLEAdvertising *pAdvertising = NimBLEDevice::getAdvertising();


  pAdvertising->setMinInterval(100); // Set minimum advertising interval
  pAdvertising->setMaxInterval(200); // Set maximum advertising interval
  pAdvertising->setName("GardenMonitor"); // Enable scan response
  pAdvertising->start(); // Start advertising. This will allow the device to be discoverable by BLE clients
#ifdef DEBUG
  Serial.println("🔗 Starting BLE advertising...");
#endif

  // Start the advertising process
  //NimBLEDevice::startAdvertising();
  //pServer->getAdvertising()->start();

/**
 * This is the main entry point for the BLE service.
  NimBLEDevice::getServer()->getAdvertising()->start();
  NimBLEDevice::getServer()->getAdvertising()->setName("GardenApp");
  NimBLEDevice::startAdvertising();
*/
#ifdef DEBUG
  Serial.println("🔗 BLE service started and advertising...");
#endif

  // Wait for BLE to be ready
  while (!NimBLEDevice::isInitialized()) {
    delay(100);
  }
#ifdef DEBUG
  Serial.println("🔗 BLE initialized.");
#endif

  // Start the BLE service
  //NimBLEDevice::getServer()->getAdvertising()->start();
#ifdef DEBUG
  Serial.println("🔗 BLE advertising started.");
#endif
}

void sensor_soil_setup() {

#ifdef DEBUG
  Serial.println("🌱 Soil moisture sensor initializing...");
  Serial.printf("Calibration: DRY=%d, WET=%d, Delay=%lu ms\n", DRY_VALUE, WET_VALUE, readDelay);
#endif

  analogReadResolution(12);
  analogSetAttenuation(ADC_11db); // Ensure full 0–3.3V range for accurate soil readings

  // Final debug message
#ifdef DEBUG
  Serial.println("🌱 Soil sensor setup complete.");
#endif
}

int sensor_soil_read() {
    uint16_t raw = analogRead(SOIL_SENSOR_PIN);
    int soil_sensor_reading_percent = 100 - ((raw - WET_VALUE) * 100 / (DRY_VALUE - WET_VALUE));
    int percent = constrain(soil_sensor_reading_percent, 0, 100);

  #ifdef DEBUG
    Serial.printf("🔢 Raw ADC: %d | 💧 Moisture: %d%%\n", raw, percent);
  #endif

  pCharacteristic->setValue(percent);
  pCharacteristic->notify();
#ifdef DEBUG
  Serial.printf("📡 Initial soil moisture: %d%%\n", percent);
#endif

  return soil_sensor_reading_percent;
}

void sensor_soil_loop() {
  int soil_sensor_reading_percent = sensor_soil_read();
  String value = String(soil_sensor_reading_percent);
  pCharacteristic->setValue(value.c_str());
  pCharacteristic->notify();

#ifdef DEBUG
  Serial.printf("📡 Notified BLE with moisture: %d%%\n", soil_sensor_reading_percent);
#endif
}

void setup() {

#ifdef DEBUG
  Serial.begin(115200);
  delay(1000);  // Give time for serial to initialize
#endif

  initBLE();
  sensor_soil_setup();

#ifdef DEBUG
  Serial.println("🌱 Soil sensor initialized and BLE service started.");
#endif
} 

void loop() {
  sensor_soil_loop();
  // Read and notify soil moisture
  delay(readDelay);
}
