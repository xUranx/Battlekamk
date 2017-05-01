
#pragma once
#include "Defines.h"
#include "CustomVector.h"
#include "Boxes.h"
class Joystick;
class  S1D13700;

enum class BoxPos 
{
	_UP,_DOWN,_DEFAULT
};
enum class Index 
{
	UP,DOWN
};

class MainMenu
{
public:
	MainMenu();
	~MainMenu();
	void init(S1D13700 *handler, Joystick *stick,int boxAmount);
	void write(CustomVector<CustomVector <char>> &word);// give only the same amount text as you have boxes
	int loop();
protected:
	void drawBox(BoxPos where = BoxPos::_DEFAULT);
	void getBoxPositions(int boxAmount);
	void setIndex(Index where);
	S1D13700 *_handler;
	Joystick *_stick;
	Boxes _boxes;//init this always
	int _divide;
	int UY;
	int DY;
	int _index;
};

