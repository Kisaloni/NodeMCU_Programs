#include <ESP8266WiFi.h>

String  i;
WiFiServer server(80);

void setup()
{
  i = "";

Serial.begin(9600);
pinMode(4, OUTPUT);
pinMode(D4, OUTPUT);
digitalWrite(D4,HIGH);
pinMode(D7,OUTPUT);
digitalWrite(D7,HIGH);
  WiFi.disconnect();
  delay(1000);
  Serial.println(" ");
  Serial.println(" ");
   WiFi.begin("mittu","qwertyuiop");
  while ((!(WiFi.status() == WL_CONNECTED))){
    delay(300);
    Serial.print("...");

  }
  Serial.println("");
  Serial.println("Connected");
  Serial.print("local Ip: ");
  Serial.println((WiFi.localIP().toString()));
  server.begin();

}


void loop()
{

    WiFiClient client = server.available();
    if (!client) { return; }
    while(!client.available()){  delay(1); }
    i = (client.readStringUntil('\r'));
    i.remove(0, 5);
    i.remove(i.length()-9,9);
    Serial.println(i);
    if (i == "ON") {
      digitalWrite(4,HIGH);
      digitalWrite(D4,HIGH);
      client.println("HTTP/1.1 200 OK");
      client.println("Content-Type: text/html");
      client.println("");
      client.println("<!DOCTYPE HTML>");
      client.println("<html>");
      client.println("LED ON");
      client.println("</html>");
      delay(1);
    }
    if (i == "OFF") {
      digitalWrite(4,LOW);
      digitalWrite(D4,LOW);
      client.println("HTTP/1.1 200 OK");
      client.println("Content-Type: text/html");
      client.println("");
      client.println("<!DOCTYPE HTML>");
      client.println("<html>");
      client.println("LED OFF");
      client.println("</html>");
      delay(1);
    }
}
