#include "UIButton.h"



UIButton::UIButton()
{
	clickable = true;
}


UIButton::UIButton(sf::Vector2f pPosition, std::string pString, int characterSize) : Label(pPosition, pString, characterSize){
	clickable = true;
	addBackgroundRect(sf::Color::Black, sf::Color(228, 71, 98));
	addHoverState(sf::Color(113, 248, 192), sf::Color::Black, sf::Color(113, 248, 192));
	text.setFont(font);
}
UIButton::UIButton(sf::Font pFont, sf::Vector2f pPosition, std::string pString, int characterSize) : Label(pFont, pPosition, pString, characterSize) {
	clickable = true;
	addBackgroundRect(sf::Color::Black, sf::Color(228, 71, 98));
	addHoverState(sf::Color(113, 248, 192), sf::Color::Black, sf::Color(113, 248, 192));
	text.setFont(font);
}
UIButton::UIButton(sf::Font pFont, sf::Color pColor, std::string pString, int characterSize, sf::RenderWindow* pWindow) : Label(pFont, pColor, pString, characterSize, pWindow) {
	clickable = true;
	addBackgroundRect(sf::Color::Black, sf::Color(228, 71, 98));
	addHoverState(sf::Color(113, 248, 192), sf::Color::Black, sf::Color(113, 248, 192));
	text.setFont(font);
}



//The right one
UIButton::UIButton(sf::Font pFont, sf::Color pColor, sf::Vector2f pPosition, sf::Vector2f pSize, std::string pString, int characterSize) : Label(pFont, pColor, pPosition, pString, characterSize){
	clickable = true;
	size = pSize;
	position = pPosition;
	addBackgroundRect(sf::Color::Black, sf::Color(228, 71, 98));
	textPosition = background.getTextPosition();
	text.setPosition(textPosition);
	text.setFont(font);
	/*std::cout << "COUCOU BBOBO:::::" << pString << std::endl;
	std::cout << "Init font adress : " << &font << std::endl;
	std::cout << "Font Family From UIButton : " << pFont.getInfo().family << " / " << text.getFont()->getInfo().family << std::endl;*/
	addHoverState(sf::Color(113, 248, 192), sf::Color::Black, sf::Color(113, 248, 192));
}

UIButton::~UIButton()
{
}

void UIButton::setSize(sf::Vector2f pSize) {
	size = pSize;
	//Maybe add a function to update display
	updateInnerPositions();
}

void UIButton::updateInnerPositions() {
	if (&background != nullptr && size.x != 0 && size.y != 0) {
		background.setSize(size);
	}
}

void UIButton::addBackgroundRect(sf::Color pBack, sf::Color pRect) {
	background = Background(&text, pBack, pRect, size, position);
}

void UIButton::addHoverState(sf::Color pFontColor, sf::Color pBack, sf::Color pRect) {
	hashoverstate = true;
	overState = Background(&text, pBack, pRect, size, position);
	overText = text;
	overText.setFillColor(pFontColor);
}


void UIButton::printName() {
	std::cout << "Clicked button named " << getText() << std::endl;
}