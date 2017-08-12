#pragma once
#include <string>
#include <vector>
#include <iostream>
#include <memory>

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

class Mission
{

private:
	std::string title;
	std::string description;

	int assignedTo; // CharacterId
	int applicant; // CharacterId

	std::vector<int> sponsor;
	std::vector<int> targetArray; // List of Company Ids
	std::vector<int> companiesDoing; // Can be shared for COOP 

	int securityLevel;
	int whitePercentage;
	int greyPercentage;
	int blackPercentage;

	bool current;
	bool finished;

public:
	Mission();
	Mission(std::string pTitle, std::string pDescription, int pTargetCompanyId, int pLevel, int pW, int pG, int pB);


	void headLines() const;
	void details();
	//void displayAllTargetsStatistics();
	void addTarget(int newTargetId);

	void assignToCharacter(int pCharacterId);
	void assignToCompany(int pCompanyId);
	void setApplicant(int characterId) { applicant = characterId; };
	void setFinished();
	bool isFinished() const { return finished; }

	bool isAssignedToCharacter(int pCharacterIdr) const;
	bool isAssignedToCompany(int pCompany) const;
	bool isCurrent() const { return current; }
	void setCurrent(bool pCurrent);
	int getCharacterAssigned() const { return assignedTo; }
	std::vector<int> getCompaniesAssigned() const { return companiesDoing; }
};

