#include "Alpaca.h"

Alpaca::Alpaca(std::string n) : Animal(n, "Alpaca", "hum")
{}

void Alpaca::speak() const {
	std::cout << "hum hum hum" << std::endl;
}

void Alpaca::move() const {
	std::cout << "Alpaca'a move" << std::endl;
}

void Alpaca::beingAdorable() const {
	std::cout << "Have you seen non-adorable alpaca??? That's because alpacas are always adorable!" << std::endl;
}