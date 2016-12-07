#include "../common/common.h"

class interpret
{
private:
  std::string commandNames[10]; 
  bool act(std::string command);

public:
  interpret();
  ~interpret();

  bool parse(std::string code);
};
