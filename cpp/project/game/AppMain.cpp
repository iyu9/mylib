
/*
 * Application Entry Point
 */
namespace AppMain
{
  bool isQuit = false;

  bool Init()
  {
	return true;
  }

  void MainLoop()
  {
	
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
