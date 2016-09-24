#include "network.h"

network::network() {

}

network::~network() {

}

void network::http_request()
{
  
}

void network::on_http_respond()
{
  
}

/**/
int main()
{
  network* n = new network();

  n->http_request();

  while(1)
  {
	n->on_http_respond();
  }

  return 0;
}
/**/
