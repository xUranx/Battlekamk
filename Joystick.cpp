#include "Joystick.h"
#include "Arduino.h"

Joystick::Joystick(void)
{
  Sw = 2;
  Xcord = A0;
  Ycord = A1;
  pinMode(Sw, INPUT);
}

int Joystick::ReadX(void)
{
  int result = analogRead(Xcord);
  int C = (result*10/1023);  
  if(C > 9)
  {
    return 1;
  }
  else if(C<1)
  {
    return -1;
  }
  else
  {
    return 0;
  }
}
int Joystick::ReadY(void)
{
  int result = analogRead(Ycord);
  float voltage = (result*10/1023);
  int C= floor(voltage+0.5);  
  if(C > 9)
  {
    return 1;
  }
  else if(C<1)
  {
    return -1;
  }
  else
  {
    return 0;
  }
}
bool Joystick::Button(void)
{
  int State = digitalRead(Sw);
  if(State == HIGH)
  {
    return true;
  }
  else
  {
    return false;
  }
}
