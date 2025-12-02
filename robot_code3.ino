#include "src/Motor.h"
#define DirectionPin 4
#define BaudRate 115200
// TASK: MOVE ON A STAR CIRCUMFURENCE TRACK

int theta1 = 360;
int theta2 = 72; // Right Turn
int theta3 = 144; // Left Turn

int t1 = 5000;
int t2 = 4000; // Forward Time
int t3 = 7000; // Turning Time

int wheelr = 3; // Custom
float innerr = 17.5; // (Distance between wheels to wheels)
float outerr = 17.5; 

int constantrpm = 30;
int innerrpm1 = (theta2*innerr*60000)/(3*t2*360); // T1 apx 22.5
int outerrpm1 = (theta2*outterr*60000)/(3*t2*360); // T1 apx 37.5
int innerrpm2 = (theta3*innerr*60000)/(3*t3*360); // T2 apx 25.714
int outerrpm2 = (theta3*outterr*60000)/(3*t3*360); // T2 apx 42.857
 
void setup() {
  Serial.begin(115200);
  Motor.begin(BaudRate, DirectionPin, &Serial2);  
}

// 1 = Left | 2 = Right

void forward(){
  Motor.turnWheel(1,constantrpm); 
  Motor.turnWheel(2,constantrpm);
  delay(t1);
  Motor.turnWheel(1,0); 
  Motor.turnWheel(2,0);
}

void turn1(){ // R turn
  Motor.turnWheel(1, RIGHT, innerrpm1); // Check LR Status when Run
  Motor.turnWheel(2, RIGHT, outerrpm1);
  delay(t3);
  Motor.turnWheel(1,0); 
  Motor.turnWheel(2,0);
}

// void turn1(){ // R turn RECOMMENDED
//   Motor.turnWheel(1, RIGHT, 17); // Check LR Status when Run
//   Motor.turnWheel(2, RIGHT, 0);
//   delay(t3);
//   Motor.turnWheel(1,0); 
//   Motor.turnWheel(2,0);
// }


void turn2(){ // L turn
  Motor.turnWheel(1, LEFT, innerrpm2); 
  Motor.turnWheel(2, LEFT, outerrpm2);
  delay(t3);
  Motor.turnWheel(1,0); 
  Motor.turnWheel(2,0);
}

// void turn2(){ // l turn RECOMMENDED
//   Motor.turnWheel(1, LEFT, 0); // Check LR Status when Run
//   Motor.turnWheel(2, LEFT, 34);
//   delay(t3);
//   Motor.turnWheel(1,0); 
//   Motor.turnWheel(2,0);
// }


void execute(){ // Main Function
  delay(10000);
  for(int i=0; i < 5,i++){
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
 execute();
 while(1);
}
