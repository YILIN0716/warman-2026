#pragma once

// Initialisation
void sensorInit(void);
void sensorCalibrate(void);

// Sensor reading
void readLineSensors(void);
void readEncoderDistance(void);

// Button detection
bool isStartButtonPressed(void);
