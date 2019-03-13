/*
 * @author Kishan Dasondhi
*/
# define pot A0
# define led D6       //or GPIO 12
void setup() {
  // put your setup code here, to run once:
pinMode(pot,INPUT);
pinMode(led,OUTPUT);
Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
int val=analogRead(pot);
Serial.print("val= ");
Serial.println(val);

int sp=map(val,0,1023,0,255);
Serial.print("speed= ");
Serial.println(sp);
analogWrite(led,sp);
delay(100);
}
