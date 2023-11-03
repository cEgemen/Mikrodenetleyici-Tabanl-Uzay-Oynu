#ifndef Oyun_h
#define Oyun_h
#include "Arduino.h"
#include "Ship.h"
#include "Target.h"
class Oyun{
public:
Oyun();
void insert_Target(byte  syc);
void update_Target();
void del_Target(byte syc);
byte kontrol1();
void kontrol2();
Ship *s;
Target *t;
byte tip;
Target matris [16] [8];
};
#endif