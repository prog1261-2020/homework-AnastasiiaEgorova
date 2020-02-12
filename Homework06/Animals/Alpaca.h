#pragma once
#include <string>
#include <iostream>
#include "Animal.h"

class Alpaca : public Animal
{
public:
	Alpaca(std::string name);
	virtual void speak() const;
	virtual void move() const;

private:
	void beingAdorable() const;
};

