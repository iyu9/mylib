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
		//enemy->print_status();
        break;
      case 'g':
		println("you guarded");
		println(player->def);
		player->guard();
		println(player->def);
        break;
      case 'e':
		if (!player->escape()) {
		  println("escape succeeded!");
		  set_exit();
		}
		else {
		  println("escape failed!");  
		}
        break;
    }
}

void battle::render()
{
    //clear();
    println(step_name[step]);

    switch(step)
	{
      case STEP_INIT:
        println(enemy->name + "と出会った！");
        println("");
		step++;
        //player->print_battle_status();
		//enemy->print_status();
        println("コマンド？");
        println("(A)ttack, (G)uard, (E)scape");
        break;

      case STEP_CMD:
        println("コマンド？");
        println("(A)ttack, (G)uard, (E)scape");
      case STEP_ACT:
      case STEP_FIN:
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
        break;
   }     
}

void battle::update()
{
    render();
    input();
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
