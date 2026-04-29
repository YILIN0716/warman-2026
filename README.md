# Warman Project 2026

MMA2001 Design 1 竞赛项目 — Arduino Mega 2560 + WM1 扩展板

## 功能概述

使用 HC-SR04 超声波传感器测距，根据距离控制 SG90 舵机角度：

| 距离        | 舵机角度 |
|-------------|----------|
| < 10 cm     | 0°       |
| 10 ~ 20 cm  | 90°      |
| > 20 cm     | 180°     |

## 硬件清单

| 器件               | 型号             |
|--------------------|------------------|
| 微控制器           | Arduino Mega 2560 |
| 扩展板             | WM1              |
| 超声波传感器       | HC-SR04          |
| 舵机               | SG90             |

## 引脚定义

所有引脚定义在 [include/WM1_pins.h](include/WM1_pins.h)，不在代码中硬编码数字。

| 功能            | 引脚 |
|-----------------|------|
| 超声波 TRIG     | 22   |
| 超声波 ECHO     | 23   |
| 舵机 1          | 9    |
| 舵机 2          | 10   |

## 编译与烧录

```bash
# 编译
pio run

# 编译并烧录
pio run -t upload

# 打开串口监视器（115200 baud）
pio device monitor
```

## 项目结构

```
Warman_Project_2026/
├── src/
│   └── main.cpp          # 主程序
├── include/
│   └── WM1_pins.h        # 引脚定义
├── platformio.ini         # 构建配置
└── README.md
```
