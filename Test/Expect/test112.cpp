// test for org and label interaction
#define __SPIN2CPP__
#include <propeller.h>
#include "test112.h"

unsigned char test112::dat[] = {
  0x70, 0x00, 0x00, 0x00, 0x03, 0x00, 0x00, 0x00, 0x71, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
  0x01, 0x00, 0x00, 0x00, 
};
int32_t test112::Me(void)
{
  return ((int32_t *)&dat[12])[0];
}

