#include "object.h"

object::object() {
	this->id = 0;
	this->name = "no_name";
	this->pos = vector3(0,0,0);
	this->scale = vector3(1,1,1);
}

object::object(int id, std::string name) {
	this->id = id;
	this->name = name;
	this->pos = vector3(0,0,0);
	this->scale = vector3(1,1,1);
}

object::object(vector3 pos, vector3 scale) {
	this->name = "no_name";
	this->pos = pos;
	this->scale = scale;
}

object::object(int id, vector3 pos, vector3 scale) {
	this->id = id;
	this->name = "no_name";
	this->pos = pos;
	this->scale = scale;
}

object::object(int id, std::string name, vector3 pos, vector3 scale) {
	this->id = id;
	this->name = name;
	this->pos = pos;
	this->scale = scale;
}

object::~object() {

}

/*
int main() {
  object* o = new object();

  return 0;
}
*/
