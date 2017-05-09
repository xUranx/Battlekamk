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
	Searching,Shot_No_Dir,UP,DOWN,LEFT,RIGHT,AIMING
};
struct AI 
{
	int lastAIx = 0;
	int lastAIy = 0;
	AIState _ai = AIState::Searching;
	AIState _OriginalDir = AIState::LEFT;
	int originalX = 0;
	int originalY = 0;
	bool guessing = true;
	int aimingX = 0;
	int aimingY = 0;
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
	//bool _turn;
	//void aiMove(int &x, int &y);
	//void setupAI();
	//int (*_aiGrid)[10][10];
	//AI _AI;
	//void checkIsDestroyed(int x,int y);
};

