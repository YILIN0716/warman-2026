#pragma once

// Initialisation
void servoInit(void);

// Extension arm
void armExtend(void);
void armRetract(void);

// Elevation
void elevationCollect(void);
void elevationDrop(void);
void elevationStow(void);

// Hopper door
void hopperOpen(void);
void hopperClose(void);

// Scoop
void scoopCollect(void);
void scoopStow(void);

// High-level actions
void collectPayload(void);
void dropPayload(void);
void exitDropoffOrShutdown(void);
