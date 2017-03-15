#ifndef menu_h
#define menu_h
#include "S1D13700.h"
#include "Defines.h"
class Joystick;

enum class MENUENUM
{
  UP,MIDDLE,DOWN,CLEAR,DONT_CLEAR
};

class menu
{
public:
  menu(Joystick &stick,S1D13700 &LCD);
  ~menu();
  int startMenu();
private:
  void moveBox(MENUENUM STATE);
  void setBoxPos(int _x0,int _y0, int _x1,int _y1);
  MENUENUM getBoxPos(MENUENUM _where);
  int x0;
  int y0;
  int x1;
  int y1;
  S1D13700 _handler;
 /* bool _button1;
  bool _button2;
  bool _button3;*/
  void printTXT();// Päätä miten tehdään
  
  Joystick *_stick;

  
};
#endif
