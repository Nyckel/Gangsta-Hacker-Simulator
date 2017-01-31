#pragma once
#include "BackgroundShape.h"
#include "SFML\Graphics.hpp"
#include "Component.h"

class Background: public Component
{

private:

	sf::Vector2f size;
	sf::Vector2f padding;
	sf::Vector2f position;

	int width;
	int height;
	int positionX;
	int positionY;
	std::vector<BackgroundShape> shapes;

public:
	Background();
	Background(sf::Text* pText);
	Background(sf::Text* pText, sf::Color pColor);
	Background(sf::Text* pText, sf::Color pBackColor, sf::Color pRectColor);
	Background(sf::Text* pText, sf::Color pBackColor, sf::Color pRectColor, sf::Vector2f pSize, sf::Vector2f pPosition);
	~Background();

	virtual void draw(sf::RenderWindow* pWindow);
	void setPosition(int x, int y);
	void setColors(sf::Color pBack, sf::Color pRect);
	void setSize(sf::Vector2f pSize);
	sf::Vector2f getTextPosition();
	virtual bool isCursorHover(sf::Vector2f pCursorPosition);


private:
	void addShape(BackgroundShape pShape);
};

