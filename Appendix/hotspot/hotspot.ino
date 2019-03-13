#include <ESP8266WiFi.h>

void setup()
{
  Serial.begin(9600);
  /***********connetct to somwe wifi network***********/
  WiFi.disconnect();
  Serial.println();
  Serial.println("Ready to Connect dlink");
  WiFi.begin("dlink","iist@4568");
  while ((!(WiFi.status() == WL_CONNECTED))){
    delay(300);
    Serial.print("...");

  }
  Serial.println();
  Serial.println("Connected to dlink");
  /**************************************************/
  /*****create your own Access point(hotspot)*******/
   WiFi.softAP("MyAP","12345678");
  Serial.println((WiFi.softAPIP()));
  /************************************************/
}


void loop()
{
  Serial.print("No of connected Devices: ");
  Serial.println((WiFi.softAPgetStationNum()));
  delay(5000);
}

