#include "World.h"



World::World()
{
}


World::~World()
{
	for (auto elt : organisations)
		delete elt;
	for (auto elt : peopleAlone)
		delete elt;
}


void World::addOrganisation(Company* pComp) {
	organisations.push_back(pComp);
}

std::vector<Company*> World::getOrganisations() {
	return organisations;
}