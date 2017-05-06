#include "Coordinates.h"
#include "S1D13700.h"
#include "Joystick.h"
#include "Defines.h"
#include "PrintHex.h"
#include "Pictures.h"
Coordinates::Coordinates() :_handler(nullptr),_stick(nullptr), _XPlus(320 / 11), _YPlus(240 / 11), _currentXSector(_XPlus + 4), _currentYSector(_YPlus + 4)
{
	_index.setValue(1);
	_index.setValue(1);
}


Coordinates::~Coordinates()
{
}
void Coordinates::
init(S1D13700 *handler, Joystick *stick)
{
	_handler = handler;
	_stick = stick;
}
void Coordinates::
drawCoord()
{
	_handler->clearGraphic();
	_handler->clearText();
	PrintHex pr;
	pr.Print(grid,0,0);
	/*this->moveCursor(CursorDir::_DEFAULT);
	int sectorX = _XPlus;
	for (int i = 0; i < 10; i++)
	{
	
		_handler->drawLine(sectorX, 0, sectorX, SCREENHEIGHT);
		sectorX += _XPlus;
	}
	int sectorH = _YPlus;
	for (int i = 0; i < 10; i++)
	{

		_handler->drawLine(0, sectorH, SCREENWIDHT, sectorH);
		sectorH += _YPlus;
	}*/
}
void Coordinates::
drawChar()
{

	CustomVector<CustomVector<char>> words;
	char _char[10] = { 'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J' };
	this->setWord(words,_char);
	int plusChar = 40 / 12;
	int placeChar = plusChar*2;
	for (int i = 0; i < 10; i++)
	{
		_handler->textGoTo(placeChar, 1);
		_handler->writeText(words[i].y);
		placeChar += plusChar;
	}
	CustomVector<CustomVector<char>> ints;
	char _int[10] = { '1', '2', '3', '4', '5', '6', '7', '8', '9', 'X' };
	this->setWord(ints,_int);
	int plusInt = 33 / 11;
	int placeInt = plusInt;
	for (size_t i = 0; i < 10; i++)
	{
		_handler->textGoTo(2, placeInt);
		_handler->writeText(ints[i].y);
		placeInt += plusInt;
	}
}
void Coordinates::
setWord(CustomVector<CustomVector<char>> &words,char array[])
{
	for (size_t i = 0; i < 10; i++)
	{
		words[words.amount].setValue(array[i]);
		words[words.amount].setValue('\0');
	}
}
void Coordinates::
moveCursor(CursorDir _dir)
{
	const int minus = 10;
	if (_dir != CursorDir::_DEFAULT)
	{
	_handler->drawBox(_currentXSector, _currentYSector, _currentXSector + (_XPlus-minus), _currentYSector + (_YPlus-minus), 0);// undraw
	}
	switch (_dir)
	{
	case CursorDir::UP:
	{
		Serial.println(_index[1]);

		if (_index[1]>1)
		{
		_index[1] -= 1;
		_currentYSector -= _YPlus;
#if DEBUG == 0
		Serial.println("changed sector");
#endif

		}
	}
		break;
	case CursorDir::DOWN:
	{
#if DEBUG == 0
		Serial.println(_index[1]);
#endif

		if (_index[1]<10)
		{
			_index[1] += 1;
			_currentYSector += _YPlus;
#if DEBUG == 0
			Serial.println("changed sector");
#endif

		}
	}

		break;
	case CursorDir::LEFT:
	{
#if DEBUG == 0
		Serial.println(_index[0]);
#endif

		if (_index[0] > 1)
		{
			_index[0] -= 1;
			_currentXSector -= _XPlus;
#if DEBUG == 0
			Serial.println("changed sector");
#endif

		}
	}
		break;
	case CursorDir::RIGHT:
	{
#if DEBUG == 0
		Serial.println(_index[0]);
#endif

		if (_index[0]<10)
		{
			_index[0] += 1;
			_currentXSector += _XPlus;
#if DEBUG == 0
			Serial.println("changed sector");
#endif

		}
	}

		break;
	case CursorDir::_DEFAULT:
	{
	}
		break;

	}
#if DEBUG == 0
	Serial.write(" printed box ");
	Serial.println(_currentXSector);
	Serial.println(_currentYSector);
#endif


	_handler->drawBox(_currentXSector, _currentYSector, _currentXSector + (_XPlus-minus), _currentYSector + (_YPlus-minus));

}
void Coordinates::
drawShape(Shape shape, int x, int y, int visible)
{
	if (x>0 && y>0 && x<11 && y<11)
	{
	static int baseX = _XPlus;
	static int baseY = _YPlus;
	int whereX = x*baseX;// MUUTETTU
	int whereY = y*baseY; // MUUTETTU
	switch (shape)
	{
	case Shape::Circle:
		_handler->drawCircle(whereX,whereY,CIRCLERADIUS,visible);
		break;
	case Shape::Box:
		_handler->drawBox(whereX +2,whereY+2,whereX+BOXWIDHT,whereY+BOXHEIGHT,visible);
		break;
	default:
#if DEBUG == 0
		Serial.println("DEFAULT VALUE USED IN COORDS");
#endif // DEBUG = 0

		break;
	}
	}
}
void Coordinates::coordLoop(int &_x, int &_y)
{

	do
	{
	delay(200);
	int x = 0;
	int y = 0;
	do
	{
		x = _stick->ReadY();
		y = _stick->ReadX();
		if (_stick->Button())
		{
			return;
		}
	} while (x == 0 && y == 0);
	if (x == 1)
	{
#if DEBUG == 0
		Serial.println("moved u ");
#endif
		this->moveCursor(CursorDir::UP);
	}
	else if (x == -1)
	{
#if DEBUG == 0
		Serial.println("moved d ");
#endif
		this->moveCursor(CursorDir::DOWN);
	}
	if (y == 1)
	{
#if DEBUG == 0
		Serial.println("moved r ");
#endif
		this->moveCursor(CursorDir::RIGHT);
	}
	if (y == -1)
	{
#if DEBUG == 0
		Serial.println("moved l ");
#endif
		this->moveCursor(CursorDir::LEFT);
	}
	_x = _index[0];
	_y = _index[1];
	} while (true);
}

