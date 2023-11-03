#include "Ship.h"
Ship::Ship(){
   can=3;
   x=32;
   y=120;
   for(int i=0;i<3;i++)
   {
     this->silah[i].s=new Silah;
   }
   cephane=3;
}
Ship::Ship(int x,int y)
{
this->x=x;
this->y=y;
can=3;
cephane=3;
   for(int i=0;i<3;i++)
   {
        this->silah[i].s=new Silah;

   }
}
void Ship::update_Silah()
{
  for(int i=0;i<3;i++)
  {
    if(!(this->silah[i].s==NULL) && this->silah[i].s->active==true)
    {
this->silah[i].s->update();
    if(this->silah[i].s->y<0)
    {
this->silah[i].s=NULL;
   }      
    }
  }
}
void Ship::update(int deger){
     x=deger;
}
