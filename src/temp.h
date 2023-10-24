#include <OneWire.h>
#include <DS18B20.h>

// define onewire temp pins and activate onewire
#define SENSOR_PIN1 1
#define SENSOR_PIN2 2
#define SENSOR_PIN3 4
#define SENSOR_PIN4 5
#define SENSOR_PIN5 6
#define SENSOR_PIN6 7

OneWire oneWire1(SENSOR_PIN1);
OneWire oneWire2(SENSOR_PIN2);
OneWire oneWire3(SENSOR_PIN3);
OneWire oneWire4(SENSOR_PIN4);
OneWire oneWire5(SENSOR_PIN5);
OneWire oneWire6(SENSOR_PIN6);

DS18B20 TempSensor1(&oneWire1);
DS18B20 TempSensor2(&oneWire2);
DS18B20 TempSensor3(&oneWire3);
DS18B20 TempSensor4(&oneWire4);
DS18B20 TempSensor5(&oneWire5);
DS18B20 TempSensor6(&oneWire6);

uint32_t start, stop;

// check if temp sensor is present and activate it
void tempSensorDetect()
{
// bool SETUP_STATUS = false;
    if (TempSensor1.begin() == false)
    {
#define Temp1
        TempSensor1.setResolution(9);
    }
    if (TempSensor2.begin() == false)
    {
#define Temp2
        TempSensor2.setResolution(9);
    }
    if (TempSensor3.begin() == false)
    {
#define Temp3
        TempSensor3.setResolution(9);
    }
    if (TempSensor4.begin() == false)
    {
#define Temp4
        TempSensor4.setResolution(9);
    }
    if (TempSensor5.begin() == false)
    {
#define Temp5
        TempSensor5.setResolution(9);
    }
    if (TempSensor6.begin() == false)
    {
#define Temp6
        TempSensor6.setResolution(9);
    }
// return SETUP_STATUS;
}

// get temps from activated sensors
void getTemps()
{
// TEMP_READ_STATUS = false;
    start = millis();

    uint32_t timeout = millis();

#ifdef Temp1
    TempSensor1.requestTemperatures();
    while (!TempSensor1.isConversionComplete())
    {
        if (millis() - timeout >= 500)
        {
            break;
        }
    }
    float t1 = TempSensor1.getTempC();
    Serial.println(t1);
#endif

#ifdef Temp2
    TempSensor2.requestTemperatures();
    while (!TempSensor2.isConversionComplete())
    {
        if (millis() - timeout >= 500)
        {
            break;
        }
    }
    float t2 = TempSensor2.getTempC();
    Serial.println(t2);
#endif

#ifdef Temp3
    TempSensor3.requestTemperatures();
    while (!TempSensor3.isConversionComplete())
    {
        if (millis() - timeout >= 500)
        {
            break;
        }
    }
    float t3 = TempSensor3.getTempC();
    Serial.println(t3);
#endif

#ifdef Temp4
    TempSensor4.requestTemperatures();
    while (!TempSensor4.isConversionComplete())
    {
        if (millis() - timeout >= 500)
        {
            break;
        }
    }
    float t4 = TempSensor4.getTempC();
    Serial.println(t4);
#endif

#ifdef Temp5
    TempSensor5.requestTemperatures();
    while (!TempSensor5.isConversionComplete())
    {
        if (millis() - timeout >= 500)
        {
            break;
        }
    }
    float t5 = TempSensor5.getTempC();
    Serial.println(t5);
#endif

#ifdef Temp6
    TempSensor6.requestTemperatures();
    while (!TempSensor6.isConversionComplete())
    {
        if (millis() - timeout >= 500)
        {
            break;
        }
    }
    float t6 = TempSensor6.getTempC();
    Serial.println(t6);
#endif
    stop = millis();

// TEMP_READ_STATUS = true;

}