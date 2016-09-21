#include "../common/common.h"

enum SUIT
{
  CLUB = 0,
  DAIA = 1,
  HEART = 2,
  SPADE = 3, 
};

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
