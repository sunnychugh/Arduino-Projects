// Naming of Pins
int ledFirst=7;
int ledSecond=6;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(ledFirst, OUTPUT);
  pinMode(ledSecond, OUTPUT); 
}

void loop() {
  // put your main code here, to run repeatedly:
  Serial.println("");
  Serial.println("Enter which LED to turn On!!");
  Serial.println("Type f for First LED..");
  Serial.println("Type s for Second LED..");
  Serial.println("Enter f or s: ");
    
  //Get the number of bytes (characters) available for reading from the serial port.
  while (Serial.available() == 0) {
    delay(200);  }
    
  if(Serial.available()){
    char inByte = Serial.read();
    Serial.println("");
    Serial.print("You have entered- ");
    Serial.println(inByte);
    Serial.println("");

  switch (inByte) {
  case 'f':
   // First LED is ON 
   digitalWrite(ledFirst, HIGH);    // turn on the LED 1
   digitalWrite(ledSecond, LOW);       
   Serial.println("-- First LED is turned ON --");
   Serial.println("");
   break;
    
   case 's':
   // Second LED is ON
   digitalWrite(ledFirst, LOW);    // turn on the LED 1
   digitalWrite(ledSecond, HIGH);       
   Serial.println("-- Second LED is turned ON --");
   Serial.println("");
   break;

   default:
   // both LED's are OFF:
   digitalWrite(ledFirst, LOW);    // turn off the LED 1
   digitalWrite(ledSecond, LOW);
   Serial.println("-- You should type only f or s !! --");
   }   
}}
// Naming of Pins
int ledFirst=7;
int ledSecond=6;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(ledFirst, OUTPUT);
  pinMode(ledSecond, OUTPUT); 
}

void loop() {
  // put your main code here, to run repeatedly:
  Serial.println("");
  Serial.println("Enter which LED to turn On!!");
  Serial.println("Type f for First LED..");
  Serial.println("Type s for Second LED..");
  Serial.println("Enter f or s: ");
    
  //Get the number of bytes (characters) available for reading from the serial port.
  while (Serial.available() == 0) {
    delay(200);  }
    
  if(Serial.available()){
    char inByte = Serial.read();
    Serial.println("");
    Serial.print("You have entered- ");
    Serial.println(inByte);
    Serial.println("");

  switch (inByte) {
  case 'f':
   // First LED is ON 
   digitalWrite(ledFirst, HIGH);    // turn on the LED 1
   digitalWrite(ledSecond, LOW);       
   Serial.println("-- First LED is turned ON --");
   Serial.println("");
   break;
    
   case 's':
   // Second LED is ON
   digitalWrite(ledFirst, LOW);    // turn on the LED 1
   digitalWrite(ledSecond, HIGH);       
   Serial.println("-- Second LED is turned ON --");
   Serial.println("");
   break;

   default:
   // both LED's are OFF:
   digitalWrite(ledFirst, LOW);    // turn off the LED 1
   digitalWrite(ledSecond, LOW);
   Serial.println("-- You should type only f or s !! --");
   }   
}}

