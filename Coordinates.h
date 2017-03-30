#pragma once
class Coordinates
{
public:
	Coordinates(S1D13700 *handler);
	~Coordinates();
	void drawCoord();
private:
	S1D13700 *_handler;
	int _screenWidht;
	int _screenHeight;
};

