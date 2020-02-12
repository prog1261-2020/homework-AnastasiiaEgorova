#pragma once
#include <string>
#include <iostream>
#include "Animal.h"

class Dog : public Animal
{
public:
	Dog(std::string name);
	void speak() const override;
	virtual void move() const override;
	int walk();
	//void play();

private:
	int walked = 0;
};

