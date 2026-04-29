/*******************************************************************************
 * 文件：  main.cpp
 * 功能：  Warman 2026 主控程序
 * 硬件：  Arduino Mega 2560 + WM1 扩展板
 ******************************************************************************/

#include <Arduino.h>
#include <Servo.h>
#include "WM1_pins.h"


/* ============================================================
 *  可配置参数
 * ============================================================ */
static const int   CFG_LOOP_DELAY_MS     = 100;  // 主循环刷新率（ms）
static const int   CFG_SERVO_STOW_DEG    = 0;    // 初始收起角度（符合 400x400x400mm 尺寸限制）
static const int   CFG_COLLECTION_TARGET = 3;    // 目标收集物资数量


/* ============================================================
 *  机器人状态机
 * ============================================================ */
enum class RobotState {
    WAITING_FOR_START,
    GOTO_COLLECTION,
    EXECUTE_COLLECTION,
    GOTO_DROPOFF,
    EXECUTE_DROPOFF,
    MISSION_COMPLETE
};

static RobotState g_robotState     = RobotState::WAITING_FOR_START;
static int        g_collectedCount = 0;


/* ============================================================
 *  舵机对象
 * ============================================================ */
static Servo g_servo;


/* ============================================================
 *  函数声明
 * ============================================================ */
// 初始化
void motorInit(void);
void sensorInit(void);
void sensorCalibrate(void);
void servoInit(void);
void motorStop(void);

// 传感器读取
void readLineSensors(void);
void readEncoderDistance(void);

// 状态机动作
bool isStartButtonPressed(void);
void runLineFollowPID(void);
void driveOdometryStraight(void);
bool isAtCollectionZone(void);
void collectPayload(void);
void runNavigationWithObstacle(void);
bool isAtDropoffZone(void);
void dropPayload(void);
void exitDropoffOrShutdown(void);

// 舵机
void servoSetAngle(int targetAngleDeg);


/* ============================================================
 *  setup
 * ============================================================ */
void setup()
{
    Serial.begin(115200);

    motorInit();
    sensorInit();
    servoInit();
    motorStop();
    sensorCalibrate();

    Serial.println("Warman 2026 Ready.");
}


/* ============================================================
 *  loop：感知 → 决策（状态机）→ 执行
 * ============================================================ */
void loop()
{
    // 感知
    readLineSensors();
    readEncoderDistance();

    // 状态机
    switch (g_robotState)
    {
        case RobotState::WAITING_FOR_START:
            if (isStartButtonPressed())
                g_robotState = RobotState::GOTO_COLLECTION;
            break;

        case RobotState::GOTO_COLLECTION:
            runLineFollowPID();
            if (isAtCollectionZone())
            {
                motorStop();
                g_robotState = RobotState::EXECUTE_COLLECTION;
            }
            break;

        case RobotState::EXECUTE_COLLECTION:
            collectPayload();
            if (g_collectedCount == CFG_COLLECTION_TARGET)
                g_robotState = RobotState::GOTO_DROPOFF;
            break;

        case RobotState::GOTO_DROPOFF:
            runNavigationWithObstacle();  // 含跷跷板等特殊地形处理
            if (isAtDropoffZone())
            {
                motorStop();
                g_robotState = RobotState::EXECUTE_DROPOFF;
            }
            break;

        case RobotState::EXECUTE_DROPOFF:
            dropPayload();
            g_robotState = RobotState::MISSION_COMPLETE;
            break;

        case RobotState::MISSION_COMPLETE:
            exitDropoffOrShutdown();
            motorStop();
            while (true) {}  // 比赛结束，停止一切动作
            break;
    }

    delay(CFG_LOOP_DELAY_MS);
}


/* ============================================================
 *  初始化
 * ============================================================ */
void motorInit(void)
{
    // TODO: 设置 M1~M4 PWM 和 DIR 引脚为输出模式
}

void sensorInit(void)
{
    // TODO: 初始化循迹传感器、编码器、超声波引脚
}

void sensorCalibrate(void)
{
    // TODO: 如有需要，在此校准传感器基准值
}

void servoInit(void)
{
    g_servo.attach(SERVO1);
    g_servo.write(CFG_SERVO_STOW_DEG);  // 收起到初始位置
    delay(500);
}

void motorStop(void)
{
    // TODO: 将所有电机 PWM 置 0
}


/* ============================================================
 *  传感器读取
 * ============================================================ */
void readLineSensors(void)
{
    // TODO: 读取循迹传感器，更新全局传感器数据
}

void readEncoderDistance(void)
{
    // TODO: 读取编码器脉冲，更新里程计数据
}


/* ============================================================
 *  状态机动作
 * ============================================================ */
bool isStartButtonPressed(void)
{
    // TODO: 检测启动按钮
    return false;
}

void runLineFollowPID(void)
{
    // TODO: PID 循迹控制，输出差速驱动
}

void driveOdometryStraight(void)
{
    // TODO: 里程计直线行驶
}

bool isAtCollectionZone(void)
{
    // TODO: 检测是否到达收集区（标记线或预定距离）
    return false;
}

void collectPayload(void)
{
    // TODO: 执行收集动作，完成后 g_collectedCount++
}

void runNavigationWithObstacle(void)
{
    // TODO: 导航前往投放区，处理跷跷板等特殊地形
}

bool isAtDropoffZone(void)
{
    // TODO: 检测是否到达投放区目标位置
    return false;
}

void dropPayload(void)
{
    // TODO: 执行投放动作
}

void exitDropoffOrShutdown(void)
{
    // TODO: 撤离投放区或原地断电
}


/* ============================================================
 *  舵机控制
 * ============================================================ */
void servoSetAngle(int targetAngleDeg)
{
    g_servo.write(targetAngleDeg);
}
