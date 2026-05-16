/*
 * File:        input_signals.cpp
 * Purpose:     start button detection, ultrasonic reading
 */


#include <Arduino.h>
#include "DEFINED_PINS.h"
#include "INPUT_SIGNAL.h"


// initialization
void sensorInit(void)
{
    // Initialise ultrasonic pins
    pinMode(TRIG_PIN, OUTPUT);
    pinMode(ECHO_PIN, INPUT);
}


// read input signals — returns true on a confirmed button press (active LOW with pull-up)
bool readStartButton(void)
{
    // TODO： Read start button, only exit function when a valid button press is detected
    
}


int readUltrasonicDist(void)
{
    // TODO: Read ultrasonic sensor and return distance in cm
    return 0;
}