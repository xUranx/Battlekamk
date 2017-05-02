#pragma once
class S1D13700;
class Grid;
class Joystick;

enum class States
{
	Player_One, Player_Two, AI,PVP
};

class Game
{
public:
	Game(S1D13700 *handler,Grid *grid,Joystick *stick,States gametype);
	~Game();
	void gameloop();
private:
	S1D13700 *_handler;
	Grid	*_grid;
	Joystick *_stick;
	States _gameType;
	bool _turn;
};

