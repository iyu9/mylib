#include <GL/glut.h> 
#include <stdlib.h> 
#include <stdio.h> 
#define TEX_HEIGHT 16 
#define TEX_WIDTH 16 

static GLubyte image[TEX_HEIGHT][TEX_WIDTH][4];

void initTexture(void) 
{
  int i, j, c;
  for (i = 0; i < TEX_HEIGHT; i++) 
  {
	for (j = 0; j < TEX_WIDTH; j++)
	{
	  c = ( ((i&0x01)==0)^((j&0x01)==0) );
	  image[i][j][0] = image[i][j][1] = image[i][j][2] = c*255;
	  image[i][j][3]=255;
	}
  }
} 

void displayTexPolygon(void)
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

void display(void)
{
  static float spin=0.0;
  glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);
  glPushMatrix();
  {
	glTranslatef(0.0, 0.0,-20.0);
	glRotatef(spin, 0.0, 1.0, 0.0);
	glColor3f(1.0, 1.0, 1.0);
	displayTexPolygon();
  }
  spin+=1.0;
  glPopMatrix();
  glFlush();
  glutSwapBuffers();
} 

void init(void)
{
  glClearColor(0.0, 0.0, 0.0, 0.0);
  glDepthFunc(GL_LEQUAL);
  glEnable(GL_DEPTH_TEST);
  initTexture();
  glPixelStorei(GL_UNPACK_ALIGNMENT, 1);
  glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
  glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
  glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);
  glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
  glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, TEX_WIDTH, TEX_HEIGHT, 0, GL_RGBA, GL_UNSIGNED_BYTE, image);
} 

void reshape(int w, int h)
{
  glViewport(0, 0, (GLsizei) w, (GLsizei) h);
  glMatrixMode(GL_PROJECTION);
  glLoadIdentity();
  glFrustum(-5.0, 5.0,-5.0, 5.0, 5.0, 500.0);
  glMatrixMode(GL_MODELVIEW);
  glLoadIdentity();
} 

int main(int argc, char** argv)
{
  glutInit(&argc, argv);
  glutInitDisplayMode (GLUT_DEPTH|GLUT_DOUBLE|GLUT_RGBA);
  glutInitWindowSize (250, 250);
  glutInitWindowPosition (100, 100);
  glutCreateWindow (argv[0]);
  init();
  glutIdleFunc(display);
  glutDisplayFunc(display);
  glutReshapeFunc(reshape);
  glutMainLoop();
  return 0;
}
