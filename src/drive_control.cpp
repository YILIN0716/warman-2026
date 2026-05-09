/*
 * File:        drive_control.cpp
 * Purpose:     motor control
 * Hardware:    2*driving brush motor
 */

 
#include <Arduino.h>
#include "Arduino_Pins.h"
#include "drive_control.h"

// configurable parameters
float wheelDiameter;
int motorMaxSpeed;


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
    // TODO: Set M1 and M2 motor PWM outputs to 0
}

void motorDriveForward(void)
{
    // TODO: Set M1 and M2 motor PWM outputs to drive the robot forward
}

void motorDriveBackward(void)
{   
    // TODO: Set M1 and M2 motor PWM outputs to drive the robot backward
}

void motorTurnLeft(void)
{
    // TODO: Set M1 and M2 motor PWM outputs to turn the robot left
}

void motorTurnRight(void)
{   
    // TODO: Set M1 and M2 motor PWM outputs to turn the robot right
}






