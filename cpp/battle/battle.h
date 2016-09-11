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

public:
    enum BattleStep
	{
       STEP_INIT,
       STEP_CMD,
       STEP_ACT,
       STEP_FIN
    };

	actor* player;
	actor* enemy;

	battle();
	battle(actor* player, actor* enemy);
	~battle();

    void update();

    void next_actor(int pl_idx);
	void next_step(int current_step);
	void back_step(int current_step);
    void input();
    void render(int current_step);
    void proc(int current_step);
};
