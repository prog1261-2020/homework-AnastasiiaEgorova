#include "Duck.h"

Duck::Duck(std::string n) : Animal(n, "duck", "quack")
{}

void Duck::speak() const {
	//Animal::speak();
	std::cout << "My name is " << name << " and dogs are awesome!\n";
}
