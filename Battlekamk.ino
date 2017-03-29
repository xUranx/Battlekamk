//#include <ArduinoSTL.h> // includaa vactorit yms.yms

#include "Defines.h"
#include "S1D13700.h"
#include "Joystick.h"
#include "MenuHandler.h"
#include "Pictures.h"
#include "PrintHex.h"
enum MENUSTATE 
{
 MAIN,PVP,AI,BOAT
};


Joystick _stick;
S1D13700 LCD;
PrintHex hexx;
int next = 0;

void setup() {
	Serial.begin(9600);
    LCD.initLCD();
    LCD.clearText();
    LCD.clearGraphic();
}



void loop() 
{
	Joystick _stick;
	MenuHandler menus(&LCD,&_stick);
	menus.initClasses();
	menus.menuLoop();

	
	
}


