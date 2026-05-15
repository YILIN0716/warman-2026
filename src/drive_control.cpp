/*
 * File:        drive_control.cpp
 * Purpose:     motor control
 * Hardware:    2*driving brush motor
 */

 
#include <Arduino.h>
#include "Arduino_Pins.h"
#include "drive_control.h"

// configurable parameters
static int motorMaxSpeed = 255;

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
}

void motorDriveBackward(void)
{   
    // Set M1 and M2 motor PWM outputs to drive the robot backward
    digitalWrite(M1_DIR, LOW);
    digitalWrite(M2_DIR, LOW);
    analogWrite(M1_PWM, motorMaxSpeed);
    analogWrite(M2_PWM, motorMaxSpeed);
}

void motorTurnLeft(void)
{
    // Set M1 and M2 motor PWM outputs to turn the robot left
    digitalWrite(M1_DIR, LOW);
    digitalWrite(M2_DIR, HIGH);
    analogWrite(M1_PWM, motorMaxSpeed);
    analogWrite(M2_PWM, motorMaxSpeed);
}

void motorTurnRight(void)
{   
    // Set M1 and M2 motor PWM outputs to turn the robot right
    digitalWrite(M1_DIR, HIGH);
    digitalWrite(M2_DIR, LOW);
    analogWrite(M1_PWM, motorMaxSpeed);
    analogWrite(M2_PWM, motorMaxSpeed);
}






