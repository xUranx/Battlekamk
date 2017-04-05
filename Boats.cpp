#include "Boats.h"

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
	if (x>0 && y>0)
	{
		x -= 1;
		y -= 1;
		node[y][x] = what;
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


void Grid::operator =(Grid n)
{
	for (int y = 0; y < 10; y++)
	{
		for (int x = 0; x < 10; x++)
		{
			if (n.node[y][x] == Node::BOAT)
			{
			this->node[y][x] = Node::BOAT;
			}
			else
			{
				this->node[y][x] = Node::FREE;
			}
		}
	}
}

bool Boats::addValue(int _x, int _y)
{
	Grid::Node stat = _grid.chekValue(_x, _y);
	if (stat != Grid::Node::BOAT)
	{
		if (this->setValue(_x,_y))
		{
		_grid.setValue(_x, _y);
		}
	}
	else
	{
		return false;
	}
}
bool Boats::checkAmount()
{
	if (longs.amount == 2 && mediums.amount == 3 && shorts.amount == 4)
	{
		return true;
	}
	else
	{
		return false;
	}
}
bool Boats::setValue(int _x, int _y) // true if legit
{

}
