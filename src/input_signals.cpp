/*
 * File:        input_signals.cpp
 * Purpose:     start button detection, ultrasonic reading
 */


#include <Arduino.h>
#include "Arduino_Pins.h"
#include "input_signals.h"


// initialization
void sensorInit(void)
{
    pinMode(BTN_START, INPUT_PULLUP);
    // TODO: Initialise line tracking sensors, encoders, and ultrasonic pins
}


// read input signals — returns true on a confirmed button press (active LOW with pull-up)
bool readStartButton(void)
{
    if (digitalRead(BTN_START) == HIGH)
        return false;

    delay(20);  // debounce
    return (digitalRead(BTN_START) == LOW);
}


int readUltrasonicDist(void)
{
    // TODO: Read ultrasonic sensor and return distance in cm
    return 0;
}