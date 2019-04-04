//TerOledTwi.ino 190403

#include "TwiOled.h"
#include "PixOled.h"
#include "TerOled.h" 

void setup(){ 
  SetupTwiOled();
  SetupPixOled();
//  DoubleH();
  LiCol(0,0); // 0.8ms
 // Text("Test sur carte Arduino");
 // DelMs(1000);
}
int8_t val=0xFC; int vals=-13; int valss=20123;
void loop() { 
  LiCol(1,20); Text("Oled7654");  
  LiCol(2,0);Bin8(36); Hex16(0x1234); Dec16(19999);
  LiCol(4,0);Bin16(vals); // 4.8ms
  LiCol(5,0);Dec16(valss);Dec16(-valss);  
  LiCol(6,0);Dec16(vals);Dec16(-vals);
  LiCol(7,0);Text("fin");  
  while(1); 
}
