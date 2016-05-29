#include <fstream>

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
		int load();
		int load(const char* file);
};
