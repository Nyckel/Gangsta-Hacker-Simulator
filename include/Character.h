#pragma once
#include <iostream>
#include <vector>
#include <string>
#include <chrono>
#include <fstream>

#include "Attribute.h"
#include "Activity.h"
#include "Entity.h"



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

	Attribute name;
	std::vector<Activity> possibleActivities;
	int currentActivityIndex;

	Attribute renown;
	Attribute balance;
	Attribute acheivedWhite; //Nb missions finished in domain
	Attribute acheivedGrey;
	Attribute acheivedBlack;
	
	Attribute xpGlobal;
	Attribute xpWhite;
	Attribute xpGrey;
	Attribute xpBlack;
	Attribute xpRecon;
	Attribute xpScan;
	Attribute xpExploit;
	Attribute xpPostExploit;

	Attribute level_global;

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

	std::string getName();
	//void affectMission(Mission* pMission);
	//void startMission(int pIndex);
	//void displayMissions();
	//Mission* getCurrentMission();

	void addPossibleActivity(Activity* pAct);
	void setCurrentActivity(int pIndex);
	Activity* getCurrentActivity();
	int getCurrentActivityIndex();
	void updateActivity(std::chrono::microseconds elapsed);
	void getActivityPoints(Activity *pAct);
	bool isDoingSomething();



private: void deleteAttribute(Attribute* pAttr);
		 void deletePossibleActivity(int pIndex);
		 void checkLevels();

	//Create activity from a TechTreeElement object

	
};


