#include "Menu.h"



Menu::Menu()
{
	title = Label(sf::Vector2f(100, 100));
}


Menu::~Menu()
{
}

void Menu::draw(sf::RenderWindow* pWindow)
{
	if (&title != nullptr) {
		title.draw(pWindow);
	}
	for (int i = 0; i < options.size(); i++) {
		options.at(i).draw();
	}
}
