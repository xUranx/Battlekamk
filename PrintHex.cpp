#include "PrintHex.h"
#include "S1D13700.h"
PrintHex::PrintHex()
{
}


PrintHex::~PrintHex()
{
}

void PrintHex::Print(const uint8_t *tex, int _x, int _y)
{
	S1D13700 lcd;
	x = _x;
	y = _y;
	int ins = 1;
	int comp = 1;
	Serial.print(*tex);
	while (*tex != 0x03)
	{
		if (*tex == 0x01)
		{
			Serial.print("test");
			tex++;
			uint8_t count = *tex;
			tex++;
			uint8_t value = *tex;
			tex++;
			if (value == 0x00)
			{
				if (ins == 1)
				{
					for (uint8_t i = 0x00;i < count;i++)
					{
						for (int i = 0; i < 8; i++)
						{
							x++;
						}
						if (x >= 320)
						{
							x = _x;
							y++;
						}
					}
				}
			}
			else
			{
				
				int bint[8] = { 0 };
				if (value == 0xFF)
				{
					for (uint8_t i = 0x00;i < count;i++)
					{
						for (int j = 0; j < 8; j++)
						{
							lcd.setPixel(x, y, 1);
							x++;
						}
						if (x >= 320)
						{
							x = _x;
							y++;
						}
					}
				}
				else
				{
					CalcHex(value, bint);
					for (uint8_t i = 0x00;i < count;i++)
					{
						for (int j = 0; j < 8; j++)
						{
							lcd.setPixel(x, y, bint[j]);
							x++;
						}
						if (x >= 320)
						{
							x = _x;
							y++;
						}
					}
				}
			}	
		}
		else if(*tex==0x00)
		{
			
			tex++;
			uint8_t count = *tex;
			tex++;
			for (uint8_t i = 0x00; i < count;i++)
			{
				int bint[8] = { 0 };
				CalcHex(*tex, bint);

				for (int j = 0; j < 8; j++)
				{
					lcd.setPixel(x, y, bint[j]);
					x++;
				}
				if (x >= 320)
				{
					x = _x;
					y++;
				}
				tex++;
				
			}
		}
		if (x >= 320)
		{
			x = _x;
			y++;
		}
		
	}
}
void PrintHex::CalcHex(uint8_t value, int *bint)
{
	if (value - 0x80 >= 0x00)
	{
		bint[0] = 1;
		value -= 0x80;
	}
	if (value - 0x40 >= 0x00)
	{
		bint[1] = 1;
		value -= 0x40;
	}
	if (value - 0x20 >= 0x00)
	{
		bint[2] = 1;
		value -= 0x20;
	}
	if (value - 0x10 >= 0x00)
	{
		bint[3] = 1;
		value -= 0x10;
	}
	if (value - 0x08 >= 0x00)
	{
		bint[4] = 1;
		value -= 0x08;
	}
	if (value - 0x04 >= 0x00)
	{
		bint[5] = 1;
		value -= 0x04;
	}
	if (value - 0x02 >= 0x00)
	{
		bint[6] = 1;
		value -= 0x02;
	}
	if (value - 0x01 >= 0x00)
	{
		bint[7] = 1;
		value -= 0x01;
	}
}
