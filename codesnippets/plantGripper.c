#include "EV3Servo-lib-UW.c"
// Motor locations on interface board
const int SV_CSERVO1 = 1;
const int SV_CSERVO2 = 2;
const int SV_STANDARD = 3;
const int SV_GRIPPER = 4;
// Demo types
const int CONTINUOUS = buttonUp;
const int GRIPPER = buttonEnter;
const int STANDARD = buttonDown;

void GripperClose(){
	setServoSpeed(S4,SV_CSERVO1, -60);
}
void GripperOpen(){
	setServoSpeed(S4,SV_CSERVO1, 60);
}

void plantPickup(){
	GripperClose();
	wait1Msec(1000);
	motor[motorA] = -29;
	motor[motorD] = 25;
	while(abs(getGyroDegrees(S1)) < 180){}
  motor[motorA] = motor[motorD] = 0;
  resetGyro(S1);
  motor[motorA] = 29;
	motor[motorD] = 25;
	while(SensorValue[S4]!=(int)colorBrown){}
	motor[motorA] = motor[motorD] = 0;
	motor[motorA] = -29;
	motor[motorD] = 25;
	while(abs(getGyroDegrees(S1)) < 180){}
  motor[motorA] = motor[motorD] = 0;
  resetGyro(S1);
}

void plantDropoff(){
	GripperOpen();
	wait1Msec(1000);
	motor[motorA] = -29;
	motor[motorD] = 25;
	while(abs(getGyroDegrees(S1)) < 180){}
  motor[motorA] = motor[motorD] = 0;
  resetGyro(S1);
  motor[motorA] = 29;
	motor[motorD] = 25;
	while(SensorValue[S4]!=(int)colorBrown){}
	motor[motorA] = motor[motorD] = 0;
	motor[motorA] = -29;
	motor[motorD] = 25;
	while(abs(getGyroDegrees(S1)) < 180){}
  motor[motorA] = motor[motorD] = 0;
  resetGyro(S1);
}



task main(){
		SensorType[S4] = sensorEV3_Color;
		wait1Msec(50);
		SensorMode[S4] = modeEV3Color_Color;
		wait1Msec(50);
		SensorType[S1] = sensorEV3_Gyro;
		wait1Msec(50);
		SensorMode[S1] = modeEV3Gyro_Calibration;
		wait1Msec(50);
		SensorMode[S1] = modeEV3Gyro_RateAndAngle;
		wait1Msec(50);
		GripperOpen();
		wait1Msec(100);
		GripperClose();
}
