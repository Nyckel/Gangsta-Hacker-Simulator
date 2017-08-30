#include "Character.h"

int Character::characterIds = 0;

Character::Character(bool pPlayable){

	characterId = characterIds++;

	gender = Male;
	playable = pPlayable;
	currentActivity = nullptr;

	name = { "Chappie" };//*new Attribute(std::string("Chappie"));
	renown = { 0 };
	balance = { 0 };
	
	if (playable) {
		acheivedWhite = { 0 };
		acheivedGrey = { 0 };
		acheivedBlack = { 0 };

		xpGlobal = { 0 };
		xpWhite = { 0 };
		xpGrey = { 0 };
		xpBlack = { 0 };
	}
	
	level_global = LevelAttribute(xpGlobal.getValue(), std::string("ressources/jsons/levels.json"));
	//std::cout << "In constructor level: " << std::endl << level_global.getIndex();
	/*
	level_recon = *new Attribute(0);
	level_scan = *new Attribute(0);
	level_exploit = *new Attribute(0);
	level_postExploit = *new Attribute(0);
	*/
}

Character::Character(std::string pName, enum eGender pGender, bool pPlayable) {

	characterId = characterIds++;

	playable = { pPlayable };
	name = { pName };
	currentActivity = nullptr;

	gender = pGender;
	renown = { 0 };
	balance = { 0 };
	acheivedWhite = { 0 };
	acheivedGrey = { 0 };
	acheivedBlack = { 0 };

	xpGlobal = { 0 };
	xpBlack = { 0 };
	xpGrey = { 0 };
	xpWhite = { 0 };
	xpRecon = { 0 };
	xpScan = { 0 };
	xpExploit = { 0 };
	xpPostExploit = { 0 };
	
	//Create Attributes of type level from json
	/*Json::Value root;
	Json::Reader reader;
	std::ifstream file("levels.json", std::ifstream::binary);
	file >> root;
	const Json::Value levels = root["levels"]; //Send that to a function with info about if playableCharacter, and the level he has
	if (levels["white"] != NULL) {
		std::cout << levels["white"]["1"]["label"].asString() << ", " << levels["white"]["2"]["label"].asString() << std::endl;
		Level levelWhite;
		system("pause");
	}*/

	level_global = LevelAttribute(xpGlobal.getValue(), std::string("ressources/jsons/levels.json"));
	/*level_recon = *new Attribute(0);
	level_scan = *new Attribute(0);
	level_exploit = *new Attribute(0);
	level_postExploit = *new Attribute(0);*/
}


void Character::displayStatistics() {
	std::cout << "\tName: " << name << std::endl;
	if (currentActivity != nullptr) {
		std::cout << "\tCurrent activity: " << getCurrentActivity()->getName() << std::endl;
		std::cout << "\tTime elapsed: " << getCurrentActivity()->getTimeElapsed().count() << std::endl;
	}
	//std::cout << "\tGender: ";
	//if (gender == 0)
	//	std::cout << "Male" << std::endl;
	//else
	//	std::cout << "Female" << std::endl;
	std::cout << "\tBalance: " << balance << std::endl;
	std::cout << "\t  -> acheivedWhite: " << acheivedWhite << std::endl;
	std::cout << "\t  -> acheivedGrey: " << acheivedGrey << std::endl;
	std::cout << "\t  -> acheivedBlack: " << acheivedBlack << std::endl;
	std::cout << "\tLevel: " << level_global << std::endl;

	std::cout << "\tXP: " << xpGlobal << std::endl;
	std::cout << "\t\tWhite   -> " << xpWhite << std::endl;
	std::cout << "\t\tGrey    -> " << xpGrey << std::endl;
	std::cout << "\t\tBlack   -> " << xpBlack << std::endl;
	std::cout << "\t\tRecon   -> " << xpRecon << std::endl;
	std::cout << "\t\tScan    -> " << xpScan << std::endl;
	std::cout << "\t\tExploit -> " << xpExploit << std::endl;
	std::cout << "\t\tPost    -> " << xpPostExploit << std::endl;
	/*std::cout << "\t\t  -> Recon: " << level_recon << std::endl;
	std::cout << "\t\t  -> Scan: " << level_scan << std::endl;
	std::cout << "\t\t  -> Exploit: " << level_exploit << std::endl;
	std::cout << "\t\t  -> Post exploit: " << level_postExploit << std::endl;*/
}


Character::~Character()
{
	/*deleteAttribute(&name);
	deleteAttribute(&renown);
	deleteAttribute(&balance);*/
	
	//deleteAttribute(&acheivedWhite);
	//deleteAttribute(&acheivedGrey);
	//deleteAttribute(&acheivedBlack);

	//deleteAttribute(&xpGlobal);
	//deleteAttribute(&xpWhite);
	//deleteAttribute(&xpGrey);
	//deleteAttribute(&xpBlack);
	//deleteAttribute(&xpRecon);
	//deleteAttribute(&xpScan);
	//deleteAttribute(&xpExploit);
	//deleteAttribute(&xpPostExploit);

	//
	//deleteAttribute(&level_global);
	/*deleteAttribute(&level_recon);
	deleteAttribute(&level_scan);
	deleteAttribute(&level_exploit);
	deleteAttribute(&level_postExploit)*/;

	//for (int i = 0; i < possibleActivities.size(); i++) {
	//	//deletePossibleActivity(i);
	//}
}
void Character::deleteAttribute(Attribute* pAttr) {
	if (pAttr != nullptr) {
		//delete(pAttr);
	}
}

void Character::setName(std::string pName) {
	name.setValue(pName);
}
void Character::setGender(enum eGender pGender) {
	gender = pGender;
}


std::string Character::getName() const{
	return name.getValue();
}
/*Mission* Character::getCurrentMission() {
if (currentMissionIndex != NULL) {
Mission* currentMission = &(missions.at(currentMissionIndex));
return currentMission;
}
else return NULL;
}
void Character::affectMission(Mission* pMission) {
	missions.push_back(*pMission);
}
void Character::startMission(int pIndex) {
	if (pIndex < missions.size()) {
		currentMissionIndex = pIndex;
		//Update activities with allowed target for certains tasks
	}
	else std::cout << "Could not start mission, index out of missions vector" << std::endl;

}

void Character::displayMissions() {
	for (int i = 0; i < missions.size(); i++) {
		missions.at(i).details();
	}
}*/

//void Character::addPossibleActivity(const Activity* pAct) {
//	possibleActivities.push_back(*pAct);
//}
void Character::setCurrentActivity(Activity* pAct) {
	currentActivity = { pAct };
	std::cout << name << " is now doing " << pAct->getName() << std::endl;
}
Activity* Character::getCurrentActivity() const{
	return currentActivity;
}
//int Character::getCurrentActivityIndex() const { return currentActivityIndex; }

void Character::updateActivity(std::chrono::microseconds elapsed){
	if (currentActivity != nullptr) {

		currentActivity->update(elapsed);//Things are discovered in updateActivity() in a function using randomness and skills or only time (conf)	
		//Maybe send back discovered things from here (send pointer to vector of discovered things) or 
		if (currentActivity->isFinished()) {
			getActivityPoints(currentActivity);//Will also  update levels
			// Check if that mission ended a mission (or a part ? -> Do a pentest report be the last activity, can go as far as wanted before ?)
			// Detection current activity or finished activity was off contract -> (risk reaction ?)
			// Advance missions status
			
			//deletePossibleActivity(currentActivityIndex);
			std::cout << "Current activity finished" << std::endl;
			currentActivity = nullptr;
		}
	}
	else {
		std::cout << "my current activity index is NULL" << std::endl;
	}
	
}


void Character::getActivityPoints(Activity *pAct) {
	//Add renown 

	int earnedXp = pAct->getXp();
	xpGlobal.setValue(xpGlobal.getValue() + earnedXp);
	switch (pAct->getOrientation()) {
	case White:	xpWhite.setValue(xpWhite.getValue() + earnedXp);
		break;
	case Grey: xpGrey.setValue(xpGrey.getValue() + earnedXp);
		break;
	case Black:	xpBlack.setValue(xpBlack.getValue() + earnedXp);
		break;
	}
	switch (pAct->getType()) {
	case Recon:	xpRecon.setValue(xpRecon.getValue() + earnedXp);
		break;
	case Scan: xpScan.setValue(xpScan.getValue() + earnedXp);
		break;
	case Exploit: xpExploit.setValue(xpExploit.getValue() + earnedXp);
		break;
	case PostExploit: xpPostExploit.setValue(xpPostExploit.getValue() + earnedXp);
		break;
	}

	checkLevels();
	//Update levels and orientation(w/g/b)

}
//
//void Character::deletePossibleActivity(int pIndex) {
//	//if (currentActivityIndex != pIndex) {
//		delete(&(possibleActivities.at(pIndex)));
//		possibleActivities.erase(possibleActivities.begin() + pIndex);
//	//}
//	//else {
//		//std::cout << "Trying to delete current activity (" << possibleActivities.at(currentActivityIndex).getName() << ")" << std::endl;
//	//}
//}

bool Character::isDoingSomething() const
{
	return currentActivity != nullptr && currentActivity->isStarted();
}


void Character::checkLevels() {
	if (xpGlobal.getValue() > level_global.getLevelXpForNext()) {
		level_global.update(xpGlobal.getValue(), "ressources/jsons/levels.json");
		//for each level check if xp > pallier for next level
	}
}

void Character::createTechTree() {
	technologyTree = TechTree("ressources/jsons/techTree.json");
}