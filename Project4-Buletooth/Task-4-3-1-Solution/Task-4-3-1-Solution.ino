#include <Servo.h> 
// Naming of Pins
#define trigPin 13
#define echoPin 12
int servoPin = 3;
Servo Servo1; 
#include <Wire.h> 
#include <LiquidCrystal_I2C.h>
LiquidCrystal_I2C lcd(0x27,20,4);
int frontDistance;
int leftDistance;
int rightDistance;
String currentDirection;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600); 
  Servo1.attach(servoPin);
  pinMode(trigPin, OUTPUT); 
  pinMode(echoPin, INPUT);
  lcd.init();  //initialize the lcd
  lcd.backlight();  //open the backlight 
}

void loop() {
  // put your main code here, to run repeatedly:
  Serial.println("");
//  Serial.println("Enter direction!!");
//  Serial.println("Type f for front");
//  Serial.println("Type l left");
//  Serial.println("Type r right");
//  Serial.println("Enter f, l or r: ");
    
  //Get the number of bytes (characters) available for reading from the serial port.
  while (Serial.available() == 0) {
    delay(500);  }
    
    if(Serial.available()){
    char inByte = Serial.read();
    Serial.println("");
    Serial.print("You have entered- ");
    Serial.println(inByte);
    Serial.println("");

  switch (inByte) {
   case 'f':
   currentDirection = "Front";
   Servo1.write(90);
   delay(1000);     
   Serial.println("the distance in front is");
   Serial.println("");
   frontDistance = checkDistance();
   Serial.println(frontDistance);
   displayLCD();
   break;
    
   case 'l':
   currentDirection = "Left";
   Servo1.write(180);
   delay(1000);  
   Serial.println("the distance left is");
   Serial.println("");
   leftDistance = checkDistance();
   Serial.println(leftDistance);
   displayLCD();
   break;

   case 'r':
   currentDirection = "Right";
   Servo1.write(0);
   delay(1000);  
   Serial.println("the distance right is");
   Serial.println("");
   rightDistance = checkDistance();
   Serial.println(rightDistance);
   displayLCD();
   break;

   default:
   Serial.println("-- You should type only f, l or r !! --");
   }   
}}

int checkDistance(){
  long duration, distance;
  digitalWrite(trigPin, LOW);  // Added this line
  delayMicroseconds(2);        // 2usec delay between pulses
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);       // Trig pin High for 10usec
  digitalWrite(trigPin, LOW);
  duration = pulseIn(echoPin, HIGH); //Gives the duration of HIGH state a echoPin 
  distance = (duration/2) / 29.1;
  return distance;
}

void displayLCD(){
  String line1, line2, line3, line4;
  line1 = "Front " + String(frontDistance) + " cm";
  line2 = "Left " + String(leftDistance) + " cm";
  line3 = "Right " + String(rightDistance) + " cm";

  if (currentDirection == "Front"){
    if (frontDistance < 12){
    line4 = "Unsafe to move";
    }
    else {
      line4 = "Safe to move";
    }
  }
  else if (currentDirection == "Left"){
    if (leftDistance < 12){
    line4 = "Unsafe to move";
    }
    else {
      line4 = "Safe to move";
    }
  }
  else if (currentDirection == "Right"){
    if (rightDistance < 12){
    line4 = "Unsafe to move";
    }
    else {
      line4 = "Safe to move";
    }
  }
  else{
    line4 = "Situation Unknown";
  }



  lcd.clear();

  lcd.setCursor ( 0, 0 );            // go to the top left corner
  lcd.print(line1); // write this string on the top row
  lcd.setCursor ( 0, 1 );            // go to the 2nd row
  lcd.print(line2); // pad string with spaces for centering
  lcd.setCursor ( 0, 2 );            // go to the third row
  lcd.print(line3); // pad with spaces for centering
  lcd.setCursor ( 0, 3 );            // go to the fourth row
  lcd.print(line4);
}

