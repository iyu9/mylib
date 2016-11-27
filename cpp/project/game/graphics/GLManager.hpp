#include <GL/glut.h>
#include <stdio.h>
#include <stdlib.h>

/*
 * OpenGL Graphics Control Class
 * Referenced by https://tokoik.github.io/opengl/libglut.html#3.1
 */
namespace GL
{
  struct Vec2
  {
	float x;
	float y;
  };

  const int WindowWidth = 320;
  const int WindowHeight = 240;

  static Vec2 pos;
  const float MoveVal = 0.1;

  class GLManager
  {
	private:
	public:
	  GLManager(){}
	  ~GLManager(){}

	  static void Init(int* argc, char* argv[])
	  {
		glutInitWindowPosition(100, 100);
		glutInitWindowSize(WindowWidth, WindowHeight);
		glutInit(argc, argv);
		glutInitDisplayMode(GLUT_RGBA);
		glutCreateWindow(argv[0]);
		glutDisplayFunc(Display);
		glutReshapeFunc(Reshape);
		glutMouseFunc(Mouse);
		glutKeyboardFunc(Keyboard);
		glClearColor(0,0,1,1);
		glutMainLoop();
	  }
	  
	  static void Display()
	  {
		glClear(GL_COLOR_BUFFER_BIT);
		glBegin(GL_LINE_LOOP);
		  glVertex2d(-0.9 + pos.x, -0.9 + pos.y);
		  glVertex2d( 0.9 + pos.x, -0.9 + pos.y);
		  glVertex2d( 0.9 + pos.x,  0.9 + pos.y);
		  glVertex2d(-0.9 + pos.x,  0.9 + pos.y);
		  glVertex2d(-0.9 + pos.x, -0.9 + pos.y);
		  glVertex2d( 0.9 + pos.x,  0.9 + pos.y);
		glEnd();
		glFlush();
	  } 


	  static void Reshape(int w, int h)
	  {
		glViewport(0, 0, w, h);	
		glLoadIdentity();
		glOrtho(-w / 200.0, w / 200.0, -h / 200.0, h / 200.0, -1.0, 1.0);
	  }

	  static void Keyboard(unsigned char key, int x, int y)
	  {
		switch (key)
		{
		  case 'q':
			exit(0);
			break;
		  case 'w':
		    pos.y += MoveVal;	
			break;
		  case 'a':
		    pos.x -= MoveVal;	
			break;
		  case 's':
		    pos.y -= MoveVal;	
			break;
		  case 'd':
		    pos.x += MoveVal;	
			break;
		}

		glutPostRedisplay();	
	  }

	  static void Mouse(int button, int state, int x, int y)
	  {
		switch (button)
		{
		  case GLUT_LEFT_BUTTON:
			printf("MOUSE_LEFT");
			break;
		  case GLUT_MIDDLE_BUTTON:
			printf("MOUSE_MIDDLE");
			break;
		  case GLUT_RIGHT_BUTTON:
			printf("MOUSE_RIGHT");
			break;
		}

		switch (state)
		{
		  case GLUT_UP:
			printf("MOUSE_ON_UP");
			break;
		  case GLUT_DOWN:
			printf("MOUSE_ON_DOWN");
			break;
		}
	  }
  };
};
