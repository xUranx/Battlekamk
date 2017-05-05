#include "Game.h"
#include "Defines.h"
#include "Coordinates.h"
#include "Radio.h"
#include "Joystick.h"
#include "AITemplates.h"
Game::Game(S1D13700 *handler, Grid grid, Joystick *stick): _handler(handler),_grid(grid),_stick(stick),_ai(AIState::Searching),lastAIx(0),lastAIy(0),_aiGrid(nullptr)
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
	this->setupAI();
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
#if DEBUG == 0
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
#if DEBUG == 0
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
				//BOOM BUUM RƒJƒHTI
				_turn == true;
			}
			else
			{
				_turn == false;
			}

		}
		else
		{
#if DEBUG == 0
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
				int x, y;
				this->aiMove(x,y);
#if DEBUF == 0
				Serial.print("Ai move is ");
				Serial.print(x);
				Serial.println(y);
#endif
			}
		}

	} while (!_grid.checkVictory());

/*
kumman vuoro?
ota kohde
tarkista ettei ole aikaisemmin ammuttu
jos osuma k‰‰nn‰ bool trueksi
muuten false
tarkista voitto
*/
}
void Game::
aiMove(int &x, int &y)
{
	int tempx;
	int tempy;
	AIState temp;
	//int tempaix = lastAIx;
	//int tempaiy = lastAIy;
	do
	{
		temp = _ai;
		tempx = 0;
		tempy = 0;
		switch (temp)
		{
		case AIState::Searching:
		{
	
				tempx = random(1, 11);
				tempy = random(1, 11);
				temp = AIState::Shot_No_Dir;
		}
			break;
			case AIState::Shot_No_Dir:
			{

					int dir = random(1, 5);
					switch (dir)
					{
					case 1:
					{
						temp = AIState::UP;
						tempy = lastAIy - 1;
					}
						break;
					case 2:
					{
						temp = AIState::DOWN;
						tempy = lastAIy + 1;
					}
						break;
					case 3:
					{
						temp = AIState::RIGHT;
						tempx = lastAIx + 1;
					}
						break;
					case 4:
					{
						temp = AIState::LEFT;
						tempx = lastAIx - 1;
					}
						break;
					}

			}
				break;
		case AIState::UP:
			temp = AIState::UP;
			tempy = lastAIy - 1;
			break;
		case AIState::DOWN:
			temp = AIState::DOWN;
			tempy = lastAIy + 1;
			break;
		case AIState::RIGHT:
			temp = AIState::RIGHT;
			tempx = lastAIx + 1;
			break;
		case AIState::LEFT:
			temp = AIState::LEFT;
			tempx = lastAIx - 1;
			break;
		default:
#if DEBUG == 0
			Serial.println("ERROR IN STATES AIMOVE");
#endif

			break;
		}

	} while ((*_aiGrid)[tempy-1][tempx-1] == 2);
	_ai = temp;
	x = tempx;
	y = tempy;
	lastAIx = x;
	lastAIy = y;
	(*_aiGrid)[tempy - 1][tempx - 1] = 2;
}
void Game::
setupAI()
{
	int rnd = random(1, 6);
	switch (rnd)
	{
	case 1:
		_aiGrid = &ai_t1;
		break;
	case 2:
		_aiGrid = &ai_t2;
		break;
	case 3:
		_aiGrid = &ai_t3;
		break;
	case 4:
		_aiGrid = &ai_t4;
		break;
	case 5:
		_aiGrid = &ai_t5;
		break;
	}
}

