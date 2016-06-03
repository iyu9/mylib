#include "chrono.h"

chrono::chrono() {
	this->prev_time = 0;
}

chrono::~chrono() {

}

float chrono::get_sec() {
	float sec = ( (float)clock() / (float)CLOCKS_PER_SEC );
	this->prev_time = sec;
	return sec;
}

float chrono::get_delta() {
	float current = ( (float)clock() / (float)CLOCKS_PER_SEC );
	float delta = current - this->prev_time;
	this->prev_time = current;
	return delta;
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