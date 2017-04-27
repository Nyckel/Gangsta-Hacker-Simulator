#include "Activity.h"



Activity::Activity()
{
	name = "Default activity name";
	finished = false;
	//Overload with character skills to compute duration
	xp = 15;
	orientation = Black;
	allowed = false;
	duration = std::chrono::duration_cast<std::chrono::microseconds>(std::chrono::seconds(5));
	std::cout << "Activity will last " << duration.count() << std::endl;
	//system("pause");
}


Activity::~Activity()
{
}

void Activity::start() {//Add computation of duration...
	startTime = std::chrono::steady_clock::now();
	//std::cout << "Starting activity" << std::endl;
	elapsed = std::chrono::microseconds(0);
}
void Activity::update(std::chrono::microseconds pElapsed) {
	elapsed += std::chrono::duration_cast<std::chrono::microseconds>(std::chrono::steady_clock::now() - startTime);
	//elapsed += pElapsed;
	std::cout << "Updating activity  (+" << pElapsed.count() << ") to " << elapsed.count() << std::endl;
	//system("pause");
	//Random things that can happen in the activity, bug in dev, new thing discovered while recon...
	

	//Check if activity is not finished
	if (elapsed > duration) {
		finished = true;
		std::cout << "Activity finished" << std::endl;
		
		//Popup or notif to player
		//Update tech tree or mission or...
	}
}

std::string Activity::getName() { return name; }
eActType Activity::getType(){ return typeAct;}
eOrientation Activity::getOrientation() { return orientation; }

int Activity::getXp() { return xp; }

void Activity::setAllowed(bool pAllowed) { allowed = pAllowed; }
bool Activity::isAllowed() { return allowed; }
/*bool Activity::isAllowed(Mission *mission, bool isMission) { // Remove Mission param
	if (isMission) {
		//Check on element given in param or on a company 
		// Go through allowed targets
		for (int i = 0; i < allowedTargets.size(); i++) {

		}
	}
	//Else check if action is offensive
}*/
bool Activity::isFinished() { return finished; }

bool Activity::isRecon() { return (typeAct == Recon); }
bool Activity::isScan() { return (typeAct == Scan); }
bool Activity::isExploit() { return (typeAct == Exploit); }
bool Activity::isPostExploit() { { return (typeAct == PostExploit); } }

bool Activity::isResearch() { return (typeAct == Research); }
bool Activity::isDev() { return (typeAct == dev); }
bool Activity::isHardWare() { return (typeAct == hardwareInstall); }
bool Activity::isConference() { return (typeAct == conf); }
std::chrono::microseconds Activity::getTimeElapsed() { return elapsed; }
