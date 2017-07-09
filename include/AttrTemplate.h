#pragma once
#include "Entity.h"
#include <vector>

template <typename T>
class AttrTemplate
{
	T value;
	std::vector<Entity*> discoveredBy;

public:
	AttrTemplate<T>() {};
	explicit AttrTemplate(const T& val) :value{val}, discoveredBy() {};
	const T& getValue() { return value; };
	void setValue(const T& val) { value = val; };
	~AttrTemplate();

	friend std::ostream& operator<< (std::ostream& stream, const AttrTemplate<T>& pAttr) { stream << pAttr.value; return stream; };
	//std::ostream operator<<(const std::ostream& lhs, const AttrTemplate<std::basic_string<char>>& rhs);
};

