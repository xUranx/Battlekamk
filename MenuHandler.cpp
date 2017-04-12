#include "MenuHandler.h"
#include "Coordinates.h"
#include "Joystick.h"
MenuHandler::MenuHandler(S1D13700 *handler, Joystick *stick) : _handler(handler), _stick(stick)
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
	_boatChecker.init(&_grid);
}
void MenuHandler::
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

		int choise = 1;
		do
		{
			switch (choise)
			{
			case 1:
			{
			Serial.println("Started main menu loop");
			_main.write(wordsM);
			int a = _main.loop();
			Serial.println("Loop said ");
			Serial.println(a);
			if (a == 2)
			{
				choise = 3;
			}
			else
			{
				choise = 1;
			}
			break;
			}
			case 2:
			{
				Serial.println("Started dir menu loop");
				_dirMen.write(wordsD);
				Serial.println("Loop said ");
				int c = _dirMen.loop();
				int x = 0;
				int y = 0;
				if (c != 2)
				{
				_coo.drawCoord();
				bool b = false;
				do
				{
				_coo.coordLoop(x,y);
				} while (!_boatChecker.isValid(x,y));

				}
				Serial.println(c);
				Serial.println(x);
				Serial.println(y);
				choise = 3;
				break;
			}
			case 3:
			{
				Serial.println("Started boat menu loop");
				_boats.write(wordsB);
				Serial.println("Loop said ");
				int b = _boats.loop();
				Serial.println(b);
				if (b == 3)
				{
					choise = 1;
				}
				else if (b  == 0 || b == 1 || b==2)
				{
					choise = 2;
				}
				else
				{
					choise = 1;
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




