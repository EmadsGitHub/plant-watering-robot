#include "EV3Servo-lib-UW.c"
const int SV_CSERVO1 = 1;

void GripperClose(){
	setServoSpeed(S4,SV_CSERVO1, -60);
}
void GripperOpen(){
	setServoSpeed(S4,SV_CSERVO1, 60);
}


void plantDropoff(){
const float wheelradius=2.75;
	float CONVERSION = (2*PI*wheelradius)/360;
	GripperOpen();
	wait1Msec(1000);
	nMotorEncoder[motorA]=0;
	motor[motorA] = 25;
	motor[motorD] = 25;
	while(abs(nMotorEncoder[motorA])*CONVERSION<11){}
	motor[motorA] = motor[motorD] = 0;
	wait1Msec(500);
	motor[motorA] = -15;
	motor[motorD] = 15;
	while(abs(getGyroDegrees(S1)) < 90){}
  motor[motorA] = motor[motorD] = 0;
  resetGyro(S1);
}

void plantPickup(){
	const float wheelradius=2.75;
	float CONVERSION = (2*PI*wheelradius)/360;
	GripperClose();
	wait1Msec(1000);
	nMotorEncoder[motorA]=0;
	motor[motorA] = 25;
	motor[motorD] = 25;
	while(abs(nMotorEncoder[motorA])*CONVERSION<11){}
	motor[motorA] = motor[motorD] = 0;
	wait1Msec(500);
	motor[motorA] = -15;
	motor[motorD] = 15;
	while(abs(getGyroDegrees(S1)) < 90){}
  motor[motorA] = motor[motorD] = 0;
  resetGyro(S1);
}

void driveUntilColor(int colorValue, int dir) {
	/*
0 = No Colour
1 = Black
2 = Blue
3 = Green
4 = Yellow
5 = Red
6 = White
7 = Brown
*/
	const float wheelradius=2.75;
		float CONVERSION = (2*PI*wheelradius)/360;
		//while(SensorValue[S4]!= (int)colorBlack){
			/*nMotorEncoder[motorA]=0;
			motor[motorA]=-26;
    	motor[motorD] = -25;
    	while (abs(nMotorEncoder[motorA])*CONVERSION<50){}
    	motor[motorA] = motor[motorD] = 0;
    	wait1Msec(200);
    	motor[motorA] = 15;
    	motor[motorD] = -15;
    	while(abs(getGyroDegrees(S1)) < 90){}
    	motor[motorA] = motor[motorD] = 0;
    	resetGyro(S1);
    	wait1Msec(200);
    	nMotorEncoder[motorA]=0;*/
			motor[motorA]=-25*dir;
    	motor[motorD] = -25*dir;
    	while (SensorValue[S3]!= (int)colorValue){}
    	motor[motorA] = motor[motorD] = 0;
    	wait1Msec(200);

    motor[motorA] = 25;
    motor[motorD] = 25;
    wait1Msec(500);///500 is a placeholder, do the math to actually find out how long it goes back for
    motor[motorA] = motor[motorD] = 0;
    resetGyro(S1);

    motor[motorA] = (15);
    motor[motorD] = (-15);
    while(abs(getGyroDegrees(S1)) < 90){}
    motor[motorA] = motor[motorD] = 0;


	//}
}
task main() {
	GripperOpen();
	const float wheelradius=2.75;
		float CONVERSION = (2*PI*wheelradius)/360;
		SensorType[S3] = sensorEV3_Color;
		wait1Msec(50);
		SensorMode[S3] = modeEV3Color_Color;
		wait1Msec(50);
		SensorType[S1] = sensorEV3_Gyro;
		wait1Msec(50);
		SensorMode[S1] = modeEV3Gyro_Calibration;
		wait1Msec(50);
		SensorMode[S1] = modeEV3Gyro_RateAndAngle;
		wait1Msec(50);
    driveUntilColor(4, 1);
    wait1Msec(50);
    nMotorEncoder[motorA] = 0;
    motor[motorA] = -25;
    motor[motorD] = -25;
    while((abs(nMotorEncoder[motorA])*CONVERSION)<10){}///500 is a placeholder, do the math to actually find out how long it goes back for
    motor[motorA] = motor[motorD] = 0;
    resetGyro(S1);
    plantPickup();
    motor[motorA]=motor[motorD] = -25;
    while (SensorValue[S3]!=2){}
    resetGyro(S1);
    motor[motorA]=motor[motorD] = 0;
    motor[motorA]=motor[motorD] = 25;
    while(SensorValue[S3]!=4){}
    wait1Msec(1000);
    motor[motorA] = (15);
    motor[motorD] = (-15);
    while(abs(getGyroDegrees(S1)) < 90){}
    motor[motorA] = motor[motorD] = 0;
    nMotorEncoder[motorA] = 0;
    motor[motorA] = -25;
    motor[motorD] = -25;
    while((abs(nMotorEncoder[motorA])*CONVERSION)<11){}///500 is a placeholder, do the math to actually find out how long it goes back for
    motor[motorA] = motor[motorD] = 0;
    resetGyro(S1);
    plantDropoff();

}
