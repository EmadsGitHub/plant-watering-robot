void waterPlantBasedOnColor(int duration) {

	nMotorEncoder[motorC] = 0
	motor[motorC]= 20;
	while(abs(nMotorEncoder(motorC))<180){}
	motor[motorC] = 0;
	wait1Msec(duration);
	nMotorEncoder[motorC] = 0
	motor[motorC]= -20;
	while(abs(nMotorEncoder(motorC))<180){}
	motor[motorC] = 0;
}


task main() {
   waterPlantBasedOnColor(2000);
   wait1Msec(100);
}
