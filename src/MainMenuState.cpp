#include "MainMenuState.h"
#include "PlayingState.h"


MainMenuState::MainMenuState(MainWindow* pWindow) {
	window = pWindow;
	/*title = window->createTitle();
	menu = window->createMainMenu();

	window->addComponent(title);
	window->addComponent(menu);*/

	window->setBackground("ressources/images/2.jpg");
	createMainTitle();
	createMenu();
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
				/*if (event.key.code == sf::Keyboard::Down && menu->getChildElements().size() != 0) {
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
				}*/
			}
		}
		window->tguiHandle(event);
	}
}
std::unique_ptr<GameState> MainMenuState::update(std::chrono::microseconds elapsed) {
	if (&menuChoice != nullptr && menuChoice != "") {
		if (menuChoice == "Play") {
			window->clearAll();
			auto ps = std::make_unique<PlayingState>();
			ps->setWindow(window);//todo:replace by a move
			return ps;// if we load a game we assign the saved file to the state before returning

		} if (menuChoice == "Options") {
			//window->getMenuActions->showOptions();
			//window->showOptions();
			std::cout << "Window->showOptions();" << std::endl;
		} if (menuChoice == "Exit") {
			std::cout << "Closing window..." << std::endl;
			window->close();
		}
		menuChoice = "";//To remove later
	}
	return nullptr;
}

void MainMenuState::draw() {
	window->update();

}

void MainMenuState::validateEntry() {
	Component** hoveredClickableComponent = window->getHoveredClickable();
	if (*hoveredClickableComponent != nullptr) {
		//hoveredClickableComponent->click = &(hoveredClickableComponent->printName);
		if (*hoveredClickableComponent != window->getDummyComponent()) {
			std::cout << "(state) Clicked on " << (*hoveredClickableComponent)->getName() << std::endl;

			menuChoice = (*hoveredClickableComponent)->getName();
		}

	}
	else {
		std::cout << "hoverClickableComponent is null (in state)" << std::endl;
	}
}

void MainMenuState::createMenu()
{
	auto customTheme = window->getTheme();

	auto bPlay = tgui::Button::create("Play");
	auto bOpti = tgui::Button::create("Options");
	auto bQuit = tgui::Button::create("Exit");

	bPlay->setRenderer(customTheme.getRenderer("Button"));
	bOpti->setRenderer(customTheme.getRenderer("Button"));
	bQuit->setRenderer(customTheme.getRenderer("Button"));

	bPlay->connect("pressed", [this] {menuChoice = "Play"; });
	bOpti->connect("pressed", [this] {menuChoice = "Options"; });
	bQuit->connect("pressed", [this] {menuChoice = "Exit"; });

	auto upperBound = window->getSize().y * 1 / 5;
	auto shift = bOpti->getSize().y + 10;

	bPlay->setPosition(100, upperBound);
	bOpti->setPosition(100, upperBound + shift);
	bQuit->setPosition(100, upperBound + 2 * shift);

	window->addToGui(bPlay);
	window->addToGui(bOpti);
	window->addToGui(bQuit);
}

void MainMenuState::createMainTitle() const
{
	auto title = tgui::Label::create("Gangsta Hacker Simulator");
	title->setTextSize(50);
	title->setPosition(window->getSize().x / 2 - title->getSize().x / 2, 50);
	title->setPosition(100, 50);
	title->setRenderer(window->getTheme().getRenderer("Label"));

	window->addToGui(title);
}