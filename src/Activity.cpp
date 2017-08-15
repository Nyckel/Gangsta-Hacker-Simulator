#include "Activity.h"



Activity::Activity()
{
	name = { "Default activity name" };
	finished = false;
	//Overload with character skills to compute duration
	xp = 15;
	orientation = Black;
	allowed = false;
	duration = std::chrono::duration_cast<std::chrono::microseconds>(std::chrono::seconds(5));
	//std::cout << "Activity " << name << "will last " << duration.count() << std::endl;
	//system("pause");
	elapsed = std::chrono::microseconds(0);
	startTime = std::chrono::steady_clock::now();

	typeAct = Research;
	
	xpRecon = {};
	xpScan = {};
	xpExploit = {};
	xpPostExploit = {};

	started = false;
}


Activity::~Activity()
{
}

void Activity::start() {

	startTime = std::chrono::steady_clock::now();
	elapsed = std::chrono::microseconds(0);
	started = true;
}
void Activity::update(std::chrono::microseconds pElapsed) {

	elapsed += pElapsed;
	//std::cout << "Updating activity  (+" << pElapsed.count() << ") to " << elapsed.count() << std::endl;
	//std::cout << "Time left: " << duration.count() - elapsed.count() << std::endl;

	//Random things that can happen in the activity,
	// bug in dev, new thing discovered while recon...
	

	//Check if activity is not finished
	if (elapsed > duration) {
		finished = true;
		std::cout << "Activity finished" << std::endl;
		
		//Popup or notif to player
		//Update tech tree or mission or...
	} else
	{
		//std::cout << "Activity not finished" << std::endl;
	}
}

std::string Activity::getName() const { return name; }
eActType Activity::getType() const { return typeAct;}
eOrientation Activity::getOrientation() { return orientation; }

void Activity::setAllowed(bool pAllowed) { allowed = pAllowed; }
/*bool Activity::isAllowed(Mission *mission, bool isMission) { // Remove Mission param
	if (isMission) {
		//Check on element given in param or on a company 
		// Go through allowed targets
		for (int i = 0; i < allowedTargets.size(); i++) {

		}
	}
	//Else check if action is offensive
}*/
