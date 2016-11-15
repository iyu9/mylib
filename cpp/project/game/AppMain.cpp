#include "../../common_class/common/common.h"

/*
 * Application Entry Point
 */
namespace AppMain
{
  bool isQuit = false;
  int currentScene = 0;

  std::string checkCommands[] =
  {
	"start",
	"load",
	"continue",
	"option",
	"exit",
  };

  enum Scene
  {
	Loading,
	Title,
	Start,
	Continue,
	Option,
	Exit
  };

  bool Init()
  {
	currentScene = Loading;
	return true;
  }

  std::string CheckInput()
  {
	std::string cmd;
	std::cin >>	cmd;
	std::cout << std::endl << "inputed: ";
	std::cout << cmd << std::endl;

	return cmd;
  }

  void Decode(std::string cmd)
  {
	for (int i = 0; i < 0; i++)
	{
	  if (cmd == checkCommands[i])
	  {
		
	  }
	}
  }

  void MainLoop()
  {
	std::string cmd = CheckInput();
	Decode(cmd);
  }
}

/**/
int main ()
{
  AppMain::Init();
  while(!AppMain::isQuit)
  {
	AppMain::MainLoop();
  }
  return 0;  
}
/**/
