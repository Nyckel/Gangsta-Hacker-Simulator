#pragma once
#include <vector>
#include <map>
#include <string>

#include "Component.h"
#include "Label.h"
#include "UIButton.h"
#include "SFML\Graphics.hpp"

class Menu : public Component
{
private:

	Label title;
	sf::Vector2f buttonSize;
	sf::Vector2f menuSize;
	sf::Vector2f position;
	int selectedItemIndex;
	int interButtonPadding;
	std::vector<UIButton> options;


public:
	Menu();
	Menu(std::vector<std::string> pMap, std::string pMenuName, sf::Font pFont, sf::Color pColor, sf::Vector2f pSize, int pCharacterSize, int pPadding, sf::Vector2f pPosition);
	~Menu();

	virtual void draw(sf::RenderWindow* pWindow);
	void build();

	std::vector<UIButton> getMenuButtons();
	//void addButton(UIButton *pButton);
	virtual bool isCursorHover(sf::Vector2f pCursorPosition);
};

