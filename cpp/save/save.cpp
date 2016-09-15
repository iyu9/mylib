#include "save.h"

savemanager::savemanager()
{
	ifs = NULL;
	ofs = NULL;
	time = 0;
	count = 0;
}

savemanager::~savemanager()
{
	delete(ifs);
	delete(ofs);		
}

void ReadDataStructure()
{		
}

void WriteDataStructure(std::ofstream* ofs)
{
  *ofs << "date:" << "1423/12/32/2200" << std::endl;
  *ofs << "Count: " << "120" << std::endl;
}

int savemanager::save()
{
	ofs = new std::ofstream("save.dat");

	//Write Attributes
	WriteDataStructure(ofs);
	
	return 0;	
}

int savemanager::save(const char* file)
{
	ofs = new std::ofstream(file);
	WriteDataStructure(ofs);
	return 0;	
}

int savemanager::save(const char* file, int filemode)
{
	//TODO:add binmode
	ofs = new std::ofstream(file);
	WriteDataStructure(ofs);	
	return 0;	
}

int savemanager::load()
{
	ifs = new std::ifstream("save.dat");
	std::string buffer;

	while (*ifs && getline(*ifs, buffer)) {
		std::cout << buffer << std::endl;
	}

	return 0;	
}

int savemanager::load(const char* file)
{
	ifs = new std::ifstream(file);
	std::string buffer;

	while (*ifs && getline(*ifs, buffer)) {
		std::cout << buffer << std::endl;
	}

	return 0;	
}

/**/
int main()
{
	savemanager* s = new savemanager();

	s->load();
	s->save();

	delete(s);
	return 0;
}
/**/
