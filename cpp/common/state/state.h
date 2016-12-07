#include "../common/common.h"

class base_state
{
protected:
  void on_start();
  void on_exit();

public:
  int state_id;
  int state_type;
  int state_counter;
  std::string name;
  base_state* prevState[];
  base_state* nextState[];

  base_state();
  ~base_state();
  
  bool change_state(base_state* next);
  void update();
};

//-----------------------
//imaginary use example
//-----------------------

class Title : base_state
{
  Title() : base_state(){}
  void on_start(){}
  void on_exit(){}
  void update(){}
};

class Battle : base_state
{
  Battle() : base_state(){}
  void on_start(){}
  void on_exit(){}
  void update(){}
};

class Option : base_state
{
  Option() : base_state(){}
  void on_start(){}
  void on_exit(){}
  void update(){}
};
