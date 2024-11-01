/*----------------------------------------------------------------------------*/
/*                                                                            */
/*    Module:       main.cpp                                                  */
/*    Author:       cline                                                     */
/*    Created:      1/25/2024, 9:06:15 AM                                     */
/*    Description:  V5 project                                                */
/*                                                                            */
/*----------------------------------------------------------------------------*/

#include "vex.h"

using namespace vex;

// A global instance of competition
competition Competition;

//extra function calls

// define your global instances of motors and other devices here

/*---------------------------------------------------------------------------*/
/*                          Pre-Autonomous Functions                         */
/*                                                                           */
/*  You may want to perform some actions before the competition starts.      */
/*  Do them in the following function.  You must return from this function   */
/*  or the autonomous and usercontrol tasks will not be started.  This       */
/*  function is only called once after the V5 has been powered on and        */
/*  not every time that the robot is disabled.                               */
/*---------------------------------------------------------------------------*/

void pre_auton(void) {

    vexcodeInit();

    // All activities that occur before the competition starts
    // Example: clearing encoders, setting servo positions, ...
    return;
}

/*---------------------------------------------------------------------------*/
/*                                                                           */
/*                              Autonomous Task                              */
/*                                                                           */
/*  This task is used to control your robot during the autonomous phase of   */
/*  a VEX Competition.                                                       */
/*                                                                           */
/*  You must modify the code to add your own robot specific commands here.   */
/*---------------------------------------------------------------------------*/

void autonomous(void) {
    //AutonSkills();

    if(GpsSensor.xPosition() > 0){
    //    AutonAufenseRed();
        AutonDefenseBlue();
    } else {
    //    AutonDefenseRed();
        AutonAufenseBlue();
    }

    // ..........................................................................
    // Insert autonomous user code here.
    // ..........................................................................
}

/*---------------------------------------------------------------------------*/
/*                                                                           */
/*                              User Control Task                            */
/*                                                                           */
/*  This task is used to control your robot during the user control phase of */
/*  a VEX Competition.                                                       */
/*                                                                           */
/*  You must modify the code to add your own robot specific commands here.   */
/*---------------------------------------------------------------------------*/

void usercontrol(void) {
    bool firing = false;
    bool intakeActive = false;
    bool PushersActive = false;

    bool latch[3] = { false, false, false };

    GpsSensor.calibrate();
    Pneumatics.set(false);
    Controller.Screen.clearScreen();

    //CatapultMotors.spin(forward, 100, percent);

    while (1) {
        // Drive Train Control Tank Steering
        

        Controller.Screen.setCursor(0, 0);
        Controller.Screen.print(CatapultMotors.temperature(temperatureUnits::celsius));
        Controller.Screen.newLine();


        Brain.Screen.clearScreen();
        Brain.Screen.setCursor(2, 2);

        Brain.Screen.print(GpsSensor.heading());
        Brain.Screen.print("       ");
        Brain.Screen.print(GpsSensor.xPosition());
        Brain.Screen.print("       ");
        Brain.Screen.print(GpsSensor.yPosition());
        Brain.Screen.newLine();
        Brain.Screen.print("DriveTrain Motor Temps: ");
        Brain.Screen.print(LeftMotors.temperature(celsius));
        Brain.Screen.print("       ");
        Brain.Screen.print(RightMotors.temperature(celsius));
        // Aim At goal
        if (Controller.ButtonR1.pressing())
        {
            //gets variables
            int robotX = GpsSensor.xPosition();
            int robotY = GpsSensor.yPosition();
            double angle = GpsSensor.heading();

            double X = (-1800 - robotX);
            double Y = (0- robotY);

            double slope = (Y/X);

            double angletogoto = (tanf(slope) * (180 / 3.14159265358979323846));
            
            Brain.Screen.clearScreen();
            Brain.Screen.setCursor(2, 0);
            Brain.Screen.print(robotX);
            Brain.Screen.print("       ");
            Brain.Screen.print(robotY);
            Brain.Screen.newLine();

            // if(robotX>0 && robotY< 0){
            //     angletogoto += 180;
            // } else if (robotX>0&&robotY>0){
            //     angletogoto += 180;
            // }

            //calculates tha angle needed to turn
            int angleratio = angle - angletogoto;

            Controller.Screen.clearScreen();
            Controller.Screen.print("angle to net =");
            Controller.Screen.print(angle);
            Controller.Screen.newLine();
            Controller.Screen.print(angletogoto);

            //if it is not at the right heading
            if(angleratio<-5 or angleratio >5){
                if(angleratio <0){
                    RightMotors.spin(reverse, 20, percent);
                    LeftMotors.spin(forward, 20, percent);
                } else if(angleratio >0){
                    RightMotors.spin(forward, 20, percent);
                    LeftMotors.spin(reverse, 20, percent);
                } else {
                    Controller.Screen.print("Error");
                }
            } else {
                
                RightMotors.stop();
                LeftMotors.stop();
            }
        } else {
            RightMotors.spin(forward, Controller.Axis3.value()-Controller.Axis1.value(), percent);
            LeftMotors.spin(forward, Controller.Axis3.value()+Controller.Axis1.value(), percent);
        }

        if(Controller.ButtonR2.pressing()){
            if(latch[0]){
                latch[0] = false;
                if(firing){
                    firing = false;
                    CatapultMotors.spin(forward, 100, percent);
                } else{
                    firing = true;
                    CatapultMotors.stop();
                }
            }
        } else {
            latch[0] = true;
        }

        if(Controller.ButtonL2.pressing()){
            if(latch[1]){
                
                latch[1] = false;
                if(intakeActive){
                    intakeActive = false;
                    Intake.spin(forward, 100, percent);
                } else {
                    intakeActive = true;
                    Intake.stop();
                }
            }
        } else{
            latch[1] = true;
        }

        if (Controller.ButtonX.pressing())
        {
            if(latch[2]){
                
                latch[2] = false;
                if(PushersActive){
                    Pneumatics.set(true);
                    PushersActive = false;
                } else {
                    Pneumatics.set(false);
                    PushersActive = true;
                }
            }
        } else {
            latch[2] = true;
        }

        wait(20, msec); // Sleep the task for a short amount of time to prevent wasted resources.
    }
}

//
// Main will set up the competition functions and callbacks.
//
int main() {
  // Set up callbacks for autonomous and driver control periods.
  Competition.autonomous(autonomous);
  Competition.drivercontrol(usercontrol);

  // Run the pre-autonomous function.
  pre_auton();

  // Prevent main from exiting with an infinite loop.
  while (true) {
    wait(100, msec);
  }
}





