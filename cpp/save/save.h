#include "../common/common.h"
#include <fstream>

const int FILEMODE_TEXT = 0;
const int FILEMODE_BIN = 1;

class savemanager {
	private:
		std::ifstream *ifs;
		std::ofstream *ofs;

		int time;
		int count;

	public:
		savemanager();
		~savemanager();

		int save();
		int save(const char* file);
		int save(const char* file, int type);
		int load();
		int load(const char* file);
};
