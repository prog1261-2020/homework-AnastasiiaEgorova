#include "Dog.h"

Dog::Dog(std::string n) : Animal(n, "dog", "gav")
{}

void Dog::speak() const{
	//Animal::speak();
	std::cout << "My name is " << name << " and people are awesome!\n";
}
