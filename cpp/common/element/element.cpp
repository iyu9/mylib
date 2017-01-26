#ifndef __ELEMENT__HPP__
#define __ELEMENT__HPP__

#include "../common/common.h"
#define DEBUG

namespace Elements
{
  enum ElementID
  {
	FLAME,
	ICE,
	THUNDER,
	WIND,
	HOLY,
	EVIL
  };

  std::string name[] =
  {
	"FLAME", "ICE", "THUNDER", "WIND",
	"HOLY", "EVIL"
  };
};

#ifdef DEBUG
int main()
{
  println(Elements::name[Elements::EVIL]);

  return 0;  
}
#endif

#endif
