#include "../common/common.h"

class chrono {
private:
  clock_t start;
  clock_t end;
  clock_t prev_clock;

public:
  chrono();
  ~chrono();

  clock_t get_clock_time();
  clock_t get_clock_sec();
  clock_t get_clock_delta();

  double get_time();
  double get_sec();
  double get_delta();
};
