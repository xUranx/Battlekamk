#pragma once
#include <RF24.h>
#include <SPI.h>


class Radio
{
public:
	Radio();
	~Radio();
	void radioSetup();
	bool listenRadio(int &x, int &y);
	void sendRadio(const int x,const int y);
private:
	void emptyArray();
	uint8_t data[32];
	RF24 *radio;
};

