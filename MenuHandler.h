#pragma once
#include "MainMenu.h"
#include "Coordinates.h"
#include "Boats.h"
class MenuHandler
{
public:
	MenuHandler(S1D13700 *handler, Joystick *stick);
	~MenuHandler();
	void initClasses();
	void menuLoop();
private:
	void setWord(CustomVector<char> &word,char array[], int size);
	MainMenu _main;
	MainMenu _boats;
	MainMenu _dirMen;
	Coordinates _coo;
	Grid _grid;
	Boats _boatChecker;
	S1D13700 *_handler;
	Joystick *_stick;

};

