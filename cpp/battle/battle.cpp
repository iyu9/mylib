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

void battle::next_step(int current)
{
    switch(current)
	{
       case STEP_INIT:
        step = STEP_CMD;
        break;

       case STEP_CMD:
        step = STEP_ACT;
        break;

       case STEP_ACT:
        step = STEP_FIN;
        break;

       case STEP_FIN:
        break;
    }
}

void battle::ret_step(int current)
{
    switch(current)
	{
       case STEP_INIT:
	     break;
       case STEP_CMD:
		 break;
       case STEP_ACT:
	     break;
       case STEP_FIN:
	     break;
    }
}

void battle::input()
{
    std::string cmd;
    std::cin >> cmd;

    switch(cmd[0])
	{
      case 'a':
        break;
      case 'g':
        break;
      case 'e':
        break;
    }
}

void battle::render(int current)
{
	clear();
    println(step_name[step]);

    switch(current)
	{
      case STEP_INIT:
        println(enemy->name + "と出会った！");
        println("");
        player->print_battle_status();
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

void battle::proc(int current)
{
   switch(current)
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
    render(step);
    input();

    proc(step);
    next_step(step);
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
