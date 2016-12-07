#include "card.h"

card::card()
{
	this->id = 0;
	this->suit = CLUB;
	this->num = 0;
	this->suit_str = suit_name[CLUB];
}

card::card(int id)
{
	this->id = id;
	this->suit = id % 4;
	this->num = id / 4;
	this->suit_str = suit_name[this->suit];
}

card::card(int suit, int num)
{
	this->id = (4 * num) + suit;
	this->suit = suit;
	this->num = num;
	this->suit_str = suit_name[suit];
}

card::~card() {}

/**/
int main()
{
  card* c = new card(25);

  println(c->id);
  println(c->suit);
  println(c->suit_str);
  println(c->num);

  return 0;
}
/**/
