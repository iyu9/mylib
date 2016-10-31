#include "vector2.h"

const vector2 vector2::zero = vector2(0, 0);
const vector2 vector2::one = vector2(1, 1);

//constructors
vector2::vector2(){
	x = 0;
	y = 0;	
}

vector2::vector2(float x_, float y_){
	x = x_;
	y = y_;	
}

//operators
vector2* vector2::operator+(vector2* v_) {
	vector2 *v = new vector2();
	v->x = x + v_->x;
	v->y = y + v_->y;
	return v;
}

vector2* vector2::operator-(vector2* v_) {
	vector2 *v = new vector2();
	v->x = x - v_->x;
	v->y = y - v_->y;
	return v;
}

vector2* vector2::operator*(float f) {
	vector2 *v = new vector2();
	v->x = x * f;
	v->y = y * f;
	return v;
}

vector2* vector2::operator/(float f) {
	vector2 *v = new vector2();
	v->x = x / f;
	v->y = y / f;
	return v;
}


/**/
#include <iostream>
int main ()
{
	vector2* a = new vector2(12, 3);
	vector2* b = new vector2(14, 5);
	std::cout << a->x << ", " << a->y << std::endl;

    std::cout << vector2::zero.x;

	delete(a);
	delete(b);
	return 0;		
}
/**/
