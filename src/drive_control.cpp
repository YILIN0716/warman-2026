/*
 * File:        drive_control.cpp
 * Purpose:     motor control with 
 * Hardware:    2*driving brush motor
 */


#include <Arduino.h>
#include "DEFINED_PINS.h"
#include "drive_control.h"

// configurable parameters
static int go_to_collect_ms = 8000;
static int back_to_start_ms = 8000;
static int turn_time_ms     = 4000;
static int go_up_ramp_ms    = 10000;
static int go_down_ramp_ms  = 10000;
static int go_to_end_ms     = 2000;

static int motorMaxSpeed    = 255;         

// initialization
void motorInit(void)
{
    pinMode(M1_PWM, OUTPUT);
    pinMode(M1_DIR, OUTPUT);
    pinMode(M2_PWM, OUTPUT);
    pinMode(M2_DIR, OUTPUT);
}

// control functions
void motorStop(void)
{
    // Set M1 and M2 motor PWM outputs to 0
    digitalWrite(M1_DIR, LOW);
    digitalWrite(M2_DIR, LOW);
    analogWrite(M1_PWM, 0);
    analogWrite(M2_PWM, 0);
}

void motorDriveForward(void)
{
    // Set M1 and M2 motor PWM outputs to drive the robot forward
    digitalWrite(M1_DIR, HIGH);
    digitalWrite(M2_DIR, HIGH);
    analogWrite(M1_PWM, motorMaxSpeed);
    analogWrite(M2_PWM, motorMaxSpeed);
    delay(go_to_collect_ms);
}

void motorDriveBackward(void)
{   
    // Set M1 and M2 motor PWM outputs to drive the robot backward
    digitalWrite(M1_DIR, LOW);
    digitalWrite(M2_DIR, LOW);
    analogWrite(M1_PWM, motorMaxSpeed);
    analogWrite(M2_PWM, motorMaxSpeed);
    delay(back_to_start_ms);
}

void motorTurnLeft(void)
{
    // Set M1 and M2 motor PWM outputs to turn the robot left
    digitalWrite(M1_DIR, LOW);
    digitalWrite(M2_DIR, HIGH);
    analogWrite(M1_PWM, motorMaxSpeed);
    analogWrite(M2_PWM, motorMaxSpeed);
    delay(turn_time_ms);
}

void motorTurnRight(void)
{   
    // Set M1 and M2 motor PWM outputs to turn the robot right
    digitalWrite(M1_DIR, HIGH);
    digitalWrite(M2_DIR, LOW);
    analogWrite(M1_PWM, motorMaxSpeed);
    analogWrite(M2_PWM, motorMaxSpeed);
    delay(turn_time_ms);
}


void motorUpRamp(void)
{
    // Set M1 and M2 motor PWM outputs to drive the robot up the ramp
    digitalWrite(M1_DIR, HIGH);
    digitalWrite(M2_DIR, HIGH);
    analogWrite(M1_PWM, motorMaxSpeed);
    analogWrite(M2_PWM, motorMaxSpeed);
    delay(go_up_ramp_ms);
}

void motorDownRamp(void)
{
    // Set M1 and M2 motor PWM outputs to drive the robot down the ramp
    digitalWrite(M1_DIR, LOW);
    digitalWrite(M2_DIR, LOW);
    analogWrite(M1_PWM, motorMaxSpeed);
    analogWrite(M2_PWM, motorMaxSpeed);
    delay(go_down_ramp_ms);
}

void motorDriveEnd(void)
{
    // Set M1 and M2 motor PWM outputs to drive the robot to the endzone
    digitalWrite(M1_DIR, HIGH);
    digitalWrite(M2_DIR, HIGH);
    analogWrite(M1_PWM, motorMaxSpeed);
    analogWrite(M2_PWM, motorMaxSpeed);
    delay(go_to_end_ms);
}