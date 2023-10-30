#include <Arduino.h>
#include <connect.h>
#include <sleep.h>
#include <moist.h>
#include <temp.h>
#include <http.h>

// used in debug purposes
int waitcounter = 0;
int waitcounter2 = 0;

void setup()
{
  Serial.begin(115200);
  print_wakeup_reason();

  connectbase();

  tempSensorDetect();

  bootcounter();

  // if (SETUP_STATUS == 0)
  // {
  //   while (!SETUP_STATUS);
  // }
}

void loop()
{
  checkbase();
  getTemps();

  // if (TEMP_READ_STATUS == false)
  // {
  //   while (!TEMP_READ_STATUS);
  // }

  // wait and count to 5 before deep sleep
  while (waitcounter != 5)
  {
    Serial.print(".");
    delay(1000);
    ++waitcounter;
  }
  getMoist();

  while (waitcounter2 != 5)
  {
    Serial.print(".");
    delay(1000);
    ++waitcounter2;
  }
  Serial.print("id: ");
  Serial.println(hostname);
  SendTempData();
  delay(5000);
  // go deep sleep
  // Serial.println("Going to sleep now");
  // Serial.flush();
  // esp_deep_sleep_start();
  // Serial.println("This will never be printed");
}
