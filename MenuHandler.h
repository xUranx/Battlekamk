#pragma once
#include "MainMenu.h"

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
	S1D13700 *_handler;
	Joystick *_stick;
};

