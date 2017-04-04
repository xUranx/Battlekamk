#pragma once
#include "CustomVector.h"

class S1D13700;

class Coordinates
{
public:
	Coordinates(S1D13700 *handler);
	~Coordinates();
	void drawCoord();
	void drawChar();
private:
	void setWord(CustomVector<CustomVector<char>> &words,char array[]);
	S1D13700 *_handler;
	int _screenWidht;
	int _screenHeight;
};

