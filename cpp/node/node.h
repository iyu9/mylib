#include "../common/common.h"

const int NodeLimitNum = 10;

class node {
private:
  int id;
  std::string name;
  int prevCount;
  int nextCount;
  int prev[NodeLimitNum];
  int next[NodeLimitNum];

public:
  node();
  node(int id, std::string name);
  ~node();

  void addNextNode(int next) {
	if(nextCount > NodeLimitNum) {
	  std::cout << "Node NextList is Full" << std::endl;
	}

	next[nextCount] = next;
	nextCount++;
  }

  void addPrevNode(int prev) {	
	if(prevCount > NodeLimitNum) {
	  std::cout << "Node PrevList is Full" << std::endl;
	}

	prev[prevCount] = prev;
	prevCount++;
  }
};
