#include "../common/common.h"

const int NodeLimitNum = 10;

template <typename T> class node
{
private:
  int id;

public:
  std::string name;

  T prev[NodeLimitNum];
  T next[NodeLimitNum];
  int prevCount;
  int nextCount;

  void addNextNode(T next)
  {
	next[nextCount] = next;
	nextCount++;
  }

  void addPrevNode(T prev)
  {	
	prev[prevCount] = prev;
	prevCount++;
  }
};
