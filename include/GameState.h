#pragma once
#include "SFML\Graphics.hpp"
#include "Game.h"

class GameState
{
protected:
	GameState() {};

public:

	virtual void init() = 0;
	virtual void cleanUp() = 0;

	virtual void pause() = 0;
	virtual void resume() = 0;

	virtual void handleEvents(sf::RenderWindow* pWindow) = 0;
	virtual void update(Game pGame) = 0;
	virtual void draw(Game pGame) = 0;

	void changeState(Game *pGame, GameState *state) {
		/*pGame->changeState(state);*/
	}
};

