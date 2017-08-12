#pragma once
#include <map>
#include <iostream>
#include "SFML\Graphics.hpp"
#include "Component.h"


class BackgroundShape : public Component
{
private:
	int width;
	int height;
	int positionX;
	int positionY;
	int paddingX;
	int paddingY;
	sf::Color color;

	sf::RectangleShape shape;

	////std::vector<sf::RectangleShape, int> shapes;
	//std::map<sf::RectangleShape,int> shapes;

	void updateShapeSize();

public:

	BackgroundShape(sf::Text* pText, int pPaddingX, int pPaddingY, sf::Color pColor);

	BackgroundShape(sf::Vector2f pSize, sf::Vector2f pPadding, sf::Vector2f pPosition, sf::Color pColor);

	~BackgroundShape();

	void draw(sf::RenderWindow& pWindow) const;
	void setPosition(int x, int y);
	void setColor(sf::Color pColor);
	void setSize(sf::Vector2f pSize);
	void setSizeWithoutPadding(sf::Vector2f pSize);
	//void setPadding(int pPadding);
	//int getPadding();

};

