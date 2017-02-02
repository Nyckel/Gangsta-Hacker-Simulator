#pragma once
#include <vector>
#include <iostream>
#include <string>

class TechTreeElement
{
	//Will be created from json file
private:
	std::string name;

	TechTreeElement* parent;//Remove

	std::vector<TechTreeElement*> parents;
	std::vector<TechTreeElement*> sons;
	bool discovered;
public:
	TechTreeElement();
	TechTreeElement(std::string pName);
	~TechTreeElement();

	void addSon(TechTreeElement *pSon);
	void setParent(TechTreeElement *pParent);
	void setName(std::string pName);
	std::string getName();

	void displayAllChilds();
	void displayData();
};

