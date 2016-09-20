#include "../common/common.h"

const int NodeLimitNum = 10;

template <typename T> class node {
private:
  int id;

public:
  std::string name;
  int prevCount;
  int nextCount;
  template <typename T> prev[NodeLimitNum];
  template <typename T> next[NodeLimitNum];

  node();
  node(int id, std::string name);
  ~node();

  void addNextNode(template <typename T> next)
  {
	next[nextCount] = next;
	nextCount++;
  }

  void addPrevNode(template <typename T> prev)
  {	
	prev[prevCount] = prev;
	prevCount++;
  }
};
