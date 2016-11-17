#include "../../../common_class/common/common.h"
#include "GL/glut.h"

namespace GLManager
{
  class GLManager
  {
	void Init()
	{
	  //
	}

	void Render()
	{
	  glClear(GL_COLOR_BUFFER_BIT);
	  glBegin(GL_LINE_LOOP);
	  glVertex2d(0,0);
	  glVertex2d(1,0);
	  glVertex2d(1,1);
	  glVertex2d(0,1);
	  glFlush();
	} 
  };
}
