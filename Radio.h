#pragma once
#include <RF24.h>
#include <SPI.h>


enum class RADIO 
{
	SEND_GET,SEND,GET_SEND,GET
};

class Radio
{
public:
	static void radioSetup();
	static bool listenRadio(int &x, int &y);
	static void sendRadio(int x, int y);
private:
	static void emptyArray();
	static bool getResponse();
	static void GetXY(int &yx);
	static void sendResponse();
	static uint8_t data[32];
	static RF24 radio;
};

