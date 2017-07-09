#pragma once
#include <iostream>
#include <vector>
#include "Entity.h"

class AbstractAttribute
{
	std::vector<Entity*> discoveredBy;

public:
	virtual ~AbstractAttribute();
	bool isDiscovered(Entity *pEntity) const;
};