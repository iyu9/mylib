/*
 * Game Character Defined Class
 * @written by tomii
 */

#include "../common/common.h"
#include "../item/item.h"
#include "../skill/skill.h"
#include "../magic/magic.h"
#include "../vector/vector2.cpp"

const int LIST_SIZE = 10;
const int WEAK_NONE = 0;
const int WEAK_WEAK = 1;
const int WEAK_DEATH = 2;
const int WEAK_STRONG = 3;
const int WEAK_NODAMAGE = 4;
const int WEAK_REFLECT = 5;

class actor
{
public:
	//base
	int id;
	int index;
	std::string name;
	int type;
	int condition;
	vector2 pos;

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

	int max_mov;		
	int mov;
	int max_hit;
	int hit;
	int max_range;
	int range;
	
	//liste
	int weakness_list[LIST_SIZE];
	int equip_list[LIST_SIZE];
	int item_list[LIST_SIZE];
	int skill_list[LIST_SIZE];
	int magic_list[LIST_SIZE];

	//grows
	float per_hp;
	float per_mp;
	float per_atk;
	float per_def;
	float per_spd;
	float per_tec;
	float per_luk;

	actor();
	actor(std::string name_);
	actor(std::string name_, int type_);
	actor(int lv);
	~actor();

	void action_move(vector2 vec);
	void move(int x_, int y_);
	void lvup();
	//void lvdn();
	void attack(actor* target);
	void guard();
	void refresh();
	bool escape();
	bool is_dead();

	void set_item(item* item);
	void use_item(item* item);
	void use_skill(skill* skill);
	void use_magic(magic* magic);
	void on_damage(actor* attacker);
	int check_weakness();
	void get_exp(int exp);

	void print_status();
	void print_battle_status();
};