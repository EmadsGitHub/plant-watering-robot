#include "EV3Servo-lib-UW.c"
#include "Drive until Color.c"
#include "Final Project.c"
#include "Gripper project.c"
#include "Gripper Test.c"
#include "Time Test.c"
#include "Water motor.c"



task main(){
	SensorType[S1] = sensorEV3_Gyro;
	waitMsec(50);

	int RunTime = setTime();
	int Cycles = RunTime/30000;//30000 is a placeholder
	int PlantOrder[1,2,3,4]; //Placeholder //Need a function to let the user decide this
	int WateringOrder[sizeof(PlantOrder)*cycles];
	orderList(plantOrder[], Cycles, WateringOrder);

	for(int i =0; i < sizeof(WateringOrder); i++){
		GripperOpen();
		driveUntilColor(WateringOrder[i]);
		GripperClose();
	}
}
