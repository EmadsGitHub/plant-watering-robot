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

task main()
{
setServoSpeed(S1,SV_CSERVO1, 0);
wait1Msec(1000);
setServoSpeed(S1,SV_CSERVO1, 60);
wait1Msec(2000);
setServoSpeed(S1,SV_CSERVO1, -60);


}
