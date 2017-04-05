#pragma once
#include "CustomVector.h"
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
private:
	void init();
};

class Boats
{
private:
	struct VecXY
	{
		const int x, y;
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
	CustomVector<Long> longs;
	CustomVector<Medium> mediums;
	CustomVector<Short> shorts;
	Grid _grid;
	bool addValue(int _x, int _y);
	bool checkAmount();
	void getGrid(Grid n) const { n = _grid; }// saattaa sekottaa ja ylikuormitettu
};