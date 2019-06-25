#include "UbidotsMicroESP8266.h"
//#define TOKEN  "A1E-4Y75tlzDNAvdIcLd63qwZkLNhDK2eP"  // Put here your Ubidots TOKEN
#define TOKEN  ""
#define WIFISSID ""
#define PASSWORD ""

Ubidots client(TOKEN);

void setup() {
  // initialize serial communication at 9600 bits per second:
  Serial.begin(115200);
  client.wifiConnection(WIFISSID, PASSWORD);
}

void loop() {
  // read the input on analog pin 0:
  int sensorValue = analogRead(A0);
  Serial.println(sensorValue);
  delay(1000);
   // Convert the analog reading (which goes from 0 - 1023) to a voltage (0 - 5V):
  float voltage = sensorValue * (5.0 / 1023.0);
  
  // print out the value you read:
  Serial.println(voltage);
  delay(1000);
    client.add("LDR Voltage", voltage);
    client.sendAll(true);
}
