#include "map.h"

map::map() {
	pos_x = pos_y = 1;

	for(int i = 0; i < MAP_SIZE; i++) {
		for(int j = 0; j < MAP_SIZE; j++) {
			coord[i][j] = MAP_TYPE_WALL;
		}
	}
}

map::~map() {
}

void map::create(int type) {
	for(int i = 0; i < MAP_SIZE; i++) {
		for(int j = 0; j < MAP_SIZE; j++) {
			if(i == 0 || i == MAP_SIZE-1 || j == 0 || j == MAP_SIZE-1) {
				coord[i][j] = MAP_TYPE_WALL;
			} else {
				coord[i][j] = 0;		
			}
		}
	}
}

char map::sign(int val) {

	switch(val) {
		case MAP_TYPE_NONE:
			return ' ';
		case MAP_TYPE_WALL:
			return '#';
		case MAP_TYPE_PLAYER:
			return '@';
		case MAP_TYPE_BRIDGE:
			return '|';
		case MAP_TYPE_BUILD:
			return 'N';
		case MAP_TYPE_FOREST:
			return 'F';
		case MAP_TYPE_ENEMY:
			return 'E';
		default:
			return ' ';
	}
}

void map::print() {		
	for(int i = 0; i < MAP_SIZE; i++) {
		for(int j = 0; j < MAP_SIZE; j++) {
			if (i == pos_x && j == pos_y) {
				std::cout << sign(MAP_TYPE_PLAYER) << ' ';
			} else {
				std::cout << sign(coord[i][j]) << ' ';
			}
		}
		std::cout << std::endl;
	}
}

void map::print(actor* player, actor* enemy) {		
	for(int i = 0; i < MAP_SIZE; i++)
	{
		for(int j = 0; j < MAP_SIZE; j++)
		{
			if (i == player->pos.x && j == player->pos.y)
			{
				std::cout << sign(MAP_TYPE_PLAYER) << ' ';
			}
			else if (i == enemy->pos.x && j == enemy->pos.y)
			{
				std::cout << sign(MAP_TYPE_ENEMY) << ' ';
			}
			else
			{
				std::cout << sign(coord[i][j]) << ' ';
			}
		}
		std::cout << std::endl;
	}
}

void map::print(actor** players, actor** enemies) {		
	for(int i = 0; i < MAP_SIZE; i++) {
		for(int j = 0; j < MAP_SIZE; j++) {
			if (i == pos_x && j == pos_y) {
				std::cout << sign(MAP_TYPE_PLAYER) << ' ';
			} else {
				std::cout << sign(coord[i][j]) << ' ';
			}
		}
		std::cout << std::endl;
	}
}

void map::move_pl(int dir, int move) { 
	int prev_pos_x = pos_x;
	int prev_pos_y = pos_y;

	switch(dir) { 
		case DIR_NORTH:
			pos_y += move;
			if (coord[pos_x][pos_y] == MAP_TYPE_WALL) {
				pos_x = prev_pos_x;
				pos_y = prev_pos_y; 
			}
			if (pos_y >= MAP_SIZE) {
				pos_y = MAP_SIZE-1;
			}
			break;

		case DIR_EAST:
			pos_x += move;
			if (coord[pos_x][pos_y] == MAP_TYPE_WALL) {
				pos_x = prev_pos_x;
				pos_y = prev_pos_y; 
			}
			if (pos_x >= MAP_SIZE) {
				pos_x = MAP_SIZE-1;
			}
			break;

		case DIR_SOUTH:
			pos_y -= move;
			if (coord[pos_x][pos_y] == MAP_TYPE_WALL) {
				pos_x = prev_pos_x;
				pos_y = prev_pos_y; 
			}
			if (pos_y < 0) {
				pos_y = 0;
			}
			break;

		case DIR_WEST:
			pos_x -= move;
			if (coord[pos_x][pos_y] == MAP_TYPE_WALL) {
				pos_x = prev_pos_x;
				pos_y = prev_pos_y; 
			}
			if (pos_x < 0) {
				pos_x = 0; 
			}
			break;	 
	}		
}

int map::get_dist(actor* a, actor* b)
{
  int x_dist = (a->pos.x - b->pos.x);
  int y_dist = (a->pos.y - b->pos.y);
  x_dist = (x_dist < 0) ? -x_dist : x_dist;
  y_dist = (y_dist < 0) ? -y_dist : y_dist;

  return (x_dist + y_dist); 
}

/*
int main() {
	map* m = new map();
	m->create(0);
	m->print(); 
	return 0;		
}
*/
