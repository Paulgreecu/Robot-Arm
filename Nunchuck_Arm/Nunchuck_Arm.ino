#include <Wiichuck.h>
#include <Wire.h>

Wiichuck wii;

int inBase1 = 4;
int inBase2 = 5;
int inBase3 = 7;
int inBase4 = 6;

void setup() {
  Serial.begin(9600);
  wii.init();

  // Set all the motor control pins to outputs
  
  pinMode(inBase1, OUTPUT);
  pinMode(inBase2, OUTPUT);
  pinMode(inBase3, OUTPUT);
  pinMode(inBase4, OUTPUT);
  
  // Turn off motors - Initial state
  digitalWrite(inBase1, LOW);
  digitalWrite(inBase2, LOW);
  digitalWrite(inBase3, LOW);
  digitalWrite(inBase4, LOW);
  
  wii.calibrate();  // calibration
}


void loop() {
  
  if (wii.poll()) {

    if(wii.joyX()>150){
      digitalWrite(inBase1, HIGH);
      digitalWrite(inBase2, LOW);
    }else if(wii.joyX()<100){
      digitalWrite(inBase1, LOW);
      digitalWrite(inBase2, HIGH);
    }else{
      digitalWrite(inBase1, LOW);
      digitalWrite(inBase2, LOW);
    }

    if(wii.joyY()>150){
      digitalWrite(inBase3, HIGH);
      digitalWrite(inBase4, LOW);
    }else if(wii.joyY()<100){
      digitalWrite(inBase3, LOW);
      digitalWrite(inBase4, HIGH);
    }else{
      digitalWrite(inBase3, LOW);
      digitalWrite(inBase4, LOW);
    }
    
    Serial.print("joy:");
    Serial.print(wii.joyX());
    Serial.print(", ");
    Serial.println(wii.joyY());
    //Serial.print("  \t");
    /*
    
    Serial.print("accle:");
    Serial.print(wii.accelX());
    Serial.print(", ");
    Serial.print(wii.accelY());
    Serial.print(", ");
    Serial.print(wii.accelZ());
    Serial.print("  \t");
    
    Serial.print("button:");
    Serial.print(wii.buttonC());
    Serial.print(", ");
    Serial.print(wii.buttonZ());
    Serial.println("");
    */
  }
  

}
