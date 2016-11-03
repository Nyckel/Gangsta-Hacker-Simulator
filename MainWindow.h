#pragma once
#include <vector>
#include "Component.h"
#include "SFML\Graphics.hpp"

class MainWindow
{

private:
	sf::RenderWindow* window;
	std::vector<Component*> components;
public:
	MainWindow();
	~MainWindow();
	void update();
	void addComponent(Component *pComp);
	int showMainMenu();
	void display();

private:
	int getMenuChoice();
};

