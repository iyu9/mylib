#include "graphics.h"
#include <sstream>  //for transf wchar
#include <stdlib.h>	//for key input

#include <GL/glut.h>

//#include <d3d9.h>
//#include <d3dx9.h>

//global declaration
float r = 0;
float timer = 0;

chrono* chr;
graphics* g;
vector3* pos;

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


void DrawLine(float x1, float y1, float x2, float y2);
void DrawString(float x, float y, std::string const& str);
void DrawRect(float x, float y, float width, float height);
void DrawCube(vector3 scale, vector3 pos);

graphics::graphics()
{
  r = 0;
  chr = new chrono();
  pos = new vector3(0,0,0);
}

graphics::~graphics(){}

void switch_camera()
{		
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
	  glTranslatef(0, 0.1, 0);
	  break;

  case 's':
	  glTranslatef(0, -0.1, 0);
	  break;

  case 'a':
	  glTranslatef(-0.1, 0, 0);
	  break;

  case 'd':
	  glTranslatef(0.1, 0, 0);
	  break;

  case 'z':
	  glTranslatef(0, 0, 0.1);
	  break;

  case 'x':
	  glTranslatef(0, 0, -0.1);
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

void resize(int w, int h)
{
	glViewport(0, 0, w, h);

	glLoadIdentity();
	//glOrtho(-2.0, 2.0, -2.0, 2.0, -2.0, 2.0);
	gluPerspective(30.0, (double)w / (double)h, 1.0, 100.0);
	gluLookAt(3.0, 4.0, 5.0, 0.0, 0.0, 0.0, 0.0, 1.0, 0.0);
}

void idle()
{
	glutPostRedisplay();
}

void graphics::init()
{
	state = 0;	
	int argc = 1;

	glutInitWindowPosition(100,100);
	glutInitWindowSize(300,300);
	glutInit(&argc, NULL);
	glutInitDisplayMode(GLUT_RGBA | GLUT_DEPTH);
	glutCreateWindow(NULL);
	glutDisplayFunc(/*display*/render);
	glutIdleFunc(idle);
	glutReshapeFunc(resize);
	glClearColor(0, 0, 0, 1);
	glEnable(GL_DEPTH_TEST);
	glutKeyboardFunc(keyboard);
	glutMainLoop();
}

void DrawLine(float x1, float y1, float x2, float y2)
{
	glBegin(GL_LINE_LOOP);
	glVertex2d(x1, y1);	
	glVertex2d(x2, y2);
	glEnd();
}

void DrawRect(float x, float y, float width, float height)
{
	glBegin(GL_QUADS);
	glVertex2d(x,y);	
	glVertex2d(x + width, y);
	glVertex2d(x + width, y + height);
	glVertex2d(x, y + height);
	glEnd();
}

void DrawString(float x, float y, std::string const& str)
{
	float z = -1.0f;
	glRasterPos3f(x, y, z);

	for(int i = 0; i < str.length(); i++) {
		glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, str[i]);
	}
}

void DrawCube(vector3 pos, vector3 scale)
{
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
	
	vertex[0][0] = -scale.x + pos.x; vertex[0][1] = -scale.y + pos.y; vertex[0][2] = -scale.z + pos.z;
	vertex[1][0] =  scale.x + pos.x; vertex[1][1] = -scale.y + pos.y; vertex[1][2] = -scale.z + pos.z;
	vertex[2][0] =  scale.x + pos.x; vertex[2][1] =  scale.y + pos.y; vertex[2][2] = -scale.z + pos.z;
	vertex[3][0] = -scale.x + pos.x; vertex[3][1] =  scale.y + pos.y; vertex[3][2] = -scale.z + pos.z;
	vertex[4][0] = -scale.x + pos.x; vertex[4][1] = -scale.y + pos.y; vertex[4][2] =  scale.z + pos.z;
	vertex[5][0] =  scale.x + pos.x; vertex[5][1] = -scale.y + pos.y; vertex[5][2] =  scale.z + pos.z;
	vertex[6][0] =  scale.x + pos.x; vertex[6][1] =  scale.y + pos.y; vertex[6][2] =  scale.z + pos.z;
	vertex[7][0] = -scale.x + pos.x; vertex[7][1] =  scale.y + pos.y; vertex[7][2] =  scale.z + pos.z;

	glBegin(GL_QUADS);
	for (int j = 0; j < 6; ++j) {
		glColor3dv(color[j]);
		for (int i = 0; i < 4; ++i) {
			glVertex3dv(vertex[face[j][i]]);
		}
	}
	glEnd();
}

void graphics::add_object(object* obj)
{
	obj_list[obj_length] = obj;
	obj_length++;
}

void graphics::draw_object()
{
	for (int i = 0; i < obj_length; i++)
	{
		object obj = *obj_list[i];
		DrawCube(obj.pos, obj.scale);		
	}	
}

GLuint loadImage(const char* path)
{
  int width, height;
  unsigned char *data;

  width = 100;
  height = 100;

  GLuint tex;
  glGenTextures(1, &tex);
  glBindTexture(GL_TEXTURE_2D, tex);
  gluBuild2DMipmaps(GL_TEXTURE_2D, 3, width, height, GL_RGB, GL_UNSIGNED_BYTE ,data);

  delete(data);

  return tex;
}

void graphics::render()
{
	double delta = chr->get_delta();
	timer += delta;

	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	//main	
	//g->draw_object();

	//for debug
	pos->x += delta;
	vector3 s(1,1,1);
	DrawCube(*pos, s);
		
	std::ostringstream stream;
	/**/
	stream << timer;
	std::string str = stream.str();
	DrawString(-0.8, 0.8, str);
	/**/
	stream << delta;
	std::string d_str = stream.str();
	DrawString(-0.8, 1, d_str);
	glutSwapBuffers();
}

object* graphics::get_object(std::string name)
{	
	for (int i = 0; i < obj_length; i++)
	{
		object* obj = obj_list[i];

		if(obj->name == name)
		{
			return obj_list[i];	
		}
	}	

	return NULL;
}

/**/
int main()
{
	g = new graphics();
	vector3* v1 = new vector3(2, 0, 0);
	vector3* v2 = new vector3(-2, 0, 0);
	vector3* v3 = new vector3(0, 0, 2);
	vector3* v4 = new vector3(0, 0, -2);
	vector3* v5 = new vector3(0, -2, 0);

	vector3* s1 = new vector3(1, 1, 1);
	vector3* s2 = new vector3(10, 0.1, 10);
	vector3* s3 = new vector3(100, 100, 100);

	object* o1 = new object(*v1, *s1);
	object* o2 = new object(*v2, *s1);
	object* o3 = new object(*v3, *s1);
	object* o4 = new object(*v4, *s1);
	object* o5 = new object(*v5, *s2);

	g->add_object(o1);
	g->add_object(o2);
	g->add_object(o3);
	g->add_object(o4);
	g->add_object(o5);
	g->init();

	//object* which = g->get_object("no_name");
	//g->obj_list[0]->scale = *s3;
	
	return 0;
}
/**/
