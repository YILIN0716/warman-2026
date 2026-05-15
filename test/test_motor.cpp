/*
 * File:        test_motor.cpp
 * Purpose:     WM1 motor driver test — M1 forward/reverse speed ramp
 * Hardware:    Standard brushed DC geared motor connected to WM1 M1 output port
 * Notes:       Motor speed ramps from 0 to maximum then back to 0, direction alternates
 */


#include <Arduino.h>
#include "Arduino_Pins.h"


 // Global Variables
static int g_motorDutyCycle = 0;  // PWM duty cycle (0~255)


void setup()
{
    // Pins in use
    pinMode(M1_PWM, OUTPUT);
    pinMode(M1_DIR, OUTPUT);

    // Unused pins set as OUTPUT to avoid floating state
    pinMode(M2_PWM, OUTPUT);
    pinMode(M2_DIR, OUTPUT);
    pinMode(M3_PWM, OUTPUT);
    pinMode(M3_DIR, OUTPUT);
    pinMode(M4_PWM, OUTPUT);
    pinMode(M4_DIR, OUTPUT);
    pinMode(RELAY1,  OUTPUT);
    pinMode(RELAY2,  OUTPUT);
    pinMode(SERVO1,  OUTPUT);
    pinMode(SERVO2,  OUTPUT);
}


/* ============================================================
 *  loop: forward ramp → reverse ramp
 * ============================================================ */
void loop()
{
    // Forward rotation
    digitalWrite(M1_DIR, HIGH);
    for (g_motorDutyCycle = 0;   g_motorDutyCycle <= 255; g_motorDutyCycle++) { analogWrite(M1_PWM, g_motorDutyCycle); delay(4); }
    for (g_motorDutyCycle = 255; g_motorDutyCycle >= 0;   g_motorDutyCycle--) { analogWrite(M1_PWM, g_motorDutyCycle); delay(4); }

    // Reverse rotation
    digitalWrite(M1_DIR, LOW);
    for (g_motorDutyCycle = 0;   g_motorDutyCycle <= 255; g_motorDutyCycle++) { analogWrite(M1_PWM, g_motorDutyCycle); delay(4); }
    for (g_motorDutyCycle = 255; g_motorDutyCycle >= 0;   g_motorDutyCycle--) { analogWrite(M1_PWM, g_motorDutyCycle); delay(4); }
}