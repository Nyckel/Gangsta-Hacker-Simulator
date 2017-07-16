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

	void init() override;
	void cleanUp() override;

	void pause() override;
	void resume() override;

	void handleEvents() override;
	GameState* update(std::chrono::microseconds elapsed) override;
	void draw() override;
};