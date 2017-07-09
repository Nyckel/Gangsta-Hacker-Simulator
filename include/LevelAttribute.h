#pragma once

#include "AbstractAttribute.h"
#include "Level.h"
#include "json/json.h"
#include <fstream>

class LevelAttribute :
	public AbstractAttribute
{
	Level value;
public:
	LevelAttribute() {};
	LevelAttribute(const Level& pVal) : value{ pVal } {}
	LevelAttribute(const int pVal, const std::string fileName);
	void setValue(const Level& pVal) { value = pVal; }
	Level getValue() const { return value; }
	~LevelAttribute() {};

	std::string getLabel() const { return value.getLabel(); }
	int getIndex() const { return value.getIndex(); }
	int getLevelXpForNext() const { return value.getLevelXpForNext(); }

	void update(const int pExpEarned, const std::string pFilename);
	friend std::ostream& operator<< (std::ostream& stream, const LevelAttribute& pAttr) {
		stream << pAttr.value.getIndex() << " - " << pAttr.value.getLabel(); return stream;
	}
};

