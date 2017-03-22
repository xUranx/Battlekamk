//#include <ArduinoSTL.h> // includaa vactorit yms.yms

#include "Defines.h"
#include "S1D13700.h"
#include "menu.h"
#include "Joystick.h"
#include "BoatMenu.h"
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

void menuChoice(menu &main,BoatMenu &bmenu);

void loop() 
{
	int** boats = new int*[10];
	
	//int *boatPTR = &boats;

	BoatMenu bmenu(_stick, LCD, boats); 
	menu main(_stick, LCD);
	_stick.ReadX();
	next = main.startMenu();
	hexx.Print(STPIC);
	for (;;)
	{
	menuChoice(main,bmenu);
	}
	
	delete[] boats;
}
void menuChoice(menu &main, BoatMenu &bmenu)
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

