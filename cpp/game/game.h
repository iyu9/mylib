#include "../common/common.h"

//very abstract game-class
class Game {

private:
	//members
	int mode;
	char command;

	//functions
	int input_command();
	int decode_command();
	void Render();
	void Input();

public:
	Game();
	~Game();
	void MainLoop();
};
