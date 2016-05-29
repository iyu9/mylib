#include "input.h"

//headers
#include <iostream>
#include <string>

/*
 *	input manager class
 *	@tomii
 */

//constructors
input::input() {
	key = 0;	
}

input::~input() {
	//delete
}

//properties
char input::get_key() {
	return key;		
}
	
//methods
void input::read() {
	std::string command;
	std::cin >> command;
	key = command[0];
}

/*uni-test*/
int main() {
	input* ip = new input();
	while(ip->get_key() != 'q') {
			ip->read();
			std::cout << ip->get_key() << std::endl;
	}
	delete(ip);
}
/**/
