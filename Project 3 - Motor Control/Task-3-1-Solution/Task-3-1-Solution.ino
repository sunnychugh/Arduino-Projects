// Motor 1
int dir1PinA = 6;
int dir2PinA = 7;
int speedPinA = 5; // Needs to be a PWM pin to be able to control motor speed

void setup() {
  // put your setup code here, to run once:
Serial.begin(9600);

//Define L298N Dual H-Bridge Motor Controller Pins

pinMode(dir1PinA,OUTPUT);
pinMode(dir2PinA,OUTPUT);
pinMode(speedPinA,OUTPUT);
}


void CarForward(int movingSpeed){
analogWrite(speedPinA, movingSpeed);//Sets speed variable via PWM 
digitalWrite(dir1PinA, LOW);
digitalWrite(dir2PinA, HIGH);
Serial.print("Car Moving Forward at speed = ");
Serial.println(movingSpeed);
  }

void CarStop(int movingSpeed){
analogWrite(speedPinA, movingSpeed);//Sets speed variable via PWM 
//digitalWrite(dir1PinA, LOW);
//digitalWrite(dir2PinA, HIGH);
Serial.print("Car Stopped, speed = ");
Serial.println(movingSpeed);
  }

void CarBackward(int movingSpeed){
analogWrite(speedPinA, movingSpeed);//Sets speed variable via PWM 
digitalWrite(dir1PinA, HIGH);
digitalWrite(dir2PinA, LOW);
Serial.print("Car Moving Backward at speed = ");
Serial.println(movingSpeed);
  }

void loop() {
  // put your main code here, to run repeatedly:
  CarForward(90);
  delay(2000);
  CarForward(167);
  delay(3000);
  CarForward(255);
  delay(2000);

  CarStop(0);
  delay(3000);

  CarBackward(255);
  delay(2000);
  CarBackward(167);
  delay(2000);
  CarBackward(90);
  delay(2000);
  
  CarBackward(0);
  delay(2000);
  
}
