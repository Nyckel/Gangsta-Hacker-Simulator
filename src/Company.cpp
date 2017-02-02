#include "Company.h"


class Character;


Company::Company()
{
}

Company::Company(std::string pName) {//This is for the player
	//name = pName;
	name.setValue(pName);

	renown = 0; // -> Better missions
	balance = 0;
	acheivedWhite = 0;
	acheivedGrey = 0;
	acheivedBlack = 0;

	Character firstCharacter = createFirstCharacter();
	characters.push_back(firstCharacter);

	dollars = Attribute(money, 0);
	bitcoins = Attribute(money, 0);
	//displayStatistics();
	//std::cout << "\t";
	//system("pause");
}

Company::Company(std::string pName, int pRenown, int pBalance) { 
	name.setValue(pName);
	renown = pRenown;
	balance = pBalance;
	allowedScan = false;
	allowedExploit = false;
	allowedPostExploit = false;

}


Company::~Company()
{
}


Character Company::createFirstCharacter() {
	std::string name;

	std::cout << "\tAnd what is your little name ? ";
	std::cin >> name;

	//Set gender of new Character
	bool goodGender = false;
	std::string genderChar;
	enum eGender gender;
	while (!goodGender) {
		std::cout << "\tSex (M/F)? ";
		std::cin >> genderChar;
		if (std::string(genderChar) == "M" || std::string(genderChar) == "m") {
			goodGender = true;
			gender = Male;
		}
		else if (std::string(genderChar) == "F" || std::string(genderChar) == "f") {
			goodGender = true;
			gender = Female;
		}
	}

	Character newCharacter(name, gender, true);
		
	std::cout << std::endl << "\tWelcome to a whole new world bro, my world.." << std::endl << "\t";
	system("pause");
	return newCharacter;
}

void Company::addCharacter(Character *pChar) {
	characters.push_back(*pChar);
}

Character* Company::getCharacter(int index) {
	if (index >= 0 && index < characters.size()) {
		return &(characters.at(index));
	}
	else
		return NULL;
}


void Company::displayStatistics(){
	//system("cls");

	std::cout <<std::endl<< "\tCompany name: " << name << std::endl;
	std::cout << "__________________________________________________________________________________________" << std::endl;
	if(!description.empty())
		std::cout << "\tDescription: " << description << std::endl;
	std::cout << "\tRenown: " << renown << std::endl;
	std::cout << "\tBalance: " << balance << std::endl;
	std::cout << "\tList of employees: " << std::endl;
	for (int i = 0; i < characters.size(); i++) {
		characters[i].displayStatistics();
	}
	std::cout << "__________________________________________________________________________________________" << std::endl;
}

/*void Company::displayAllMissions() {
	for (int i = 0; i < characters.size(); i++) {
		characters.at(i).displayMissions();
	}
}
std::vector<Mission*> Company::getRunningMissions() {
	std::vector<Mission*> runningMissions;
	for (int i = 0; i < characters.size(); i++) {
		if(characters.at(i).getCurrentMission() != NULL)
		runningMissions.push_back(characters.at(i).getCurrentMission());
	}
	return runningMissions;
}*/
int Company::getNbCharacters() {
	return characters.size();
}


void Company::updateActivities(std::chrono::microseconds elapsed) {

	for (int i = 0; i < characters.size(); i++) {
		if (characters.at(i).isDoingSomething()) {
			characters.at(i).updateActivity(elapsed);//Add "characters.at(i)" param to get elements discovered by this character
			// -> Things are discovered in updateActivity() in a function using randomness and skills
		}
		else {
			std::cout << characters.at(i).getName() << " is not doing anything" << std::endl;
		}
	}
}

void Company::createTechTree() {
	technologyTree = *new TechTree("techTree.json");
}


bool Company::isAllowedScan() { return allowedScan; }
bool Company::isAllowedExploit() { return allowedExploit; }
bool Company::isAllowedPostExploit() { return allowedPostExploit; }