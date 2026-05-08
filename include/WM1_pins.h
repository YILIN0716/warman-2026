/*
 * file：  WM1_pins.h
 * function：  WM1 扩展板 + Arduino Mega 2560 全部引脚定义
 * clarification：  所有硬件引脚只在此文件定义，其他文件只引用，不硬编码数字
 */

#pragma once        // Header guard to prevent multiple inclusions


// ultrasonic sensor pins
#define TRIG_PIN    22
#define ECHO_PIN    23


// servo pins
#define SERVO1      9
#define SERVO2      10


// motor pins
#define M1_PWM      6
#define M1_DIR      7
#define M2_PWM      3
#define M2_DIR      8
#define M3_PWM      5
#define M3_DIR      12
#define M4_PWM      11
#define M4_DIR      13


// relay pins
#define RELAY1      2
#define RELAY2      4