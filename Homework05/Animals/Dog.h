#pragma once
#include <string>
#include <iostream>
#include "Animal.h"

class Dog : public Animal
{
public:
	Dog(std::string name);
	void speak() const;
};

