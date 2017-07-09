#pragma once
#include <vector>
#include <json/json.h>
#include <fstream>
#include <iostream>

#include "Entity.h"
#include "Level.h"
//#include "Character.h"

enum eType {integer, string, level, money};

class Attribute
{
private:

	enum eType type;
	int intValue;
	std::string stringValue;
	std::vector<Entity*> discoveredBy;
	Level levelValue;

public:
	Attribute();
	Attribute(int pValue);
	Attribute(std::string pValue);
	Attribute(int pXp, std::string pFilename);//Constructor for level
	Attribute(eType pType, int pIntValue=0, std::string pString="");
	~Attribute();

	void setValue(int pValue);
	void setValue(std::string pValue);
	friend std::ostream& operator<< (std::ostream& stream, Attribute &pAttr);
	//Overload comparison operators
	/*inline bool operator>(const int nbA);*/
	friend bool operator> (const int &nbA, Attribute &attr);
	friend bool operator< (const int &nbA, Attribute &attr);

	enum eType getType();
	int getIntValue();
	bool empty();
	std::string getStringValue();
	
	std::string getLevelLabel();
	int Attribute::getLevelIndex();
	int getLevelXpForNext();
	void levelUpdate(int pExpEarned, std::string pFilename);

	bool isDiscovered(Entity *pEntity);

};

