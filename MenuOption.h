#pragma once
#include <string>

#include "Component.h"


class MenuOption : public Component
{
private:
	std::string text;
	//Position
	//Font 
	//Size      derive all these from Component

public:
	MenuOption();
	~MenuOption();
	void draw();
};

