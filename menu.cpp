#include "menu.h"
#include "Defines.h"
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
  this->printTXT();
 // this->startMenu();
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
void menu::
startMenu()
{
 this->printTXT();
 this->moveBox(_m::UP);
int button;

  do
  {
    int where =_stick->ReadY();
 /*   if (analogRead(buttonPin1) == HIGH)
      {
        button = 3;
#if (DEBUG == 1)    
serial.println("Button is registered: " button);
#endif
        break;
      }
*/
do{
   if (where == 1)
      {
        button = 2;
#if (DEBUG == 1)    
serial.println("Button is registered: " button);
#endif
        break;
      }
   if (where == -1)
      {
        button = 1;
#if (DEBUG == 1)    
serial.println("Button is registered: " button);
#endif
        break;
      }
  }
  while(where == 0);

  switch (button)
  {
  case 1:
  //go down
  getBoxPos(MENUENUM::DOWN);
  break;
  case 2:
  //go up
  getBoxPos(MENUENUM::UP);
  break;
  case 3:
  // confirm choose;
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
 // moveBox(MENUENUM::UP);
  _handler.textGoTo(43,70);
  _handler.writeText("Set Boats");
  _handler.textGoTo(43,140);
  _handler.writeText("Play against AI");
  _handler.textGoTo(43,210);
  _handler.writeText("Play PvP");
  
  
}


