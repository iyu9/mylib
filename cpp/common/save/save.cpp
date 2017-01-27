#ifndef __SAVE_H__
#define __SAVE_H__

#include "save.h"

save_manager::save_manager()
{
	ifs = NULL;
	ofs = NULL;
}

save_manager::~save_manager()
{
	delete(ifs);
	delete(ofs);		
}

int save_manager::save()
{
	ofs = new std::ofstream("save.dat");

	//Write Attributes
	
	return 0;	
}

int save_manager::save(const char* file)
{
	ofs = new std::ofstream(file);
	return 0;	
}

int save_manager::save(const char* file, int filemode)
{
	//TODO:add binmode
	ofs = new std::ofstream(file);
	return 0;	
}

int save_manager::load()
{
	ifs = new std::ifstream("save.dat");
	std::string buffer;

	while (*ifs && getline(*ifs, buffer))
	{
		std::cout << buffer << std::endl;
	}

	return 0;	
}

int save_manager::load(const char* file)
{
	ifs = new std::ifstream(file);
	std::string buffer;

	while (*ifs && getline(*ifs, buffer))
	{
		std::cout << buffer << std::endl;
	}

	return 0;	
}

#ifdef DEBUG
int main()
{
	save_manager* s = new save_manager();

	s->load();
	s->save();

	delete(s);
	return 0;
}
#endif

#endif
