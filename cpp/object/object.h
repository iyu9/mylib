#include "../common/common.h"

//dependent::
//#include "../vector/vector3.cpp"

class object {
private:
  int id;
  std::string name;
  vector3 pos;
  vector3 scale;
  int prim_type;
  int tris;

public:
  object();
  object(int id, std::string name);
  object(vector3 pos, vector3 scale);
  object(int id, vector3 pos, vector3 scale);
  object(int id, std::string name, vector3 pos, vector3 scale);
  ~object();
};
