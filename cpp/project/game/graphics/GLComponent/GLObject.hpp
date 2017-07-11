#include "GLCommon.hpp"

#ifndef __ONCE_GLOBJ__
#define __ONCE_GLOBJ__
class GLObject
{
private:
  int id;

public:
  GL::Vec2 pos;

  GLObject()
  {
	
  }
  GLObject(int id_)
  {
	id = id_;
  }
};
#endif
