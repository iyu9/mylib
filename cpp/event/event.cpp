#include "event.h"

//global
const int EVENT_TYPE_COMMON = 0;
const int EVENT_TYPE_BATTLE = 1;
const int EVENT_TYPE_OP = 2;
const int EVENT_TYPE_ED = 3;
const int EVENT_TYPE_ADV = 4;

//constructors
event::event(){
	name = "event_no_name";	
}

event::event(int id_, std::string name_, int type_) {
	id = id_;
	name = name_;
	type = type_;
}

event::~event(){
}

/**/
int main() {
	return 0;		
}
/**/
