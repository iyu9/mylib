#include "random.h"

//constructors
ran::ran() {
	srand((unsigned)time(NULL));
}

ran::~ran() {
			
}

//functions
int ran::value() {
	return rand();
}

int ran::max() {
	return RAND_MAX;		
}


int main() {
	ran* r;
	std::cout << r->max() << std::endl;
	std::cout << r->value() << std::endl;
	return 0;
}
