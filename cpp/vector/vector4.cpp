#include "vector4.h"

//constructors
Vector4::Vector4(){
	x = 0;
	y = 0;
	z = 0;
	w = 0;	
}

Vector4::Vector4(float x_, float y_, float z_, float w_){
	x = x_;
	y = y_;
	z = z_;	
	w = w_;
}

//operators
Vector4* Vector4::operator+(Vector4* v_) {
	Vector4 *v = new Vector4();
	v->x = x + v_->x;
	v->y = y + v_->y;
	v->z = z + v_->z;
	v->w = w + v_->w;
	return v;
}

Vector4* Vector4::operator-(Vector4* v_) {
	Vector4 *v = new Vector4();
	v->x = x - v_->x;
	v->y = y - v_->y;
	v->z = z - v_->z;
	v->w = w - v_->w;
	return v;
}

Vector4* Vector4::operator*(float f) {
	Vector4 *v = new Vector4();
	v->x = x * f;
	v->y = y * f;
	v->z = z * f;
	v->w = w / f;
	return v;
}

Vector4* Vector4::operator/(float f) {
	Vector4 *v = new Vector4();
	v->x = x / f;
	v->y = y / f;
	v->z = z / f;
	v->w = w / f;
	return v;
}

/*unit-test*/
#include <iostream>
int main () {
	
	Vector4* a = new Vector4(12, 3, 4, 5);
	Vector4* b = new Vector4(14, 5, 4, 5);
	std::cout << a->x << ", " << a->y << std::endl;
	delete(a);
	delete(b);
	return 0;		
}
/**/
