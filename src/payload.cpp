/*
 * File:        payload.cpp
 * Purpose:     control extension arm
 *              control angle of elevation of extension arm
 *              control hopper door for payload collection and dropoff
 * 
 * 
 *  and mechanism control for collection and dropoff
 */

#include <Arduino.h>
#include <Servo.h>
#include "WM1_pins.h"
#include "payload.h"


static const int CFG_SERVO_STOW_DEG = 0;
static Servo g_servo;


// initialization
void servoInit(void)
{
    // TODO: Attach servo and move to stow position (CFG_SERVO_STOW_DEG)
}

void collectPayload(void)
{
    // TODO: Execute collection action, increment collected count on success
}

void dropPayload(void)
{
    // TODO: Execute payload deposit action
}

void exitDropoffOrShutdown(void)
{
    // TODO: Retreat from dropoff zone or power down in place
}
