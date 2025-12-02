#include "src/Motor.h"
#define DirectionPin 4
#define BaudRate 115200

void setup() {
  // put your setup code here, to run once:
  Motor.begin(BaudRate, DirectionPin, &Serial2);
  Serial.begin(115200);

  // ให้มอเตอร์ตัวที่จะให้มือหมุน (ID 1) ถูก disable Torque ไว้
  Motor.disableTorque(1);

  // ให้มอเตอร์ ID 2 หมุน
  Motor.turnWheel(2, LEFT, 10);
}

void loop() {
  // put your main code here, to run repeatedly:

  int Position = Motor.readPosition(1);  // Request and Print the Position
  
  // if (Position) --> to get the correct position value
  if (Position) {

    Serial.print(Position);
    Serial.println(" of 360");
    delay(16);  // 60 RPM to time = (60*1000)/(360*RPM)
    if (Position > 270) {
      Motor.turnWheel(2, LEFT, 10);
    } else if (Position <= 90) {
      Motor.turnWheel(2, RIGHT, 10);
    } else {
      Motor.Stop(2);
    }

  }

}