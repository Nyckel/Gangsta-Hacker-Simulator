#include "PlayingState.h"


void ClrScrn(char attrib) {
	const int ROWS = 50;
	const int COLS = 80;
	COORD pos = { 0, 0 };
	DWORD written;
	CHAR_INFO disp[ROWS][COLS];
	auto console = GetStdHandle(STD_OUTPUT_HANDLE);
	//COORD size = { COLS, ROWS };
	COORD src = { 0, 0 };
	SMALL_RECT  dest = { 0, 0, COLS, ROWS };

	unsigned size = ROWS * COLS;

	FillConsoleOutputCharacter(console, ' ', size, pos, &written);
	FillConsoleOutputAttribute(console, attrib, size, pos, &written);
	SetConsoleCursorPosition(console, pos);
}


PlayingState::PlayingState(MainWindow* pWindow)
{
	window = pWindow;
	world = std::make_unique<World>(World());

	messager = tgui::ChatBox::create();
	//messager->setRenderer(window->getTheme().getRenderer("TextBox"));
	messager->setSize(window->getSize().x * 0.8, window->getSize().y*0.5);
	messager->setPosition(window->getSize().x/2 - messager->getSize().x/2, 200);
	system("cls");
	/*std::cout << "Switching to PlayingState" << std::endl;
	std::cout << std::endl << "\tCreating new game..." << std::endl;*/
	messager->addLine("Hi, we're going to create your character together ;)");
	//window->addToGui(messager);
	displayNewGameMenu();
	//world->createFirstCompany();
	std::cout << "\tCompany created" << std::endl;
	//playerCompanies.at(0)->createTechTree();

	running = true;
	quit = false;

	system("cls");

	auto start = std::chrono::steady_clock::now();
	auto end = std::chrono::steady_clock::now();
	auto elapsed = std::chrono::duration_cast<std::chrono::microseconds>(end - start); //Why not as an object attribute
																					   //Or multipliate the timer for every action (code, research,...) by a speed coef -> but wouldn't speed up animations ?
	window->setBackground("ressources/images/3.jpg");
	//testMissions();
	//world->loadMissions();
}


PlayingState::~PlayingState()
{
	for (auto cmp : playerCompanies) {
		delete(cmp);
	}
	for (auto cmp : companies) {
		delete(cmp);
	}
	for (auto m : missions) {
		delete(m);
	}
}

void PlayingState::init() {

}
void PlayingState::cleanUp() {

}

void PlayingState::pause() {

}
void PlayingState::resume() {

}

void PlayingState::handleEvents() {
	auto events =  window->getEvents();
	for (auto event : events) {
		if (event.type == sf::Event::Closed) {
			window->close();
			break;
		}
		window->tguiHandle(event);
	}
}

std::unique_ptr<GameState> PlayingState::update(std::chrono::microseconds elapsed) {
	//system("cls");
	//ClrScrn(0x71);
	//std::cout << "At pos 1 elapsed = " << elapsed.count() << std::endl;
	updateActivities(elapsed);
	// Generate some random things happening ? Missions arriving, random events...

	//displayMissionsOfCharacter(playerdkjsjb s:kw Companies.at(0).getCharacter(0));
	//playerCompanies.at(0)->getCharacter(0)->displayStatistics();
	//if (!playerCompanies.at(0)->getCharacter(0)->isDoingSomething()) {
		//auto actMenu = window->createAcdskhbszkdqjntivityMenu();
		//window->clearComponents();
		//window->addComponent(actMenu);
	//}
	//if (!world->getPlayerCompanies().at(0).getCharacters().at(0).isDoingSomething())
	//{
	//	askForNewAct();
	//}
	return nullptr;
}
void PlayingState::draw() {
	window->update();
}

//Company* PlayingState::createCompany() {
//	std::string companyName;
//	std::cout << "\tWell, we are going to create your Company, what name did you think to ? ";
//	std::cin >> companyName;
//	Company* newCompany = new Company(companyName);
//
//	return newCompany;
////}
//
//void PlayingState::testMissions() {
//
//	//Create Characters and companies
//	Character badGuysDirector("Brandon", Male, false);
//	Character goodGuysDirector("Michelle", Female, false);
//	Company *goodGuys = new Company("ThegoodGuys", 1, 0);
//	goodGuys->addCharacter(&goodGuysDirector);
//
//	//Create Missions and set people giving these missions
//	Mission attack("Hack bob", "Hi, we need to break these guys, we'll pay you a lot if you hack X company", goodGuys->getCompanyId(), 0, 0, 0, 100);
//	Mission defend("Protect bob", "X company has reasons to believe that someone is trying to hack them, they ask for help", goodGuys->getCompanyId(), 1, 100, 0, 0);
//	attack.setApplicant(badGuysDirector.getCharacterId());
//	defend.setApplicant(goodGuysDirector.getCharacterId());
//
//	// Affect these missions
//	Company *mainCompany = playerCompanies.at(0);
//	if (mainCompany->getNbCharacters() != 0)
//		if (mainCompany->getCharacter(0) != nullptr) {
//
//			attack.assignToCompany(mainCompany->getCompanyId());
//			defend.assignToCompany(mainCompany->getCompanyId());
//			attack.assignToCharacter(mainCompany->getCharacter(0)->getCharacterId());
//			defend.assignToCharacter(mainCompany->getCharacter(0)->getCharacterId());
//			missions.push_back(&attack);
//			missions.push_back(&defend);
//			setCurrentMissionOf(mainCompany->getCharacter(0), &attack);
//			//displayMissionsOfCharacter(mainCompany->getCharacter(0));
//			//system("pause");
//		}
//		else {
//			std::cout << "Mission could not be affected to character";
//			system("pause");
//			exit(1);
//		}
//	else {
//		//std::cout << "There are " << mainCompany->getNbCharacters() << "characters in the comany" << std::endl;
//	}
//
//
//#pragma region testsActivities
//	Activity actTest;
//	mainCompany->getCharacter(0)->addPossibleActivity(&actTest);
//	mainCompany->getCharacter(0)->setCurrentActivity(0);
//	mainCompany->getCharacter(0)->getCurrentActivity()->start();
//	//std::cout << "Time elapsed (just started): " << mainCompany->getCharacter(0)->getCurrentActivity()->getTimeElapsed().count() << std::endl;
//	//std::cout << "Current activity in .. is : " << mainCompany->getCharacter(0)->getCurrentActivityIndex() << std::endl;
//#pragma endregion
//}
//

void PlayingState::setCurrentMissionOf(Character *pChar, Mission *pMission) {
	Mission *old = getCurrentMissionOf(pChar);
	if (old != nullptr)
		old->setCurrent(false);

	pMission->setCurrent(true);
}

Mission* PlayingState::getCurrentMissionOf(const Character *pChar) {
	Mission* current = nullptr;
	for (int i = 0; i < missions.size(); i++) {
		if (missions.at(i)->getCharacterAssigned() == pChar->getCharacterId() && missions.at(i)->isCurrent()) {
			current = missions.at(i);
			//std::cout << "Current mission of " << pChar->getName() << " found!" << std::endl;
		}
	}
	return current;
}

void PlayingState::updateActivities(std::chrono::microseconds elapsed) {
	for (Company& cmp : world->getPlayerCompanies()) {
		cmp.updateActivities(elapsed);
		cmp.getCharacters()[0].displayStatistics();
	}
}


void PlayingState::displayMissionsOfCharacter(Character *pChar) {
	Mission *current = getCurrentMissionOf(pChar);
	if (current != nullptr) {
		std::cout << "Current mission : " << std::endl;
		std::cout << "\t";
		current->headLines();
	}
	if (getNbOfMissionsFor(pChar) > 1) {
		std::cout << "Other missions : " << std::endl;
		for (Mission* mission : missions) {
			if (mission->isAssignedToCharacter(pChar->getCharacterId()) && mission != current && !(mission->isFinished())) {
				std::cout << "\t";
				mission->headLines();
			}
		}
	}
	else
		std::cout << "No other missions are assigned to " << pChar->getName() << std::endl;
}

int PlayingState::getNbOfMissionsFor(Character *pChar) {
	auto nbMissions = 0;
	for (auto* mission : missions) {
		if (mission->isAssignedToCharacter(pChar->getCharacterId()))
			nbMissions++;
	}
	return nbMissions;
}

void PlayingState::askForNewAct() const
{
	static int asked;
	asked++;
	if (!asked)
	{
		auto ask = tgui::Button::create("Start new Activity ? ");
		ask->setRenderer(window->getTheme().getRenderer("Button"));
		ask->setPosition(100, 100);

		window->addToGui(ask);
	}
}

void PlayingState::createFirstCompany(std::string companyName, std::string characterName, std::string sex)
{
	//std::cout << "\tWell, we are going to create your Company, what name did you think to ? ";
	//std::cin >> companyName;
	auto company = Company(companyName, characterName, sex);
	company.getCharacters()[0].createTechTree();
	world->addPlayableCompany(std::move(company));
	window->clearAll();
}

void PlayingState::displayNewGameMenu() //todo:This method is too long
{
	auto menuTitle = tgui::Label::create("New game");
	auto subTitle = tgui::Label::create("We're going to create your first character ;)");

	menuTitle->setTextSize(30);
	menuTitle->setSize(window->getSize().x / 2, 60);

	menuTitle->setRenderer(window->getTheme().getRenderer("Title"));
	subTitle ->setRenderer(window->getTheme().getRenderer("Label"));

	menuTitle->setPosition(window->getSize().x / 2 - menuTitle->getSize().x / 2, 30);
	subTitle ->setPosition(window->getSize().x / 2 - subTitle ->getSize().x / 2, 100);

	auto panel = tgui::Panel::create();
	panel->setSize(window->getSize().x*0.5, window->getSize().y*0.5);
	panel->setRenderer(window->getTheme().getRenderer("Panel"));
	panel->setPosition(window->getSize().x / 2 - panel->getSize().x / 2, window->getSize().y / 2 - panel->getSize().y / 2);

	auto lCompName = tgui::Label::create("Company name");
	auto compNameInput = tgui::EditBox::create();

	auto lCharName = tgui::Label::create("Character name");
	auto charNameInput = tgui::EditBox::create();

	compNameInput->setMaximumCharacters(20);
	compNameInput->setSize(compNameInput->getSize().x, 30);
	lCompName->setRenderer(window->getTheme().getRenderer("Label"));
	compNameInput->setRenderer(window->getTheme().getRenderer("EditBox"));

	charNameInput->setMaximumCharacters(20);
	charNameInput->setSize(compNameInput->getSize().x, 30);
	lCharName->setRenderer(window->getTheme().getRenderer("Label"));
	charNameInput->setRenderer(window->getTheme().getRenderer("EditBox"));

	lCompName->setPosition(10, 10);
	compNameInput->setPosition(200, 10);

	lCharName->setPosition(10, 50);
	charNameInput->setPosition(200, 50);

	compNameInput->focus();
	compNameInput->setAlignment(tgui::EditBox::Alignment::Center);
	charNameInput->setAlignment(tgui::EditBox::Alignment::Center);

	auto maleRadio = tgui::RadioButton::create();
	auto femaleRadio = tgui::RadioButton::create();
	maleRadio->setText("Male");
	femaleRadio->setText("Female");

	maleRadio->setPosition(10, 90);
	femaleRadio->setPosition(100, 90);

	maleRadio->setRenderer(window->getTheme().getRenderer("RadioButton"));
	femaleRadio->setRenderer(window->getTheme().getRenderer("RadioButton"));
	maleRadio->check();

	auto validate = tgui::Button::create("Continue");
	validate->setRenderer(window->getTheme().getRenderer("Button"));
	validate->setSize(window->getSize().x*1/4, 30);
	validate->setPosition(panel->getSize().x / 2 - validate->getSize().x / 2, panel->getSize().y - (validate->getSize().y + 10));
	validate->disable();

	// Check for non empty input before continuing
	compNameInput->connect("TextChanged", [compNameInput, charNameInput, validate]{ 
		if (compNameInput->getText() != "" && charNameInput->getText() != "")
			validate->enable();
		else validate->disable();
	});
	charNameInput->connect("TextChanged", [compNameInput, charNameInput, validate] {
		if (compNameInput->getText() != "" && charNameInput->getText() != "")
			validate->enable();
		else validate->disable();
	});

	validate->connect("pressed", [=]{
		createFirstCompany(compNameInput->getText(), charNameInput->getText(), maleRadio->isChecked() ? "M" : "F");
	});

	panel->add(lCompName);
	panel->add(compNameInput);
	panel->add(lCharName);
	panel->add(charNameInput);
	panel->add(maleRadio);
	panel->add(femaleRadio);
	panel->add(validate);

	window->clearAll();
	window->addToGui(menuTitle);
	window->addToGui(subTitle);
	window->addToGui(panel);
	
}