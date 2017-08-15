#pragma once
#include "SFML\Graphics.hpp"
#include "MainWindow.h"
#include "World.h"
#include <chrono>

/*
	Main states:
		- Main menu state
			-> If new game : CreateCompanyAndCharacterState
		- Playing state
		- Menu state
		- End game state (-> Main menu state ?)
*/

class GameState
{
protected:
	GameState() {};
	MainWindow* window;
	std::unique_ptr<World> world;

public:

	virtual void init() = 0;
	virtual void cleanUp() = 0;

	virtual void pause() = 0;
	virtual void resume() = 0;

	virtual void handleEvents() = 0;
	virtual std::unique_ptr<GameState> update(std::chrono::microseconds elapsed) = 0;
	virtual void draw() = 0;

	void changeState(GameState *state) {
		/*pGame->changeState(state);*/
	}
};

