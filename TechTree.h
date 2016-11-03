#pragma once
#include <string>
#include <vector>
#include "TechTreeElement.h"
#include "include\json\json.h"


//One file for the standard techtree and the info about player advancement is in  gamesave
class TechTree
{
private:
	int lastElementId;
	std::vector<TechTreeElement*> tree;

public:
	TechTree();
	TechTree(std::string filename);
	~TechTree();

	TechTreeElement* createElement(Json::Value pElement);
	void createElement(Json::Value pJsonElement, TechTreeElement* pElement);
	void display();
};

