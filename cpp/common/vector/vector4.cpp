#include "vector4.h"

vector4::vector4(){
	x = 0;
	y = 0;
	z = 0;
	w = 0;	
}

vector4::vector4(float x_, float y_, float z_, float w_){
	x = x_;
	y = y_;
	z = z_;	
	w = w_;
}

vector4* vector4::operator+(vector4* v_) {
	vector4 *v = new vector4();
	v->x = x + v_->x;
	v->y = y + v_->y;
	v->z = z + v_->z;
	v->w = w + v_->w;
	return v;
}

vector4* vector4::operator-(vector4* v_) {
	vector4 *v = new vector4();
	v->x = x - v_->x;
	v->y = y - v_->y;
	v->z = z - v_->z;
	v->w = w - v_->w;
	return v;
}

vector4* vector4::operator*(float f) {
	vector4 *v = new vector4();
	v->x = x * f;
	v->y = y * f;
	v->z = z * f;
	v->w = w / f;
	return v;
}

vector4* vector4::operator/(float f) {
	vector4 *v = new vector4();
	v->x = x / f;
	v->y = y / f;
	v->z = z / f;
	v->w = w / f;
	return v;
}

/*
int main () {
	
	vector4* a = new vector4(12, 3, 4, 5);
	vector4* b = new vector4(14, 5, 4, 5);
	std::cout << a->x << ", " << a->y << std::endl;
	delete(a);
	delete(b);
	return 0;		
}
*/
