#pragma once
class Grid
{
public:
	enum class Node
	{
		FREE, BOAT , RESERVED, SHOT
	};
	Grid::Grid();
	Node chekValue(int x, int y);
	void setValue(int x, int y, Node what = Node::BOAT);
	bool checkVictory();
	void normalize(); // gets rid of reserved values
private:
	void init();
	Node node[10][10];
};

