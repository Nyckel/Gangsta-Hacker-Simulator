#include "Attribute.h"


Attribute::Attribute()
{
}
Attribute::Attribute(int pValue) {
	type = integer;
	intValue = pValue;
}
Attribute::Attribute(std::string pValue) {
	type = string;
	stringValue = pValue;
}
Attribute::Attribute(int pXp, std::string pFilename) {
	/*std::cout << "Creating level attribute" << std::endl;*/
	//TODO parse json file, get first level where "next" > pXp
	Json::Value root;
	Json::Reader reader;
	std::ifstream file(pFilename, std::ifstream::binary);
	type = level;
	file >> root;
	if (pFilename == "levels.json") {
		if (root["levels"] != NULL) {
			//std::cout << "ici";
			int i = 0;
			bool levelFound = false;
			while (i < root["levels"].size() && !levelFound) {
				if (root["levels"][std::to_string(i + 1)]["next"] > pXp) {
					Json::Value currentLevel = root["levels"][std::to_string(i + 1)];
					levelFound = true;
					//std::cout << "level found" << currentLevel["label"].asString() << currentLevel["next"].asInt() << i+1;
					levelValue = Level(currentLevel["label"].asString(), currentLevel["next"].asInt(), i+1);
				}

				i++;
			}
		}
	}
}
Attribute::Attribute(eType pType, int pIntValue, std::string pString){
	type = pType;
	switch (type) {
	case integer:
	case money:
		intValue = pIntValue;
		break;
	case string:
		stringValue = pString;
		break;
	}
}


Attribute::~Attribute()
{
}

void Attribute::setValue(int pValue) {
	if (type != integer) type = integer;
	intValue = pValue;
}
void Attribute::setValue(std::string pValue) {
	if (type != string) type = string;
	stringValue = pValue;
}

std::ostream& operator<< (std::ostream& stream, Attribute &pAttr) {
	switch (pAttr.type) {
	case string:
		//return pAttr->getStringValue();
		stream << pAttr.stringValue;
		break;
	case integer:
		stream << pAttr.intValue;
		break;
	case level:
		stream << pAttr.getLevelIndex() << " - " << pAttr.getLevelLabel();
		break;
	}
	return stream;
}

enum eType Attribute::getType() { return type; }
std::string Attribute::getStringValue() { return stringValue;  }
int Attribute::getIntValue() { return intValue; }
bool Attribute::empty() { return stringValue.empty(); }


bool operator> (const int &nbA, Attribute &attr) {
	if (attr.getType() == integer && attr.getIntValue() != NULL) {
		return (attr.getIntValue() > nbA);
	}
	else return NULL;
}

bool operator< (const int &nbA, Attribute &attr) {
	if (attr.getType() == integer && attr.getIntValue() != NULL) {
		return (attr.getIntValue() < nbA);
	}
	else return NULL;
}

std::string Attribute::getLevelLabel() {
	if (!levelValue.isNull()) {
		return levelValue.getLabel();
	}
	else return std::string();
}
int Attribute::getLevelIndex() {
	return levelValue.getIndex();
}
int Attribute::getLevelXpForNext() {
	if (!levelValue.isNull()) {
		return levelValue.getLevelXpForNext();
	}
	else {
		std::cout << "Asking lacking xp on a null Level object" << std::endl;
		return NULL;
	}
}
void Attribute::levelUpdate(int pExpEarned, std::string pFilename) {
	if (!levelValue.isNull()) {
		Json::Value root;
		Json::Reader reader;
		std::ifstream file(pFilename, std::ifstream::binary);
		file >> root;
		if (pFilename == "levels.json") {
			if (root["levels"] != NULL) {
				int i = 0;
				bool levelFound = false;
				while (i < root["levels"].size() && !levelFound) {
					if (root["levels"][std::to_string(i + 1)]["next"] > pExpEarned) {
						Json::Value currentLevel = root["levels"][std::to_string(i + 1)];
						levelFound = true;
						levelValue = Level(currentLevel["label"].asString(), currentLevel["next"].asInt(), i + 1);
					}

					i++;
				}
			}
		}
	}
}

bool Attribute::isDiscovered(Entity *pEntity) {
	bool discovered = false;
	if (pEntity != NULL) {
		for (int i = 0; i < discoveredBy.size(); i++) {
			if (discoveredBy.at(i) == pEntity)
				discovered = true;
		}
	}
	else {
		std::cout << "Checking if an attribute is discovered by a NULL Entity object" << std::endl;
		system("pause");
	}
	return discovered;
}