#include "PrintHex.h"
#include "S1D13700.h"
#include "Arduino.h"

PrintHex::PrintHex()
{
}


PrintHex::~PrintHex()
{
}

void PrintHex::Print(const uint8_t *tex)
{
	x = 0;
	y = 0;
	int ins = 1;
	while(*tex != 0xFFF)
	{
		
		if (*tex == 0x00)
		{
			if (ins == 1)
			{
				for (int i = 0; i < 8; i++)
				{
					x++;
				}		
			}
			tex++;
		}
		else
		{
			int bint[8] = { 0,0,0,0,0,0,0,0 };
			if (*tex - 0xFF == 0x00)
			{
				for (int j = 0; j < 8; j++)
				{
					bint[j] = 1;
				}
			}
			else
			{
				uint8_t thex = *tex;
				if (thex - 0x80 >= 0x00)
				{
					bint[0] = 1;
					thex -= 0x80;
				}
				if (thex - 0x40 >= 0x00)
				{
					bint[1] = 1;
					thex -= 0x40;
				}
				if (thex - 0x20 >= 0x00)
				{
					bint[2] = 1;
					thex -= 0x20;
				}
				if (thex - 0x10 >= 0x00)
				{
					bint[3] = 1;
					thex -= 0x10;
				}
				if (thex - 0x08 >= 0x00)
				{
					bint[4] = 1;
					thex -= 0x08;
				}
				if (thex - 0x04 >= 0x00)
				{
					bint[5] = 1;
					thex -= 0x04;
				}
				if (thex - 0x02 >= 0x00)
				{
					bint[6] = 1;
					thex -= 0x02;
				}
				if (thex - 0x01 >= 0x00)
				{
					bint[7] = 1;
					thex -= 0x01;
				}
			}
			S1D13700 GLCD;
			for (int i = 0; i < 8; i++)
			{
				GLCD.setPixel(x, y, 1);
				x++;
			}
			tex++;
			//Sleep(1);
		}
		if (x >= 320)
		{
			x = 0;
			y++;
		}
	}
}
