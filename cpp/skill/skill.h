#include "../common/common.h"

const int SK_ATTACK = 0;
const int SK_HEAL = 1;

class skill {
private:
  int id;
  std::string name;
  int type;
  int attr;
  int value;

public:
  skill();
  ~skill();
};
