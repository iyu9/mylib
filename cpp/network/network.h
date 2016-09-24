#include "../common/common.h"

class network
{
public:
  network();
  ~network();

  void http_request();
  void on_http_respond();
};
