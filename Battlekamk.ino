//#include <ArduinoSTL.h> // includaa vactorit yms.yms
#include "Defines.h"
#include "S1D13700.h"
#include "menu.h"
#include "Joystick.h"

enum MENUSTATE 
{
 MAIN,PVP,AI,BOAT
};


Joystick _stick;
S1D13700 LCD;
int next = 0;

void setup() {
	Serial.begin(9600);
    LCD.initLCD();
    LCD.clearText();
    LCD.clearGraphic();
}

void menuChoice(menu &main);

void loop() 
{

	menu main(_stick, LCD);
	next = main.startMenu();
	for (;;)
	{
	menuChoice(main);
	}
	
  
}
void menuChoice(menu &main)
{
	switch (next)
	{
	case 'PVP':
		//next =
		break;
	case 'AI':
		//next =
		break;
	case 'BOAT':
		//next =
		break;
	case 'MAIN':
		next = main.startMenu();
		break;
	}
}

