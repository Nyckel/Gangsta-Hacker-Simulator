#pragma once
#include "GameState.h"
#include "MainWindow.h"
#include "Label.h"
#include "Menu.h"

class MainMenuState : public GameState {

private:
	Menu* menu;
	Label* title;
	std::string menuChoice;
	void validateEntry();
public:
	MainMenuState(MainWindow* pWindow);
	~MainMenuState();

	void init();
	void cleanUp();

	void pause();
	void resume();

	void handleEvents();
	GameState* update(std::chrono::microseconds elapsed);
	void draw();
};