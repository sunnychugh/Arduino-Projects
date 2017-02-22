 /********************************/
// include the library code
// include the library code
#include <Wire.h> 
#include <LiquidCrystal_I2C.h>
LiquidCrystal_I2C lcd(0x27,20,4);  // set the LCD address to 0x27 for a 16 chars and 2 line display
/*********************************************************/
 
#include <Servo.h>     // Include the Servo library
int servoPin = 3;       // Declare the Servo pin 
Servo Servo1;           // Create a servo object 

#define trigPin 13 
#define echoPin 12
int ledLeft = 11; int ledFront = 10; int ledRight = 9;

void setup() {
  // put your setup code here, to run once:
  Serial.begin (9600);      // Set the baudrate for serial communication
  Servo1.attach(servoPin);
  lcd.init();  lcd.backlight();
  pinMode(trigPin, OUTPUT); 
  pinMode(echoPin, INPUT);
  pinMode(ledLeft, OUTPUT);  pinMode(ledFront, OUTPUT);  pinMode(ledRight, OUTPUT);  
}

void loop() {
  // put your main code here, to run repeatedly:
  //long  distance, duration;
  for (int i=0; i<=180; i+=90){
    digitalWrite(ledLeft, LOW); digitalWrite(ledFront, LOW);  digitalWrite(ledRight, LOW);
    long  distance, duration;
    Servo1.write(i); 
    Serial.print("i-");
    Serial.println(i); 
    delay(1000);
    
    digitalWrite(trigPin, LOW);  // Added this line
    delayMicroseconds(2);        // 2usec delay between pulses
    digitalWrite(trigPin, HIGH);
    delayMicroseconds(10);       // Trig pin High for 10usec
    digitalWrite(trigPin, LOW);
    duration = pulseIn(echoPin, HIGH); //Gives the duration of HIGH state a echoPin 
    distance = (duration/2) / 29.1;
    Serial.println(duration);
    Serial.println(distance);

    if (i==0){
      lcd.setCursor(0,0);
      lcd.print("Left (cm) = ");
      lcd.setCursor(15,0);
      lcd.print(distance);
      if (distance<10){digitalWrite(ledLeft, HIGH);}
      }

    if (i==90){
      lcd.setCursor(0,1);
      lcd.print("Front (cm) = ");
      lcd.setCursor(15,1);
      lcd.print(distance);
      if (distance<10){digitalWrite(ledFront, HIGH);} 
      }

    if (i==180){
      lcd.setCursor(0,2);
      lcd.print("Right (cm) = ");
      lcd.setCursor(15,2);
      lcd.print(distance);
      if (distance<10){digitalWrite(ledRight, HIGH);} 
      }
      
    delay(1000);  
      }
}
