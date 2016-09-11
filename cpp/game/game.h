#include "../common/common.h"
#include "../scene/scene.cpp"
#include "game_def.hpp"
#include "message_def.hpp"

class Game
{
private:
	scene* current_scene;

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
