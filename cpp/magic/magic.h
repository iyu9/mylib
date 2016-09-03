#include <string>

class magic {
public:
  int id;
  int cost;
  int type;
  int val;
  std::string name;
  bool is_use;

  void use()
  {
	//eff exec
	is_use = true;	
  }

};
