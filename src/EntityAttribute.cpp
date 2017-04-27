#include "EntityAttribute.h"


template<typename T>
EntityAttribute<T>::EntityAttribute(T) {
	value = T;
}

template<typename T>
EntityAttribute<T>::~EntityAttribute() {
}

template<typename T>
void EntityAttribute<T>::setValue(const T pVal) {
	value = T;
}

template<typename T>
void EntityAttribute<T>::setLabel(const std::string& pLabel) {
	label = pLabel;
}

template<typename T>
T* EntityAttribute<T>::getValue() {
	return &value;
}

template<typename T>
std::string EntityAttribute<T>::getLabel() {
	return label;
}

template<typename T>
bool EntityAttribute<T>::isDiscoveredBy(Entity *pEntity) {
	if (pEntity != nullptr) {
		return (std::find(discoveredBy.begin(); discoveredBy.end(); pEntity) != discoveredBy.end());
	}
	return false;
}

