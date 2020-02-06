#include "Cat.h"

Cat::Cat(std::string n) : Animal(n, "Cat", "meow") 
{}

void Cat::speak() const {
	//Animal::speak();
	std::cout << "My name is " << name << " and I like mice! \n";
}
