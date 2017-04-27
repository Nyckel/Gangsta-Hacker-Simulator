#include "MainMenuState.h"
#include "PlayingState.h"


MainMenuState::MainMenuState(MainWindow* pWindow) {
	window = pWindow;
	title = window->createTitle();
	menu = window->createMainMenu();

	window->addComponent(title);
	window->addComponent(menu);

}


MainMenuState::~MainMenuState() {
	delete(menu);
	delete(title);
}

void MainMenuState::init() {
	//Create Menu Elements here
	//Set index of selected element
}
void MainMenuState::cleanUp() {

}

void MainMenuState::pause() {

}
void MainMenuState::resume() {

}

void MainMenuState::handleEvents() {
	for (sf::Event event : window->getEvents()) {
		switch (event.type) {
			case sf::Event::Closed: {
				window->close();
				break;
			}
			case sf::Event::MouseMoved: {
				sf::Vector2f mousePosition(event.mouseMove.x, event.mouseMove.y);
				std::vector<Component*>* hoveredComponents = window->getHoveredComponents();
				Component** hoveredClickableComponent = window->getHoveredClickable();
				std::vector<Component*>::iterator it = hoveredComponents->begin();
				while (it != hoveredComponents->end()) {
					//If it's not in hovered anymore
					if (!(*it)->isCursorHover(mousePosition)) {
						(*it)->normalState();
						it = hoveredComponents->erase(it);
					}
					else {
						++it;
					}
					if (*hoveredClickableComponent != nullptr) {
						if (!(*hoveredClickableComponent)->isCursorHover(mousePosition)) {
							*hoveredClickableComponent = nullptr;//window->getDummyComponent();
						}
					}
				}

				bool hoveredElementFound = false;
				std::vector<std::vector<Component*>>* componentsAtLevel = window->getComponentsByLevel();
				std::vector<std::vector<Component*>>::reverse_iterator it2 = componentsAtLevel->rbegin();

				while (!hoveredElementFound && it2 != componentsAtLevel->rend()) {
					std::vector<Component*>::iterator it3 = (*it2).begin();
					while (!hoveredElementFound && it3 != (*it2).end()) {
						if ((*it3)->isCursorHover(mousePosition)) {
							hoveredElementFound = true;
							hoveredComponents->push_back(*it3);
							if ((*it3)->hasHoverState()) {
								(*it3)->hoverState();
							}
							if ((*it3)->hasChildElements()) {
								(*it3)->getClickableAndHoveredComponents(mousePosition, hoveredComponents, hoveredClickableComponent);
							}
						}
						++it3;
					}
					it2++;
				}
				if (*hoveredClickableComponent != nullptr && *hoveredClickableComponent != window->getDummyComponent())
					std::cout << "hovered element " << (*hoveredClickableComponent)->getName() << std::endl;
				break;
			}

			case sf::Event::MouseButtonReleased: {
				std::cout << "Validate" << std::endl;
				validateEntry();
				break;
			}
			case sf::Event::KeyPressed:{
				if (sf::Keyboard::isKeyPressed(sf::Keyboard::Return)) {
					std::cout << "Validate" << std::endl;
					validateEntry();
				}
				break;
			}
			case sf::Event::KeyReleased: {
				if (event.key.code == sf::Keyboard::Down && menu->getChildElements().size() != 0) {
					Component** hoveredClickableComponent = window->getHoveredClickable();
					int oldCursorPosition = menu->positionOf(*hoveredClickableComponent);
					if (oldCursorPosition == -1) {
						window->hoverElement(menu->elementAt(0));
					}
					else {
						window->unHoverElement(menu->elementAt(oldCursorPosition));
						window->hoverElement(menu->elementAt((oldCursorPosition + 1) % menu->getMenuButtons().size()));
					}
				}
				else if (event.key.code == sf::Keyboard::Up && menu->getChildElements().size() != 0) {
					Component** hoveredClickableComponent = window->getHoveredClickable();
					int oldCursorPosition = menu->positionOf(*hoveredClickableComponent);
					if (oldCursorPosition <= 0) {
						window->unHoverElement(menu->elementAt(oldCursorPosition));
						window->hoverElement(menu->elementAt(menu->getChildElements().size() -1));
					} else {
						window->unHoverElement(menu->elementAt(oldCursorPosition));
						window->hoverElement(menu->elementAt((oldCursorPosition - 1) % menu->getMenuButtons().size()));
					}
				}
			}
		}
	}
}
GameState* MainMenuState::update(std::chrono::microseconds elapsed) {
	if (&menuChoice != nullptr && menuChoice != "") {
		if (menuChoice == "Play") {
			/*window->getMenuStateActions()->promptNewOrLoadGame();*/
			std::cout << "Switch to playingState" << std::endl;
			return new PlayingState();// if we load a game we assign the saved file to the state before returning
		} else if (menuChoice == "Options") {
			//window->getMenuActions->showOptions();
			//window->showOptions();
			std::cout << "Window->showOptions();" << std::endl;
		} else if (menuChoice == "Exit") {
			std::cout << "Closing window..." << std::endl;
			window->close();
		}
		menuChoice = "";//To remove later
	}
	return nullptr;
}

void MainMenuState::draw() {

}

void MainMenuState::validateEntry() {
	Component** hoveredClickableComponent = window->getHoveredClickable();
	if (*hoveredClickableComponent != nullptr) {
		//hoveredClickableComponent->click = &(hoveredClickableComponent->printName);
		if (*hoveredClickableComponent != window->getDummyComponent()) {
			std::cout << "(state) Clicked on " << (*hoveredClickableComponent)->getName() << std::endl;
			/*hoveredClickableComponent->click = [this]() { hoveredClickableComponent->printName(); };*/
			(*hoveredClickableComponent)->click2;
			//hoveredClickableComponent->click;
			menuChoice = (*hoveredClickableComponent)->getName();
		}

	}
	else {
		std::cout << "hoverClickableComponent is null (in state)" << std::endl;
	}
}