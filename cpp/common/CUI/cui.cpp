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
void get_clear()
{
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

void set_rect(int x1, int y1, int x2, int y2)
{
  for (int x = x1; x < x2; x++)
  {
	for (int y = y1; y < y2; y++)
	{
	  a[x][y] = '*';
	}
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
		set_rect(0, 0, 5, 5);
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
