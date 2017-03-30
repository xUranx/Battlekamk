#include "Coordinates.h"


Coordinates::Coordinates(S1D13700 *handler) :_handler(handler), _screenWidht(320), _screenHeight(240)
{
}


Coordinates::~Coordinates()
{
}
void Coordinates::
drawCoord()
{
	int plus = _screenWidht / 11;
	int sector = plus;
	for (int i = 0; i < 10; i++)
	{
		_handler->drawLine(sector++,0,sector,_screenHeight);
	}
	int plusH = _screenHeight / 11;
	int sectorH = plusH;
	for (int i = 0; i < 10; i++)
	{
		_handler->drawLine(sectorH++, 0, sector, _screenHeight);// correct THIS
	}
}
	//void drawLine(int x0, int y0, int x1, int y1);