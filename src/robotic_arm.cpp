/*===========================================================================================================
 * File:        robotic_arm.cpp
 * Purpose:     control extension arm   - 6V DC motor - M3
 *              control angle of elevation - servo     - SERVO1
 *              control hopper door        - servo     - SERVO2
 *              control up and down of scoop - 6V DC motor - M4
 * ==================================================================================================================
 */

#include <Arduino.h>
#include <Servo.h>
#include "WM1_pins.h"
#include "robotic_arm.h"


// == Configurable Parameters ===============================================================

// Extension arm — time-based (6V DC motor, 80% PWM to prevent overvoltage)
static const int CFG_ARM_EXTEND_TIME  = 3000;   // pre-determined extension time
static const int CFG_ARM_RETRACT_TIME = 3000;   // pre-determined retraction time
static const int CFG_ARM_PWM          = 204;    // 80% of 255 to prevent overvoltage

// Elevation — angle-based (servo)
static const int CFG_ELEV_STOW_DEG    = 0;      // stow position is flat
static const int CFG_ELEV_COLLECT_DEG = 15;     // collection position
static const int CFG_ELEV_HOLD_DEG    = 90;     // holding position

// Hopper door — angle-based (servo)
static const int CFG_HOPPER_CLOSED_DEG = 0;     // idle state
static const int CFG_HOPPER_OPEN_DEG   = 180;   // open state

// Scoop — time-based (6V DC motor, 80% PWM to prevent overvoltage)
static const int CFG_SCOOP_OPERATE_TIME = 10000;    // pre determined, should depend on retract of arm

// Timing
static const int CFG_SERVO_SETTLE_TIME = 500;


// == Servo Objects ===================================================================

static Servo g_servoElevation;      // SERVO1 (pin 9)
static Servo g_servoHopper;         // SERVO2 (pin 10)


// == Initialisation ========================================================
void armExtendRetractInit(void)
{
    pinMode(M3_PWM, OUTPUT);
    pinMode(M3_DIR, OUTPUT);
}

void armElevationInit(void)
{
    g_servoElevation.attach(SERVO1);   
    g_servoElevation.write(CFG_ELEV_STOW_DEG);
    delay(CFG_SERVO_SETTLE_TIME);
}

void hopperSwitchInit(void)
{
    g_servoHopper.attach(SERVO2);    
    g_servoHopper.write(CFG_HOPPER_CLOSED_DEG);
    delay(CFG_SERVO_SETTLE_TIME);
}

void scoopInit(void)
{
    pinMode(M4_PWM, OUTPUT);
    pinMode(M4_DIR, OUTPUT);
}


// == Extension Arm =================================================================
// DIR=HIGH drives arm outward
void armExtend(void)
{
    digitalWrite(M3_DIR, HIGH);
    analogWrite(M3_PWM, CFG_ARM_PWM);
    delay(CFG_ARM_EXTEND_TIME);
    analogWrite(M3_PWM, 0);
}

void armRetract(void)
{
    digitalWrite(M3_DIR, LOW);
    analogWrite(M3_PWM, CFG_ARM_PWM);
    delay(CFG_ARM_RETRACT_TIME);
    analogWrite(M3_PWM, 0);
}


// == Elevation Arm =================================================================

void elevationCollect(void)
{
    g_servoElevation.write(CFG_ELEV_COLLECT_DEG);
    delay(CFG_SERVO_SETTLE_TIME);
}

void elevationHold(void)
{
    g_servoElevation.write(CFG_ELEV_HOLD_DEG);
    delay(CFG_SERVO_SETTLE_TIME);
}

void elevationStow(void)
{
    g_servoElevation.write(CFG_ELEV_STOW_DEG);
    delay(CFG_SERVO_SETTLE_TIME);
}


// == Hopper Door =================================================================

void hopperOpen(void)
{
    g_servoHopper.write(CFG_HOPPER_OPEN_DEG);
    delay(CFG_SERVO_SETTLE_TIME);
}

void hopperClose(void)
{
    g_servoHopper.write(CFG_HOPPER_CLOSED_DEG);
    delay(CFG_SERVO_SETTLE_TIME);
}


// == Scoop =================================================================

void scoopCollect(void)
{
    // TODO: Set M4 motor PWM outputs to operate the scoop for collection
}


