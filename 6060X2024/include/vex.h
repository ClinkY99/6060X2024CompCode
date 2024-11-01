#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "v5.h"
#include "v5_vcs.h"

#include "robot-config.h"
#include "AutonSkills.h"
#include "Functions.h"
#include "AutonRegularBlue.h"
#include "AutonRegularRed.h"

#define waitUntil(condition)                                                   \
  do {                                                                         \
    wait(5, msec);                                                             \
  } while (!(condition))"

#define repeat(iterations)                                                     \
  for (int iterator = 0; iterator < iterations; iterator++)