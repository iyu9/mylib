#include "../scene/scene.cpp"
#include "../actor/actor.cpp"
#include "../map/map.cpp"

std::string step_name[] =
{
   "STEP_INIT",
   "STEP_CMD",
   "STEP_USE",
   "STEP_ENEMY",
   "STEP_FIN",
   "STEP_LOSE",
   "STEP_WIN"
};

class battle: public scene
{
private:
    int step;
    int pl_idx;
	int em_idx;
	int turn;

public:
    enum BattleStep
	{
       STEP_INIT,
       STEP_CMD,
	   STEP_USE,
       STEP_ENEMY,
       STEP_FIN,
	   STEP_LOSE,
	   STEP_WIN,
    };

	actor* player;
	actor* enemy;

	actor** players;
	actor** enemies;

	map* battle_map;

	battle();
	battle(actor* player, actor* enemy);
	battle(actor* player[], actor* enemy[]);
	~battle();

    void update();

    void input();
    void render();
	void draw_map();
    void proc();
};
