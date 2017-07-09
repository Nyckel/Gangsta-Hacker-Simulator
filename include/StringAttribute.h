#pragma once
#include <string>
#include <iostream>
#include "AbstractAttribute.h"

class StringAttribute :
	public AbstractAttribute
{
	std::string value;

public:
	
	StringAttribute() {}
	StringAttribute(const std::string& pVal) : value{ pVal } {}
	void setValue(const std::string& pVal) { value = { pVal }; }
	std::string getValue() const { return value; }
	friend std::ostream& operator<< (std::ostream& stream, const StringAttribute& pAttr) { stream << pAttr.value; return stream; }
	bool isEmpty() const { return value.empty(); }
	~StringAttribute() {};
};