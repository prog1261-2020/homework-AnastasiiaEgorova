#include "Capybara.h"

Capybara::Capybara(std::string n) : Animal(n, "Capybara", "pooh")
{}

void Capybara::speak() const {
	std::cout << "pooh pooh pooh" << std::endl;
}

void Capybara::move() const {
	std::cout << "Capybara's move" << std::endl;
}

void Capybara::swim() const {
	std::cout << "Look! Capybara swims!" << std::endl;
}