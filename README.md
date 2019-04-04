##  TerOled, a Serial Terminal for OledSSD1306
##  Compatible with TerSer, the Serial.begin killer
##  More compact and easy to us than anything you can do with Adafruit GFX

![Oledscreen](docs/TerOled.jpg?raw=True "Oled Screen")


##  TerOled, a Serial Terminal for OledSSD1306

### The new xxOled.h family of files follows the logic of the construction of your application. The SSD1306 must be connected on 2 pins. If you use the I2C pins on AVR328, load  TwiOled.h. If other pins adapt the BitBang file Bb7654Oled.h - 10 lines to understand and change. Next you need the Oled setup, a charater generator and the primitives to write numbers and texts: load the PixOled.h; it also set dots for simple graphics. 
### Add the TerOled.h  compatible with the SerOled that replace the Arduino Serial.print terminal. This will cost you only 2  kbytes of memory and 80 bytes of variable.


## How to handle SSD 1306 with 128x32 format?
### Add two lines at the end of setup _SetupOledMap()_ or _SetupOledPix()_ in order to be compatible with 32 lines.
 ####   Cmd (0xDA);
 ####   Cmd (0x02);
### Now the text lines are numbered 4,5,6,7. No guarantie is given for what happen on lines 0,1,2,3 and for dots with y>32.
### Functions are DoubleH(); - for 128x32,  SingleH(); back to 128x64. If you have access to SSD1306 low level doc, play with Cmd() to scroll and do other tricks.

## Not convinced? See See __[TerSer and TerOled Compare][2]__ 
## __[Detailed doc (4 pages) TerOled.pdf ][1]__
## You like a zip file ready to load under Arduino - Sketch - Add a zip file? __[It's here][4]__
## Oled fan?
### Since 2016, we documented many Oled applications, see __[our  Oled doc][3]__ , mostly in french and in need to be updated (check the date at the bottom)
[1]: http://www.didel.com/TerOled.pdf
[4]: http://www.didel.com/TerOled.zip
[2]: http://www.didel.com/TerCompare.pdf
[3]: http://www.didel.com/Oled.html