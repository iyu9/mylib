#include "td.h"

td::td() {

}

td::td(std::string filename) {
  ifs = new std::ifstream(filename);

  // not implemented, cos imaginary...
  while(*ifs.readline() != EOF) {
	std::string line;
	*ifs >> line;
	std::string[] parseList = line.parse(" ");

	for(std::string parse in parseList) {
	  termList.add(parse);
	}
  }
}

td::~td() {

}

/**/
int main() {
  td* t = new td();
  delete(t);

  return 0;
}
/**/
