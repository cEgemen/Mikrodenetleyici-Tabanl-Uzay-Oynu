#include "Target.h"
Target::Target(){
   hasar=0;
   x=0;
   y=0;
type=0;
t=NULL;
}
Target::Target(int x,int y,byte type)
{
this->x=x;
this->y=y;
hasar=0;
this->type=type;
t=NULL;
}
void Target::update(){
     y+=8;
}
