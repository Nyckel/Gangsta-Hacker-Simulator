#include "Label.h"


Label::Label() {
	//background = NULL;
}

Label::Label(sf::Vector2f pPosition, std::string pString, int characterSize) {
	//background = NULL;
	//overState = NULL;
	isinhoverstate = false;
	
	paddingX = 0;
	paddingY = 0;
	
	font = new sf::Font();
	//font.loadFromFile("ressources/fonts/nasalization-rg.ttf");
	text = sf::Text(pString, *font);
	text.setFont(*font);
	text.setFillColor(sf::Color::Black);
	text.setPosition(pPosition);
	std::cout << "115 Font adress from draw : " << &font << std::endl;

}
Label::Label(sf::Font* pFont, sf::Vector2f pPosition, std::string pString, int characterSize) {
	//background = NULL;
	//overState = NULL;
	isinhoverstate = false;

	paddingX = 0;
	paddingY = 0;
	
	font = pFont;
	//font.loadFromFile("ressources/fonts/nasalization-rg.ttf");
	text = sf::Text(pString, *font);
	text.setFont(*font);
	text.setCharacterSize(characterSize);
	text.setPosition(pPosition);
	std::cout << "114 Font adress from draw : " << &font << std::endl;
}
Label::Label(sf::Font *pFont, sf::Color pColor, sf::Vector2f pPosition, std::string pString, int characterSize) {
	//background = NULL;
	//overState = NULL;
	isinhoverstate = false;

	paddingX = 0;
	paddingY = 0;

	font = pFont;
	//font.loadFromFile("ressources/fonts/nasalization-rg.ttf");
	color = sf::Color(pColor);
	text = sf::Text(pString, *font);
	text.setFont(*font);
	text.setFillColor(color);
	text.setCharacterSize(characterSize);
	text.setPosition(pPosition);
	std::cout << pString << std::endl;
	std::cout << "113 Font adress from draw : " << &font << std::endl;
}
Label::Label(sf::Font* pFont, sf::Color pColor, std::string pString, int characterSize, sf::RenderWindow* pWindow) {
	/*background = NULL;
	overState = NULL;*/
	isinhoverstate = false;

	paddingX = 0;
	paddingY = 0;
	
	font = pFont;
	//font.loadFromFile("ressources/fonts/nasalization-rg.ttf");
	text = sf::Text(pString, *font);
	text.setFont(*font);
	text.setFillColor(pColor);
	text.setCharacterSize(characterSize);

	int positionX = (int) pWindow->getSize().x / 2 - text.getGlobalBounds().width / 2;
	int positionY = (int) pWindow->getSize().y / 2 - text.getGlobalBounds().height / 2;

	text.setPosition(positionX, positionY);
	std::cout << "112 Font adress from draw : " << &font << std::endl;
}

Label::~Label()
{
}

void Label::draw(sf::RenderWindow *pWindow) {
	if (pWindow != nullptr) {
		if (isinhoverstate && &overState != nullptr) {
			overState.draw(pWindow);
		}
		else {
			if (&background != nullptr) {
				background.draw(pWindow);
			}
		}
		if (!text.getString().isEmpty() && &text != nullptr) {
			if (isinhoverstate && &overText != nullptr) {
				overText.setFont(*font);
				pWindow->draw(overText);
			}
			else {
				text.setFont(*font);
				//std::cout << "text: "<< std::string(text.getString()) << std::endl;
				/*std::cout << ">///" << font.getInfo().family << std::endl;
				std::cout << "??? Font adress from draw : " << &font << std::endl;
				std::cout << "Font adress from text : " << text.getFont() << std::endl;
				std::cout << "////" << text.getFont()->getInfo().family << std::endl;*/
				pWindow->draw(text);
 				//std::cout << "7" << std::endl;
			}
		}
		else {
			//std::cout << "label text is null" << std::endl;
		}
	}
	else {
		std::cout << "pWindow is null in draw function of class Label" << std::endl;
	}
}


void Label::addBackgroundRect() {
	background = Background(&text, sf::Color(20,29,37));
}
void Label::addBackgroundRect(sf::Color pBack, sf::Color pRect) {
	background = Background(&text,pBack, pRect);
}
void Label::setBackgroundColors(sf::Color pBack, sf::Color pRect) {
	background.setColors(pBack, pRect); 
}

void Label::addHoverState() {
	hashoverstate = true;
	overState = Background(&text, sf::Color(24,34,43));
	overText = text;
}
void Label::addHoverState(sf::Color pBack, sf::Color pRect) {
	hashoverstate = true;
	overState = Background(&text, pBack, pRect);
	overText = text;
}
void Label::addHoverState(sf::Color pFontColor, sf::Color pBack, sf::Color pRect) {
	hashoverstate = true;
	overState = Background(&text, pBack, pRect);
	overText = text;
	overText.setFillColor(pFontColor);
}
void Label::setHoverColors(sf::Color pBack, sf::Color pRect) {
	overState.setColors(pBack, pRect);
}
void Label::setHoverColors(sf::Color pTextColor, sf::Color pBack, sf::Color pRect) {
	overState.setColors(pBack, pRect);
	if(&overText != nullptr)
		overText.setFillColor(pTextColor);
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
	//Or return background.getPosition();
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
	//std::cout << "In function isCursorHover of label" << getText() << std::endl;
	bool isHover = false;
	sf::FloatRect bounds = text.getGlobalBounds();
	if (pCursorPosition.x >= bounds.left - paddingX && pCursorPosition.x <= bounds.left + bounds.width + paddingX) {
		//std::cout << "1 - Vertical in " << getName() << std::endl;
		if (pCursorPosition.y >= bounds.top - paddingY && pCursorPosition.y <= bounds.top + bounds.height + paddingY) {
			//std::cout << "2 - Horizontal in " << getName() << std::endl;
			isHover = true;
		}
	}

	if (&background != nullptr) {
		//std::cout << "background is not null" << std::endl;
		if (background.isCursorHover(pCursorPosition)) {
			isHover = true;
		}
	}
	return isHover;
}


std::string Label::getText() {
	return text.getString();
}