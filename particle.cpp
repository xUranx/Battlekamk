#include "particle.h"
#include "ParticleValues.h"
#include "Arduino.h"


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

	int xpoint = x * _xSector + _xSpawn;
	int ypoint = y * _ySector + _ySpawn;

	for (int i = 0; i < LIFETIME; i++)
	{


		delay(UPTADERATE);
	}
}
