#include "../common/common.h"

class caller {

public:
	caller(){}

	void call_func(void (*func)()) {
		func();	
	}
	
	static void print() {	
		println("called: caller->print()");		
	}	
};

void print() {
	println("called: print()");		
}

int main() {
	caller* c = new caller();
	c->call_func(print);
	c->call_func(c->print);

	return 0;
}
