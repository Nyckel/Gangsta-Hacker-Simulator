#include "Main.h"

/*Prototypes*/
void createNewGame();


//const std::string DISPLAY = "Graphical";

//Here I load Software option from config file (display settings, ...)
int main() {
	Main gameManager;
	return EXIT_SUCCESS;
}

	
Main::Main(){
	//Need to create a Singleton for the renderWindow object
	if (DISPLAY == "Graphical") {
		MainWindow window;
		Game::setDisplay(&window);

		int menuChoice = window.showMainMenu();
		std::cout << "MenuChoice: " << menuChoice << std::endl;
		switch (menuChoice) {
			case 1:
				std::cout << "Starting new Game" << std::endl;
				//Game *myGame = Game::getInstance();
					system("pause");
				 //Game->startNew();
				break;

			}
		// - Game.loadFromFileSave()
		// - Game.startNew()
		// - Other options...
		
		Game *game = Game::getInstance();

	}
	else if (DISPLAY == "Console") {
		displayConsoleMenu();
		Game::getInstance()->run();

	}

	//Now I have my Game object game
	/*
	game.changeState(gameStates[introState]);	
	while(game.isRunning()){
		if(isTimeToUpdate()){
			game.handleEvents();
			game.update();
			if(hasTimeToDraw()){
				game.draw();
			}
		} else {
			waitUntilTime();
		}
	}*/

}



void createNewGame() {
	Game *newGame = Game::getInstance();// = Game::getGame();
}


void Main::displayGraphicalMenu() {
	MainWindow mainWindow;
}

void Main::displayConsoleMenu() {
	//system("color 0c");
	//system("color 4e");
	system("color d");

	std::cout << "Program initializing..." << std::endl;
	std::cout << "Menu initializing..." << std::endl << std::endl;

	bool wrongInput = true;

	while (wrongInput) {
		wrongInput = false;

		std::cout << " ________________________________________________________________________________________" << std::endl;
		std::cout << "|                                                                                        |" << std::endl;
		std::cout << "|                                                                                        |" << std::endl;
		std::cout << "|                                   GangstHacker Simulator                               |" << std::endl;
		std::cout << "|                                   ----------------------                               |" << std::endl;
		std::cout << "|                                                                                        |" << std::endl;
		std::cout << "|________________________________________________________________________________________|" << std::endl << std::endl;


		std::cout << "\t Menu" << std::endl << "\t ----" << std::endl << std::endl;
		std::cout << "\t1. New game" << std::endl << "\t2. Load game" << std::endl << "\t3. Options" << std::endl << "\t4. Quit" << std::endl;

		int menuChoice;
		std::cout << std::endl << "\tChoice: ";
		std::cin >> menuChoice;
		switch (menuChoice) {
		case 1:
			/*Launch a new game*/
			//-> Create a new character:
			createNewGame();
			break;
		case 2:
			/*Display saved games*/
			break;
		case 3:
			/*Display options screen*/
			break;
		case 4:
			/*Quit game*/
			std::cout << std::endl << "Exiting game..." << std::endl;
			exit(EXIT_SUCCESS);
			break;
		default:
			wrongInput = true;
			system("cls");
			break;

		}
	}
}

void Main::runGame(Game* pGame) {

}

