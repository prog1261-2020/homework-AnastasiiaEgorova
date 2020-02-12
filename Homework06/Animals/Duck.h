#pragma once
#include <string>
#include <iostream>
#include "Animal.h"

class Duck : public Animal
{
public:
	Duck(std::string name);
	void speak() const override;
	virtual void move() const override;
	int feed();
	void swim();

private:
	int fed = 0;
};

