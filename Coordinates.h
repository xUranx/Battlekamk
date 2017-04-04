#pragma once
#include "CustomVector.h"

class S1D13700;

enum class CursorDir
{
	UP,DOWN,LEFT,RIGHT

};

class Coordinates
{
public:
	Coordinates(S1D13700 *handler);
	~Coordinates();
	void drawCoord();
	void drawChar();
private:
	void setWord(CustomVector<CustomVector<char>> &words,char array[]);
	CustomVector<int> _index;
	void moveCursor(CursorDir _dir);
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

