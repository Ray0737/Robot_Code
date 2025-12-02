#include "src/Motor.h"
#define DirectionPin 4
#define BaudRate 115200
// TASK: MOVE ON A STAR CIRCUMFURENCE TRACK

int theta1 = 360;
int theta2 = 72; // R
int theta3 = 144; // L

int t1 = 20000;
int t2 = 3000; // S
int t3 = 1200; // T

int wheelr = 3; //C
float innerr = 22.5; //C
float outerr = 37.5; //C

int constantrpm = 30;
int innerrpm1 = (theta2*innerr*60000)/(3*t2*360); // T1
int outerrpm1 = (theta2*outterr*60000)/(3*t2*360); // T1
int innerrpm2 = (theta3*innerr*60000)/(3*t3*360); // T2
int outerrpm2 = (theta3*outterr*60000)/(3*t3*360); // T2
 
void setup() {
  Serial.begin(115200);
  Motor.begin(BaudRate, DirectionPin, &Serial2);  
}

void forward(){
  Motor.turnWheel(1,constantrpm); 
  Motor.turnWheel(2,constantrpm);
  delay(t2);
  Motor.turnWheel(1,0); 
  Motor.turnWheel(2,0);
}

void turn1(){ // R turn
  Motor.turnWheel(1, RIGHT, innerrpm1); 
  Motor.turnWheel(2, LEFT, outerrpm1);
  delay(t3);
  Motor.turnWheel(1,0); 
  Motor.turnWheel(2,0);
}

void turn2(){ // L turn
  Motor.turnWheel(1, LEFT, innerrpm2); 
  Motor.turnWheel(2, RIGHT, outerrpm2);
  delay(t3);
  Motor.turnWheel(1,0); 
  Motor.turnWheel(2,0);
}

void execute(){
  for(int i=0; i < 5,i++){
    delay(10000);
    forward();
    delay(5000);
    turn1();
    delay(5000);
    forward();
    delay(5000);
    turn2();
    delay(5000);
  }
}

void loop(){
 execute()
 while(1)
}
