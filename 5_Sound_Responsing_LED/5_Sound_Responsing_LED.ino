/*
*@author Kishan Dasondhi
*/
#define ledpin 13
#define mic A0
void setup() {
  // put your setup code here, to run once:
pinMode(ledpin,OUTPUT);
pinMode(mic,INPUT);
Serial.begin(9600);
//digitalWrite(ledpin,LOW);
}

void loop() {
  // put your main code here, to run repeatedly:
int val=analogRead(mic);
Serial.println(val);
if(val>1000)
{
  digitalWrite(ledpin,HIGH);
  delay(100);
  digitalWrite(ledpin,LOW);
 // delay(1000); 
}
}
