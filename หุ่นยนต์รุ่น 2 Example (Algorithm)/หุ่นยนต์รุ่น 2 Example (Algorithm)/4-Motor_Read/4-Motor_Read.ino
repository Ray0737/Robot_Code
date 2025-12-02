#include "src/Motor.h"
#define DirectionPin 4
#define BaudRate 115200

// Note. ไม่สามารถใช้มือหมุนมอเตอร์ทั้ง 2 ข้างได้

void setup() {
  // put your setup code here, to run once:
  Motor.begin(BaudRate, DirectionPin, &Serial2);
  Serial.begin(115200);
  Motor.turnWheel(1, LEFT, 10);
}

void loop() {
  // put your main code here, to run repeatedly:

  int Position = Motor.readPosition(1);  // Request and Print the Position
  // if (Position) --> to get the correct position value
  if (Position) {
    Serial.print(Position);
    Serial.println(" of 360");
  }
}