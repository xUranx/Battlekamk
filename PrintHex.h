#pragma once
#include "Arduino.h"
using namespace std;
class PrintHex
{
public:
	int x = 0;
	int y = 0;
public:
	PrintHex();
	~PrintHex();

	void Print(const uint8_t *tex);

};

