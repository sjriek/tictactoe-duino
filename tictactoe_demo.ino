#include "tictactoe_duino.h" 

//############################################
//# Library functions	                     #
//############################################

/*
Physical board Layout:
 +----------------+  
 | 1.1 | 1.2 | 1.3| 
 |-----+-----+----|
 | 1.1 | 1.2 | 1.3|
 |-----+-----+----|
 | 1.1 | 1.2 | 1.3|
 +----------------+
 |  G  |
 +-----+
 
 Software board Layout:
 buttonNr and ledNr range from 0 to 9, where 0..8 are the play buttons/led and 9 is the game button/led
 The Game button/led can be used to start a game, choose a random starting player and/or show the current player. 
 +----------------+  
 |  0  |  1  |  2 | 
 |-----+-----+----|
 |  3  |  4  |  5 |
 |-----+-----+----|
 |  6  |  7  |  8 |
 +----------------+
 |  9  |
 +-----+
 
 COLOR: NONE, GREEN, RED, ORANGE     // available colors
 
 initialisation();                   // initialisation of the hardware, has to be done once in setup();
 int check_buttons();                // returns buttonNr
 void set_ledNr(lednr, COLOR);       // enables LED ledNr with color
*/





void setup()                    // Setup runs only once at startup
{
  initialisation();             // initialize harwdware timing and I/O functionality to the board
}


void loop()     // loop() is a replacement for main()
{
  set_ledNr(check_buttons(),ORANGE);   // to test all buttons and LED's
}










