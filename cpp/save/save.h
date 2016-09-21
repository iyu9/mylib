#include "../common/common.h"
#include "../json/picojson.h"
#include "../actor/actor.h"
#include <fstream>

//WRITE THIS
class save_data
{
public:
  std::string date;
  actor players;
  int flags[100];
  int check_sum; 
};
//

enum FILEMODE
{
  FILEMODE_TEXT,
  FILEMODE_BIN
};

class save_manager
{
	private:
		std::ifstream *ifs;
		std::ofstream *ofs;

	public:
		save_manager();
		~save_manager();

		int save();
		int save(const char* file);
		int save(const char* file, int type);
		int load();
		int load(const char* file);
};
