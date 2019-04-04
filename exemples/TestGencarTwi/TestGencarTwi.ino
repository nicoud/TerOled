//TestGenCar.ino  
#include "TwiOled.h"
#include "PixOled.h"
void setup(){ SetupTwiOled(); SetupPixOled();}

void loop(){
  Clear(); 
  LiCol (0,0); for (byte i= 32; i<48; i++) Car(i);  // Espace, signes 
  LiCol (1,0); for (char i= 48; i<64; i++) Car(i);  // 0 1 2 3 ...
  LiCol (2,0); for (char i= 64; i<80; i++) Car(i);  // @ A B C ... 
  LiCol (3,0); for (char i= 80; i<96; i++) Car(i);  // P Q R S ...
  LiCol (4,0); for (char i= 96; i<112; i++) Car(i); // ` a b c ...
  LiCol (5,0); for (byte i= 112; i<128; i++) Car(i);// p q r s ...
  
  LiCol (7,80); Sprite(didel);
  while (1);
}

  
