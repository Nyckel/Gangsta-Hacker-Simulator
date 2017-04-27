#pragma once
#include <string>
#include <iostream>

#include "Component.h"
#include "Background.h"
#include "SFML\Graphics.hpp"

class Label : public Component
{
protected:
	sf::Text text;
	sf::Text overText;
	sf::Font* font;
	sf::Color color;
	Background background;
	Background overState;
	int paddingX;
	int paddingY;

public:
	Label();
	Label(sf::Vector2f pPosition, std::string pString = "Default string", int characterSize = 15);
	Label(sf::Font *pFont, sf::Vector2f pPosition, std::string pString = "Default string", int characterSize = 15);
	Label(sf::Font *pFont, sf::Color pColor, sf::Vector2f pPosition, std::string pString, int characterSize);
	Label(sf::Font *pFont, sf::Color pColor, std::string pString, int characterSize, sf::RenderWindow* pWindow);


	~Label();

	virtual void draw(sf::RenderWindow *pWindow);

	void addBackgroundRect();
	void addBackgroundRect(sf::Color pBack, sf::Color pRect);
	void setBackgroundColors(sf::Color  pBack, sf::Color pRect);

	void addHoverState();
	void addHoverState(sf::Color pBack, sf::Color pRect);
	void addHoverState(sf::Color pFontColor, sf::Color pBack, sf::Color pRect);
	void setHoverColors(sf::Color  pBack, sf::Color pRect);
	void setHoverColors(sf::Color pTextColor, sf::Color  pBack, sf::Color pRect);

	void setPosition(float x, float y);
	sf::Vector2f getPosition();
	sf::Vector2f getPadding();
	void setPadding(int x, int y);
	std::string getText();


	virtual bool isCursorHover(sf::Vector2f pCursorPosition);

};

