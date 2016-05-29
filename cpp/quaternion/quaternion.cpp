#include "quaternion.h"

quaternion::quaternion() {
    x = y = z = w = 0;        
}

quaternion::quaternion(float x, float y, float z) {
    this->x = x;
    this->y = y;
    this->z = z;
}

quaternion::~quaternion() {}

void quaternion::set_rotation(float x, float y, float z) {
    this->x = x; 
    this->y = y;
    this->z = z;
}

//x, y, z are 0-1 normalized vectors
void quaternion::rotate(float x, float y, float z, float theta) {
    this->x = (x * sin(theta * M_PI)) / 2; 
    this->y = (y * sin(theta * M_PI)) / 2;
    this->z = (z * sin(theta * M_PI)) / 2;
    this->w = cos(theta * M_PI) / 2;
}

/**/
int main () {
    quaternion* q = new quaternion(45, 45, 0);
    q->rotate(0, 1, 0, 45);
    std::cout << "x = " << q->x << std::endl;
    std::cout << "y = " << q->y << std::endl;
    std::cout << "z = " << q->z << std::endl;
    std::cout << "w = " << q->w << std::endl;
}
/**/
