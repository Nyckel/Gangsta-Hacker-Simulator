#pragma once
#include <vector>
#include "Component.h"
#include "UIButton.h"
#include "SFML\Graphics.hpp"


class MainWindow
{

private:
	int nbElementsInHoverState;
	Component* hoveredClickableComponent;
	std::vector<Component*> hoveredComponents;
	sf::RenderWindow* window;
	std::vector<Component*> components;
	std::vector<std::vector<Component*>> componentsAtLevel;
public:
	MainWindow();
	~MainWindow();
	void update();
	void addComponent(Component *pComp, unsigned int zIndex = 0);
	int showMainMenu();
	void handleEvents();

};

