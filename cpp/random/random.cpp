#include "random.h"

ran::ran() {
	srand((unsigned)time(NULL));
}

ran::~ran() {
			
}

int ran::value() {
	return rand();
}

int ran::max() {
	return RAND_MAX;		
}

float ran::per() {
	return ((float)rand() / (float)RAND_MAX);
}

/**/
int main() {
	ran* r;
	std::cout << r->max() << std::endl;
	std::cout << r->value() << std::endl;
	for(int i=0; i < 100; i++) {
		std::cout << r->per() << std::endl;
	}
	return 0;
}
