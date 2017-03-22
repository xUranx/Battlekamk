#include "Radio.h"


#define LED 13
#define analogPin A0 // muuta näitä


RF24 Radio::radio(40, 53);

void Radio::radioSetup()
{
	byte pipes[][6] = { "1Node", "5Node" }; //use nodes 1Node -> 6Node

	pinMode(LED, OUTPUT);
	radio.begin();
	radio.openWritingPipe(pipes[0]);
	radio.openReadingPipe(1, pipes[1]);
	radio.startListening();
	radio.printDetails();
}
bool Radio::
listenRadio(int &x,int &y)
{
	radio.startListening();
	
		do
		{
			radio.read(&data, sizeof(data)); //lukee radion
			radio.stopListening();
			digitalWrite(LED, HIGH);
			delay(100);					// light up the LED for 100ms if it worked.
			digitalWrite(LED, LOW);

			x = data[0];
			y = data[1];
			emptyArray();
		} while (!radio.available());	//tekee niin kauan kuin saa järkeviä lukuja
		
	
	radio.stopListening();

	unsigned long started_waiting_at = millis();
	bool timeout = false;
	while (!timeout)
	{
		if (millis() - started_waiting_at > 250)
			timeout = true;

	}
}
void Radio::
sendRadio(int x, int y)
{
	do
	{
	data[0] = x;
	data[1] = y;
	radio.write(&data, sizeof(data));
	emptyArray();
	} while (!getResponse());

}
void Radio::
emptyArray()
{
	for (int i = 0; i < 32; i++) // tyhjentää taulukon
	{
		data[i] = 0;
	}
}
bool Radio::
getResponse()
{
	radio.startListening();
	radio.write(&data, sizeof(data));
	if (data[0] == 100)
	{
		emptyArray();
		radio.stopListening();
		return true;
	}
	emptyArray();
	radio.stopListening();
	return false;
}
void Radio::
sendResponse()
{
		data[0] = 100;
		radio.write(&data, sizeof(data));
		emptyArray();
}
void Radio::
GetXY(int &yx)
{
	radio.read(&data, sizeof(data));
	radio.stopListening();
	digitalWrite(LED, HIGH);
	delay(100);  // light up the LED for 100ms if it worked.
	digitalWrite(LED, LOW);
	
	yx = data[0];
	emptyArray();
	
}

