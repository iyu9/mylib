#include <iostream>
#include <string>

class base_object
{
public:
  int id;
  int type;
  int num;
  int is_used;
  int val;

  std::string name;

  base_object()
  {
	std::cout << "base_object CREATED" << std::endl;
  }

  virtual void use()
  {
	switch(type)
	{
	  case 0:
	  case 1:
	  case 2:
	  break;
	}		
  }
};

/**/
int main ()
{
  base_object* b = new base_object();

  return 0;  
}
/**/
