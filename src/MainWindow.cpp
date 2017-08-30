#include "MainWindow.h"




MainWindow::MainWindow() : window(sf::VideoMode(1080, 720), "Gangsta Hacker Simulator 1.0"), gui{window}
{
	//window = new sf::RenderWindow(sf::VideoMode(800, 600), "Gangsta Hacker Simulator 1.0");
	 

	window.setPosition(sf::Vector2i(0, 0));
	window.setFramerateLimit(60);
	window.setKeyRepeatEnabled(false);
	dummyComponent = new Component();
	hoveredClickableComponent = dummyComponent;
	componentsAtLevel = std::vector<std::vector<Component*>>();


}


MainWindow::~MainWindow()
{
	/*delete(window);
	for (int i = 0; i < components.size(); i++) {
		std::cout << "Deleting "<< components.at(i)->getName() << "...";
		delete(components.at(i));
		std::cout << "Delete" << std::endl;
	}*/
	delete(dummyComponent);
}


void MainWindow::update() {
	//window->clear(sf::Color(52, 152, 219));
	sf::Color windowBackgroundColor = sf::Color::Black;// sf::Color(44, 62, 80, 1.0);// sf::Color(10, 10, 10);
	window.clear(windowBackgroundColor);
	sf::Texture texture;
	if (!texture.loadFromFile("ressources/city.jpg"))
	{
		std::cout << "Couldn't load background image " << std::endl;
	}
	sf::Sprite background(texture);
	window.draw(background);

	for (std::vector<Component*> components : componentsAtLevel) {
		for (Component* comp : components) {
			//std::cout << "Component : " << comp->getName() << std::endl;
			comp->draw(window);
		}
	}
	gui.draw();
	window.display();
}


void MainWindow::addComponent(Component *pComp, unsigned int zIndex) {
	//We don't have a vector of components at this zIndex yet
	std::cout << "Adding component called " << pComp->getName() << " at level " << zIndex << std::endl;
	if (componentsAtLevel.size() < zIndex+1) {
		while (componentsAtLevel.size() < zIndex + 1) {
			std::vector<Component*>* componentsAtNextZIndex = new std::vector<Component*>();
			componentsAtLevel.push_back(*componentsAtNextZIndex);
		}
	}
	std::cout << "This element is nb " << componentsAtLevel[zIndex].size() + 1 << " at this level" << std::endl;
	componentsAtLevel[zIndex].push_back(pComp);
	//components.push_back(pComp);
}

//int MainWindow::createMainMenu() {
//
//	sf::Font titleFont;
//	titleFont.loadFromFile("../ressources/fonts/nasalization-rg.ttf");
//
//	Label title(titleFont, sf::Color::White, "Gangsta Hacker Simulator", 50, window);
//	title.setPadding(20, 20);
//	title.setPosition(title.getPosition().x, 10);
//	title.addBackgroundRect();
//	title.setName("Title");
//	addComponent(&title);
//
//	dummyComponent = new Component();
//
//	sf::Vector2f buttonSize = sf::Vector2f(window->getSize().x - 100, window->getSize().y / 6);
//	//Start Menu
//	//std::vector<std::string> menuOptions;
//	std::vector<std::pair<std::string, std::function<void()>>> menuParams;
//
//	std::function<void()> func = [this]() { hoveredClickableComponent->printName(); };
//	std::function<void()> funcExit = [this]() { std::cout << "Exiting game" << std::endl; };
//	std::function<void()> funcPlay = [this]() { std::cout << "Playing game" << std::endl; };
//	menuParams.push_back({"Play", funcPlay });
//	menuParams.push_back({ "Options", func });
//	menuParams.push_back({ "Exit", funcExit });
//	
//	//menuOptions.push_back("Play");
//	//menuOptions.push_back("Options");
//	//menuOptions.push_back("Exit");
//	//Menu* startMenu = new Menu(menuOptions, "Gangsta Hacker Simulator", titleFont, sf::Color(228, 71, 98), buttonSize, 30, 10, sf::Vector2f(50, window->getSize().y * 1 / 3));
//	Menu* startMenu = new Menu(menuParams, "Gangsta Hacker Simulator", titleFont, sf::Color(228, 71, 98), buttonSize, 30, 10, sf::Vector2f(50, window->getSize().y * 1 / 3));
//	startMenu->setName("Main Game Menu");
//	addComponent(startMenu);
//
//	int choice = 0;
//	while (choice == 0) {
//		handleEvents();
//		update();
//	}
//
//	return choice;
//}

Label* MainWindow::createTitle() {
	sf::Font* titleFont = new sf::Font();
	/*titleFont->loadFromFile("ressources/fonts/nasalization-rg.ttf");*/
	titleFont->loadFromFile("ressources/fonts/SourceCodePro-Regular.ttf");

	Label* title = new Label(titleFont, sf::Color::White, "Gangsta Hacker Simulator", 50, window);
	title->setPadding(20, 20);
	title->setPosition(title->getPosition().x, 10);
	//title->addBackgroundRect();
	title->addBackgroundRect(sf::Color(44, 62, 80), sf::Color(142, 68, 173));
	//std::cout << "Setting colors" << std::endl;
	//title->setBackgroundColors(sf::Color(44, 62, 80, 1.0), sf::Color(192, 57, 43, 1.0));
	title->setName("Title");
	return title;
}


Menu* MainWindow::createMainMenu() {

	sf::Font* titleFont = new sf::Font();
	//titleFont->loadFromFile("ressources/fonts/nasalization-rg.ttf");
	titleFont->loadFromFile("ressources/fonts/SourceCodePro-Regular.ttf");
	//titleFont->loadFromFile("../ressources/fonts/nasalization-rg.ttf");

	dummyComponent = new Component();

	sf::Vector2f buttonSize = sf::Vector2f(window.getSize().x - 100, window.getSize().y / 6);
	//Start Menu
	//std::vector<std::string> menuOptions;
	std::vector<std::pair<std::string, std::function<void()>* >> menuParams;

	std::function<void()> func = [this]() { hoveredClickableComponent->printName(); };
	std::function<void()> funcExit = [this]() { std::cout << "Exiting game" << std::endl; };
	std::function<void()> funcPlay = [this]() { std::cout << "Playing game" << std::endl; };
	menuParams.push_back({ "Play", &funcPlay }); //Except here we will point to unhautorized memory
	menuParams.push_back({ "Options", &func });
	menuParams.push_back({ "Exit", &funcExit });

	//menuOptions.push_back("Play");
	//menuOptions.push_back("Options");
	//menuOptions.push_back("Exit");
	//Menu* startMenu = new Menu(menuOptions, "Gangsta Hacker Simulator", titleFont, sf::Color(228, 71, 98), buttonSize, 30, 10, sf::Vector2f(50, window->getSize().y * 1 / 3));
	Menu* startMenu = new Menu(menuParams, "Gangsta Hacker Simulator", titleFont, sf::Color(228, 71, 98), buttonSize, 30, 10, sf::Vector2f(50, window.getSize().y * 1 / 3));
	startMenu->setName("Main Game Menu");
	return startMenu;
	//addComponent(startMenu);
}


//
//void MainWindow::handleEvents() {
//	sf::Event event;
//	while (window.pollEvent(event)) {
//		switch (event.type) {
//			case sf::Event::Closed: {
//				window.close();
//				break;
//			}
//			case sf::Event::MouseMoved: {
//				sf::Vector2f mousePosition(event.mouseMove.x, event.mouseMove.y);
//
//				std::vector<Component*>::iterator it = hoveredComponents.begin();
//				while (it != hoveredComponents.end()) {
//					//If it's not in hovered anymore
//					if (!(*it)->isCursorHover(mousePosition)) {
//						(*it)->normalState();
//						it = hoveredComponents.erase(it);
//					}
//					else {
//						++it;
//					}
//					if (!hoveredClickableComponent->isCursorHover(mousePosition)) {
//						hoveredClickableComponent = dummyComponent;
//					}
//				}
//
//				bool hoveredElementFound = false;
//				std::vector<std::vector<Component*>>::reverse_iterator it2 = componentsAtLevel.rbegin();
//				while (!hoveredElementFound && it2 != componentsAtLevel.rend()) {
//					std::vector<Component*>::iterator it3 = (*it2).begin();
//					while (!hoveredElementFound && it3 != (*it2).end()) {
//						if ((*it3)->isCursorHover(mousePosition)) {
//							hoveredElementFound = true;
//							hoveredComponents.push_back(*it3);
//							if ((*it3)->hasHoverState()) {
//								(*it3)->hoverState();
//							}
//							if ((*it3)->hasChildElements()) {
//								(*it3)->getClickableAndHoveredComponents(mousePosition, &hoveredComponents, &hoveredClickableComponent);
//							}
//							if (hoveredClickableComponent != nullptr) {
//							}
//							else {
//							}
//						}
//						++it3;
//					}
//					it2++;
//				}
//				break;
//			}
//		
//			case sf::Event::MouseButtonReleased: {
//				if (hoveredClickableComponent != nullptr) {
//					//hoveredClickableComponent->click = &(hoveredClickableComponent->printName);
//					if (hoveredClickableComponent != dummyComponent) {
//						std::cout << "Clicked on " << hoveredClickableComponent->getName() << std::endl;
//						/*hoveredClickableComponent->click = [this]() { hoveredClickableComponent->printName(); };*/
//						hoveredClickableComponent->click;
//					}
//
//				}
//				else {
//					std::cout << "hoverClickableComponent is null" << std::endl;
//				}
//				break;
//			}
//		}
//	}
//	//gui.handleEvent(event);
//}

std::vector<sf::Event> MainWindow::getEvents() {
	std::vector<sf::Event> events;
	sf::Event event;
	while (window.pollEvent(event)) {
		events.push_back(event);
	}

	return events;
}

void MainWindow::close() {
	window.close();
}

std::vector<Component*>* MainWindow::getHoveredComponents() {
	return &hoveredComponents;
}

Component** MainWindow::getHoveredClickable() {
	return &hoveredClickableComponent;
}

void MainWindow::hoverElement(Component* elt) {
	if (elt != nullptr) {
		//std::cout << "Trying to hover " << elt->getName() << std::endl;
		if (elt->hasHoverState()) {
			elt->hoverState();
			hoveredComponents.push_back(elt);
			hoveredClickableComponent = elt;
		}
		else {
			//std::cout << "Element has no hover state" << std::endl;
		}
	}
}

void MainWindow::unHoverElement(Component* elt) {
	if (elt != nullptr) {
		//std::cout << "Trying to unHover " << elt->getName() << std::endl;
		if (elt->hasHoverState() && elt->isInHoverState()) {
			elt->normalState();
			removeFromHoveredList(elt);
			if (hoveredClickableComponent == elt)
				hoveredClickableComponent = nullptr;
		}
	}
}

void MainWindow::removeFromHoveredList(Component* elt) {
	std::vector<Component*>::iterator it = hoveredComponents.begin();
	while (it != hoveredComponents.end()) {
		//If it's not in hovered anymore
		if (*it == elt) {
			(*it)->normalState();
			it = hoveredComponents.erase(it);
		}
		else {
			++it;
		}
	}
}
Component* MainWindow::getDummyComponent() {
	return dummyComponent;
}

std::vector<std::vector<Component*>>* MainWindow::getComponentsByLevel() {
	return &componentsAtLevel;
}

void MainWindow::clearComponents()
{
	nbElementsInHoverState = 0;
	hoveredClickableComponent = nullptr;
	dummyComponent = nullptr;
	for (auto elt : hoveredComponents)
		delete elt;
	for (auto elt : components)
		delete elt;
	for (auto level : componentsAtLevel)
		for (auto elt : level)
			delete elt;
}