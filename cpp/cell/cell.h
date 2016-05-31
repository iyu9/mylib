#include "../common/common.h"
#include "../random/random.cpp"

class cell {

public:
  int id;
  int status;

  int x;
  int y;

  int width;
  int height;

  int row;
  int col;

  int img[100];
  int img_length;

  cell();
  cell(int x, int y, int width, int height);
  ~cell();
};
