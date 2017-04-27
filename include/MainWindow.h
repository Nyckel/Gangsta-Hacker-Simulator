#pragma once
#include <vector>
#include <iostream>
#include <stdlib.h>
#include <functional>
#include <string>
#include "Component.h"
#include "UIButton.h"
#include "SFML\Graphics.hpp"
#include "Label.h"
#include "Menu.h"


class MainWindow
{

private:
	int nbElementsInHoverState;
	Component* hoveredClickableComponent;
	Component* dummyComponent;
	std::vector<Component*> hoveredComponents;
	sf::RenderWindow* window;
	std::vector<Component*> components;
	std::vector<std::vector<Component*>> componentsAtLevel;

	void removeFromHoveredList(Component*);
public:
	MainWindow();
	~MainWindow();
	void update();
	void close();
	void addComponent(Component *pComp, unsigned int zIndex = 0);
	void hoverElement(Component* elt);
	void unHoverElement(Component* elt);
	//int createMainMenu();
	Menu* createMainMenu();
	Label* createTitle();
	void handleEvents();
	std::vector<sf::Event> getEvents();
	std::vector<Component*>* getHoveredComponents();
	Component** getHoveredClickable();
	Component* getDummyComponent();
	std::vector<std::vector<Component*>>* getComponentsByLevel();
};

