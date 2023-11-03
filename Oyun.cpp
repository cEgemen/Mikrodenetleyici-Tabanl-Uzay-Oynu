#include "Oyun.h"

Oyun::Oyun(){
this->s=new Ship;              
}
void Oyun::insert_Target(byte  syc)
{
  Serial.print("syc= ");
Serial.println(syc);
byte t_say=random(1,4); 
Serial.print("t_say= ");
Serial.println(t_say);
byte t1=random(0,t_say+1);
Serial.print("t1= ");
Serial.println(t1);
byte t2=t_say-t1;
Serial.print("t2= ");
Serial.println(t2);
if(t_say==1){
Serial.println("case 1 for");
byte konum=random(0,8);
Serial.print("konum= ");
Serial.println(konum);
if(t1==1)
{
  matris[syc][konum].t=new Target(konum*8,-8,1);
}
else{
    matris[syc][konum].t=new Target(konum*8,-8,2);
}
}
else if(t_say==2){
byte mod=random(1,4);
Serial.print("mod= ");
Serial.println(mod);
for(int i=0;i<2;i++)
{
Serial.println("case 2 for ");
 byte secim=random(1,3);
 Serial.print("secim= ");
Serial.println(secim);
if(mod==1){
 if((secim==1 && !(t1==0)) || t2==0)
{
  matris[syc][(i+1)*2].t=new Target(((i+1)*2)*8,-8,1);
t1--;
}
else if ((secim==2 && !(t2==0)) || t1==0) {
    matris[syc][(i+1)*2].t=new Target(((i+1)*2)*8,-8,2);
t2--;  
}
Serial.print("t1 say = ");
Serial.println(t1);
Serial.print("t2 say = ");
Serial.println(t2);
}
else if(mod==2){
 if((secim==1 && !(t1==0)) || t2==0)
{
  matris[syc][(i+1)*3].t=new Target(((i+1)*3)*8,-8,1);
t1--;
}
else if ((secim==2 && !(t2==0)) || t1==0) {
    matris[syc][(i+1)*3].t=new Target(((i+1)*3)*8,-8,2);
t2--;  
}
Serial.print("t1 say = ");
Serial.println(t1);
Serial.print("t2 say = ");
Serial.println(t2);
}
else{
  if((secim==1 && !(t1==0)) || t2==0)
{
  matris[syc][i*4].t=new Target((i*4)*8,-8,1);
t1--;
}
else if ((secim==2 && !(t2==0)) || t1==0) {
    matris[syc][i*4].t=new Target((i*4)*8,-8,2);
t2--;  
}
Serial.print("t1 say = ");
Serial.println(t1);
Serial.print("t2 say = ");
Serial.println(t2);
}
}
}
else {
  byte mod=random(1,4);
Serial.print("mod= ");
Serial.println(mod);
for(int i=0;i<3;i++)
{
Serial.println("case 3 for ");
 byte secim=random(1,3);
 Serial.print("secim= ");
Serial.println(secim);
if(mod==1){
 if((secim==1 && !(t1==0)) || t2==0)
{
  matris[syc][i*3].t=new Target((i*3)*8,-8,1);
t1--;
}
else if ((secim==2 && !(t2==0)) || t1==0) {
    matris[syc][i*3].t=new Target((i*3)*8,-8,2);
t2--;  
}
Serial.print("t1 say = ");
Serial.println(t1);
Serial.print("t2 say = ");
Serial.println(t2);
}
else if(mod==2){
 if((secim==1 && !(t1==0)) || t2==0)
{
  matris[syc][i+2+i].t=new Target((i+2+i)*8,-8,1);
t1--;
}
else if ((secim==2 && !(t2==0)) || t1==0) {
    matris[syc][i+2+i].t=new Target((i+2+i)*8,-8,2);
t2--;  
}
Serial.print("t1 say = ");
Serial.println(t1);
Serial.print("t2 say = ");
Serial.println(t2);
}
else if(mod==3){
 if((secim==1 && !(t1==0)) || t2==0)
{
  matris[syc][i+3+i].t=new Target((i+i+3)*8,-8,1);
t1--;
}
else if ((secim==2 && !(t2==0)) || t1==0) {
    matris[syc][i+3+i].t=new Target((i+i+3)*8,-8,2);
t2--;  
}
Serial.print("t1 say = ");
Serial.println(t1);
Serial.print("t2 say = ");
Serial.println(t2);
}
}
}
/*
else{
   byte mod=random(1,3);
Serial.print("mod= ");
Serial.println(mod);
for(int i=0;i<4;i++)
{
Serial.println("case 4 for ");
 byte secim=random(1,2);
 Serial.print("secim= ");
Serial.println(secim);
if(mod==1){
if((secim==1 && !(t1==0)) || t2==0)
{
  matris[syc][2*i].t=new Target((2*i)*8,0,1);
t1--;
}
else if ((secim==2 && !(t2==0)) || t1==0) {
    matris[syc][2*i].t=new Target((2*i)*8,0,2);
t2--;  
}
Serial.print("t1 say = ");
Serial.println(t1);
Serial.print("t2 say = ");
Serial.println(t2);
}
else if(mod==2){
if((secim==1 && !(t1==0)) || t2==0)
{
  matris[syc][i+1+i].t=new Target((i+1+i)*8,0,1);
t1--;
}
else if ((secim==2 && !(t2==0)) || t1==0) {
    matris[syc][i+1+i].t=new Target((i+1+i)*8,0,2);
t2--;  
}
Serial.print("t1 say = ");
Serial.println(t1);
Serial.print("t2 say = ");
Serial.println(t2);
}
}
}
*/
}
byte Oyun::kontrol1(){
for(int i=0;i<16;i++)
{
  for(int j=0;j<8;j++)
  {
      if(!(this->matris[i][j].t==NULL))
      {
            if((this->s->x==this->matris[i][j].t->x) && (this->s->y==this->matris[i][j].t->y)) 
            {
                this->s->can--;
                Serial.print("this->s->can=");
                   Serial.println(this->s->can);
                return   this->s->can;
                
            }       
      }
  }
}
return this->s->can;
}
void Oyun::kontrol2(){
      
     for(int k=0;k<16;k++)
     {
         for(int j=0;j<8;j++)
         {
           if(!(this->matris[k][j].t==NULL)){
            for(int i=0;i<3;i++)
      {
        if(!(this->s->silah[i].s==NULL) && this->s->silah[i].s->active==true)
        {
                      if((this->matris[k][j].t->x==this->s->silah[i].s->x) && (this->matris[k][j].t->y==this->s->silah[i].s->y) || ((this->matris[k][j].t->x==(this->s->silah[i].s->x)) && (this->matris[k][j].t->y==(this->s->silah[i].s->y+8))))
                      {
                              if(this->matris[k][j].t->type==1)
                              {
                                this->matris[k][j].t=NULL;
                              }
                              else{
                               this->matris[k][j].t->hasar++;
                               if(this->matris[k][j].t->hasar==2)
                               {
                                 this->matris[k][j].t=NULL;
                               }

                              }
                          this->s->silah[i].s=NULL;
                      }
        }
      }
         }

         }
       
     }
      
}
void Oyun::update_Target(){
for(int i=0;i<16;i++)
{
  for(int j=0;j<8;j++)
  {
      if((this->matris[i][j].t->type==1) || (this->matris[i][j].t->type==2))
      {
        this->matris[i][j].t->update();
      }
  }
}
}
void Oyun::del_Target(byte syc)
{
for(int i=0;i<8;i++)
{
     this->matris[syc][i].t=NULL;
}

}
