#include <SPI.h>
#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>
#include "Oyun.h"
#include "Target.h"
#define SCREEN_WIDTH 128
#define SCREEN_HEIGHT 64
#define OLED_RESET -1
#define SCREEN_ADDRESS 0x3C

Adafruit_SSD1306 ekran(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, OLED_RESET);

const unsigned char test [512] PROGMEM = {
	0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0x80, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 
	0x80, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 0x9f, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xf9, 
	0x9f, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xf9, 0x98, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x19, 
	0x98, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x19, 0x99, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0x99, 
	0x99, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0x99, 0x99, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0x99, 
	0x99, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0x99, 0x99, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0x99, 
	0x99, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0x99, 0x99, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0x99, 
	0x99, 0xfc, 0x0f, 0x3f, 0xc3, 0xcf, 0x3f, 0x99, 0x99, 0xfc, 0x07, 0x3f, 0x81, 0xcf, 0x3f, 0x99, 
	0x99, 0xfc, 0xe3, 0x3f, 0x18, 0xcf, 0x3f, 0x99, 0x99, 0xfc, 0xf3, 0x3f, 0x3c, 0xcf, 0x3f, 0x99, 
	0x99, 0xfc, 0xf3, 0x3f, 0x3c, 0xcf, 0x3f, 0x99, 0x99, 0xfc, 0xe3, 0x3f, 0x3c, 0xc6, 0x3f, 0x99, 
	0x99, 0xfc, 0x07, 0x3f, 0x3c, 0xe0, 0x7f, 0x99, 0x99, 0xfc, 0x0f, 0x3f, 0x00, 0xf0, 0xff, 0x99, 
	0x99, 0xfc, 0xff, 0x3f, 0x00, 0xf9, 0xff, 0x99, 0x99, 0xfc, 0xff, 0x3f, 0x3c, 0xf9, 0xff, 0x99, 
	0x99, 0xfc, 0xff, 0x03, 0x3c, 0xf9, 0xff, 0x99, 0x99, 0xfc, 0xff, 0x03, 0x3c, 0xf9, 0xff, 0x99, 
	0x99, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0x99, 0x99, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0x99, 
	0x99, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0x99, 0x99, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0x99, 
	0x99, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0x99, 0x99, 0xff, 0xe0, 0x3f, 0xfc, 0x07, 0xff, 0x99, 
	0x99, 0xff, 0xe0, 0x3f, 0xfc, 0x07, 0xff, 0x99, 0x99, 0xff, 0xe7, 0x3f, 0xfc, 0xe7, 0xff, 0x99, 
	0x99, 0xff, 0xe7, 0x3f, 0xfc, 0xe7, 0xff, 0x99, 0x98, 0x1f, 0x00, 0x00, 0x00, 0x00, 0xf8, 0x19, 
	0x98, 0x1c, 0x00, 0x00, 0x00, 0x00, 0x38, 0x19, 0x9f, 0xf8, 0xfc, 0x73, 0xce, 0x1f, 0x1f, 0xf9, 
	0x9f, 0xf1, 0x02, 0x33, 0xcc, 0x61, 0x8f, 0xf9, 0x80, 0x03, 0x03, 0x10, 0x08, 0xc0, 0xc0, 0x01, 
	0x80, 0x07, 0x33, 0x90, 0x09, 0xcc, 0xe0, 0x01, 0xff, 0xc8, 0x30, 0x09, 0x91, 0x0c, 0x33, 0xff, 
	0xff, 0xc8, 0x30, 0x49, 0x92, 0x00, 0x13, 0xff, 0xff, 0xc9, 0xfe, 0x49, 0x92, 0x61, 0x93, 0xff, 
	0xff, 0xc9, 0xfe, 0x49, 0x92, 0x61, 0x93, 0xff, 0xff, 0xc8, 0x30, 0x49, 0x92, 0x00, 0x13, 0xff, 
	0xff, 0xc0, 0x30, 0x49, 0x93, 0x0c, 0x23, 0xff, 0xff, 0xe7, 0x33, 0x99, 0x99, 0xcc, 0xe7, 0xff, 
	0xff, 0xe3, 0x03, 0x19, 0x98, 0xc0, 0xc7, 0xff, 0xff, 0xe1, 0x02, 0x39, 0x9c, 0x61, 0x87, 0xff, 
	0xff, 0xe0, 0x7c, 0x79, 0x9e, 0x3e, 0x07, 0xff, 0xff, 0xe4, 0x00, 0xf9, 0x9f, 0x00, 0x27, 0xff, 
	0xff, 0xcf, 0x03, 0xf9, 0x9f, 0xc0, 0xf3, 0xff, 0xff, 0xcf, 0xff, 0xf9, 0x9f, 0xff, 0xf3, 0xff, 
	0xff, 0xcf, 0xff, 0xf9, 0x9f, 0xff, 0xf3, 0xff, 0xff, 0xcf, 0xff, 0xf8, 0x1f, 0xff, 0xf3, 0xff, 
	0xff, 0xcf, 0xff, 0xc0, 0x03, 0xff, 0xf3, 0xff, 0xff, 0xc7, 0xff, 0x07, 0xe0, 0xff, 0xe3, 0xff, 
	0xff, 0xe7, 0xfe, 0x1f, 0xf8, 0x7f, 0xe7, 0xff, 0xff, 0xe3, 0xfc, 0x7f, 0xfe, 0x3f, 0xc7, 0xff, 
	0xff, 0xf0, 0xf0, 0xff, 0xff, 0x0f, 0x0f, 0xff, 0xff, 0xf8, 0x03, 0xff, 0xff, 0xc0, 0x1f, 0xff, 
	0xff, 0xfe, 0x07, 0xff, 0xff, 0xe0, 0x7f, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff
};

const unsigned char ship [8] PROGMEM = {
	// 'ship4, 8x8px
	0x18, 0x18, 0xa5, 0xbd, 0xff, 0xbd, 0xbd, 0x3c
};
const unsigned char t2 [] PROGMEM = {
	// 't1, 8x8px
	0x18, 0x3c, 0x7e, 0xff, 0xff, 0x7e, 0x3c, 0x18
};
const unsigned char t1 [8] PROGMEM = {
	// 't5, 8x8px
	0x00, 0x08, 0x1c, 0x3e, 0x7c, 0x38, 0x10, 0x00
};
const unsigned char silah2 [8] PROGMEM = {
	// 'silah2, 8x8px
	0xc3, 0xc3, 0xc3, 0xc3, 0x00, 0x00, 0x00, 0x00
};
Oyun oyun;
int buzzer_pin=2;
int deger=0;
int deger2=0;
bool tus = true;
bool zorluk = false;
bool active = false;
void giris();
void page1();
void page2();
void page3();
void option();
void select();
void LDR();
void ledler();
void ledler2();
void ship_move();
void draw_Target();
void draw_Ship();
void draw_Silah();
void can_kontrol();
void atis();
int page = -1;
int up = -1;
int down = -1;
int ok = -1;
int at=-1;
byte imlec_x = 0;
byte imlec_y = 16;
int seviye = -1;
byte ses = 50;
bool sesOn = false;
byte parlaklik = 150;
bool parlaklikOn = false;
bool click1 = false, click2 = false, click3 = false;
bool click4=1,click5=false;
byte giris1 = 0, giris2 = 0,syc=0;
int syc1=0,syc2=0;
long end1=0,end2=0,start=0;
// end1 ve end2 == zaman kontrolü için
// syc == satır numarası
// syc1 ve syc2 == hasar yemeye başlama süresi kontolü için
void setup() {
  Serial.begin(9600);

  if(!ekran.begin(SSD1306_SWITCHCAPVCC, SCREEN_ADDRESS)) {
    Serial.println(F("SSD1306 allocation failed"));
    for(;;);
  }
  ekran.clearDisplay();
   ekran.setTextSize(1);
   ekran.setTextColor(WHITE);
     pinMode(11,INPUT_PULLUP);//onay
    pinMode(12,INPUT_PULLUP);//asagı
    pinMode(13,INPUT_PULLUP);//yukarı
    pinMode(10,INPUT_PULLUP); //ates  
pinMode(26,OUTPUT);  //can
pinMode(27,OUTPUT);  //can
pinMode(28,OUTPUT);  //can
pinMode(22,OUTPUT);  //silah
pinMode(23,OUTPUT);  //silah
pinMode(24,OUTPUT);  //silah
pinMode(buzzer_pin,OUTPUT);  // buzzer
ekran.setRotation(1);
    ekran.display();
}
void loop() {
  // put your main code here, to run repeatedly:
/*up = digitalRead(13);
  down = digitalRead(12);
  ok = digitalRead(11);

  if (up == 0 && tus == true) {
    click1 = true;
    tus == false;
  }
  if (down == 0 && tus == true) {
    click2 = true;
    tus = false;
  }
  if (ok == 0 && tus == true) {
    click3 = true;
    tus = false;
  }
  if (page == -1) {
    giris();
  }
  if (page == 1) {
    page1();
  } else if (page == 2) {
    page2();
  } else if (page == 3) {
    page3();
  } else if (page == 4) {
    page4();
  }
  */
  page3();
}
void ledler2()
{
   if(oyun.s->cephane==3)
  {
    digitalWrite(22,HIGH);
    digitalWrite(23,HIGH);
    digitalWrite(24,HIGH);
  }
  else if(oyun.s->cephane==2)
  {
     digitalWrite(22,HIGH);
    digitalWrite(23,HIGH);
    digitalWrite(24,LOW);
  }
  else if(oyun.s->cephane==1)
  {
     digitalWrite(22,HIGH);
    digitalWrite(23,LOW);
    digitalWrite(24,LOW);
  }
  else{
     digitalWrite(22,LOW);
    digitalWrite(23,LOW);
    digitalWrite(24,LOW);
  }
}
void ledler()
{
  if(oyun.s->can==3)
  {
    digitalWrite(28,HIGH);
    digitalWrite(27,HIGH);
    digitalWrite(26,HIGH);
  }
  else if(oyun.s->can==2)
  {
     digitalWrite(28,HIGH);
    digitalWrite(27,HIGH);
    digitalWrite(26,LOW);
  }
  else if(oyun.s->can==1)
  {
     digitalWrite(28,HIGH);
    digitalWrite(27,LOW);
    digitalWrite(26,LOW);
  }
  else{
     digitalWrite(28,LOW);
    digitalWrite(27,LOW);
    digitalWrite(26,LOW);
  }
}
void LDR()
{
deger=analogRead(A0);
Serial.println(deger);
if(deger<500)
{
  ekran.invertDisplay(true);
}
else{
  ekran.invertDisplay(false);
}
}
void option() {
  if (click1 == true && up == 1) {
    ekran.clearDisplay();

    if (!(imlec_y == 16) && !(sesOn == true || parlaklikOn == true)) {
      imlec_y -= 16;
    } else if (page == 4 && sesOn == true) {
      ses += 10;
      if ((ses >= 100))
        ses = 100;
    } else if (page == 4 && parlaklikOn == true) {
      parlaklik += 30;
      if ((parlaklik >= 255))
        parlaklik = 255;
    }
    click1 = false;
    tus = true;
  }
  if (click2 == true && down == 1) {
    ekran.clearDisplay();
    if (!(imlec_y == 48) && !(sesOn == true || parlaklikOn == true)) {
      imlec_y += 16;
    } else if (page == 4 && sesOn == true) {
      ses -= 10;
      if ((ses <= 0))
        ses = 0;
    } else if (page == 4 && parlaklikOn == true) {
      parlaklik -= 30;
      if ((parlaklik <= 0))
        parlaklik = 0;
    }
    click2 = false;
    tus = true;
  }
}
void giris() {
  ekran.setCursor(0, 60);
  ekran.println("Yukleniyor");
  ekran.drawRect(0, 72, 63, 16, WHITE);
  for (int i = 1; i <= 62; i++) {
    ekran.drawLine(i, 72, i, 88, WHITE);
    delay(30);
    LDR();
    ekran.display();
  }
  delay(50);
  ekran.clearDisplay();
  int syc = 0;
  while (page == -1) {
    LDR();
    ekran.clearDisplay();
    ekran.drawBitmap(0, 0, test, 64, 64, 1);
    ekran.setCursor(20, 75);
    ekran.print("Press");
    ekran.setCursor(20, 84);
    ekran.print("Button");
    ekran.display();
    ok = digitalRead(11);
    if (ok == 0 && tus == true) {
      click3 = true;
      tus = false;
    }
    select();
  }
  ekran.clearDisplay();
}
void select() {
  if (click3 == true && ok == 1) {
    if (page == -1) {
      page = 1;
      click3 = false;
      tus = true;
    } else {
      if (imlec_y == 16) {
        if (page == 1 && zorluk == true) {
          ekran.clearDisplay();
          page = 3;
          imlec_x = 0;
          imlec_y = 16;
          click3 = false;
          tus = true;
        } else if (page == 2) {
          seviye = 1;
          zorluk = true;
          click3 = false;
          tus = true;
        } else if (page == 4) {
          ekran.invertDisplay(true);
          parlaklikOn = true;
          click3 = false;
          tus = true;
          giris2++;
          if (giris2 == 2) {
            ekran.invertDisplay(false);
            parlaklikOn = false;
            giris2 = 0;
          }
        } else {
          click3 = false;
          tus = true;
        }
      } else if (imlec_y == 32) {
        if (page == 1) {
          ekran.clearDisplay();
          page = 2;
          imlec_x = 0;
          imlec_y = 16;
          click3 = false;
          tus = true;
        } else if (page == 2) {
          seviye = 2;
          zorluk = true;
          click3 = false;
          tus = true;
        } else if (page == 4) {
          sesOn = true;
          click3 = false;
          tus = true;
          giris1++;
          if (giris1 == 2) {
            sesOn = false;
            giris1 = 0;
          }
        }
      } else if (imlec_y == 48) {
        if (page == 1) {
          ekran.clearDisplay();
          page = 4;
          imlec_x = 0;
          imlec_y = 16;
          click3 = false;
          tus = true;
        } else if (page == 2) {
          ekran.clearDisplay();
          page = 1;
          imlec_x = 0;
          imlec_y = 16;
          click3 = false;
          tus = true;
        } else if (page == 4) {
          ekran.clearDisplay();
          sesOn = false;
          parlaklikOn = false;
          page = 1;
          imlec_x = 0;
          imlec_y = 16;
          click3 = false;
          tus = true;
        }
      }
    }
  }
}
void page1() {
  ekran.setCursor(20, 0);
  ekran.print("Menu");
  ekran.setCursor(13, 16);
  ekran.print("Oyna");
  ekran.setCursor(13, 32);
  ekran.print("Zorluk");
  ekran.setCursor(13, 48);
  ekran.print("Ayarlar");
  ekran.setCursor(imlec_x, imlec_y);
  ekran.print(">");
  ekran.drawRect(10, imlec_y - 5, 127, 18, WHITE);
  ekran.display();
  LDR();
  option();
  select();
    ekran.clearDisplay();  
}
void page2() {
  ekran.setCursor(20, 0);
  ekran.print("Zorluk");
  ekran.setCursor(13, 16);
  ekran.print("Normal");
  ekran.setCursor(13, 32);
  ekran.print("Zor");
  ekran.setCursor(13, 48);
  ekran.print("Cikis");
  ekran.setCursor(imlec_x, imlec_y);
  ekran.print(">");
  ekran.drawRect(10, imlec_y - 5, 127, 18, WHITE);
  ekran.display();
  LDR();
  option();
  select();
  ekran.clearDisplay();  
}
void ship_move()
{
  deger2=analogRead(A1);
  deger2=map(deger2,0,1023,0,56);
  if((deger2 % 8)==0)
  {
    oyun.s->update(deger2);
  Serial.println(deger2);
  }
  else{
    byte kalan=deger2%8;
    if(kalan<=4)
    {
      deger2=deger2-kalan;
      oyun.s->update(deger2);
    Serial.println(deger2);   
    }
    else{
  deger2=deger2+(8-kalan);
  oyun.s->update(deger2);
    Serial.println(deger2);        
    }
  }
}
void draw_Ship(){
  ekran.drawBitmap(oyun.s->x,120,ship,8,8,WHITE);
  Serial.print("ship_x= ");
  Serial.println(oyun.s->x);
}
void draw_Target(){
  int x=0;
   for(int i=0;i<16;i++)
{
  for(int j=0;j<8;j++)
  {
    if(!(oyun.matris[i][j].t==NULL)){
        if(oyun.matris[i][j].t->type==1){
          ekran.drawBitmap(oyun.matris[i][j].t->x,oyun.matris[i][j].t->y,t1,8,8,WHITE); 
          x++;
      }
      else if(oyun.matris[i][j].t->type==2){
          ekran.drawBitmap(oyun.matris[i][j].t->x,oyun.matris[i][j].t->y,t2,8,8,WHITE); 
         x++;
      }
    }
}
}
Serial.print("x= ");
Serial.println(x);
}
void can_kontrol(){
     Serial.print("click4= ");
        Serial.println(click4);
   if(click4==true)
 {
   Serial.println("click4 true ve if ici= ");
   byte tmp=oyun.s->can;
   Serial.print("tmp= ");
Serial.println(tmp);
   byte  tmp2=oyun.kontrol1();
   Serial.print("tmp2= ");
Serial.println(tmp2);
   if(!(tmp==tmp2)){
   digitalWrite(buzzer_pin,HIGH);
     if(tmp2==0)
     {
       delay(100);
       digitalWrite(buzzer_pin,LOW);
delay(200);
       digitalWrite(buzzer_pin,HIGH);
       delay(300);
       digitalWrite(buzzer_pin,LOW);       
      click4=false;     
      syc1=0;
   syc2=0;
   ekran.print("OYUN BİTTİ");
   page=1;
  ekran.display();
  ekran.clearDisplay();
  return;
     }
      syc1=0;
   syc2=0;
    ekran.println("click4 falsee");
   click4=false;
      delay(100);
       digitalWrite(buzzer_pin,LOW);
   }
 }
 else
    Serial.println("click4 false galiba");
}
void atis()
{
 /*  at=digitalRead(10);
       Serial.print("at= ");
     Serial.println(at);
         Serial.print("click5 basta= ");
     Serial.println(click5);
   if(click5==false && at==0)
{
  click5=true;
      Serial.print("click5 true oldu= ");
     Serial.println(click5);
}
*/
 if(click5==true && at==1 && !(oyun.s->cephane==0))
 {
         Serial.println("atıs yapıldı= ");
        oyun.s->silah[3-oyun.s->cephane].s->x=oyun.s->x;
        oyun.s->silah[3-oyun.s->cephane].s->y=oyun.s->y;
         oyun.s->silah[3-oyun.s->cephane].s->active=true;
        click5=false;
        oyun.s->cephane--;
 }
}
void draw_Silah()
{
   for(int i=0;i<3;i++)
   {
      if(!(oyun.s->silah[i].s==NULL)   &&  (oyun.s->silah[i].s->active==true))
{
  ekran.drawBitmap(oyun.s->silah[i].s->x,oyun.s->silah[i].s->y,silah2,8,8,WHITE); 
}      
   }
}
void page3(){
  while(page==-1){
    at=digitalRead(10);
    Serial.print("at deger= ");
    Serial.println(at);
      if(click5==false && at==0)
{
  click5=true;
}
    atis();
  start=millis();
  ledler();
 ledler2();
LDR();
  if(start-end2>=60){
     Serial.print("at2 deger= ");
    Serial.println(at);
    atis();
  syc1++;
     Serial.print("syc1= ");
     Serial.println(syc1);
     if(click4==false && syc1==50)
      {
         Serial.println("click4 truee");
        syc1=0;
        click4=true;
      }       
  //  draw_Target();
    draw_Silah();  
    ship_move();
  draw_Ship();
ekran.display();
can_kontrol();
    ekran.clearDisplay();  
      end2=start;
        start=millis();
  }
  if(start-end1>=500)
  {
     Serial.print("at3 deger= ");
    Serial.println(at);
    atis();
    syc2++;
     Serial.print("syc2= ");
     Serial.println(syc2);
    if(click4==false && syc2==3)
    {
     Serial.println("click4 true");
      click4=true;
      syc2=0;
    }
//  oyun.del_Target(syc);      
 //   oyun.insert_Target(syc);
 // oyun.update_Target();
    oyun.s->update_Silah();
    oyun.kontrol2();
  //      draw_Target();
    draw_Silah();
     syc++;
  if(syc==16)
  {
    syc=0;
  }
     draw_Ship();
    ekran.display();
can_kontrol();
     ekran.clearDisplay(); 
         end1=start;
          start=millis();
  }
  }
}
void page4() {
  ekran.setCursor(20, 0);
  ekran.print("Ayarlar");
  ekran.setCursor(13, 16);
  ekran.print("Isik");
  ekran.setCursor(40, 16);
  String parlak = String(parlaklik);
  ekran.print(parlak);
  ekran.setCursor(13, 32);
  ekran.print("Ses");
  ekran.setCursor(53, 32);
  ekran.print("%");
  ekran.setCursor(40, 32);
  String s = String(ses);
  ekran.print(s);
  ekran.setCursor(13, 48);
  ekran.print("Cikis");
  ekran.setCursor(imlec_x, imlec_y);
  ekran.print(">");
  ekran.drawRect(10, imlec_y - 5, 127, 18, WHITE);
  ekran.display();
  LDR();
  option();
  select();
  ekran.clearDisplay();  
}