#include "vector3.h"

//constructors
Vector3::Vector3(){
	x = 0;
	y = 0;
	z = 0;	
}

Vector3::Vector3(float x_, float y_, float z_){
	x = x_;
	y = y_;
	z = z_;	
}

//operators
Vector3* Vector3::operator +(Vector3* v_) {
	Vector3 *v = new Vector3();
	v->x = x + v_->x;
	v->y = y + v_->y;
	v->z = z + v_->z;
	return v;
}

Vector3* Vector3::operator -(Vector3* v_) {
	Vector3 *v = new Vector3();
	v->x = x - v_->x;
	v->y = y - v_->y;
	v->z = z - v_->z;
	return v;
}

Vector3* Vector3::operator *(float f) {
	Vector3 *v = new Vector3();
	v->x = x * f;
	v->y = y * f;
	v->z = z * f;
	return v;
}

Vector3* Vector3::operator /(float f) {
	Vector3 *v = new Vector3();
	v->x = x / f;
	v->y = y / f;
	v->z = z / f;
	return v;
}

/*unit-test*/
#include <iostream>
int main() {
	
	Vector3* a = new Vector3(12, 3, 4);
	Vector3* b = new Vector3(14, 5, 4);
	std::cout << a->x << ", " << a->y << std::endl;
	delete(a);
	delete(b);
	return 0;		
}
/**/
