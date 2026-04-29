/*******************************************************************************
 * 文件：  test_ultrasonic_servo.cpp
 * 功能：  HC-SR04 超声波测距 + SG90 舵机联动硬件测试
 * 硬件：  Arduino Mega 2560 + WM1 扩展板
 * 逻辑：  距离 < 10cm  → 舵机转到   0°
 *         距离 10~20cm → 舵机转到  90°
 *         距离 > 20cm  → 舵机转到 180°
 * 使用：  如需单独测试硬件，将本文件复制到 src/ 并移除 main.cpp
 ******************************************************************************/

#include <Arduino.h>
#include <Servo.h>
#include "WM1_pins.h"


/* ============================================================
 *  可配置参数
 * ============================================================ */
static const long  CFG_PULSE_TIMEOUT_US = 30000;  // 超声波超时（us）
static const int   CFG_LOOP_DELAY_MS    = 100;    // 主循环刷新率（ms）

static const float CFG_DIST_NEAR_CM     = 10.0f;
static const float CFG_DIST_MID_CM      = 20.0f;

static const int   CFG_SERVO_NEAR_DEG   = 0;
static const int   CFG_SERVO_MID_DEG    = 90;
static const int   CFG_SERVO_FAR_DEG    = 180;


/* ============================================================
 *  舵机对象
 * ============================================================ */
static Servo g_servo;


/* ============================================================
 *  函数声明
 * ============================================================ */
void  ultrasonicInit(void);
float ultrasonicGetDistance(void);
int   selectServoAngle(float distanceCm);
void  servoInit(void);
void  servoSetAngle(int targetAngleDeg);


/* ============================================================
 *  setup
 * ============================================================ */
void setup()
{
    Serial.begin(115200);
    ultrasonicInit();
    servoInit();
    Serial.println("Ultrasonic + Servo Test Starting...");
}


/* ============================================================
 *  loop：感知 → 决策 → 执行
 * ============================================================ */
void loop()
{
    float distanceCm     = ultrasonicGetDistance();
    int   targetAngleDeg = selectServoAngle(distanceCm);

    Serial.print("Distance: ");
    Serial.print(distanceCm);
    Serial.println(" cm");

    servoSetAngle(targetAngleDeg);
    delay(CFG_LOOP_DELAY_MS);
}


/* ============================================================
 *  超声波初始化
 * ============================================================ */
void ultrasonicInit(void)
{
    pinMode(TRIG_PIN, OUTPUT);
    pinMode(ECHO_PIN, INPUT);
    digitalWrite(TRIG_PIN, LOW);
}


/* ============================================================
 *  单次超声波测距
 *  返回值：距离（cm），超时返回 999.0f 视为无障碍
 * ============================================================ */
float ultrasonicGetDistance(void)
{
    digitalWrite(TRIG_PIN, LOW);
    delayMicroseconds(2);
    digitalWrite(TRIG_PIN, HIGH);
    delayMicroseconds(10);
    digitalWrite(TRIG_PIN, LOW);

    long echoDurationUs = pulseIn(ECHO_PIN, HIGH, CFG_PULSE_TIMEOUT_US);
    if (echoDurationUs == 0) return 999.0f;

    return (echoDurationUs * 0.0343f) / 2.0f;
}


/* ============================================================
 *  根据距离决定舵机角度
 * ============================================================ */
int selectServoAngle(float distanceCm)
{
    if (distanceCm < CFG_DIST_NEAR_CM) return CFG_SERVO_NEAR_DEG;
    if (distanceCm < CFG_DIST_MID_CM)  return CFG_SERVO_MID_DEG;
    return CFG_SERVO_FAR_DEG;
}


/* ============================================================
 *  舵机初始化：绑定引脚并归位到 90°
 * ============================================================ */
void servoInit(void)
{
    g_servo.attach(SERVO1);
    g_servo.write(CFG_SERVO_MID_DEG);
    delay(500);
}


/* ============================================================
 *  舵机设置角度
 *  targetAngleDeg：目标角度，有效范围 0~180°
 * ============================================================ */
void servoSetAngle(int targetAngleDeg)
{
    g_servo.write(targetAngleDeg);
}
