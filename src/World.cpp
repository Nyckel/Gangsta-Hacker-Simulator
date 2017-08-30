#include "World.h"

//void World::createFirstCompany()
//{
//	std::string companyName;
//	std::cout << "\tWell, we are going to create your Company, what name did you think to ? ";
//	std::cin >> companyName;
//	auto company = Company(companyName);
//	company.getCharacters()[0].createTechTree();
//	playableCompanies.push_back(company);
//}

void World::loadMissions()
{
	//Create Characters and companies
	Character badGuysDirector { "Brandon", Male, false };
	Character goodGuysDirector { "Michelle", Female, false };
	std::unique_ptr<Company> goodGuys = std::make_unique<Company> ( "ThegoodGuys", 1, 0 );
	goodGuys->addCharacter(&goodGuysDirector);

	//Create Missions and set people giving these missions
	Mission attack("Hack bob", "Hi, we need to break these guys, we'll pay you a lot if you hack X company", goodGuys->getCompanyId(), 0, 0, 0, 100);
	Mission defend("Protect bob", "X company has reasons to believe that someone is trying to hack them, they ask for help",goodGuys->getCompanyId(), 1, 100, 0, 0);
	attack.setApplicant(badGuysDirector.getCharacterId());
	defend.setApplicant(goodGuysDirector.getCharacterId());

	playableCompanies.at(0).giveMission(attack); // give a copy of the mission
	playableCompanies.at(0).giveMission(defend);
	missions.push_back(attack);
	missions.push_back(defend);
	knownCompanies[goodGuys->getCompanyId()] = move(goodGuys);

	playableCompanies.at(0).getCharacter(0)->setCurrentActivity(&playableCompanies.at(0).getAvailableActivities()[0]);

}
