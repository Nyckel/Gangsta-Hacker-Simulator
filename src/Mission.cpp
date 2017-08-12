#include "Mission.h"
class Character;
class Company;


Mission::Mission()
{

	assignedTo = -1;
	applicant = -1;
	current = false;
	finished = false;

	title = "Tuto";
	description = "Petite mission pour apprendre le game";
	//Company* targetArray;
	//Company *target;
	securityLevel = 0;
	whitePercentage = 100/3;
	greyPercentage = 100/3;
	blackPercentage = 100/3;
}

Mission::Mission(std::string pTitle, std::string pDescription, int pTargetCompanyId, int pLevel, int pW, int pG, int pB) 
	: title{ pTitle }, description{ pDescription }, securityLevel{ pLevel }, whitePercentage{ pW }, greyPercentage{ pG }, blackPercentage{ pB } {

	//Company* targetsArray;
	applicant = -1;
	current = false;
	finished = false;
	targetArray.push_back(pTargetCompanyId);

	assignedTo ={};

}

void Mission::headLines() const {
	std::cout << title << " (Given by: " << applicant << ") -> " << description << std::endl;
}

void Mission::details() {
	std::cout << "Mission brief" << std::endl;
	std::cout << "\tTitle: " << title << std::endl;
	std::cout << "Description: " << description << std::endl;
	std::cout << "The target(s) is/are : " << std::endl;
	for (auto target : targetArray)
		std::cout << target << std::endl;
	//displayAllTargetsStatistics();
}

//void Mission::displayAllTargetsStatistics() {
//	for (int i = 0; i < targetArray.size(); i++) {
//		targetArray.at(i)->displayStatistics();
//	}
//}

void Mission::addTarget(int newTargetId) {
	targetArray.push_back(newTargetId);
}

void Mission::assignToCharacter(int pCharacterId) {
	assignedTo = pCharacterId;
}
void Mission::assignToCompany(int pCompany) {
	companiesDoing.push_back(pCompany);
}
void Mission::setFinished() {
	finished = true;
}

bool Mission::isAssignedToCharacter(int pCharacterIdr) const {
	return (assignedTo == pCharacterIdr);
}
bool Mission::isAssignedToCompany(int pCompany) const
{
	bool assigned = false;
	for (auto comp : companiesDoing) {
		if (comp == pCompany)
			assigned = true;
	}
	return assigned;
}

void Mission::setCurrent(bool pCurrent) { current = pCurrent; }