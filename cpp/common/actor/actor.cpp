#include "actor.h"

#define DEBUG 

float rand_prob();

enum UnitType
{
  TYPE_HERO   = 0,
  TYPE_KNIGHT,
  TYPE_DRAGON,
  TYPE_ARMOR,
  TYPE_WITCH
};

enum UnitCondition
{
  CON_FINE,
  CON_DEAD,
  CON_STONE
};

actor::actor()
{
  srand((unsigned)time(NULL));

  name = "no_name";
  lv  = 1;
  hp  = 10;
  max_hp = hp;
  mp  = 10;
  max_mp = mp;
  atk = 5;
  def = 5;
  spd = 5;
  tec = 5;
  luk = 5;
  mov = 5;
  range = 2;

  per_hp  = 0.80;
  per_mp  = 0.80;
  per_atk = 0.30;
  per_def = 0.30;
  per_spd = 0.30;
  per_tec = 0.30;
  per_luk = 0.30;
  max_range = range;
}

actor::actor(std::string name_)
{
  srand((unsigned)time(NULL));

  name = name_;
  type = TYPE_HERO;

  lv  = 1;
  hp  = 10;
  max_hp = hp;
  mp  = 10;
  max_mp = mp;
  atk = 10;
  def = 5;
  spd = 5;
  tec = 5;
  luk = 5;
  mov = 5;
  range = 2;

  per_hp  = 0.80;
  per_mp  = 0.80;
  per_atk = 0.30;
  per_def = 0.30;
  per_spd = 0.30;
  per_tec = 0.30;
  per_luk = 0.30;

  max_atk = atk;
  max_def = def;
  max_spd = spd;
  max_tec = tec;
  max_luk = luk;
  max_mov = mov;
  max_range = range;
}

actor::actor(int lv)
{
  srand((unsigned)time(NULL));

  name = "NO_NAME";	
  type = TYPE_HERO;

  lv = lv;
  hp  = 10;
  max_hp = hp; 
  mp  = 10;
  max_mp = mp;
  atk = 5;
  def = 5;
  spd = 5;
  tec = 5;
  luk = 5;
  mov = 5;
  range = 2;

  per_hp  = 0.80;
  per_mp  = 0.80;
  per_atk = 0.30;
  per_def = 0.30;
  per_spd = 0.30;
  per_tec = 0.30;

  max_atk = atk;
  max_def = def;
  max_spd = spd;
  max_tec = tec;
  max_luk = luk;
  max_mov = mov;
  max_range = range;
}

actor::actor(std::string name_, int type_)
{
  srand((unsigned)time(NULL));

  name = name_;
  type = type_;

  lv  = 1;
  hp  = 10;
  max_hp = hp;
  mp  = 10;
  max_mp = mp;
  atk = 5;
  def = 5;
  spd = 5;
  tec = 5;
  luk = 5;
  def = 5;
  mov = 5;
  range = 2;

  per_hp  = 0.80;
  per_mp  = 0.80;
  per_atk = 0.30;
  per_def = 0.30;
  per_spd = 0.30;
  per_tec = 0.30;

  max_atk = atk;
  max_def = def;
  max_spd = spd;
  max_tec = tec;
  max_luk = luk;
  max_mov = mov;
  max_range = range;
}

actor::~actor(){}

int upper_lim(int val, int lim, int upper_val)
{
  if (val > lim) {
	return upper_val;
  }
  return val;
}

int lower_lim(int val, int lim, int lower_val)
{
  if (val < lim) {
	return lower_val;
  }
  return val;
}

void actor::lvup()
{
  if (lv >= 99)
  {
	std::cout << "already 99..." << std::endl;
	return;
  }

  lv++;
  std::cout << "LVUP: " << lv-1 << " -> " << lv << std::endl;

  float percent = (float) rand() / RAND_MAX;
  if (percent <= per_atk)
  {
	atk++;	
	std::cout << "ATK UP: " << atk << std::endl;
  }


  percent = (float) rand() / RAND_MAX;
  if(percent <= per_def)
  {
	def++;	
	std::cout << "DEF UP: " << def << std::endl;
  }


  percent = (float) rand() / RAND_MAX;
  if (percent <= per_spd)
  {
	spd++;	
	std::cout << "SPD UP: " << spd << std::endl;
  }

  percent = (float) rand() / RAND_MAX;
  if (percent <= per_tec)
  {
	tec++;	
	std::cout << "TEC UP: " << tec << std::endl;
  }

  percent = (float) rand() / RAND_MAX;
  if (percent <= per_luk)
  {
	luk++;	
	std::cout << "LUK UP: " << luk << std::endl;
  }


  percent = (float) rand() / RAND_MAX;
  if (percent <= per_mp)
  {
	mp++;	
	std::cout << "MP UP: " << mp << std::endl;
  }

  percent = (float) rand() / (float )RAND_MAX;
  if (percent <= per_hp)
  {
	hp++;	
	std::cout << "HP UP: " << hp << std::endl;
  }

  std::cout << std::endl;
}

int actor::check_weakness()
{
  int count = 1;

  REP(i, LIST_SIZE)
  {
	if (weakness_list[i] == WEAK_WEAK)
	{
	  count++;
	}
  }
  return count;
}

void actor::on_damage(actor* atacker)
{
  float rand = rand_prob();
  int is_critical = 0;

  //hit phase
  float hit_percent = 100;
  float hit_factor = 2 * atacker->tec + atacker->luk - 2 * spd;
  hit_percent += hit_factor;
  if (rand > hit_percent)
  {
	std::cout << "miss" << std::endl;
	return;	
  }

  //critical phase
  float cri_percent = lower_lim(atacker->tec - 2 * luk, 0, 0);
  rand = rand_prob();
  if (rand < cri_percent)
  {
	is_critical = 1;
	std::cout << "critical" << std::endl;
  }

  //weakness phase
  int weak_factor = check_weakness();
  if (weak_factor > 1)
  {
	std::cout << "weak" << std::endl;
  }

  //damage phase
  float damage = lower_lim(atacker->atk - def, 0, 0);

  if (weak_factor > 1)
  {
	damage *= 2;
  }

  if (is_critical)
  {
	damage *= 3;
  }

  hp -= damage;	
  if (is_dead())
  {
	hp = 0;
  }

  std::cout << "hit_percent: " << hit_percent  << std::endl;	
  std::cout << "cri_percent: " << cri_percent  << std::endl;	
  std::cout << "damage: " << damage << std::endl;	
}	

//Actions
void actor::attack(actor* target)
{
  target->on_damage(this);		
}

void actor::fixed_damage(actor* target, int damage)
{
  target->hp -= damage;
  if (target->is_dead())
  {
	target->hp = 0;	
  }

  std::cout << "fixed_damage: " << damage << std::endl;	
}	

void actor::guard()
{
  def *= 2;		
}

void actor::refresh()
{
  atk = max_atk;
  def = max_def;
  spd = max_spd;
  luk = max_luk;
}

bool actor::escape()
{
  float r = rand_prob();

  if (r > 0.5)
  {
	return true;
  }
  return false;
}

bool actor::is_dead()
{
  if (hp <= 0)
  {
	return true;
  }
  return false;
}

void actor::use_skill(skill* sk)
{
  switch(sk->type)
  {
	case SK_ATTACK:
	case SK_HEAL:
	  break;
  }		
}

void actor::set_item(item* it)
{
  //item_list[0] = it->id; 
}

void actor::use_item(item* it)
{
  switch(it->type)
  {
	case IT_HEAL:
	case IT_ATTACK:
	  break;
  }		
}

void actor::get_exp(int exp)
{
  this->exp += exp;
}

void actor::action_move(vector2 vec)
{
  //pos.x += vec.x;
  //pos.y += vec.y;
}

void actor::move(int x_, int y_)
{
  pos.x += x_;
  pos.y += y_;
}

void actor::jump()
{
  
}

void actor::shot()
{
  
}

int actor::draw_card()
{
  int card = deck[deck_idx];
  deck_idx++;
  return deck[deck_idx];
}

void actor::print_status()
{		
  std::cout << "STATUS::" << std::endl;
  std::cout << "LV: "     << lv     << std::endl;
  std::cout << "TYPE: "   << type   << std::endl;
  std::cout << "NAME: "   << name   << std::endl;
  std::cout << "MAXHP: "  << max_hp << std::endl;
  std::cout << "HP: "     << hp     << std::endl;
  std::cout << "MAXMP: "  << max_mp << std::endl;
  std::cout << "MP: "     << mp     << std::endl;
  std::cout << "ATK: "    << atk    << std::endl;
  std::cout << "DEF: "    << def    << std::endl;
  std::cout << "SPD: "    << spd    << std::endl;
  std::cout << "TEC: "    << tec    << std::endl;
  std::cout << "LUK: "    << luk    << std::endl;
  std::cout << "MOV: "    << mov    << std::endl;
  std::cout << "POS: "    << "(" << pos.x << ", " << pos.y << ")"
	<< std::endl << std::endl << std::endl;
}

void actor::print_battle_status()
{
  std::cout << "NAME: " << name << std::endl;		
  std::cout << "HP: " << hp << std::endl;		
  std::cout << "MP: " << mp << std::endl;
  if (is_dead())
  {
	std::cout << "DEAD" << std::endl;
  }
  std::cout << std::endl;
}

float rand_prob()
{
  return (float) (rand() / RAND_MAX);		
}

#ifdef DEBUG 
int main()
{
  actor* player = new actor("tom");
  actor* enemy = new actor("mot");

  //lvup test
  REP (i, 10)
  {
	player->lvup();
  }	
  player->print_status();	

  //damage test
  //player->attack(enemy);
  player->fixed_damage(enemy, 20);
  enemy->print_battle_status();
  player->print_battle_status();

  delete(player);
  delete(enemy);

  return 0;		
}
#endif
