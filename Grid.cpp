#include "Grid.h"
#include "Defines.h"


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
	if (x>0 && y>0 && x<10 && y<10)
	{
		if (node[y][x] != Node::RESERVED)
		{
			x -= 1;
			y -= 1;
			node[y][x] = what;
#ifdef DEBUG = 0
			Serial.print("Setted boat to x , y =");
			Serial.print(x+1);
			Serial.print(" ");
			Serial.println(y+1);
#endif // DEBUG = 0

		}
	}
	else
	{
#ifdef DEBUG = 0
		Serial.println("ERROR SETTING VALUE");
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

