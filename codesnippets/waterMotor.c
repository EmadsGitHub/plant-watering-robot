void waterPlantBasedOnColor(*colorDetected) {


    if (colorDetected == (int)colorRed) {
        motor[motorC] = 100;
        wait1Msec(2000);
        motor[motorC] = 0;
    }
    else if (colorDetected == (int)colorBlue) {
        motor[motorC] = 100;
        wait1Msec(6000);
        motor[motorC] = 0;
    }
    else if (colorDetected == (int)colorGreen) {
        motor[motorC] = 100;
        wait1Msec(1000);
        motor[motorC] = 0;
    }
    else if (colorDetected == (int)colorYellow) {
    		motor[motorC] = 100;
      	wait1Msec(5000);
      	motor[motorC] = 0;
    }
     else if (colorDetected == (int)colorBlack) {
    		motor[motorC] = 100;
      	wait1Msec(3000);
      	motor[motorC] = 0;
    }
     else if (colorDetected == (int)colorBrown) {
    		motor[motorC] = 100;
      	wait1Msec(7000);
      	motor[motorC] = 0;
    }

    else {
        motor[motorC] = 0;
    }
}


task main() {
    while(true) {
        waterPlantBasedOnColor();
        wait1Msec(100);
    }
}
