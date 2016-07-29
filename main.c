#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <termios.h>
#include "firstscreen.h"
#include "initialization.h"
#include "play_screen.h"
#include "input"
#define FIRST_SCREEN 0
#define PLAY_SCREEN 1
#define MODE_SCREEN 2
#define EXCIT 3

extern char grid[LENGTH][WIDTH];
extern int pointer_shift;

void plotter(int screen)
{
if(screen == FIRST_SCREEN)
{
 draw_first_screen();
}
else if(screen == PLAY_SCREEN)
{
 draw_play_screen();
}
else if(screen == MODE_SCREEN)
{
 //draw_mode_screen();
}
else if(screen == EXCIT)
{
  //draw_excit_screen
}
}




void display()
{
       for(int i = 0 ; i < LENGTH ; i++)
         {
            for(int j =0 ; j <WIDTH ;j++)
              printf("%c",grid[i][j]);

              printf("\n");
 }
}


int main()
{

// plotter(PLAY_SCREEN);
 //display();
 int i=0 , j=0 ,shift=0;
char c;
while(1)
{
  while(!kbhit())
  {

    draw_first_screen(shift);
    display();
    usleep(500000);
  }
  printf("You pressed '%c'!\n", c = getchar());

    if(c=='w'|| c=='s')
    {
     shift +=2;
     shift %=6;

     if(c=='w')
       pointer_shift = 4-shift;

     else if(c=='s')
       pointer_shift = shift;
    }
    }

/*   int shift;
    char c;
    draw_first_screen();
    display();
    while((c=getch()) !='\n')
    {
    if(c=='w'|| c=='s')
    {
     shift +=2;
     shift %=6;

     if(c=='w')
       pointer_shift = 4-shift;

     else if(c=='s')
       pointer_shift = shift;
    }
     draw_first_screen();
     display();
    }
*/
//    draw_grid();


    //interaction
    //input();
/*
    while((c=getch()) != 'q')
     if(c == 'a')
       {
        draw_grid();
        grid[5][5]= '^';
        display();
        }
      else
       {
        draw_grid();
        grid[5][5]= '*';
        display();
        }

*/    return 0;
}
