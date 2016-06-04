#include "physics.h"

physics::physics() {
	ch = new chrono();	
}

physics::physics(float vx, float vy, float vz) {
	v.x = vx;
	v.y = vy;
	v.z = vz;
}

physics::~physics() {

}

//TODO:switch falldown type
void physics::fall_down() {
  pos.y += (v.y * t) - (0.5 * g * t * t);
}

void physics::update_stat() {
  //on ground
  if(pos.y <= -AREA_LIMIT) {
	stat = PH_GROUND;
	pos.y = -100;
	v.y = 0;
  }

  //on flow
  else {
	stat = PH_FLOW;	  
  }
}

vector3 physics::update() {

  update_stat();

  //update time
  t += 0.001;

  //update position
  pos.x += v.x * t;
  pos.z += v.z * t;

  //update falldown to the ground process
  if(stat != PH_GROUND) {
	fall_down();
  }

  return (pos);
}

//simple sphere_col
bool physics::is_collision(physics op) {
  float r = 2; 
  vector3 a = pos;
  vector3 b = op.pos;
  if ( 
       (a.x-b.x)*(a.x-b.x) +
       (a.y-b.y)*(a.y-b.y) +
       (a.z-b.z)*(a.z-b.z) >=  r*r
     )
  {
    return true;
  }
    
  return false;
}

bool physics::is_collision_floor(physics op) {
  //fall down floor from above
  if(is_collision(op) && pos.y >= op.pos.y) {
	//reset falldown stat
	stat = PH_GROUND;
	v.y = 0;

	return true;
  }		
  return false;
}

bool physics::add_force(vector3 a) {
	//invalid
	//vector3 vec = a * (t * t);
	//v = &vec;
}

/**/
int main() {
  physics* p = new physics(0, 100, 0);
  p->pos.y = 100;
  physics* f = new physics();

  while(1) {
    vector3 pos = p->update();

    std::cout << "time=" << p->t << ": " 
	<< "(" << pos.x << ", " << pos.y << ", " << pos.z << ")" << std::endl;
  }

  delete(p);

  return 0;
}
/**/
