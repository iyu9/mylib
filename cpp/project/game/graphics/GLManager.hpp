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

  struct Rect
  {
    float x;
    float y;
    float w;
    float h;
  };

  enum RenderObjectType
  {
	Line,
	Rect,
	Poly,
  };

  class Object
  {
	public:
	  int id;
	  int renderType;
	  Vec2 pos;

	  Object(){}
	  ~Object(){}

	  int GetID()
	  {
		return id;
	  }

	  int GetRenderType()
	  {
		return renderType;
	  }
  };

  class Scene
  {
	private:
	  Object drawTarget[99];

    public:

	  void Save(const char* fileName)
	  {
		//Save Scene File
	  }

	  void Load(const char* sceneName)
	  {
		//Load Scene File	
	  }

	  void GetRenderTypes()
	  {
		//
	  }
  };

  const Vec2 WindowPos = {100, 100};
  const Vec2 WindowSize = {320, 240};

  const int IntervalUpdate = 100; //msec

  static Vec2 pos;
  const float MoveVal = 0.1;

  static Object actor;
  static Scene scene;

  class GLManager
  {
    private:

      static void DrawRect(float x, float y, float w, float h)
      {
        glBegin(GL_POLYGON);
          glVertex2d(x, y);
          glVertex2d(x + w, y);
          glVertex2d(x + w, y + h);
          glVertex2d(x, y + h);
        glEnd();
      }

      static void DrawLine(int start_x, int start_y, int end_x, int end_y)
      {
        glBegin(GL_LINE);
          glVertex2d(start_x, start_y);
          glVertex2d(end_x, end_y);
        glEnd();  
      }

      static void DrawText()
      {
		//add plugin...  
      }

      //for Auto Handling//
      static void Display()
      {
        glClear(GL_COLOR_BUFFER_BIT);
          DrawRect(-0.9 + actor.pos.x, -0.9 + actor.pos.y, 1.8, 1.8);
        glFlush();
      } 

      static void Reshape(int w, int h)
      {
        glViewport(0, 0, w, h);  
        glLoadIdentity();
        glOrtho(-w / 200.0, w / 200.0, -h / 200.0, h / 200.0, -1.0, 1.0);
      }

      static void Timer(int value)
      {  
        //Update//
        glutPostRedisplay();
        glutTimerFunc(IntervalUpdate, Timer, 0);
      }

      static void Keyboard(unsigned char key, int x, int y)
      {
        switch (key)
        {
          case 'q':
            exit(0);
            break;
          case 'w':
            actor.pos.y += MoveVal;  
            break;
          case 'a':
            actor.pos.x -= MoveVal;  
            break;
          case 's':
            actor.pos.y -= MoveVal;  
            break;
          case 'd':
            actor.pos.x += MoveVal;  
            break;
        }
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

    public:
      GLManager(){}
      ~GLManager(){}

      static void Init(int* argc, char* argv[])
      {
        glutInitWindowPosition(WindowPos.x, WindowPos.y);
        glutInitWindowSize(WindowSize.x, WindowSize.y);
        glutInit(argc, argv);
        glutInitDisplayMode(GLUT_RGBA);
        glutCreateWindow(argv[0]);

        //Set Auto Execute Functions
        glutDisplayFunc(Display);
        glutReshapeFunc(Reshape);
        glutMouseFunc(Mouse);
        glutKeyboardFunc(Keyboard);
        glutTimerFunc(IntervalUpdate, Timer, 0);

        glClearColor(0,0,0,1);
        glutMainLoop();
      }
	  
	  void SetScene(const Scene *scene)
	  {
		//
	  }
  };
}
