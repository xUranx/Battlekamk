//#include <ArduinoSTL.h> // includaa vactorit yms.yms

#include "Defines.h"
#include "S1D13700.h"
#include "Joystick.h"
#include "MenuHandler.h"
#include "Pictures.h"// do we need?
#include "PrintHex.h"// do we need?
#include "Grid.h"
#include "Game.h"
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
	Grid _grid;	//this runs constantly in memory
	for (;;)
	{
#if DEBUG == 0
		Serial.println("Menus created");
#endif // DEBUG = 0
		MenuHandler *menus = new MenuHandler(&LCD, &_stick, &_grid); // we dont need menus in memory constantly so we delete it before game loop and create it when we need it
		menus->initClasses();
		int state = menus->menuLoop();
		delete menus;
		_grid.normalize();
#if DEBUG == 0
		Serial.println("Game loop started");
		Game *games = new Game(&LCD,_grid,&_stick);
		if (state == 0)
		{
		games->gameloop(States::PVP);
		}
		else
		{
		games->gameloop(States::AI);
		}
#endif // DEBUG = 0
	// go to game loop
	}
	/*if (_stick.Button())
	{
		LCD.textGoTo(20, 20);
		char buf[] = { "test" };
		LCD.writeText(buf);
		delay(2000);
	}*/
	
}


