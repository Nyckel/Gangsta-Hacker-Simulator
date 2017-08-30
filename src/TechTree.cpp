#include "TechTree.h"



TechTree::TechTree()
{
	lastElementId = 0;
}

TechTree::TechTree(std::string pFilename) {
	lastElementId = 0;
#pragma region JSON
	//std::cout << "Starting techtree creation from json... (file: "<< pFilename << " )" << std::endl;
	Json::Value root;
	Json::Reader reader;
	std::ifstream file(pFilename, std::ifstream::binary);
	file >> root;
	const Json::Value elements = root["elements"];//["firstname"];// ["name"];
	for (int i = 0; i < elements.size(); i++) {
		tree.push_back(createElement(elements[i]));
	}
	
#pragma endregion


}

TechTree::~TechTree()
{
}

TechTreeElement* TechTree::createElement(Json::Value pElement){// Or do function with pointer to element in parameter
	//Fill fields with data of this elt 
	TechTreeElement *newElement = new TechTreeElement;
	newElement->setName(pElement["name"].asString());
	Json::Value eltSons = pElement["sons"];
	if (eltSons != NULL) {
		for (int i = 0; i < eltSons.size(); i++) {
			newElement->addSon(createElement(eltSons[i]));
		}
	};
	return newElement;
}


void TechTree::createElement(Json::Value pJsonElement, TechTreeElement* pElement) {
	pElement->setName(pJsonElement["name"].asString());
	Json::Value eltSons = pJsonElement["sons"];
	if (eltSons != nullptr) {
		//std::cout << "Element " << newElement.getName() << " has " << sons.size() << " sons" << std::endl;
		for (int i = 0; i < eltSons.size(); i++) {
			TechTreeElement* newSon = new TechTreeElement;
			createElement(eltSons[i], newSon);
			pElement->addSon(newSon);
			//newElement.displayAllChilds();
			//system("pause");
		}
	};
}

void TechTree::display() {
	std::cout << "There are " << tree.size() << " main entries in the tree" << std::endl;
	for (int i = 0; i < tree.size(); i++) {
		tree.at(i)->displayAllChilds();
	}
}
