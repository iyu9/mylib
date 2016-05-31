#include "graphics.h"
#include <sstream>  //for transf wchar
#include <stdlib.h>	//for key input

#include <GL/glut.h>

//#include <d3d9.h>
//#include <d3dx9.h>

//global declaration
float r = 0;
float pos_x = 0;
float pos_y = 0;
float pos_z = 0;

Vector3* pos;
chrono* chr;

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
void DrawCube(float size, float x, float y, float z);

//constructors
Graphics::Graphics(){		
	r = 0;
  chr = new chrono();
  pos = new Vector3();
}

Graphics::~Graphics(){
}

void keyboard(unsigned char key, int x, int y)
{
  switch (key) {

  case 'w':
	  pos->y++;
	  glTranslatef(0, 0.1, 0);
	  break;

  case 's':
	  pos->y--;
	  glTranslatef(0, -0.1, 0);
	  break;

  case 'a':
	  pos->x--;
	  glTranslatef(-0.1, 0, 0);
	  break;

  case 'd':
	  glTranslatef(0.1, 0, 0);
	  pos->x++;
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
	gluLookAt(3.0, 4.0, 5.0, 0.0, 0.0, 0.0, 0.0, 1.0, 0.0);
}

void idle() {
	glutPostRedisplay();
}

void display() {
	r = 100 * chr->get_delta();

	if(r > 360) {
		r = 0;
	}

  pos->x += chr->get_delta();

  if(pos->x > 10) {
    pos->x = -10;
  }

	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	glRotatef(r, 0, 1, 0);
	//LINE_LOOP, QUADS, POLYGON etc
	DrawCube(1.0, pos->x, pos->y, pos->z);	
	DrawLine(0, 0, 0, 0);
	std::ostringstream stream;
	stream << r;
	std::string res = stream.str();
	DrawString(-0.8, 0.8, res);
	glutSwapBuffers();
};

//initialize once
void Graphics::init() {

	state = 0;	
	int argc = 1;

	glutInitWindowPosition(100,100);
	glutInitWindowSize(300,300);
	glutInit(&argc, NULL);
	glutInitDisplayMode(GLUT_RGBA | GLUT_DEPTH);
	glutCreateWindow(NULL);
	glutDisplayFunc(display);
	glutIdleFunc(idle);
	glutReshapeFunc(resize);
	glClearColor(0, 0, 0, 1);
	glEnable(GL_DEPTH_TEST);
	glutKeyboardFunc(keyboard);
	glutMainLoop();
}

//helper draw methods
void DrawLine(float x1, float y1, float x2, float y2) {
	glBegin(GL_LINE_LOOP);
	glVertex2d(x1, y1);	
	glVertex2d(x2, y2);
	glEnd();
}

void DrawRect(float x, float y, float width, float height) {
	glBegin(GL_QUADS);
	glVertex2d(x,y);	
	glVertex2d(x + width, y);
	glVertex2d(x + width, y + height);
	glVertex2d(x, y + height);
	glEnd();
}

void DrawString(float x, float y, std::string const& str) {
	float z = -1.0f;
	glRasterPos3f(x, y, z);

	for(int i = 0; i < str.length(); i++) {
		glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, str[i]);
	}
}

void DrawCube(float size, float x, float y, float z) {
	int face[][4] = {
		{0, 1, 2, 3},
		{1, 5, 6, 2},
		{5, 4, 7, 6},
		{4, 0, 3, 7},
		{4, 5, 1, 0},
		{3, 2, 6, 7}
	};
/*
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
*/
  //re-valueset
  vertex[0][0] = -size + x; vertex[0][1] = -size + y;  vertex[0][2] = -size + z;
  vertex[1][0] = size + x;  vertex[1][1] = -size + y;  vertex[1][2] = -size + z;
  vertex[2][0] = size + x;  vertex[2][1] = size + y;   vertex[2][2] = -size + z;
  vertex[3][0] = -size + x; vertex[3][1] = size + y;   vertex[3][2] = -size + z;
  vertex[4][0] = -size + x; vertex[4][1] = -size + y;  vertex[4][2] =  size + z;
  vertex[5][0] = size + x;  vertex[5][1] = -size + y;  vertex[5][2] =  size + z;
  vertex[6][0] = size + x;  vertex[6][1] = size + y;   vertex[6][2] =  size + z;
  vertex[7][0] = -size + x; vertex[7][1] = size + y;   vertex[7][2] =  size + z;

  //render
	glBegin(GL_QUADS);
	for (int j = 0; j < 6; ++j) {
		glColor3dv(color[j]);
		for (int i = 0; i < 4; ++i) {
			glVertex3dv(vertex[face[j][i]]);
		}
	}
	glEnd();
}

/**/
int main() {
	Graphics* gp = new Graphics();
	gp->init();
	
	return 0;
}
/**/
