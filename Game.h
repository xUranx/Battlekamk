#pragma once
#include "Grid.h"

class S1D13700;
class Joystick;

enum class States
{
	Player_One, Player_Two, AI,PVP
};
enum class AIState
{
	Searching,Shot_No_Dir,UP,DOWN,LEFT,RIGHT
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
	void aiMove(int &x, int &y);
	AIState _ai;
	int lastAIx;
	int lastAIy;
	void setupAI();
	int (*_aiGrid)[10][10];
};

