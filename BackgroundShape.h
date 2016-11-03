#pragma once
#include <map>
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

public:

	BackgroundShape(sf::Text* pText, int pPaddingX, int pPaddingY, sf::Color pColor);
	~BackgroundShape();

	void draw(sf::RenderWindow* pWindow);
	void setPosition(int x, int y);
	//void setPadding(int pPadding);
	//int getPadding();

};

