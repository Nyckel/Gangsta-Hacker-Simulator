#pragma once
#include <string>
#include <vector>
#include <chrono>

#include "Character.h"
#include "Attribute.h"
#include "Entity.h"

#include "TechTree.h"

class Company : public Entity //Compagny data for other than targets will be loaded in data files
{
private:
	//Technologies trees are Game property, in vs mode you can't see the target's tech tree (no sense)

	//std::vector<Company> subCompanies;  Maybe later
	// Power consumption...

	Attribute name;
	Attribute description;

	bool isTarget; // If true, other booleans discared
	//Maybe put on individual elements (servers, characters, ...)
	bool allowedScan;
	bool allowedExploit;
	bool allowedPostExploit;
	//Employees, email adresses, machines and servers, (map of equipements) -> each equipement and version has vulnerbilities
	//Website ? Clients talking about you ? renown

	
	std::vector<Character> characters;
	Attribute nbCharacters;
	Attribute renown; // -> Better missions, publishing zeroDays, being politically engaged or claiming hack makes you famous (not always a good thing) 
	Attribute balance;
	Attribute acheivedWhite;
	Attribute acheivedGrey;
	Attribute acheivedBlack;

	//Moneymoney
	Attribute dollars;
	Attribute bitcoins;
	TechTree technologyTree;

public:
	Company();
	Company(std::string pName);
	Company::Company(std::string pName, int pRenown, int pBalance);
	~Company();

	Character createFirstCharacter();
	Character* getCharacter(int index);
	void addCharacter(Character *pChar);
	void createTechTree();
	int getNbCharacters();
	void displayStatistics();
	//void displayAllMissions();
	//std::vector<Mission*> getRunningMissions();
	//void updateActivities(const long long elapsed);
	void updateActivities(std::chrono::microseconds elapsed);

	bool isAllowedScan();
	bool isAllowedExploit();
	bool isAllowedPostExploit();

};

