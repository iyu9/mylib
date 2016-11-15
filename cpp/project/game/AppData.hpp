#include "../../common_class/common/common.h"

namespace AppData
{
  class AppData
  {
	static std::string playerName;
	static std::string lastLoginData;
	static int clearFlag;
  };
  
  void Save(){}
  void Load(){}
};

/**/
int main ()
{
  AppData::Save();  

  return 0;
}
/**/
