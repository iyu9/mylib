#include "../../../common_class/common/common.h"

namespace Scene
{
  static int prevScene;
  static int currentScene;
  static int nextScene;

  enum Scene
  {
	Loading,
	Title,
	Start,
	Continue,
	Option,
	Exit
  };

  std::string SceneNames[] =
  {
	"Loading",
	"Title",
	"Start",
	"Continue",
	"Option",
	"Exit",
  };

  void ChangeScene(int scene)
  {
	currentScene = scene;
  }
};
