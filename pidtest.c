#pragma config(Hubs,  S1, HTMotor,  HTMotor,  HTMotor,  HTMotor)
#pragma config(Hubs,  S2, HTServo,  none,     none,     none)
#pragma config(Sensor, S1,     ,               sensorI2CMuxController)
#pragma config(Sensor, S2,     ,               sensorI2CMuxController)
#pragma config(Motor,  mtr_S1_C1_1,     left,          tmotorTetrix, openLoop, reversed)
#pragma config(Motor,  mtr_S1_C1_2,     llauncher,     tmotorTetrix, openLoop)
#pragma config(Motor,  mtr_S1_C2_1,     left2,         tmotorTetrix, openLoop, reversed)
#pragma config(Motor,  mtr_S1_C2_2,     lifter,        tmotorTetrix, openLoop)
#pragma config(Motor,  mtr_S1_C3_1,     rlauncher,     tmotorTetrix, openLoop)
#pragma config(Motor,  mtr_S1_C3_2,     right,         tmotorTetrix, openLoop)
#pragma config(Motor,  mtr_S1_C4_1,     right2,        tmotorTetrix, openLoop)
#pragma config(Motor,  mtr_S1_C4_2,     intake,        tmotorTetrix, openLoop)
#pragma config(Servo,  srvo_S2_C1_1,    grabber,              tServoStandard)
#pragma config(Servo,  srvo_S2_C1_2,    opener,               tServoStandard)
#pragma config(Servo,  srvo_S2_C1_3,    servo3,               tServoNone)
#pragma config(Servo,  srvo_S2_C1_4,    servo4,               tServoNone)
#pragma config(Servo,  srvo_S2_C1_5,    servo5,               tServoNone)
#pragma config(Servo,  srvo_S2_C1_6,    servo6,               tServoNone)
#include "PID.h"
task main()
{



}
