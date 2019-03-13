/*
* @author kishan Dasondhi
*/
void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);  /* initialise serial communication */
}

void loop() {
  // put your main code here, to run repeatedly:
  Serial.println("Node Mcu"); /* print Electronic Wings at new line per second */
  delay(1000);
}
