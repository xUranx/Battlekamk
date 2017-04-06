#include "Coordinates.h"
#include "S1D13700.h"
Coordinates::Coordinates(S1D13700 *handler, Joystick *stick) :_handler(handler),_stick(stick), _screenWidht(320), _screenHeight(240), _XPlus(320 / 11), _YPlus(240 / 11), _currentXSector(_XPlus + 4), _currentYSector(_YPlus + 4), _BoxHeight(15), _BoxWidht(20)
{
	_index.setValue(1);
	_index.setValue(1);
}


Coordinates::~Coordinates()
{
}
void Coordinates::
drawCoord()
{

	int sectorX = _XPlus;
	for (int i = 0; i < 10; i++)
	{
	
		_handler->drawLine(sectorX, 0, sectorX, _screenHeight);
		sectorX += _XPlus;
	}
	int sectorH = _YPlus;
	for (int i = 0; i < 10; i++)
	{

		_handler->drawLine(0, sectorH, _screenWidht, sectorH);
		sectorH += _YPlus;
	}
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
		Serial.println("changed sector");

		}
	}
		break;
	case CursorDir::DOWN:
	{
		Serial.println(_index[1]);

		if (_index[1]<10)
		{
			_index[1] += 1;
			_currentYSector += _YPlus;
			Serial.println("changed sector");

		}
	}

		break;
	case CursorDir::LEFT:
	{
		Serial.println(_index[0]);

		if (_index[0] > 1)
		{
			_index[0] -= 1;
			_currentXSector -= _XPlus;
			Serial.println("changed sector");

		}
	}
		break;
	case CursorDir::RIGHT:
	{
		Serial.println(_index[0]);

		if (_index[0]<10)
		{
			_index[0] += 1;
			_currentXSector += _XPlus;
			Serial.println("changed sector");

		}
	}

		break;
	case CursorDir::_DEFAULT:
	{
	}
		break;

	}
	Serial.write(" printed box ");
	Serial.println(_currentXSector);
	Serial.println(_currentYSector);


	_handler->drawBox(_currentXSector, _currentYSector, _currentXSector + (_XPlus-minus), _currentYSector + (_YPlus-minus));

}
void Coordinates::
drawShape(Shape shape, int x, int y)
{
	if (x<0 && y && 0)
	{
	static int baseX = _XPlus + 4;
	static int baseY = _YPlus + 4;
	int whereX = x*baseX;
	int whereY = y*baseY;
	switch (shape)
	{
	case Shape::Circle:
		_handler->drawCircle(whereX,whereY,10);
		break;
	case Shape::Box:
		_handler->drawBox(whereX,whereY,whereX+_BoxWidht,whereY+_BoxHeight);
		break;
	default:
		break;
	}
	}
}
void Coordinates::coordLoop(int &_x, int &_y)
{
	this->moveCursor(CursorDir::_DEFAULT);


	do
	{
	delay(500);
	int x = 0;
	int y = 0;
	do
	{
		x = _stick->ReadY();
		y = _stick->ReadX();
	/*	if (_stickReadButton())
		{
			return;
		}*/
	} while (x == 0 && y == 0);
	if (x == 1)
	{
		Serial.println("moved d ");
		this->moveCursor(CursorDir::DOWN);
	}
	else if (x == -1)
	{
		Serial.println("moved u ");
		this->moveCursor(CursorDir::UP);
	}
	if (y == 1)
	{
		Serial.println("moved l ");
		this->moveCursor(CursorDir::LEFT);
	}
	if (y == -1)
	{
		Serial.println("moved r ");
		this->moveCursor(CursorDir::RIGHT);
	}
	_x = _index[0];
	_y = _index[1];
	} while (true);
}

