#include "../../common_class/common/common.h"

namespace Time
{
  float delta = 0;
};

namespace Scene
{
  enum Scene
  {
	Loading,
	Title,
	Start,
	Continue,
	Option,
	Exit
  }; 
};

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

  /*
   * Initialize app settings before MainLoop()
   */
  bool Init()
  {
	currentScene = Scene::Loading;
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
	//DECODE_ACTION	
  }

  void MainLoop()
  {
	Time::delta += 1;

	std::string cmd = CheckCommand();
	DecodeCommand(cmd);
  }
}

/**/
int main ()
{
  AppMain::Init();

  while (!AppMain::isQuit)
  {
	AppMain::MainLoop();
  }
  return 0;  
}
/**/
