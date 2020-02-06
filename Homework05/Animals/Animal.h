#pragma once
#include <string>
#include <iostream>

class Animal
{
public:
	Animal();
	Animal(const std::string& name, const std::string& type, const std::string& sound);

	void speak() const;
	const std::string& getName() const;
	const std::string& getType() const;
	const std::string& getSound() const;

protected:
	std::string name;
	std::string type;
	std::string sound;
};

