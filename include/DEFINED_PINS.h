/*
 * file：      WM1_pins.h
 * function：  WM1 + Arduino Mega 2560 
 */

#pragma once        // Header guard to prevent multiple inclusions


// ultrasonic sensor pins
#define TRIG_PIN    22
#define ECHO_PIN    23


// servo pins
#define SERVO1      9
#define SERVO2      10


// motor pins
#define M1_PWM      6       // left wheel
#define M1_DIR      7   
#define M2_PWM      3       // right wheel
#define M2_DIR      8
#define M3_PWM      5
#define M3_DIR      12
#define M4_PWM      11
#define M4_DIR      13


// relay pins
#define RELAY1      2
#define RELAY2      4


// button pin
#define BTN_START    24

// led pin
#define LED_PIN      25