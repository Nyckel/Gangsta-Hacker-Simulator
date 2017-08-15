#include "Main.h"

/*Prototypes*/


//const std::string DISPLAY = "Graphical";

//Here I load Software option from config file (display settings, ...)
int main() {
	Main gameManager;
	return EXIT_SUCCESS;
}

	
Main::Main(){

	MainWindow window;
	game = Game::getInstance();
	Game::setDisplay(&window);
	game->changeState(std::make_unique<MainMenuState>(&window));
	
	maxFps = 60;
	computeDeltaTime();
	start = std::chrono::steady_clock::now();
	end = std::chrono::steady_clock::now();
	//Why not as an object attribute
	//Or multipliate the timer for every action (code, research,...) by a speed coef -> but wouldn't speed up animations 
	elapsed = std::chrono::duration_cast<std::chrono::microseconds>(end - start);

	while(game->isRunning()){
		if(isTimeToUpdate()){
			game->handleEvents();
			game->update(elapsed);
			if(hasTimeToDraw()){
				game->draw();
			}
		} else {
			waitUntilTime();
		}
	}
}

bool Main::isTimeToUpdate() {
	end = std::chrono::steady_clock::now();
	elapsed = std::chrono::duration_cast<std::chrono::microseconds>(end - start);
	if (elapsed.count() >= deltaTime) {
		start = std::chrono::steady_clock::now();
		return true;
	}
	return false;
}

//TODO: write actual function
bool Main::hasTimeToDraw() {
	return true;
}

void Main::waitUntilTime() {
	//TODO: write function
	std::this_thread::sleep_for(std::chrono::microseconds((deltaTime-elapsed.count())-3000));
}

void Main::computeDeltaTime() {
	deltaTime = 1000000 / maxFps;
}