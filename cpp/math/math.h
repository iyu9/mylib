#include "../common/common.h"

class math {
private:

public:
  math();
  ~math();

  int cut_lower(int val, int lower);
  int cut_upper(int val, int upper);
  int cut_area(int val, int lower, int upper);
};
