#include "game.h"

const char exit_code = '4';

Game::Game()
{
	mode = 0;
	cmd = 0;
	s_manager = new scene_manager();
}

Game::~Game()
{
}

int Game::input_command()
{
	std::cin >> cmd;
}

int Game::decode_command() 
{
	switch(cmd)
	{
		case '0':
		case '1':
		case '2':
		case '3':
		case '4':
			mode = cmd;
			break;

		break;	
	}		
}

void Game::Input()
{
	input_command();
	decode_command();	
}

void Game::Render()
{
	switch(mode)
	{
		case '0':
		println("Title");
		break;

		case '1':
		println("Start");
		break;

		case '2':
		println("Load");
		break;

		case '3':
		println("Config");
		break;

		case '4':
		println("Bye");
		break;
	}	
}

void Game::MainLoop()
{
	println("Title Menu:");
	println("(1.Start, 2.Load, 3.Config, 4.Exit)");

	while(cmd != exit_code)
	{
	  /*
		Input();
		Render();	
	  */
	}	
}

/**/
int main()
{
	Game* game = new Game();
	game->MainLoop();
	delete(game);

	return 0;		
}
/**/
