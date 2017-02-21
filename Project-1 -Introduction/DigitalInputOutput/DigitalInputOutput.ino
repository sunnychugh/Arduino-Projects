
// Digital Input Output
// 


// Naming of Pins
int led1=7;
int led2=6;
int switch1=5;
int switch2=4;

// the setup routine runs once when you press reset:
void setup() {
  // initialize the digital pin as an output.
  pinMode(switch1, INPUT);
  pinMode(switch2, INPUT); 
  pinMode(led1, OUTPUT);
  pinMode(led2, OUTPUT); 
 
}

// the loop routine runs over and over again forever:
void loop() {
 // read the switch1 input:
   if (digitalRead(switch1) == HIGH) {
     // if the switch is closed:
     digitalWrite(led1, HIGH);    // turn on the LED 1
   }
   else {
     // if the switch is open:
     digitalWrite(led1, LOW);    // turn off the LED 1
   }   
  
  
  // read the switch2 input:
   if (digitalRead(switch2) == HIGH) {
     // if the switch is closed:
     digitalWrite(led2, HIGH);    // turn on the LED 2
   }
   else {
     // if the switch is open:
     digitalWrite(led2, LOW);    // turn off the LED 2
   }              
  
  
}
