#include "Dog.h"

Dog::Dog(std::string n) : Animal(n, "dog", "gav")
{}

void Dog::speak() const{
	//Animal::speak();
	std::cout << getSound() << " " << getSound() << " " << getSound() << std::endl;
}

void Dog::move() const {
	std::cout << "Dog's move" << std::endl;
}

int Dog::walk() {
	return ++walked = 0;
}


