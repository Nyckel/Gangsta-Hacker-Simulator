#pragma once
#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

#include "Entity.h";

template<typename T>
class EntityAttribute
{
	T value;
	std::string label;
	std::vector<Entity*> discoveredBy;

	public:
		EntityAttribute(T);

		void setValue(const T pValue);
		void setLabel(const std::string& pLabel);

		T*          getValue();
		std::string getLabel();
		bool isDiscoveredBy(Entity *pEntity);

		~EntityAttribute();
};