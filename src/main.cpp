#define DEBUG
#define SOIL_SENSOR_PIN 4

#include "Arduino.h"

/* Configurable calibration values soil sensor
Measures dielectric permittivity of the surrounding medium (i.e., soil)
Higher water content = higher permittivity → more voltage dropped across the sensor
*/
int DRY_VALUE = 2750;
int WET_VALUE = 1149;

// Configurable read delay (ms)
unsigned long readDelay = 1000;

void setup() {
#ifdef DEBUG
  Serial.begin(115200);
  delay(1000);  // Give time for serial to initialize
#endif
  analogReadResolution(12);
  analogSetAttenuation(ADC_11db); // Ensure full 0–3.3V range for accurate soil readings
#ifdef DEBUG
  Serial.println("🌱 Soil moisture sensor initializing...");
  Serial.printf("Calibration: DRY=%d, WET=%d, Delay=%lu ms\n", DRY_VALUE, WET_VALUE, readDelay);
#endif
}

void loop() {
  uint16_t raw = analogRead(SOIL_SENSOR_PIN);
  int percent = 100 - ((raw - WET_VALUE) * 100 / (DRY_VALUE - WET_VALUE));
  percent = constrain(percent, 0, 100);

#ifdef DEBUG
  Serial.printf("🔢 Raw ADC: %d | 💧 Moisture: %d%%\n", raw, percent);
#endif
  delay(readDelay);
}
