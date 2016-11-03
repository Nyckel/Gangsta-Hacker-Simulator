#include "Background.h"


Background::Background() {

}

Background::Background(sf::Text* pText) {

	BackgroundShape shape1(pText, 20, 20, sf::Color::Black);
	BackgroundShape shape2(pText, 18, 18, sf::Color(52, 73, 94));

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