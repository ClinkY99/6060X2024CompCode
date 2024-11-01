using namespace vex;

extern brain Brain;

extern controller Controller;

//Motors
extern motor_group RightMotors;
extern motor_group LeftMotors;
extern motor_group CatapultMotors;
extern motor_group Intake;
extern motor LiftMechanism;

//Pneumatics
extern digital_out Pneumatics;

//Sensors
extern gps GpsSensor;
extern distance IsStuckSensor;

extern distance IsCockedSensor;


void vexcodeInit(void);