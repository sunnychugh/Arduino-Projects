
// 
// Analog read
// 

// Naming of Pins
int Led = 5;
int Signal= 0;      // A0 pin is named as signal variable
int SignalValue = 0; // The digitzed value of signal will be assigned to this variable

// the setup routine runs once when you press reset:
void setup() {
  // initialize the digital pin as an output.
  pinMode(Led, OUTPUT);
  Serial.begin(9600); 
 
}

// the loop routine runs over and over again forever:
void loop() {
 
  SignalValue = analogRead(Signal);    // read the input pin
  Serial.println(SignalValue);         // debug value on Seral Monitor
  if(SignalValue < 512)
  {
  digitalWrite(Led, LOW);    // turn on the LED 1
  }
  else if(SignalValue >= 512)
  {
  digitalWrite(Led, HIGH);    // turn on the LED 1
  }

}

