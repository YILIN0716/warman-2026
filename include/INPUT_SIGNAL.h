#pragma once        // Header guard to prevent multiple inclusions

// Initialisation
void inputSignalInit(void);

// Sensor reading
int readUltrasonicDist(void);

// Button detection
bool readStartButton(void);
