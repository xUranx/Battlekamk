#pragma once
#include <RF24.h>
#include <SPI.h>


class Radio
{
public:
	static void radioSetup();
	static bool listenRadio(int &x, int &y);
	static void sendRadio(const int x,const int y);
private:
	static void emptyArray();
	static uint8_t data[32];
	static RF24 radio;
};

