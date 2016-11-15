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

  std::string CheckCommand()
  {
	std::string cmd;
	std::cin >>	cmd;
	std::cout << std::endl << "inputed: ";
	std::cout << cmd << std::endl;

	return cmd;
  }

  void DecodeCommand(std::string cmd)
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
	std::string cmd = CheckCommand();
	DecodeCommand(cmd);
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
