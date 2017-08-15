#include "Game.h"

Game* Game::instance = nullptr;
MainWindow* Game::display = nullptr;

Game::Game() {
	running = true;
}

Game::Game(std::string saveFilename) {
	//Load from file
	/*Load:
		characters
		missions
		techtree & advancement 
	Start game running loop
	*/

}

Game::~Game()
{
	delete(instance);
	delete(display);
}


Game* Game::getInstance() {
	if(instance == nullptr){
		instance = new Game();
	}
	return instance;
}

void Game::setDisplay(MainWindow* pWindow) {
	display = pWindow;
}

bool Game::isRunning() {
	return running;
}

void Game::draw() {
	display->update();
}

void Game::update(std::chrono::microseconds elapsed) {
	// Things happening here (delegate to state)
	std::unique_ptr<GameState> newState = currentState->update(elapsed);
	if (newState != nullptr) {
		changeState(move(newState));//Manage deletion of old state somewhere, and see how I do with those to keep in memory
	}
}

void Game::handleEvents() {
	//Will be delegated to state
	currentState->handleEvents();
}

void Game::changeState(std::unique_ptr<GameState> newState) {
	currentState = std::move(newState);
}