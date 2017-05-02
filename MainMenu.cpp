#include "MainMenu.h"
#include "Defines.h"
#include "Joystick.h"
#include "S1D13700.h"

MainMenu::MainMenu() : UY(0), DY(0), _handler(nullptr), _stick(nullptr), _divide(0), _index(0)
{
}


MainMenu::~MainMenu()
{
}
void MainMenu::
init(S1D13700 *handler, Joystick *stick, const int boxAmount)
{
	_handler = handler;
	_stick = stick;
	_divide = boxAmount + 1;
	this->getBoxPositions(boxAmount);
}
void MainMenu::getBoxPositions(int boxAmount)
{
	CustomVector<int> vector;
	CustomVector<int> middleVector;
	int boxPos = 0;
	if (_divide != 0)
	{
	boxPos = SCREENHEIGHT / _divide;
	}
	int box = boxPos;
	for (int i = 0; i < boxAmount; i++)
	{
		middleVector.setValue(box);
		box += boxPos;
	}

	for (int i = 0; i < middleVector.amount; i++)
	{
		vector.setValue(middleVector.y[i] - PIXELDIFFERENCE);
		vector.setValue(middleVector.y[i] + PIXELDIFFERENCE);
	}
	_boxes.init(_handler,vector);

	if (_boxes.index != boxAmount)
	{
		char buff[] = "Boxes not equal to amount ";
		fatalError(_handler,buff);
	}
}

void MainMenu::
write(CustomVector<CustomVector <char>> &word)
{
	_handler->clearGraphic();
	_handler->clearText();
	this->drawBox();
	int plus = TEXTXHEIGHT / (_boxes.index+1);
	int ySize = plus;
	int texts = 0;
	if (word.amount == _boxes.index)
	{
#if DEBUG == 0
		Serial.print(" String amount ");
		Serial.print(word.amount);
#endif // DEBUG =



		
	for (int i = 0; i < _boxes.index; i++)
	{ 
		_handler->textGoTo(TEXTX,ySize);

		_handler->writeText(word[i].y);//get the WORD!!!
		ySize += plus;
		texts++;
	}
	}
	else
	{
#if DEBUG == 0
		Serial.println(" String amount ");
		Serial.println(word.amount);
#endif // DEBUG =

		char buff[] = "Not correct string amount";
		fatalError(_handler,buff);
	}

}
void MainMenu::
drawBox(BoxPos where)// olettaa default
{
	_boxes.drawBox(_index,0);
	if (where == BoxPos::_DEFAULT)
	{
		_boxes.drawBox(0);
	}
	if (where == BoxPos::_DOWN)
	{
		this->setIndex(Index::DOWN);
		_boxes.drawBox(_index);
	}
	if (where == BoxPos::_UP)
	{
		this->setIndex(Index::UP);
		_boxes.drawBox(_index);
	}
}
void MainMenu::
setIndex(Index where)
{
	if (where == Index::DOWN)
	{
		if (_index == _boxes.index-1)
		{
			_index = 0;
		}
		else
		{
			++_index;
		}
	}
	else if (where == Index::UP)
	{
		if (_index == 0)
		{
			_index = _boxes.index-1;
		}
		else
		{
			--_index;
		}
	}		
#if DEBUG == 0
		Serial.println("current index is ");
		Serial.println(_index);
#endif // DEBUG =
}
int MainMenu::
loop()
{
	_index = 0;
	bool button = false;// TÄHÄN TULEE NAPIN LUKU
	do
	{
		delay(100);
		int where = _stick->ReadY();

		if (!_stick->Button())
		{
			switch (where)
			{
			case 1:
				this->drawBox(BoxPos::_UP);
				break;
			case -1:
				this->drawBox(BoxPos::_DOWN);
				break;
			default:
				break;
			}
		}
		else
		{
			button = true;
		}
	} while (!button);
	return _index;
}


