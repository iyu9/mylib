#include "scene.h"

/*
 * Scene Transition Control Class
 * @Written by Tomii
 * */

scene::scene() {
    this->state = state_enter;
    this->id = 0;
    this->name = "";        
}

scene::scene(int id_, std::string name_) {
	this->state = state_enter;
	this->id = id_;
	this->name = name_;	
}

scene::scene(int id_) {
	this->state = state_enter;
	this->id = id_;
	this->name = "";	
}
scene::scene(std::string name_) {
	this->state = state_enter;
	this->id = -1;
	this->name = name_;	
}

scene::~scene() {
	//release		
}

void scene::update() {
	if (state == state_enter) {
		on_enter();
		state = state_update;
		return;		
	}

	//update main
	on_update();

	if (state == state_exit) {
		on_exit();
		return;		
	}
}

void scene::on_update() {
	//std::cout << "on_update" << std::endl;
}

void scene::on_enter() {
	//std::cout << "on_enter" << std::endl;	
}

void scene::on_exit() {	
	//std::cout << "on_exit" << std::endl;
}

bool scene::is_exit() {
	return (state == state_exit);	
}

/*
int main() {
	scene* s = new scene(0, "name");
	
	while(!s->is_exit()){
		s->update();
	}

	delete(s);
	return 0;
}
*/
