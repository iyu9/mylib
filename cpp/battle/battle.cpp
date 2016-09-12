#include "battle.h"

const int PLAYER_COUNT = 1;
const int ENEMY_COUNT  = 1;

battle::battle(): scene::scene()
{
    this->step = STEP_INIT;

    this->player = new actor("tommy");
    this->enemy = new actor("slime");

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
	    player->attack(enemy);
		if (enemy->is_dead())
		{
		  println("you defeated enemies");
		  step = STEP_WIN;
		  return;
		}
		pl_idx++;
		if (pl_idx >= PLAYER_COUNT)
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
		println("youmoved");
		player->move(1, 1);
		break;

	  case 'i':
		//player->use_item();
		break;

	  case 's':
		clear();
		println("Status::");
		player->print_battle_status();
		enemy->print_battle_status();
		step = STEP_CMD;
		break;
    }
}

void battle::render()
{
	print("current_step = ");
    println(step_name[step]);

    switch(step)
	{
      case STEP_INIT:
        println(enemy->name + "と出会った！");
        println("");
		step = STEP_CMD;
        player->print_battle_status();
        println("コマンド？");
        println("(A)ttack, (G)uard, (E)scape, (M)ove, (S)tatus, (U)se");
        break;

      case STEP_CMD:
        println("コマンド？");
        println("(A)ttack, (G)uard, (E)scape, (M)ove, (S)tatus, (U)se");
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
		em_idx++;
		if (em_idx > ENEMY_COUNT)
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

	if(step == STEP_CMD)
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
