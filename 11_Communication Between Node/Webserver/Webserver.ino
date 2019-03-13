#include <ESP8266WiFi.h>

WiFiServer server(80);

void setup()
{
  Serial.begin(115200);
  WiFi.disconnect();
  delay(3000);
  Serial.println("");
  Serial.println("");
  Serial.print("Connecting to: ");
  Serial.println("dlink");
  WiFi.begin("dlink","iist@4568");
  while ((!(WiFi.status() == WL_CONNECTED))){
    delay(300);
    Serial.print("...");

  }
  Serial.println("");
  Serial.println("Connected");
  server.begin();
  Serial.print("local Ip = ");
  Serial.println((WiFi.localIP().toString()));
}


void loop()
{
    WiFiClient client = server.available();
    if (!client) { return; }
    while(!client.available()){  delay(1); }
    String s1=client.readStringUntil('\r');
    s1.remove(0, 5);
    Serial.println("Message recived: "+s1);
    client.println("HTTP/1.1 200 OK");
    client.println("Content-Type: text/html");
    client.println("");
    client.println("<!DOCTYPE HTML>");
    client.println("<html>");
    client.println("<h1>Welcome<h1>"+s1);
    client.println("</html>");
    delay(1);

}


//client.stop();
