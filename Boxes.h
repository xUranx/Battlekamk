#pragma once
#include "CustomVector.h"
#include "S1D13700.h"
#include "Defines.h"
struct Boxes
{
	S1D13700 *_handler= nullptr;
	CustomVector<CustomVector <int>> vectors;
	int index = 0;
	void init(S1D13700 *handler, CustomVector<int> &vecYPOSes){
		_handler = handler; 
		int _i = 0;
		for (int i = 0; i < vecYPOSes.amount/2; i ++)
		{
			CustomVector<int> temp;
			temp.setValue(LX);
			temp.setValue(vecYPOSes.y[_i++]);
			temp.setValue(RX);
			temp.setValue(vecYPOSes.y[_i++]);
			vectors.setValue(temp);
			index++;
		}
	}
	void drawBox(int which,int visible = 1){
		if (which < index)
		{
			_handler->drawBox(vectors[which][0], vectors[which][1], vectors[which][2], vectors[which][3],visible);
		}
	}
};