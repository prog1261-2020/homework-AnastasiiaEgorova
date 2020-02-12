#pragma once
#include <string>
#include <iostream>
#include "Animal.h"

class Capybara : public Animal
{
public:
	Capybara(std::string name);
	virtual void speak() const override;
	virtual void move() const override;

private:
	void swim() const;
};

