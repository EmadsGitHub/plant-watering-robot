/* void waterPlantBasedOnColor(*colorDetected) {
    if (colorDetected == (int)colorRed) {
        motor[motorC] = 50;
        wait1Msec(1000);
        motor[motorC] = 0;
    }
    else if (colorDetected == (int)colorBlue) {
        motor[motorC] = 50;
        wait1Msec(6000);
        motor[motorC] = 0;
    }
    else if (colorDetected == (int)colorGreen) {
        motor[motorC] = 50;
        wait1Msec(1000);
        motor[motorC] = 0;
    }
    else if (colorDetected == (int)colorYellow) {
    		motor[motorC] = 50;
      	wait1Msec(5000);
      	motor[motorC] = 0;
    }
     else if (colorDetected == (int)colorBlack) {
    		motor[motorC] = 50;
      	wait1Msec(3000);
      	motor[motorC] = 0;
    }
     else if (colorDetected == (int)colorBrown) {
    		motor[motorC] = 50;
      	wait1Msec(7000);
      	motor[motorC] = 0;
    }
    else {
        motor[motorC] = 0;
    }
} */
/*
void orderList (int plantOrder[], int size, int runtime){
	int cycles = runtime/30000;
	int q = 0;
	int wateringOrder[size*cycles];
	for (int i=0; i<cycles; i++){
		for (int j = 0; j<size; j++){
			wateringOrder[(i*size)+j]=plantOrder[j];
		}
	}
	for (int m = 0; m<size*cycles; m++){
		cout<<wateringOrder[m]<<endl;
	}
}
*/
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
    motor[motorA]=29;
    motor[motorD] = 25;
    while(SensorValue[S4]!= colorValue){}
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
task main() {
		SensorType[S4] = sensorEV3_Color;
		wait1Msec(50);
		SensorMode[S4] = modeEV3Color_Color;
		wait1Msec(50);
    int targetColors[6] = {1, 2, 3, 4, 5, 6};
    driveUntilColor(1);
    displayTextLine(0, "Color Sensor Initialized");
}
