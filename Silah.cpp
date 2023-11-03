#include "Silah.h"

Silah::Silah(){
  this->x=0;
  this->y=0;
  active=false;
}
Silah::Silah(int x, int y){
this->x=x;
this->y=y;
active=false;
}
void Silah::update(){
 this->y-=8; 
}