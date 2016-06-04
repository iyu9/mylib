#include "graphics.h"
#include <sstream>  //for transf wchar
#include <stdlib.h>	//for key input

#include <GL/glut.h>

//#include <d3d9.h>
//#include <d3dx9.h>

//global declaration
float r = 0;
float time_d = 0;

vector3* pos;
vector3* scale;
chrono* chr;

graphics* gp;

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

//3d
void DrawCube(vector3 scale, vector3 pos);

//constructors
graphics::graphics(){		
  r = 0;
  chr = new chrono();
  pos = new vector3();
  scale = new vector3(0.5, 1, 0.5);
}

graphics::~graphics(){
}

void switch_camera() {		
  glOrtho(0.0, 0.0, 10.0, 0.0, 0.0, 0.0);
  gluLookAt(0, 0, 10, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0);
  /*
  glViewport(0, 0, 300, 300);
  glLoadIdentity();
  gluPerspective(0.0, (double)300 / (double)300, 1.0, 100.0);
  gluLookAt(0, 0, 0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0);
  */
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

  case 'c':
  	  switch_camera();
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
	
	float delta = 0.001;//chr->get_delta();
	time_d += delta;

	/*
	if(time_d < (1.0 / 60.0)) {
		return;
	}else {
		time_d = 0;
	}

	pos->x += 4 * delta;
 
	if(pos->x > 4) {
		pos->x = -4;
	}
	*/

	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	gp->draw_object();

	//glRotatef(r, 0, 1, 0);
	//LINE_LOOP, QUADS, POLYGON etc
	/*
	DrawCube(*scale, *pos);	
	DrawLine(0, 0, 0, 0);

	std::ostringstream stream;
	stream << r;
	std::string res = stream.str();
	DrawString(-0.8, 0.8, res);
	*/
	glutSwapBuffers();
};

//initialize once
void graphics::init() {

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

void DrawCube(vector3 scale, vector3 pos) {
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
	vertex[0][0] = -scale.x + pos.x; vertex[0][1] = -scale.y + pos.y; vertex[0][2] = -scale.z + pos.z;
	vertex[1][0] =  scale.x + pos.x; vertex[1][1] = -scale.y + pos.y; vertex[1][2] = -scale.z + pos.z;
	vertex[2][0] =  scale.x + pos.x; vertex[2][1] =  scale.y + pos.y; vertex[2][2] = -scale.z + pos.z;
	vertex[3][0] = -scale.x + pos.x; vertex[3][1] =  scale.y + pos.y; vertex[3][2] = -scale.z + pos.z;
	vertex[4][0] = -scale.x + pos.x; vertex[4][1] = -scale.y + pos.y; vertex[4][2] =  scale.z + pos.z;
	vertex[5][0] =  scale.x + pos.x; vertex[5][1] = -scale.y + pos.y; vertex[5][2] =  scale.z + pos.z;
	vertex[6][0] =  scale.x + pos.x; vertex[6][1] =  scale.y + pos.y; vertex[6][2] =  scale.z + pos.z;
	vertex[7][0] = -scale.x + pos.x; vertex[7][1] =  scale.y + pos.y; vertex[7][2] =  scale.z + pos.z;

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

//regist render object
void graphics::create_object(int type, vector3 pos) {
	obj_list[obj_length] = pos;
	obj_length++;
}

//draw registered render object
void graphics::draw_object() {
	for(int i = 0; i < obj_length; i++) {
		vector3* scl = new vector3(1, 1, 1);
		vector3 obj = obj_list[i];
		DrawCube(*scl, obj);	
	}	
}

/**/
int main() {
	gp = new graphics();
	vector3* v1 = new vector3(2, 0, 0);
	vector3* v2 = new vector3(-2, 0, 0);
	gp->create_object(0, *v1);
	gp->create_object(0, *v2);
	gp->init();
	
	return 0;
}
/**/
