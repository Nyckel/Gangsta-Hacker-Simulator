#pragma once

#include <Windows.h>
#include <memory>
#include "GameState.h"
#include "Company.h"
#include "Mission.h"

class PlayingState : public GameState
{

private:
	std::unique_ptr<World> world;
	std::string saveFilename; //Changed when saved in a new file
	std::vector<Company*>playerCompanies; //Can put a character in another company (time to change...)
	std::vector<Company*> companies; //Every other company (bot, targets, other players...)
	std::vector<Mission*> missions;
	
	Company* createCompany();
	void setCurrentMissionOf(Character *pChar, Mission *pMission);
	Mission* getCurrentMissionOf(const Character* pChar);
	void updateActivities(std::chrono::microseconds elapsed);

	//Tests
	void testMissions();

	int global_level;
	int global_balance;


	bool running;
	bool quit;
	int maxFps;
	int deltaTime;
	//Techtree object;
	//Characters characters;

public:
	PlayingState();
	~PlayingState();

	void init() override;
	void cleanUp() override;

	void pause() override;
	void resume() override;

	void handleEvents() override;
	std::unique_ptr<GameState> update(std::chrono::microseconds elapsed) override;
	void displayMissionsOfCharacter(Character *pChar);
	int getNbOfMissionsFor(Character *pChar);
	void draw() override;
};

