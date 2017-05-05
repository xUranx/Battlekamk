#pragma once
#include "Grid.h"

class S1D13700;
class Joystick;

enum class States
{
	Player_One, Player_Two, AI,PVP
};

class Game
{
public:
	Game(S1D13700 *handler,Grid grid,Joystick *stick);
	~Game();
	void gameloop(States gametype);
private:
	S1D13700 *_handler;
	Grid _grid;
	Joystick *_stick;
	bool _turn;
};

