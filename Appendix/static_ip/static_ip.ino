#include <ESP8266WiFi.h>

IPAddress staticIP832_150(192,168,1,150);
IPAddress gateway832_150(192,168,1,1);
IPAddress subnet832_150(255,255,255,0);

void setup()
{
  Serial.begin(9600);
  WiFi.disconnect();
  Serial.println("");
  Serial.println("");
  Serial.println("Ready to Connect");
   WiFi.begin("dlink","iist@4568");
  while ((!(WiFi.status() == WL_CONNECTED))){
    delay(300);
  Serial.print("...");
  }
  delay(1000);
  WiFi.config(staticIP832_150, gateway832_150, subnet832_150);
  delay(1000);
  Serial.println("Connected to dlink");
  Serial.println("Local IP:");
  Serial.println((WiFi.localIP().toString()));
  Serial.println("Gateway IP");
  Serial.println((WiFi.gatewayIP().toString().c_str()));
  Serial.println("Host Name");
  Serial.println((WiFi.hostname()));
}


void loop()
{

}



