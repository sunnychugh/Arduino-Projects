
#define trigPin 13
#define echoPin 12
#define led1 11
#define led2 10

void setup() {
  Serial.begin (9600);      // Set the baudrate for serial communication
  pinMode(trigPin, OUTPUT); 
  pinMode(echoPin, INPUT);
  pinMode(led1, OUTPUT);
  pinMode(led2, OUTPUT);
}

void loop() {
  long duration, distance;
  digitalWrite(trigPin, LOW);  // Added this line
  delayMicroseconds(2);        // 2usec delay between pulses
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);       // Trig pin High for 10usec
  digitalWrite(trigPin, LOW);
  duration = pulseIn(echoPin, HIGH); //Gives the duration of HIGH state a echoPin 
  distance = (duration/2) / 29.1;
  if (distance < 10 ) {  // This is where the LED On/Off happens
    digitalWrite(led1,HIGH); // When the Red condition is met, the Green LED should turn off
  digitalWrite(led2,LOW);
}
  else {
    digitalWrite(led1,LOW);
    digitalWrite(led2,HIGH);
  }
  if (distance >= 200 || distance <= 0){
    Serial.println("Out of range");
    digitalWrite(led1,HIGH);
    digitalWrite(led2,HIGH);
  }
  else {
    Serial.print(distance);
    Serial.println(" cm");
  }
  delay(500);
}
