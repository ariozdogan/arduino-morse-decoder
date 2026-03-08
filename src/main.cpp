#include <Arduino.h>

const int buttonPin = 8;
const int lightPin = 7;

void setup() {
    pinMode(buttonPin, INPUT);
    pinMode(lightPin, OUTPUT);
}

void loop() {
    if(digitalRead(buttonPin) == HIGH){
        digitalWrite(lightPin, HIGH);
        delay(500);
    }
    else{
        digitalWrite(lightPin, LOW);
    }

}
