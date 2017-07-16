#pragma once
#include <vector>
#include <memory>
#include "Company.h"
#include "Mission.h"

class World
{
	std::vector<Company*> organisations;
	std::vector<Character*> peopleAlone;
	std::vector<std::shared_ptr<Mission>> missions;

public:
	World();
	World(World&&) = default;
	~World();

	void addOrganisation(Company* pComp);

	std::vector<Company*> getOrganisations();
};

