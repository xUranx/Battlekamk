#include "Coordinates.h"
#include "S1D13700.h"
Coordinates::Coordinates(S1D13700 *handler) :_handler(handler), _screenWidht(320), _screenHeight(240)
{
}


Coordinates::~Coordinates()
{
}
void Coordinates::
drawCoord()
{
	int plus = _screenWidht / 11;
	int sector = plus;
	for (int i = 0; i < 10; i++)
	{
		_handler->drawLine(sector, 0, sector, _screenHeight);
		sector += plus;
	}
	int plusH = _screenHeight / 11;
	int sectorH = plusH;
	for (int i = 0; i < 10; i++)
	{
		_handler->drawLine(0, sectorH, _screenWidht, sectorH);
		sectorH += plusH;
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
