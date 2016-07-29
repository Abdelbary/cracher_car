#include <stdio.h>
#include <stdlib.h>
#include "initialization.h"



void draw_first_screen(int pointer_shift )
{
//clean
initialize();

//first screen string
char pointer = '*';
char play[5] = "play" , mode[5] = "mode" , exit[5] = "exit"
,creator_text[50] = "****console game created by Mahmoud Abdelbary****";


//put strings on grid

//determin pointer position by a shifthing value to its original postion
grid[25+pointer_shift][28] = pointer;

strcpy(&grid[25][29],&play);
strcpy(&grid[27][29],&mode);
strcpy(&grid[29][29],&exit);
strcpy(&grid[35][7],&creator_text);
}



