#include "../vector/vector3.cpp"
#include "../common/common.h"

float g = 0.98;

class physics {
public:  
  Vector3 v;
  Vector3 pos;
  Vector3 range;
  float t;

public:
  physics();
  ~physics();

  Vector3 update()
  {
    pos.x += v.x * t;
    pos.y += (v.y * t) - (0.5 * g * t * t);
    pos.z += v.y * t;

    return pos;
  }

  bool is_collision(physics op)
  {
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

   
};
