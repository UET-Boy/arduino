#include <Arduino.h>


int count = 0;

void setup() {
  pinMode(LED_BUILTIN, OUTPUT);
  Serial.begin(9600);
  while (! Serial);
  Serial.println("Enter Y to turn on the LED:");
}

void loop(){
  if (Serial.available()){
    char ch = Serial.read();
    if (ch == 'y' ||	ch == 'Y'){
      digitalWrite(LED_BUILTIN, HIGH);
      Serial.println("You have turned on the LED!!");
      Serial.print("The LED was off for ");
      Serial.print(count);
      Serial.println(" seconds");
      Serial.println("If you want to switch it off, simply enter N or n!");
      count = 0;
    }
    if (ch == 'n' ||	ch == 'N'){
      digitalWrite(LED_BUILTIN, LOW);
      Serial.println("You have turned off the LED!!");
      Serial.print("The LED was on for ");
      Serial.print(count);
      Serial.println(" seconds");
      Serial.println("If you want to switch it on, simply enter Y or y!");
      count = 0;
    }
  }
    delay(1000);
    //count += 1;
    count = count + 1;
}