#pragma DebuggerWindows ("Globals")



int converttoSecs(int days, int hours, int minutes, int secs) {

    int totalSecs = 0;

    totalSecs += days * 86400;
    totalSecs += hours * 3600;
    totalSecs += minutes * 60;
    totalSecs = totalSecs+secs;

    return totalSecs;
}

int setDuration() {
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
	    }
	}
	return converttoSecs(0, 0, mins, secs);

}

int setTime() {

		int days = 0;
		int minutes = 0;
		int hours = 0;
		int secs = 0;

    int currentSelection = 0;
    bool finished = false;

    while(!finished) {

        displayBigTextLine(1, "Set Water Time:");
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
    int runTime = converttoSecs(days, hours, minutes, secs);

		return runTime;
 }



 int plantPick(){
 				eraseDisplay();

	            displayBigTextLine(1, "Plant?");
			        displayBigTextLine(3, "Cactus (Left)");
			        displayBigTextLine(5, "Jade (Right)");
			        displayBigTextLine(7, "Aloe (Up)");

	            while(!getButtonPress(buttonAny)){}

						    if (getButtonPress(buttonLeft)) {
						        // Wait for button release and add small delay for debouncing
						     		while (getButtonPress(buttonLeft)){}
										wait1Msec(20);  // Debounce delay
										return 0;
						    }
						    else if (getButtonPress(buttonRight)) {
						        // Wait for button release and add small delay for debouncing
						     		while (getButtonPress(buttonRight)){}
										wait1Msec(20);  // Debounce delay
										return 1;
						    }
						    else if (getButtonPress(buttonUp)) {
						        // Wait for button release and add small delay for debouncing
						     		while (getButtonPress(buttonUp)){}
										wait1Msec(20);  // Debounce delay
										return 2;
						    }


		return -1;
}






task main() {

    int waitTime = setTime();
    int plantPicked = plantPick();
    int timeWatered = setDuration();
		wait1Msec(200);
    eraseDisplay();

}
