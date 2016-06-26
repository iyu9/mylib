#include "../common/common.h"

const int TD_W_MAX = 100;
const int TD_H_MAX = 100;

class td {
private:
  std::ifstream ifs;
  int matrix[TD_W_MAX][TD_H_MAX];

public:
  td();
  td(std::string filename);
  ~td();
};
