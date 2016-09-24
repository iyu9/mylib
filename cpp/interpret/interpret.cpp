#include "interpret.h"

interpret::interpret()
{
  //Register commands
  commandNames[0] = "Init"; 
  commandNames[1] = "Show"; 
  commandNames[2] = "Hide"; 
}

interpret::~interpret()
{
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

  std::cout << "NOT Found Command" << code << std::endl;
  return false;
}

bool interpret::act(std::string command)
{
  for (int i = 0; i < LENGTH(commandNames); i++)
  {
	if (command == commandNames[i])
	{
	  std::cout << "Do " << command << std::endl;
	  return true;
	}	
  }

  return false;
}

/**/
int main()
{
  interpret* i = new interpret();
  i->parse("Init");
  i->parse("Show");
  i->parse("Hide");
  i->parse("AntiPattern");

  return 0;
}
/**/
