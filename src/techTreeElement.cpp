#include "TechTreeElement.h"

TechTreeElement::TechTreeElement()
{
}

TechTreeElement::TechTreeElement(std::string pName)
{
	name = pName;
}


TechTreeElement::~TechTreeElement()
{
}

void TechTreeElement::addSon(TechTreeElement *pSon) {
	sons.push_back(pSon);
	pSon->setParent(this);
}

void TechTreeElement::setParent(TechTreeElement *pParent) { //Why not working with const ? 
	parent = pParent;
}

void TechTreeElement::setName(std::string pName) {
	name = pName;
}

std::string TechTreeElement::getName() {
	return name;
}

void TechTreeElement::displayAllChilds() {
	std::cout << "Element name: "<< name << " (" << sons.size() << ")" << std::endl;
	if (sons.size() != 0) {
		std::cout << name << " has the following sons: " << std::endl;
		for (int i = 0; i < sons.size(); i++) {
			std::cout << "\t";
			sons.at(i)->displayAllChilds();
		}
	}
	else
		std::cout << name << " has no sons" << std::endl;
}

void TechTreeElement::displayData(){
	std::cout << "Name: " << name << std::endl;
	std::cout << sons.size() << " sons: " << std::endl;
	for (int i = 0; i < sons.size(); i++) {
		std::cout << "\t - " << sons.at(i)->getName() << std::endl;
	}
}
