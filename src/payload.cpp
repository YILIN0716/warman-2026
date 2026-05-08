/*
 * File:        payload.cpp
 * Purpose:     control extension arm
 *              control angle of elevation of extension arm
 *              control hopper door
 *              control angle of scoop
 */

#include <Arduino.h>
#include <Servo.h>
#include "WM1_pins.h"
#include "payload.h"


// Configurable Parameters

// Extension arm
static const int CFG_ARM_STOW_DEG   = 0;
static const int CFG_ARM_EXTEND_DEG = 0;

// Elevation
static const int CFG_ELEV_STOW_DEG    = 0;
static const int CFG_ELEV_COLLECT_DEG = 0;
static const int CFG_ELEV_DROP_DEG    = 0;

// Hopper door
static const int CFG_HOPPER_CLOSED_DEG = 0;
static const int CFG_HOPPER_OPEN_DEG   = 0;

// Scoop
static const int CFG_SCOOP_STOW_DEG    = 0;
static const int CFG_SCOOP_COLLECT_DEG = 0;

// Timing
static const int CFG_SERVO_SETTLE_MS = 500;  // Time for servo to reach position


// Servo Objects
static Servo g_servoArm;       // Extension arm       → TODO: assign pin in WM1_pins.h
static Servo g_servoElevation; // Elevation angle     → TODO: assign pin in WM1_pins.h
static Servo g_servoHopper;    // Hopper door         → TODO: assign pin in WM1_pins.h
static Servo g_servoScoop;     // Scoop angle         → TODO: assign pin in WM1_pins.h


// Initialization

void servoInit(void)
{
    // TODO: Attach each servo to its pin and move to stow position
    // g_servoArm.attach(ARM_PIN);         g_servoArm.write(CFG_ARM_STOW_DEG);
    // g_servoElevation.attach(ELEV_PIN);  g_servoElevation.write(CFG_ELEV_STOW_DEG);
    // g_servoHopper.attach(HOPPER_PIN);   g_servoHopper.write(CFG_HOPPER_CLOSED_DEG);
    // g_servoScoop.attach(SCOOP_PIN);     g_servoScoop.write(CFG_SCOOP_STOW_DEG);
    delay(CFG_SERVO_SETTLE_MS);
}


// Extension Arm

void armExtend(void)
{
    // TODO: Drive arm to extended position
}

void armRetract(void)
{
    // TODO: Drive arm back to stow position
}


// Elevation

void elevationCollect(void)
{
    // TODO: Set elevation to collection angle
}

void elevationDrop(void)
{
    // TODO: Set elevation to dropoff angle
}

void elevationStow(void)
{
    // TODO: Return elevation to stow angle
}


// Hopper Door 

void hopperOpen(void)
{
    // TODO: Open hopper door
}

void hopperClose(void)
{
    // TODO: Close hopper door
}


// Scoop 

void scoopCollect(void)
{
    // TODO: Set scoop to collection angle
}

void scoopStow(void)
{
    // TODO: Return scoop to stow angle
}


// High-Level Actions， sequences of movements for collection and dropoff
void collectPayload(void)
{
    // TODO: Sequence — extend arm, set elevation, scoop, close hopper, retract
}

void dropPayload(void)
{
    // TODO: Sequence — set elevation to drop, open hopper, wait, close hopper
}

void exitDropoffOrShutdown(void)
{
    // TODO: Stow all mechanisms before halt
}
