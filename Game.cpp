#include "Game.h"
#include "Defines.h"
#include "Coordinates.h"
#include "Radio.h"
#include "Joystick.h"
#include "AITemplates.h"
#include "particle.h"
Game::Game(S1D13700 *handler, Grid grid, Joystick *stick): _handler(handler),_grid(grid),_stick(stick)//,_aiGrid(nullptr)
{
	//if (PLAYER == 1)
	//{
	//	_turn = true;
	//}
	//else
	//{
	//	_turn = false;
	//}
	
}


Game::~Game()
{
}
void Game::
gameloop(States gametype)
{
	//this->setupAI();
#if DEBUG == 0
	Serial.println("GOT OUT OF SETUP AI");
#endif // DEBUG = 0
	//Radio radio;
	//radio.radioSetup();
#if DEBUG == 0
	Serial.println("GOT OUT OF SETUP RADIO");
#endif // DEBUG = 0
	Coordinates coo;
	coo.init(_handler, _stick);
#if DEBUG == 0
	Serial.println("COO INIT");
#endif // DEBUG = 0 
#if DEBUG == 0
	Serial.println("DRAWING COORDINATES");
#endif // DEBUG = 0
	coo.drawCoord();
	for (int testy = 0; testy < 10; testy++)
	{
		for (int testx = 0; testx < 10; testx++)
		{
			if (_grid.chekValue(testx + 1, testy + 1) == Grid::Node::BOAT || _grid.chekValue(testx + 1, testy + 1) == Grid::Node::SHOT_AND_BOAT)
			{
				coo.drawShape(Shape::Box, testx + 1, testy + 1);
			}
		}
	}
	particle p(_handler);
	for (;;)
	{
		int x = 0;
		int y = 0;
		/*if (_turn)
		{*/
#if DEBUG == 0
		Serial.println("It it your turn");
#endif // DEBUG = 0

		do
		{
		coo.coordLoop(x, y);
#if DEBUG == 0
		Serial.println("LOOP GOT ");
		Serial.println(x);
		Serial.println(y);
#endif // DEBUG = 0
		} while (_grid.chekValue(x, y) != Grid::Node::BOAT);
#if DEBUG == 0
		Serial.println("GET TO COVER!!!");
#endif // DEBUG = 0
		p.Explode(x, y);
	}
}
//			_grid.setValue(x, y, Grid::Node::SHOT);
//			int hit = 0;
//			int wincheck = 0;
//			if (gametype == States::PVP)
//			{
//			radio.sendRadio(x, y);
//			radio.listenRadio(hit, wincheck);
//#if DEBUG == 0
//			Serial.print("Hit and irrelevant was ");
//			Serial.print(hit);
//			Serial.print("   ");
//			Serial.println(wincheck);
//#endif // DEBUG = 0
//				if (hit == 1) 
//				{
//					if (wincheck == 1)
//					{
//						break; // WON
//					}
//					//BOOM BUUM RÄJÄHTI
//					_turn == true;
//				}
//				else
//				{
//					_turn == false;
//				}
//			}
//			else /// AI
//			{
//				if ((*_aiGrid)[y-1][x-1] == BOATAI || (*_aiGrid)[y - 1][x - 1] == SHOT_AND_BOATAI)
//				{
//					coo.drawShape(Shape::Box, x, y, 0);
//					(*_aiGrid)[y - 1][x - 1] = FREEAI;
//					_turn = true;
//					bool winCheck = true;
//					for (int y = 0; y < 10; y++)
//					{
//						for (int x = 0; x < 10; x++)
//						{
//							if((*_aiGrid)[y][x] == BOATAI || (*_aiGrid)[y][x] == SHOT_AND_BOATAI)
//							{
//								winCheck = false;
//							}
//
//						}
//						if (winCheck)
//						{
//#if DEBUG == 0
//							Serial.print("AYYYY YOU WON ");
//
//#endif // DEBUG = 0
//							break;
//						}
//
//					}
//
//					// totea häviäminen
//				}
//				else
//				{
//					_turn = false;
//				}
//			}
//
//			
//
//		}
//		//// ENEMY TURN
//		else
//		{
//#if DEBUG == 0
//			Serial.println("It it enemy turn");
//#endif // DEBUG = 0
//			int x = 0;
//			int y = 0;
//			if (gametype == States::PVP)
//			{
//				
//				radio.listenRadio(x, y);
//				if (_grid.chekValue(x,y) == Grid::Node::BOAT)
//				{
//					_turn = false;
//					_grid.setValue(x, y, Grid::Node::FREE);
//					coo.drawShape(Shape::Box, x, y,0);
//					if (_grid.checkVictory())
//					{
//						radio.sendRadio(1, 1);
//					}
//					else
//					{
//					radio.sendRadio(1, 0);
//					}
//				}
//				else
//				{
//					_turn = true;
//				}
//			}
//			else
//			{
//				int x, y;
//				this->aiMove(x,y);
//#if DEBUF == 0
//				Serial.print("Ai move is ");
//				Serial.print(x);
//				Serial.print(" ");
//				Serial.println(y);
//#endif
//				if (_grid.chekValue(x,y)== Grid::Node::BOAT)
//				{
//					_grid.setValue(x, y, Grid::Node::FREE);
//					coo.drawShape(Shape::Box, x, y, 0);
//					_turn = false;
//					_AI.guessing = false;
//				}
//				else if(_grid.chekValue(x, y) == Grid::Node::SHOT_AND_BOAT)
//				{
//					_grid.setValue(x, y, Grid::Node::SHOT);
//					coo.drawShape(Shape::Box,x,y,0);
//					_turn = false;
//					_AI.guessing = false;
//				}
//				else
//				{
//					AIState temp = _AI._ai;
//					if (temp == AIState::DOWN|| temp == AIState::UP || temp == AIState::RIGHT|| temp == AIState::LEFT)
//					{
//						if (_AI.guessing)
//						{
//							_AI._ai = AIState::Shot_No_Dir;
//							_AI.lastAIx = _AI.originalX;
//							_AI.lastAIy = _AI.originalY;
//						}
//						else
//						{
//							_AI._OriginalDir = _AI._ai;
//							switch (_AI._ai)
//							{
//							case AIState::DOWN:
//							{
//								this->checkIsDestroyed(_AI.originalX, _AI.originalX - 1);
//							}
//								break;
//							case AIState::UP:
//							{
//								this->checkIsDestroyed(_AI.originalX, _AI.originalX + 1);
//							}
//								break;
//							case AIState::LEFT:
//							{
//								this->checkIsDestroyed(_AI.originalX + 1, _AI.originalX);
//							}
//								break;
//							case AIState::RIGHT:
//							{
//								this->checkIsDestroyed(_AI.originalX -1, _AI.originalX);
//							}
//								break;
//							default:
//#if DEBUG == 0
//								Serial.println("ERROR IN AI MISSING STATEMENTS");
//#endif
//								break;
//							}
//							
//						}
//					}
//					_turn = true;
//				}
//			}
//		}
//
//	} while (!_grid.checkVictory());
//
///*
//kumman vuoro?
//ota kohde
//tarkista ettei ole aikaisemmin ammuttu
//jos osuma käännä bool trueksi
//muuten false
//tarkista voitto
//*/
//}
//void Game::
//aiMove(int &x, int &y)
//{
//	int tempx;
//	int tempy;
//	AIState temp;
//	//int tempaix = lastAIx;
//	//int tempaiy = lastAIy;
//	do
//	{
//		temp = _AI._ai;
//		tempx = 0;
//		tempy = 0;
//		switch (temp)
//		{
//		case AIState::Searching:
//		{
//	
//				tempx = random(1, 11);
//				tempy = random(1, 11);
//				temp = AIState::Shot_No_Dir;
//		}
//			break;
//			case AIState::Shot_No_Dir:
//			{
//
//					int dir = random(1, 5);
//					_AI.originalX = _AI.lastAIx;
//					_AI.originalY = _AI.lastAIy;
//					_AI.guessing = true;
//					switch (dir)
//					{
//					case 1:
//					{
//						temp = AIState::UP;
//						tempy = _AI.lastAIy - 1;
//					}
//						break;
//					case 2:
//					{
//						temp = AIState::DOWN;
//						tempy = _AI.lastAIy + 1;
//					}
//						break;
//					case 3:
//					{
//						temp = AIState::RIGHT;
//						tempx = _AI.lastAIx + 1;
//					}
//						break;
//					case 4:
//					{
//						temp = AIState::LEFT;
//						tempx = _AI.lastAIx - 1;
//					}
//						break;
//					}
//
//
//			}
//				break;
//		case AIState::UP:
//			temp = AIState::UP;
//			tempy = _AI.lastAIy - 1;
//			break;
//		case AIState::DOWN:
//			temp = AIState::DOWN;
//			tempy = _AI.lastAIy + 1;
//			break;
//		case AIState::RIGHT:
//			temp = AIState::RIGHT;
//			tempx = _AI.lastAIx + 1;
//			break;
//		case AIState::LEFT:
//			temp = AIState::LEFT;
//			tempx = _AI.lastAIx - 1;
//			break;
//		case AIState::AIMING:
//		{
//			tempx = _AI.aimingX;
//			tempy = _AI.aimingY;
//			switch (_AI._OriginalDir)
//			{
//			case AIState::DOWN:
//				{
//					this->checkIsDestroyed(tempx, tempy-1);
//				}
//				break;
//			case AIState::LEFT:
//				{
//					this->checkIsDestroyed(tempx+1, tempy);
//				}
//				break;
//			case AIState::RIGHT:
//				{
//					this->checkIsDestroyed(tempx-1, tempy);
//				}
//				break;
//			case AIState::UP:
//				{
//					this->checkIsDestroyed(tempx, tempy+1);
//				}
//				break;
//			default:
//#if DEBUG == 0
//				Serial.println("ERROR IN AI AIMING STATEMENTS");
//#endif
//				break;
//			}
//		}
//			break;
//		default:
//#if DEBUG == 0
//			Serial.println("ERROR IN STATES AIMOVE");
//#endif
//
//			break;
//		}
//
//	} while ((*_aiGrid)[tempy-1][tempx-1] == SHOTAI || (*_aiGrid)[tempy - 1][tempx - 1] == SHOT_AND_BOATAI);
//
//	
//	_AI._ai = temp;
//	x = tempx;
//	y = tempy;
//	_AI.lastAIx = x;
//	_AI.lastAIy = y;
//	if ((*_aiGrid)[tempy - 1][tempx - 1] == FREEAI)
//	{
//		(*_aiGrid)[tempy - 1][tempx - 1] = SHOTAI;
//	}
//	else
//	{
//		(*_aiGrid)[tempy - 1][tempx - 1] = SHOT_AND_BOATAI;
//	}
//	
//}
//void Game::
//setupAI()
//{
////	int rnd = random(1, 6);
////#if DEBUG == 0
////	Serial.print("USING TEMPLATE ");
////	Serial.println(rnd);
////
////#endif
//	int rnd = 1;
//	switch (rnd)
//	{
//	case 1:
//		_aiGrid = &ai_t1;
//		break;
//	//case 2:
//	//	_aiGrid = &ai_t2;
//	//	break;
//	//case 3:
//	//	_aiGrid = &ai_t3;
//	//	break; 
//	//case 4:
//	//	_aiGrid = &ai_t4;
//	//	break;
//	//case 5:
//	//	_aiGrid = &ai_t5;
//	//	break;
//	default:
//#if DEBUG == 0
//		Serial.print("ERROR IN RANDOM CHOOSE ");
//		Serial.println(rnd);
//
//#endif
//		break;
//	}
//#if DEBUG == 0
//	Serial.print("GOT END OF CHOOSE ");
//	Serial.println(rnd);
//#endif
//}
//
//void Game::
//checkIsDestroyed(int x, int y)
//{
//	if (_grid.chekValue(x,y) == Grid::Node::BOAT || _grid.chekValue(x, y) == Grid::Node::SHOT_AND_BOAT)
//	{
//		_AI._ai = AIState::AIMING;
//		_AI.aimingX = x;
//		_AI.aimingY = y;
//	}
//	else
//	{
//		_AI._ai = AIState::Searching;
//		(*_aiGrid)[y - 1][x - 1] = SHOTAI;
//	}
//}
//
