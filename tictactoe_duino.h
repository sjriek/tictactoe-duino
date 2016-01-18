

/* tictactoe_duino.h
 
 
 */

#ifndef tictactoe_duino_h
#define tictactoe_duino.h

//#include "WProgram.h"
#include "Arduino.h"

/* Assign Arduino Pin numbers*/
#define BUT_COL_0 2
#define BUT_COL_1 3
#define BUT_COL_2 4
#define BUT_ROW_0 5
#define BUT_ROW_1 6
#define BUT_ROW_2 7
#define LED_RED_COL_0 8
#define LED_GREEN_COL_0 9
#define LED_RED_COL_1 10
#define LED_GREEN_COL_1 11
#define LED_RED_COL_2 12
#define LED_GREEN_COL_2 13
#define LED_ROW_0 14
#define LED_ROW_1 15
#define LED_ROW_2 16
#define BUT_GAME 17
#define LED_RED_GAME 18
#define LED_GREEN_GAME 19

#define NONE 0
#define GREEN 1
#define RED 2
#define ORANGE 3


void show_board();
extern void set_ledNr(int pos, int color);
extern void set_led(int x, int y, int color);
extern int check_buttons();
extern void initialisation();
int get_button(int &Xbut,int &Ybut);
void set_game_led(int player);

#endif

