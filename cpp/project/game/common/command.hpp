#include "../../../common/common/common.h"

namespace Command
{
  enum Command
  {
	Start,
	Load,
	Continue,
	Option,
	Exit,
  };

  static std::string checkCommands[] =
  {
	"start",
	"load",
	"continue",
	"option",
	"exit",
  };
}
