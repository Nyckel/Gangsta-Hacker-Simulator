#pragma once
#include <vector>
#include <iostream>
#include <stdlib.h>
#include <functional>
#include <string>
#include "Component.h"
#include "UIButton.h"
#include "SFML\Graphics.hpp"
#include "Label.h"
#include "Menu.h"
#include <TGUI/TGUI.hpp>


class MainWindow
{

private:
	int nbElementsInHoverState;
	Component* hoveredClickableComponent;
	Component* dummyComponent;
	std::vector<Component*> hoveredComponents;
	sf::RenderWindow window;
	tgui::Gui gui;
	std::vector<Component*> components;
	std::vector<std::vector<Component*>> componentsAtLevel;

	sf::Texture back_texture;
	sf::Sprite background;
	tgui::Theme customTheme;

	void removeFromHoveredList(Component*);
public:
	MainWindow();
	~MainWindow();
	void update();
	void close();
	void addComponent(Component *pComp, unsigned int zIndex = 0);
	void hoverElement(Component* elt);
	void unHoverElement(Component* elt);
	Menu* createMainMenu();
	Label* createTitle();
	//void handleEvents();
	std::vector<sf::Event> getEvents();
	std::vector<Component*>* getHoveredComponents();
	Component** getHoveredClickable();
	Component* getDummyComponent();
	std::vector<std::vector<Component*>>* getComponentsByLevel();
	void clearComponents();


	void tguiHandle(sf::Event e) { gui.handleEvent(e); }
	void addToGui(tgui::Widget::Ptr widget) { gui.add(widget); }
	void removeFromGui(std::vector<tgui::Widget::Ptr> widgets) { for (auto& wid : widgets) gui.remove(wid); }
	void removeFromGui(tgui::Widget::Ptr widget) { gui.remove(widget); }
	std::vector<tgui::Widget::Ptr> getGuiElements() const { return gui.getWidgets(); }
	sf::Vector2u getSize() const { return window.getSize(); }

	void setBackground(std::string path);
	tgui::Theme& getTheme() { return customTheme; }

	void clearAll();
};

