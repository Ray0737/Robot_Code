#include "src/Motor.h"
#define DirectionPin 4
#define BaudRate 115200
// TASK: MOVE ON A STAR CIRCUMFURENCE TRACK

int theta1 = 360;
int theta2 = 72; // Right Turn
int theta3 = 144; // Left Turn

int t1 = 5000;
int t2 = 5000; // Forward Time
int t3 = 5000; // Turning Time

int wheelr = 3; // Custom
float innerr = 15; // (Distance between wheels to wheels)
float outerr = 15; 

float constantrpm = 20; // origin 30
float innerrpm1 = (theta2*innerr*60000)/(3*t2*360); // T1 6
float outerrpm1 = (theta2*outerr*60000)/(3*t2*360); // 
float innerrpm2 = (theta3*innerr*60000)/(3*t3*360); //  
float outerrpm2 = (theta3*outerr*60000)/(3*t3*360); // T2 12
 
void setup() {
  Serial.begin(115200);
  Motor.begin(BaudRate, DirectionPin, &Serial2);  
}

// 1 = Left | 2 = Right

void forward(){
  Motor.turnWheel(1,LEFT,constantrpm); 
  Motor.turnWheel(2,RIGHT,constantrpm);
  delay(t1);
  Motor.turnWheel(1,RIGHT,0); 
  Motor.turnWheel(2,RIGHT,0);
}

void turn1(){ // R turn
  Motor.turnWheel(1, LEFT, innerrpm1); // Check LR Status when Run
  Motor.turnWheel(2, LEFT, 0);
  delay(t3);
  Motor.turnWheel(1,RIGHT,0); 
  Motor.turnWheel(2,RIGHT,0);
}

// void turn1(){ // R turn RECOMMENDED
//   Motor.turnWheel(1, LEFT, 17); // Check LR Status when Run
//   Motor.turnWheel(2, RIGHT, 0);
//   delay(t3);
//   Motor.turnWheel(1,LEFT,0); 
//   Motor.turnWheel(2,RIGHT,0);
// }


void turn2(){ // L turn
  Motor.turnWheel(1, LEFT, 0); 
  Motor.turnWheel(2, RIGHT, outerrpm1);
  delay(t3+4000);
  Motor.turnWheel(1,LEFT,0); 
  Motor.turnWheel(2,LEFT,0);
}

// void turn2(){ // l turn RECOMMENDED
//   Motor.turnWheel(1, LEFT, 0); // Check LR Status when Run
//   Motor.turnWheel(2, RIGHT, 34);
//   delay(t3);
//   Motor.turnWheel(1,LEFT,0); 
//   Motor.turnWheel(2,RIGHT,0);
// }


void execute(){ // Main Function
  delay(10000);
  for(int i=0; i < 5;i++){
    delay(1000);
    forward();
    delay(3000);
    turn1();
    delay(3000);
    forward();
    delay(3000);
    turn2();
    delay(3000);
  }
}

void loop(){ 
 execute();
 while(1);
}
