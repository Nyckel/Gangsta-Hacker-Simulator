#include "Game.h"

Game* Game::instance = nullptr;
MainWindow* Game::display = nullptr;

Game::Game() //Replace by a singleton
{
	//When in graphical get the renderWindow singleton
	//Create a new Game

	/*Company newCompany;*/
	//system("cls");
	//std::cout << std::endl << "\tCreating new game..." << std::endl;
	//playerCompanies.push_back(createCompany());
	//std::cout << "\tCompany created" << std::endl;
	//playerCompanies.at(0).createTechTree();
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

/*bool Game::isInstantiated() { return isInstantiated; }
Game Game::getGame() {
	if (!instantiated) {
		instance = Game();
	}
	return instance;
}*/

Game::~Game()
{
	delete(instance);
	delete(display);
}

Company Game::createCompany() {
	std::string companyName;
	std::cout << "\tWell, we are going to create your Company, what name did you think to ? ";
	std::cin >> companyName;
	Company newCompany(companyName);
	
	return newCompany;
}

void Game::startNew() {
	system("cls");
	std::cout << std::endl << "\tCreating new game..." << std::endl;
	playerCompanies.push_back(createCompany());
	std::cout << "\tCompany created" << std::endl;
	playerCompanies.at(0).createTechTree();
}

void Game::run() {
	running = true;
	quit = false;

	system("cls");
		
		maxFps = 60; //Apply the option read in option file here
		computeDeltaTime();
		auto start = std::chrono::steady_clock::now();
		auto end = std::chrono::steady_clock::now();
		auto elapsed = std::chrono::duration_cast<std::chrono::microseconds>(end - start); //Why not as an object attribute
		//Or multipliate the timer for every action (code, research,...) by a speed coef -> but wouldn't speed up animations ?

		
#pragma region testsMissions
		Character badGuysDirector("Brandon", Male, false);
		Character goodGuysDirector("Michelle", Female,false);
		Company *goodGuys = new Company("ThegoodGuys",1,0);
		goodGuys->addCharacter(&goodGuysDirector);
		
		Mission attack("Hack bob", "Hi, we need to break these guys, we'll pay you a lot if you hack X company", std::make_shared<Company>(*goodGuys), 0, 0, 0, 100);
		attack.setApplicant(&badGuysDirector);
		Mission defend("Protect bob", "X company has reasons to believe that someone is trying to hack them, they ask for help", std::make_shared<Company>(*goodGuys), 1, 100, 0, 0);
		defend.setApplicant(&goodGuysDirector);
		
		Company *mainCompany = &(playerCompanies.at(0));
		if(mainCompany->getNbCharacters() !=0)
			if (mainCompany->getCharacter(0) != NULL) {
				
				attack.assignToCompany(mainCompany);
				defend.assignToCompany(mainCompany);
				attack.assignToCharacter(mainCompany->getCharacter(0));
				defend.assignToCharacter(mainCompany->getCharacter(0));
				missions.push_back(&attack);
				missions.push_back(&defend);
				setCurrentMissionOf(mainCompany->getCharacter(0), &attack);
				//displayMissionsOfCharacter(mainCompany->getCharacter(0));
				//system("pause");
			}
			else {
				std::cout << "Mission could not be affected to character";
				system("pause");
				exit(1);
			}
		else {
			std::cout << "There are " << mainCompany->getNbCharacters() << "characters in the comany" <<std::endl;
		}
#pragma endregion
		

#pragma region testsActivities
		Activity actTest;
		mainCompany->getCharacter(0)->addPossibleActivity(&actTest);
		mainCompany->getCharacter(0)->setCurrentActivity(0);
		//std::cout << "Current activity in .. is : " << mainCompany->getCharacter(0)->getCurrentActivityIndex() << std::endl;
		//system("pause");
#pragma endregion

		while (!quit) {

			end = std::chrono::steady_clock::now();
		    elapsed = std::chrono::duration_cast<std::chrono::microseconds>(end - start);
			
			//std::cout << "Dt: " << deltaTime << ", elapsed: " << elapsed.count() << ", left: " << std::chrono::milliseconds(elapsed.count() - deltaTime).count() << std::endl;
			
			if (elapsed.count() >= deltaTime) {
				start = std::chrono::steady_clock::now();
				//Check mouse & keyboard events	
				system("cls"); // Buggy and shitty fps with it
				std::cout << "FPS: " << 1000000/ elapsed.count()<< std::endl;
				mainCompany->getCharacter(0)->displayStatistics();
				//Update informations:
				
				updateActivities(elapsed);

				//	-> See if new missions
				//		(for each character)
				//Update display
			}else {
				//std::this_thread::sleep_for(std::chrono::microseconds((deltaTime-elapsed.count())-3000));
			}
			//Maybe put display update here to allow higher framerate wither making the game run faster
		}
	system("pause");
	
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

void Game::computeDeltaTime() {
	deltaTime = 1000000 / maxFps;
}


void Game::updateActivities(std::chrono::microseconds elapsed) {
	for (int i = 0; i < playerCompanies.size(); i++) {
		Company* currentCompany = &playerCompanies.at(i);
		
		currentCompany->updateActivities(elapsed);

		//Faire un calcul avec elapsed pour trouver le temps écoulé dans le jeu (coef de vitesse)

	}
}

Mission* Game::getCurrentMissionOf(Character *pChar) {
	Mission* current = nullptr;
	for (int i = 0; i < missions.size(); i++) {
		if (missions.at(i)->getCharacterAssigned() == pChar && missions.at(i)->isCurrent()) {
			current = missions.at(i);
			//std::cout << "Current mission of " << pChar->getName() << " found!" << std::endl;
		}
	}
	return current;
}

void Game::setCurrentMissionOf(Character *pChar, Mission *pMission) {
	Mission *old = getCurrentMissionOf(pChar);
	if (old != nullptr)
		old->setCurrent(false);
	
	pMission->setCurrent(true);
}
void Game::displayMissionsOfCharacter(Character *pChar) {
	Mission *current = getCurrentMissionOf(pChar);
	if (current != nullptr) {
		std::cout << "Current mission : " << std::endl;
		std::cout << "\t";
		current->headLines();
	}
	if (getNbOfMissionsFor(pChar) > 1) {
		std::cout << "Other missions : " << std::endl;
		for (Mission* mission : missions) {
			if (mission->isAssignedTo(pChar) && mission != current && !(mission->isFinished())) {
				std::cout << "\t";
				mission->headLines();
			}
		}
	}
	else
		std::cout << "No other missions are assigned to " << pChar->getName() << std::endl;
}

int Game::getNbOfMissionsFor(Character *pChar) {
	int nbMissions = 0;
	for (Mission* mission : missions) {
		if (mission->isAssignedTo(pChar))
			nbMissions++;
	}
	return nbMissions;
}
int Game::getNbOfMissionsFor(Company *pCompany) {
	int nbMissions = 0;
	for (Mission* mission : missions) {
		if (mission->isAssignedTo(pCompany))
			nbMissions++;
	}
	return nbMissions;
}


bool Game::isRunning() {
	return running;
}

void Game::draw() {
	display->update();
}

void Game::update(std::chrono::microseconds elapsed) {
	// Things happening here (delegate to state)
	GameState* newState = currentState->update(elapsed);
	if (newState != nullptr) {
		changeState(newState);//Manage deletion of old state somewhere, and see how I do with those to keep in memory
	}
}

void Game::handleEvents() {
	//Will be delegated to state
	currentState->handleEvents();
}

void Game::changeState(GameState* newState) {
	delete(currentState);
	currentState = newState;
}