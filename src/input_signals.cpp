/*
 * File:        input_signals.cpp
 * Purpose:     start button detection, ultrasonic reading
 */


#include <Arduino.h>
#include "DEFINED_PINS.h"
#include "INPUT_SIGNAL.h"


// configurable parameters
static const int DEBOUNCE_DELAY_MS = 20;


// initialization
void inputSignalInit(void)
{
    // Initialise start button pin with pull-up resistor
    pinMode(BTN_START, INPUT_PULLUP);
}

// Read start button, only exit function when a valid button press is detected
bool readStartButton(void)
{
    while(1) {
        // wait for button press, press = LOW
        while(digitalRead(BTN_START) == HIGH)
        {
            delay(10);
        }
        // debounce
        delay(DEBOUNCE_DELAY_MS);
        if(digitalRead(BTN_START) == LOW) {
            return true;
        }
    }  
}


