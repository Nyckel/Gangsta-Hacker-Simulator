#pragma once
#include "SFML\Graphics.hpp"
#include <string>

//Parent of all visual components
class Component
{

private:
	std::string name;
public:
	Component();
	~Component();

	virtual bool isCursorHover(sf::Vector2f pCursorPosition);
	virtual void draw(sf::RenderWindow *pWindow);
	std::string getName();
	void setName(std::string pName);
};

