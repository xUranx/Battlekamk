#ifndef Joystick_h
#define Joystick_h

class Joystick
{
    

  public:
    int Sw;
    int Xcord;
    int Ycord;
    
    Joystick(void);
    int ReadX(void);
    int ReadY(void);
    bool Button(void);

   
};
#endif 

