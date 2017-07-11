#include <GL/glut.h>
#include <stdio.h>
#include <stdlib.h>

#include "GLComponent/GLVec.hpp"
#include "GLComponent/GLObject.hpp"

/*
 * OpenGL Graphics Control Class
 * Reference:
 * https://tokoik.github.io/opengl/libglut.html#3.1,
 * http://www.oit.ac.jp
 */

#define TEX_HEIGHT 16 
#define TEX_WIDTH 16 

static GLubyte image[TEX_HEIGHT][TEX_WIDTH][4];

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

void display()
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

namespace GL
{
  const Vec2 WindowPos = {100, 100};
  const Vec2 WindowSize = {320, 240};

  const int IntervalUpdate = 10; //msec
  const float MoveVal = 0.1;

  static Vec2 pos;

  GLObject actor;

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
		glViewport(0, 0, (GLsizei) w, (GLsizei) h);
		glMatrixMode(GL_PROJECTION);
		glLoadIdentity();
		glFrustum(-5.0, 5.0, -5.0, 5.0, 5.0, 500.0);
		glMatrixMode(GL_MODELVIEW);
		glLoadIdentity();
      }

      static void Timer(int value)
      {  
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
        glutInitDisplayMode(GLUT_DEPTH|GLUT_DOUBLE|GLUT_RGBA);
        glutCreateWindow(argv[0]);

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
        glutDisplayFunc(display);
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

