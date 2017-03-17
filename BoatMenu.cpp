#include "BoatMenu.h"


BoatMenu::BoatMenu(Joystick &stick, S1D13700 &LCD, int **boats)
	: menu(stick,LCD)
{
	_boats = boats;
}

BoatMenu::~BoatMenu()
{

}