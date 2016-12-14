class GLSceneManager
{
private:
  GLScene sceneList[99];
  GLScene* current;

  Scene* FindScene(const char* name)
  {
	for (int i = 0; i < 99; i++)
	{
	  if(sceneList[i].name == name)
	  {
		return &sceneList[i]	
	  }
	}
	return NULL;
  }

public:
  void ChangeScene(GLScene* nextScene)
  {
	current = nextScene;
  }

  void ChangeScene(const char* sceneName)
  {
	current = nextScene;
  }
};
