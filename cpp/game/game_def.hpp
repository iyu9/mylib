#include "../common/common.h"

class GameDef
{
  public:
	std::string title;

	enum Mode
	{
	  Start,
	  Battle,
	  Option,
	  Exit,
	};
};
