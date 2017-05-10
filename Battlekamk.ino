//#include <ArduinoSTL.h> // includaa vactorit yms.yms

#include "Defines.h"
#include "S1D13700.h"
#include "Joystick.h"
#include "MenuHandler.h"
#include "Pictures.h"// do we need?
#include "PrintHex.h"// do we need?
#include "particle.h"//we dont need
#include "Grid.h"
#include "Game.h"
//#include "EEPROM\src\EEPROM.h"
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

int freeRam()
{
	extern int __heap_start, *__brkval;
	int v;
	return (int)&v - (__brkval == 0 ? (int)&__heap_start : (int)__brkval);
}

void loop() 
{
	particle p(&LCD);
	//Serial.println("raining");
	p.rain();
	Joystick _stick;
	Grid _grid;	//this runs constantly in memory
#if DEBUG == 0
	int mem = freeRam();
	//particle p(&LCD);
	//p.Explode(5, 5);
	Serial.print("CURREN MEMORY ");

	Serial.println(mem);
#endif // DEBUG = 0
	for (;;)
	{
#if DEBUG == 0
		Serial.println("Menus created");
#endif // DEBUG = 0
		MenuHandler menus(&LCD, &_stick, &_grid); // we dont need menus in memory constantly so we delete it before game loop and create it when we need it
		menus.initClasses();
		int state = menus.menuLoop();
#if DEBUG == 0
		int mem = freeRam();
		Serial.print("CURREN MEMORY ");

		Serial.println(mem);
#endif // DEBUG = 0
		//delete menus;
		_grid.normalize();
#if DEBUG == 0
		Serial.println("Game loop started");
#endif // DEBUG = 0
		Game *games = new Game(&LCD,_grid,&_stick);
		if (state == 0)
		{
		games->gameloop(States::PVP);
		}
		else
		{
		games->gameloop(States::AI);
		}
	}

	
}


