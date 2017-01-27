#ifndef __ELEMENT__HPP__
#define __ELEMENT__HPP__

#include "../common/common.h"

#define DEBUG
namespace Element
{
  enum ElementType
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
  println(Element::name[Element::EVIL]);

  return 0;  
}
#endif

#endif
