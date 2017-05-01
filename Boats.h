#pragma once
#include "CustomVector.h"
class Coordinates;
class Grid;
struct UsedPositions
{

};
class Boats
{
public:
	enum class Type
	{
		LONG,MED,SHORT,HORIZONTAL,VERTICAL
		
	};
	enum class State 
	{
	Used,Reserved,Free
	};
	Boats::Boats();
	bool checkAmount(); // use for checking correct amount before going to game
	bool checkIsTooMuch(Type _type);	// use before trying to add boats
	void init(Grid *grid);
	bool isValid(int x, int y, Type _type, Type _dir);
private:
	void placeBoat(int x, int y, Type _type, Type _dir);
	bool correctPlace(int x, int y,int lenght, Type _dir);
	Grid *_grid;
	int _shorts;
	int _mediums;
	int _longs;
};