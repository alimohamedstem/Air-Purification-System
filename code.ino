#include <MQUnifiedsensor.h>

// Pin Definitions
#define Voltage_Resolution 5
#define ADC_Bit_Resolution 10
#define type "MQ-135"
#define RatioMQ135CleanAir 3.6

#define pin_before A0  // MQ135 before purification system
#define pin_after  A1  // MQ135 after purification system

// Declare Sensor Instances
MQUnifiedsensor MQ135_before("Arduino", Voltage_Resolution, ADC_Bit_Resolution, pin_before, type);
MQUnifiedsensor MQ135_after("Arduino", Voltage_Resolution, ADC_Bit_Resolution, pin_after, type);

void setup() {
  Serial.begin(9600);

  // Initialize sensors
  MQ135_before.init();
  MQ135_before.setRegressionMethod(1);
  MQ135_before.setR0(91.79);

  MQ135_after.init();
  MQ135_after.setRegressionMethod(1);
  MQ135_after.setR0(91.79);

  Serial.println("Sensors calibrated.");
}

void loop() {
  MQ135_before.update();
  MQ135_after.update();

  // Alcohol
  MQ135_before.setA(77.255); MQ135_before.setB(-3.18);
  float Alcohol_before = MQ135_before.readSensor();
  MQ135_after.setA(77.255); MQ135_after.setB(-3.18);
  float Alcohol_after = MQ135_after.readSensor();

  // Toluene
  MQ135_before.setA(44.947); MQ135_before.setB(-3.445);
  float Toluene_before = MQ135_before.readSensor();
  MQ135_after.setA(44.947); MQ135_after.setB(-3.445);
  float Toluene_after = MQ135_after.readSensor();

  // Acetone
  MQ135_before.setA(34.668); MQ135_before.setB(-3.369);
  float Acetone_before = MQ135_before.readSensor();
  MQ135_after.setA(34.668); MQ135_after.setB(-3.369);
  float Acetone_after = MQ135_after.readSensor();

  // Efficiency calculation
  float Alcohol_eff = (Alcohol_before - Alcohol_after) / Alcohol_before * 100.0;
  float Toluene_eff = (Toluene_before - Toluene_after) / Toluene_before * 100.0;
  float Acetone_eff = (Acetone_before - Acetone_after) / Acetone_before * 100.0;

  // Print results
  Serial.println("=== Gas Concentration Before & After Purification ===");
  Serial.print("Alcohol: "); Serial.print(Alcohol_before); Serial.print(" ppm -> ");
  Serial.print(Alcohol_after); Serial.print(" ppm | Efficiency: ");
  Serial.print(Alcohol_eff); Serial.println("%");

  Serial.print("Toluene: "); Serial.print(Toluene_before); Serial.print(" ppm -> ");
  Serial.print(Toluene_after); Serial.print(" ppm | Efficiency: ");
  Serial.print(Toluene_eff); Serial.println("%");

  Serial.print("Acetone: "); Serial.print(Acetone_before); Serial.print(" ppm -> ");
  Serial.print(Acetone_after); Serial.print(" ppm | Efficiency: ");
  Serial.print(Acetone_eff); Serial.println("%");

  delay(1000);
}
