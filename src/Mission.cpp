#include "Mission.h"
class Character;
class Company;


Mission::Mission()
{
	title = "Tuto";
	description = "Petite mission pour apprendre le game";
	//Company* targetArray;
	//Company *target;
	securityLevel = 0;
	whitePercentage = 100/3;
	greyPercentage = 100/3;
	blackPercentage = 100/3;
}

Mission::Mission(std::string pTitle, std::string pDescription, std::shared_ptr<Company> pTarget, int pLevel, int pW, int pG, int pB) {
	title = pTitle;
	description = pDescription;
	//Company* targetsArray;
	targetArray.push_back(pTarget);
	securityLevel = pLevel;
	whitePercentage = pW;
	greyPercentage = pG;
	blackPercentage = pB;
}


Mission::~Mission()
{
	for (Company *cmp : companiesDoing) {
		cmp = nullptr;
	}
}

void Mission::headLines() {
	std::cout << title << " (Given by: " << applicant->getName() << ") -> " << description << std::endl;
}

void Mission::details() {
	std::cout << "Mission brief" << std::endl;
	std::cout << "\tTitle: " << title << std::endl;
	std::cout << "Description: " << description << std::endl;
	std::cout << "The target is: " << std::endl;
	displayAllTargetsStatistics();
}

void Mission::displayAllTargetsStatistics() {
	for (int i = 0; i < targetArray.size(); i++) {
		targetArray.at(i)->displayStatistics();
	}
}

void Mission::addTarget(std::shared_ptr<Company> newTarget) {
	targetArray.push_back(newTarget);
}

void Mission::assignToCharacter(Character *pChar) {
	assignedTo = pChar;
}
void Mission::assignToCompany(Company* pCompany) {
	companiesDoing.push_back(pCompany);
}
void Mission::setApplicant(Character *pChar) {
	applicant = pChar;
}

void Mission::setFinished() {
	finished = true;
}
Character* Mission::getCharacterAssigned() {
	return assignedTo;
}
std::vector<Company*> Mission::getCompaniesAssigned() {
	return companiesDoing;
}
bool Mission::isAssignedTo(Character* pChar) {
	return (assignedTo == pChar);
}
bool Mission::isAssignedTo(Company* pCompany) {
	bool assigned = false;
	for (Company *comp : companiesDoing) {
		if (comp == pCompany)
			assigned = true;
	}
	return assigned;
}
bool Mission::isFinished() { return finished;  }
bool Mission::isCurrent() { return current; }
void Mission::setCurrent(bool pCurrent) { current = pCurrent; }