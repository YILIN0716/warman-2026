/*
 * File:        input_signals.cpp
 * Purpose:     start button detection, ultrasonic reading
 */


#include <Arduino.h>
#include "WM1_pins.h"
#include "input_signals.h"


// initialization
void sensorInit(void)
{
    // TODO: Initialise line tracking sensors, encoders, and ultrasonic pins
}


// read input signals
bool readStartButton(void)
{
    // TODO: Detect start button press
    return false;
}


int readUltrasonicDistance(void)
{
    // TODO: Read ultrasonic sensor and return distance in cm
    return 0;
}