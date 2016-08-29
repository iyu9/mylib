#include <iostream>
#include <regex>
#include <stdlib.h>

using namespace std;

void clear_screen()
{
  system("clear");  
}

int main()
{
  regex re("a");

  while(1)
  {
	int cmd = 0;
	scanf("%d", &cmd);
	clear_screen();
	cout << "test" << endl;
	cout << "test" << endl;
	cout << "test" << endl;
	cout << "test" << endl;
	cout << "test" << endl;
  }

  return 0;
}
