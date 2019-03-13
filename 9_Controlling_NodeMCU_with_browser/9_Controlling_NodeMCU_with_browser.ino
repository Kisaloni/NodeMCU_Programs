/*
*@author Kishan Dasondhi
*/

/*including wifi library*/
#include <ESP8266WiFi.h>

/*creating char pointer to hold ssid and password*/
const char* ssid = "dlink";                     //enter your ssid
const char* password = "iist@4568";             //enter your password

/*Defining led pin*/
int ledpin=2;                                   // D4 in NodeMcu

/*Creating wifi server*/
WiFiServer server(80);

/* void setup starts here*/
void setup() 
{
  /*starting serial communication*/
  Serial.begin(115200);
  delay(10);

  /*Defining pinmode*/
  pinMode(ledpin,OUTPUT);
  digitalWrite(ledpin,LOW);

  
  Serial.println();
  Serial.println();
  Serial.print("Connecting to ");
  Serial.println(ssid);

  /*to connect with hotspot*/
  WiFi.begin (ssid,password);

  while (WiFi.status()!=WL_CONNECTED)           //check if connected
  {  delay(500);
     Serial.print(".");
  }


  Serial.println("");
  Serial.println("WiFi connected");
  // Start the server
  server.begin();
  Serial.println("Server started");
 
  /*Print the IP Address*/

  Serial.print("Use this url to connect: ");
  Serial.print("http://");
  Serial.print(WiFi.localIP());
  Serial.println("/");  
}

void loop() 
{
  /*Check if a client has connected*/
  WiFiClient client = server.available();
  if (!client)
  { 
    return;
  }
  
  /*Wait until the client sends some data*/
  while (!client.available())
  {
    delay(1);
  }
  
  /*Read the first line of the request*/
  String request = client.readStringUntil('\r');
  Serial.println(request);
  client.flush();
  //Match the request

  int value=LOW;
  if (request.indexOf(" /LED=ON1")!=-1)
  {
    digitalWrite(ledpin,1);
    value=HIGH ; 
  }

  if (request.indexOf(" /LED=OFF1")!=-1)
  {
    digitalWrite(ledpin,0);
    value=LOW ;
  }

  
  client.println("HTTP/1.1 200 OK");
  client.println("Content-Type: text/html");
  client.println("");// do not forget this one
  client.println("<!DOCTYPE HTML>");
  client.println("<html>");
  client.println("<title>switch</title>");
  client.print("Led pin1 is now: ");
  if(value==HIGH)
  {
    client.print("OFF");
  }
  else
  {
    client.print("ON");
  }
  client.println("<br><br>");
  client.println("<a href=\"/LED=OFF1\"><button>Turn <b>ON</b></button></a>");
  client.println("<a href=\"/LED=ON1\"><button>Turn <b>OFF</b></button></a></br>");
  client.println("</html>");
  delay(1);
  Serial.println("");
  }
