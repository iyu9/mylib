#include "../common/common.h"

std::string COLOR_RED = "red";
std::string COLOR_GREEN = "green";
std::string COLOR_BLUE = "blue";
std::string COLOR_BLACK = "black";
std::string COLOR_WHITE = "white";
std::string COLOR_GRAY = "gray";

class color {

public:
  float r, g, b, a;

  color();
  color(std::string color_name);
  color(float r, float g, float b, float a);
  color(float r, float g, float b);
  ~color();

  void attach();
};
