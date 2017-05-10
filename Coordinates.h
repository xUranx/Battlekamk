#pragma once
#include "CustomVector.h"

class S1D13700;
class Joystick;
enum class CursorDir
{
	UP,DOWN,LEFT,RIGHT,_DEFAULT,_BACK
};
enum class Shape
{
	Circle, Box
};

class Coordinates
{
public:
	Coordinates();
	~Coordinates();
	void init(S1D13700 *handler, Joystick *stick);
	void drawCoord(int clear = 0);
	void drawChar();
	void drawShape(Shape shape, int x,int y,int visible = 1);
	void coordLoop(int &_x,int &_y);
private:
	void moveCursor(CursorDir _dir);
	void setWord(CustomVector<CustomVector<char>> &words,char array[]);
	CustomVector<int> _index;
	S1D13700 *_handler;
	const int _XPlus;
	const int _YPlus;
	int _currentXSector;
	int _currentYSector;
	Joystick *_stick;
};

