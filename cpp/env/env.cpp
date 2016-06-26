#include "env.h"

env::env() {

}

env::~env() {

}

/**/
int main() {
  env* e = new env();

  //simple shell?
  while(1) {
	std::string cmd;
	std::cin >> cmd;

	switch(cmd[0]) {
	  case 'q':
		break;

	  case 's':
		break;
	}
  }

  return 0;
}
/**/
