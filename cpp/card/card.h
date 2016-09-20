#include "../common/common.h"

//SUIT
const int CLUB = 0;
const int DAIA = 1;
const int HEART = 2;
const int SPADE = 3;

//SUIT_NAME
std::string suit_name[] =
{
	"CLUB",
	"DAIA",
	"HEART",
	"SPADE"
};

class card
{
public:
  int id;
  int num;
  int suit;
  std::string suit_str;

  card();
  card(int id);
  card(int suit, int num);
  ~card();
};
