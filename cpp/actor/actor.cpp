#include "actor.h"

//forward
float rand_prob();

//type defined
const int TYPE_HERO = 0;
const int TYPE_KNIGHT = 1;
const int TYPE_DRAGON = 2;
const int TYPE_ARMOR = 3;
const int TYPE_WITCH = 4;

//condition defined
const int CON_FINE = 0;
const int CON_DEAD = 1;
const int CON_STONE = 2;

//constructors
actor::actor() {
	srand((unsigned)time(NULL));

	name = "no_name";
	lv = 1;
	hp = 10;
	mp = 10;
	atk = 5;
	def = 5;
	spd = 5;
	luk = 5;
	def = 5;
	move = 5;

	per_hp = 0.80;
	per_mp = 0.80;
	per_atk = 0.30;
	per_def = 0.30;
	per_spd = 0.30;
	per_luk = 0.30;
}

actor::actor(std::string name_) {
	name = name_;	
}

actor::actor(int lv) {
	lv = lv;
    name = "NO_NAME";	
}

actor::actor(std::string name_, int type_) {
	name = name_;
	type = type_;
}

actor::~actor() {
}

void actor::lvup() {

	if(lv >= 99) {
		std::cout << "already 99..." << std::endl;
		return;
	}

	lv++;
	std::cout << "LVUP: " << lv-1 << " -> " << lv << std::endl;
	
	float percent = (float) rand() / RAND_MAX;
	if(percent <= per_atk) {
		atk++;	
		std::cout << "ATK UP: " << atk << std::endl;
	}


	percent = (float) rand() / RAND_MAX;
	if(percent <= per_def) {
		def++;	
		std::cout << "DEF UP: " << def << std::endl;
	}
			

	percent = (float) rand() / RAND_MAX;
	if(percent <= per_spd) {
		spd++;	
		std::cout << "SPD UP: " << spd << std::endl;
	}


	percent = (float) rand() / RAND_MAX;
	if(percent <= per_luk) {
		luk++;	
		std::cout << "LUK UP: " << luk << std::endl;
	}


	percent = (float) rand() / RAND_MAX;
	if(percent <= per_mp) {
		mp++;	
		std::cout << "MP UP: " << mp << std::endl;
	}

	percent = (float) rand() / (float )RAND_MAX;
	if(percent <= per_hp) {
		hp++;	
		std::cout << "HP UP: " << hp << std::endl;
	}

	std::cout << std::endl;
}


void actor::lvdn() {

	if(lv <= 1) {
		std::cout << "already 0..." << std::endl;
		return;
	}

	lv--;
	std::cout << "LVDOWN: " << lv+1 << " -> " << lv << std::endl;
	
	float percent = (float) rand() / RAND_MAX;
	if(percent <= per_atk) {
		atk--;	
		std::cout << "ATK DOWN: " << atk << std::endl;
	}


	percent = (float) rand() / RAND_MAX;
	if(percent <= per_def) {
		def--;	
		std::cout << "DEF DOWN: " << def << std::endl;
	}
			

	percent = (float) rand() / RAND_MAX;
	if(percent <= per_spd) {
		spd--;	
		std::cout << "SPD DOWN: " << spd << std::endl;
	}


	percent = (float) rand() / RAND_MAX;
	if(percent <= per_luk) {
		luk--;	
		std::cout << "LUK DOWN: " << luk << std::endl;
	}


	percent = (float) rand() / RAND_MAX;
	if(percent <= per_mp) {
		mp--;	
		std::cout << "MP DOWN: " << mp << std::endl;
	}

	percent = (float) rand() / (float )RAND_MAX;
	if(percent <= per_hp) {
		hp--;	
		std::cout << "HP DOWN: " << hp << std::endl;
	}

	std::cout << std::endl;
}

int actor::check_weakness() {
  int count = 1;

  for(int i = 0; i < LIST_SIZE; i++) {
    if(weakness_list[i] == WEAK_WEAK) {
      count++;
    }
  }

  return count;
}

void actor::on_damage(actor* op) {
	float rand = rand_prob();
	int is_critical = 0;

	//hit phase
	float hit_percent = 1.0;
	float hosei = 0.1 * (op->hit - spd);
	hit_percent -= hosei;
	if(rand > hit_percent) {
		//not hit
		std::cout << "miss" << std::endl;
		return;	
	}

	//critical phase
	float cri_percent = 0.1 * (op->luk - luk);
	rand = rand_prob();
	if(rand < cri_percent) {
		is_critical = 1;
		std::cout << "critical" << std::endl;
	}

	//weakness phase
	int weak_factor = check_weakness();
	if(weak_factor > 1) {
	  std::cout << "weak" << std::endl;
	}

	//damage phase
	float damage = (op->atk - def);

	if(weak_factor > 1) {
	  damage *= 2;
	}

	if(is_critical) {
		damage *= 3;
	}

	hp -=  damage;	
	if(hp <= 0) {
		hp = 0;
	}
	
	//debug
	std::cout << "hit_percent: " << hit_percent  << std::endl;	
	std::cout << "cri_percent: " << cri_percent  << std::endl;	
	std::cout << "damage: " << damage << std::endl;	
}	

//util methods
void actor::print_status() {		
	std::cout << "STATUS::" << std::endl;
	std::cout << "LV: " << lv << std::endl;
	std::cout << "TYPE: " << type << std::endl;
	std::cout << "NAME: " << name << std::endl;
	std::cout << "MAXHP: " << max_hp << std::endl;
	std::cout << "HP: " << hp << std::endl;
	std::cout << "MAXMP: " << max_mp << std::endl;
	std::cout << "MP: " << mp << std::endl;
	std::cout << "ATK: " << atk << std::endl;
	std::cout << "DEF: " << def << std::endl;
	std::cout << "SPD: " << spd << std::endl;
	std::cout << "LUK: " << luk << std::endl;
	std::cout << "MOVE: " << move << std::endl << std::endl;
}


void actor::print_battle_status() {
	std::cout << "NAME: " << name << std::endl;		
	std::cout << "HP: " << hp << std::endl;		
	std::cout << "MP: " << mp << std::endl << std::endl;		
}

float rand_prob() {
	return (float) (rand() / RAND_MAX);		
}

/*
int main() {
	actor* player = new actor();
	actor* enemy = new actor();

	//lvup test
	for(int i = 0; i < 10; i++) {
		player->lvup();
	}	
	player->print_status();	
	
	//damage test
	player->on_damage(enemy);	
	player->print_battle_status();

	delete(player);
	return 0;		
}
*/
