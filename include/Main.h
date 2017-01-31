#pragma once
#include <string>
#include <iostream>
#include <string>
#include <stdlib.h>
#include <fstream>
#include <json.h>

#include "Character.h"
#include "Game.h"
#include "MainWindow.h"


extern const std::string DISPLAY = "Graphical";

class Main {

	public:
		Main();
		void displayConsoleMenu();
		void displayGraphicalMenu();
		void runGame(Game* pGame);
};