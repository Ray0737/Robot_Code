#include "src/Motor.h"
#include <ESP32Servo.h>

// --- Configuration ---
#define DirectionPin 4
#define BaudRate 115200

Servo myservo; 

// --- Physical Robot Constants ---
float wheelr = 3.0;   // Wheel radius in cm
float track = 15.0;   // Distance between wheels in cm
float PI_VAL = 3.14159;
int t = 3000;         // Execution time window for each command (ms)

/**
 * UNIT CALCULATION: rpm_unit
 * Converts "distance in cm" to "RPM required" based on time 't'.
 * Formula: (Distance / Circumference) * (Minutes / Time)
 */
float rpm_unit = (1.0 / (2.0 * PI_VAL * wheelr)) * (60000.0 / t);

void setup() {
  Serial.begin(115200);
  
  // Initialize RS485 Motor Communication
  Motor.begin(BaudRate, DirectionPin, &Serial2);
  myservo.attach(16); 
  
  delay(5000); // Safety startup delay
  execute();   // Run the movement sequence
}

/**
 * Hard stop for both motors with a cooling delay
 */
void stop() {
  Motor.turnWheel(1, LEFT, 0);
  Motor.turnWheel(2, RIGHT, 0);
  delay(1000);
}

void execute() {

  // --- 1. Forward to Box 1 ---
  Motor.turnWheel(1, LEFT, 47 * rpm_unit);
  Motor.turnWheel(2, RIGHT, 47 * rpm_unit);
  delay(t); stop();

  delay(3000); // Checkpoint: Box 1 reached

  // Minor adjustment / nudge back
  Motor.turnWheel(1, RIGHT, 7 * rpm_unit);
  Motor.turnWheel(2, LEFT, 7 * rpm_unit);
  delay(t); stop();

  // --- 2. 90-Degree Pivot (Back Right) ---
  // Calculates arc length for 1/4 of a full circle turn
  float dist90 = (2.0 * PI_VAL * track) * 0.25;
  Motor.turnWheel(1, RIGHT, dist90 * rpm_unit); // Pivot on right wheel
  Motor.turnWheel(2, RIGHT, 0);
  delay(t); stop();

  // --- 3. Backward Travel (44cm) ---
  Motor.turnWheel(1, RIGHT, 44 * rpm_unit);
  Motor.turnWheel(2, LEFT, 44 * rpm_unit);
  delay(t); stop();

  delay(2000); // Checkpoint: Box 2 reached

  // --- 4. Forward Return (44cm) ---
  Motor.turnWheel(1, LEFT, 44 * rpm_unit);
  Motor.turnWheel(2, RIGHT, 44 * rpm_unit);
  delay(t); stop();

  // --- 5. 90-Degree Right Turn ---
  Motor.turnWheel(1, LEFT, dist90 * rpm_unit);
  Motor.turnWheel(2, RIGHT, 0);
  delay(t); stop();

  // --- 6. Short Approach (5cm) ---
  Motor.turnWheel(1, LEFT, 5 * rpm_unit);
  Motor.turnWheel(2, RIGHT, 5 * rpm_unit);
  delay(t); stop();

  delay(2000); // Checkpoint: Box 3 reached

  // --- 7. Advance to Box 4 (22cm) ---
  Motor.turnWheel(1, LEFT, 22 * rpm_unit);
  Motor.turnWheel(2, RIGHT, 22 * rpm_unit);
  delay(t); stop();

  delay(2000); // Checkpoint: Box 4 reached

  // Orientation Adjustments
  Motor.turnWheel(1, LEFT, dist90 * rpm_unit);
  Motor.turnWheel(2, LEFT, 0);
  delay(t); stop();

  Motor.turnWheel(1, RIGHT, dist90 * rpm_unit);
  Motor.turnWheel(2, RIGHT, 0);
  delay(t); stop();

  // --- 8. Backward Approach (22cm) ---
  Motor.turnWheel(1, RIGHT, 22 * rpm_unit);
  Motor.turnWheel(2, LEFT, 22 * rpm_unit);
  delay(t); stop();

  delay(2000); // Checkpoint: Box 5 reached
  
  // --- 9. Final Alignment Adjustments ---
  Motor.turnWheel(1, RIGHT, 5 * rpm_unit);
  Motor.turnWheel(2, LEFT, 5 * rpm_unit);
  delay(t); stop();

  // --- 10. 90-Degree Left Pivot ---
  Motor.turnWheel(1, LEFT, 0);
  Motor.turnWheel(2, RIGHT, dist90 * rpm_unit);
  delay(t); stop();

  // --- 11. Forward Travel (34cm) ---
  Motor.turnWheel(1, LEFT, 34 * rpm_unit);
  Motor.turnWheel(2, RIGHT, 34 * rpm_unit);
  delay(t); stop();

  // --- 12. Complex Arc Movement ---
  // Calculates differential steering for a curved path
  int theta = 180;
  int t2 = 10000;     // Longer duration for smooth curve
  float innerr = 11;  // Inner radius of the curve
  float outerr = 27;  // Outer radius of the curve

  int innerrpm = (theta * innerr * 60000) / (3 * t2 * 360);
  int outerrpm = (theta * outerr * 60000) / (3 * t2 * 360); 

  Motor.turnWheel(1, LEFT, innerrpm);
  Motor.turnWheel(2, RIGHT, outerrpm);
  delay(t2 - 1000); stop();

  // Final Straight (16cm)
  Motor.turnWheel(1, LEFT, 16 * rpm_unit);
  Motor.turnWheel(2, RIGHT, 16 * rpm_unit);
  delay(t); stop();

  // --- 13. 60-Degree Precise Turn ---
  float dist60 = (2.0 * PI_VAL * track) * (60.0 / 360.0);
  Motor.turnWheel(1, LEFT, 0);
  Motor.turnWheel(2, RIGHT, dist60 * rpm_unit);
  delay(t); stop();

  // --- 14. Final Dash (29cm) ---
  Motor.turnWheel(1, LEFT, 29 * rpm_unit);
  Motor.turnWheel(2, RIGHT, 29 * rpm_unit);
  delay(t); stop();
}

void loop() {
  // Static loop: sequence only runs once in setup
}
