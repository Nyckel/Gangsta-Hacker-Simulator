#include "Component.h"



Component::Component()
{
	name = "Dummy";
}


Component::~Component()
{
}

bool Component::hasHoverState()
{
	return hashoverstate;
}

void Component::hoverState(){
	isinhoverstate = true;
}
void Component::normalState() {
	isinhoverstate = false;
}
bool Component::isInHoverState() {
	return isinhoverstate;
}

bool Component::isCursorHover(sf::Vector2f pCursorPosition)
{
	//For debug purpose
	//std::cout << "In function isCursorHover of Component" << std::endl;
	return false;
}
bool Component::isClickable() { return clickable; }
void Component::setClickable(bool pClickable) { clickable = pClickable; }
void Component::draw(sf::RenderWindow * pWindow)
{
	//For debug purpose
	//std::cout << "In function draw of Component" << std::endl;
}

std::string Component::getName() {
	return name;
}
void Component::setName(std::string pName) {
	std::cout << "Setting name of elt to " << pName << std::endl;
	name = pName;
}
void Component::setColor(sf::Color pColor) {

}


bool Component::hasChildElements() {
	return (&childElements != nullptr && childElements.size() > 0);
}
void Component::addChildrenElement(Component* pComp) {
	childElements.push_back(pComp);
}
std::vector<Component*> Component::getChildElements() {
	return childElements;
}

void Component::getClickableAndHoveredComponents(sf::Vector2f mousePosition, std::vector<Component*>* hoveredComponents, Component** hoveredClickableComponent) {
	if (this->isCursorHover(mousePosition)) {
		hoveredComponents->push_back(this);
		if (this->hasHoverState()) {
			this->hoverState();
		}
		if (this->isClickable()) {
			*hoveredClickableComponent = this;
		}
		else {
		}
	}
	if (this->hasChildElements()) {
		for (Component* comp : this->childElements) {
			comp->getClickableAndHoveredComponents(mousePosition, hoveredComponents, hoveredClickableComponent);
		}
	}
}

void Component::printName() {
	std::cout << "Action caaaaaaallllleeed ! !" << std::endl;
}