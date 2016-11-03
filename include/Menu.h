#pragma once
#include <vector>

#include "Component.h"
#include "Label.h"
#include "MenuOption.h"
#include "SFML\Graphics.hpp"

class Menu : public Component
{
private:

	Label title;
	int selectedItemIndex;
	std::vector<MenuOption> options;

public:
	Menu();
	~Menu();

	void draw(sf::RenderWindow* pWindow);
};

