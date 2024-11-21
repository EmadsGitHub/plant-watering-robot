void waterPlantBasedOnColor(int duration) {

	nMotorEncoder[motorC] = 0;
	motor[motorC]= -10;
	while(abs(nMotorEncoder(motorC))<120){}
	motor[motorC] = 0;
	wait1Msec(duration);
	nMotorEncoder[motorC] = 0;
	motor[motorC]= 10;
	while(abs(nMotorEncoder(motorC))<440){}
	motor[motorC] = 0;
	nMotorEncoder[motorC] = 0;
	motor[motorC]= -10;
	while(abs(nMotorEncoder(motorC))<315){}
	motor[motorC] = 0;

}


task main() {
   waterPlantBasedOnColor(2000);
   wait1Msec(100);
}
