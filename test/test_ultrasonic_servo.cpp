/*******************************************************************************
 * File:    test_ultrasonic_servo.cpp
 * Purpose: HC-SR04 ultrasonic distance sensor + SG90 servo linkage hardware test
 * Hardware: Arduino Mega 2560 + WM1 Shield
 * Logic:   Distance < 10cm  → servo moves to   0°
 *          Distance 10~20cm → servo moves to  90°
 *          Distance > 20cm  → servo moves to 180°
 * Usage:   To test hardware standalone, copy this file to src/ and remove main.cpp
 ******************************************************************************/

#include <Arduino.h>
#include <Servo.h>
#include "WM1_pins.h"


// Configurable Parameters
static const long  CFG_PULSE_TIMEOUT_US = 30000;  // Ultrasonic timeout (us)
static const int   CFG_LOOP_DELAY_MS    = 100;    // Main loop refresh rate (ms)

static const float CFG_DIST_NEAR_CM     = 10.0f;
static const float CFG_DIST_MID_CM      = 20.0f;

static const int   CFG_SERVO_NEAR_DEG   = 0;
static const int   CFG_SERVO_MID_DEG    = 90;
static const int   CFG_SERVO_FAR_DEG    = 180;


// Servo Object
static Servo g_servo;


// Function Declarations
void  ultrasonicInit(void);
float ultrasonicGetDistance(void);
int   selectServoAngle(float distanceCm);
void  servoInit(void);
void  servoSetAngle(int targetAngleDeg);


// setup
void setup()
{
    Serial.begin(115200);
    ultrasonicInit();
    servoInit();
    Serial.println("Ultrasonic + Servo Test Starting...");
}


// loop: Sense → Decide → Act
void loop()
{
    float distanceCm     = ultrasonicGetDistance();
    int   targetAngleDeg = selectServoAngle(distanceCm);

    Serial.print("Distance: ");
    Serial.print(distanceCm);
    Serial.println(" cm");

    servoSetAngle(targetAngleDeg);
    delay(CFG_LOOP_DELAY_MS);
}


// Initialise ultrasonic sensor pins
void ultrasonicInit(void)
{
    pinMode(TRIG_PIN, OUTPUT);
    pinMode(ECHO_PIN, INPUT);
    digitalWrite(TRIG_PIN, LOW);
}


// Single ultrasonic distance measurement
// Returns distance in cm; returns 999.0f on timeout (no obstacle detected)
float ultrasonicGetDistance(void)
{
    digitalWrite(TRIG_PIN, LOW);
    delayMicroseconds(2);
    digitalWrite(TRIG_PIN, HIGH);
    delayMicroseconds(10);
    digitalWrite(TRIG_PIN, LOW);

    long echoDurationUs = pulseIn(ECHO_PIN, HIGH, CFG_PULSE_TIMEOUT_US);
    if (echoDurationUs == 0) return 999.0f;

    return (echoDurationUs * 0.0343f) / 2.0f;
}


// Select servo angle based on measured distance
int selectServoAngle(float distanceCm)
{
    if (distanceCm < CFG_DIST_NEAR_CM) return CFG_SERVO_NEAR_DEG;
    if (distanceCm < CFG_DIST_MID_CM)  return CFG_SERVO_MID_DEG;
    return CFG_SERVO_FAR_DEG;
}


// Initialise servo: attach pin and home to 90°
void servoInit(void)
{
    g_servo.attach(SERVO1);
    g_servo.write(CFG_SERVO_MID_DEG);
    delay(500);
}


// Set servo angle
// targetAngleDeg: desired angle, valid range 0~180°
void servoSetAngle(int targetAngleDeg)
{
    g_servo.write(targetAngleDeg);
}