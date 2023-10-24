#include <DallasTemperature.h>
#include <OneWire.h>

#define SENSOR1_PIN 6
#define SENSOR2_PIN 7
#define SENSOR_POWER_PIN 4
 #define SENSOR2_POWER_PIN 5

OneWire oneWire1(SENSOR1_PIN);
OneWire oneWire2(SENSOR2_PIN);
DallasTemperature sensor1(&oneWire1);
DallasTemperature sensor2(&oneWire2);

void tempSensorDetect(){
pinMode(SENSOR_POWER_PIN, OUTPUT);
digitalWrite(SENSOR_POWER_PIN, HIGH);
pinMode(SENSOR2_POWER_PIN, OUTPUT);
digitalWrite(SENSOR2_POWER_PIN, HIGH);
sensor1.begin();
sensor2.begin();
}

void getTemps(){
  sensor1.requestTemperatures();
  sensor2.requestTemperatures();
  float temperatureC1 = sensor1.getTempCByIndex(0);
float temperatureC2 = sensor2.getTempCByIndex(0);

  Serial.print("Sensor 1: ");
  Serial.println(temperatureC1);
  Serial.print("Sensor 2: ");
  Serial.println(temperatureC2);

}
