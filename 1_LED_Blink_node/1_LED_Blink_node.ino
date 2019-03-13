/*
* @author kishan Dasondhi 
* LED_BUILTIN/D0/GPIO 16
*/
void setup() {
  // initialize digital pin LED_BUILTIN as an output.
  pinMode(16, OUTPUT);
}

// the loop function runs over and over again forever
void loop() {
  digitalWrite(D0, LOW);   // turn the LED on (Low is the HIGH voltage level in Node Mcu)
  delay(1000);                       // wait for a second
  digitalWrite(D0, HIGH);    // turn the LED off by making the voltage LOW
  delay(1000);                       // wait for a second
}
