#include "src/Motor.h"
#include <ESP32Servo.h>

// --- Hardware Configuration ---
#define DirectionPin 4
#define BaudRate 115200
Servo myservo; 

// --- Physical Constants & Robot Geometry ---
float wheelr  = 3.0;   // Radius of the wheels in cm
float track   = 15.0;  // Distance between the two drive wheels in cm
float PI_VAL  = 3.14159;
int t         = 3000;  // Default duration (ms) for movement steps

/**
 * RPM Unit Calculation:
 * Converts "distance in cm" to "required RPM" to cover that distance in time 't'.
 * Formula: (Distance / Circumference) * (Minutes / Time in ms)
 */
float rpm_unit = (1.0 / (2.0 * PI_VAL * wheelr)) * (60000.0 / t);

void setup() {
  Serial.begin(115200);
  
  // Initialize Motor Shield and Servo
  Motor.begin(BaudRate, DirectionPin, &Serial2);
  myservo.attach(16); 
  
  delay(5000); // Safety delay to place robot on start line
  
  execute();   // Run the movement sequence once
}

/**
 * Emergency/Interval Stop
 * Briefly halts both motors to prevent inertia drift between steps.
 */
void stop() {
  Motor.turnWheel(1, LEFT, 0);
  Motor.turnWheel(2, RIGHT, 0);
  delay(1000);
}

void execute() {
  // --- 1. Move Forward to Checkpoint 1 ---
  Motor.turnWheel(1, LEFT, 47 * rpm_unit);
  Motor.turnWheel(2, RIGHT, 47 * rpm_unit);
  delay(t); stop();

  delay(3000); // Wait at CHECK POINT BOX 1

  // Small corrective reverse
  Motor.turnWheel(1, RIGHT, 7 * rpm_unit);
  Motor.turnWheel(2, LEFT, 7 * rpm_unit);
  delay(t); stop();

  // --- 2. 90 Degree Pivot Turn (Back Right) ---
  // Calculates arc length for 1/4 of a circle based on wheel track
  float dist90 = (2.0 * PI_VAL * track) * 0.25;
  Motor.turnWheel(1, RIGHT, dist90 * rpm_unit); // Pivot on stationary Right wheel
  Motor.turnWheel(2, RIGHT, 0);
  delay(t); stop();

  // --- 3. Backward Movement to Checkpoint 2 ---
  Motor.turnWheel(1, RIGHT, 44 * rpm_unit);
  Motor.turnWheel(2, LEFT, 44 * rpm_unit);
  delay(t); stop();

  delay(2000); // Wait at CHECK POINT BOX 2

  // --- 4. Return Forward ---
  Motor.turnWheel(1, LEFT, 44 * rpm_unit);
  Motor.turnWheel(2, RIGHT, 44 * rpm_unit);
  delay(t); stop();

  // --- 5. 90 Degree Right Turn ---
  Motor.turnWheel(1, LEFT, dist90 * rpm_unit);
  Motor.turnWheel(2, RIGHT, 0);
  delay(t); stop();

  // --- 6. Short Forward Burst to Checkpoint 3 ---
  Motor.turnWheel(1, LEFT, 5 * rpm_unit);
  Motor.turnWheel(2, RIGHT, 5 * rpm_unit);
  delay(t); stop();

  delay(2000); // Wait at CHECK POINT BOX 3

  // --- 7. Approach Checkpoint 4 ---
  Motor.turnWheel(1, LEFT, 24 * rpm_unit);
  Motor.turnWheel(2, RIGHT, 24 * rpm_unit);
  delay(t); stop();
  delay(2000); // Wait at CHECK POINT BOX 4

  // Swing maneuvers (S-turn or adjustment)
  Motor.turnWheel(1, LEFT, dist90 * rpm_unit);
  Motor.turnWheel(2, LEFT, 0);
  delay(t); stop();

  Motor.turnWheel(1, RIGHT, dist90 * rpm_unit);
  Motor.turnWheel(2, RIGHT, 0);
  delay(t); stop();

  // --- 8. Backward to Checkpoint 5 ---
  Motor.turnWheel(1, RIGHT, 24 * rpm_unit);
  Motor.turnWheel(2, LEFT, 24 * rpm_unit);
  delay(t); stop();

  delay(2000); // Wait at CHECK POINT BOX 5
  
  // --- 9. Final Alignment & Positioning ---
  Motor.turnWheel(1, RIGHT, 5 * rpm_unit);
  Motor.turnWheel(2, LEFT, 5 * rpm_unit);
  delay(t); stop();

  // 10. 90 Degree Left Turn (Pivot on Left)
  Motor.turnWheel(1, LEFT, 0);
  Motor.turnWheel(2, RIGHT, dist90 * rpm_unit);
  delay(t); stop();

  // 11. Move to Final Section
  Motor.turnWheel(1, LEFT, 34 * rpm_unit);
  Motor.turnWheel(2, RIGHT, 34 * rpm_unit);
  delay(t); stop();

  // --- Curved Path Calculation (180 Degree Arc) ---
  int theta = 180;
  int t2 = 10000;    // Longer duration for smooth curve
  float innerr = 11; // Inner radius of curve
  float outerr = 27; // Outer radius of curve

  // Calculate differential speeds for the arc
  int innerrpm = (theta * innerr * 60000) / (3 * t2 * 360);
  int outerrpm = (theta * outerr * 60000) / (3 * t2 * 360); 

  Motor.turnWheel(1, LEFT, innerrpm);
  Motor.turnWheel(2, RIGHT, outerrpm);
  delay(t2 - 1000); stop();

  // --- Final Stretch ---
  float dist60 = (2.0 * PI_VAL * track) * (60.0 / 360.0);
  Motor.turnWheel(1, LEFT, 0);
  Motor.turnWheel(2, RIGHT, dist60 * rpm_unit); // 60 deg turn
  delay(t); stop();

  Motor.turnWheel(1, LEFT, 29 * rpm_unit); // Final 29cm forward
  Motor.turnWheel(2, RIGHT, 29 * rpm_unit);
  delay(t); stop();
}

void loop() {
  // Program finished, idling.
}
