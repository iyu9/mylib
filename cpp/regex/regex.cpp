#include <iostream>
#include <regex>
#include <stdlib.h>

using namespace std;

void print_screen(string msg)
{
  cout << msg;
}

void clear_screen()
{
  system("clear");  
}

int main()
{
  regex re("a");
  clear_screen();
  print_screen("Hello, CLI GAME");

  while(1)
  {
	int cmd;
	scanf("%d", &cmd);

	clear_screen();
	print_screen("test");
  }

  return 0;
}
