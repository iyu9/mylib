#include "physics.h"

physics::physics() {

}

physics::~physics() {

}

Vector3 physics::update() {
  pos.x += v.x * t;
  pos.y += (v.y * t) - (0.5 * g * t * t);
  pos.z += v.y * t;

  return pos;
}

bool physics::is_collision(physics op) {
    float r = 2; 
    Vector3 a = this->pos;
    Vector3 b = op.pos;
    if( 
        (
          (a.x-b.x)*(a.x-b.x) 
        + (a.y-b.y)*(a.y-b.y) 
        + (a.z-b.z)*(a.z-b.z) ) >=  r*r
        )
    {
      return true;
    }
    
  return false;
}

/**/
int main() {
  physics* p = new physics();
  delete(p);

  while(1) {
    p->update();
  }

  return 0;
}
/**/
