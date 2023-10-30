#include <HTTPClient.h>
#include <ArduinoJson.h>

String serverName = "http://192.168.100.11:6969/api/v1/sensor/ingest";
uint64_t hostname = ESP.getEfuseMac();
String apiKey = "dupajasia123";
String payloadJson;

WiFiClient client;
HTTPClient http;

void SendTempData()
{

    DynamicJsonDocument tjson(200);
    tjson["name"] = hostname;
    tjson["apiKey"] = apiKey;
    tjson["temp1"] = 12;
    tjson["moist1"] = 55;

    serializeJson(tjson, payloadJson);
    // Your Domain name with URL path or IP address with path
    http.begin(client, serverName + "/api/test" + hostname);

    // basic httpauth
    // http.setAuthorization("REPLACE_WITH_SERVER_USERNAME", "REPLACE_WITH_SERVER_PASSWORD");

    // If you need an HTTP request with a content type: application/json, use the following:
    http.addHeader("Content-Type", "application/json");
    int httpResponseCode = http.POST(payloadJson);

    Serial.println(payloadJson);
    Serial.print("HTTP Response code: ");
    Serial.println(httpResponseCode);

    // Free resources
    http.end();
}
