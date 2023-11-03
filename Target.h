#ifndef Target_h
#define Target_h
#include "Arduino.h"
class Target{
 public :
Target();
Target(int x,int y,byte type);
void update();
uint8_t hasar;
Target *t;
  byte type;
  int x;
  int y;  
};
#endif