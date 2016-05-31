#include "../common/common.h"

class chrono {
private:
  float prev_time;

public:
  chrono();
  ~chrono();

  float get_sec();
  float get_delta();
};
