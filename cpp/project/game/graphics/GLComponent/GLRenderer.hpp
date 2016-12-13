class GLRenderer
{
private:
  int id;
  int type;
  double vertices[99];
  double texture[99];

public:
  GLRenderer(){}
  GLRenderer(int id_){}
  ~GLRenderer(){}

  void Initialize() {}
  void Release() {}

  /*
   * For Change Draw Functions
   */
  int GetRenderType()
  {
	return type;
  }	
};
