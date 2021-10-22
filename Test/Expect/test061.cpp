#define __SPIN2CPP__
#include <propeller.h>
#include "test061.h"

char test061::dat[] = {
  0x01, 0x02, 0x61, 0x62, 0x63, 0x03, 0x01, 0x00, 0x02, 0x00, 0x61, 0x00, 0x62, 0x00, 0x63, 0x00, 
  0x03, 0x00, 0x00, 0x00, 0x01, 0x00, 0x00, 0x00, 0x02, 0x00, 0x00, 0x00, 0x61, 0x00, 0x00, 0x00, 
  0x62, 0x00, 0x00, 0x00, 0x63, 0x00, 0x00, 0x00, 0x04, 0x00, 0x00, 0x00, 
};
int32_t test061::Getstr(void)
{
  return ((char *)&dat[0])[0];
}

