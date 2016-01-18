
/* 
 
 */

//#include "WProgram.h"
#include "Arduino.h"
#include "tictactoe_duino.h"
#include "TimerOne.h"

char LED [3][3];

int posX(int i)
{
  return (i/3); 
}

int posY(int i)
{
  return (i%3);
}

void initialisation()
{

  pinMode(BUT_ROW_0, OUTPUT);
  pinMode(BUT_ROW_1, OUTPUT);
  pinMode(BUT_ROW_2, OUTPUT);
  pinMode(BUT_COL_0, INPUT);
  pinMode(BUT_COL_1, INPUT);
  pinMode(BUT_COL_2, INPUT);
  digitalWrite(BUT_COL_0, HIGH);       // turn on pullup resistors
  digitalWrite(BUT_COL_1, HIGH);       // turn on pullup resistors
  digitalWrite(BUT_COL_2, HIGH);       // turn on pullup resistors
  digitalWrite(BUT_ROW_0, LOW); 
  digitalWrite(BUT_ROW_1, LOW); 
  digitalWrite(BUT_ROW_2, LOW); 

  pinMode(LED_ROW_0, OUTPUT);
  pinMode(LED_ROW_1, OUTPUT);
  pinMode(LED_ROW_2, OUTPUT);
  pinMode(LED_RED_COL_0, OUTPUT);
  pinMode(LED_RED_COL_1, OUTPUT);
  pinMode(LED_RED_COL_2, OUTPUT);
  pinMode(LED_GREEN_COL_0, OUTPUT);
  pinMode(LED_GREEN_COL_1, OUTPUT);
  pinMode(LED_GREEN_COL_2, OUTPUT);

  pinMode(BUT_GAME, INPUT);
  pinMode(LED_RED_GAME, OUTPUT);
  pinMode(LED_GREEN_GAME, OUTPUT);


  Timer1.initialize(7000); // refresh rate for LED's
  Timer1.attachInterrupt(show_board); 

  // test led's

  for (int i = 0 ; i<9; i++) {
    set_led(i/3,i%3, ORANGE);
    delay(20);  
  }
  digitalWrite(LED_GREEN_GAME, HIGH);
  digitalWrite(LED_RED_GAME, HIGH);
  for (int i = 0 ; i<9; i++) {
    set_ledNr(i,NONE);
    delay(20);  
  }

  digitalWrite(LED_GREEN_GAME, LOW);
  digitalWrite(LED_RED_GAME, LOW);
}


void set_ledNr(int pos, int color)
{
  if (pos==9) set_game_led(color);
  else
    LED[(pos) / 3][(pos) % 3] = color;
}

void set_led(int x, int y, int color)
{
  LED[x][y] = color; 
}

int row = 0;

void show_board()
{

  switch (row%=3)
  {
  case 0: 
    digitalWrite(LED_ROW_0, LOW);
    digitalWrite(LED_ROW_1, HIGH);
    digitalWrite(LED_ROW_2, HIGH);
    break;
  case 1: 
    digitalWrite(LED_ROW_0, HIGH);
    digitalWrite(LED_ROW_1, LOW);
    digitalWrite(LED_ROW_2, HIGH);
    break;
  case 2: 
    digitalWrite(LED_ROW_0, HIGH);
    digitalWrite(LED_ROW_1, HIGH);
    digitalWrite(LED_ROW_2, LOW);
    break;
  }

  //1st colum
  if (LED[row][0] == RED) {
    digitalWrite(LED_GREEN_COL_0, LOW);
    digitalWrite(LED_RED_COL_0, HIGH);
  } 
  else
    if (LED[row][0] == GREEN) {
      digitalWrite(LED_GREEN_COL_0, HIGH);
      digitalWrite(LED_RED_COL_0, LOW);
    } 
    else
      if (LED[row][0] == ORANGE) {
        digitalWrite(LED_GREEN_COL_0, HIGH);
        digitalWrite(LED_RED_COL_0, HIGH);
      } 
      else if (LED[row][0] == NONE)//off
      {
        digitalWrite(LED_GREEN_COL_0, LOW);
        digitalWrite(LED_RED_COL_0, LOW); 
      }


  //2nd colum
  if (LED[row][1] == RED) {
    digitalWrite(LED_GREEN_COL_1, LOW);
    digitalWrite(LED_RED_COL_1, HIGH);
  } 
  else
    if (LED[row][1] == GREEN) {
      digitalWrite(LED_GREEN_COL_1, HIGH);
      digitalWrite(LED_RED_COL_1, LOW);
    } 
    else
      if (LED[row][1] == ORANGE) {
        digitalWrite(LED_GREEN_COL_1, HIGH);
        digitalWrite(LED_RED_COL_1, HIGH);
      } 
      else if (LED[row][1] == NONE)
      {
        digitalWrite(LED_GREEN_COL_1, LOW);
        digitalWrite(LED_RED_COL_1, LOW);
      }

  //3th colum
  if (LED[row][2] == RED) {
    digitalWrite(LED_GREEN_COL_2, LOW);
    digitalWrite(LED_RED_COL_2, HIGH);
  } 
  else
    if (LED[row][2] == GREEN) {
      digitalWrite(LED_GREEN_COL_2, HIGH);
      digitalWrite(LED_RED_COL_2, LOW);
    } 
    else
      if (LED[row][2] == ORANGE) {
        digitalWrite(LED_GREEN_COL_2, HIGH);
        digitalWrite(LED_RED_COL_2, HIGH);
      } 
      else if (LED[row][2] == NONE)
      {
        digitalWrite(LED_GREEN_COL_2, LOW);
        digitalWrite(LED_RED_COL_2, LOW);
      }

  row++;
}






int check_buttons()
{
  digitalWrite(BUT_ROW_0, HIGH);
  digitalWrite(BUT_ROW_1, HIGH);
  digitalWrite(BUT_ROW_2, HIGH);


  digitalWrite(BUT_ROW_0, LOW);
  if (!digitalRead(BUT_COL_0)) {  
    while(!digitalRead(BUT_COL_0)); 
    return 0;
  }

  if (!digitalRead(BUT_COL_1)) {
    while(!digitalRead(BUT_COL_1)); 
    return 1;
  }

  if (!digitalRead(BUT_COL_2)) {
    while(!digitalRead(BUT_COL_2)); 
    return 2;
  }
  digitalWrite(BUT_ROW_0, HIGH);

  digitalWrite(BUT_ROW_1, LOW);
  if (!digitalRead(BUT_COL_0)) {  
    while(!digitalRead(BUT_COL_0)); 
    return 3;
  }

  if (!digitalRead(BUT_COL_1)) {
    while(!digitalRead(BUT_COL_1)); 
    return 4;
  }

  if (!digitalRead(BUT_COL_2)) {
    while(!digitalRead(BUT_COL_2)); 
    return 5;
  }
  digitalWrite(BUT_ROW_1, HIGH);

  digitalWrite(BUT_ROW_2, LOW);
  if (!digitalRead(BUT_COL_0)) {  
    while(!digitalRead(BUT_COL_0)); 
    return 6;
  }

  if (!digitalRead(BUT_COL_1)) {
    while(!digitalRead(BUT_COL_1)); 
    return 7;
  }

  if (!digitalRead(BUT_COL_2)) {
    while(!digitalRead(BUT_COL_2)); 
    return 8;
  }
  digitalWrite(BUT_ROW_2, HIGH);

  while (!digitalRead(BUT_GAME)) 
    return 9;

  return -1; // nothing pressed
}

int get_button(int &Xbut,int &Ybut)
{
  digitalWrite(BUT_ROW_0, HIGH);
  digitalWrite(BUT_ROW_1, HIGH);
  digitalWrite(BUT_ROW_2, HIGH);


  digitalWrite(BUT_ROW_0, LOW);
  Ybut = 0;
  if (!digitalRead(BUT_COL_0)) {  
    while(!digitalRead(BUT_COL_0)); 
    Xbut = 0;
    return 1;
  }

  if (!digitalRead(BUT_COL_1)) {
    while(!digitalRead(BUT_COL_1)); 
    Xbut = 1;
    return 1;
  }

  if (!digitalRead(BUT_COL_2)) {
    while(!digitalRead(BUT_COL_2)); 
    Xbut = 2;
    return 1;
  }
  digitalWrite(BUT_ROW_0, HIGH);

  digitalWrite(BUT_ROW_1, LOW);
  Ybut = 1;
  if (!digitalRead(BUT_COL_0)) {  
    while(!digitalRead(BUT_COL_0));
    Xbut = 0; 
    return 1;
  }

  if (!digitalRead(BUT_COL_1)) {
    while(!digitalRead(BUT_COL_1)); 
    Xbut = 1;
    return 1;
  }

  if (!digitalRead(BUT_COL_2)) {
    while(!digitalRead(BUT_COL_2)); 
    Xbut = 2;
    return 1;
  }
  digitalWrite(BUT_ROW_1, HIGH);

  digitalWrite(BUT_ROW_2, LOW);
  Ybut = 2;
  if (!digitalRead(BUT_COL_0)) {  
    while(!digitalRead(BUT_COL_0)); 
    Xbut = 0;
    return 1;
  }

  if (!digitalRead(BUT_COL_1)) {
    while(!digitalRead(BUT_COL_1)); 
    Xbut = 1;
    return 1;
  }

  if (!digitalRead(BUT_COL_2)) {
    while(!digitalRead(BUT_COL_2)); 
    Xbut = 2;
    return 1;
  }
  digitalWrite(BUT_ROW_2, HIGH);

  return 0; // nothing pressed
}

void set_game_led(int player)
{
  if (player==GREEN)
  {      
    digitalWrite(LED_GREEN_GAME, HIGH);
    digitalWrite(LED_RED_GAME, LOW);
  }
  if (player==RED)
  {      
    digitalWrite(LED_GREEN_GAME, LOW);
    digitalWrite(LED_RED_GAME, HIGH);
  }
  if (player==ORANGE)
  {      
    digitalWrite(LED_GREEN_GAME, HIGH);
    digitalWrite(LED_RED_GAME, HIGH);
  }
  if (player==NONE)
  {      
    digitalWrite(LED_GREEN_GAME, LOW);
    digitalWrite(LED_RED_GAME, LOW);
  }
}







