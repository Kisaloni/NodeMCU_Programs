/*
* @author kishan Dasondhi
*/

void setup() {
pinMode(D7, OUTPUT);   // Initialize the LED pin as an output
}

void loop() {
digitalWrite(D7, HIGH);// Turn the LED off
delay(1000); 
digitalWrite(D7, LOW); // Turn the LED on
delay(1000);                // Wait for a second
}
