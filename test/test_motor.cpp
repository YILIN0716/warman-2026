/*******************************************************************************
 * 文件：  test_motor.cpp
 * 功能：  WM1 电机驱动测试 — M1 正反转速度斜坡
 * 硬件：  标准有刷直流减速电机接至 WM1 M1 输出口
 * 说明：  电机速度从 0 升至最大再降回 0，方向交替切换
 * 使用：  如需单独测试硬件，将本文件复制到 src/ 并移除 main.cpp
 ******************************************************************************/

#include <Arduino.h>
#include "WM1_pins.h"


/* ============================================================
 *  全局变量
 * ============================================================ */
static int g_motorDuty = 0;  // PWM 占空比（0~255）


/* ============================================================
 *  setup
 * ============================================================ */
void setup()
{
    // 使用的引脚
    pinMode(M1_PWM, OUTPUT);
    pinMode(M1_DIR, OUTPUT);

    // 未使用引脚设为输出，避免浮空
    pinMode(M2_PWM, OUTPUT);
    pinMode(M2_DIR, OUTPUT);
    pinMode(M3_PWM, OUTPUT);
    pinMode(M3_DIR, OUTPUT);
    pinMode(M4_PWM, OUTPUT);
    pinMode(M4_DIR, OUTPUT);
    pinMode(RELAY1,  OUTPUT);
    pinMode(RELAY2,  OUTPUT);
    pinMode(SERVO1,  OUTPUT);
    pinMode(SERVO2,  OUTPUT);
}


/* ============================================================
 *  loop：正转斜坡 → 反转斜坡
 * ============================================================ */
void loop()
{
    // 正转
    digitalWrite(M1_DIR, HIGH);
    for (g_motorDuty = 0;   g_motorDuty <= 255; g_motorDuty++) { analogWrite(M1_PWM, g_motorDuty); delay(4); }
    for (g_motorDuty = 255; g_motorDuty >= 0;   g_motorDuty--) { analogWrite(M1_PWM, g_motorDuty); delay(4); }

    // 反转
    digitalWrite(M1_DIR, LOW);
    for (g_motorDuty = 0;   g_motorDuty <= 255; g_motorDuty++) { analogWrite(M1_PWM, g_motorDuty); delay(4); }
    for (g_motorDuty = 255; g_motorDuty >= 0;   g_motorDuty--) { analogWrite(M1_PWM, g_motorDuty); delay(4); }
}
