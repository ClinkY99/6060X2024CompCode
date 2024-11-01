#include "vex.h"
using namespace vex;

int stuckCount = 0;

void DriveWithAutoCorrectForwards(int heading, int speed, int fixspeed, bool CheckStuck){
    if (GpsSensor.heading() < heading + 2 && GpsSensor.heading() > heading -2)
    {
        RightMotors.spin(forward, speed, percent);
        LeftMotors.spin(forward, speed, percent);
    }
    else if (GpsSensor.heading() > heading)
    {
        RightMotors.spin(forward, speed, percent);
        LeftMotors.spin(forward, fixspeed, percent);
    }
    else
    {
        RightMotors.spin(forward, fixspeed, percent);
        LeftMotors.spin(forward, speed, percent);
    }
    // if(IsStuckSensor.value()>= 10&&CheckStuck){
    //     stuckCount++;
    //     if(stuckCount >20){
    //         while(IsStuckSensor.value()<=50){
    //             RightMotors.spin(reverse, 100, percent);
    //             LeftMotors.spin(reverse, 100, percent);
    //         }
    //         stuckCount = 0;
    //     }
    // } 
                
}

void DriveWithAutoCorrectReverse(int heading, int speed, int fixspeed){
    if (GpsSensor.heading() < heading+1 && GpsSensor.heading() > heading-1)
    {
    RightMotors.spin(reverse, speed, percent);
    LeftMotors.spin(reverse, speed, percent);
    }
    else if (GpsSensor.heading() < heading)               
    {
        RightMotors.spin(reverse, speed, percent);
        LeftMotors.spin(reverse, fixspeed, percent);
    }
    else
    {
        RightMotors.spin(reverse, fixspeed, percent);
        LeftMotors.spin(reverse, speed, percent);
    }
}

void GotoLocation(int XorY, int location, int GreaterThanLessThan, int heading,  vex::directionType Direction, int speed, int fixspeed, bool detectStuck){
    if(XorY == 0)
    {
        if(GreaterThanLessThan == 1 && Direction == forward){
            
            while (GpsSensor.xPosition() > location)
            {
                DriveWithAutoCorrectForwards(heading, speed, fixspeed, detectStuck);
            }
        } else if(GreaterThanLessThan<0 && Direction == forward) {
            while (GpsSensor.xPosition() < location)
            {
                DriveWithAutoCorrectForwards(heading, speed, fixspeed, detectStuck);
            }
        } else if(GreaterThanLessThan == 1 && Direction == reverse){
            
            while (GpsSensor.xPosition() > location)
            {
                DriveWithAutoCorrectReverse(heading, speed, fixspeed);
            }
        } else {
            while (GpsSensor.xPosition() < location)
            {
                DriveWithAutoCorrectReverse(heading, speed, fixspeed);
            }
        }
    } else {
        if(GreaterThanLessThan == 1 &&Direction == forward){
            
            while (GpsSensor.yPosition() > location)
            {
                DriveWithAutoCorrectForwards(heading, speed, fixspeed, detectStuck);
            }
        } else if(GreaterThanLessThan < 0 &&Direction == forward){
            while (GpsSensor.yPosition() < location)
            {
                DriveWithAutoCorrectForwards(heading, speed, fixspeed, detectStuck);
            }
        }else if(GreaterThanLessThan == 1 &&Direction == reverse){
            
            while (GpsSensor.yPosition() > location)
            {
                DriveWithAutoCorrectReverse(heading, speed, fixspeed);
            }
        } else {
            while (GpsSensor.yPosition() < location)
            {
                DriveWithAutoCorrectReverse(heading, speed, fixspeed);
            }
        }
    }
}
void TurnToAngle(int heading, int LeftOrRight, int turnspeed, vex::directionType Direction){
    if(LeftOrRight == 1 && Direction == forward){
        
        while (GpsSensor.heading() > heading)
        {
            RightMotors.spin(Direction, 100, percent);
            LeftMotors.spin(Direction, turnspeed, percent);
        }
    }else if (LeftOrRight == -1 && Direction == forward){
        while (GpsSensor.heading() < heading)
        {
            RightMotors.spin(Direction, turnspeed, percent);
            LeftMotors.spin(Direction, 100, percent);
        }
    } else if(LeftOrRight == -1 && Direction == reverse){
        while (GpsSensor.heading() > heading)
        {
            RightMotors.spin(Direction, turnspeed, percent);
            LeftMotors.spin(Direction, 100, percent);
        }
    }else if(LeftOrRight == 1 && Direction == reverse){
        while (GpsSensor.heading() < heading)
        {
            RightMotors.spin(Direction, 100, percent);
            LeftMotors.spin(Direction, turnspeed, percent);
        }
    }
}



