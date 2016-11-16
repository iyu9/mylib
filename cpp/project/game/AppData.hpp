#include "../../common_class/common/common.h"

namespace AppData
{
  const char* const OutPutDirectory = "./data/";
  const char* const OutPutFileName = "SaveData.txt";

  class AppData
  {
	static std::string playerName;
	static std::string lastLoginData;
	static int clearFlag;
  };
  
  void Save()
  {
	print("Data Saved");
  }

  void Load()
  {
	print("Data Loaded");
  }

  void Clear()
  {
	print("Data Cleared");
  }
};

#ifdef UNIT_TESTING
int main ()
{
  AppData::Clear();
  AppData::Load();
  AppData::Save();  

  return 0;
}
#endif
