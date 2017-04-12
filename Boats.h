#pragma once
#include "CustomVector.h"

class Coordinates;
class Grid
{
public:
	enum class Node
	{
		FREE,BOAT
	};
	Grid::Grid();
	Node node[10][10];
	Node chekValue(int x, int y);
	void setValue(int x, int y, Node what = Node::BOAT);
	void operator =(Grid n);
	bool checkVictory();
private:
	void init();
};

class Boats
{
private:
	struct VecXY
	{
		 
		int x, y;
	};
	struct Long
	{
		VecXY xy[3];
		int amount = 3;
	};
	struct Medium
	{
		VecXY xy[2];
		int amount = 2;

	};
	struct Short
	{
		
		VecXY xy[1];
		int amount = 1;
	};
	bool setValue(int _x,int _y);
public:
	enum class Type
	{
		LONG,MED,SHORT,HORIZONTAL,VERTICAL
		
	};
	Boats::Boats();
	bool checkAmount();
	void placeBoat(Type _type, Type _dir);
	void init(Grid *grid);
	bool isValid(int x,int y);
private:
	void boatCursor();
	Grid *_grid;
	CustomVector<Long> longs;
	CustomVector<Medium> mediums;
	CustomVector<Short> shorts;
};