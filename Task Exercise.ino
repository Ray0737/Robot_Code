#include "src/Motor.h"

#define DirectionPin 4
#define BaudRate 115200

// Q1 var
int d = 25;
int m = 11;
int y = 2009;
int sum;

// Q2 var
float thb = 100.0;
float usd;
float rate = 0.03;

// Q3 var
float r = 14;
float c = 0.0;
float pi = 3.14;

// Q4 var
int num1 = 5;
int num2 = 6;
int num3 = 6;
int num4 = 1;
int num5 = 9;
long result;

// Q5 var
double v_i = 10.0;
double v_f = 5.0;
double t = 4.0;
double a;

// Q6-7 var
int innerRPM = 18;
int outerRPM = 36;
unsigned long moveTime = 20000;
int motor1Position = 0;

// Q8-9 var
int i = 1

void setup() {
  Serial.begin(115200);
  while (!Serial);

  Motor.begin(BaudRate, DirectionPin, &Serial2);
  Motor.turnWheel(1, LEFT, innerRPM);
  Motor.turnWheel(2, LEFT, 0); 

  // Q1
  sum = d + m + y;
  Serial.println("--- Date/Sum ---");
  Serial.print(d);
  Serial.print("/");
  Serial.print(m);
  Serial.print("/");
  Serial.println(y);
  Serial.print("Sigma: ");
  Serial.println(sum);

  // Q2
  usd = thb * rate;
  Serial.println("--- Currency Conversion ---");
  Serial.print("THB = ");
  Serial.println(thb);
  Serial.print("USD = ");
  Serial.println(usd);
  Serial.println("---");

  // Q3
  c = 2 * pi * r;
  Serial.println("--- Circumference Calculation ---");
  Serial.print("Input radius (r) = ");
  Serial.println(r);
  Serial.print("Circumference (C) = ");
  Serial.println(c);
  Serial.println("---");
  Serial.println("Ready for next input:");
  Serial.println("---");

  // Q4
  result = num5 * num1 + num2 * num3 + num4;
  Serial.println("--- Calculation Q4 ---");
  Serial.println("Calculation:");
  Serial.print("Result: ");
  Serial.println(result);
  Serial.println("---");

  // Q5
  a = (v_f - v_i) / t;
  Serial.println("--- Acceleration Calculation ---");
  Serial.print("Initial Velocity (v_i): ");
  Serial.print(v_i);
  Serial.println(" m/s");
  Serial.print("Final Velocity (v_f): ");
  Serial.print(v_f);
  Serial.println(" m/s");
  Serial.print("Time (t): ");
  Serial.print(t);
  Serial.println(" s");
  Serial.print("Acceleration (a): ");
  Serial.print(a, 2);
  Serial.println(" m/s^2");
  Serial.println("---");

  //Q8
  for (i = 1; i <= 10; ++i) {
    Serial.println(i);
    delay(500); 
  }
  Serial.println("Count Complete");

  //Q9
  while (i <= 10) {
    Serial.println(i);
    i = i + 1; 
    delay(500);
  }
  Serial.println("Count Complete");

}


void loop() {

  delay(100);

  // Q6
  motor1Position += 10;
  if (motor1Position > 360) {
    motor1Position = 0;
  }

  Serial.println("--- Motor Control ---");
  Serial.print("M1 Position: ");
  Serial.println(motor1Position);

  // Q7
  if (motor1Position > 270) {
    Motor.turnWheel(2, LEFT, outerRPM);
  } else if (motor1Position < 90) {
    Motor.turnWheel(2, RIGHT, outerRPM);
  } else {
    Motor.turnWheel(2, LEFT, 0);
  }

  delay(5000);
}
