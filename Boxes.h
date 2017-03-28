#pragma once
#include "CustomVector.h"
class S1D13700;
struct Boxes
{
	S1D13700 *_handler= nullptr;
	CustomVector vectors[5];
	int index = 0;
	void init(S1D13700 *handler, CustomVector &vecYPOSes, const int RX, const int LX){
		_handler = handler; 
		int _i = 0;
		for (int i = 0; i < vecYPOSes.amount/2; i ++)
		{
			CustomVector temp;
			temp.setValue(LX);
			temp.setValue(vecYPOSes.y[_i++]);
			temp.setValue(RX);
			temp.setValue(vecYPOSes.y[_i++]);
			vectors[index++] = temp;
		}
	}
	void drawBox(int which){
		if (which < index)
		{
			_handler->drawBox(vectors[which].y[0], vectors[which].y[1], vectors[which].y[2], vectors[which].y[3]);
		}
	}
};