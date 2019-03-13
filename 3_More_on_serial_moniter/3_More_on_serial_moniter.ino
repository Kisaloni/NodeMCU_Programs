int n=5,m=1;
int loopcnt=0;

void setup() {
  // initialize digital pin LED_BUILTIN as an output.
  Serial.begin(9600);
  pinMode(D2, OUTPUT);
  
  Serial.println("Lets Start..");
  String Myname;
  Serial.println("Enter your name : ");
  while(Serial.available()==0){}
  Myname=Serial.readString();
  Serial.println("Welcome "+Myname+"!");
  
  Serial.println("Enter no of blink : ");
  while(Serial.available()==0){}
  n=Serial.parseInt();//Serial.readString();for string
}

// the loop function runs over and over again forever
void loop() {
  loopcnt++;
  Serial.println();
  Serial.print("loop: ");
  Serial.println(loopcnt);
  for(int i=1;i<=n;i++)
  {
    Serial.print("Blink:");
    Serial.println(i);
    digitalWrite(D2,HIGH);
    delay(1000);
    digitalWrite(D2,LOW);
    delay(1000);
  }
}
