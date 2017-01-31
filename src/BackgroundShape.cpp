#include "BackgroundShape.h"
#include <iostream>



BackgroundShape::BackgroundShape(sf::Text* pText, int pPaddingX, int pPaddingY, sf::Color pColor){
	paddingX = pPaddingX;
	paddingY = pPaddingY;
	color = pColor;

	//std::cout << paddingX << paddingY << color.r << color.g << color.b << "YOLO"<<std::endl;
	if (pText != nullptr) {
		std::cout << pText->getGlobalBounds().width << "/" << pText->getGlobalBounds().height << std::endl;

		width = pText->getGlobalBounds().width + 2 * paddingX;
		height = pText->getGlobalBounds().height + 2 * paddingY;
		positionX = pText->getGlobalBounds().left - paddingX;
		positionY = pText->getGlobalBounds().top - paddingY;

		shape = sf::RectangleShape(sf::Vector2f(width, height));
		shape.setFillColor(color);
		shape.setPosition(positionX, positionY);
	}
	else {
		std::cout << "pText is null" << std::endl;
	}

}


BackgroundShape::BackgroundShape(sf::Vector2f pSize, sf::Vector2f pPadding, sf::Vector2f pPosition, sf::Color pColor) {
	paddingX = pPadding.x;
	paddingY = pPadding.y;

	width = pSize.x - 2*paddingX;
	height = pSize.y - 2*paddingY;

	positionX = pPosition.x + paddingX;
	positionY = pPosition.y + paddingY;
	
	shape = sf::RectangleShape(sf::Vector2f(width, height));
	shape.setFillColor(pColor);
	shape.setPosition(positionX, positionY);
}

BackgroundShape::~BackgroundShape()
{
}

void BackgroundShape::draw(sf::RenderWindow* pWindow) {
	pWindow->draw(shape);
}

void BackgroundShape::setPosition(int x, int y) {
	positionX = x + paddingX;
	positionY = y + paddingY;

	shape.setPosition(positionX, positionY);
}
void BackgroundShape::setColor(sf::Color pColor) {
	color = pColor;
}

void BackgroundShape::setSize(sf::Vector2f pSize) {
	width = pSize.x;
	height = pSize.y;
	updateShapeSize();
}

void BackgroundShape::setSizeWithoutPadding(sf::Vector2f pSize) {
	width = pSize.x + 2 * paddingX;
	height = pSize.y + 2 * paddingY;
	updateShapeSize();
}

void BackgroundShape::updateShapeSize() {
	shape.setSize(sf::Vector2f(width, height));
}
