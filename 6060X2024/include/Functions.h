using namespace vex;

void GotoLocation(int XorY, int location, int GreaterThanLessThan, int heading,  vex::directionType Direction, int speed = 100, int fixspeed=70, bool detectStuck = false);

void TurnToAngle(int heading, int LeftOrRight, int turnspeed, vex::directionType Direction);