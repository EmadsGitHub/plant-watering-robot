#pragma DebuggerWindows ("Globals")
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


int converttoSecs(int days, int hours, int minutes) {

    int totalSecs = 0;

    totalSecs += days * 86400;
    totalSecs += hours * 3600;
    totalSecs += minutes * 60;

    return totalSecs;
}

void setDuration(int pos, int *durationArray) {
	int mins=0;
	int secs=0;
	bool newplant = false;

	while(!newplant) {
	    eraseDisplay();
	    displayBigTextLine(1, "How long?");
	    displayBigTextLine(3, "Minutes (Up)");
	    displayBigTextLine(5, "Seconds (Down)");
	    displayBigTextLine(7, "Done (Other)");

	    // Wait for any button press
	    while (!getButtonPress(buttonAny)) {
	        wait1Msec(20);  // Add small delay to reduce CPU usage
	    }

	    if (getButtonPress(buttonUp)) {
	        while (getButtonPress(buttonUp)) {}
	        wait1Msec(20);

	        eraseDisplay();
	        // Hours adjustment loop
	        while (!getButtonPress(buttonEnter)) {
	            eraseDisplay();  // Clear display each update
	            displayBigTextLine(1, "Increase Time");
	            displayBigTextLine(3, "Mins: %d", mins);

	            if (getButtonPress(buttonUp)) {
	                while(getButtonPress(buttonUp)) {}
	                wait1Msec(20);
	                mins = mins + 1;
	            }
	            if (getButtonPress(buttonDown)) {
	                while(getButtonPress(buttonDown)) {}
	                wait1Msec(20);
	                mins = mins - 1;

	                // Add bounds checking
	                if (mins < 0) mins = 0;
	            }
	            wait1Msec(100);  // Reduced delay for better responsiveness
	        }
	        // Wait for Enter button release
	        while (getButtonPress(buttonEnter)) {}
	        wait1Msec(20);
	    }
	    else if (getButtonPress(buttonDown)) {
	        while (getButtonPress(buttonDown)) {}
	        wait1Msec(20);

	        eraseDisplay();
	        // Minutes adjustment loop
	        while (!getButtonPress(buttonEnter)) {
	            eraseDisplay();  // Clear display each update
	            displayBigTextLine(1, "Increase Time");
	            displayBigTextLine(3, "Secs: %d", secs);

	            if (getButtonPress(buttonUp)) {
	                while(getButtonPress(buttonUp)) {}
	                wait1Msec(20);
	                secs = secs + 5;
	            }
	            if (getButtonPress(buttonDown)) {
	                while(getButtonPress(buttonDown)) {}
	                wait1Msec(20);
	                secs = secs - 5;

	                // Add bounds checking
	                if (secs < 0) secs = 0;
	            }
	            wait1Msec(100);
	        }
	        // Wait for Enter button release
	        while (getButtonPress(buttonEnter)) {}
	        wait1Msec(20);
	    }
	    else {
	        newplant = true;
	        while (getButtonPress(buttonAny)) {}  // Wait for any button release
	        wait1Msec(20);
	        durationArray[pos] = mins*60+secs;
	    }
	}

}

int setTime() {

		int days = 0;
		int minutes = 0;
		int hours = 0;

    int currentSelection = 0;
    bool finished = false;

    while(!finished) {

        displayBigTextLine(1, "Set Time:");
        displayBigTextLine(3, "Days: %d", days);
        displayBigTextLine(5, "Hours: %d", hours);
        displayBigTextLine(7, "Minutes: %d", minutes);

        if (getButtonPress(buttonUp)) {

            if (currentSelection == 0) days++;
            else if (currentSelection == 1) hours = (hours + 1) % 24;
            else if (currentSelection == 2) minutes = (minutes + 1) % 60;

            while (getButtonPress(buttonUp)) {};

        } else if (getButtonPress(buttonDown)) {

            if (currentSelection == 0 && days > 0) days--;
            else if (currentSelection == 1 && hours > 0) hours--;
            else if (currentSelection == 2 && minutes > 0) minutes--;

            while (getButtonPress(buttonDown)) {};
        }

        if (getButtonPress(buttonRight)) {

            currentSelection = (currentSelection + 1) % 3;
            while (getButtonPress(buttonRight)) {};

        } else if (getButtonPress(buttonLeft)) {

            currentSelection = (currentSelection + 2) % 3;
            while (getButtonPress(buttonLeft)) {};
        }
        if (getButtonPress(buttonEnter)) {
        	finished = true;
        	while(getButtonPress(buttonEnter)){

        	}
        	wait1Msec(20);

        }
    }
    int runTime = converttoSecs(days, hours, minutes);

		return runTime;
 }

 int setInterval() {

		int days = 0;
		int minutes = 0;
		int hours = 0;

    int currentSelection = 0;
    bool finished = false;

    while(!finished) {

        displayBigTextLine(1, "Set Plant Interval:");
        displayBigTextLine(3, "Days: %d", days);
        displayBigTextLine(5, "Hours: %d", hours);
        displayBigTextLine(7, "Minutes: %d", minutes);

        if (getButtonPress(buttonUp)) {

            if (currentSelection == 0) days++;
            else if (currentSelection == 1) hours = (hours + 1) % 24;
            else if (currentSelection == 2) minutes = (minutes + 1) % 60;

            while (getButtonPress(buttonUp)) {};

        } else if (getButtonPress(buttonDown)) {

            if (currentSelection == 0 && days > 0) days--;
            else if (currentSelection == 1 && hours > 0) hours--;
            else if (currentSelection == 2 && minutes > 0) minutes--;

            while (getButtonPress(buttonDown)) {};
        }

        if (getButtonPress(buttonRight)) {

            currentSelection = (currentSelection + 1) % 3;
            while (getButtonPress(buttonRight)) {};

        } else if (getButtonPress(buttonLeft)) {

            currentSelection = (currentSelection + 2) % 3;
            while (getButtonPress(buttonLeft)) {};
        }
        if (getButtonPress(buttonEnter)) {
        	finished = true;

        }
    }
    int intervalTime = converttoSecs(days, hours, minutes);

		return intervalTime;
 }

 void plantPick(int *intervalArray){
 				eraseDisplay();
				bool willloop = true;
						while(willloop){
	            displayBigTextLine(1, "Plant?");
			        displayBigTextLine(3, "Cactus (Left)");
			        displayBigTextLine(5, "Jade (Right)");
			        displayBigTextLine(7, "Aloe (Up)");
			        displayBigTextLine(9, "Finished (Down)");
	            while(!getButtonPress(buttonAny)){}

						    if (getButtonPress(buttonLeft)) {
						        // Wait for button release and add small delay for debouncing
						     		while (getButtonPress(buttonLeft)){}
										wait1Msec(20);  // Debounce delay
										setDuration(0, intervalArray);
						    }
						    if (getButtonPress(buttonRight)) {
						        // Wait for button release and add small delay for debouncing
						     		while (getButtonPress(buttonRight)){}
										wait1Msec(20);  // Debounce delay
										setDuration(1, intervalArray);
						    }
						    if (getButtonPress(buttonUp)) {
						        // Wait for button release and add small delay for debouncing
						     		while (getButtonPress(buttonUp)){}
										wait1Msec(20);  // Debounce delay
										setDuration(2, intervalArray);
						    }
						    if (getButtonPress(buttonDown)) {
						        // Wait for button release and add small delay for debouncing
						     		while (getButtonPress(buttonDown)){}
										willloop = false;
						    }
						}


}





void runRobot(int runtimeInSeconds) {

    clearTimer(T1);

    motor[motorA] = motor[motorD] = 50;

    while(time1[T1] < runtimeInSeconds * 1000) {};

    motor[motorA] = motor[motorD] = 50;
}


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
		//while(SensorValue[S4]!= (int)colorBlack){
			while (SensorValue[S4]!= colorValue){
			nMotorEncoder[motorA]=0;
			motor[motorA]=25;
    	motor[motorD] = 25;
    	while (abs(nMotorEncoder[motorA])*CONVERSION<100){}
    	motor[motorA] = motor[motorD] = 0;
    	wait1Msec(200);
    	motor[motorA] = -25;
    	motor[motorD] = 25;
    	while(abs(getGyroDegrees(S1)) < 90){}
    	motor[motorA] = motor[motorD] = 0;
    	resetGyro(S1);
    	wait1Msec(200);
    	nMotorEncoder[motorA]=0;
			motor[motorA]=25;
    	motor[motorD] = 25;
    	while (abs(nMotorEncoder[motorA])*CONVERSION<50){}
    	motor[motorA] = motor[motorD] = 0;
    	wait1Msec(200);
    	motor[motorA] = -25;
    	motor[motorD] = 25;
    	while(abs(getGyroDegrees(S1)) < 90){}
    	motor[motorA] = motor[motorD] = 0;
    	resetGyro(S1);
    	wait1Msec(200);
			}


		motor[motorA] = motor[motorD] = 0;
    motor[motorA] = -25;
    motor[motorD] = -25;
    wait1Msec(500);///500 is a placeholder, do the math to actually find out how long it goes back for
    motor[motorA] = motor[motorD] = 0;
    resetGyro(S1);

    motor[motorA] = -25;
    motor[motorD] = 25;
    while(abs(getGyroDegrees(S1)) < 90){}
    motor[motorA] = motor[motorD] = 0;

    motor[motorA] = 25;
    motor[motorD] = 25;
    wait1Msec(50); //50 is a placeholder, needs trial & error, or motor encoder math
    motor[motorA] = motor[motorD] = 0;
	//}
}

void waterPlantBasedOnColor(int duration) {

	motor[motorC]= 20;
	wait1Msec(700);
	motor[motorC] = 0;
	wait1Msec(duration);
	motor[motorC] = -20;
	wait1Msec(700);
	motor[motorC] = 0;

}


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



task main()
{
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
		string plantArray[3] = {"Cactus", "Jade", "Aloe"};
    int durationArray[3];
    int runtimeInSeconds = setTime();
    int intervalinSeconds = setInterval();
    plantPick(durationArray);
		wait1Msec(200);
    eraseDisplay();
		wait1Msec(200);
    for (int i = 0; i<3; i++){
    	if (durationArray[i] == 0){
    		plantArray[i]="";
    	}
    }
    int cycles = runtimeInSeconds/intervalinSeconds;


    runRobot(runtimeInSeconds);


}
