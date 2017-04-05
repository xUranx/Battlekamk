#include "MenuHandler.h"
#include "Coordinates.h"
#include "Joystick.h"
MenuHandler::MenuHandler(S1D13700 *handler, Joystick *stick) : _handler(handler), _stick(stick)
{
}


MenuHandler::~MenuHandler()
{
}
void MenuHandler::
initClasses()
{
	_main.init(_handler,_stick,3);
	_boats.init(_handler, _stick, 5);
}
void MenuHandler::
menuLoop()
{
	Coordinates coo(_handler);
	coo.drawCoord();
	//coo.drawChar();
	for (;;)
	{
		delay(500);
		int x = 0;
		int y = 0;
		do
		{
		x=_stick->ReadY();
		y=_stick->ReadX();
		} while (x == 0&& y ==0);
		if (x == 1)
		{
			Serial.println("moved d ");
			coo.moveCursor(CursorDir::DOWN);
		}
		else if (x==-1)
		{
			Serial.println("moved u ");
			coo.moveCursor(CursorDir::UP);
		}
		if (y == 1)
		{
			Serial.println("moved l ");
			coo.moveCursor(CursorDir::LEFT);
		}
		if (y == -1)
		{
			Serial.println("moved r ");
			coo.moveCursor(CursorDir::RIGHT);
		}
	}
	CustomVector <CustomVector<char>> words;
	CustomVector<char> word1;
	char array1[4] = "PVP";

	this->setWord(word1,array1, 4);
	CustomVector<char> word2;
	char array2[3] = "AI";
	this->setWord(word2, array2, 3);
	CustomVector<char> word3;
	char array3[10] = "SET_BOATS";
	
	this->setWord(word3, array3, 10);
	words.setValue(word1);
	words.setValue(word2);
	words.setValue(word3);
	_main.write(words);
	_main.loop();
}
void MenuHandler::
setWord(CustomVector<char> &word,char array[], int size)
{
	array[size - 1] = '\0';
	for (int i = 0; i < size; i++)
	{
		word.setValue(array[i]);
	}
}




