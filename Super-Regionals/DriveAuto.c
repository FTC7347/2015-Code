#pragma config(Hubs,  S1, HTMotor,  HTMotor,  HTMotor,  HTMotor)
#pragma config(Hubs,  S2, HTServo,  none,     none,     none)
#pragma config(Sensor, S3,     compass,        sensorI2CCustom)
#pragma config(Motor,  mtr_S1_C1_1,     left,          tmotorTetrix, openLoop, reversed)
#pragma config(Motor,  mtr_S1_C1_2,     intake,        tmotorTetrix, openLoop)
#pragma config(Motor,  mtr_S1_C2_1,     left2,         tmotorTetrix, openLoop, encoder)
#pragma config(Motor,  mtr_S1_C2_2,     llifter,       tmotorTetrix, openLoop)
#pragma config(Motor,  mtr_S1_C3_1,     rlifter,       tmotorTetrix, openLoop)
#pragma config(Motor,  mtr_S1_C3_2,     right,         tmotorTetrix, openLoop)
#pragma config(Motor,  mtr_S1_C4_1,     right2,        tmotorTetrix, openLoop, reversed, encoder)
#pragma config(Motor,  mtr_S1_C4_2,     launcher,      tmotorTetrix, openLoop)
#pragma config(Servo,  srvo_S2_C1_1,    LBgrab,               tServoStandard)
#pragma config(Servo,  srvo_S2_C1_2,    RBgrab,               tServoStandard)
#pragma config(Servo,  srvo_S2_C1_3,    opener,               tServoStandard)
#pragma config(Servo,  srvo_S2_C1_4,    FLgrab,               tServoStandard)
#pragma config(Servo,  srvo_S2_C1_5,    FRgrab,               tServoStandard)
#pragma config(Servo,  srvo_S2_C1_6,    servo6,               tServoNone)
//*!!Code automatically generated by 'ROBOTC' configuration wizard               !!*//

#include "PID.h"
#include "JoystickDriver.c"
#include "hitechnic-compass.h"

PIDController pid = {
	1,0,0,0,0,0,0,0,0,0, false, 0};

float turnSteer = 0;
void driveFwd(int pwr, int ticks) {
	int startPos = nMotorEncoder[left2];
	while(nMotorEncoder[left2] < ticks + startPos) {
		int heading = nMotorEncoder[left2] - nMotorEncoder[right2];
		float steer = PIDUpdate(heading, &pid);
		nxtDisplayCenteredTextLine(2, "heading %d", heading);
		motor[left] = pwr + steer;
		motor[left2] = pwr + steer;
		motor[right] = pwr - steer;
		motor[right2] = pwr - steer;
		wait1Msec(20);
	}
	motor[left] = 0;
	motor[left2] = 0;
	motor[right] = 0;
	motor[right2] = 0;
}

void driveBack(int pwr, int ticks) {
	int startPos = nMotorEncoder[left2];
	while(nMotorEncoder[left2] > startPos-ticks) {
		int heading = nMotorEncoder[left2] - nMotorEncoder[right2];
		float steer = PIDUpdate(heading, &pid);
		nxtDisplayCenteredTextLine(2, "heading %d", heading);
		motor[left] = -pwr + steer;
		motor[left2] = -pwr + steer;
		motor[right] = -pwr - steer;
		motor[right2] = -pwr - steer;
		wait1Msec(20);
	}
	motor[left] = 0;
	motor[left2] = 0;
	motor[right] = 0;
	motor[right2] = 0;
}

void turn(int heading) {
	pid.setPoint = heading;
	float steer;
	long finishTime = time1[T1];
	do {
		int heading = nMotorEncoder[left2] - nMotorEncoder[right2];
		steer = PIDUpdate(heading, &pid);
		turnSteer = steer;
		//nxtDisplayCenteredTextLine(2, "heading %d", heading);
		motor[left] = steer;
		motor[left2] = steer;
		motor[right] = -steer;
		motor[right2] = -steer;
		nxtDisplayCenteredTextLine(2, "%d %d, %d", heading, steer, finishTime);
		wait1Msec(20);
		if (abs(steer) > 10) finishTime = time1[T1];
	} while (steer > 10 || finishTime + 100 > time1[T1]);
	turnSteer = 0;
	motor[left] = 0;
	motor[left2] = 0;
	motor[right] = 0;
	motor[right2] = 0;
}

task main()
{
	pid.kP = 0.2;
	pid.kD = 0.2;
	pid.minOutput = -127;
	pid.maxOutput = 127;
	servo[FLgrab] = 255;
	servo[FRgrab] = 0;
	servo[LBgrab] = 0;
	servo[RBgrab] = 241;   //up
	waitForStart();
	time1[T1] = 0;
	HTMCsetTarget(compass);
	nMotorEncoder[left2] = 0;
	nMotorEncoder[right2] = 0;
	driveBack(100, 6500);
	turn(3000);
	driveFwd(100, 1500);
	turn(-400);
	driveBack(100, 2000);
	wait1Msec(0);
	driveBack(25, 1000);
	servo[LBgrab] = 226;
	servo[RBgrab] = 0;
	wait1Msec(750);
	driveFwd(100, 3000);
	turn(-1000);
	driveFwd(100, 4000);
	turn(200);
	driveFwd(100, 2500);
	turn(2000);
}
