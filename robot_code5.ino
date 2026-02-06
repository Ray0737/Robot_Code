#include "src/Motor.h"
#define DirectionPin 4
#define BaudRate 115200

// --- Physical Constants ---
float wheelr = 3.0; 
float track = 15.0; // Distance between wheels
float PI_VAL = 3.14159;
int t = 3000; // Standard delay for most movements

// Calculations for specific movements
// Forward 1cm RPM formula: (1 / (2 * PI * wheelr)) * (60000 / t)
float rpm_unit = (1.0 / (2.0 * PI_VAL * wheelr)) * (60000.0 / t);

void setup() {
  Serial.begin(115200);
  Motor.begin(BaudRate, DirectionPin, &Serial2);
  delay(10000); 
  execute();
}

void stop() {
  Motor.turnWheel(1, LEFT, 0);
  Motor.turnWheel(2, RIGHT, 0);
  delay(1000);
}

void execute() {

  // // 1. FORWARD 47
  // Motor.turnWheel(1, LEFT, 47 * rpm_unit);
  // Motor.turnWheel(2, RIGHT, 47 * rpm_unit);
  // delay(t); stop();

  // delay(5000); // CHECK POINT BOX 1

  // Motor.turnWheel(1, RIGHT, 8 * rpm_unit);
  // Motor.turnWheel(2, LEFT, 8 * rpm_unit);
  // delay(t); stop();

  // // 2. ROTATION 90DG BACK RIGHT
  // // Distance = (2 * PI * track) * (90/360)
  // float dist90 = (2.0 * PI_VAL * track) * 0.25;
  // Motor.turnWheel(1, RIGHT, dist90 * rpm_unit);
  // Motor.turnWheel(2, RIGHT, 0);
  // delay(t); stop();

  // // 3. BACKWARD 44
  // Motor.turnWheel(1, RIGHT, 44 * rpm_unit);
  // Motor.turnWheel(2, LEFT, 44 * rpm_unit);
  // delay(t); stop();

  // delay(5000); // CHECK POINT BOX 2

  // // 4. FORWARD 44
  // Motor.turnWheel(1, LEFT, 44 * rpm_unit);
  // Motor.turnWheel(2, RIGHT, 44 * rpm_unit);
  // delay(t); stop();

  // // 5. ROTATION 90DG RIGHT TURN
  // Motor.turnWheel(1, LEFT, dist90 * rpm_unit);
  // Motor.turnWheel(2, RIGHT,0);
  // delay(t); stop();

  // // 6. FORWARD 9
  // Motor.turnWheel(1, LEFT, 5 * rpm_unit);
  // Motor.turnWheel(2, RIGHT, 5 * rpm_unit);
  // delay(t); stop();

  // delay(5000); // CHECK POINT BOX 3

  // // 7. FORWARD 21
  // Motor.turnWheel(1, LEFT, 24 * rpm_unit);
  // Motor.turnWheel(2, RIGHT, 24 * rpm_unit);
  // delay(t); stop();

  // delay(5000); // CHECK POINT BOX 4
  
  // // 8. BACKWARD 21
  // Motor.turnWheel(1, RIGHT, 24 * rpm_unit);
  // Motor.turnWheel(2, LEFT, 24 * rpm_unit);
  // delay(t); stop();

  // delay(5000); // CHECK POINT BOX 5
  
  // // 9. BACKWARD 7
  // Motor.turnWheel(1, RIGHT, 5 * rpm_unit);
  // Motor.turnWheel(2, LEFT, 5 * rpm_unit);
  // delay(t); stop();

  // // 10. ROTATION 90DG LEFT TURN
  // Motor.turnWheel(1, LEFT, 0);
  // Motor.turnWheel(2, RIGHT, dist90 * rpm_unit);
  // delay(t); stop();

  // // 11. FORWARD 37

  // Motor.turnWheel(1, LEFT, 34 * rpm_unit);
  // Motor.turnWheel(2, RIGHT, 34 * rpm_unit);
  // delay(t); stop();

  // // 10. Rotate back (Right wheel moves BACK, left still)
  // Motor.turnWheel(1, LEFT, 0);
  // Motor.turnWheel(2, LEFT, dist90 * rpm_unit);
  // delay(t); stop();

  // Motor.turnWheel(1, LEFT, 5 * rpm_unit);
  // Motor.turnWheel(2, RIGHT, 5 * rpm_unit);
  // delay(t); stop();
  
  int theta = 180;
  int t = 10000;
  int wheelr = 3.5; //C
  float innerr = 11; //C
  float outerr = 27; //C

  int innerrpm = (theta*innerr*60000)/(3*t*360);
  int outerrpm = (theta*outerr*60000)/(3*t*360); 

  Motor.turnWheel(1, LEFT, innerrpm);
  Motor.turnWheel(2, RIGHT, outerrpm);
  delay(t-1000); stop();

  Motor.turnWheel(1, LEFT, 10 * rpm_unit);
  Motor.turnWheel(2, RIGHT, 10 * rpm_unit);
  delay(t); stop();

  // 13. Left rotate 60 deg (Right wheel moves)
  float dist60 = (2.0 * PI_VAL * track) * (60.0 / 360.0);
  Motor.turnWheel(1, LEFT, 0);
  Motor.turnWheel(2, RIGHT, dist60 * rpm_unit);
  delay(t); stop();

  // 14. Forward 26cm
  Motor.turnWheel(1, LEFT, 20 * rpm_unit);
  Motor.turnWheel(2, RIGHT, 20 * rpm_unit);
  delay(t); stop();




}

void loop() {
  // Done
}

