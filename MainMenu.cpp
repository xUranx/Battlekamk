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
	boxPos = screenHeight / _divide;
	}
	int box = boxPos;
	for (int i = 0; i < boxAmount; i++)
	{
		middleVector.setValue(box);
		box += boxPos;
	}

	for (int i = 0; i < middleVector.amount; i++)
	{
		vector.setValue(middleVector.y[i] - _pixelDifference);
		vector.setValue(middleVector.y[i] + _pixelDifference);
	}
	_boxes.init(_handler,vector,RX,LX);
	Serial.print("box ammount ");//TESTIÄ
	Serial.print(_boxes.vectors.amount);//TESTIÄ
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
	int plus = TEXTXHEIGHT / (_boxes.index+1);
	int ySize = plus;
	int texts = 0;
	if (word.amount == _boxes.index)
	{
		Serial.print(" String amount ");

		Serial.print(word.amount);


		
	for (int i = 0; i < _boxes.index; i++)
	{ 
		_handler->textGoTo(TEXTX,ySize);

		
		// 
		_handler->writeText(word[i].y);//get the WORD!!!
		ySize += plus;
		texts++;
	}
	}
	else
	{
		Serial.print(" String amount ");

		Serial.print(word.amount);
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
		if (_index == _boxes.index)
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
		Serial.print(_index);
	}
}
int MainMenu::
loop()
{
	bool button = false;// TÄHÄN TULEE NAPIN LUKU
	do
	{
		delay(100);
		int where = _stick->ReadY();
		if (button == 0)
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
	} while (!button);
	return _index;
}


