#include "../common/common.h"
//#include "../scene/scene.cpp"
#include "../scene/scene_manager.cpp"
#include "game_def.hpp"
#include "message_def.hpp"

class Game
{
private:
	//scene* current_scene;

    scene_manager* s_manager;

	int mode;
	char cmd;

	int input_command();
	int decode_command();
	void Render();
	void Input();

public:
	Game();
	~Game();

	void MainLoop();
};
