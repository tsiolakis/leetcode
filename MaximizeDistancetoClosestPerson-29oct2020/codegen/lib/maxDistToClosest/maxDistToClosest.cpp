//
// File: maxDistToClosest.cpp
//
// MATLAB Coder version            : 4.0
// C/C++ source code generated on  : 29-Oct-2020 22:18:13
//

// Include Files
#include <cmath>
#include "rt_nonfinite.h"
#include "maxDistToClosest.h"

// Function Definitions

//
// Arguments    : const emxArray_real_T *seats
// Return Type  : double
//
double maxDistToClosest(const emxArray_real_T *seats)
{
  double maxDist;
  int lastCoronaSeat;
  int i;
  boolean_T exitg1;
  int b_lastCoronaSeat;
  int i0;
  unsigned int b_i;
  lastCoronaSeat = 1;
  maxDist = 0.0;
  i = 0;
  exitg1 = false;
  while ((!exitg1) && (i <= seats->size[1] - 1)) {
    if (seats->data[i] == 1.0) {
      lastCoronaSeat = 1 + i;
      maxDist = (1.0 + (double)i) - 1.0;
      exitg1 = true;
    } else {
      i++;
    }
  }

  b_lastCoronaSeat = lastCoronaSeat;
  i0 = seats->size[1] - lastCoronaSeat;
  for (i = 0; i <= i0; i++) {
    b_i = (unsigned int)b_lastCoronaSeat + i;
    if (seats->data[(int)b_i - 1] == 1.0) {
      if (std::floor((double)((int)b_i - lastCoronaSeat) / 2.0) > maxDist) {
        maxDist = std::floor((double)((int)b_i - lastCoronaSeat) / 2.0);
      }

      lastCoronaSeat = (int)b_i;
    }
  }

  if ((seats->data[seats->size[1] - 1] == 0.0) && (seats->size[1] -
       lastCoronaSeat > (int)maxDist)) {
    maxDist = seats->size[1] - lastCoronaSeat;
  }

  return maxDist;
}

//
// File trailer for maxDistToClosest.cpp
//
// [EOF]
//
