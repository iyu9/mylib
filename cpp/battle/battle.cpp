#include "battle.h"

const int PLAYER_COUNT = 1;
const int ENEMY_COUNT  = 1;

battle::battle(): scene::scene()
{
    this->step = STEP_INIT;

    this->player = new actor("tommy");
    this->enemy = new actor("slime");

	this->battle_map = new map();

	//this->players = new actor[6];
	//this->enemies = new actor[6];
}

battle::battle(actor* player, actor* enemy)
{
    this->step = STEP_INIT;

    this->player = player;
    this->enemy = enemy;
}

battle::battle(actor* players[], actor* enemies[])
{
    this->step = STEP_INIT;

    this->players = players;
    this->enemies = enemies;
}

battle::~battle()
{
    delete(player);
    delete(enemy);

    delete[] players;
    delete[] enemies;
}

void battle::input()
{
    std::string cmd;
    std::cin >> cmd;

	player->refresh();
	enemy->refresh();

    switch (cmd[0])
	{
      case 'a':

		if (battle_map->get_dist(player, enemy) > player->range)
		{
		  println("over fire range");
		  return;
		}

	    player->attack(enemy);
		if (enemy->is_dead())
		{
		  println("you defeated enemies");
		  step = STEP_WIN;
		  return;
		}
		if (++pl_idx >= PLAYER_COUNT)
		{
		  pl_idx = em_idx = 0;
		  step = STEP_ENEMY;
		}
        break;

      case 'g':
		println("you carefully defenced");
		println(player->def);
		player->guard();
		println(player->def);
		step = STEP_ENEMY;
        break;

      case 'e':
		if (!player->escape()) {
		  println("escape succeeded!");
		  set_exit();
		}
		else {
		  println("escape failed!");  
		  step = STEP_ENEMY;
		}
        break;

	  case 'm':
		print("Remain Move: ");
		println(player->mov);
		println("x = ");
		int x, y;
		std::cin >> x;
		println("y = ");
		std::cin >> y;

		if (x >= 0 && y >= 0 && x + y <= player->mov)
		{
		  println("you moved position");
		  player->move(x, y);  
		}
		else
		{
		  println("can't move");  
		}

		break;

	  case 'f':
		println("you check map");
		battle_map->print(player, enemy);
		break;

	  case 'i':
		println("your items list");
		//player->use_item();
		break;

	  case 's':
		clear();
		print("step = ");
		println(step_name[step]);
		println("");
		println("");
		println("Status::");
		player->print_battle_status();
		enemy->print_battle_status();
		step = STEP_CMD;
		break;

	  case 'q':
		println("BYE");
		set_exit();
		break;
    }
}

void battle::render()
{
    switch(step)
	{
      case STEP_INIT:
        println(enemy->name + "と出会った！");
        println("");
		step = STEP_CMD;
        println("Command >");
        println("(A)ttack, (G)uard, (E)scape, (F)igure");
        println("(M)ove, (S)tatus, (U)se");
        break;

      case STEP_CMD:
        println("Command>");
        println("(A)ttack, (G)uard, (E)scape, (F)igure");
        println("(M)ove, (S)tatus, (U)se");
		break;

	  case STEP_USE:
		println("use item");
		break;

      case STEP_ENEMY:
		println("enemy turn action");
		enemy->attack(player);
		if (player->is_dead())
		{
		  println("R.I.P. you died!");
		  set_exit();
		  step = STEP_LOSE;
		}
		if (++em_idx > ENEMY_COUNT)
		{
		  pl_idx = em_idx = 0;
		  turn++;

		  step = STEP_CMD;
		}
		break;

      case STEP_FIN:
        break;

	  case STEP_LOSE:
		break;

	  case STEP_WIN:
		println("YOU GET EXP:");
		println("100 exp.");
		println("YOU GET ITEM:");
		println("white chocorate.");
		set_exit();
		break;
    }        
}

void battle::update()
{
    render();

	if (step == STEP_CMD)
	{
	  input();
	}
}

/**/
int main()
{
	battle* b = new battle();

    while(!b->is_exit())
	{
      b->update();
    }

	delete(b);
    
	return 0;
}
/**/
