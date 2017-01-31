#include "Background.h"


Background::Background() {

}

Background::Background(sf::Text* pText) {

	BackgroundShape shape1(pText, 20, 20, sf::Color::Black);
	BackgroundShape shape2(pText, 18, 18, sf::Color(52, 73, 94));

	addShape(shape1);
	addShape(shape2);
}

Background::Background(sf::Text* pText, sf::Color pColor) {

	BackgroundShape shape1(pText, 20, 20, sf::Color::Black);
	BackgroundShape shape2(pText, 18, 18, pColor);

	addShape(shape1);
	addShape(shape2);
}
Background::Background(sf::Text* pText, sf::Color pBackColor, sf::Color pRectColor) {

	BackgroundShape shape1(pText, 20, 20, pRectColor);
	BackgroundShape shape2(pText, 18, 18, pBackColor);

	addShape(shape1);
	addShape(shape2);
}


Background::Background(sf::Text* pText, sf::Color pBackColor, sf::Color pRectColor, sf::Vector2f pSize, sf::Vector2f pPosition) {
	size = pSize;
	position = pPosition;
	padding.x = (size.x - pText->getGlobalBounds().width) / 2;
	padding.y = (size.y - pText->getGlobalBounds().height) / 2;
	BackgroundShape shape1(size, sf::Vector2f(0, 0), position, pRectColor);
	BackgroundShape shape2(size, sf::Vector2f(2, 2), position, pBackColor);

	addShape(shape1);
	addShape(shape2);
}

Background::~Background()
{
}

void Background::draw(sf::RenderWindow* pWindow) {
	for (int i = 0; i < shapes.size(); i++) {
		shapes.at(i).draw(pWindow);
	}
}

void Background::addShape(BackgroundShape pShape) {
	shapes.push_back(pShape);
}

void Background::setPosition(int x, int y) {
	for (int i = 0; i < shapes.size(); i++) {
		shapes.at(i).setPosition(x, y);
	}
}


void Background::setColors(sf::Color pBack, sf::Color pRect) {
	shapes.at(0).setColor(pBack);
	shapes.at(1).setColor(pRect);
}

void Background::setSize(sf::Vector2f pSize) {
	width = pSize.x;
	height = pSize.y;
	for (BackgroundShape iShape : shapes) {
		iShape.setSizeWithoutPadding(pSize);
	}
}

sf::Vector2f Background::getTextPosition() {
	sf::Vector2f textPosition;
	//std::cout << "Position in background.getTextPosition()" << position.x << "/" << position.y << std::endl;
	//std::cout << "Padding in background " << padding.x << "/" << padding.y << std::endl;
	//padding.x = 0;
	//padding.y = 0;
	textPosition.x = position.x + padding.x;
	textPosition.y = position.y + padding.y;

	return textPosition;
}

bool Background::isCursorHover(sf::Vector2f pCursorPosition) {
	//std::cout << "In function isCursorHover of background " << std::endl;
	return (pCursorPosition.x >= position.x && pCursorPosition.x <= position.x + size.x && pCursorPosition.y >= position.y && pCursorPosition.y <= position.y + size.y);
}