#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "initialization.h"
#define CRACK_LINE_MAX_LENGTH 4
#define CRACK_MAX 12

void drawe_car(int x,int y,int cracker_counter)
{
//(x,y)>>>>car coordinates

//limit cracker_length
if(cracker_counter > CRACK_MAX)
cracker_counter  = CRACK_MAX ;

//draw car
grid[x][y] = '*';
grid[x-1][y-1] = '*';
grid[x-1][y+1] =  '*';
grid[x+1][y-1] =  '*';
grid[x+1][y+1] = '*';


for(int i = 0 ,j=-2 ; cracker_counter > 0 ; i++)
{
  if(i == 4)
  {
   j--;
   i = 0 ;
  }
  grid[x+j][y-i]='^';
  grid[x+j][y+i]='^';
  cracker_counter--;
}
 }

void draw_opstical(int x,int y,int length ,int width)
{
for(int i = x ; i <x+length ; i++)
 for(int j = y ; j<y+width ; j++)
    grid[i][j] = '*';
}

void draw_plus(int x,int y)
{
grid[x][y] = '^';
}

void draw_play_screen()
{
//clean
initialize();
//draw boundrises
 for(int i = 0 ; i < LENGTH ; i++)
 {
  grid[i][0]='|';
  grid[i][WIDTH-1]='|';
 }
 draw_opstical(10,10,2,3);
 drawe_car(25,25,9);
 draw_plus(50,50);
}
