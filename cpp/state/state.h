#include "../common/common.h"

class base_state
{
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
};

//-----------------------
//imaginary use example
//-----------------------

class Title : base_state
{
  Title() : base_state()
  {
	
  }

  ~Title()
  {
	
  }
};

class Battle : base_state
{
  Battle() : base_state()
  {
	
  }

  ~Battle()
  {
	
  }
};

class Option : base_state
{
  Option() : base_state()
  {
	
  }

  ~Option()
  {
	
  }
};
