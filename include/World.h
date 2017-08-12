#pragma once
#include <vector>
#include <string>
#include <memory>
#include "Company.h"
#include "Mission.h"

class World
{
	std::vector<Company> playableCompanies;
	std::vector<std::unique_ptr<Company>> organisations;
	std::vector<std::unique_ptr<Character>> peopleAlone;
	std::vector<Mission> missions;

	// Maybe just put vectors (no unique ptr) and return references

public:

	void createFirstCompany();
	void loadMissions();

};

