#include "src/Motor.h"
#define DirectionPin 4
#define BaudRate 115200
int velocity = 65;
void setup() {
  // put your setup code here, to run once:
  Motor.begin(BaudRate, DirectionPin, &Serial2);
}

void loop() {
  // put your main code here, to run repeatedly:
  Motor.turnWheel(1,LEFT,velocity);
  delay(1000);
  Motor.turnWheel(1,LEFT,0);
  delay(1000);
}
