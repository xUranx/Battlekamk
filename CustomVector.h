#pragma once

template<class T>
struct CustomVector
{
	T y[10];
	void setValue(T _y){
		if (amount < 10)
		{
		y[amount++] = _y; }
		}
	int amount = 0;

	//Ts reSized()
	//{ 
	//	T temp[amount];
	//	for (int i = 0; i < amount; i++)
	//	{
	//		y[i] = temp[i];
	//	}
	//	return temp;
	//}

	
	//operator
	T& operator[](int index) { 
		
		if (index < amount)
		{
		return y[index]; }
		}
		else
		{
			if (amount < 0)
			{
			return y[amount-1];
			}
			else
			{
				return y[0];
			}
		}

		
};