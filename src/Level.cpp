#include "Level.h"



Level::Level()
{
}

Level::Level(std::string pLabel, int pXp, int pId) {
	label = pLabel;
	xpForNext = pXp;
	levelNumber = pId;
}


Level::~Level()
{
}

//TODO : Create levels from Json file
std::ostream& operator<< (std::ostream& stream, Level &pLevel) {
	stream << pLevel.getLabel() << " (" << pLevel.getLevelXpForNext() << " till next level)" << std::endl;
	return stream;
}

int Level::getIndex() const { return levelNumber; }
std::string Level::getLabel() const { return label; }
int Level::getLevelXpForNext() const { return xpForNext; }
bool Level::isNull() {
	if (label.empty() || xpForNext == NULL || levelNumber == NULL) return true;
	else return false;
}

void Level::show() {
	std::cout << "Level " << levelNumber << std::endl;
	std::cout << "-> " << label << std::endl;
	std::cout << "XP for next level: " << xpForNext << std::endl;

}