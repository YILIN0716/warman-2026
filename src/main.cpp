/*
 * File:        main.cpp
 * Purpose:     Warman 2026 Main Control Program
 * Hardware:    Arduino Mega 2560 + WM1 Shield
 */

#include <Arduino.h>
#include <Servo.h>
#include "WM1_pins.h"



// Configurable Parameters (CFG)
static const int   CFG_LOOP_DELAY_MS     = 100;  // Main loop refresh rate (ms)
static const int   CFG_SERVO_STOW_DEG    = 0;    // Initial stow angle (must fit within 400x400x400mm size limit)
static const int   CFG_COLLECTION_TARGET = 3;    // Target number of rocks to collect


// Robot State Machine
enum class RobotState {
    WAITING_FOR_START,
    GOTO_COLLECTION,
    EXECUTE_COLLECTION,
    GOTO_DROPOFF,
    EXECUTE_DROPOFF,
    MISSION_COMPLETE
};


// Global Variables
static RobotState global_robotState      = RobotState::WAITING_FOR_START;
static int        global_collectedCount  = 0;
static Servo      global_servo;
static int        global_serialBaudRate  = 115200;


// Function Declarations
// Initialisation
void motorInit(void);
void sensorInit(void);
void sensorCalibrate(void);
void servoInit(void);
void motorStop(void);

// Sensor reading
void readLineSensors(void);
void readEncoderDistance(void);

// State machine actions
bool isStartButtonPressed(void);
void runLineFollowPID(void);
void driveOdometryStraight(void);
bool isAtCollectionZone(void);
void collectPayload(void);
void runNavigationWithObstacle(void);
bool isAtDropoffZone(void);
void dropPayload(void);
void exitDropoffOrShutdown(void);

// Servo
void servoSetAngle(int targetAngleDeg);



// setup
void setup()
{
    Serial.begin(global_serialBaudRate);

    motorInit();
    sensorInit();
    servoInit();
    motorStop();
    sensorCalibrate();

    Serial.println("Warman 2026 Ready.");
}

/*
    main loop: main robot algorithm
    pesudo-code outline: 
    


*/
 
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
            if (global_collectedCount == CFG_COLLECTION_TARGET)
                global_robotState = RobotState::GOTO_DROPOFF;
            break;

        case RobotState::GOTO_DROPOFF:
            runNavigationWithObstacle();  // Includes special terrain handling (e.g. ramp)
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
            while (true) {}  // Mission complete — halt all operations
            break;
    }

    delay(CFG_LOOP_DELAY_MS);
}



// Function Definitions
void motorInit(void)
{
    // TODO: Set M1~M4 PWM and DIR pins to OUTPUT mode
}

void sensorInit(void)
{
    // TODO: Initialise line tracking sensors, encoders, and ultrasonic pins
}

void sensorCalibrate(void)
{
    // TODO: Calibrate sensor baseline values if required
}

void servoInit(void)
{
    global_servo.attach(SERVO1);
    global_servo.write(CFG_SERVO_STOW_DEG);  // Move servo to initial stow position
    delay(500);
}

void motorStop(void)
{
    // TODO: Set all motor PWM outputs to 0
}



// Sensor Reading
void readLineSensors(void)
{
    // TODO: Read line tracking sensors and update global sensor data
}

void readEncoderDistance(void)
{
    // TODO: Read encoder pulses and update odometry data
}



// State Machine Actions
bool isStartButtonPressed(void)
{
    // TODO: Detect start button press
    return false;
}

void runLineFollowPID(void)
{
    // TODO: PID line following control, output differential drive signals
}

void driveOdometryStraight(void)
{
    // TODO: Drive straight using odometry
}

bool isAtCollectionZone(void)
{
    // TODO: Detect whether the robot has reached the collection zone (marker line or preset distance)
    return false;
}

void collectPayload(void)
{
    // TODO: Execute collection action, increment global_collectedCount on success
}

void runNavigationWithObstacle(void)
{
    // TODO: Navigate to dropoff zone, handle special terrain such as the ramp
}

bool isAtDropoffZone(void)
{
    // TODO: Detect whether the robot has reached the dropoff target position
    return false;
}

void dropPayload(void)
{
    // TODO: Execute payload deposit action
}

void exitDropoffOrShutdown(void)
{
    // TODO: Retreat from dropoff zone or power down in place
}



 // Servo Control
void servoSetAngle(int targetAngleDeg)
{
    global_servo.write(targetAngleDeg);
}