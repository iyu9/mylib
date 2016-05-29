#include <iostream>
#include <fstream>
#include <string>
#include "save.h"

//global declaration
int m_text_index = 0;
std::string m_text_map[100];

//forward declaration
void decode_syntax(std::string str);
void mapping_text(std::string text);

//constructors
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
int savemanager::save() {
	ofs = new std::ofstream("save.dat");
	*ofs << "Count: " << count << std::endl;
	
	return 0;	
}

int savemanager::save(const char* file) {
	ofs = new std::ofstream(file);
	*ofs << "Count: " << count << std::endl;
	
	return 0;	
}

int savemanager::load() {
	ifs = new std::ifstream("sample.script");
	std::string buffer;

	while (*ifs && getline(*ifs, buffer)) {
		std::cout << buffer << std::endl;
		decode_syntax(buffer);
	}

	return 0;	
}


int savemanager::load(const char* file) {
	ifs = new std::ifstream(file);
	std::string buffer;

	while (*ifs && getline(*ifs, buffer)) {
		std::cout << buffer << std::endl;
		decode_syntax(buffer);
	}

	return 0;	
}

//script read defined
void decode_syntax(std::string str) {
	if(str.find("text_start:") != -1) {
		std::cout << "TEXT_BEGIN" << std::endl;
		return;
	}

	if(str.find("text_end:") != -1) {
		std::cout << "TEXT_END" << std::endl;
		return;
	}

	mapping_text(str);
}

//read file mode
void mapping_text(std::string text) {
	m_text_index++;
	m_text_map[m_text_index] = text; 
}

/* unit-test */
int main() {
	savemanager* s = new savemanager();

	s->load();
	s->save();

	//text check
	int cmd;
	while(1) {
		std::cin >> cmd;
		std::cout << m_text_map[cmd];
	}

	delete(s);
	return 0;
}
/* */
