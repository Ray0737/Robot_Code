#include "src/Motor.h"
#define DirectionPin 4
#define BaudRate 115200
// TASK: CIRCLE THE ROBOT AROUND 30 CM RADIUS CIRCLE TRACK

int theta = 360;
int t = 20000;
int wheelr = 3; //C
float innerr = 22.5; //C
float outerr = 37.5; //C

int innerrpm = (theta*innerr*60000)/(3*t*360);
int outerrpm = (theta*outterr*60000)/(3*t*360); 

void setup() {
  Serial.begin(115200);
  Motor.begin(BaudRate, DirectionPin, &Serial2);
  delay(10000); //Pre Launch
  Motor.turnWheel(1, LEFT, innerrpm);
  Motor.turnWheel(2, RIGHT, outerrpm);
  delay(t);
  Motor.turnWheel(1,0);
  Motor.turnWheel(2,0); 
}

void loop() {
}
