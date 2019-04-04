// TerOled.h    ref 190326 
// TerOled need before TwiOledh/BcXxOled.h et PixOled.h ou MapOled.h
// dans pp  #include "TerOled.h"  pas de setup spécifique
// Compatible to TerSer.h in the default mode Do not have Compact and 
// Replace TerNum.h    Big/double size) not available
// differences with TerSer  TetGet TerEcho TabCar
byte moz=0;
#define HideZ() moz=0  // Spaces mode of TerSer
#define ShowZ() moz=1  // Zeros mode of TerSer

#define TerCar Car  // car défini dans OledPix

void TerText(const char str[]) {
   for (byte i=0; i< strlen(str); i++) {
      TerCar(str[i]);
   }
}
void TtBin8 (byte bb) {
  for (byte i=0;i<8;i++) {
     if (bb&0x80) TerCar('1');
     else TerCar('0');
     bb <<= 1;
  }
}
void TerBin8 (byte bb) {
  TtBin8 (bb);
  TerCar(' ');
}
void TerBin16 (uint16_t bb) {
 TtBin8 (bb>>8);
  TerCar('.');
 TtBin8 (bb&0xFF);
 TerCar(' ');
}
char TerConvNibble (byte nn) { // converti 4 bit hexa en Ascii
  byte cc;
  if (nn<10) {cc = nn + '0';}
  else {cc = nn-10 + 'A';}
  return cc;
}
void TerHex8 (byte hh) {
  byte cc;
  cc = TerConvNibble (hh >> 4) ; // ne modifie pas hh
  TerCar(cc);
  cc = TerConvNibble (hh & 0x0F) ; 
  TerCar(cc);
  TerCar(' '); // space
}
void TerHex16 (uint16_t hh) {
  byte cc;
  cc = TerConvNibble (hh >> 12) ;   TerCar(cc);
  cc = TerConvNibble ((hh >> 8)&0x0F) ; TerCar(cc);
  cc = TerConvNibble ((hh >> 4)&0x0F) ; TerCar(cc);
  cc = TerConvNibble ((hh     )&0x0F) ;   TerCar(cc);
  TerCar(' ');
}

// espace pour zéros non sig // moz=1 affiche zero et pas espace
#define Afzs if(moz){cc='0';}else{cc=' ';}
void TerHex12 (uint16_t hh) {
  byte cc; byte afz=0;
  cc = TerConvNibble ((hh >> 8)&0x0F); 
    if (cc>48) {afz=1;} else {Afzs;}  TerCar(cc);
  cc = TerConvNibble ((hh >> 4)&0x0F) ;
    if ((cc>48)|(afz)){afz=1;} else {Afzs;} TerCar(cc);
  cc = TerConvNibble (hh & 0x0F) ;   TerCar(cc);
  TerCar(' ');
}
void TerHex20 (uint32_t hh) {
  byte cc; byte afz=0;
  cc = TerConvNibble ((hh >> 16)&0x0F) ; 
    if (cc>48) {afz=1;} else {Afzs;}  TerCar(cc);
  cc = TerConvNibble ((hh >> 12)&0x0F) ; 
    if ((cc>48)|(afz)){afz=1;} else {Afzs;} TerCar(cc);
  cc = TerConvNibble ((hh >> 8 )&0x0F) ;  
    if ((cc>48)|(afz)){afz=1;} else {Afzs;} TerCar(cc);
  cc = TerConvNibble ((hh >> 4 )&0x0F) ;  
    if ((cc>48)|(afz)){afz=1;} else {Afzs;} TerCar(cc);
  cc = TerConvNibble (hh &       0x0F) ;   TerCar(cc);
  TerCar(' ');
}
void TerHex32 (uint32_t hh) {
  byte cc;
  
  cc = TerConvNibble ((hh >> 28)&0x0F) ; TerCar(cc);
  cc = TerConvNibble ((hh >> 24)&0x0F) ; TerCar(cc);
  cc = TerConvNibble ((hh >> 20)&0x0F) ; TerCar(cc);
  cc = TerConvNibble ((hh >> 16)&0x0F) ; TerCar(cc);
  cc = TerConvNibble ((hh >> 12)&0x0F) ;   TerCar(cc);
  cc = TerConvNibble ((hh >> 8)&0x0F) ; TerCar(cc);
  cc = TerConvNibble ((hh >> 4)&0x0F) ; TerCar(cc);
  cc = TerConvNibble ((hh     )&0x0F) ;   TerCar(cc);
  TerCar(' ');
}  
uint16_t TerBinDec8 (uint8_t bb) {
  uint16_t dd=0;
   for (byte i=0; i<8; i++) {
    if ((dd & 0x0F)>0x04) {dd += 0x03;}
    if ((dd & 0xF0)>0x40) {dd += 0x30;}
    dd=dd<<1;
    if ((bb & 0x80)) {dd += 1;}  //inject bit
    bb=bb<<1; // prepare next bit
  }
  return dd;
}
#define TerDec8(v)                 \
    do { typeof(v) _v = -1;        \
      if (_v < 0) { TerDec8s(v); } \
       else { TerDec8u(v); }       \
    } while(0);

void TerDec8u (uint8_t hh) {
  TerHex12(TerBinDec8(hh));
}

void TerDec8s (int8_t hh) {
  if (hh<0) {  // négatif
    TerCar('-'); hh = -hh;
  } else {
    TerCar('+');
  }
  TerHex12(TerBinDec8(hh));
}

uint32_t BinDec16 (uint16_t bb) { 
  uint32_t dd=0;
  for (byte i=0; i<16 ; i++) {
    if ((dd & 0x000F)>0x0004) {dd += 0x0003;}
    if ((dd & 0x00F0)>0x0040) {dd += 0x0030;}
    if ((dd & 0x0F00)>0x0400) {dd += 0x0300;}
    if ((dd & 0xF000)>0x4000) {dd += 0x3000;}
      dd=dd<<1;
      if ((bb & 0x8000)) {dd += 1; }  //inject bit
      bb<<=1; // prepare next bit
  }
  return dd;
}

#define TerDec16(v)                \
    do { typeof(v) _v = -1;         \
      if (_v < 0) { TerDec16s(v); } \
       else { TerDec16u(v); }       \
    } while(0);
    
void TerDec16u (uint32_t hh) {  // 
  TerHex20(BinDec16(hh));
}

void TerDec16s (int16_t hh) {  // signé
  if(hh<0) {  // negatif
    TerCar('-'); hh = -hh;
  } else {
    TerCar('+'); 
  }
  TerHex20(BinDec16(hh));
}



