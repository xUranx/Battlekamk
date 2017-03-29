#include "Defines.h"


void fatalError(S1D13700 *_handler, char buff[])
{
	LCD.clearText();
	LCD.clearGraphic();
	_handler->textGoTo(13,15);
	_handler->writeText(buff);
	for (;;)
	{

	}
}