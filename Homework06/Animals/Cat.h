#pragma once
#include <string>
#include <iostream>
#include "Animal.h"

class Cat : public Animal
{
public:
	Cat(std::string name);
	void speak() const override;
	virtual void move() const override;
	int pet();

private:
	int petted = 0;
};

