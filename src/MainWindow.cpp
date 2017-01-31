#include "MainWindow.h"
#include "SFML\Graphics.hpp"
#include "Component.h"
#include "Label.h"
#include <iostream>
#include <stdlib.h>
#include <vector>

#include "Menu.h"



MainWindow::MainWindow()
{
	//window = new sf::RenderWindow(sf::VideoMode(800, 600), "Gangsta Hacker Simulator 1.0");
	window = new sf::RenderWindow(sf::VideoMode(1080, 720), "Gangsta Hacker Simulator 1.0");
	window->setPosition(sf::Vector2i(0, 0));
	window->setFramerateLimit(60);
	window->setKeyRepeatEnabled(false);

	//Split : mainMenuEventManager, gameEventManager, inGameMenuEventManager...

}


MainWindow::~MainWindow()
{
	/*delete(window);
	for (int i = 0; i < components.size(); i++) {
		std::cout << "Deleting "<< components.at(i)->getName() << "...";
		delete(components.at(i));
		std::cout << "Delete" << std::endl;
	}*/
}


void MainWindow::update() {
	//window->clear(sf::Color(52, 152, 219));
	sf::Color windowBackgroundColor = sf::Color(10, 10, 10);
	window->clear(windowBackgroundColor);

	//for (int i = 0; i < components.size(); i++) {
	//	components.at(i)->draw(window);
	//}
	for (std::vector<Component*> components : componentsAtLevel) {
		for (Component* comp : components) {
			comp->draw(window);
		}
	}
	window->display();
}


void MainWindow::addComponent(Component *pComp, unsigned int zIndex) {
	//We don't have a vector of components at this zIndex yet
	if (componentsAtLevel.size() < zIndex+1) {
		while (componentsAtLevel.size() < zIndex + 1) {
			std::vector<Component*> componentsAtNextZIndex;
			componentsAtLevel.push_back(componentsAtNextZIndex);
		}
	}
	componentsAtLevel[zIndex].push_back(pComp);
	//components.push_back(pComp);
}

int MainWindow::showMainMenu() {

	sf::Font titleFont;
	titleFont.loadFromFile("ressources/fonts/nasalization-rg.ttf");

	Label title(titleFont, sf::Color::White, "Gangsta Hacker Simulator", 50, window);
	title.setPadding(20, 20);
	title.setPosition(title.getPosition().x, 10);
	title.addBackgroundRect();
	title.setName("Title");
	addComponent(&title);

	sf::Vector2f buttonSize = sf::Vector2f(window->getSize().x - 100, window->getSize().y / 6);

	//Start Menu
	std::vector<std::string> menuOptions;
	menuOptions.push_back("Play");
	menuOptions.push_back("Options");
	menuOptions.push_back("Exit");
	Menu* startMenu = new Menu(menuOptions, "Gangsta Hacker Simulator", titleFont, sf::Color(228, 71, 98), buttonSize, 30, 10, sf::Vector2f(50, window->getSize().y * 1 / 3));
	startMenu->setName("Main Game Menu");
	//startMenu->bindButtonFunction("Play", func);
	addComponent(startMenu);

	int choice = 0;
	while (choice == 0) {
		handleEvents();
		update();
	}

	return choice;
}



void MainWindow::handleEvents() {
	sf::Event event;
	while (window->pollEvent(event)) {
		switch (event.type) {
			case sf::Event::Closed: {
				window->close();
				break;
			}
			case sf::Event::MouseMoved: {
				sf::Vector2f mousePosition(event.mouseMove.x, event.mouseMove.y);

				std::vector<Component*>::iterator it = hoveredComponents.begin();
				while (it != hoveredComponents.end()) {
					//If it's not in hovered anymore
					if (!(*it)->isCursorHover(mousePosition)) {
						(*it)->normalState();
						it = hoveredComponents.erase(it);
					}
					else {
						++it;
					}
				}

				bool hoveredElementFound = false;
				std::vector<std::vector<Component*>>::reverse_iterator it2 = componentsAtLevel.rbegin();
				while (!hoveredElementFound && it2 != componentsAtLevel.rend()) {
					std::vector<Component*>::iterator it3 = (*it2).begin();
					while (!hoveredElementFound && it3 != (*it2).end()) {
						if ((*it3)->isCursorHover(mousePosition)) {
							hoveredElementFound = true;
							hoveredComponents.push_back(*it3);
							if ((*it3)->hasHoverState()) {
								(*it3)->hoverState();
							}
							if ((*it3)->hasChildElements()) {
								(*it3)->getClickableAndHoveredComponents(mousePosition, &hoveredComponents, &hoveredClickableComponent);
							}
							if (hoveredClickableComponent != nullptr) {
							}
							else {
							}
						}
						++it3;
					}
					it2++;
				}
				break;
			}
		
			case sf::Event::MouseButtonReleased: {
				std::cout << "Clicked" << std::endl;
				if (hoveredClickableComponent != nullptr) {
					hoveredClickableComponent->click = &(hoveredClickableComponent->printName);
					hoveredClickableComponent->click;
					
					//hoveredClickableComponent->click = [hoveredClickableComponent]() {hoveredClickableComponent->printName(); };
					//std::cout << "Clicked " << hoveredClickableComponent->clickAction << std::endl;
				}
				else {
					std::cout << "hoverClickableComponent is null" << std::endl;
				}
				break;
			}
		}
	}
}