#include "src/Motor.h"
#define DirectionPin 4
#define BaudRate 115200
int RPM_1 = 40;
int RPM_2 = 40;

void setup() {
  // put your setup code here, to run once:
  Motor.begin(BaudRate, DirectionPin, &Serial2);
}

void loop() {
  // put your main code here, to run repeatedly:
  Motor.turnWheel(1,LEFT,RPM_1);
  Motor.turnWheel(2,LEFT,RPM_2);
}
