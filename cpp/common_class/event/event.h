#include "../common/common.h"

class event {

public:

	//attributes
	int id;
	std::string name;
	int type;

	//methods
	event();
	event(int id_, std::string name_, int type);
	~event();	
};
