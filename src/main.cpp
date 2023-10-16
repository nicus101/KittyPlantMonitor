#include <Arduino.h>
#include <connect.h>
#include <sleep.h>

// used in debug purposes
int waitcounter = 0;

void setup()
{
  Serial.begin(115200);
  print_wakeup_reason();

  connectbase();

  bootcounter();
}

void loop()
{
  checkbase();

  // wait and count to 5 before deep sleep
  while (waitcounter != 5)
  {
    Serial.print(".");
    delay(1000);
    ++waitcounter;
  }
  // go deep sleep
  Serial.println("Going to sleep now");
  Serial.flush();
  esp_deep_sleep_start();
  Serial.println("This will never be printed");
}
