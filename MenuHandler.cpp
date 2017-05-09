#include "MenuHandler.h"
#include "Coordinates.h"
#include "Joystick.h"
#include "Grid.h"
#include "Defines.h"
MenuHandler::MenuHandler(S1D13700 *handler, Joystick *stick,Grid *grid) : _handler(handler), _stick(stick),_grid(grid)
{
}


MenuHandler::~MenuHandler()
{
}
void MenuHandler::
initClasses()
{
	_main.init(_handler,_stick,3);
	_boats.init(_handler, _stick, 4);
	_dirMen.init(_handler,_stick,3);
	_coo.init(_handler,_stick);
	_boatChecker.init(_grid);
}
int MenuHandler::
menuLoop()
{

	for (;;)
	{
		Serial.println("Started menu loop");
		/*----------------------------------*/
		CustomVector <CustomVector<char>> wordsM;
		CustomVector<char> word1;

		char array1[4] = "PVP";
		this->setWord(word1, array1, 4);
		CustomVector<char> word2;
		char array2[3] = "AI";
		this->setWord(word2, array2, 3);
		CustomVector<char> word3;
		char array3[10] = "SET_BOATS";
		this->setWord(word3, array3, 10);


		wordsM.setValue(word1);
		wordsM.setValue(word2);
		wordsM.setValue(word3);

		/*----------------------------------*/
		CustomVector <CustomVector<char>> wordsB;
		CustomVector<char> wordB1;

		char arrayB1[5] = "Long";
		this->setWord(wordB1, arrayB1, 5);
		CustomVector<char> wordB2;
		char arrayB2[7] = "Medium";
		this->setWord(wordB2, arrayB2, 7);
		CustomVector<char> wordB3;
		char arrayB3[6] = "Short";
		this->setWord(wordB3, arrayB3, 6);
		CustomVector<char> wordB4;
		char arrayB4[6] = "Back";
		this->setWord(wordB4, arrayB4,5);

		wordsB.setValue(wordB1);
		wordsB.setValue(wordB2);
		wordsB.setValue(wordB3);
		wordsB.setValue(wordB4);
		/*----------------------------------*/
		
		CustomVector <CustomVector<char>> wordsD;
		CustomVector<char> wordD1;

		char arrayD1[11] = "Horizontal";
		this->setWord(wordD1, arrayD1, 11);
		CustomVector<char> wordD2;
		char arrayD2[9] = "Vertical";
		this->setWord(wordD2, arrayD2, 9);


		wordsD.setValue(wordD1);
		wordsD.setValue(wordD2);
		wordsD.setValue(wordB4);//back

		/*----------------------------------*/
		Boats::Type btyp;
		int choise = 1;
		do
		{
			switch (choise)
			{
			case 1:                            /*            MAIN MENU          */
			{
#if DEBUG == 0
			Serial.println("Started main menu loop");
#endif // DEBUG =
			_main.write(wordsM);
			int a = _main.loop();
#if DEBUG == 0
			Serial.println("Loop said ");
			Serial.println(a);
#endif // DEBUG =
			if (a == 2) //boat menu
			{
				choise = 3;
			}
			else if (a = 0) // PVP
			{
				if (_boatChecker.checkAmount())
				{
					return 0; //PVP
				}
				else
				{
				choise = 1;
#if DEBUG == 0
				Serial.println("NO CORRECT AMOUNT OF BOATS ");
#endif // DEBUG =
				}
			}
			else
			{
				if (_boatChecker.checkAmount())
				{
					return 1; 
				}
				else
				{
					choise = 1;
#if DEBUG == 0
					Serial.println("NO CORRECT AMOUNT OF BOATS ");
#endif // DEBUG =
				}
			}
			break;
			}
			case 2:                                                /*            DIRECTION MENU          */
			{
#if DEBUG == 0
				Serial.println("Started dir menu loop");
#endif // DEBUG =

				_dirMen.write(wordsD);
#if DEBUG == 0
				Serial.println("Loop said ");
#endif // DEBUG =
				int c = _dirMen.loop();              //returns 0,1,2 = HORIZONTAL, VERTICAL, back
				int x = 0;
				int y = 0;

				if (c != 2)
				{
				Boats::Type vectype = Boats::Type::HORIZONTAL;
					if (c == 1)
					{
						vectype = Boats::Type::VERTICAL;
					}
				_coo.drawCoord();
				for (int y = 1; y < 11; y++)
				{
					for (int x = 1; x < 11; x++)
					{
						Grid::Node _node = _grid->chekValue(x, y);
						if (_node == Grid::Node::BOAT)
						{
							_coo.drawShape(Shape::Box, x, y);
						}
					}
				}
				//_grid-> TO DO
				bool b = false;
#if DEBUG == 0
				switch (btyp)
				{
				case Boats::Type::LONG:
					Serial.println("printing long");
					break;
				case Boats::Type::MED:
					Serial.println("printing med");
					break;
				case Boats::Type::SHORT:
					Serial.println("printing shotr");
					break;
				default:
					Serial.println("TRYING TO ADD UNKNOWN TYPE");
					break;
				}
#endif // DEBUG =
				do
				{
				_coo.coordLoop(x,y);				// does as long as position is valid and HAS NO BACK BUTTON
#if DEBUG == 0
				Serial.println("coord loop said X , Y = ");
				Serial.print(x);
				Serial.print(" ");
				Serial.println(y);
#endif // DEBUG =
				} while (!_boatChecker.isValid(x,y,btyp,vectype));				
				//_boatChecker.placeBoat(btyp, vectype); place boat if valid
				}
#if DEBUG == 0
				Serial.println(c);
				Serial.println(x);
				Serial.println(y);
#endif // DEBUG =
				choise = 3;
				break;
			}
			case 3:												 /*            BOAT CHOICE MENU          */
			{
#if DEBUG == 0
				Serial.println("Started boat menu loop");
#endif // DEBUG =
				_boats.write(wordsB);
#if DEBUG == 0
				Serial.println("Loop said ");
#endif // DEBUG =
				int b = _boats.loop();
#if DEBUG == 0
				Serial.println(b);
#endif // DEBUG =
				if (b == 3)
				{
					choise = 1;
				}
				else if (b  == 0 || b == 1 || b==2)
				{
					bool correctBoatAmount = true;
					switch (b)
					{
					case 0:
						btyp = Boats::Type::LONG;
						correctBoatAmount = _boatChecker.checkIsTooMuch(Boats::Type::LONG);
						break;
					case 1:
						btyp = Boats::Type::MED;
						correctBoatAmount = _boatChecker.checkIsTooMuch(Boats::Type::MED);
						break;
					case 2:
						btyp = Boats::Type::SHORT;
						correctBoatAmount = _boatChecker.checkIsTooMuch(Boats::Type::SHORT);
						break;
					default:
						btyp = Boats::Type::SHORT;
#if DEBUG == 0
						Serial.println("ERROR, USED DEFAULT CASE IN CASE 3");
#endif // DEBUG =
						break;
					}
					if (correctBoatAmount)
					{
					choise = 2;
					}
				}
				break;
			}
			case 4:
				break;
			case 5:
				break;
			case 6:
				break;
			default:
				break;
			}
		} while (true);
	}
}
void MenuHandler::
setWord(CustomVector<char> &word,char array[], int size)
{
	array[size - 1] = '\0';
	for (int i = 0; i < size; i++)
	{
		word.setValue(array[i]);
	}
}




