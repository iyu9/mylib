#include "../common/common.h"

const int SK_ATTACK = 0;
const int SK_HEAL = 1;

class skill {
public:
  int id;
  std::string name;
  int type;
  int attr;
  int value;

  skill();
  ~skill();
};
