#include "../../common_class/common/common.h"

namespace Time
{
  long clock = 0;
  double delta = 0;

  double GetSec()
  {
	//
  }
};

namespace Scene
{
  static int currentScene;

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

namespace Command
{
  enum Command
  {
	Start,
	Load,
	Continue,
	Option,
	Exit,
  };

  static std::string checkCommands[] =
  {
	"start",
	"load",
	"continue",
	"option",
	"exit",
  };
}

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
