#include "../common/common.h"

/*
 * 矩形クラス
 */
class rect
{
public:
  int x;
  int y;

  float w;
  float h;

  rect();
  rect(int x_, int y_, float w_, float h_);
  rect(float w_, float h_);
  ~rect();

  void set_position(int x_, int y_);
  void set_size(float w_, float h_);
};
