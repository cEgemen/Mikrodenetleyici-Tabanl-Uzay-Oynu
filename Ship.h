#ifndef Ship_h
#define Ship_h
#include  "Arduino.h"
#include "Silah.h"
class Ship
{
 public :
Ship();
Ship(int x,int y);
void update(int deger);
void update_Silah();
byte can;
Silah silah[3];
  int x;
  int y;
  byte cephane;
};

#endif