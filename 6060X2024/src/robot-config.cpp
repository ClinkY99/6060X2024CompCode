#include "vex.h"

using namespace vex;
using signature = vision::signature;
using code = vision::code;

brain Brain;

controller Controller = controller(primary);

//motors
motor RightMotorA = motor(PORT3, ratio18_1, true);
motor RightMotorB = motor(PORT4, ratio18_1, true);
motor_group RightMotors = motor_group(RightMotorA, RightMotorB);

motor LeftMotorA = motor(PORT1, ratio18_1, false);
motor LeftMotorB = motor(PORT2, ratio18_1, false);
motor_group LeftMotors = motor_group(LeftMotorA, LeftMotorB);

motor CatapultMotorA = motor(PORT5, ratio18_1, false);
motor CatapultMotorB = motor(PORT6, ratio18_1, true);
motor_group CatapultMotors = motor_group(CatapultMotorA, CatapultMotorB);

motor IntakeMotorA = motor(PORT7, ratio18_1, true);
motor IntakeMotorB = motor(PORT8, ratio18_1, true);
motor_group Intake = motor_group(IntakeMotorA, IntakeMotorB);

motor ClimbMotor = motor(PORT9, ratio36_1, true);

//pneumatics
digital_out Pneumatics = digital_out(Brain.ThreeWirePort.A);

//Sensors
gps GpsSensor = gps(PORT11, 0.00, 0.50, mm, 90);
distance IsStuckSensor = distance(PORT12);
distance IsCockedSensor = distance(PORT9);

bool RemoteControlCodeEnabled = true;

void vexcodeInit(void){
    
}