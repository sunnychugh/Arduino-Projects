/********************************/
// include the library code
// include the library code
#include <Wire.h> 
#include <LiquidCrystal_I2C.h>
LiquidCrystal_I2C lcd(0x27,20,4);  // set the LCD address to 0x27 for a 16 chars and 2 line display
/*********************************************************/

float degreePerUnit=(23.00/51.00);
float signalValue=0.00;
int signal=0;		            // A0 pin
float degreeCelsius=0.00;
float signalVoltage=0.00;

int switch1=7;
int switch2=4;
char* name[]={"sunny ","aamir ","souvik"};
int i=0;

// the setup routine runs once when you press reset:
void setup() {
  // initialize the digital pin as an output.
  lcd.init();  //initialize the lcd
  lcd.backlight();  //open the backlight
  Serial.begin(9600);
  pinMode(switch1,INPUT);
  pinMode(switch2,INPUT);  
  
}

// the loop routine runs over and over again forever:
void loop() {
 //Serial.println(degreePerUnit);
 signalValue=analogRead(signal);
 //Serial.println(signalValue);
 signalVoltage=(signalValue*0.0049);
 // Serial.println(signalVoltage);
 degreeCelsius=( degreePerUnit*signalValue);
 //Serial.println("LAB-1");
 //Serial.print("Temp=");
 //Serial.println(degreeCelsius);
 //Serial.println("Group Members");
  
 lcd.setCursor(0,0);
 lcd.print("LAB-1");
 lcd.setCursor(0,1);
 lcd.print("Temp=");
 lcd.setCursor(9,1);
 lcd.print(degreeCelsius);
 lcd.setCursor(0,2);
 lcd.print("Group Members:");
 
  
  if(digitalRead(switch1)== HIGH){
    i=i+1;
    if(i==3){
      i=2;}
      //delay(1000);
     }
  else if(digitalRead(switch2)== HIGH){
    i=i-1;
    if(i==-1){
      i=0;}
      //delay(1000);
    }    
  //Serial.println(name[i]);
  //Serial.println();
  lcd.setCursor(0,3);
  lcd.print(name[i]);
  delay(1000); 
  
  
}
