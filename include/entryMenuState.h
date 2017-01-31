#pragma once
#include "GameState.h"

class entryMenuState : public GameState
{
public:
	entryMenuState();
	~entryMenuState();

	void init();
	void cleanUp();

	void pause();
	void resume();

	void handleEvents(sf::RenderWindow* pWindow);
	void update(Game pGame);
	void draw(Game pGame);

};