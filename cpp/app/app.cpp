#include <iostream>
#include <string>

#include <stdlib.h>

using namespace std;

int main ()
{
  string cmd;

  while (1)
  {
	cin >> cmd;
	cout << cmd << endl;

	if (cmd == "less")
	{
	  system("less");
	}

	if (cmd == "exit")
	{
	  break;
	}
  }  

  return 0;
}
