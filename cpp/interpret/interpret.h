#include "../common/common.h"

class interpret
{
private:
  enum CommandAct
  {
	CMD_INIT,
	CMD_SHOW,
	CMD_HIDE
  };

  std::string commandNames[10]; 

public:
  interpret();
  ~interpret();

  bool parse(std::string code);
  bool act(std::string command);
};
