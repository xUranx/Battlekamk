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
	index = 0;
	while ((uint8_t*)pgm_read_byte(tex + index) != 0x03)
	{
		
		if ((uint8_t*)pgm_read_byte(tex + index) == 0x01)
		{
			index++;
			uint8_t count = (uint8_t*)pgm_read_byte(tex + index);
			index++;
			uint8_t value = (uint8_t*)pgm_read_byte(tex + index);
			index++;
			if (value == 0x00)
			{
				if (ins == 1)
				{
					for (uint8_t i = 0x00;i < count;i++)
					{	
						x++;				
						if (x >= 320/8)
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

						printBTM(value);
						x++;
						
						if (x >= 320/8)
						{
							
							x = _x;
							y++;
						}
					}
				}
				else
				{
					for (uint8_t i = 0x00;i < count;i++)
					{

						printBTM(value);
						x++;
						if (x >= 320/8)
						{
							
							x = _x;
							y++;
						}
					}
				}
			}	
		}
		else if((uint8_t*)pgm_read_byte(tex + index)==0x00)
		{
			
			index++;
			uint8_t count = (uint8_t*)pgm_read_byte(tex + index);
			index++;
			for (uint8_t i = 0x00; i < count;i++)
			{

				printBTM(pgm_read_byte(tex + index));
				x++;

				if (x >= 320/8)
				{
					
					x = _x;
					y++;
				}
				index++;
				
			}
		}
		if (x >= 320/8)
		{
			
			x = _x;
			y++;
		}
		
	}
}


void PrintHex::printBTM(uint8_t tex)
{
	S1D13700 lcd;
	lcd.setCursorAddress(S1D13700_GRAPHICSTART + (40 * y) + x);
	lcd.writeCommand(S1D13700_MWRITE);
	//(width % 8 != 0))
	lcd.writeData(tex);
}
