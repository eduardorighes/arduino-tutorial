
#include <Arduino.h>

const int latchPin = 8;
const int clockPin = 12;
const int dataPin = 11;

void setup() {
  // put your setup code here, to run once:
  pinMode(latchPin, OUTPUT);
  pinMode(clockPin, OUTPUT);
  pinMode(dataPin, OUTPUT);

  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  for (int numberToDisplay = 0; numberToDisplay < 256; numberToDisplay++) {
    digitalWrite(latchPin, LOW);
    shiftOut(dataPin, clockPin, MSBFIRST, numberToDisplay);
    digitalWrite(latchPin, HIGH);
    delay(500);

    Serial.print("value: ");
    Serial.println(numberToDisplay);
  }
}
