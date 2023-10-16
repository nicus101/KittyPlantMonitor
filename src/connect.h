// manages connection with base unit

#include <WiFi.h>
//#define WIFI_SSID
//#define WIFI_PASS

// Put your router/base ssid and pass
const char* ssid = WIFI_SSID;
const char* pass = WIFI_PASS;

// Connect to router

void connectbase()
{
  WiFi.mode(WIFI_STA);
  WiFi.useStaticBuffers(true);
  WiFi.begin(ssid, pass);
  while (WiFi.status() != WL_CONNECTED)
  {
    Serial.print(".");
    delay(5000);
  }
  Serial.println("You're connected to the network");
}

// check network status;
void checkbase()
{
  Serial.print("Checking connection: ");
  Serial.println(WiFi.status());
}
