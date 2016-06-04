#include "chrono.h"

chrono::chrono() {
	prev_time = 0;
}

chrono::~chrono() {

}

double chrono::get_sec() {
	double sec = (double)clock() / (double)CLOCKS_PER_SEC;
	prev_time = sec;

	return sec;
}

double chrono::get_delta() {
	clock_t current_clock = clock();
	clock_t delta_clock = current_clock - prev_clock;
	double delta_sec = (double) delta_clock / (double)CLOCKS_PER_SEC;

	prev_clock = current_clock;
	return delta_sec;
}

/*
int main() {
  chrono* c = new chrono();

  while(1) {
  	std::cout << "get_sec(): " << c->get_sec() << std::endl;
  	std::cout << "get_delta(): " << c->get_delta() << std::endl;
  }

  return 0;
}
*/
