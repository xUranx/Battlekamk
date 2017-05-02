#pragma once;
#include "Arduino.h"
class PrintHex
{
public:
	int x = 0;
	int y = 0;
	int index = 0;
public:
	PrintHex();
	~PrintHex();

	void Print(const uint8_t *tex, int _x, int _y);
private:
	void printBTM(uint8_t tex);
};

