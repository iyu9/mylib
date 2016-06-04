#include "../common/common.h"

class chrono {
private:
  double prev_time;
  clock_t prev_clock;

public:
  chrono();
  ~chrono();

  double get_sec();
  double get_delta();
};
