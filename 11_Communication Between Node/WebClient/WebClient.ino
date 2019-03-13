
#include <ESP8266WiFi.h>

#include <ESP8266HTTPClient.h>

String  httpurl;
HTTPClient http;
String msg="";
//WiFiClient client;

void setup()
{
  Serial.begin(115200);
  WiFi.disconnect();
  delay(3000);
  Serial.println("");
  Serial.println("");
  Serial.println("Connecting to ");
  Serial.print("dlink");
   WiFi.begin("dlink","iist@4568");
  while ((!(WiFi.status() == WL_CONNECTED))){
    delay(300);
    Serial.print("...");

  }
  Serial.println("");
  Serial.println("Connected");

}


void loop()
{
  while(Serial.available())
  {
    msg=Serial.readString();
  }
    Serial.println("Sending: "+msg);
    httpurl = "http://";
    httpurl+="192.168.100.101";
    httpurl+="/";
    httpurl+=msg;
    http.begin(httpurl);
    http.GET();
    http.end();
    delay(100);
}
