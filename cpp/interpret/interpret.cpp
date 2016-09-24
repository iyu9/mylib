#include "interpret.h"

interpret::interpret() {
  
}

interpret::~interpret() {

}

bool interpret::parse(std::string code)
{
  for (int i = 0; i < LENGTH(commandNames); i++)
  {
	if (code == commandNames[i])
	{
	  act(code);
	  return true;
	}
  }

  return false;
}

bool interpret::act(std::string command)
{
  for (int i = 0; i < LENGTH(commandNames); i++)
  {
	if (command == commandNames[i])
	{
	  return true;
	}	
  }

  return false;
}

/**/
int main()
{
  interpret* i = new interpret();

  return 0;
}
/**/
