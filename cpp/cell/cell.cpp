#include "cell.h"

//like metroid room structure
//for random create?

cell::cell() {
	ran* r = new ran();
	this->x = r->value() % 8;
	this->y = r->value() % 8;
	this->width = r->value() % 12 + 1;  //1 <= w <= 12
	this->height = r->value() % 12 + 1; //1 <= h <= 12
}

cell::cell(int x, int y, int width, int height) {
	this->x = x;
	this->y = y;
	this->width = width;
	this->height = height;
}

cell::~cell() {

}

/**/
int main() {
  cell* c = new cell();

  println(c->x);
  println(c->y);
  println(c->width);
  println(c->height);
  return 0;
}
