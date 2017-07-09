#include "LevelAttribute.h"

LevelAttribute::LevelAttribute(const int pVal, const std::string fileName)
{
	/*std::cout << "Creating level attribute" << std::endl;*/
	//TODO parse json file, get first level where "next" > pXp
	Json::Value root;
	Json::Reader reader;
	std::ifstream file(fileName, std::ifstream::binary);

	file >> root;
	if (fileName == "ressources/jsons/levels.json") {
		if (&root["levels"] != nullptr) {
			int i = 0;
			bool levelFound = false;
			while (i < root["levels"].size() && !levelFound) {
				if (root["levels"][std::to_string(i + 1)]["next"] > pVal) {
					Json::Value currentLevel = root["levels"][std::to_string(i + 1)];
					levelFound = true;
					//std::cout << "level found" << currentLevel["label"].asString() << currentLevel["next"].asInt() << i+1;
					value = Level(currentLevel["label"].asString(), currentLevel["next"].asInt(), i + 1);
				}

				i++;
			}
		}
		else {
			std::cout << "Couldn't read json file" << std::endl;
		}
	}
}

void LevelAttribute::update(const int pExpEarned, const std::string pFilename)
{
	Json::Value root;
	Json::Reader reader;
	std::ifstream file(pFilename, std::ifstream::binary);
	file >> root;
	if (pFilename == "levels.json") {
		if (root["levels"] != nullptr) {
			auto i = 0;
			auto levelFound = false;
			while (i < root["levels"].size() && !levelFound) {
				if (root["levels"][std::to_string(i + 1)]["next"] > pExpEarned) {
					auto currentLevel = root["levels"][std::to_string(i + 1)];
					levelFound = true;
					value = Level(currentLevel["label"].asString(), currentLevel["next"].asInt(), i + 1);
				}

				i++;
			}
		}
	}
}
