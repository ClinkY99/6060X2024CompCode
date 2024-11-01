#include "vex.h"

using namespace vex;


void AutonDefenseRed(){
    GotoLocation(0, -450, -1, 0, reverse, 100, 100);

    GotoLocation(0, -900, 1, .0, forward, 100, 100);

    LeftMotors.spin(forward, 100, percent);
    RightMotors.stop();

    wait(500, msec);

    GotoLocation(1, -900, -1, 60, forward, 100, 0);

    TurnToAngle(50, -1, 0, forward);

    RightMotors.spin(forward, 100, percent);
    LeftMotors.spin(forward, 100, percent);
    wait(500, msec);
    RightMotors.spin(reverse, 100, percent);
    LeftMotors.spin(reverse, 100, percent);
    wait(250, msec);
    RightMotors.spin(forward, 100, percent);
    LeftMotors.spin(forward, 100, percent);
    wait(500, msec);

    GotoLocation(1, -800, 1, 90, reverse);

    TurnToAngle(130, -1, 0, reverse);

    RightMotors.stop();
    LeftMotors.stop();
}
void AutonAufenseRed(){

    // RightMotors.spin(forward, 100, percent);
    // LeftMotors.spin(forward, 100, percent);
    // wait(50, msec);

    // LeftMotors.spin(reverse, 100, percent);
    // RightMotors.spin(reverse, 100, percent);
    // wait(10, msec);

    GotoLocation(0, 900, -1, 170, forward);

    Pneumatics.set(true);

    TurnToAngle(120, 1, 25, forward);

    Pneumatics.set(false);

    RightMotors.spin(forward, 100, percent);
    LeftMotors.spin(forward, 100, percent);
    wait(750, msec);

    RightMotors.spin(reverse, 100, percent);
    LeftMotors.spin(reverse, 100, percent);
    wait(500, msec);

    

    TurnToAngle(60, 1, 0, forward);

   

    GotoLocation(0, 200, 1, 40, forward, 100,25);
    Pneumatics.set(true);

    GotoLocation(1, -300, -1, 90, forward, 50, 0);

    TurnToAngle(160, -1, 0, forward);
    RightMotors.spin(forward, 100, percent);
    LeftMotors.spin(forward, 100, percent);

    wait(3, sec);
    RightMotors.stop();
    LeftMotors.stop();
}