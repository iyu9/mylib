#include <iostream>
#include <string>
#include <stdlib.h>
#include <time.h>

using namespace std;

#define SCREEN_WIDTH 10
#define SCREEN_HEIGHT 10

int frame = 0;
double timer = 0;
clock_t start;

/*
 * Render Animation Frame data
 */
char a[SCREEN_WIDTH][SCREEN_HEIGHT] =
{
  {'#', '#', '#', '#', '#', '#', '#', '#', '#', '#'},
  {'#', '#', '#', '#', '#', '#', '#', '#', '#', '#'},
  {'#', '#', '#', '#', '#', '#', '#', '#', '#', '#'},
  {'#', '#', '#', '#', '#', '#', '#', '#', '#', '#'},
  {'#', '#', '#', '#', '#', '#', '#', '#', '#', '#'},
  {'#', '#', '#', '#', '#', '#', '#', '#', '#', '#'},
  {'#', '#', '#', '#', '#', '#', '#', '#', '#', '#'},
  {'#', '#', '#', '#', '#', '#', '#', '#', '#', '#'},
  {'#', '#', '#', '#', '#', '#', '#', '#', '#', '#'},
  {'#', '#', '#', '#', '#', '#', '#', '#', '#', '#'}
};

char b[SCREEN_WIDTH][SCREEN_HEIGHT] =
{
  {'#', '#', '#', '#', '#', '#', '#', '#', '#', '#'},
  {'#', '#', '#', '#', '#', '#', '#', '#', '#', '#'},
  {'#', '#', ' ', ' ', ' ', ' ', ' ', ' ', '#', '#'},
  {'#', '#', ' ', '#', '#', '#', '#', ' ', '#', '#'},
  {'#', '#', ' ', '#', '#', '#', '#', ' ', '#', '#'},
  {'#', '#', ' ', '#', '#', '#', '#', ' ', '#', '#'},
  {'#', '#', ' ', '#', '#', '#', '#', ' ', '#', '#'},
  {'#', '#', ' ', ' ', ' ', ' ', ' ', ' ', '#', '#'},
  {'#', '#', '#', '#', '#', '#', '#', '#', '#', '#'},
  {'#', '#', '#', '#', '#', '#', '#', '#', '#', '#'}
};

/*
 * Clear Function
 */
char data[SCREEN_WIDTH][SCREEN_HEIGHT] get_clear()
{
  char ch[SCREEN_WIDTH][SCREEN_HEIGHT];
  return ch;  
}

/*
 * Render Character In CUI Screen
 */
void render(char data[SCREEN_WIDTH][SCREEN_HEIGHT])
{
  for(int y = 0; y < SCREEN_HEIGHT; y++)
  {
	for(int x = 0; x < SCREEN_WIDTH; x++)
	{
	  cout << data[x][y] << ' ';
	}
	cout << endl;
  } 
}

/*
 * Clear Screen Chars
 */
void clear()
{
  system("clear");  
}

#ifndef DEBUG
int main()
{
  while(1)
  {
	clock_t current = clock();
	timer = (double)(current - start) / CLOCKS_PER_SEC;

	if (timer > 0.25)
	{
	  //update
	  start = current;
	  clear();

	  //Render Animation
	  if (frame == 0)
	  {
		frame = 1;
		render(a);
	  }
	  else
	  {
		frame = 0;
		render(b);
	  }
	}
  }

  return 0;  
}
#endif
