/*
 * Game Character Defined Class
 * @written by tomii
 */

#include "../common/common.h"

const int LIST_SIZE = 10;
const int WEAK_NONE = 0;
const int WEAK_WEAK = 1;
const int WEAK_DEATH = 2;
const int WEAK_STRONG = 3;
const int WEAK_NODAMAGE = 4;
const int WEAK_REFLECT = 5;

class actor {
public:
	//idents
	int id;
  int index;
	std::string name;
	int type;
	int condition;

	//params
	int lv;
	int exp;
	int max_hp;
	int hp;
	int max_mp;
	int mp;

	int max_atk;	
	int atk;
	int max_def;
	int def;
	int max_spd;
	int spd;
	int max_luk;
	int luk;
	int max_tec;
	int tec;		

	int max_move;		
	int move;
	int max_hit;
	int hit;

  //weaknesses
  int weakness_list[LIST_SIZE];

	//lists
	int equip_list[LIST_SIZE];
	int item_list[LIST_SIZE];
	int skill_list[LIST_SIZE];

	//grows
	float per_hp;
	float per_mp;
	float per_atk;
	float per_def;
	float per_spd;
	float per_luk;

	//constructors
	actor();
	actor(std::string name_);
	actor(std::string name_, int type_);
	actor(int lv);
	~actor();

	//methods
	void lvup();
	void lvdn();
	void on_damage(actor* op);
  int check_weakness();

	//utils
	void print_status();
	void print_battle_status();
};
