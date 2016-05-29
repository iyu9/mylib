#include "game.h"

const char exit_code = '4';

//util
void newln() {
		std::cout << std::endl;		
}

void println(const char* str) {
		std::cout << str << std::endl;
}

//constructors
Game::Game() {
	mode = 0;
	command = 0;	
}

Game::~Game() {
	//delete members!		
}

//functions
int Game::input_command() {
	std::cin >> command;
}

int Game::decode_command() {
	switch(command) {
		case '0':
		case '1':
		case '2':
		case '3':
		case '4':
			mode = command;
			break;

		break;	
	}		
}

void Game::Input() {
	input_command();
	decode_command();	
}

void Game::Render() {
	switch(mode) {
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

void Game::MainLoop() {
	println("Terra Anigma\n");
	println("Title Menu:");
	println("(1.Start, 2.Load, 3.Config, 4.Exit)");

	while(command != exit_code) {
		Input();
		Render();	
	}	
}

/*unit-test*/
int main(){
	Game* game = new Game();
	game->MainLoop();
	delete(game);
	return 0;		
}
/**/
