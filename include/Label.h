#pragma once
#include <string>
#include "Component.h"
#include "Background.h"
#include "SFML\Graphics.hpp"

class Label : public Component
{
private:
	sf::Text text;
	sf::Font font;
	Background background;
	int paddingX;
	int paddingY;


public:
	Label();
	Label(sf::Vector2f pPosition, std::string pString = "Default string", int characterSize = 15);
	Label(sf::Font pFont, sf::Vector2f pPosition, std::string pString = "Default string", int characterSize = 15);
	Label(sf::Font pFont, sf::Color pColor, sf::Vector2f pPosition, std::string pString, int characterSize);
	Label(sf::Font pFont, sf::Color pColor, std::string pString, int characterSize, sf::RenderWindow* pWindow);


	~Label();

	void draw(sf::RenderWindow *pWindow);
	void addBackgroundRect();
	void setPosition(float x, float y);
	sf::Vector2f getPosition();
	sf::Vector2f getPadding();
	void setPadding(int x, int y);

	bool isCursorHover(sf::Vector2f pCursorPosition);

};

