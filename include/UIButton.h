#pragma once
#include "Component.h"
#include "Label.h"

class UIButton : public Label
{

private:

	sf::Vector2f size;
	sf::Vector2f position;
	sf::Vector2f textPosition;

public:
	//void clickAction(UIButton*)();
	UIButton();

	UIButton(sf::Vector2f pPosition, std::string pString = "Default string", int characterSize = 15);
	UIButton(sf::Font *pFont, sf::Vector2f pPosition, std::string pString = "Default string", int characterSize = 15);
	UIButton(sf::Font *pFont, sf::Color pColor, std::string pString, int characterSize, sf::RenderWindow* pWindow);

	UIButton(sf::Font *pFont, sf::Color pColor, sf::Vector2f pPosition, sf::Vector2f pSize, std::string pString, int characterSize);


	void setSize(sf::Vector2f pSize);
	void updateInnerPositions();
	void addBackgroundRect(sf::Color pBack, sf::Color pRect);
	void addHoverState(sf::Color pFontColor, sf::Color pBack, sf::Color pRect);
	void printName();
	~UIButton();
};

