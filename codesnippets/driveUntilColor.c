

#include "EV3Servo-lib-UW.c";
const int SV_CSERVO1 = 1;
float CONVERSION = (2*PI*2.75)/360;


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
  motor[motorA] = 26;
  motor[motorD] = 25;
  while(abs(nMotorEncoder[motorA])*CONVERSION<5){}
	motor[motorA] = -10;
	motor[motorD] = 10;
	while(abs(getGyroDegrees(S1)) < 90){}
  motor[motorA] = motor[motorD] = 0;
  resetGyro(S1);
  wait1Msec(50);
}

void plantPickup(int plant){
	float CONVERSION = (2*PI*2.75)/360;
	GripperClose();
	wait1Msec(1000);
	motor[motorA] = motor[motorD] = 0;
	wait1Msec(500);
	nMotorEncoder[motorA] = 0;

  motor[motorA] = 25;
  motor[motorD] = 25;
  if (plant == 0){
  	while(abs(nMotorEncoder[motorA])*CONVERSION<10){}
  }
  if (plant == 1){
  	while(abs(nMotorEncoder[motorA])*CONVERSION<10){}
	}
	motor[motorA] = -10;
	motor[motorD] = 10;
	while(abs(getGyroDegrees(S1)) < 82){}
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
		if (dir==-1){
			motor[motorA]=26;
    	motor[motorD] = 25;
    	while(SensorValue[S3]!=2){}
    	wait1Msec(50);
    	while(SensorValue[S3]!=2){}
    	wait1Msec(50);
    	while(SensorValue[S3]!=2){}
    	wait1Msec(50);
    	motor[motorA] = motor[motorD] = 0;
    	wait1Msec(200);
      nMotorEncoder[motorA]=0;
    	motor[motorA] = 26;
  		motor[motorD] = 25;
  		while(abs(nMotorEncoder[motorA])*CONVERSION<5){}
  		wait1Msec(50);
		}
		else{
			motor[motorA]=-25;
    	motor[motorD] = -25;
    	while(SensorValue[S3]!=2){}
    	wait1Msec(50);
    	while(SensorValue[S3]!=2){}
    	wait1Msec(50);
    	while(SensorValue[S3]!=2){}
    	wait1Msec(50);
    	motor[motorA] = motor[motorD] = 0;
    	wait1Msec(200);

		}

	}
	if (plant == 1){
			if (dir==-1){
			motor[motorA]=26;
    	motor[motorD] = 25;
    	while(SensorValue[S3]!=6){}
    	motor[motorA] = motor[motorD] = 0;
    	wait1Msec(200);
      nMotorEncoder[motorA]=0;
    	motor[motorA] = 26;
  		motor[motorD] = 25;
  		while(abs(nMotorEncoder[motorA])*CONVERSION<5){}
  		wait1Msec(50);
		}
		else{
			motor[motorA]=-25;
    	motor[motorD] = -25;
    	while(SensorValue[S3]!=6){}
    	motor[motorA] = motor[motorD] = 0;
    	wait1Msec(200);

		}
	}
	if (plant == 2){
			if (dir==-1){
			motor[motorA]=26;
    	motor[motorD] = 25;
    	while(SensorValue[S3]!=3){}
    	wait1Msec(50);
    	while(SensorValue[S3]!=3){}
    	wait1Msec(50);
    	while(SensorValue[S3]!=3){}
    	wait1Msec(50);
    	motor[motorA] = motor[motorD] = 0;
    	wait1Msec(200);
      nMotorEncoder[motorA]=0;
    	motor[motorA] = 26;
  		motor[motorD] = 25;
  		while(abs(nMotorEncoder[motorA])*CONVERSION<5){}
  		wait1Msec(50);
		}
		else{
			motor[motorA]=-25;
    	motor[motorD] = -25;
    	while(SensorValue[S3]!=3){}
    	wait1Msec(50);
    	while(SensorValue[S3]!=3){}
    	wait1Msec(50);
    	while(SensorValue[S3]!=3){}
    	wait1Msec(50);
    	motor[motorA] = motor[motorD] = 0;
    	wait1Msec(200);

		}
	}

    motor[motorA] = (10);
    motor[motorD] = -10;
    while(abs(getGyroDegrees(S1)) < 88){}
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
		SensorMode[S3] = modeEV3Color_Color;
		wait1Msec(50);
		SensorType[S1] = sensorEV3_Gyro;
		wait1Msec(50);
		SensorMode[S1] = modeEV3Gyro_Calibration;
		wait1Msec(50);
		SensorMode[S1] = modeEV3Gyro_RateAndAngle;
		wait1Msec(50);
    driveUntilColor(2, 1);
    wait1Msec(50);
    nMotorEncoder[motorA] = 0;
    motor[motorA] = -25;
    motor[motorD] = -25;
    while(abs(nMotorEncoder[motorA])*CONVERSION<10){}///500 is a placeholder, do the math to actually find out how long it goes back for
    motor[motorA] = motor[motorD] = 0;
    wait1Msec(50);
    plantPickup(1);
    wait1Msec(50);
    nMotorEncoder[motorA] = 0;
    motor[motorA]= -25;
    motor[motorD]= -25;
    while(SensorValue[S3]!=4){}
    wait1Msec(50);
    while(SensorValue[S3]!=4){}
    wait1Msec(50);
    while(SensorValue[S3]!=4){}
    wait1Msec(50);
    motor[motorA]=motor[motorD] = 0;
    wait1Msec(50);
    driveUntilColor(2, -1);
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
    wait1Msec(1800);
   	motor[motorA] = motor[motorD] = 0;
    wait1Msec(50);

}
