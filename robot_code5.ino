#include "src/Motor.h"
#include <ESP32Servo.h>
#define DirectionPin 4
#define BaudRate 115200
Servo myservo; 
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
  myservo.attach(16); 
  delay(5000); 
  // myservo.write(-90);  // Moves to 90 degrees
  // delay(4000);
  // myservo.write(0);
  execute();
}

void stop() {
  Motor.turnWheel(1, LEFT, 0);
  Motor.turnWheel(2, RIGHT, 0);
  delay(1000);
}

void execute() {

  // 1. FORWARD 47
  Motor.turnWheel(1, LEFT, 47 * rpm_unit);
  Motor.turnWheel(2, RIGHT, 47 * rpm_unit);
  delay(t); stop();

  delay(3000); // CHECK POINT BOX 1

  Motor.turnWheel(1, RIGHT, 7 * rpm_unit);
  Motor.turnWheel(2, LEFT, 7 * rpm_unit);
  delay(t); stop();

  // 2. ROTATION 90DG BACK RIGHT
  // Distance = (2 * PI * track) * (90/360)
  float dist90 = (2.0 * PI_VAL * track) * 0.25;
  Motor.turnWheel(1, RIGHT, dist90 * rpm_unit);
  Motor.turnWheel(2, RIGHT, 0);
  delay(t); stop();

  // 3. BACKWARD 44
  Motor.turnWheel(1, RIGHT, 44 * rpm_unit);
  Motor.turnWheel(2, LEFT, 44 * rpm_unit);
  delay(t); stop();

  delay(2000); // CHECK POINT BOX 2

  // 4. FORWARD 44
  Motor.turnWheel(1, LEFT, 44 * rpm_unit);
  Motor.turnWheel(2, RIGHT, 44 * rpm_unit);
  delay(t); stop();

  // 5. ROTATION 90DG RIGHT TURN
  Motor.turnWheel(1, LEFT, dist90 * rpm_unit);
  Motor.turnWheel(2, RIGHT,0);
  delay(t); stop();

  // 6. FORWARD 9
  Motor.turnWheel(1, LEFT, 5 * rpm_unit);
  Motor.turnWheel(2, RIGHT, 5 * rpm_unit);
  delay(t); stop();

  delay(2000); // CHECK POINT BOX 3

  // 7. FORWARD 21
  Motor.turnWheel(1, LEFT, 24 * rpm_unit);
  Motor.turnWheel(2, RIGHT, 24 * rpm_unit);
  delay(t); stop();

  // myservo.write(-90);  // Moves to 90 degrees
  // delay(2000);
  // myservo.write(0);
  delay(2000); // CHECK POINT BOX 4

  Motor.turnWheel(1, LEFT,0);
  Motor.turnWheel(2, LEFT,dist90 * rpm_unit);
  delay(t); stop();

  Motor.turnWheel(1, RIGHT,0);
  Motor.turnWheel(2, RIGHT,dist90 * rpm_unit);
  delay(t); stop();

  
  // 8. BACKWARD 21
  Motor.turnWheel(1, RIGHT, 24 * rpm_unit);
  Motor.turnWheel(2, LEFT, 24 * rpm_unit);
  delay(t); stop();

  delay(2000); // CHECK POINT BOX 5
  
  // 9. BACKWARD 7
  Motor.turnWheel(1, RIGHT, 5 * rpm_unit);
  Motor.turnWheel(2, LEFT, 5 * rpm_unit);
  delay(t); stop();

  // 10. ROTATION 90DG LEFT TURN
  Motor.turnWheel(1, LEFT, 0);
  Motor.turnWheel(2, RIGHT, dist90 * rpm_unit);
  delay(t); stop();

  // 11. FORWARD 37

  Motor.turnWheel(1, LEFT, 34 * rpm_unit);
  Motor.turnWheel(2, RIGHT, 34 * rpm_unit);
  delay(t); stop();

  // 10. Rotate back (Right wheel moves BACK, left still)
  Motor.turnWheel(1, LEFT, 0);
  Motor.turnWheel(2, LEFT, dist90 * rpm_unit);
  delay(t); stop();

  Motor.turnWheel(1, LEFT, 7 * rpm_unit);
  Motor.turnWheel(2, RIGHT, 7 * rpm_unit);
  delay(t); stop();
  
  int theta = 180;
  int t2 = 10000;
  float innerr = 11; //C
  float outerr = 27; //C

  int innerrpm = (theta*innerr*60000)/(3*t2*360);
  int outerrpm = (theta*outerr*60000)/(3*t2*360); 

  Motor.turnWheel(1, LEFT, innerrpm);
  Motor.turnWheel(2, RIGHT, outerrpm);
  delay(t2-1000); stop();

  Motor.turnWheel(1, LEFT, 13 * rpm_unit);
  Motor.turnWheel(2, RIGHT, 13 * rpm_unit);
  delay(t); stop();

  // 13. Left rotate 60 deg (Right wheel moves)
  float dist60 = (2.0 * PI_VAL * track) * (60.0 / 360.0);
  Motor.turnWheel(1, LEFT, 0);
  Motor.turnWheel(2, RIGHT, dist60 * rpm_unit);
  delay(t); stop();

  // 14. Forward 26cm
  Motor.turnWheel(1, LEFT, 29 * rpm_unit);
  Motor.turnWheel(2, RIGHT, 29 * rpm_unit);
  delay(t); stop();




}

void loop() {
  // Done
}

