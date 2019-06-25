#include <ESP8266WiFi.h>
#include "ThingSpeak.h"
#include <SPI.h>
#include <ESP8266WiFi.h>

//Thingspeak Channel Field Values Measurement
unsigned long myChannelNumber = 534628;
const char * myWriteAPIKey = "MC2KU41IN5H3MV78";

#define WIFI_SSID "INTERNSHIP"
#define WIFI_PASSWORD "ictak@Guest"
#include <DHT.h>
#include <DHT_U.h>
#include<dht.h>
dht DHT;
#define DHT11_D0
WiFiClient client; 
     void setup(){
                    Serial.begin(9600);
                    WiFi.begin(WIFI_SSID, WIFI_PASSWORD);// connect to wifi.
                    ThingSpeak.begin(client);
                    Serial.print("connecting");
                    while (WiFi.status() != WL_CONNECTED) {
                    Serial.print(".");
                    delay(500);
                 }
Serial.println();
Serial.print("connected: ");
Serial.println(WiFi.localIP());
void loop()
      {
         int chk = DHT.read11(DHT11_PIN);
         Serial.print("Temperature = ");
         Serial.println(DHT.temperature);
         Serial.print("Humidity = ");
         Serial.println(DHT.humidity);
         delay(1000);
         ThingSpeak.setField(1,cm);
         ThingSpeak.writeFields(myChannelNumber, myWriteAPIKey);
         delay(20000);
      }
