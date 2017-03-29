#include "Defines.h"
#include "S1D13700.h"
void fatalError(S1D13700 *_handler, char buff[])
{
	_handler->clearText();
	_handler->clearGraphic();
	_handler->textGoTo(13,10);
	_handler->writeText(buff);
	for (;;)
	{

	}
}