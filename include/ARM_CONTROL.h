#pragma once

// Initialisation
void armExtendRetractInit(void);
void armElevationInit(void);
void hopperSwitchInit(void);
void scoopInit(void);

// Extension arm
void armExtend(void);
void armRetract(void);

// Elevation
void elevationCollect(void);
void elevationHold(void);
void elevationStow(void);
void elevationDropoff(void);

// Hopper door
void hopperOpen(void);
void hopperClose(void);

// Scoop
void scoopCollect(void);
