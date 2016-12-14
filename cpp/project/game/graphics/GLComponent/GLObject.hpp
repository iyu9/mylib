#include "GLCommon.hpp"

class GLObject
{
private:
  int id;
  char* name;
  float x, y, z, w;

public:
  GLObject(){}
  GLObject(int id_)
  {
	id = id_;
  }
  GLObject(int id_, char* name_)
  {
	id = id_;
	name = name_;
  }
  ~GLObject(){}
};
