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

	std::chrono::microseconds duration;
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

	bool started;

	std::string getName() const;
	eActType getType() const;
	eOrientation getOrientation();

	int getXp() const { return xp; }// How is an activity grey ? Research, dev, hardwareInstall..
	std::chrono::microseconds getTimeElapsed() const { return elapsed; }

	void setFinished(bool f) { finished = {f}; }

	void setAllowed(bool pAllowed);
	bool isAllowed() const { return allowed; }
	//bool isAllowed(Mission *mission = NULL, bool isMission = false);

	bool isFinished() const { return finished; }
	bool isResearch() const { return typeAct == Research; }

	bool isRecon() const { return typeAct == Recon; }
	bool isScan() const { return typeAct == Scan; }
	bool isExploit() const { return typeAct == Exploit; }
	bool isPostExploit() const { return typeAct == PostExploit; }

	bool isDev() const { return typeAct == dev; }
	bool isHardWare() const { return typeAct == hardwareInstall; }
	bool isConference() const { return typeAct == conf; }

	bool isStarted() const { return started; }
};

