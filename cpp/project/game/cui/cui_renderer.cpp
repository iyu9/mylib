#include <iostream>
#include <string>
#include <stdlib.h>
#include <time.h>

#define SCREEN_WIDTH 86 
#define SCREEN_HEIGHT 28

#include "common.hpp"

using namespace std;

//--------------------------
// Game variables
//--------------------------

int game_mode = 0;
const int Title  = 0;
const int Option = 1;
const int Main   = 2;
const int Result = 3;

//--------------------------
// CUI Screen Setting
//--------------------------
const double UPDATE_FPS = 0.1;

char buf[SCREEN_WIDTH][SCREEN_HEIGHT];
double timer_secs = 0;
clock_t start;
long frame = 0;
bool is_exit = false;

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

void clear_buf()
{
  for (int x = 0; x < SCREEN_WIDTH; x++)
  {
	for (int y = 0; y < SCREEN_HEIGHT; y++)
	{
	  buf[x][y] = ' ';
	}
  } 
}

void draw_rect(int start_x, int start_y, int end_x, int end_y, char ch)
{
  for (int x = start_x; x < end_x; x++)
  {
	for (int y = start_y; y < end_y; y++)
	{
	  buf[x][y] = ch;
	}
  }  
}
void draw_rect(Vec2 start_pos, Vec2 end_pos, char ch)
{
  for (int x = start_pos.x; x < end_pos.x; x++)
  {
	for (int y = start_pos.y; y < end_pos.y; y++)
	{
	  buf[x][y] = ch;
	}
  }  
}

void draw_rectsize(int start_x, int start_y, int size_x, int size_y, char ch)
{
  for (int x = start_x; x < start_x + size_x; x++)
  {
	for (int y = start_y; y < start_y + size_y; y++)
	{
	  buf[x][y] = ch;
	}
  }  
}
void draw_rectsize(Vec2 pos, Vec2 size, char ch)
{
  for (int x = pos.x; x < pos.x + size.x; x++)
  {
	for (int y = pos.y; y < pos.y + size.y; y++)
	{
	  buf[x][y] = ch;
	}
  }  
}

void draw_line(int x0, int y0, int x1, int y1, char ch)
{
  int dx = x1 - x0;
  int dy = y1 - y0;
  float err = 0;
  float d_err = (float) abs(dy/dx);
  
  int y = y0;
  for (int x = x0; x <= x1; x++)
  {
	buf[x][y] = ch;
	err = err + d_err;
	if (err >= 0.5)
	{
	  y = y + 1;
	  err--;
	}
  }
}

void draw_point(int x, int y, char ch)
{
  if (x <= SCREEN_WIDTH && y <= SCREEN_HEIGHT)
  {
	buf[x][y] = ch;
  }
}

void draw_character(int x, int y, char ch)
{
  switch (ch)
  {
	case 'a':
	  draw_point(0, 0, ch);
	  draw_point(1, 0, ch);
	  draw_point(2, 0, ch);
	  draw_point(3, 0, ch);

	  draw_point(3, 1, ch);

	  draw_point(0, 2, ch);
	  draw_point(1, 2, ch);
	  draw_point(2, 2, ch);
	  draw_point(3, 2, ch);

	  draw_point(0, 3, ch);
	  draw_point(3, 3, ch);

	  draw_point(0, 4, ch);
	  draw_point(1, 4, ch);
	  draw_point(2, 4, ch);
	  draw_point(3, 4, ch);
	  break;

	case 't':
	  //T
	  draw_rect(0, 0, 9, 5, '#');
	  draw_rect(3, 2, 6, 10, '#');

	  //O
	  draw_rect(10, 0,  20,  3, '#');
	  draw_rect(17, 0,  20, 10, '#');
	  draw_rect(10, 8,  20, 10, '#');
	  draw_rect(10, 0,  13, 10, '#');
	  break;

	default:
	  draw_point(x, y, ch);
	  break;
  }
}

void clear()
{
  clear_buf();
  system("clear");  
}

//--------------------------
// App Main Procedure
//--------------------------
void update()
{
  switch(game_mode)
  {
	case Title:
	  draw_character(0, 0, 't');
	  //draw_rect(0, 0, frame % SCREEN_WIDTH, frame, '@');

	  if (frame > 20)
	  {
		game_mode = Main;
	  }
	  break;

	case Main:
	  //SNOW
	  for (int i = 0; i < SCREEN_WIDTH; i++)
	  {
	  	draw_point(i, (frame + 4 * i) % SCREEN_HEIGHT, '*');
	  }
	  break;
  }
}

//--------------------------
// For UnitTesting
//--------------------------

#ifndef DEBUG
int main()
{
  while (!is_exit)
  {
	clock_t current = clock();
	timer_secs = (double)(current - start) / CLOCKS_PER_SEC; 

	if (timer_secs > UPDATE_FPS)
	{
	  start = current;
	  frame++;

	  clear();
	  update();
	  render(buf);
	}
  }
  return 0;  
}
#endif
