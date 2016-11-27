#include <GL/glut.h>

/*
 * OpenGL Graphics Control Class
 */
namespace GL
{

  class GLManager
  {
	public:
	  GLManager(){}
	  ~GLManager(){}

	  static void Init(int* argc, char* argv[])
	  {
		glutInit(argc, argv);
		glutCreateWindow(argv[0]);
		glutDisplayFunc(Render);
		glutMainLoop();
	  }

	  static void Render()
	  {
		glClear(GL_COLOR_BUFFER_BIT);
		glBegin(GL_LINE_LOOP);
		  glVertex2d(-0.9, -0.9);
		  glVertex2d( 0.9, -0.9);
		  glVertex2d( 0.9,  0.9);
		  glVertex2d(-0.9,  0.9);
		glEnd();
		glFlush();
	  } 
  };
};
