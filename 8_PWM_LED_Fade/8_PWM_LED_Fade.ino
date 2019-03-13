/*
*@author Kishan Dasondhi
*/
#define ledpin D6
void setup() {
  // put your setup code here, to run once:
pinMode(ledpin,OUTPUT);

}

void loop() {
  // put your main code here, to run repeatedly:
  int i=0;
for(int i=0;i<255;i++)
{
  analogWrite(ledpin,i);
  delay(10);
}
//delay(1000);
for(int i=255;i>0;i--)
{
  analogWrite(ledpin,i);
  delay(10);
}
delay(1000);
}
