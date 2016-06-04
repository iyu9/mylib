#include "../common/common.h"

#include "../vector/vector3.cpp"
#include "../object/object.cpp"

class obj_manager {

private:
  int count;
  object* obj[99];

public:
  obj_manager();
  ~obj_manager();

  void add(object* obj);
  void remove(object* obj);
  object* get_object(std::string name);

  void save();
  void load();
};
