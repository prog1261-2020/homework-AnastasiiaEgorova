#include "Animal.h"

Animal::Animal() 
{}

Animal::Animal(const std::string& n, const std::string& t, const std::string& s) : name(n), type(t), sound(s)	
{}

void Animal::speak() const {
	std::cout << "My name is " << getName() << " I am a " << getType() << " and I say " << getSound() << std::endl;
}

const std::string& Animal::getName() const {
	return name;
}

const std::string& Animal::getType() const {
	return type;
}

const std::string& Animal::getSound() const {
	return sound;
}