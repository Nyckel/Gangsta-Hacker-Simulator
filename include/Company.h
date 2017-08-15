#pragma once
#include <string>
#include <vector>
#include <chrono>
#include <map>

#include "Character.h"
#include "StringAttribute.h"
#include "IntAttribute.h"
#include "Mission.h"
#include "Entity.h"
#include "TechTree.h"


class Company : public Entity //Compagny data for other than targets will be loaded in data files
{
private:
	//Technologies trees are Game property, in vs mode you can't see the target's tech tree (no sense)

	//std::vector<Company> subCompanies;  Maybe later
	// Power consumption...

	StringAttribute name;
	StringAttribute description;
	int companyId;

	std::map<std::string,Company> knownCompanies;
	std::vector<Mission> activeMissions;
	std::vector<Mission> finishedMissions;

	bool isTarget; // If true, other booleans discared
	//Maybe put on individual elements (servers, characters, ...)
	bool allowedScan;
	bool allowedExploit;
	bool allowedPostExploit;
	//Employees, email adresses, machines and servers, (map of equipements) -> each equipement and version has vulnerbilities
	//Website ? Clients talking about you ? renown

	std::vector<Activity> possibleActivities;

	
	std::vector<Character> characters;
	std::vector<Mission> missions;
	IntAttribute nbCharacters;
	IntAttribute renown; // -> Better missions, publishing zeroDays, being politically engaged or claiming hack makes you famous (not always a good thing) 
	IntAttribute balance;
	IntAttribute acheivedWhite;
	IntAttribute acheivedGrey;
	IntAttribute acheivedBlack;

	//Moneymoney
	IntAttribute dollars;
	IntAttribute bitcoins;
	TechTree technologyTree;

	void initDefaultActivities();

public:
	Company();
	Company(std::string pName);
	Company::Company(std::string pName, int pRenown, int pBalance);
	~Company();

	Character createFirstCharacter();
	Character* getCharacter(int index);
	std::vector<Character>& getCharacters() { return characters; }
	void addCharacter(Character *pChar);
	void createTechTree();
	int getNbCharacters() const { return characters.size(); }
	void displayStatistics();
	//void displayAllMissions();
	//std::vector<Mission*> getRunningMissions();
	//void updateActivities(const long long elapsed);
	void updateActivities(std::chrono::microseconds elapsed);

	bool isAllowedScan() const { return allowedScan; }
	bool isAllowedExploit() const { return allowedExploit; }
	bool isAllowedPostExploit() const { return allowedPostExploit; }

	int getCompanyId() const { return companyId; }
	void setCompanyId(int pId) { companyId = { pId }; }

	void giveMission(Mission pMission) { missions.push_back(pMission); }
	std::vector<Activity>& getAvailableActivities() { return possibleActivities; }

	static int compannyIds;

};

