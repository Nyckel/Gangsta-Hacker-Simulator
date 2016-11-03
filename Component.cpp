#include "Component.h"
#include <iostream>



Component::Component()
{
}


Component::~Component()
{
}

bool Component::isCursorHover(sf::Vector2f pCursorPosition)
{
	//For debug purpose
	std::cout << "In function isCursorHover of Component" << std::endl;
	return false;
}

void Component::draw(sf::RenderWindow * pWindow)
{
	//For debug purpose
	std::cout << "In function draw of Component" << std::endl;
}

std::string Component::getName() {
	return name;
}
void Component::setName(std::string pName) {
	name = pName;
}