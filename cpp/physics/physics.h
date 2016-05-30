#include "../vector/vector2.cpp"
#include "../common/common.h"

class physics {
private:  
  vector2 velocity;
  vector2 pos;
  float time;

public:
  physics();
  ~physics();
};
