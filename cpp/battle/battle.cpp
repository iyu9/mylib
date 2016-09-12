#include "battle.h"

battle::battle(): scene::scene()
{
    this->step = STEP_INIT;

    this->player = new actor("tommy");
    this->enemy = new actor("slime");
}

battle::battle(actor* player, actor* enemy)
{
    this->step = STEP_INIT;

    this->player = player;
    this->enemy = enemy;
}

battle::~battle()
{
    delete(player);
    delete(enemy);
}

void battle::input()
{
    std::string cmd;
    std::cin >> cmd;

	//clear();
	player->refresh();
	enemy->refresh();

    switch(cmd[0])
	{
      case 'a':
	    player->attack(enemy);
		if (enemy->is_dead())
		{
		  println("you defeated enemies");
		  step = STEP_WIN; 
		}
		step = STEP_ACT;
        break;

      case 'g':
		println("you carefully defenced");
		println(player->def);
		player->guard();
		println(player->def);
		step = STEP_ACT;
        break;

      case 'e':
		if (!player->escape()) {
		  println("escape succeeded!");
		  set_exit();
		}
		else {
		  println("escape failed!");  
		  step = STEP_ACT;
		}
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
        //player->print_battle_status();
		//enemy->print_status();
        println("コマンド？");
        println("(A)ttack, (G)uard, (E)scape, (S)tatus, (U)se");
        break;

      case STEP_CMD:
        println("コマンド？");
        println("(A)ttack, (G)uard, (E)scape, (S)tatus, (U)se");
		break;

	  case STEP_USE:
		println("use item");
		break;

      case STEP_ACT:
		println("enemy turn action");
		enemy->attack(player);
		if (player->is_dead())
		{
		  println("RIP: you died!");
		  set_exit();
		  step = STEP_LOSE;
		}

      case STEP_FIN:
        break;
	  case STEP_LOSE:
		break;
	  case STEP_WIN:
		println("YOU GET EXP:");
		println("YOU GET ITEM:");
		break;
    }        
}

void battle::proc()
{
   switch(step)
   {
      case STEP_INIT:
      case STEP_CMD:
      case STEP_ACT:
      case STEP_FIN:
	  case STEP_LOSE:
		break;
	  case STEP_WIN:
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
    //proc();
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
