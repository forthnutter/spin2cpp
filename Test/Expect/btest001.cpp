// this is a comment
//
// and this is a comment too
#define __SPIN2CPP__
#include <propeller.h>
#include "btest001.h"

int32_t btest001::sum_I(int32_t re, int32_t y_I)
{
  remainder = y_I;
  return (re + y_I);
}

