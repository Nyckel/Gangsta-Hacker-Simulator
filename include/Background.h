#pragma once
#include "BackgroundShape.h"
#include "SFML\Graphics.hpp"
#include "Component.h"

class Background: public Component
{

private:
	int width;
	int height;
	int positionX;
	int positionY;
	std::vector<BackgroundShape> shapes;

public:
	Background();
	Background(sf::Text* pText);
	~Background();

	void draw(sf::RenderWindow* pWindow);
	void setPosition(int x, int y);

private:
	void addShape(BackgroundShape pShape);
};

