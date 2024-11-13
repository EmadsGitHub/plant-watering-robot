
void driveUntilColor(int colorValue) {
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
		while(SensorValue[S4]!= (int)colorBlack){
			while (SensorValue[S4]!= colorValue){
			nMotorEncoder[motorA]=0;
			motor[motorA]=29;
    	motor[motorD] = 25;
    	while (abs(nMotorEncoder)*CONVERSION<200)){}
    	motor[motorA] = motor[motorD] = 0;
    	wait1Msec(200);
    	motor[motorA] = -29;
    	motor[motorD] = 25;
    	while(abs(getGyroDegrees[S1] < 90)){}
    	motor[motorA] = motor[motorD] = 0;
    	resetGyro[S1];
    	wait1Msec(200);
    	nMotorEncoder[motorA]=0;
			motor[motorA]=29;
    	motor[motorD] = 25;
    	while (abs(nMotorEncoder)*CONVERSION<100)){}
    	motor[motorA] = motor[motorD] = 0;
    	wait1Msec(200);
    	motor[motorA] = -29;
    	motor[motorD] = 25;
    	while(abs(getGyroDegrees[S1] < 90)){}
    	motor[motorA] = motor[motorD] = 0;
    	resetGyro[S1];
    	wait1Msec(200);
			}


		motor[motorA] = motor[motorD] = 0;
    motor[motorA] = -29;
    motor[motorD] = -25;
    wait1Msec(500)///500 is a placeholder, do the math to actually find out how long it goes back for
    motor[motorA] = motor[motorD] = 0;
    resetGyro[S1];

    motor[motorA] = -29;
    motor[motorD] = 25;
    while(abs(getGyroDegrees[S1] < 90)){}
    motor[motorA] = motor[motorD] = 0;

    motor[motorA] = 29;
    motor[motorD] = 25;
    wait1Msec(50); //50 is a placeholder, needs trial & error, or motor encoder math
    motor[motorA] = motor[motorD] = 0;
	}
}
task main() {
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
    driveUntilColor(1);
}
