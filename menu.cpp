#include "menu.h"

#include "Joystick.h"
typedef MENUENUM _m;

menu::menu(Joystick &stick,S1D13700 &LCD)
{
  x0=40;
  y0=15;
  x1=280;
  y1=75;
  _handler = LCD;
  _stick = &stick;
  
  this->startMenu();
}
menu::~menu()
{
}
void menu::
moveBox(MENUENUM STATE)
{
  _handler.drawBox(x0,y0,x1,y1,0);
  switch (STATE)
  {
   case _m::UP:
   this->setBoxPos(40,15,280,75);
   _handler.drawBox(x0,y0,x1,y1);
   break; 
   case _m::MIDDLE:
   this->setBoxPos(40,90,280,150);
   _handler.drawBox(x0,y0,x1,y1);
   break; 
   case _m::DOWN:
   this->setBoxPos(40,165,280,225);
   _handler.drawBox(x0,y0,x1,y1);
   break; 
   default:
   
   break;
  }
  
}
int menu::
startMenu()
{
  this->printTXT();
do
{
	int button = 0;

	delay(100);// vähentää hektisyyttä

do{
   int stickButton = 0;
   int where =_stick->ReadY();
   if (where == 1 && stickButton == 0)
      {
        button = 2;
#if (DEBUG == 1)    
Serial.println("Button is registered: " );
#endif
        break;
      }
   else if (where == -1 && stickButton == 0)
      {
        button = 1;
#if (DEBUG == 1)    
Serial.println("Button is registered: " );
#endif
        break;
      }
      else if(stickButton != 0)
      {
          button = 3;
      }
  }
  while(button == 0);
  switch (button)
  {
  case 1:
	  moveBox(getBoxPos(MENUENUM::DOWN));
	  break;

  case 2:
	  moveBox(getBoxPos(MENUENUM::UP));
	  break;

  case 3:
  {
	  if (y0 == 15)
	  {
		  return 1;
	  }
	  else if (y0 == 90)
	  {
		  return 2;
	  }
	  else
	  {
		  return 3;
	  }
  }
  break;
  }


} while(true);
}


void menu::
setBoxPos(int _x0,int _y0, int _x1,int _y1)
{
   x0 = _x0;
   y0 = _y0;
   x1 = _x1;
   y1 = _y1;
}
MENUENUM menu::
getBoxPos(MENUENUM _where)
{
  if(_where == MENUENUM::DOWN)
  {
  if (y0 == 15){return MENUENUM::MIDDLE;}
  else if(y0 == 90){return MENUENUM::DOWN;}
  else{return MENUENUM::UP;}
  }
   if(_where == MENUENUM::UP)
  {
  if (y0 == 15){return MENUENUM::DOWN;}
  else if(y0 == 90){return MENUENUM::UP;}
  else{return MENUENUM::MIDDLE;}
  }
  
}
void menu::printTXT()
{
  moveBox(MENUENUM::UP);
  char buf[] = "Play PvP";
  _handler.textGoTo(13,5);
  _handler.writeText(buf);
  char buf2[] = "Play agains AI";
  _handler.textGoTo(13,16);
  _handler.writeText(buf2);
  char buf3[] = "Set boats";
  _handler.textGoTo(13,25);
  _handler.writeText(buf3);
  
  
}


