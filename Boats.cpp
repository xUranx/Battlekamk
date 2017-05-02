#include "Boats.h"
#include "Grid.h"
#include "Defines.h"
#include "Arduino.h"


Boats::Boats() : _grid(nullptr),_longs(0), _mediums(0), _shorts(0)
{
}
void Boats::init(Grid *grid)
{
	_grid = grid;
}

bool Boats::checkAmount()
{
	if (_longs == MAXLONG && _mediums == MAXMED && _shorts == MAXSHORT)
	{
		return true;
	}
	else
	{
		return false;
	}
}
void Boats::placeBoat(int x,int y,Type _type,Type _dir)
{
	int xdir = 0;
	int ydir = 0;
	int lenght = 0;
	//CustomVector<int> 
	switch (_type)
	{
	case Boats::Type::LONG:
	{
		_longs++;
		lenght = LONG_LEN;
	}
		break;
	case Boats::Type::MED:
	{
		_mediums++;
		lenght = MED_LEN;
	}
		break;
	case Boats::Type::SHORT:
	{		
		_shorts++;
		lenght = SHORT_LEN;
	}
		break;
	default:
#ifdef DEBUG = 0
		Serial.println("ERROR DEFAULT VALUE USED IN PLACEBOAT");
#endif // DEBUG = 0

		break;
	}
	if (_dir == Type::HORIZONTAL)
	{
		xdir++;
	}
	else
	{
		ydir++;
	}
	int tempx = x;
	int tempy = y;
	for (int i = 0; i < lenght; i += xdir +ydir)//sets boats
	{
		_grid->setValue(tempx,tempy);
		tempx += xdir;
		tempy += ydir;
	}
	if (_dir == Type::HORIZONTAL)//sets rezerved
	{
		_grid->setValue(x - 1, y, Grid::Node::RESERVED);
		_grid->setValue(x +lenght, y, Grid::Node::RESERVED);
		for (int i = 0; i < lenght + 2; i++)
		{
			_grid->setValue(x - 1 + i, y - 1, Grid::Node::RESERVED);
			_grid->setValue(x - 1 + i, y + 1, Grid::Node::RESERVED);
		}
#if DEBUG == 0
		Serial.println("placed horizontal boat");
#endif // DEBUG = 0

	}
	else
	{
		_grid->setValue(x, y -1, Grid::Node::RESERVED);
		_grid->setValue(x, y + lenght, Grid::Node::RESERVED);
		for (int i = 0; i < lenght + 2; i++)
		{
			_grid->setValue(x - 1 + i, y - 1 + i, Grid::Node::RESERVED);
			_grid->setValue(x + 1 + i, y - 1 + i, Grid::Node::RESERVED);
		}
#if DEBUG == 0
		Serial.println("placed vertical boat");
#endif // DEBUG = 0
	}

}

bool Boats::isValid(int x, int y, Type _type, Type _dir)
{
	// check if everyone is in grid, IF MULTIPLE CURSORS ARE IPLEMENTED U DONT NEED THIS ****CHECK*******
	int currentLenght = 0;
	switch (_type)
	{
	case Boats::Type::LONG:
		currentLenght = LONG_LEN;
		break;
	case Boats::Type::MED:
		currentLenght = MED_LEN;
		break;
	case Boats::Type::SHORT:
		currentLenght = SHORT_LEN;
		break;
	default:
#if DEBUG == 0
		Serial.println("ERROR DEFAULT VALUE USED IN BOAT CHECK // ISVALID");
#endif // DEBUG = 0
		currentLenght = SHORT_LEN;
		break;
	}
	if (x+currentLenght -1 <= 10 && y+currentLenght-1 <= 10)
	{
		if (this->correctPlace(x,y,currentLenght,_dir))
		{
			this->placeBoat(x, y, _type, _dir);
			return true;
		}
	}
	return false;
}
bool Boats::
checkIsTooMuch(Type _type)
{
	switch (_type)
	{
	case Boats::Type::LONG:
		if (_mediums < MAXMED)
		{
			return true;
		}
		break;
	case Boats::Type::MED:
		if (_shorts < MAXSHORT)
		{
			return true;
		}
		break;
	case Boats::Type::SHORT:
		if (_shorts < MAXSHORT)
		{
			return true;
		}
		break;
	default:
#if DEBUG == 0
		Serial.println("ERROR USED DEFAULT VALUE IN BOAT CHECK");
#endif // DEBUG =
		return false;
		break;
	}
	return false;
}
bool Boats::correctPlace(int x, int y, int lenght, Type _dir)
{
	for (int i = 0; i < lenght; i++)
	{
		if (_grid->chekValue(x,y) == Grid::Node::BOAT || _grid->chekValue(x, y) == Grid::Node::RESERVED)
		{
#if DEBUG == 0
			Serial.println("INCORRECT PLACE");
#endif // DEBUG =
			return false;
		}
		if (_dir == Type::HORIZONTAL)
		{
			x++;
		}
		else
		{
			y++;
		}
	}
	return true; /////// TO      DOOOOO
}


