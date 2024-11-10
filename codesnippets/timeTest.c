int days = 0;
int hours = 0;
int minutes = 0;
int setTime() {
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
            while (getButtonPress(buttonEnter)) {};
            finished = true;
        }
    }
    return days*24*60*60 + hours*3600 + minutes * 60;
}
int calculateRuntimeInSeconds() {
    int totalSeconds = 0;
    totalSeconds += days * 86400;
    totalSeconds += hours * 3600;
    totalSeconds += minutes * 60;
    return totalSeconds;
}
void runRobot(int runtimeInSeconds) {
    clearTimer(T1);
    motor[motorA] = motor[motorD] = 50;
    while(time1[T1] < runtimeInSeconds * 1000) {};
    motor[motorA] = motor[motorD] = 50;
}
void orderList (int plantOrder[], int cycles, int &WateringOrder[]){
	int size = sizeof(plantOrder);
	for (int i=0; i<cycles; i++){
		for (int j = 0; j<size; j++){
			WateringOrder[(i*size)+j]=plantOrder[j];
		}
	}
}
void setDuration(int pos, int *intervalArray) {
	int mins=0;
	int hrs=0;
	bool newplant = false;

	while(!newplant) {
	    eraseDisplay();
	    displayBigTextLine(1, "How often?");
	    displayBigTextLine(3, "Hours (Up)");
	    displayBigTextLine(5, "Minutes (Down)");
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
	            displayBigTextLine(3, "Hours: %d", hrs);

	            if (getButtonPress(buttonUp)) {
	                while(getButtonPress(buttonUp)) {}
	                wait1Msec(20);
	                hrs = hrs + 1;
	            }
	            if (getButtonPress(buttonDown)) {
	                while(getButtonPress(buttonDown)) {}
	                wait1Msec(20);
	                hrs = hrs - 1;

	                // Add bounds checking
	                if (hrs < 0) hrs = 0;
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
	            displayBigTextLine(3, "Minutes: %d", mins);

	            if (getButtonPress(buttonUp)) {
	                while(getButtonPress(buttonUp)) {}
	                wait1Msec(20);
	                mins = mins + 5;
	            }
	            if (getButtonPress(buttonDown)) {
	                while(getButtonPress(buttonDown)) {}
	                wait1Msec(20);
	                mins = mins - 5;

	                // Add bounds checking
	                if (mins < 0) mins = 0;
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
	        intervalArray[pos] = hrs*3600+mins*60;
	    }
	}

}
task main() {
    setTime();
    int runtimeInSeconds = calculateRuntimeInSeconds();
    displayBigTextLine(9, "Runtime: %d sec", runtimeInSeconds);
    wait1Msec(2000);
    runRobot(runtimeInSeconds);
}
