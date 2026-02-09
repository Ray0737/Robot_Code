#include "src/Motor.h"

// --- Hardware Configuration ---
#define DirectionPin 4
#define BaudRate 115200

// --- Physical Constants (cm) ---
const float WHEEL_RADIUS = 3.0; 
const float TRACK_WIDTH  = 15.0; // Distance between the two wheels
const float PI_VAL       = 3.14159;
const int MOVE_DURATION  = 3000;  // Standard time window (ms) for movements

/** * Conversion Factor: rpm_unit
 * Converts a distance (cm) into the RPM required to cover that distance 
 * within the standard MOVE_DURATION (t).
 * Formula: (Distance / Circumference) * (Minutes / Time_in_ms)
 */
float rpm_unit = (1.0 / (2.0 * PI_VAL * WHEEL_RADIUS)) * (60000.0 / MOVE_DURATION);

void setup() {
    Serial.begin(115200);
    // Initialize motor with serial communication on Serial2
    Motor.begin(BaudRate, DirectionPin, &Serial2);
    
    delay(10000); // Safety startup delay
    executePath();
}

/**
 * Stops both motors and waits for inertia to settle.
 */
void stopRobot() {
    Motor.turnWheel(1, LEFT, 0);
    Motor.turnWheel(2, RIGHT, 0);
    delay(1000);
}

void executePath() {
    // --- 1. Move Forward 47cm ---
    Motor.turnWheel(1, LEFT, 47 * rpm_unit);
    Motor.turnWheel(2, RIGHT, 47 * rpm_unit);
    delay(MOVE_DURATION); 
    stopRobot();

    delay(5000); // CHECKPOINT BOX 1

    // Adjustment: Back up slightly
    Motor.turnWheel(1, RIGHT, 7 * rpm_unit);
    Motor.turnWheel(2, LEFT, 7 * rpm_unit);
    delay(MOVE_DURATION); 
    stopRobot();

    // --- 2. Pivot Turn: 90 Degrees Back-Right ---
    // Distance one wheel travels for a pivot turn: (2 * PI * track) * (angle / 360)
    float dist90 = (2.0 * PI_VAL * TRACK_WIDTH) * 0.25;
    Motor.turnWheel(1, RIGHT, dist90 * rpm_unit);
    Motor.turnWheel(2, RIGHT, 0); // Pivot on the right wheel
    delay(MOVE_DURATION); 
    stopRobot();

    // --- 3. Move Backward 44cm ---
    Motor.turnWheel(1, RIGHT, 44 * rpm_unit);
    Motor.turnWheel(2, LEFT, 44 * rpm_unit);
    delay(MOVE_DURATION); 
    stopRobot();

    delay(5000); // CHECKPOINT BOX 2

    // --- 4. Move Forward 44cm ---
    Motor.turnWheel(1, LEFT, 44 * rpm_unit);
    Motor.turnWheel(2, RIGHT, 44 * rpm_unit);
    delay(MOVE_DURATION); 
    stopRobot();

    // --- 5. Pivot Turn: 90 Degrees Right ---
    Motor.turnWheel(1, LEFT, dist90 * rpm_unit);
    Motor.turnWheel(2, RIGHT, 0);
    delay(MOVE_DURATION); 
    stopRobot();

    // --- 6. Forward 5cm ---
    Motor.turnWheel(1, LEFT, 5 * rpm_unit);
    Motor.turnWheel(2, RIGHT, 5 * rpm_unit);
    delay(MOVE_DURATION); 
    stopRobot();

    delay(5000); // CHECKPOINT BOX 3

    // --- 7. Forward 24cm ---
    Motor.turnWheel(1, LEFT, 24 * rpm_unit);
    Motor.turnWheel(2, RIGHT, 24 * rpm_unit);
    delay(MOVE_DURATION); 
    stopRobot();

    delay(5000); // CHECKPOINT BOX 4
    
    // --- 8. Backward 24cm ---
    Motor.turnWheel(1, RIGHT, 24 * rpm_unit);
    Motor.turnWheel(2, LEFT, 24 * rpm_unit);
    delay(MOVE_DURATION); 
    stopRobot();

    delay(5000); // CHECKPOINT BOX 5
    
    // --- 9. Backward 5cm ---
    Motor.turnWheel(1, RIGHT, 5 * rpm_unit);
    Motor.turnWheel(2, LEFT, 5 * rpm_unit);
    delay(MOVE_DURATION); 
    stopRobot();

    // --- 10. Pivot Turn: 90 Degrees Left ---
    Motor.turnWheel(1, LEFT, 0);
    Motor.turnWheel(2, RIGHT, dist90 * rpm_unit);
    delay(MOVE_DURATION); 
    stopRobot();

    // --- 11. Forward 34cm ---
    Motor.turnWheel(1, LEFT, 34 * rpm_unit);
    Motor.turnWheel(2, RIGHT, 34 * rpm_unit);
    delay(MOVE_DURATION); 
    stopRobot();

    // --- 12. Arc Turn (180 Degrees) ---
    int theta = 180;
    int t_arc = 10000;
    float inner_radius = 11.0;
    float outer_radius = 27.0;

    // Direct RPM calculation for specific curve radius
    int inner_rpm = (theta * inner_radius * 60000.0) / (3.0 * t_arc * 360.0);
    int outer_rpm = (theta * outer_radius * 60000.0) / (3.0 * t_arc * 360.0); 

    Motor.turnWheel(1, LEFT, inner_rpm);
    Motor.turnWheel(2, RIGHT, outer_rpm);
    delay(t_arc - 1000); 
    stopRobot();

    // --- 13. Pivot Turn: 60 Degrees Left ---
    float dist60 = (2.0 * PI_VAL * TRACK_WIDTH) * (60.0 / 360.0);
    Motor.turnWheel(1, LEFT, 0);
    Motor.turnWheel(2, RIGHT, dist60 * rpm_unit);
    delay(MOVE_DURATION); 
    stopRobot();

    // --- 14. Final Forward 27cm ---
    Motor.turnWheel(1, LEFT, 27 * rpm_unit);
    Motor.turnWheel(2, RIGHT, 27 * rpm_unit);
    delay(MOVE_DURATION); 
    stopRobot();
}

void loop() {
    // Execution finished
}
