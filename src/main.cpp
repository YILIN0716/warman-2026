/*
 * File:        main.cpp
 * Purpose:     Warman 2026 Main Control Program
 * Hardware:    Arduino Mega 2560 + WM1 Shield
 */


// Include necessary libraries and headers
#include <Arduino.h>
#include "drive_control.h"
#include "input_signals.h"
#include "robotic_arm.h"


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
    sensorCalibrate();
    armExtendRetractInit();
    armElevationInit();
    hopperSwitchInit();
    scoopInit();
    motorStop();

    Serial.println("Warman 2026 Ready.");
}


// Main control loop
void loop()
{
    // Sense
    readLineSensors();
    readEncoderDistance();

    // State machine
    switch (global_robotState)
    {
        case RobotState::WAITING_FOR_START:
            if (isStartButtonPressed())
                global_robotState = RobotState::GOTO_COLLECTION;
            break;

        case RobotState::GOTO_COLLECTION:
            runLineFollowPID();
            if (isAtCollectionZone())
            {
                motorStop();
                global_robotState = RobotState::EXECUTE_COLLECTION;
            }
            break;

        case RobotState::EXECUTE_COLLECTION:
            collectPayload();
            break;

        case RobotState::GOTO_DROPOFF:
            runNavigationWithObstacle();
            if (isAtDropoffZone())
            {
                motorStop();
                global_robotState = RobotState::EXECUTE_DROPOFF;
            }
            break;

        case RobotState::EXECUTE_DROPOFF:
            dropPayload();
            global_robotState = RobotState::MISSION_COMPLETE;
            break;

        case RobotState::MISSION_COMPLETE:
            exitDropoffOrShutdown();
            motorStop();
            while (true) {}
            break;
    }

    delay(CFG_LOOP_DELAY_MS);
}
