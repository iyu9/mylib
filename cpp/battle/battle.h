#include "../scene/scene.cpp"
#include "../actor/actor.cpp"
#include "../map/map.cpp"

std::string step_name[4] = {
   "STEP_INIT",
   "STEP_CMD",
   "STEP_ACT",
   "STEP_FIN"
};

class battle: public scene {

private:
    int step;
    int pl_idx;
	int em_idx;
public:
    enum BattleStep
	{
       STEP_INIT,
       STEP_CMD,
	   STEP_USE,
       STEP_ACT,
       STEP_FIN,
	   STEP_LOSE,
	   STEP_WIN,
    };

	actor* player;
	actor* enemy;

	battle();
	battle(actor* player, actor* enemy);
	~battle();

    void update();

    void input();
    void render();
    void proc();
};
