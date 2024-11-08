int days = 0;
int hours = 0;
int minutes = 0;

void setTime() {

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

void orderList (int plantOrder[], int size, int runtime){
	int cycles = runtime/30000;
	int q = 0;
	int wateringOrder[size*cycles];
	for (int i=0; i<cycles; i++){
		for (int j = 0; j<size; j++){
			wateringOrder[(i*size)+j]=plantOrder[j];
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
