class GLScene
{
private:
  int id;
  char* name;

public:
  GLScene(){}
  GLScene(const char* name_)
  {
	name = name_;
  }
  ~GLScene(){}

  void Start()
  {
	//StartCall	
  }
  
  void Update()
  {
	//UpdateCall	
  }
};
