#include "vector3.h"

//constructors
vector3::vector3(){
	x = 0;
	y = 0;
	z = 0;	
}

vector3::vector3(float x_, float y_, float z_){
	x = x_;
	y = y_;
	z = z_;	
}

//operators
vector3* vector3::operator +(vector3* v_) {
	vector3 *v = new vector3();
	v->x = x + v_->x;
	v->y = y + v_->y;
	v->z = z + v_->z;
	return v;
}

vector3* vector3::operator -(vector3* v_) {
	vector3 *v = new vector3();
	v->x = x - v_->x;
	v->y = y - v_->y;
	v->z = z - v_->z;
	return v;
}

vector3* vector3::operator *(float f) {
	vector3 *v = new vector3();
	v->x = x * f;
	v->y = y * f;
	v->z = z * f;
	return v;
}

vector3* vector3::operator /(float f) {
	vector3 *v = new vector3();
	v->x = x / f;
	v->y = y / f;
	v->z = z / f;
	return v;
}

/*
int main() {
	
	vector3* a = new vector3(12, 3, 4);
	vector3* b = new vector3(14, 5, 4);
	std::cout << a->x << ", " << a->y << std::endl;
	delete(a);
	delete(b);
	return 0;		
}
*/
