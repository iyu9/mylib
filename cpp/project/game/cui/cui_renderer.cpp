#include <iostream>
#include <string>
#include <stdlib.h>
#include <time.h>

#define SCREEN_WIDTH 86 
#define SCREEN_HEIGHT 28

using namespace std;

const double UPDATE_FPS = 0.033;

char buffer[SCREEN_WIDTH][SCREEN_HEIGHT];
double timer_secs = 0;
clock_t start;
long frame = 0;
bool is_exit = false;

struct Vec2
{
  double x, y;
};

class Rect
{
public:
  Vec2 position;
  Vec2 size;

  void set_center(Vec2 center_pos)
  {
	double x = center_pos.x - 0.5f * size.x;
	double y = center_pos.y - 0.5f * size.y;

	position.x = x;
	position.y = y;
  }

  void get_center()
  {
	double x = position.x + 0.5f * size.x;
	double y = position.y + 0.5f * size.y;

	Vec2 center_pos;
	center_pos.x = x;
	center_pos.y = y;
  }
};

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

void clear_buffer()
{
  for (int x = 0; x < SCREEN_WIDTH; x++)
  {
	for (int y = 0; y < SCREEN_HEIGHT; y++)
	{
	  buffer[x][y] = ' ';
	}
  } 
}

void draw_rect(int x1, int y1, int x2, int y2, char ch)
{
  for (int x = x1; x < x2; x++)
  {
	for (int y = y1; y < y2; y++)
	{
	  buffer[x][y] = ch;
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
	buffer[x][y] = ch;
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
	buffer[x][y] = ch;
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

	default:
	  draw_point(x, y, ch);
	  break;
  }
}

void store_buffer()
{
  draw_rect(0, 0, frame % SCREEN_WIDTH, frame, '@');
 
  //SNOW
  //for (int i = 0; i < SCREEN_WIDTH; i++)
  //{
  //	draw_point(i, (frame + 4 * i) % SCREEN_HEIGHT, '*');
  //}
}

void clear()
{
  clear_buffer();
  system("clear");  
}

//--------------------------
//Game Proc
//--------------------------

int mode = 0;
const int Title  = 0;
const int Main   = 1;
const int Result = 2;

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
	  store_buffer();
	  render(buffer);
	}
  }
  return 0;  
}
#endif
