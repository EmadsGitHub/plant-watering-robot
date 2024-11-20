

#include "EV3Servo-lib-UW.c";
const int SV_CSERVO1 = 1;



void GripperClose(){
	setServoSpeed(S4,SV_CSERVO1, -60);
}
void GripperOpen(){
	setServoSpeed(S4,SV_CSERVO1, 60);
}


void plantDropoff(){
	float CONVERSION = (2*PI*2.75)/360;
	GripperOpen();
	wait1Msec(500);
	nMotorEncoder[motorA] = 0;
  motor[motorA] = 25;
  motor[motorD] = 25;
  while(abs(nMotorEncoder[motorA])*CONVERSION<5){}
	motor[motorA] = -15;
	motor[motorD] = 15;
	while(abs(getGyroDegrees(S1)) < 90){}
  motor[motorA] = motor[motorD] = 0;
  resetGyro(S1);
  wait1Msec(50);
}

void plantPickup(){
	float CONVERSION = (2*PI*2.75)/360;
	GripperClose();
	wait1Msec(1000);
	motor[motorA] = motor[motorD] = 0;
	wait1Msec(500);
	nMotorEncoder[motorA] = 0;

  motor[motorA] = 25;
  motor[motorD] = 25;
  while(abs(nMotorEncoder[motorA])*CONVERSION<2){}
	motor[motorA] = -15;
	motor[motorD] = 15;
	while(abs(getGyroDegrees(S1)) < 90){}
  motor[motorA] = motor[motorD] = 0;
  resetGyro(S1);
  wait1Msec(50);
}



void driveUntilColor(int plant, int dir) {
	/*
0 = Cactus
1 = Jade
2 = Aloe
*/
	if (plant == 0){
			motor[motorA]=-25*dir;
    	motor[motorD] = -25*dir;
    	while(SensorValue[S3]<20 || SensorValue[S3]>25){}
    	motor[motorA] = motor[motorD] = 0;
    	wait1Msec(200);
	}
	if (plant == 1){
			motor[motorA]=-25*dir;
    	motor[motorD] = -25*dir;
    	while(SensorValue[S3]<20 || SensorValue[S3]>25){}
    	motor[motorA] = motor[motorD] = 0;
    	wait1Msec(200);
	}
	if (plant == 2){
			motor[motorA]=-25*dir;
    	motor[motorD] = -25*dir;
    	while(SensorValue[S3]<20 || SensorValue[S3]>25){}
    	motor[motorA] = motor[motorD] = 0;
    	wait1Msec(200);
	}

    motor[motorA] = (15);
    motor[motorD] = -15;
    while(abs(getGyroDegrees(S1)) < 90){}
    motor[motorA] = motor[motorD] = 0;
    resetGyro(S1);
    wait1Msec(50);

}
task main() {
		float CONVERSION = (2*PI*2.75)/360;
		GripperOpen();
		resetGyro(S1);
		SensorType[S3] = sensorEV3_Color;
		wait1Msec(50);
		SensorMode[S3] = modeEV3Color_Reflected;
		wait1Msec(50);
		SensorType[S1] = sensorEV3_Gyro;
		wait1Msec(50);
		SensorMode[S1] = modeEV3Gyro_Calibration;
		wait1Msec(50);
		SensorMode[S1] = modeEV3Gyro_RateAndAngle;
		wait1Msec(50);
    driveUntilColor(0, 1);
    wait1Msec(50);
    nMotorEncoder[motorA] = 0;
    motor[motorA] = -25;
    motor[motorD] = -25;
    while(abs(nMotorEncoder[motorA])*CONVERSION<10){}///500 is a placeholder, do the math to actually find out how long it goes back for
    motor[motorA] = motor[motorD] = 0;
    wait1Msec(50);
    plantPickup();
    wait1Msec(50);
    nMotorEncoder[motorA] = 0;
    motor[motorA]= -25;
    motor[motorD]= -25;
    while(SensorValue[S3]<10 || SensorValue[S3]>18){}
    motor[motorA]=motor[motorD] = 0;
    wait1Msec(50);
    driveUntilColor(0, -1);
    wait1Msec(50);
    nMotorEncoder[motorA] = 0;
    motor[motorA] = -25;
    motor[motorD] = -25;
    while(abs(nMotorEncoder[motorA])*CONVERSION<10){}///500 is a placeholder, do the math to actually find out how long it goes back for
    motor[motorA] = motor[motorD] = 0;
    wait1Msec(50);
    plantDropoff();
    motor[motorA] = 25;
    motor[motorD] = 25;
    wait1Msec(2000);
   	motor[motorA] = motor[motorD] = 0;
    wait1Msec(50);

}
