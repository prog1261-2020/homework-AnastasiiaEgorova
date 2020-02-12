#include "Duck.h"

Duck::Duck(std::string n) : Animal(n, "duck", "quack")
{}

void Duck::speak() const {
	//Animal::speak();
	std::cout << getSound() << " " << getSound() << " " << getSound() << std::endl;
}

void Duck::move() const {
	std::cout << "Duck's move" << std::endl;
}

int Duck::feed() {
	return ++fed;
}

void Duck::swim() {
	std::cout << "Splach splach splach\n";
}
