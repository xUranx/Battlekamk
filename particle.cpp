#include "particle.h"
#include "ParticleValues.h"
#include "Arduino.h"
#include "S1D13700.h"


particle::particle(S1D13700 *handler):_handler(handler),_xSector(320/11),_ySector(240/11),_xSpawn(5),_ySpawn(5)
{
}


particle::~particle()
{
}
void particle::Explode(int x,int y)
{
	x -= 1;
	y -= 1;

	int xpoint = x * _xSector + _xSpawn + 20;
	int ypoint = y * _ySector + _ySpawn + 20;
	for (int i = 0; i < 100; i++)
	{
		do
		{
			arvot[i].prevx = xpoint;
			arvot[i].prevy = ypoint;
			arvot[i].x = random(-3, 4);
			arvot[i].y = random(-3, 4);
			arvot[i].spawnPoint = random(5, 20);
			//Serial.println(arvot[i].x);
			//Serial.println(arvot[i].y);
		} while (arvot[i].x == 0 && arvot[i].y == 0);
	}

	int vertailu = 0;
	for (int i = 0; i < LIFETIME; i++)
	{
		vertailu++;
		for (int amount = 0; amount < 100; amount++)
		{
			if (arvot[amount].prevx > 10 && arvot[amount].prevx < 300 && arvot[amount].prevy > 10 && arvot[amount].prevy < 230)
			{
				if (arvot[amount].spawnPoint < vertailu)
				{
				_handler->setPixel(arvot[amount].prevx, arvot[amount].prevy, 0);
				_handler->setPixel(arvot[amount].prevx + 1, arvot[amount].prevy + 1, 0);
				_handler->setPixel(arvot[amount].prevx - 1, arvot[amount].prevy - 1, 0);
				_handler->setPixel(arvot[amount].prevx - 1, arvot[amount].prevy, 0);
				_handler->setPixel(arvot[amount].prevx + 1, arvot[amount].prevy, 0);
				_handler->setPixel(arvot[amount].prevx, arvot[amount].prevy + 1, 0);

				int rn = random(-1, 1);

				arvot[amount].prevx += arvot[amount].x + rn;
				arvot[amount].prevy += arvot[amount].y + rn;

				
				//Serial.println("pate nopeus");

				//Serial.println(arvot[amount].x);
				//Serial.println(arvot[amount].y);

				//Serial.println("pate");

				//Serial.println(arvot[amount].prevx);
				//Serial.println(arvot[amount].prevy);

				// piirretään tetris palikka
				_handler->setPixel(arvot[amount].prevx, arvot[amount].prevy, 1);
				_handler->setPixel(arvot[amount].prevx + 1, arvot[amount].prevy + 1, 1);
				_handler->setPixel(arvot[amount].prevx - 1, arvot[amount].prevy - 1, 1);
				_handler->setPixel(arvot[amount].prevx - 1, arvot[amount].prevy, 1);
				_handler->setPixel(arvot[amount].prevx + 1, arvot[amount].prevy, 1);
				_handler->setPixel(arvot[amount].prevx, arvot[amount].prevy+1, 1);

				}
			}
			//delay(UPTADERATE);
		}
	}
}
void particle::
rain()
{
	for (int i = 0; i < 100; i++)
	{
		do
		{
			arvot[i].prevx = random(1,319);
			arvot[i].prevy = 5;
			arvot[i].x = random(-3, 4);
			arvot[i].y = random(1, 4);
			arvot[i].spawnPoint = random(5, 20);
			//Serial.println(arvot[i].x);
			//Serial.println(arvot[i].y);
		} while (arvot[i].x == 0 && arvot[i].y == 0);
	}
	int vertailu;
	for (int i = 0; i < LIFETIME; i++)
	{
		vertailu++;
		for (int amount = 0; amount < 100; amount++)
		{
			if (/*arvot[amount].prevx > 10 && arvot[amount].prevx < 300 && arvot[amount].prevy > 4 && */arvot[amount].prevy < 230)
			{
				if (arvot[amount].spawnPoint < vertailu)
				{
					_handler->setPixel(arvot[amount].prevx, arvot[amount].prevy, 0);
					_handler->setPixel(arvot[amount].prevx + 1, arvot[amount].prevy + 1, 0);
					_handler->setPixel(arvot[amount].prevx - 1, arvot[amount].prevy - 1, 0);
					_handler->setPixel(arvot[amount].prevx - 1, arvot[amount].prevy, 0);
					_handler->setPixel(arvot[amount].prevx + 1, arvot[amount].prevy, 0);
					_handler->setPixel(arvot[amount].prevx, arvot[amount].prevy + 1, 0);
					int rn = 0;
					if (arvot[amount].prevx > 2 && arvot[amount].prevx < 316)
					{
					rn = random(-1, 1);
					}

					arvot[amount].prevx += arvot[amount].x + rn;
					arvot[amount].prevy += arvot[amount].y + rn;


					//Serial.println("pate nopeus");

					//Serial.println(arvot[amount].x);
					//Serial.println(arvot[amount].y);

					//Serial.println("pate");

					//Serial.println(arvot[amount].prevx);
					//Serial.println(arvot[amount].prevy);

					// piirretään tetris palikka
					_handler->setPixel(arvot[amount].prevx, arvot[amount].prevy, 1);
					_handler->setPixel(arvot[amount].prevx + 1, arvot[amount].prevy + 1, 1);
					_handler->setPixel(arvot[amount].prevx - 1, arvot[amount].prevy - 1, 1);
					_handler->setPixel(arvot[amount].prevx - 1, arvot[amount].prevy, 1);
					_handler->setPixel(arvot[amount].prevx + 1, arvot[amount].prevy, 1);
					_handler->setPixel(arvot[amount].prevx, arvot[amount].prevy + 1, 1);

				}
			}
			//delay(UPTADERATE);
		}
	}
}

