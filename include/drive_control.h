#pragma once            // Header guard to prevent multiple inclusions

// Motor
void motorInit(void);
void motorStop(void);

// Navigation
bool isAtCollectionZone(void);
bool isAtDropoffZone(void);
void runLineFollowPID(void);
void driveOdometryStraight(void);
void runNavigationWithObstacle(void);
