#pragma once
#include <string>
#include <vector>
#include <iostream>
#include <memory>

#include "Company.h"
#include "Character.h"

/*Have to put somewhere what the mission goal is
	-> Min level of reinforced equipements
	-> Max vulnerabilities left
	-> Name of employees ? Logins/pwd ? 
	-> Money to perceive
	-> Backdoor to place
*/
//Put desiredValues on attributes (= discovered on employe names, backdoor introduced on a server (=something placed on an element), password found
// something powered off,...

//Have to put a list of all things to discover or discovered

//class Company;

class Company;

class Mission
{

private:
	std::string title;
	std::string description;

	Character *assignedTo;
	Character *applicant;

	std::vector<Entity*> sponsor;
	std::vector<std::shared_ptr<Company>> targetArray;
	std::vector<Company*> companiesDoing; // Can be shared for COOP 

	int securityLevel;
	int whitePercentage;
	int greyPercentage;
	int blackPercentage;

	bool current;
	bool finished;

public:
	Mission();
	Mission(std::string pTitle, std::string pDescription, std::shared_ptr<Company> pTarget, int pLevel, int pW, int pG, int pB);
	~Mission();


	void headLines();
	void details();
	void displayAllTargetsStatistics();
	void addTarget(std::shared_ptr<Company> newTarget);

	void assignToCharacter(Character* pChar);
	void assignToCompany(Company* pCompany);
	void setApplicant(Character *pChar);
	void setFinished();
	bool isFinished();

	bool isAssignedTo(Character* pChar);
	bool isAssignedTo(Company* pCompany);
	bool isCurrent();
	void setCurrent(bool pCurrent);
	Character* getCharacterAssigned();
	std::vector<Company*> getCompaniesAssigned();
};

