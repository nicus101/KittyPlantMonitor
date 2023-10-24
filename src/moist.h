#include <Arduino.h>
#define MOISTURE_SENSOR_0_PIN 17
#define MOISTURE_SENSOR_1_PIN 18
#define MOISTURE_SENSOR_2_PIN 16

void getMoist(){
    int moisture;

    moisture = analogRead(MOISTURE_SENSOR_0_PIN);
    Serial.print("Analog level 0 5k: ");
    Serial.println(moisture);
    
    moisture = analogRead(MOISTURE_SENSOR_1_PIN);
    Serial.print("Analog level 1 2K: ");
    Serial.println(moisture);
    
    moisture = analogRead(MOISTURE_SENSOR_1_PIN);
    Serial.print("Analog level 2 1K: ");
    Serial.println(moisture);
    
    delay(1000);
}