#ifndef Silah_h
#define Silah_h
#include "Arduino.h"

class Silah{
public :
Silah();
Silah(int x ,int y);
void update();
const uint8_t damage=1;
int x;
int y;
Silah *s;
bool active;
};



#endif 