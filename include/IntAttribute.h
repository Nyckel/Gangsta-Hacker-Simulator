#pragma once
#include "AbstractAttribute.h"
class IntAttribute :
	public AbstractAttribute
{
	int value;
public:
	IntAttribute(): value(0) {};
	IntAttribute(const int & pVal) : value(pVal) {}
	void setValue(const int & pVal) { value = pVal; }
	int getValue() const { return value; }
	~IntAttribute() {};

	friend std::ostream& operator<< (std::ostream& stream, const IntAttribute& pAttr) { stream << pAttr.value; return stream; };
};

