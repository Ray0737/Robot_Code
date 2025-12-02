#include "src/Motor.h"
#define DirectionPin 4
#define BaudRate 115200

void setup() {
  // put your setup code here, to run once:
  Motor.begin(BaudRate, DirectionPin, &Serial2);
}

void loop() {
  // put your main code here, to run repeatedly:
  int RPM = 50; //maximum 60
  Motor.turnWheel(1,RIGHT,RPM);

}
