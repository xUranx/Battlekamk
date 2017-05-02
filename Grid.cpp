#include "Grid.h"
#include "Defines.h"
#include "Arduino.h"

Grid::Grid()
{
	this->init();
};
Grid::Node Grid::chekValue(int x, int y)
{
	x -= 1;
	y -= 1;
	return node[y][x];
};
void Grid::setValue(int x, int y, Node what)
{
	if (x>0 && y>0 && x<=10 && y<=10)
	{
			x -= 1;
			y -= 1;
		if (node[y][x] != Node::RESERVED)
		{
	/*		x -= 1;
			y -= 1;*/// MUOKATTU
			node[y][x] = what;
#if DEBUG == 0
			Serial.print("Setted boat to x , y =");
			Serial.print(x+1);
			Serial.print(" ");
			Serial.println(y+1);
#endif // DEBUG = 0

		}
		else if (node[y][x] == Node::RESERVED)
		{
#if DEBUG == 0
			Serial.println("Boat found in RESERVED PLACE DANGER DANGER ");
			Serial.print(x +1);
			Serial.print(" ");
			Serial.println(y +1);
#endif // DEBUG = 0

		}
	}
	else
	{
#if DEBUG == 0
		Serial.println("ERROR SETTING VALUE TO X Y =");
		Serial.print(x );
		Serial.print(" ");
		Serial.println(y);
#endif // DEBUG = 0

	}
}
void Grid::init()
{
	for (int i = 0; i < 10; i++)
	{
		for (int a = 0; a < 10; a++)
		{
			node[i][a] = Node::FREE;
		}

	}
};


bool Grid::
checkVictory() // game loop function
{
	for (int y = 0; y < 10; y++)
	{
		for (int x = 0; x < 10; x++)
		{
			if (node[y][x] == Node::BOAT)
			{
				return false;
			}
		}

	}
	return true;
}
void Grid::
normalize()
{
	for (int y = 0; y < 10; y++)
	{
		for (int x = 0; x < 10; x++)
		{
			if (node[y][x] == Node::RESERVED)
			{
				node[y][x] = Node::FREE;
			}
		}

	}
}

