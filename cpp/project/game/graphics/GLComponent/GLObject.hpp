class GLObject
{
private:
  int id;
  char* name;
  float x, y, z, w;

public:
  GLObject(){}
  GLObject(int id_){id = id_;}
  ~GLObject(){}
};
