#include "chrono.h"

chrono::chrono()
{
    start = clock();
	prev_clock = start;
}

chrono::~chrono()
{
}

clock_t chrono::get_clock_sec()
{
	clock_t current = clock();
	prev_clock = current;

	return current;
}
double chrono::get_sec()
{
	clock_t current = clock();
	double sec = (double)current / CLOCKS_PER_SEC;
	prev_clock = current;

	return sec;
}

clock_t chrono::get_clock_delta()
{
	clock_t current_clock = clock();
	clock_t delta_clock = current_clock - prev_clock;

	prev_clock = current_clock;
	return delta_clock;
}
double chrono::get_delta()
{
	clock_t current_clock = clock();
	clock_t delta_clock = current_clock - prev_clock;
	double delta_sec = (double) delta_clock / CLOCKS_PER_SEC;

	prev_clock = current_clock;
	return delta_sec;
}

clock_t chrono::get_clock_time()
{
	clock_t current = clock();
	return (current - start);
}
double chrono::get_time()
{
	clock_t current = clock();
	double time = (double) (current - start) / CLOCKS_PER_SEC;

	return time;
}

/*
#include <stdio.h>
#include <time.h>

int main(void)
{
  chrono *c = new chrono();

  clock_t start, end;
  int i;

  start = clock();
  printf( "開始時間:%d¥n", start );

  for( i=0; i<500000000; i++ );

  //end = clock();
  //printf( "終了時間:%f¥n", (double) end / CLOCKS_PER_SEC  );
  //printf( "処理時間:%f¥n", (double) (end - start) / CLOCKS_PER_SEC );

  printf("start from time = %f", c->get_time());
  return 0;
}
*/
