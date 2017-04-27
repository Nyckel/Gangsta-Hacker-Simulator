#pragma once
#include <string>
#include <vector>
#include <chrono>
#include <thread>

#include "Character.h"
#include "Company.h"
#include "Mission.h"
#include "MainWindow.h"
#include "TechTreeElement.h"
#include "GameState.h"
#include "MainMenuState.h"

class Game
{

private:

	static MainWindow *display;
	static Game *instance;
	GameState* currentState = nullptr;

	std::string saveFilename; //Changed when saved in a new file
	std::vector<Company>playerCompanies; //Can put a character in another company (time to change...)
	std::vector<Company> companies; //Every other company (bot, targets, other players...)
	std::vector<Mission*> missions;

	int global_level;
	int global_balance;

	
	bool running;
	bool quit;
	int maxFps;
	int deltaTime;
	//Techtree object;
	//Characters characters;



public:
	~Game();

	Company createCompany();
	//void run(Company* pMainCompany);
	void startNew();
	void run();
	//Start scenario ?
	//void pause();
	//void resume;

	void computeDeltaTime();
	//void updateActivities(long long elapsed);
	void updateActivities(std::chrono::microseconds elapsed);

	Mission* getCurrentMissionOf(Character *pChar);
	void setCurrentMissionOf(Character *pChar, Mission *pMission);
	void displayMissionsOfCharacter(Character *pChar);

	int getNbOfMissionsFor(Character *pChar);
	int getNbOfMissionsFor(Company *pCompany);
	void handleEvents();
	void update(std::chrono::microseconds elapsed);
	void draw();
	void changeState(GameState* newState);
	bool isRunning();


	static void setDisplay(MainWindow* pWindow);
	static Game* getInstance();


private:
	Game();
	Game(std::string saveFilename);
};

