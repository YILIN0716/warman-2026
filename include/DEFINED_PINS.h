#pragma once        // Header guard to prevent multiple inclusions

// ultrasonic sensor pins
#define TRIG_PIN    22
#define ECHO_PIN    23


// servo pins
#define SERVO1      9
#define SERVO2      10


// motor pins correct
//#define M1_PWM      6       // left wheel
//#define M1_DIR      7   
//#define M2_PWM      3       // right wheel
//#define M2_DIR      8
//#define M3_PWM      5
//#define M3_DIR      12
//#define M4_PWM      11
//#define M4_DIR      13

// motor pins
#define M1_PWM        5     // left wheel
#define M1_DIR         12
#define M2_PWM         11    // right wheel
#define M2_DIR      13
#define M3_PWM      6
#define M3_DIR      7
#define M4_PWM      3
#define M4_DIR      8







// relay pins
#define RELAY1      2
#define RELAY2      4


// button pin
#define BTN_START    25      // pin25 -> button -> GND

// led pin
#define LED_PIN      24      // pin24 -> Resistor 220Ω -> LED -> GND