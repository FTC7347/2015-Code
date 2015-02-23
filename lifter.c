#pragma config(Hubs,  S1, HTMotor,  HTMotor,  HTMotor,  HTMotor)
#pragma config(Hubs,  S2, HTServo,  none,     none,     none)
#pragma config(Sensor, S1,     ,               sensorI2CMuxController)
#pragma config(Sensor, S2,     ,               sensorI2CMuxController)
#pragma config(Motor,  mtr_S1_C1_1,     left2,         tmotorTetrix, PIDControl, reversed, encoder)
#pragma config(Motor,  mtr_S1_C1_2,     lifter,        tmotorTetrix, openLoop)
#pragma config(Motor,  mtr_S1_C2_1,     left,          tmotorTetrix, PIDControl, reversed, encoder)
#pragma config(Motor,  mtr_S1_C2_2,     intake,        tmotorTetrix, openLoop)
#pragma config(Motor,  mtr_S1_C3_1,     launcher,      tmotorTetrix, openLoop)
#pragma config(Motor,  mtr_S1_C3_2,     right,         tmotorTetrix, PIDControl, encoder)
#pragma config(Motor,  mtr_S1_C4_1,     right2,        tmotorTetrix, PIDControl, encoder)
#pragma config(Motor,  mtr_S1_C4_2,     motorK,        tmotorTetrix, openLoop)
#pragma config(Servo,  srvo_S2_C1_1,    servo1,               tServoNone)
#pragma config(Servo,  srvo_S2_C1_2,    servo2,               tServoNone)
#pragma config(Servo,  srvo_S2_C1_3,    servo3,               tServoNone)
#pragma config(Servo,  srvo_S2_C1_4,    servo4,               tServoNone)
#pragma config(Servo,  srvo_S2_C1_5,    servo5,               tServoNone)
#pragma config(Servo,  srvo_S2_C1_6,    servo6,               tServoNone)


#include "JoystickDriver.c"
void initializeRobot()
{

	return;
}
task main()
{
	initializeRobot();



	while(true){
		if(nNxtButtonPressed == 1){
			motor[lifter] = 100;
			}else if (nNxtButtonPressed == 2){
			motor[lifter] = -100;
			}else{
			motor[lifter] = 0;

		}
	}
}
