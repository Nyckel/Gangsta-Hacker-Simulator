#include "Label.h"
#include <iostream>


Label::Label() {
	background = NULL;
}

Label::Label(sf::Vector2f pPosition, std::string pString, int characterSize) {
	paddingX = 0;
	paddingY = 0;
	
	font = sf::Font();
	font.loadFromFile("ressources/fonts/nasalization-rg.ttf");
	text = sf::Text(pString, font);
	text.setFillColor(sf::Color::Black);
	text.setPosition(pPosition);

}
Label::Label(sf::Font pFont, sf::Vector2f pPosition, std::string pString, int characterSize) {
	paddingX = 0;
	paddingY = 0;
	
	font = sf::Font(pFont);
	text = sf::Text(pString, font);
	text.setCharacterSize(characterSize);
	text.setPosition(pPosition);
}
Label::Label(sf::Font pFont, sf::Color pColor, sf::Vector2f pPosition, std::string pString, int characterSize) {
	paddingX = 0;
	paddingY = 0;

	font = sf::Font(pFont);
	text = sf::Text(pString, font);
	text.setFillColor(pColor);
	text.setCharacterSize(characterSize);
	text.setPosition(pPosition);
}
Label::Label(sf::Font pFont, sf::Color pColor, std::string pString, int characterSize, sf::RenderWindow* pWindow) {
	paddingX = 0;
	paddingY = 0;
	
	font = sf::Font(pFont);
	text = sf::Text(pString, font);
	text.setFillColor(pColor);
	text.setCharacterSize(characterSize);

	int positionX = pWindow->getSize().x / 2 - text.getGlobalBounds().width / 2;
	int positionY = pWindow->getSize().y / 2 - text.getGlobalBounds().height / 2;

	text.setPosition(positionX, positionY);
}


Label::~Label()
{
}

void Label::draw(sf::RenderWindow *pWindow) {
	//Draw other things...
	if (&background != nullptr) {
		background.draw(pWindow);
	}
	if (!text.getString().isEmpty()) {
		pWindow->draw(text);
	}
	else {
		std::cout << "label text is null" << std::endl;
	}
}


void Label::addBackgroundRect() {
	background = Background(&text);
}


void Label::setPosition(float x, float y) {
	// Move text at this position + padding , move background at position (maybe method updatePosition)
	//-> padding has to be an attribute
	if (&background != nullptr) {
		background.setPosition(x,y);
	}
	text.setPosition(x + paddingX, y + paddingY);
}
sf::Vector2f Label::getPosition() {
	return sf::Vector2f(text.getPosition().x - paddingX, text.getPosition().y - paddingY);
}
sf::Vector2f Label::getPadding() {
	return sf::Vector2f(paddingX, paddingY);
}


void Label::setPadding(int x, int y) {
	paddingX = x;
	paddingY = y;
}


bool Label::isCursorHover(sf::Vector2f pCursorPosition) {
	bool isHover = false;
	sf::FloatRect bounds = text.getGlobalBounds();
	if (pCursorPosition.x >= bounds.left - paddingX && pCursorPosition.x <= bounds.left + bounds.width + paddingX) {
		if (pCursorPosition.y >= bounds.top - paddingY && pCursorPosition.y <= bounds.top + bounds.height + paddingY) {
			isHover = true;
		}
	}
	return isHover;
}
