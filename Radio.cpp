#include "Radio.h"
#include "Defines.h"




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
#ifdef DEBUG = 0
	Serial.write("got answer: ");
	Serial.write(x);
	Serial.write(y);
#endif // DEBUG = 0


	radio.stopListening();
	unsigned long started_waiting_at = millis();

	bool timeout = false;
	while (!timeout) // sends check 
	{
		if (millis() - started_waiting_at > 250)
			timeout = true;
			radio.write(&data, sizeof(data));
	}
}
void Radio::
sendRadio(const int x, const int y)
{
#ifdef DEBUG = 0
	Serial.write("Sending coords: ");
	Serial.write(x);
	Serial.write(y);
#endif // DEBUG = 0
	do
	{
	radio.stopListening();
	data[0] = x;
	data[1] = y;
	radio.write(&data, sizeof(data));
	emptyArray();
	radio.startListening();
	} while (!radio.available());

}
void Radio::
emptyArray()
{
	for (int i = 0; i < 32; i++) // tyhjentää taulukon
	{
		data[i] = 0;
	}
}


