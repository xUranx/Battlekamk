#pragma once
#include "menu.h"

class BoatMenu : menu
{
public:
	BoatMenu(Joystick &stick, S1D13700 &LCD, int **boards);
	BoatMenu(Joystick &stick);
	

	~BoatMenu();
private:
	int **_boats = nullptr;
};

