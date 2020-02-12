#pragma once
#include <string>
#include <iostream>

class Animal
{
public:
	//so no args CTOR cannot be used
	Animal() = delete;
	Animal(const std::string& name, const std::string& type, const std::string& sound);
	virtual ~Animal() {};

	//abstract
	virtual void speak() const;
	virtual void move() const;

	const std::string& getName() const;
	const std::string& getType() const;
	const std::string& getSound() const;

protected:
	std::string name;
	std::string type;
	std::string sound;
};

