#pragma once
#include <string>
#include <iostream>
#include "Animal.h"

class Duck : public Animal
{
public:
	Duck(std::string name);
	void speak() const;
};

