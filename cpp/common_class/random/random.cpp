#include "random.h"

t_random::t_random() {
	srand((unsigned)time(NULL));
}

t_random::~t_random() {
			
}

int t_random::value() {
	return rand();
}

int t_random::max() {
	return RAND_MAX;		
}

float t_random::per() {
	return ((float)rand() / (float)RAND_MAX);
}

/**/
int main() {
	t_random* r = new t_random();

	std::cout << r->max() << std::endl;
	std::cout << r->value() << std::endl;
	for(int i = 0; i < 100; i++) {
		std::cout << r->per() << std::endl;
	}

	return 0;
}
/**/
