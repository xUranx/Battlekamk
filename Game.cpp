#include "Game.h"
#include "Defines.h"
#include "Coordinates.h"
#include "Radio.h"
#include "Joystick.h"
Game::Game(S1D13700 *handler, Grid grid, Joystick *stick): _handler(handler),_grid(grid),_stick(stick)
{
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
gameloop(States gametype)
{
	Radio radio;
	radio.radioSetup();
	Coordinates coo;
	coo.init(_handler, _stick);
	coo.drawCoord();
	do
	{
		int x = 0;
		int y = 0;
		if (_turn)
		{
#ifdef DEBUG = 0
			Serial.println("It it your turn");
#endif // DEBUG = 0

			do
			{
			coo.coordLoop(x, y);
			} while (_grid.chekValue(x,y) == Grid::Node::RESERVED );
			_grid.setValue(x, y, Grid::Node::SHOT);
			int hit = 0;
			int wincheck = 0;
			if (gametype == States::PVP)
			{
			radio.sendRadio(x, y);
			radio.listenRadio(hit, wincheck);
#ifdef DEBUG = 0
			Serial.print("Hit and irrelevant was ");
			Serial.print(hit);
			Serial.print("   ");
			Serial.println("irrelevant ");
#endif // DEBUG = 0
			}
			if (hit == 1)
			{
				if (wincheck == 1)
				{
					break; // WON
				}
				//BOOM BUUM RÄJÄHTI
				_turn == true;
			}
			else
			{
				_turn == false;
			}

		}
		else
		{
#ifdef DEBUG = 0
			Serial.println("It it enemy turn");
#endif // DEBUG = 0
			int x = 0;
			int y = 0;
			if (gametype == States::PVP)
			{
				
				radio.listenRadio(x, y);
				if (_grid.chekValue(x,y) == Grid::Node::BOAT)
				{
					_turn = false;
					_grid.setValue(x, y, Grid::Node::FREE);
					// UNDRAW BOX AND BOOM BOOM
					if (_grid.checkVictory())
					{
						radio.sendRadio(1, 1);
					}
					else
					{
					radio.sendRadio(1, 0);
					}
				}
				else
				{
					_turn = true;
				}
			}
			else
			{
			
			}
		}

	} while (!_grid.checkVictory());
/*
kumman vuoro?
ota kohde
tarkista ettei ole aikaisemmin ammuttu
jos osuma käännä bool trueksi
muuten false
tarkista voitto
*/
}