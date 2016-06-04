#include "obj_manager.h"

obj_manager::obj_manager() {

}

obj_manager::~obj_manager() {

}

void obj_manager::add(object* obj_) {
	this->obj[count] = obj_;
	count++;		
}

void obj_manager::remove(object* obj) {
	//TODO
}

object* obj_manager::get_object(std::string name) {
	for(int i=0; i<count; i++) {
		if(obj[i]->name == name) {
			return obj[i];		
		} 
	}

	return NULL;
}

void obj_manager::save() {
	std::ofstream ofs("obj_data.txt");

	for(int i=0; i<count; i++) {
		ofs << i << std::endl;
		ofs << obj[i]->name << std::endl;
		ofs << obj[i]->pos.x << std::endl;
		ofs << obj[i]->pos.y << std::endl;
		ofs << obj[i]->pos.z << std::endl;
		ofs << obj[i]->scale.x << std::endl;
		ofs << obj[i]->scale.y << std::endl;
		ofs << obj[i]->scale.z << std::endl;
	}		
}

void obj_manager::load() {	
	std::ifstream ifs("obj_data.txt");

	for(int i=0; i<count; i++) {
		//std::cout << obj[i]->pos.x << std::endl;
	}
}

/**/
int main() {
  obj_manager* omanager = new obj_manager();
  vector3* v1 = new vector3(1, 2, 3);
  object* o1 = new object(0, "BLOCK", *v1, *v1);

  omanager->add(o1);
  omanager->save();
  return 0;
}
/**/
