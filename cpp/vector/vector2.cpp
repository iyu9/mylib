#include "vector2.h"

//constructors
Vector2::Vector2(){
	x = 0;
	y = 0;	
}

Vector2::Vector2(float x_, float y_){
	x = x_;
	y = y_;	
}

//operators
Vector2* Vector2::operator+(Vector2* v_) {
	Vector2 *v = new Vector2();
	v->x = x + v_->x;
	v->y = y + v_->y;
	return v;
}

Vector2* Vector2::operator-(Vector2* v_) {
	Vector2 *v = new Vector2();
	v->x = x - v_->x;
	v->y = y - v_->y;
	return v;
}

Vector2* Vector2::operator*(float f) {
	Vector2 *v = new Vector2();
	v->x = x * f;
	v->y = y * f;
	return v;
}

Vector2* Vector2::operator/(float f) {
	Vector2 *v = new Vector2();
	v->x = x / f;
	v->y = y / f;
	return v;
}

/*unit-test begin*/
#include <iostream>
int main () {
	
	Vector2* a = new Vector2(12, 3);
	Vector2* b = new Vector2(14, 5);
	std::cout << a->x << ", " << a->y << std::endl;
	delete(a);
	delete(b);
	return 0;		
}
/*unit-test end*/
