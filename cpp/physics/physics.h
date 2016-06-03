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

  Vector3 update();
  bool is_collision(physics op);
};
