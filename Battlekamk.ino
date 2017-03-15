//#include <ArduinoSTL.h> // includaa vactorit yms.yms
#include "Defines.h"
#include "S1D13700.h"
#include "menu.h"
#include "Joystick.h"



//#define DEBUG true

Joystick _stick;
S1D13700 LCD;

void setup() {
  // put your setup code here, to run once:
	Serial.begin(9600);
    LCD.initLCD();
    LCD.clearText();
    LCD.clearGraphic();
	
//    pinMode(buttonPin1, INPUT);
//    pinMode(buttonPin2, INPUT);
//    pinMode(buttonPin3, INPUT);
    //LCD.textGoTo(10,10);
    //char buf[] = "Setboats";
    //LCD.writeText(buf);
    
}

void loop() 
{
   //menu kakka(_stick,LCD);
   //for(;;){}
	LCD.textGoTo(10,10);
	char buf[] = "Test";
	LCD.writeText(buf);
	for (;;){}
  
}

