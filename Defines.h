#pragma once

//#define buttonPin1  2/*********************************************/
//#define buttonPin2  3/*                    MUOKKAA TÄTÄ           */
//#define buttonPin3  4/*********************************************/
#define DEBUG 0
#define MAXLONG 1 //max values are amount values
#define MAXMED 2
#define MAXSHORT 3
#define LONG_LEN 4 //len values are lenght values
#define SHORT_LEN 2
#define MED_LEN 3
#define RX 280
#define LX 40
#define TEXTX 13
#define TEXTXHEIGHT 30 //35
#define PIXELDIFFERENCE 20
#define SCREENHEIGHT 240
#define SCREENWIDHT 320
#define CIRCLERADIUS 10
#define BOXWIDHT 20
#define BOXHEIGHT 16
#define PLAYER 1 //muuta pelaajaa kun vaihat yksikköä
#define LED 13 //muuta tätä
#define analogPin A0 // muuta näitä

class S1D13700;
extern void fatalError(S1D13700 *_handler, char buff[]);
