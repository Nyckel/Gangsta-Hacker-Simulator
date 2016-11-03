#include "MainWindow.h"
#include "SFML\Graphics.hpp"
#include "Component.h"
#include "Label.h"
#include <iostream>
#include <stdlib.h>


MainWindow::MainWindow()
{
	window = new sf::RenderWindow(sf::VideoMode(800, 600), "Gangsta Hacker Simulator 1.0");
	window->setPosition(sf::Vector2i(0, 0));
	window->setFramerateLimit(60);
	window->setKeyRepeatEnabled(false);


	//Split : mainMenuEventManager, gameEventManager, inGameMenuEventManager...

}


MainWindow::~MainWindow()
{
	delete(window);
	for (int i = 0; i < components.size(); i++) {
		//delete(components.at(i));
	}
}


void MainWindow::update() {
	window->clear(sf::Color(52, 152, 219));

	for (int i = 0; i < components.size(); i++) {
		//std::cout << "Component" << std::endl;
		components.at(i)->draw(window);
	}
	window->display();
}


void MainWindow::addComponent(Component *pComp) {
	components.push_back(pComp);
}

int MainWindow::showMainMenu() {

	sf::Font titleFont;
	titleFont.loadFromFile("ressources/fonts/nasalization-rg.ttf");

	Label title(titleFont, sf::Color::White, "Gangsta Hacker Simulator", 50, window);
	title.setPadding(20, 20);
	title.setPosition(title.getPosition().x, 10);
	title.addBackgroundRect();
	addComponent(&title);

	Label play(titleFont, sf::Color::Black, sf::Vector2f(50, 100), "Play", 30);
	play.setPadding(10, 10);
	play.setPosition(play.getPosition().x, window->getSize().y * 1 / 3);
	play.addBackgroundRect();
	play.setName("MainMenu_PlayButton");
	addComponent(&play);


	int choice = 0;
	while (choice == 0) {
		choice = getMenuChoice();
		update();
	}

	//display();

	return choice;
}

void MainWindow::display() {
	while (window->isOpen()) {
		sf::Event event;
		while (window->pollEvent(event)) {
			if (event.type == sf::Event::Closed) {
				window->close();
			}
			if (event.type == sf::Event::MouseMoved) {
				sf::Vector2f mousePosition(event.mouseMove.x, event.mouseMove.y);
				for (int i = 0; i < components.size(); i++) {
					if (components.at(i)->isCursorHover(mousePosition)) {
						std::cout << "Hover a component" << std::endl;
						std::string componentName = components.at(i)->getName();
						if (componentName == "MainMenu_PlayButton") {
							
						}
					}
				}
				//if (play.isCursorHover(mousePosition)) {
				//std::cout << "Cursor is hover play option" << std::endl;
				//}
			}
		}
		//window->draw(menuTitle);
		window->clear(sf::Color(52, 152, 219));

		for (int i = 0; i < components.size(); i++) {
			//std::cout << "Component" << std::endl;
			components.at(i)->draw(window);
		}
		window->display();
		
	}
}


int MainWindow::getMenuChoice() {
	sf::Event event;
	int returnValue = 0;
	while (window->pollEvent(event)) {
		if (event.type == sf::Event::Closed) {
			window->close();
		}
		if (event.type == sf::Event::MouseMoved) {
			sf::Vector2f mousePosition(event.mouseMove.x, event.mouseMove.y);
			for (int i = 0; i < components.size(); i++) {
				if (components.at(i)->isCursorHover(mousePosition)) {
					std::cout << "Hover a component" << std::endl;
					std::string componentName = components.at(i)->getName();
					if (componentName == "MainMenu_PlayButton") {
						returnValue= 1;
					}
				}
			}
			//if (play.isCursorHover(mousePosition)) {
			//std::cout << "Cursor is hover play option" << std::endl;
			//}
		}
		//update();
	}
	return returnValue;
}
