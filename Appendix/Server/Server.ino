#include <ESP8266WiFi.h>
const char* ssid = "dlink";                     
const char* password = "iist@4568";
IPAddress staticIP832_150(192,168,100,150);
IPAddress gateway832_150(192,168,1,1);
IPAddress subnet832_150(255,255,255,0);
WiFiServer server(80);
void setup() {
  Serial.begin(115200);
  WiFi.disconnect();
  Serial.println();
  Serial.println();
  Serial.print("Connecting to ");
  Serial.println(ssid);
  WiFi.begin (ssid,password);
  while (WiFi.status()!=WL_CONNECTED)           
  {  delay(500);
     Serial.print(".");
  }
  Serial.println("");
  Serial.println("WiFi connected");
  server.begin();
  WiFi.config(staticIP832_150, gateway832_150, subnet832_150);
  delay(1000);
  Serial.println("Connected to dlink");
  Serial.println("Local IP:");
  Serial.println((WiFi.localIP().toString()));
  Serial.println("Gateway IP");
  Serial.println((WiFi.gatewayIP().toString().c_str()));
  Serial.println("Host Name");
  Serial.println((WiFi.hostname()));
  server.begin();
}

void loop() {
  WiFiClient client = server.available();
  if (client) {
    server.write("x");
    client.stop();
  }
}

//#include <SPI.h>
//#include <WiFi.h>
//
//char ssid[] = "yourNetwork";
//char pass[] = "yourPassword";
//int status = WL_IDLE_STATUS;
//
//WiFiServer server(80);
//
//void setup() {
//  // initialize serial:
//  Serial.begin(9600);
//  Serial.println("Attempting to connect to WPA network...");
//  Serial.print("SSID: ");
//  Serial.println(ssid);
//
//  status = WiFi.begin(ssid, pass);
//  if ( status != WL_CONNECTED) { 
//    Serial.println("Couldn't get a wifi connection");
//    while(true);
//  } 
//  else {
//    server.begin();
//  }
//}
//
//void loop() {
//  // listen for incoming clients
//  WiFiClient client = server.available();
//  if (client == true) {
//       // read bytes from the incoming client and write them back
//    // to any clients connected to the server:
//    server.write(client.read());
//  }
//}
