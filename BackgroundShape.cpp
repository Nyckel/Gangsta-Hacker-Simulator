#include "BackgroundShape.h"



BackgroundShape::BackgroundShape(sf::Text* pText, int pPaddingX, int pPaddingY, sf::Color pColor){
	paddingX = pPaddingX;
	paddingY = pPaddingY;
	color = pColor;

	width = pText->getGlobalBounds().width + 2 * paddingX;
	height = pText->getGlobalBounds().height + 2 * paddingY;
	positionX = pText->getGlobalBounds().left - paddingX;
	positionY = pText->getGlobalBounds().top - paddingY;

	shape = sf::RectangleShape(sf::Vector2f(width, height));
	shape.setFillColor(color);
	shape.setPosition(positionX, positionY);
}


BackgroundShape::~BackgroundShape()
{
}

void BackgroundShape::draw(sf::RenderWindow* pWindow) {
	pWindow->draw(shape);
}

void BackgroundShape::setPosition(int x, int y) {
	positionX = x;
	positionY = y;

	shape.setPosition(positionX, positionY);
}

