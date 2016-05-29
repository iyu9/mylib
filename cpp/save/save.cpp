#include "save.h"

savemanager::savemanager() {
	ifs = NULL;
	ofs = NULL;
	time = 0;
	count = 0;
}

savemanager::~savemanager() {
	delete(ifs);
	delete(ofs);		
}

//functions

void ReadDataStructure() {
		
}

void WriteDataStructure(ofstream* ofs) {
	*ofs << "Count: " << count << std::endl;	
}

int savemanager::save() {
	ofs = new std::ofstream("save.dat");

	//Write Attributes
	*ofs << "Count: " << count << std::endl;
	
	return 0;	
}

int savemanager::save(const char* file) {
	ofs = new std::ofstream(file);
	*ofs << "Count: " << count << std::endl;
	
	return 0;	
}

int savemanager::load() {
	ifs = new std::ifstream("save.dat");
	std::string buffer;

	while (*ifs && getline(*ifs, buffer)) {
		std::cout << buffer << std::endl;
	}

	return 0;	
}

int savemanager::load(const char* file) {
	ifs = new std::ifstream(file);
	std::string buffer;

	while (*ifs && getline(*ifs, buffer)) {
		std::cout << buffer << std::endl;
	}

	return 0;	
}

/*unit-test*/
int main() {
	savemanager* s = new savemanager();

	s->load();
	s->save();

	delete(s);
	return 0;
}
/**/
