#include "graphics.h"
#include <iostream>
#include <string>
#include <sstream>
#include <stdlib.h>	//for key input

//with g_api opengl
#include <GL/glut.h>

//with g_api directx
//#include <d3d9.h>
//#include <d3dx9.h>

//global declaration
float r = 0;
float pos_x = 0;
float pos_y = 0;
float pos_z = 0;

GLdouble vertex[][3] = {
	{0, 0, 0},
	{1, 0, 0},
	{1, 1, 0},
	{0, 1, 0},
	{0, 0, 1},
	{1, 0, 1},
	{1, 1, 1},
	{0, 1, 1}
};

int face[][4] = {
  { 0, 1, 2, 3 },
  { 1, 5, 6, 2 },
  { 5, 4, 7, 6 },
  { 4, 0, 3, 7 },
  { 4, 5, 1, 0 },
  { 3, 2, 6, 7 }
};


GLdouble color[][3] = {
  { 1, 0, 0},
  { 0, 1, 0},
  { 0, 0.5, 0.5},
  { 1, 1, 0},
  { 1, 0, 1},
  { 0, 1, 1}
};


//forward declaration
void DrawLine(float x1, float y1, float x2, float y2);
void DrawString(float x, float y, std::string const& str);
void DrawRect(float x, float y, float width, float height);
void DrawCube();

//constructors
Graphics::Graphics(){		
	r = 0;
}

Graphics::~Graphics(){
	r = 0;	
}

void Graphics::Render() {
	//
}

void keyboard(unsigned char key, int x, int y)
{
  switch (key) {

  case 'w':
	pos_y++;
	glTranslatef(0, 0.1, 0);
	break;

  case 's':
	pos_y--;
	glTranslatef(0, -0.1, 0);
	break;

  case 'a':
	pos_x--;
	glTranslatef(-0.1, 0, 0);
	break;
  case 'd':
	glTranslatef(0.1, 0, 0);
	pos_x++;
	break;
  case 'q':
  case 'Q':
  case '\033':  /* '\033' は ESC の ASCII コード */
    exit(0);
  default:
    break;
  }
}

void resize(int w, int h) {
	glViewport(0, 0, w, h);

	glLoadIdentity();
	//glOrtho(-2.0, 2.0, -2.0, 2.0, -2.0, 2.0);
	gluPerspective(30.0, (double)w / (double)h, 1.0, 100.0);
	//glTranslated(0.0, 0.0, -5.0);
	gluLookAt(3.0, 4.0, 5.0, 0.0, 0.0, 0.0, 0.0, 1.0, 0.0);
}

void idle(){
	glutPostRedisplay();
}

void display() {
	r += 0.0001;

	if(r > 360) {
		r = 0;
	}

	//glRotatef(r,0,1,0);
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	//LINE_LOOP, QUADS, POLYGON etc
	DrawCube();	
	//DrawLine(0,0,0,0);
	std::ostringstream stream;
	stream << r;
	std::string res = stream.str();
	DrawString(-0.8, 0.8, res);
	glutSwapBuffers();
};

//main methods
void Graphics::Init() {
	state = 0;	
	int argc = 1;

	//graphics API
	glutInitWindowPosition(100,100);
	glutInitWindowSize(1000,680);
	glutInit(&argc, NULL);
	glutInitDisplayMode(GLUT_RGBA | GLUT_DEPTH);
	glutCreateWindow(NULL);
	glutDisplayFunc(display);
	glutIdleFunc(idle);
	glutReshapeFunc(resize);
	glClearColor(0, 0, 0 ,1);
	glEnable(GL_DEPTH_TEST);
	glutKeyboardFunc(keyboard);
	glutMainLoop();
}

//helper draw methods
void DrawLine(float x1, float y1, float x2, float y2) {
	//draw graphics api
	glBegin(GL_LINE_LOOP);
	glVertex2d(-0.9,-0.9);	
	glVertex2d(0.9,-0.9);
	glEnd();
}

void DrawRect(float x, float y, float width, float height) {
	//draw graphics api
	glBegin(GL_QUADS);
	glVertex2d(-0.9,-0.9);	
	glVertex2d(0.9,-0.9);
	glVertex2d(0.9,0.9);
	glVertex2d(-0.9,0.9);
	glEnd();
}

void DrawString(float x, float y, std::string const& str) {
	float z = -1.0f;
	glRasterPos3f(x, y, z);

	for(int i = 0; i < str.length(); i++) {
		glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, str[i]);
	}
}

void DrawCube() {
	int face[][4] = {
		{0, 1, 2, 3},
		{1, 5, 6, 2},
		{5, 4, 7, 6},
		{4, 0, 3, 7},
		{4, 5, 1, 0},
		{3, 2, 6, 7}
	};

	glBegin(GL_QUADS);
	for (int j = 0; j < 6; ++j) {
		glColor3dv(color[j]);
		for (int i = 0; i < 4; ++i) {
			glVertex3dv(vertex[face[j][i]]);
		}
	}
	glEnd();
}

/*unit-test*/
int main() {
	Graphics* gp = new Graphics();
	gp->Init();
	//delete(gp);	
	return 0;
}
/**/
