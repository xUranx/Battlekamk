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
bool Grid::
checkVictory()
{
	for (int y = 0; y < 10; y++)
	{
		for (int x = 0; x < 10; x++)
		{
			if (node[y][x]== Node::BOAT)
			{
				return false;
			}
		}

	}
	return true;
}

Boats::Boats(Grid *grid, Coordinates *coo) :_grid(grid), _coo(coo)
{
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
void Boats::placeBoat(Type _type,Type _dir)
{
	CustomVector<int> 
	switch (_type)
	{
	case Boats::Type::LONG:
	{
		this->boatCursor();
	}
		break;
	case Boats::Type::MED:
	{
		this->boatCursor();
	}
		break;
	case Boats::Type::SHORT:
	{		
		this->boatCursor();
	}
		break;
	default:
		break;
	}
}
void Boats::boatCursor()
{

}


