#include "../common/common.h"

const int DIR_NORTH = 0;
const int DIR_EAST  = 1;
const int DIR_SOUTH = 2;
const int DIR_WEST  = 3;

const int MAP_TYPE_NONE   = 0;
const int MAP_TYPE_WALL   = 1;
const int MAP_TYPE_FOREST = 2;
const int MAP_TYPE_ROAD   = 2;
const int MAP_TYPE_BUILD  = 3;
const int MAP_TYPE_RIVER  = 4;
const int MAP_TYPE_SEA    = 5;
const int MAP_TYPE_BRIDGE = 6;
const int MAP_TYPE_PLAYER = 10;

const int MAP_SIZE = 10;

class map {
public:
	int coord[MAP_SIZE][MAP_SIZE];
	int pos_x;
	int pos_y;

	map();
	~map();

	void create(int type);
	char sign(int val);
	void print();

	void move_pl(int dir, int num);
};
