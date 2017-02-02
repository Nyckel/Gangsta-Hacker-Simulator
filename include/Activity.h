#pragma once
#include <string>
#include <iostream>
#include <chrono>
//#include "Mission.h"
//#include "Company.h"

enum eActType { Research, Recon, Scan, Exploit, PostExploit, dev, hardwareInstall, conf };
enum eOrientation { Black, Grey, White};

class Activity
{

private:
	std::string name;
	std::string description;

	std::chrono::seconds duration;
	std::chrono::microseconds elapsed;
	//bool paused
	bool finished;
	bool allowed;
	//std::vector<Company> allowedTargets; //Replace by elements of the company ? 
	//Install servers or new hardware, do research, go to conference, hack smthg 
	eActType typeAct;
	eOrientation orientation;
	std::chrono::steady_clock::time_point startTime;

	//The points earned each category by accomplishing this activity
	int xpRecon;
	int xpScan;
	int xpExploit;
	int xpPostExploit;

	int xp;


public:
	Activity();
	~Activity();
	void start();
	void update(std::chrono::microseconds pElapsed);
	
	std::string getName();
	eActType getType();
	eOrientation getOrientation();

	int getXp();// How is an activity grey ? Research, dev, hardwareInstall..

	void setAllowed(bool pAllowed);
	bool isAllowed();
	//bool isAllowed(Mission *mission = NULL, bool isMission = false);
	bool isFinished();
	bool isResearch();

	bool isRecon();
	bool isScan();
	bool isExploit();
	bool isPostExploit();

	bool isDev();
	bool isHardWare();
	bool isConference();
};

