#pragma once
#include "SFML\Graphics.hpp"
#include <string>
#include <iostream>
#include <functional>

//Parent of all visual components
class Component
{
	protected:std::string name;
	protected:bool hashoverstate = false;
	protected:bool isinhoverstate = false;
	protected:bool clickable = false;
	protected:unsigned int zIndex;
	protected:std::vector<Component*> childElements;

public:
	//std::string(Component::*clickAction)(void) = &Component::getName;
	std::function<void()>* click;// = &Component::printName;
	void(Component:: *click2)(void) = &Component::printName;
	//std::function<void()> click;
	Component();
	~Component();

	virtual void hoverState();
	virtual void normalState();

	virtual bool isInHoverState() const;
	virtual bool isCursorHover(sf::Vector2f pCursorPosition);
	bool hasHoverState() const;
	bool isClickable() const;
	void setClickable(bool pClickable);

	virtual void draw(const sf::RenderWindow& pWindow);
	std::string getName() const;
	void printName();
	void setName(std::string pName);
	void setColor(sf::Color pColor);

	bool hasChildElements();
	void addChildrenElement(Component* pComp);
	std::vector<Component*> getChildElements();
	void getClickableAndHoveredComponents(sf::Vector2f mousePosition, std::vector<Component*>* hoveredComponents, Component** hoveredClickableComponent);
};

