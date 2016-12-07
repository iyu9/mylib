#include "../common/common.h"

#include "../vector/vector3.cpp"
#include "../chrono/chrono.cpp"

const float g = 0.98;

const int PH_GROUND 	= 0;
const int PH_FLOW 		= 1;

const float AREA_LIMIT = 100;

class physics {

private:
  void update_stat();
  void fall_down();

public:  
  chrono* ch;
  vector3 v;
  vector3 pos;
  vector3 range;
  float t;
  float m;
  int stat;

  physics();
  physics(float vx, float vy, float vz);
  ~physics();

  vector3 update();
  bool add_force(vector3 a);
  bool is_collision(physics op);
  bool is_collision_floor(physics op);
};
