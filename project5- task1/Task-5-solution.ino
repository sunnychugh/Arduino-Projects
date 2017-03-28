//Ultrasonic Setup
#define trigPin 13
#define echoPin 12

//Servo Setup
#include <Servo.h> 
int servoPin = 3;// Declare the Servo pin 
Servo Servo1;// Create a servo object 

// Motor 1
int dir1PinA = 5;
int dir2PinA = 6;
int speedPinA = 4; 

// Motor 2
int dir3PinA = 7;
int dir4PinA = 8;
int speedPinB = 11; 

void setup() {
  Serial.begin (9600);
  Servo1.attach(servoPin);
  
  //Ultrasonic
  pinMode(trigPin, OUTPUT); 
  pinMode(echoPin, INPUT);
  
  //Motor Pins
  pinMode(dir1PinA,OUTPUT);
  pinMode(dir2PinA,OUTPUT);
  pinMode(dir3PinA,OUTPUT);
  pinMode(dir4PinA, OUTPUT);
  pinMode(speedPinA,OUTPUT);
  pinMode(speedPinB,OUTPUT);
  
}

long measure(){
  //Measure Distance with Ultrasonic
  long distance, duration;
  digitalWrite(trigPin, LOW);  // Added this line
  delayMicroseconds(2);        // 2usec delay between pulses
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);       // Trig pin High for 10usec
  digitalWrite(trigPin, LOW);
  duration = pulseIn(echoPin, HIGH); //Gives the duration of HIGH state a echoPin 
  distance = (duration/2) / 29.1;
  return distance;
}

void forward(int fspeed)
{
  //int rspeed = fspeed*1.4371;
  analogWrite(speedPinA, fspeed);
  analogWrite(speedPinB, 255);
  digitalWrite(dir1PinA, LOW);
  digitalWrite(dir3PinA, LOW);
  digitalWrite(dir2PinA, HIGH);
  digitalWrite(dir4PinA, HIGH);
}
void backward(int bspeed)
{
  analogWrite(speedPinA, bspeed);
  digitalWrite(dir1PinA, HIGH);
  digitalWrite(dir2PinA, LOW);
  analogWrite(speedPinB, 255);
  digitalWrite(dir3PinA, HIGH);
  digitalWrite(dir4PinA, LOW);
}
void leftmove(int lspeed)
{
  analogWrite(speedPinA, lspeed);
  digitalWrite(dir1PinA, LOW);
  digitalWrite(dir2PinA, HIGH);
  analogWrite(speedPinB, lspeed);
  digitalWrite(dir3PinA, HIGH);
  digitalWrite(dir4PinA, LOW);
}
void rightmove(int rspeed)
{
  analogWrite(speedPinA, rspeed);
  digitalWrite(dir1PinA, HIGH);
  digitalWrite(dir2PinA, LOW);
  analogWrite(speedPinB, rspeed);
  digitalWrite(dir3PinA, LOW);
  digitalWrite(dir4PinA, HIGH);
}
void stopall()
{
  analogWrite(speedPinA, 0);
  digitalWrite(dir1PinA, HIGH);
  digitalWrite(dir2PinA, LOW);
  analogWrite(speedPinB, 0);
  digitalWrite(dir3PinA, LOW);
  digitalWrite(dir4PinA, HIGH);
}

void loop() {
  
  long fdistance, ldistance, rdistance;
  boolean deadend = false;
  Servo1.write(90);
  delay(150);
  forward(128);
  fdistance = measure();
  if (fdistance < 30){
    do {
      stopall();
      Servo1.write(180);//left
      delay(1500);
      ldistance = measure();
      
      Servo1.write(0);//right
      delay(1500);
      rdistance = measure();
      Servo1.write(90);
      
      //check which is larger
      if (ldistance > rdistance && ldistance > 15){
        leftmove(140);
        delay(130);
        deadend = false;
      }
      else if (rdistance > ldistance && rdistance > 15){
        rightmove(140);
        delay(130);
        deadend = false;
      }
      else {
        backward(128);
        delay(300);
        
        deadend = true;
      }
    }while (deadend == true);
  }
}
