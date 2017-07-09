#include "AbstractAttribute.h"

AbstractAttribute::~AbstractAttribute()
{
	for (auto elt : discoveredBy)
		delete elt;
}

bool AbstractAttribute::isDiscovered(Entity *pEntity)  const{
	auto discovered = false;
	if (pEntity != nullptr) {
		for (auto i = 0; i < discoveredBy.size(); i++) {
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