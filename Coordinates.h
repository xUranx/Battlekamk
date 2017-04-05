#pragma once
#include "CustomVector.h"

class S1D13700;

enum class CursorDir
{
	UP,DOWN,LEFT,RIGHT
};
enum class Shape
{
	Circle, Box
};

class Coordinates
{
public:
	Coordinates(S1D13700 *handler);
	~Coordinates();
	void drawCoord();
	void drawChar();
	void drawShape(Shape shape, int x,int y);
	void moveCursor(CursorDir _dir);
private:
	void setWord(CustomVector<CustomVector<char>> &words,char array[]);
	CustomVector<int> _index;
	S1D13700 *_handler;
	const int _screenWidht;
	const int _screenHeight;
	const int _XPlus;
	const int _YPlus;
	int _currentXSector;
	int _currentYSector;
	const int _BoxWidht;
	const int _BoxHeight;

};

