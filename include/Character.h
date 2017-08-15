#pragma once
#include <iostream>
#include <vector>
#include <string>
#include <chrono>
#include <fstream>

#include "Attribute.h"
#include "Activity.h"
#include "Entity.h"
#include "StringAttribute.h"
#include "IntAttribute.h"
#include "LevelAttribute.h"


//Ajouter un truc pour gérer le sommeil et la fatigue et un truc pour voir ses mails

enum eGender { Male, Female };
class Mission;
class Activity;

class Character : public Entity
{
private:
	//Skin 
	//Color code for missions
	enum eGender gender;
	bool playable;

	StringAttribute name;
	Activity* currentActivity; // replace by an observer_ptr when implemented

	int characterId;

	IntAttribute renown;
	IntAttribute balance;
	IntAttribute acheivedWhite; //Nb missions finished in domain
	IntAttribute acheivedGrey;
	IntAttribute acheivedBlack;
	
	IntAttribute xpGlobal;
	IntAttribute xpWhite;
	IntAttribute xpGrey;
	IntAttribute xpBlack;
	IntAttribute xpRecon;
	IntAttribute xpScan;
	IntAttribute xpExploit;
	IntAttribute xpPostExploit;

	LevelAttribute level_global;

	/*Attribute level_recon;
	Attribute level_scan;
	Attribute level_exploit;
	Attribute level_postExploit;*/

	
	/*Level level_global;
	Level level_recon;
	Level level_scan;
	Level level_exploit;
	Level level_postExploit;*/

public:
	Character(bool pPlayable);
	Character(std::string pName, enum eGender pGender, bool pPlayable);
	~Character();
	void displayStatistics();
	
	void setName(std::string pName);
	void setGender(enum eGender pGender);

	std::string getName() const;
	//void affectMission(Mission* pMission);
	//void startMission(int pIndex);
	//void displayMissions();
	//Mission* getCurrentMission();

	//void addPossibleActivity(const Activity* pAct);
	void setCurrentActivity(Activity* pAct);
	Activity* getCurrentActivity() const;
	//int getCurrentActivityIndex() const;
	void updateActivity(std::chrono::microseconds elapsed);
	void getActivityPoints(Activity *pAct);
	bool isDoingSomething() const;

	int getCharacterId() const { return characterId; }

	static int characterIds;


private: void deleteAttribute(Attribute* pAttr);
		 //void deletePossibleActivity(int pIndex);
		 void checkLevels();

	//Create activity from a TechTreeElement object

	
};