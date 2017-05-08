#pragma once
class S1D13700;

struct Pvalues
{
	int x, y;
	int prevx, prevy;
};

class particle
{
public:
	particle(S1D13700 *handler);
	~particle();
	void Explode(int x, int y);
private:
	S1D13700 *_handler;
	int _xSector;
	int _ySector;
	int _xSpawn;
	int _ySpawn;
};

