#pragma once


struct CustomVector
{
	int y[10];
	void setValue(int _y){ y[amount++] = _y; }
	int amount = 0;
};