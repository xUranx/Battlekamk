#include "Coordinates.h"
#include "S1D13700.h"
Coordinates::Coordinates(S1D13700 *handler) :_handler(handler), _screenWidht(320), _screenHeight(240), _XPlus(320 / 11), _YPlus(240 / 11), _currentXSector(_XPlus + 4), _currentYSector(_YPlus + 4), _BoxHeight(15), _BoxWidht(20)
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
	_handler->drawBox(_currentXSector, _currentYSector, _currentXSector + _XPlus, _currentYSector + _YPlus, 0);// undraw
	switch (_dir)
	{
	case CursorDir::UP:
	{
		if (_index[1]<0)
		{
		_index[1] -= 1;
		_currentYSector - _YPlus;
		}
	}
		break;
	case CursorDir::DOWN:
	{
		if (_index[1]>11)
		{
			_index[1] += 1;
			_currentYSector + _YPlus;

		}
	}

		break;
	case CursorDir::LEFT:
	{
		if (_index[0] < 0)
		{
			_index[0] -= 1;
			_currentXSector - _XPlus;

		}
	}
		break;
	case CursorDir::RIGHT:
	{
		if (_index[0]>11)
		{
			_index[0] += 1;
			_currentXSector + _XPlus;
		}
	}

		break;
	default:
		break;
	}

	_handler->drawBox(_currentXSector, _currentYSector, _currentXSector + _XPlus, _currentYSector + _YPlus);

}
