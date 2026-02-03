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
  delay(5000); 
  execute();
}

void stop() {
  Motor.turnWheel(1, LEFT, 0);
  Motor.turnWheel(2, RIGHT, 0);
  delay(1000);
}

void execute() {
  // 1. Forward 48cm
  Motor.turnWheel(1, LEFT, 48 * rpm_unit);
  Motor.turnWheel(2, RIGHT, 48 * rpm_unit);
  delay(t); stop();

  // 2. Back up 15cm
  Motor.turnWheel(1, RIGHT, 15 * rpm_unit);
  Motor.turnWheel(2, LEFT, 15 * rpm_unit);
  delay(t); stop();

  // 3. Rotate back 90 deg Right (Left wheel moves BACK, right still)
  // Distance = (2 * PI * track) * (90/360)
  float dist90 = (2.0 * PI_VAL * track) * 0.25;
  Motor.turnWheel(1, RIGHT, dist90 * rpm_unit);
  Motor.turnWheel(2, RIGHT, 0);
  delay(t); stop();

  // 4. Park deep 19cm
  Motor.turnWheel(1, LEFT, 19 * rpm_unit);
  Motor.turnWheel(2, RIGHT, 19 * rpm_unit);
  delay(t); stop();

  // 5. Back out 19cm
  Motor.turnWheel(1, RIGHT, 19 * rpm_unit);
  Motor.turnWheel(2, LEFT, 19 * rpm_unit);
  delay(t); stop();

  // 6. Move forward to next parking (e.g. 20cm)
  Motor.turnWheel(1, LEFT, 20 * rpm_unit);
  Motor.turnWheel(2, RIGHT, 20 * rpm_unit);
  delay(t); stop();

  // 7. Back to pre-turn pos (e.g. 20cm back)
  Motor.turnWheel(1, RIGHT, 20 * rpm_unit);
  Motor.turnWheel(2, LEFT, 20 * rpm_unit);
  delay(t); stop();

  // 8. 90 deg Left turn (Pivot)
  Motor.turnWheel(1, LEFT, 0);
  Motor.turnWheel(2, RIGHT, dist90 * rpm_unit);
  delay(t); stop();

  // 9. Forward 48cm
  Motor.turnWheel(1, LEFT, 48 * rpm_unit);
  Motor.turnWheel(2, RIGHT, 48 * rpm_unit);
  delay(t); stop();

  // 10. Rotate back (Right wheel moves BACK, left still)
  Motor.turnWheel(1, LEFT, 0);
  Motor.turnWheel(2, LEFT, dist90 * rpm_unit);
  delay(t); stop();

  // 11. Semicircle Dia 38 (Inner R = 11.5, Outer R = 26.5)
  // Half Circumference = PI * R
  float rpm_in = (PI_VAL * 11.5 / (2 * PI_VAL * wheelr)) * (60000.0 / 5000);
  float rpm_out = (PI_VAL * 26.5 / (2 * PI_VAL * wheelr)) * (60000.0 / 5000);
  Motor.turnWheel(1, LEFT, rpm_out);
  Motor.turnWheel(2, RIGHT, rpm_in);
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
  Motor.turnWheel(1, LEFT, 26 * rpm_unit);
  Motor.turnWheel(2, RIGHT, 26 * rpm_unit);
  delay(t); stop();
}

void loop() {
  // Done
}