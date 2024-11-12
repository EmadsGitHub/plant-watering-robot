void waterPlantBasedOnColor(int duration) {

	motor[motorC]= 20;
	wait1Msec(700);
	motor[motorC] = 0;
	wait1Msec(duration);
	motor[motorC] = -20;
	wait1Msec(700);
	motor[motorC] = 0;
	
}


task main() {
   waterPlantBasedOnColor(2000);
   wait1Msec(100);
}
