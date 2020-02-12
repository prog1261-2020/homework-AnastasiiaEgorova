#include "Animal.h"

Animal::Animal(const std::string& n, const std::string& t, const std::string& s) : name(n), type(t), sound(s)	
{}

void Animal::speak() const {
	std::cout << "My name is " << getName() << " I am a " << getType() << " and I say " << getSound() << std::endl;
}

void Animal::move() const {
	std::cout << "Animal's move" << std::endl;
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