/*
 * Game Character Defined Class
 * @written by tomii
 */

#include "../common/common.h"

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

	//lists
	int equip_list;
	int item_list;
	int skill_list;

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

	//utils
	void print_status();
	void print_battle_status();
};
