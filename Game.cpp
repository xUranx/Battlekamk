#include "Game.h"
#include "Defines.h"
#include "Coordinates.h"
#include "Radio.h"
#include "Joystick.h"
#include "Grid.h"
Game::Game(S1D13700 *handler, Grid *grid, Joystick *stick, States gametype): _handler(handler),_grid(grid),_stick(stick),_gameType(gametype)
{
	Radio::radioSetup();
	if (PLAYER == 1)
	{
		_turn = true;
	}
	else
	{
		_turn = false;
	}
	
}


Game::~Game()
{
}
void Game::
gameloop()
{
	Coordinates coo;
	coo.init(_handler, _stick);
	coo.drawCoord();
	do
	{
		int x = 0;
		int y = 0;
		if (_turn)
		{
			do
			{
			coo.coordLoop(x, y);

			} while (_grid->chekValue(x,y) == Grid::Node::RESERVED);
			_grid->setValue(x, y, Grid::Node::SHOT);
			Radio::sendRadio(x, y);
			int hit = 0;
			int irrelevant = 0;
			Radio::listenRadio(hit,irrelevant);
#ifdef DEBUG = 0
			Serial.print("Hit and irrelevant was ");
			Serial.print(hit);
			Serial.print("   ");
			Serial.println("irrelevant ");
#endif // DEBUG = 0
			if (hit == 1)
			{
				//BOOM BUUM RƒJƒHTI
				_turn == true;
			}
			else
			{
				_turn == false;
			}

		}

	} while (!_grid->checkVictory());
/*
kumman vuoro?
ota kohde
tarkista ettei ole aikaisemmin ammuttu
jos osuma k‰‰nn‰ bool trueksi
muuten false
tarkista voitto
*/
}