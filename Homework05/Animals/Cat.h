#pragma once
#include <string>
#include <iostream>
#include "Animal.h"

class Cat : public Animal
{
public:
	Cat(std::string name);

	void speak() const;
};

