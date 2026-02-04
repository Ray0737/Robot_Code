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
  // 1. Forward 46-47 CM [CHECKED]
  Motor.turnWheel(1, LEFT, 47 * rpm_unit);
  Motor.turnWheel(2, RIGHT, 47 * rpm_unit);
  delay(t); stop();

  Motor.turnWheel(1, RIGHT, 3 * rpm_unit);
  Motor.turnWheel(2, LEFT, 3 * rpm_unit);
  delay(t); stop();

  // 2. Rotate back 90 deg Right (Left wheel moves BACK, right still) [CHECKED]
  // Distance = (2 * PI * track) * (90/360)
  float dist90 = (2.0 * PI_VAL * track) * 0.25;
  Motor.turnWheel(1, RIGHT, dist90 * rpm_unit);
  Motor.turnWheel(2, RIGHT, 0);
  delay(t); stop();

  // 3. Back out 44 cm [CHECKED]
  Motor.turnWheel(1, RIGHT, 44 * rpm_unit);
  Motor.turnWheel(2, LEFT, 44 * rpm_unit);
  delay(t); stop();

  // 4. Move forward to next parking [CHECKED]
  Motor.turnWheel(1, LEFT, 44.5 * rpm_unit);
  Motor.turnWheel(2, RIGHT, 44.5 * rpm_unit);
  delay(t); stop();

  // 5. 90 deg Left turn [CHECKED]
  Motor.turnWheel(1, LEFT, dist90 * rpm_unit);
  Motor.turnWheel(2, RIGHT,0);
  delay(t); stop();

  // 6. Forward 21cm [CHECKED]
  Motor.turnWheel(1, LEFT, 21 * rpm_unit);
  Motor.turnWheel(2, RIGHT, 21 * rpm_unit);
  delay(t); stop();

  Motor.turnWheel(1, LEFT, 3 * rpm_unit);
  Motor.turnWheel(2, RIGHT, 3 * rpm_unit);
  delay(t); stop();
  
  // 6. Backward 30cm [CHECKED]
  Motor.turnWheel(1, RIGHT, 30.5 * rpm_unit);
  Motor.turnWheel(2, LEFT, 30.5 * rpm_unit);
  delay(t); stop();

  // 7. 90 deg right turn 
  Motor.turnWheel(1, LEFT, 0);
  Motor.turnWheel(2, RIGHT,dist90 * rpm_unit);
  delay(t); stop();


  Motor.turnWheel(1, LEFT, 37 * rpm_unit);
  Motor.turnWheel(2, RIGHT, 37 * rpm_unit);
  delay(t); stop();

  // 10. Rotate back (Right wheel moves BACK, left still)
  Motor.turnWheel(1, LEFT, 0);
  Motor.turnWheel(2, LEFT, dist90 * rpm_unit);
  delay(t); stop();

  // 11. Semicircle Dia 38 (Inner R = 11.5, Outer R = 26.5)
  // Half Circumference = PI * R
  float rpm_in = (PI_VAL * 11 / (2 * PI_VAL * wheelr)) * (60000.0 / 5000);
  float rpm_out = (PI_VAL * 30 / (2 * PI_VAL * wheelr)) * (60000.0 / 5000);
  Motor.turnWheel(1, LEFT, rpm_in);
  Motor.turnWheel(2, RIGHT, rpm_out);
  delay(5000); stop();

  // 12. Forward 20cm
  Motor.turnWheel(1, LEFT, 20 * rpm_unit);
  Motor.turnWheel(2, RIGHT, 20 * rpm_unit);
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