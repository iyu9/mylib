#include "../common/common.h"

class mino {
private:
  int type;
  int val[4][4];

public:
  mino();
  mino(int type);
  ~mino();

  void print();
  //not implemented
  void rotate();
};
