#pragma once
#include <string>
#include <iostream>
#include <string>
#include <stdlib.h>
#include <fstream>
#include <json/json.h>

#include "Character.h"
#include "Game.h"
#include "MainWindow.h"
#include "MainMenuState.h"


extern const std::string DISPLAY = "Graphical";//Console

class Main {
	private:
		int deltaTime;
		int maxFps;
		Game *game;
		std::chrono::time_point<std::chrono::steady_clock> start;
		std::chrono::time_point<std::chrono::steady_clock> end;
		std::chrono::microseconds elapsed;

	public:
		Main();
		void displayConsoleMenu();
		void displayGraphicalMenu();
		void runGame(Game* pGame);
		bool isTimeToUpdate();
		bool hasTimeToDraw();
		void waitUntilTime();
		void computeDeltaTime();
};