#include "vex.h"

using namespace vex;

void AutonSkills()
{
    GpsSensor.calibrate();
    CatapultMotors.spin(forward, 100, percent);
    wait(40, sec);
    CatapultMotors.stop();
    // while (IsCockedSensor.objectDistance(mm) < 70)
    // {
    //     CatapultMotors.spin(forward, 100, percent);
    // }
    // CatapultMotors.spin(forward, 1, percent);
    TurnToAngle(160, -1, 0, forward);
    GotoLocation(0, 900, -1, 170, forward);
    TurnToAngle(165, 1, 25, forward);
    GotoLocation(1, -900, -1, 130, forward);

    TurnToAngle(110, 1, 25, forward);

    RightMotors.spin(forward, 100, percent);
    LeftMotors.spin(forward, 100, percent);
    wait(1, sec);
    // //GotoLocation(1, 750, -1, 110, reverse,75,50);
    // //GotoLocation(1, 700, 1, 70, forward, 100, 50);
    // //GotoLocation(1, 750, -1, 110, reverse,75,50);
    // //GotoLocation(1, 700, 1, 70, forward, 100, 50);

    TurnToAngle(200, 1, 0, reverse);

    GotoLocation(0, 450, 1, 190, reverse,100, 50);
    
    TurnToAngle(170, 1, 0, forward);

    Pneumatics.set(true);

    RightMotors.spin(forward, 100, percent);
    LeftMotors.spin(forward, 100, percent);
    wait(1, msec);
    Pneumatics.set(false);
    GotoLocation(0, 450, 1, 160, reverse,100,50);
    
    TurnToAngle(120, 1, 0, forward);
    Pneumatics.set(true);
    GotoLocation(0, 900, -1, 160, forward,100, 25);
    Pneumatics.set(false);

    // while (GpsSensor.heading() > 180)
    // {
    //     RightMotors.spin(forward, 100, percent);
    //     LeftMotors.spin(reverse, -100, percent);
    // }
    TurnToAngle(220, 1, 0, reverse);
    // while (GpsSensor.yPosition() > -1100)
    // {
    //     RightMotors.spin(forward, 100, percent);
    //     LeftMotors.spin(forward, 100, percent);
    // }

    GotoLocation(1, 1200, -1, 280, reverse, 100, 0);
    // RightMotors.stop();
    // LeftMotors.stop();

    TurnToAngle(240, 1, -100, forward);


    GotoLocation(1, 660, 1, 260, forward);
    RightMotors.stop();
    LeftMotors.stop();
    wait(3, sec);

    // while(GpsSensor.yPosition() > -1100){
    //     RightMotors.spin(reverse, 100, percent);
    //     LeftMotors.spin(reverse, 100, percent);
    // }
    // while(GpsSensor.heading()> 260){
    //     RightMotors.spin(forward, 100, percent);
    //     LeftMotors.spin(reverse, 100, percent);
    // }
    // while(GpsSensor.yPosition()<-660){
    //     RightMotors.spin(reverse, 100, percent);
    //     LeftMotors.spin(reverse, 100, percent);
    // }
    // while(GpsSensor.yPosition()<-950){
    //     RightMotors.spin(forward, 100, percent);
    //     LeftMotors.spin(forward, 100, percent);
    // }
    // while(GpsSensor.heading()>15){
    //     RightMotors.spin(reverse, 50, percent);
    //     LeftMotors.spin(reverse, 100, percent);
    // }
}


