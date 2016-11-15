#include "picojson.h"

using namespace picojson;

int main (void)
{

  const char* json = "{ \"name\" : \"test_user\" }";
  picojson::value v;
  std::string err;
  picojson::parse(v, json, json + strlen(json), &err);

  if (err.empty())
  {
	picojson::object& o = v.get<picojson::object>();
  }

  return 0;
}
