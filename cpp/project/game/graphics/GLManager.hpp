#include <GL/glut.h>
#include <stdio.h>
#include <stdlib.h>

/*
 * OpenGL Graphics Control Class
 * Reference:
 * https://tokoik.github.io/opengl/libglut.html#3.1,
 * http://www.oit.ac.jp
 */

#ifdef TEST_TEX

#define TEX_HEIGHT 16 
#define TEX_WIDTH 16 

static GLubyte image[TEX_HEIGHT][TEX_WIDTH][4];

int LoadShader(char *vtxShdName, char *frgShdName, GLuint *lpProg)
{
/*
    GLuint vtxShader;
    GLuint frgShader;
    GLuint prog;
    GLint linked;

    //シェーダオブジェクトの作成
    vtxShader = glCreateShader(GL_VERTEX_SHADER);
    frgShader = glCreateShader(GL_FRAGMENT_SHADER);

    //バーテックスシェーダのロードとコンパイル
    if (loadShader(vtxShader, vtxShdName) < 0)
        return -1;

    //フラグメントシェーダのロードとコンパイル
    if (loadShader(frgShader, frgShdName) < 0)
        return -1;

    //プログラムオブジェクトの作成
    prog = glCreateProgram();

    //シェーダオブジェクトのシェーダプログラムへの登録
    glAttachShader(prog, vtxShader);
    glAttachShader(prog, frgShader);

    //シェーダオブジェクトの削除
    glDeleteShader(vtxShader);
    glDeleteShader(frgShader);

    //シェーダプログラムのリンク
    glLinkProgram(prog);
    glGetProgramiv(prog, GL_LINK_STATUS, &linked);
    printProgramInfoLog(prog);
    if (linked == GL_FALSE)
        return -1;

    *lpProg = prog;
*/
    return 0;
}

void InitTexture() 
{
  for (int i = 0; i < TEX_HEIGHT; i++) 
  {
    for (int j = 0; j < TEX_WIDTH; j++)
    {
	  int color;
      color = ( ((i&0x01)==0)^((j&0x01)==0) );
      image[i][j][0] = image[i][j][1] = image[i][j][2] = color*255;
      image[i][j][3] = 255;
    }
  }
} 

void displayTexPolygon()
{
  glEnable(GL_TEXTURE_2D);
	glBegin(GL_QUADS);
	  glTexCoord2f(0.0, 0.0); glVertex3f(-5.0,-5.0, 0.0);
	  glTexCoord2f(0.0, 1.0); glVertex3f(-5.0, 5.0, 0.0);
	  glTexCoord2f(1.0, 1.0); glVertex3f( 5.0, 5.0, 0.0);
	  glTexCoord2f(1.0, 0.0); glVertex3f( 5.0,-5.0, 0.0);
	glEnd();
  glDisable(GL_TEXTURE_2D);
} 

void displayAltanative()
{
  static float spin = 0.0;
  glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);
  glPushMatrix();
  {
	glTranslatef(0.0, 0.0, -20.0);
	glRotatef(spin, 0.0, 1.0, 0.0);
	glColor3f(1,1,1);
	displayTexPolygon();
  }
  spin++;
  glPopMatrix();
  glFlush();
  glutSwapBuffers();
}

#endif

namespace GL
{
  struct Vec2
  {
    float x;
    float y;
  };

  struct Vec3
  {
	float x;
	float y;
	float z;
  };

  enum RenderType
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

	  Vec2 verts[99];
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
	  Object object[99];

    public:

	  void Save(const char* fileName)
	  {
      //Save Scene File
	  }

	  void Load(const char* sceneName)
	  {
      //Load Scene File	
	  }

	  //read only pointer ?
	  const Object* GetObjects()
	  {
		return object;
	  }
  };

  const Vec2 WindowPos = {100, 100};
  const Vec2 WindowSize = {320, 240};

  const int IntervalUpdate = 10; //msec

  static Vec2 pos;
  const float MoveVal = 0.1;

  Object actor;
  static Scene scene;

  class GLManager
  {
    private:

	  //--------------------------
	  //Draw Primitive Functions
	  //--------------------------
	  static void DrawTexture(float x, float y, float w, float h)
	  {		
		glEnable(GL_TEXTURE_2D);
		  glBegin(GL_QUADS);
			glTexCoord2f(0.0, 0.0); glVertex3f(x, y, 0.0);
			glTexCoord2f(0.0, 1.0); glVertex3f(x, y + h, 0.0);
			glTexCoord2f(1.0, 1.0); glVertex3f(x + w, y + h, 0.0);
			glTexCoord2f(1.0, 0.0); glVertex3f(x + w, y, 0.0);
		  glEnd();
		glDisable(GL_TEXTURE_2D);
	  } 

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

	  //--------------------------
      //Auto-processing Functions
	  //--------------------------
      static void Display()
      {
        glClear(GL_COLOR_BUFFER_BIT);
          DrawRect(-0.9 + actor.pos.x, -0.9 + actor.pos.y, 1.8, 1.8);
        glFlush();
      } 

      static void Reshape(int w, int h)
      {
#ifdef TEST_TEX
		glViewport(0, 0, (GLsizei) w, (GLsizei) h);
		glMatrixMode(GL_PROJECTION);
		glLoadIdentity();
		glFrustum(-5.0, 5.0, -5.0, 5.0, 5.0, 500.0);
		glMatrixMode(GL_MODELVIEW);
		glLoadIdentity();
#else
        glViewport(0, 0, w, h);  
        glLoadIdentity();
        glOrtho(-w / 200.0, w / 200.0, -h / 200.0, h / 200.0, -1.0, 1.0);
#endif
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
		  //Exit
          case 'q':
            exit(0);
            break;

		  //WASD
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

		  //ZXC
		  case 'z':
			break;
		  case 'x':
			break;
		  case 'c':
			break;
        }
      }

	  static void SpecialKey(int key, int x, int y)
	  {
		switch(key)
		{
		  case GLUT_KEY_F1:
			exit(0);	
			break;

		  case GLUT_KEY_UP:
			actor.pos.y += MoveVal;
			break;
		  case GLUT_KEY_RIGHT:
			actor.pos.x += MoveVal;
			break;
		  case GLUT_KEY_DOWN:
			actor.pos.y -= MoveVal;
			break;
		  case GLUT_KEY_LEFT:
			actor.pos.x -= MoveVal;
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
        //Create Window
        glutInitWindowPosition(WindowPos.x, WindowPos.y);
        glutInitWindowSize(WindowSize.x, WindowSize.y);
        glutInit(argc, argv);
#ifdef TEST_TEX
        glutInitDisplayMode(GLUT_DEPTH|GLUT_DOUBLE|GLUT_RGBA);
#else
        glutInitDisplayMode(GLUT_RGBA);
#endif
        glutCreateWindow(argv[0]);

#ifdef TEST_TEX
		//Set Depth Setting
		glClearColor(0.0, 0.0, 0.0, 0.0);
		glDepthFunc(GL_LEQUAL);
		glEnable(GL_DEPTH_TEST);

        //Set Texture Setting
        InitTexture();
        glPixelStorei(GL_UNPACK_ALIGNMENT, 1);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
        glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, TEX_WIDTH, TEX_HEIGHT, 
          0, GL_RGBA, GL_UNSIGNED_BYTE, image);

        //Set Auto-Processing Functions
        //glutDisplayFunc(Display);
        glutDisplayFunc(displayAltanative);
#else
        glutDisplayFunc(Display);
#endif
        glutReshapeFunc(Reshape);
        glutMouseFunc(Mouse);
        glutKeyboardFunc(Keyboard);
        glutSpecialFunc(SpecialKey);
        glutTimerFunc(IntervalUpdate, Timer, 0);

        glClearColor(0, 0, 0, 1);
        glutMainLoop();
      }
	  
  };
}

