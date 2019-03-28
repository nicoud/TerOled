##  TerSer  PixOled, etc 



![Oled screen](/GenCar.jpg)

##  temporary file

### The new xxOled.h family of files follows the logic of the construction of your application. The SSD1306 must be connected on 2 pins. If you use the I2C pins on AVR328, load  TwiOled.h. If other pins adapt the BitBang file Bb7654Oled.h - 10 lines to understand and change. Next you need the Oled setup, the charater generator and the possibility to write texts: load the PixOled.h or the MapOled function; it allows to put text and dots. 
### Add the TerOed.h  compatible with the SerOled that replace the Arduino Serial.print terminal. This will cost you only 2 to 3 kbytes of memory and 80 bytes of variable.


#### SSD 1306 with 128x32 format
Add two lines at the end of setup _SetupOledMap()_ or _SetupOledPix()_ in order to be compatible with 32 lines.
    Cmd (0xDA);
    Cmd (0x02);
But now the text lines are numbered 4,5,6,7. No guarantie is given for what happen on lines 0,1,2,3 and for dots with y>32.
Two functions are available now: DoubleH(); - for 128x32,  SingleH(); back to 128x64.

[1]: http://www.didel.com/OledLib.pdf
[2]: http://www.didel.com/OledFunctions.pdf
[3]: http://www.didel.com/OledI2C.pdf
[4]: http://www.didel.com/OledTerminal.pdf
[5]:  http://www.didel.com/OledPix.h.pdf
[6]:  http://www.didel.com/OledMap.h.pdf
[7]: http://www.didel.com/Oled.html