#include "src/Motor.h"
#include <ESP32Servo.h>

/* --- Hardware & Connection Settings --- */
#define DirectionPin 4
#define BaudRate 115200
Servo myservo; 

/* --- Robot Physical Parameters --- */
float wheelr = 3.0;      // Wheel radius in cm
float track = 15.0;       // Wheelbase width (center to center) in cm
float PI_VAL = 3.14159;
int t = 3000;             // Standard movement duration (3 seconds)

/**
 * MATH EXPLANATION:
 * Distance to RPM Conversion Unit:
 * 1. Circumference = 2 * PI * wheelr
 * 2. Rotations needed = Distance / Circumference
 * 3. RPM = (Rotations / t_ms) * 60,000
 * Final unit represents RPM required to move 1cm in 't' milliseconds.
 */
float rpm_unit = (1.0 / (2.0 * PI_VAL * wheelr)) * (60000.0 / t);

void setup() {
  Serial.begin(115200);
  
  // Initialize drive system and servo
  Motor.begin(BaudRate, DirectionPin, &Serial2);
  myservo.attach(16); 
  
  delay(5000); // Wait 5s for placement/calibration
  execute();   // Begin navigation sequence
}

/**
 * Helper: Stops both motors and waits to stabilize physics/momentum.
 */
void stop() {
  Motor.turnWheel(1, LEFT, 0);
  Motor.turnWheel(2, RIGHT, 0);
  delay(1000);
}

void execute() {

  // --- PHASE 1: Initial Advance & Correction ---
  // Forward 47cm
  Motor.turnWheel(1, LEFT, 47 * rpm_unit);
  Motor.turnWheel(2, RIGHT, 47 * rpm_unit);
  delay(t); stop();

  delay(3000); // Idle at CHECK POINT 1

  // Small correction backward (7cm)
  Motor.turnWheel(1, RIGHT, 7 * rpm_unit);
  Motor.turnWheel(2, LEFT, 7 * rpm_unit);
  delay(t); stop();

  // --- PHASE 2: Navigation to Box 2 ---
  // Calculate arc length for a 90-degree pivot turn (Radius = track width)
  float dist90 = (2.0 * PI_VAL * track) * 0.25; 
  
  // Pivot 90° Back-Right (Stationary wheel 2)
  Motor.turnWheel(1, RIGHT, dist90 * rpm_unit);
  Motor.turnWheel(2, RIGHT, 0);
  delay(t); stop();

  // Backward 44cm
  Motor.turnWheel(1, RIGHT, 44 * rpm_unit);
  Motor.turnWheel(2, LEFT, 44 * rpm_unit);
  delay(t); stop();

  delay(2000); // Idle at CHECK POINT 2

  // --- PHASE 3: Pivot and Alignment ---
  // Forward 44cm
  Motor.turnWheel(1, LEFT, 44 * rpm_unit);
  Motor.turnWheel(2, RIGHT, 44 * rpm_unit);
  delay(t); stop();

  // 90° Right Turn Pivot
  Motor.turnWheel(1, LEFT, dist90 * rpm_unit);
  Motor.turnWheel(2, RIGHT, 0);
  delay(t); stop();

  // Forward 5cm to Box 3
  Motor.turnWheel(1, LEFT, 5 * rpm_unit);
  Motor.turnWheel(2, RIGHT, 5 * rpm_unit);
  delay(t); stop();

  delay(2000); // Idle at CHECK POINT 3

  // --- PHASE 4: Box 4 & Reversing Maneuvers ---
  // Forward 22cm to Box 4
  Motor.turnWheel(1, LEFT, 22 * rpm_unit);
  Motor.turnWheel(2, RIGHT, 22 * rpm_unit);
  delay(t); stop();
  delay(2000); // Idle at CHECK POINT 4

  // Swing out left, then right
  Motor.turnWheel(1, LEFT, dist90 * rpm_unit);
  Motor.turnWheel(2, LEFT, 0);
  delay(t); stop();

  Motor.turnWheel(1, RIGHT, dist90 * rpm_unit);
  Motor.turnWheel(2, RIGHT, 0);
  delay(t); stop();

  // Backward 22cm
  Motor.turnWheel(1, RIGHT, 22 * rpm_unit);
  Motor.turnWheel(2, LEFT, 22 * rpm_unit);
  delay(t); stop();

  delay(2000); // Idle at CHECK POINT 5
  
  // --- PHASE 5: Advanced Arcs & Final Path ---
  // Reverse 5cm
  Motor.turnWheel(1, RIGHT, 5 * rpm_unit);
  Motor.turnWheel(2, LEFT, 5 * rpm_unit);
  delay(t); stop();

  // 90° Left Turn
  Motor.turnWheel(1, LEFT, 0);
  Motor.turnWheel(2, RIGHT, dist90 * rpm_unit);
  delay(t); stop();

  // Forward 34cm
  Motor.turnWheel(1, LEFT, 34 * rpm_unit);
  Motor.turnWheel(2, RIGHT, 34 * rpm_unit);
  delay(t); stop();

  // Pivot correction
  Motor.turnWheel(1, LEFT, 0);
  Motor.turnWheel(2, LEFT, dist90 * rpm_unit);
  delay(t); stop();

  // Forward 7cm
  Motor.turnWheel(1, LEFT, 7 * rpm_unit);
  Motor.turnWheel(2, RIGHT, 7 * rpm_unit);
  delay(t); stop();
  
  // --- ARC CALCULATION (Differential Drive Smooth Turn) ---
  int theta = 180;    // Target angle
  int t2 = 10000;     // Time for arc (10 seconds)
  float innerr = 11;  // Inner radius of the curve
  float outerr = 27;  // Outer radius of the curve

  // Calculate specific RPMs for differential steering
  int innerrpm = (theta * innerr * 60000) / (3 * t2 * 360);
  int outerrpm = (theta * outerr * 60000) / (3 * t2 * 360); 

  Motor.turnWheel(1, LEFT, innerrpm);
  Motor.turnWheel(2, RIGHT, outerrpm);
  delay(t2 - 1000); stop();

  // Final 16cm push
  Motor.turnWheel(1, LEFT, 16 * rpm_unit);
  Motor.turnWheel(2, RIGHT, 16 * rpm_unit);
  delay(t); stop();

  // 60° Left Rotate
  float dist60 = (2.0 * PI_VAL * track) * (60.0 / 360.0);
  Motor.turnWheel(1, LEFT, 0);
  Motor.turnWheel(2, RIGHT, dist60 * rpm_unit);
  delay(t); stop();

  // Final stretch 29cm
  Motor.turnWheel(1, LEFT, 29 * rpm_unit);
  Motor.turnWheel(2, RIGHT, 29 * rpm_unit);
  delay(t); stop();
}

void loop() {
  // Navigation Complete
}
