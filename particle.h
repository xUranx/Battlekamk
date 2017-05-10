#pragma once
class S1D13700;

struct Pvalues
{
	int x, y;
	int prevx, prevy;
	int spawnPoint;
};

class particle
{
public:
	particle(S1D13700 *handler);
	~particle();
	void Explode(int x, int y);
	void rain();
private:
	Pvalues arvot[150];
	S1D13700 *_handler;
	int _xSector;
	int _ySector;
	int _xSpawn;
	int _ySpawn;
};

