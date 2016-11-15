#include "../../common_class/common/common.h"

/*
 * Application Entry Point
 */
namespace AppMain
{
  bool isQuit = false;
  int currentScene = 0;
  std::string cmd;

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

  void MainLoop()
  {
	std::cin >>	cmd;
	std::cout << std::endl << "inputed: ";
	std::cout << cmd << std::endl;
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
