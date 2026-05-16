/*
 * File:        main.cpp
 * Purpose:     Warman 2026 Main Control Program
 * Hardware:    Arduino Mega 2560 + WM1 Shield
 */


// Include necessary libraries and headers
#include <Arduino.h>
#include "drive_control.h"
#include "INPUT_SIGNAL.h"
#include "ARM_CONTROL.h"
#include "DEFINED_PINS.h"


// Configurable Parameters
static const int CFG_LOOP_DELAY_MS     = 100;
static const int CFG_COLLECTION_TARGET = 6;


// Robot State Machine
enum class RobotState {
    WAITING_FOR_START,
    GOTO_COLLECTION,
    EXECUTE_COLLECTION,
    GOTO_DROPOFF,
    EXECUTE_DROPOFF,
    GOTO_ENDZONE,
    MISSION_COMPLETE
};


// Global state variable
static RobotState global_robotState = RobotState::WAITING_FOR_START;


// Main setup and loop functions
void setup()
{
    motorInit();
    sensorInit();
    armExtendRetractInit();
    armElevationInit();
    hopperSwitchInit();
    scoopInit();
}


// Main control loop
void loop()
{
    // Sense inputs
    int ultrasonicDistance = readUltrasonicDist();

    // State machine
    switch (global_robotState)
    {
        case RobotState::WAITING_FOR_START:
            if (readStartButton())
                global_robotState = RobotState::GOTO_COLLECTION;
            break;

        case RobotState::GOTO_COLLECTION:

            {
                motorStop();
                global_robotState = RobotState::EXECUTE_COLLECTION;
            }
            break;

        case RobotState::EXECUTE_COLLECTION:
        // TODO: Implement collection logic using arm and hopper control functions, and transition to next state when collection is complete

            break;

        case RobotState::GOTO_DROPOFF:
            {
                motorStop();
                global_robotState = RobotState::EXECUTE_DROPOFF;
            }
            break;

        case RobotState::EXECUTE_DROPOFF:
            global_robotState = RobotState::MISSION_COMPLETE;
            break;

        case RobotState::MISSION_COMPLETE:
        // set led to indicate completion, stop all motors, and halt program
            motorStop();
            digitalWrite(LED_PIN, HIGH);  // Turn on completion LED
            while (true) {}
            break;
    }

    delay(CFG_LOOP_DELAY_MS);
}
