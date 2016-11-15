#include "../../common_class/common/common.h"

#include "./common/time.hpp"
#include "./common/scene.hpp"
#include "./common/command.hpp"

#include "./AppData.hpp"

namespace AppMain
{
  bool isQuit = false;
  int currentScene = 0;

  void Initialize(){}
  void Release(){}

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
	//DECODE_ACTION	
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
  AppMain::Initialize();

  while (!AppMain::isQuit)
  {
	AppMain::MainLoop();
  }

  AppMain::Release();
  return 0;
}
/**/
